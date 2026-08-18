#include <iostream>
#include <stdexcept> 

template<typename T>
class UniquePtr {
public:
    explicit UniquePtr(T* ptr = nullptr) : ptr_(ptr) {}

    ~UniquePtr() {
        delete ptr_;
        std::cout << "UniquePtr destructor called (deleted managed object)\n";
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    T& operator*() const {
        if (ptr_ == nullptr) {
            throw std::runtime_error("Dereferencing null UniquePtr");
        }
        return *ptr_;
    }

    T* operator->() const {
        if (ptr_ == nullptr) {
            throw std::runtime_error("Accessing member through null UniquePtr");
        }
        return ptr_;
    }

    T* release() {
        T* tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    }

    T* get() const {
        return ptr_;
    }

private:
    T* ptr_;
};

int main() 
{
    std::cout << "=== Create UniquePtr<int> with value 42 ===\n";
    UniquePtr<int> up(new int(42));

    std::cout << "*up = " << *up << std::endl;
    std::cout << "up.get() = " << up.get() << std::endl;

    std::cout << "\n=== Release ownership ===\n";
    int* raw = up.release();
    std::cout << "Raw pointer value: " << *raw << std::endl;
    std::cout << "After release, up.get() = " << up.get() << " (nullptr)\n";

    try 
    {
        std::cout << *up << std::endl;
    } 
    catch (const std::runtime_error& e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    delete raw;

    std::cout << "\n=== Going out of scope (up will be destroyed) ===\n";
    return 0;
}
