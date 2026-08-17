#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename T>
class MyVector {
public:
    MyVector()
        : data_(nullptr), sz_(0), cap_(0) {}

    ~MyVector() {
        delete[] data_;
    }

    T& at(int index) {
        if (index < 0 || static_cast<size_t>(index) >= sz_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& at(int index) const 
	{
        if (index < 0 || static_cast<size_t>(index) >= sz_) 
		{
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    void push_back(const T& value) 
	{
        if (sz_ == cap_) 
		{
            size_t new_cap = (cap_ == 0) ? 1 : cap_ * 2;
            reserve(new_cap);
        }
        data_[sz_] = value;
        ++sz_;
    }

    size_t size() const 
	{
        return sz_;
    }

    size_t capacity() const 
	{
        return cap_;
    }

private:
    void reserve(size_t new_cap) 
	{
        T* new_data = new T[new_cap];
        if (data_) 
		{
            for (size_t i = 0; i < sz_; ++i) 
			{
                new_data[i] = data_[i];
            }
            delete[] data_;
        }
        data_ = new_data;
        cap_ = new_cap;
    }

private:
    T* data_;
    size_t sz_;
    size_t cap_;
};

int main() {
    MyVector<int> vec;

    std::cout << "Initial: size = " << vec.size()
              << ", capacity = " << vec.capacity() << std::endl;

    for (int i = 0; i < 10; ++i) 
	{
        vec.push_back(i * i);
        std::cout << "Pushed " << i * i
                  << ", size = " << vec.size()
                  << ", capacity = " << vec.capacity() << std::endl;
    }

    std::cout << "\nElement at index 3: " << vec.at(3) << std::endl;
    std::cout << "Element at index 5: " << vec.at(5) << std::endl;

    try 
	{
        vec.at(20);
    } 
	catch (const std::out_of_range& e) 
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\nAll elements:" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) 
	{
        std::cout << vec.at(i) << ' ';
    }
    std::cout << std::endl;
    return 0;
}
