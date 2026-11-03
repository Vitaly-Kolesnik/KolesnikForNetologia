#include <algorithm>
#include <future>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Iterator, typename Func>
void split_range(Iterator first, Iterator last, const Func& func,
                 std::vector<std::future<void>>& tasks)
{
    constexpr long block_size = 1000;
    const auto length = std::distance(first, last);
    if (length <= block_size)
    {
        tasks.push_back(std::async(std::launch::async, [first, last, &func] {
            std::for_each(first, last, func);
        }));
        return;
    }
    const auto middle = std::next(first, length / 2);
    split_range(first, middle, func, tasks);
    split_range(middle, last, func, tasks);
}

template <typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, const Func& func)
{
    std::vector<std::future<void>> tasks;
    split_range(first, last, func, tasks);
    for (std::future<void>& task : tasks)
    {
        task.get();
    }
}

int main()
{
    std::vector<int> data(10000);
    for (size_t i = 0; i < data.size(); ++i)
    {
        data[i] = static_cast<int>(i % 100);
    }

    auto processor = [](int& value)
    {
        value = value * 2 + 1;
    };

    parallel_for_each(data.begin(), data.end(), processor);

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
