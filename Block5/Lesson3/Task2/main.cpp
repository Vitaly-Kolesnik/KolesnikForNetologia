#include <iostream>
#include <utility>

void quick_sort_recursive(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort_recursive(arr, left, j);
    quick_sort_recursive(arr, i, right);
}

void quick_sort(int* arr, int size) {
    if (size <= 1 || arr == nullptr) {
        return;
    }
    quick_sort_recursive(arr, 0, size - 1);
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Исходный массив: ";
    print_array(arr1, size1);
    quick_sort(arr1, size1);
    std::cout << "Отсортированный массив: ";
    print_array(arr1, size1);
    std::cout << "\n";

    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Исходный массив: ";
    print_array(arr2, size2);
    quick_sort(arr2, size2);
    std::cout << "Отсортированный массив: ";
    print_array(arr2, size2);
    std::cout << "\n";

    int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "Исходный массив: ";
    print_array(arr3, size3);
    quick_sort(arr3, size3);
    std::cout << "Отсортированный массив: ";
    print_array(arr3, size3);

    return 0;
}