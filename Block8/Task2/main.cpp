#include <atomic>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<bool> hardware_printed{false};

void add_range(const std::vector<double>& a, const std::vector<double>& b,
               std::vector<double>& c, size_t begin, size_t end, int index)
{
    if (index == 0 && !hardware_printed.exchange(true))
    {
        std::cout << "Количество аппаратных ядер - "
                  << std::thread::hardware_concurrency() << std::endl;
    }
    for (size_t i = begin; i < end; ++i)
    {
        c[i] = a[i] + b[i];
    }
}

double measure_sum(const std::vector<double>& a, const std::vector<double>& b,
                   std::vector<double>& c, int thread_count)
{
    const size_t n = a.size();
    const auto start = std::chrono::steady_clock::now();
    std::vector<std::thread> threads;
    threads.reserve(thread_count);
    for (int t = 0; t < thread_count; ++t)
    {
        const size_t begin = t * n / thread_count;
        const size_t end = (t + 1) * n / thread_count;
        threads.emplace_back(add_range, std::cref(a), std::cref(b), std::ref(c), begin, end, t);
    }
    for (std::thread& t : threads)
    {
        t.join();
    }
    const auto finish = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(finish - start).count();
}

int main()
{
    const std::vector<int> thread_counts{1, 2, 4, 8, 16};
    const std::vector<size_t> sizes{1000, 10000, 100000, 1000000};
    std::vector<std::vector<double>> results(thread_counts.size(),
                                             std::vector<double>(sizes.size(), 0.0));

    for (size_t s = 0; s < sizes.size(); ++s)
    {
        std::vector<double> a(sizes[s]);
        std::vector<double> b(sizes[s]);
        std::vector<double> c(sizes[s]);
        for (size_t i = 0; i < sizes[s]; ++i)
        {
            a[i] = static_cast<double>(i % 100);
            b[i] = static_cast<double>(i % 50);
        }
        for (size_t t = 0; t < thread_counts.size(); ++t)
        {
            results[t][s] = measure_sum(a, b, c, thread_counts[t]);
        }
    }

    std::cout << std::endl;
    std::cout << std::setw(10) << "";
    for (size_t s = 0; s < sizes.size(); ++s)
    {
        std::cout << std::setw(14) << sizes[s];
    }
    std::cout << std::endl;
    for (size_t t = 0; t < thread_counts.size(); ++t)
    {
        std::cout << std::left << std::setw(10)
                  << std::to_string(thread_counts[t]) + " потоков" << std::right;
        for (size_t s = 0; s < sizes.size(); ++s)
        {
            std::cout << std::setw(13) << results[t][s] << "s";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::vector<double> total(thread_counts.size(), 0.0);
    for (size_t s = 0; s < sizes.size(); ++s)
    {
        size_t best = 0;
        for (size_t t = 0; t < thread_counts.size(); ++t)
        {
            total[t] += results[t][s];
            if (results[t][s] < results[best][s])
            {
                best = t;
            }
        }
        std::cout << "Размер " << sizes[s] << ": самый быстрый результат - "
                  << thread_counts[best] << " потоков" << std::endl;
    }

    size_t overall = 0;
    for (size_t t = 1; t < thread_counts.size(); ++t)
    {
        if (total[t] < total[overall])
        {
            overall = t;
        }
    }
    std::cout << "Оптимальное количество потоков: " << thread_counts[overall] << std::endl;

    return 0;
}
