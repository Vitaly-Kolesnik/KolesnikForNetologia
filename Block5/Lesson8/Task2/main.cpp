#include <iostream>
#include <fstream>

void topologicalSortDFS(int current_vertex, int N, int** adjacency_matrix, int* visited, int* result, int& result_index) 
{
    visited[current_vertex] = 1;
    for (int next_vertex = 0; next_vertex < N; ++next_vertex) 
	{
        if (adjacency_matrix[current_vertex][next_vertex] == 1) 
		{
            if (visited[next_vertex] == 0) 
			{
                topologicalSortDFS(next_vertex, N, adjacency_matrix, visited, result, result_index);
            }
        }
    }

    visited[current_vertex] = 2;
    result[result_index] = current_vertex;
    result_index--;
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

    int* visited = new int[N];
    for (int i = 0; i < N; ++i) 
	{
        visited[i] = 0;
    }

    int* result = new int[N];
    int result_index = N - 1; 
    for (int i = 0; i < N; ++i) 
	{
        if (visited[i] == 0) 
		{
            topologicalSortDFS(i, N, adjacency_matrix, visited, result, result_index);
        }
    }

    std::cout << "Топологический порядок вершин: ";
    for (int i = 0; i < N; ++i) 
	{
        std::cout << result[i] + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < N; ++i) 
	{
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
    delete[] visited;
    delete[] result;

    return 0;
}