#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

template <std::memory_order RmwOrder, std::memory_order LoadOrder>
class ClientQueue
{
public:
    explicit ClientQueue(int max_clients)
        : max_clients_(max_clients)
    {
    }

    void run()
    {
        std::thread client(&ClientQueue::client_work, this);
        std::thread oper(&ClientQueue::operator_work, this);
        client.join();
        clients_done_.store(true, std::memory_order_release);
        oper.join();
    }

    int counter() const
    {
        return counter_.load(LoadOrder);
    }

    int served() const
    {
        return served_.load(LoadOrder);
    }

private:
    void client_work()
    {
        for (int i = 0; i < max_clients_; ++i)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            counter_.fetch_add(1, RmwOrder);
        }
    }

    void operator_work()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if (counter_.load(LoadOrder) > 0)
            {
                counter_.fetch_sub(1, RmwOrder);
                served_.fetch_add(1, RmwOrder);
            }
            else if (clients_done_.load(std::memory_order_acquire))
            {
                break;
            }
        }
    }

    int max_clients_;
    std::atomic<int> counter_{0};
    std::atomic<int> served_{0};
    std::atomic<bool> clients_done_{false};
};

template <std::memory_order RmwOrder, std::memory_order LoadOrder>
void run_mode(const std::string& name, int max_clients)
{
    ClientQueue<RmwOrder, LoadOrder> queue(max_clients);
    queue.run();
    std::cout << name << ": counter = " << queue.counter()
              << ", served = " << queue.served() << std::endl;
}

int main(int argc, char* argv[])
{
    int max_clients = 5;
    if (argc > 1)
    {
        max_clients = std::stoi(argv[1]);
    }
    std::cout << "Max clients: " << max_clients << std::endl;

    run_mode<std::memory_order_relaxed, std::memory_order_relaxed>("relaxed", max_clients);
    run_mode<std::memory_order_release, std::memory_order_acquire>("acquire-release", max_clients);
    run_mode<std::memory_order_acq_rel, std::memory_order_acquire>("acq_rel", max_clients);
    run_mode<std::memory_order_seq_cst, std::memory_order_seq_cst>("seq_cst", max_clients);

    return 0;
}
