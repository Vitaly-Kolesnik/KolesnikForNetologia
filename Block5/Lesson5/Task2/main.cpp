#include <iostream>
#include <string>

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void print_node_info(const int* arr, int size, int index) {
    if (index == 0) {
        std::cout << "0 root " << arr[0];
        return;
    }

    int parent_index = (index - 1) / 2;
    int level = 0;
    int temp = index;
    while (temp > 0) {
        temp = (temp - 1) / 2;
        level++;
    }

    std::cout << level << " ";
    if (index % 2 != 0) {
        std::cout << "left(" << arr[parent_index] << ") ";
    } else {
        std::cout << "right(" << arr[parent_index] << ") ";
    }
    std::cout << arr[index];
}

void print_pyramid(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        print_node_info(arr, size, i);
        std::cout << "\n";
    }
}

bool get_parent(int index, int& parent_index) {
    if (index == 0) {
        return false;
    }
    parent_index = (index - 1) / 2;
    return true;
}

bool get_left_child(int index, int size, int& left_index) {
    int target = 2 * index + 1;
    if (target >= size) {
        return false;
    }
    left_index = target;
    return true;
}

bool get_right_child(int index, int size, int& right_index) {
    int target = 2 * index + 2;
    if (target >= size) {
        return false;
    }
    right_index = target;
    return true;
}

int main() {
    int arr[] = {1, 3, 6, 5, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    print_array(arr, size);
    std::cout << "Пирамида:\n";
    print_pyramid(arr, size);

    int current_index = 0;
    std::string command;

    while (true) {
        std::cout << "Вы находитесь здесь: ";
        print_node_info(arr, size, current_index);
        std::cout << "\nВведите команду: ";
        std::cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "up") {
            int next_index;
            if (get_parent(current_index, next_index)) {
                current_index = next_index;
                std::cout << "Ок\n";
            } else {
                std::cout << "Ошибка! Отсутствует родитель\n";
            }
        } else if (command == "left") {
            int next_index;
            if (get_left_child(current_index, size, next_index)) {
                current_index = next_index;
                std::cout << "Ок\n";
            } else {
                std::cout << "Ошибка! Отсутствует левый потомок\n";
            }
        } else if (command == "right") {
            int next_index;
            if (get_right_child(current_index, size, next_index)) {
                current_index = next_index;
                std::cout << "Ок\n";
            } else {
                std::cout << "Ошибка! Отсутствует правый потомок\n";
            }
        } else {
            std::cout << "Ошибка! Неизвестная команда\n";
        }
    }

    return 0;
}