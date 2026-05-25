#include <iostream>

void print_pyramid(const int* arr, int size) {
    if (size <= 0 || arr == nullptr) {
        return;
    }

    std::cout << "0 root " << arr[0] << "\n";

    for (int i = 1; i < size; i++) {
        int parent_index = (i - 1) / 2;
        int level = 0;
        int temp = i;
        
        while (temp > 0) {
            temp = (temp - 1) / 2;
            level++;
        }

        std::cout << level << " ";
        if (i % 2 != 0) {
            std::cout << "left(" << arr[parent_index] << ") ";
        } else {
            std::cout << "right(" << arr[parent_index] << ") ";
        }
        std::cout << arr[i] << "\n";
    }
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Исходный массив: ";
    print_array(arr1, size1);
    std::cout << "Пирамида:\n";
    print_pyramid(arr1, size1);
    std::cout << "\n";

    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Исходный массив: ";
    print_array(arr2, size2);
    std::cout << "Пирамида:\n";
    print_pyramid(arr2, size2);
    std::cout << "\n";

    int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Исходный массив: ";
    print_array(arr3, size3);
    std::cout << "Пирамида:\n";
    print_pyramid(arr3, size3);

    return 0;
}