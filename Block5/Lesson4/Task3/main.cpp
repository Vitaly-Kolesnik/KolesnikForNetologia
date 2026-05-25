#include <iostream>
#include <string>

void print_dynamic_array(int* arr, int logical, int actual) {
    for (int i = 0; i < logical; i++) {
        std::cout << arr[i] << " ";
    }
    for (int i = logical; i < actual; i++) {
        std::cout << "_ ";
    }
    std::cout << std::endl;
}

int* remove_dynamic_array_head(int* arr, int& logical, int& actual) {
    int new_logical = logical - 1;
    if (new_logical > actual / 3) {
        for (int i = 1; i < logical; i++) {
            arr[i - 1] = arr[i];
        }
        logical = new_logical;
        return arr;
    }
    int new_actual = actual / 3;
    if (new_actual < 1) new_actual = 1;
    int* new_arr = new int[new_actual];
    for (int i = 1; i < logical; i++) {
        new_arr[i - 1] = arr[i];
    }
    logical = new_logical;
    actual = new_actual;
    delete[] arr;
    return new_arr;
}

int main() {
    int actual, logical;
    while (true) {
        std::cout << "Введите фактичеcкий размер массива: ";
        std::cin >> actual;
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical;
        if (logical > actual) {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        } else {
            break;
        }
    }
    int* arr = new int[actual];
    for (int i = 0; i < logical; i++) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }
    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical, actual);
    while (true) {
        std::string answer;
        std::cout << "Удалить первый элемент? ";
        std::cin >> answer;
        if (answer == "да") {
            if (logical == 0) {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
                break;
            }
            arr = remove_dynamic_array_head(arr, logical, actual);
            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, logical, actual);
        } else if (answer == "нет") {
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical, actual);
            break;
        }
    }
    delete[] arr;
    return 0;
}
