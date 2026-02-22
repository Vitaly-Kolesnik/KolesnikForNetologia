#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("in.txt");
    int rows, cols;
    file >> rows >> cols;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            file >> arr[i][j];
        }
    }
    file.close();

    for (int i = 0; i < rows; i++) {
        for (int j = cols - 1; j >= 0; j--) {
            std::cout << arr[i][j];
            if (j > 0) std::cout << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}