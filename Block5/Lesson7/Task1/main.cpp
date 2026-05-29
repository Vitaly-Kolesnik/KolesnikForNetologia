#include <iostream>
#include <fstream>

void dfs(int current_vertex, int N, int** adjacency_matrix, bool* visited) 
{
    std::cout << current_vertex + 1 << " ";
    visited[current_vertex] = true;
    for (int next_vertex = 0; next_vertex < N; ++next_vertex) 
	{
        if (adjacency_matrix[current_vertex][next_vertex] == 1 && !visited[next_vertex])
		{
            dfs(next_vertex, N, adjacency_matrix, visited);
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
    bool* visited = new bool[N];
    for (int i = 0; i < N; ++i) 
	{
        visited[i] = false;
    }

    std::cout << "Порядок обхода вершин: ";
    dfs(0, N, adjacency_matrix, visited);
    std::cout << std::endl;
    for (int i = 0; i < N; ++i) 
	{
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
    delete[] visited;
    return 0;
}