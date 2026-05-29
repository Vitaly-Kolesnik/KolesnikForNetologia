#include <iostream>
#include <string>

int simple_string_hash(const std::string& s) 
{
    int hash = 0;
    for (char c : s) {
        hash += static_cast<int>(c);
    }
    return hash;
}

int find_substring_light_rabin_karp(std::string source, std::string substring)
{
    int src_len = source.length();
    int sub_len = substring.length();

    if (sub_len > src_len) 
	{
		return -1;
	}

    int sub_hash = simple_string_hash(substring);
    int current_window_hash = 0;
    for (int i = 0; i < sub_len; ++i)
	{
        current_window_hash += static_cast<int>(source[i]);
    }

    for (int i = 0; i <= src_len - sub_len; ++i) 
	{
        if (current_window_hash == sub_hash) 
		{
            bool match = true;
            for (int j = 0; j < sub_len; ++j)
			{
                if (source[i + j] != substring[j]) 
				{
                    match = false;
                    break;
                }
            }
            if (match)
			{ 
				return i;
			}
        }

        if (i < src_len - sub_len) 
		{
            current_window_hash -= static_cast<int>(source[i]);
            current_window_hash += static_cast<int>(source[i + sub_len]);
        }
    }

    return -1;
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    std::string source;
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::getline(std::cin, source);

    std::string substring;
    do
	{
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::getline(std::cin, substring);
        int index = find_substring_light_rabin_karp(source, substring);
        if (index != -1) 
		{
            std::cout << "Подстрока " << substring << " найдена по индексу " << index << std::endl;
        } else {
            std::cout << "Подстрока " << substring << " не найдена" << std::endl;
        }

    } while (substring != "exit");

    return 0;
}