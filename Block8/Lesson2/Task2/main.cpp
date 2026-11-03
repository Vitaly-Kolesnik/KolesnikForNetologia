#include <chrono>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>

std::mutex cout_mutex;

void worker(int index, int work_length, int bar_width, int step_delay_ms, int screen_row)
{
    const auto start = std::chrono::steady_clock::now();

    std::ostringstream id_stream;
    id_stream << std::this_thread::get_id();
    const std::string id_str = id_stream.str();

    for (int step = 0; step <= work_length; ++step)
    {
        const int filled = step * bar_width / work_length;
        std::string bar(filled, '#');
        bar += std::string(bar_width - filled, ' ');

        std::lock_guard<std::mutex> guard(cout_mutex);
        std::cout << "\033[" << screen_row << ";1H"
                  << index + 1 << "    "
                  << id_str.substr(0, 8) << "  "
                  << "[" << bar << "]"
                  << std::flush;

        if (step < work_length)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(step_delay_ms));
        }
    }

    const auto finish = std::chrono::steady_clock::now();
    const double seconds = std::chrono::duration<double>(finish - start).count();

    std::string bar(bar_width, '#');
    std::lock_guard<std::mutex> guard(cout_mutex);
    std::cout << "\033[" << screen_row << ";1H"
              << index + 1 << "    "
              << id_str.substr(0, 8) << "  "
              << "[" << bar << "]  " << seconds << "s"
              << std::flush;
}

int main()
{
    int thread_count = 4;
    int work_length = 50;
    int bar_width = 40;
    int step_delay_ms = 50;

    std::cout << "\033[2J\033[H";
    std::cout << "#    Id        Progress" << std::endl;
    for (int i = 0; i < thread_count + 1; ++i)
    {
        std::cout << std::endl;
    }

    std::thread threads[16];
    for (int i = 0; i < thread_count; ++i)
    {
        threads[i] = std::thread(worker, i, work_length, bar_width, step_delay_ms, i + 2);
    }
    for (int i = 0; i < thread_count; ++i)
    {
        threads[i].join();
    }

    std::cout << "\033[" << thread_count + 2 << ";1H" << std::flush;

    return 0;
}
