#include <iostream>
#include <fstream>

void findComponentsDFS(int current_vertex, int component_id, int N, int** adjacency_matrix, int* components) 
{
    components[current_vertex] = component_id;
    for (int next_vertex = 0; next_vertex < N; ++next_vertex) 
	{
        if (adjacency_matrix[current_vertex][next_vertex] == 1 && components[next_vertex] == 0) 
		{
            findComponentsDFS(next_vertex, component_id, N, adjacency_matrix, components);
        }
    }
}

int main() 
{
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) 
	{
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
    int* components = new int[N];
    for (int i = 0; i < N; ++i) 
	{
        components[i] = 0;
    }

    int component_count = 0;
    for (int i = 0; i < N; ++i) 
	{
        if (components[i] == 0) 
		{
            component_count++;
            findComponentsDFS(i, component_count, N, adjacency_matrix, components);
        }
    }

    std::cout << "Принадлежность вершин компонентам связности:" << std::endl;
    for (int i = 0; i < N; ++i) 
	{
        std::cout << i + 1 << " - " << components[i] << std::endl;
    }
    
    std::cout << "Количество компонентов связности в графе: " << component_count << std::endl;
    for (int i = 0; i < N; ++i) 
	{
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
    delete[] components;
    return 0;
}