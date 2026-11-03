#include <iostream>
#include <mutex>
#include <string>
#include <utility>

class Data
{
public:
    Data(int id, double value)
        : id_(id)
        , value_(value)
    {
    }

    void print(const std::string& name) const
    {
        std::cout << name << ": id = " << id_ << ", value = " << value_ << std::endl;
    }

    friend void swap_by_lock(Data& a, Data& b);
    friend void swap_by_scoped_lock(Data& a, Data& b);
    friend void swap_by_unique_lock(Data& a, Data& b);

private:
    int id_;
    double value_;
    std::mutex mutex_;
};

void swap_by_lock(Data& a, Data& b)
{
    std::lock(a.mutex_, b.mutex_);
    std::lock_guard<std::mutex> guard_a(a.mutex_, std::adopt_lock);
    std::lock_guard<std::mutex> guard_b(b.mutex_, std::adopt_lock);
    std::swap(a.id_, b.id_);
    std::swap(a.value_, b.value_);
}

void swap_by_scoped_lock(Data& a, Data& b)
{
    std::scoped_lock guard(a.mutex_, b.mutex_);
    std::swap(a.id_, b.id_);
    std::swap(a.value_, b.value_);
}

void swap_by_unique_lock(Data& a, Data& b)
{
    std::unique_lock<std::mutex> lock_a(a.mutex_, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(b.mutex_, std::defer_lock);
    std::lock(lock_a, lock_b);
    std::swap(a.id_, b.id_);
    std::swap(a.value_, b.value_);
}

int main()
{
    Data first(1, 10.5);
    Data second(2, 20.5);

    first.print("first");
    second.print("second");
    std::cout << std::endl;

    swap_by_lock(first, second);
    std::cout << "after swap_by_lock:" << std::endl;
    first.print("first");
    second.print("second");
    std::cout << std::endl;

    swap_by_scoped_lock(first, second);
    std::cout << "after swap_by_scoped_lock:" << std::endl;
    first.print("first");
    second.print("second");
    std::cout << std::endl;

    swap_by_unique_lock(first, second);
    std::cout << "after swap_by_unique_lock:" << std::endl;
    first.print("first");
    second.print("second");

    return 0;
}
