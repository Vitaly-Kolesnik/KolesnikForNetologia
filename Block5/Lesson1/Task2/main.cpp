#include <iostream>

std::size_t countGreater(const int arr[], std::size_t size, int x) {
    std::size_t left = 0;
    std::size_t right = size; 

    while (left < right) {
        std::size_t mid = left + (right - left) / 2;

        if (arr[mid] <= x) {
            left = mid + 1; 
        } else {
            right = mid; 
        }
    }

    return size - left;
}

int main() {
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr) / sizeof(arr[0]);

    int x;
    std::cout << "Введите точку отсчёта: ";
    std::cin >> x;

    auto result = countGreater(arr, size, x);

    std::cout << "Количество элементов в массиве больших, чем "
              << x << ": " << result << std::endl;

    return 0;
}