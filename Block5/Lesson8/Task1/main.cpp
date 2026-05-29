#include <iostream>
#include <fstream>

int main() 
{
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

    int N;
    input_file >> N;
    int** adjacency_matrix = new int*[N];
    for (int i = 0; i < N; ++i) 
	{
        adjacency_matrix[i] = new int[N];
    }

    for (int i = 0; i < N; ++i) 
	{
        for (int j = 0; j < N; ++j) 
		{
            input_file >> adjacency_matrix[i][j];
        }
    }
	
    input_file.close();
    std::cout << "Текстовый вид орграфа:" << std::endl;
    for (int i = 0; i < N; ++i) 
	{
        std::cout << i + 1 << ": ";
        bool has_edges = false;
        for (int j = 0; j < N; ++j) 
		{
            if (adjacency_matrix[i][j] == 1) 
			{
                std::cout << j + 1 << " ";
                has_edges = true;
            }
        }

        if (!has_edges) 
		{
            std::cout << "нет";
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < N; ++i) 
	{
        delete[] adjacency_matrix[i];
    }
	
    delete[] adjacency_matrix;
    return 0;
}