#include <iostream>
#include <vector>
#include <utility>

template<typename T>
class Table {
public:
    Table(size_t rows, size_t cols)
        : rows_(rows), cols_(cols), data_(rows * cols)
    {
    }

    T* operator[](size_t row) 
	{
        return data_.data() + row * cols_;
    }

    const T* operator[](size_t row) const 
	{
        return data_.data() + row * cols_;
    }

    std::pair<size_t, size_t> Size() const 
	{
        return {rows_, cols_};
    }

private:
    size_t rows_;
    size_t cols_;
    std::vector<T> data_;
};

int main() 
{
    Table<int> test(2, 3);

    test[0][0] = 4;

    std::cout << test[0][0] << std::endl; 

    for (size_t i = 0; i < test.Size().first; ++i) {
        for (size_t j = 0; j < test.Size().second; ++j) {
            test[i][j] = static_cast<int>(i * 10 + j);
        }
    }

    std::cout << "Full table:" << std::endl;
    for (size_t i = 0; i < test.Size().first; ++i) {
        for (size_t j = 0; j < test.Size().second; ++j) {
            std::cout << test[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    const Table<int>& const_test = test;
    std::cout << "const_test[1][2] = " << const_test[1][2] << std::endl;

    return 0;
}