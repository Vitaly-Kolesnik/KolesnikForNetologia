#include <iostream>
#include <fstream>
#include <queue>

void bfs(int start_vertex, int N, int** adjacency_matrix, bool* visited) 
{
    std::queue<int> q;
    q.push(start_vertex);
    visited[start_vertex] = true;

    while (!q.empty()) 
	{
        int current_vertex = q.front();
        q.pop();
        std::cout << current_vertex + 1 << " ";
        for (int next_vertex = 0; next_vertex < N; ++next_vertex) 
		{
            if (adjacency_matrix[current_vertex][next_vertex] == 1 && !visited[next_vertex]) 
			{
                q.push(next_vertex);
                visited[next_vertex] = true;
            }
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
    std::cout << "В графе " << N << " вершин." << std::endl;
    int start_node;
    while (true) 
	{
        std::cout << "Введите номер вершины, с которой начнётся обход: ";
        std::cin >> start_node;

        if (start_node >= 1 && start_node <= N) 
		{
            break;
        }
		
        std::cout << "Неверный индекс! Номер должен быть от 1 до " << N << "." << std::endl;
    }

    bool* visited = new bool[N];
    for (int i = 0; i < N; ++i) 
	{
        visited[i] = false;
    }

    std::cout << "Порядок обхода вершин: ";
    bfs(start_node - 1, N, adjacency_matrix, visited);
    std::cout << std::endl;
    for (int i = 0; i < N; ++i) 
	{
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
    delete[] visited;

    return 0;
}