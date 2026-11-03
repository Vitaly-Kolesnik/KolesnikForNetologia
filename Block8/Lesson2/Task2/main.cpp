#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>

std::mutex cout_mutex;

void calculate_step(int roll, int error_probability)
{
    if (roll < error_probability)
    {
        throw std::runtime_error("calculation error");
    }
}

void print_bar(const std::string& bar)
{
    for (char symbol : bar)
    {
        if (symbol == 'X')
        {
            std::cout << "\033[31m" << symbol << "\033[0m";
        }
        else
        {
            std::cout << symbol;
        }
    }
}

void worker(int index, int work_length, int step_delay_ms, int error_probability, int screen_row)
{
    const auto start = std::chrono::steady_clock::now();

    std::ostringstream id_stream;
    id_stream << std::this_thread::get_id();
    const std::string id_str = id_stream.str();

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 99);

    std::string bar;
    for (int step = 0; step < work_length; ++step)
    {
        try
        {
            calculate_step(distribution(generator), error_probability);
            bar += '#';
        }
        catch (const std::exception&)
        {
            bar += 'X';
        }

        {
            std::lock_guard<std::mutex> guard(cout_mutex);
            std::cout << "\033[" << screen_row << ";1H"
                      << index + 1 << "    "
                      << id_str.substr(0, 8) << "  [";
            print_bar(bar);
            std::cout << std::string(work_length - static_cast<int>(bar.size()), ' ')
                      << "]" << std::flush;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(step_delay_ms));
    }

    const auto finish = std::chrono::steady_clock::now();
    const double seconds = std::chrono::duration<double>(finish - start).count();

    std::lock_guard<std::mutex> guard(cout_mutex);
    std::cout << "\033[" << screen_row << ";1H"
              << index + 1 << "    "
              << id_str.substr(0, 8) << "  [";
    print_bar(bar);
    std::cout << "]  " << seconds << "s" << std::flush;
}

int main()
{
    int thread_count = 4;
    int work_length = 50;
    int step_delay_ms = 50;
    int error_probability = 10;

    std::cout << "\033[2J\033[H";
    std::cout << "#    Id        Progress" << std::endl;
    for (int i = 0; i < thread_count + 1; ++i)
    {
        std::cout << std::endl;
    }

    std::thread threads[16];
    for (int i = 0; i < thread_count; ++i)
    {
        threads[i] = std::thread(worker, i, work_length, step_delay_ms, error_probability, i + 2);
    }
    for (int i = 0; i < thread_count; ++i)
    {
        threads[i].join();
    }

    std::cout << "\033[" << thread_count + 2 << ";1H" << std::flush;

    return 0;
}
