#include <iostream>
#include <vector>
#include <algorithm>

class DivisibleByThreeCounter {
public:
    DivisibleByThreeCounter() : sum_(0), count_(0) {}

    void operator()(int value) {
        if (value % 3 == 0) {
            sum_ += value;
            ++count_;
        }
    }

    int get_sum() const {
        return sum_;
    }

    int get_count() const {
        return count_;
    }

private:
    int sum_;
    int count_;
};


int main() {
    std::vector<int> numbers = {4, 1, 3, 6, 25, 54};

    DivisibleByThreeCounter counter = std::for_each(
        numbers.begin(),
        numbers.end(),
        DivisibleByThreeCounter()
    );

    std::cout << "[IN]: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if (i + 1 < numbers.size()) std::cout << ' ';
    }
    std::cout << std::endl;

    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

    return 0;
}