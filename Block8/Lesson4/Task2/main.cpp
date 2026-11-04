#include <future>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>

void find_min_index(const std::vector<int>& data, int from, std::promise<int>& result)
{
    int min_index = from;
    for (int i = from + 1; i < static_cast<int>(data.size()); ++i)
    {
        if (data[i] < data[min_index])
        {
            min_index = i;
        }
    }
    result.set_value(min_index);
}

void selection_sort(std::vector<int>& data)
{
    for (int i = 0; i < static_cast<int>(data.size()); ++i)
    {
        std::promise<int> promise;
        std::future<int> future = promise.get_future();
        std::thread worker(find_min_index, std::cref(data), i, std::ref(promise));
        const int min_index = future.get();
        worker.join();
        std::swap(data[i], data[min_index]);
    }
}

int main()
{
    std::vector<int> data{5, 2, 9, 1, 7, 3, 8, 4, 6, 0};

    for (int value : data)
    {
        std::cout << value << ' ';
    }
    std::cout << std::endl;

    selection_sort(data);

    for (int value : data)
    {
        std::cout << value << ' ';
    }
    std::cout << std::endl;

    return 0;
}
