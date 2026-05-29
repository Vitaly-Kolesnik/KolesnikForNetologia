#include <iostream>
#include <fstream>

bool hasCycleDFS(int current_vertex, int parent_vertex, int N, int** adjacency_matrix, bool* visited)
{
    visited[current_vertex] = true;
    for (int next_vertex = 0; next_vertex < N; ++next_vertex) 
	{
        if (adjacency_matrix[current_vertex][next_vertex] == 1)
		{   
            if (!visited[next_vertex]) 
			{
                if (hasCycleDFS(next_vertex, current_vertex, N, adjacency_matrix, visited)) 
				{
                    return true;
                }
            }
            else if (next_vertex != parent_vertex) 
			{
                return true;
            }
        }
    }
    return false;
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

    bool cycle_found = false;
    for (int i = 0; i < N; ++i) 
	{
        if (!visited[i]) 
		{
            if (hasCycleDFS(i, -1, N, adjacency_matrix, visited)) 
			{
                cycle_found = true;
                break;
            }
        }
    }

    if (cycle_found) 
	{
        std::cout << "В графе есть цикл!" << std::endl;
    } 
	else 
	{
        std::cout << "В графе нет циклов" << std::endl;
    }

    for (int i = 0; i < N; ++i) 
	{
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
    delete[] visited;
    return 0;
}