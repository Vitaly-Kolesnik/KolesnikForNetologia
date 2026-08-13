#include <iostream>
#include <stdexcept>

class smart_array 
{
public:
    explicit smart_array(size_t capacity)
        : data_(nullptr), capacity_(capacity), size_(0) 
    {
        if (capacity_ == 0) 
        {
            throw std::invalid_argument("Capacity must be greater than zero");
        }
        data_ = new int[capacity_];
    }

    smart_array(const smart_array&) = delete;
    smart_array& operator=(const smart_array&) = delete;

    ~smart_array() 
    {
        delete[] data_;
    }

    void add_element(int value) 
    {
        if (size_ >= capacity_) 
        {
            throw std::out_of_range("Array is full: cannot add more elements");
        }

        data_[size_++] = value;
    }

    int get_element(size_t index) const 
    {
        if (index >= size_) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

private:
    int* data_;
    size_t capacity_;
    size_t size_;
};

int main() 
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
        arr.add_element(100);
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        smart_array arr2(3);
        arr2.add_element(10);
        std::cout << arr2.get_element(5) << std::endl;
    }
    catch (const std::exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}