#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

void client_thread(std::atomic<int>& counter, int max_clients) {
    for (int i = 0; i < max_clients; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        counter.fetch_add(1);
    }
}

void operator_thread(std::atomic<int>& counter, std::atomic<bool>& clients_done) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        int current = counter.load();
        if (current > 0) {
            counter.fetch_sub(1);
        } else if (clients_done.load()) {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    int max_clients = 10;
    
    if (argc > 1) {
        max_clients = std::stoi(argv[1]);
    }
    
    std::atomic<int> counter{0};
    std::atomic<bool> clients_done{false};
    
    std::thread client(client_thread, std::ref(counter), max_clients);
    std::thread oper(operator_thread, std::ref(counter), std::ref(clients_done));
    
    client.join();
    clients_done.store(true);
    oper.join();
    
    std::cout << "Final counter value: " << counter.load() << std::endl;
    
    return 0;
}
