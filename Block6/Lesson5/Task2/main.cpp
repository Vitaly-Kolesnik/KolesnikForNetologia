#include <iostream>
#include <stdexcept>
#include <algorithm>

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

    smart_array(const smart_array& other)
        : data_(new int[other.capacity_]),
          capacity_(other.capacity_),
          size_(other.size_) {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    smart_array& operator=(const smart_array& other) 
    {
        smart_array tmp(other);
        swap(tmp);
        return *this;
    }

    smart_array(smart_array&& other) noexcept
        : data_(other.data_), capacity_(other.capacity_), size_(other.size_) 
    {
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
    }

    smart_array& operator=(smart_array&& other) noexcept 
    {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            capacity_ = other.capacity_;
            size_ = other.size_;
            other.data_ = nullptr;
            other.capacity_ = 0;
            other.size_ = 0;
        }
        return *this;
    }

    ~smart_array() {
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

    void print() const 
    {
        std::cout << "[ ";
        for (size_t i = 0; i < size_; ++i) 
        {
            std::cout << data_[i] << " ";
        }
        std::cout << "] (size=" << size_ << ", capacity=" << capacity_ << ")" << std::endl;
    }

private:
    void swap(smart_array& other) noexcept 
    {
        std::swap(data_, other.data_);
        std::swap(capacity_, other.capacity_);
        std::swap(size_, other.size_);
    }

    int* data_;
    size_t capacity_;
    size_t size_;
};

int main() 
{
    try 
    {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        std::cout << "arr before assignment: ";
        arr.print();
        std::cout << "new_array: ";
        new_array.print();

        arr = new_array;

        std::cout << "arr after assignment: ";
        arr.print();

        arr.add_element(999);
        std::cout << "arr after adding 999 (new_array must stay unchanged): ";
        arr.print();
        std::cout << "new_array: ";
        new_array.print();

    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}