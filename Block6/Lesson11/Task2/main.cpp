#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

class big_integer {
private:
    std::vector<int> digits;

    void normalize() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

public:
    big_integer() : digits(1, 0) {}
    big_integer(const std::string& s) {
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (*it < '0' || *it > '9') {
                throw std::invalid_argument("Invalid digit");
            }
            digits.push_back(*it - '0');
        }
        normalize();
    }

    big_integer(big_integer&& other) noexcept : digits(std::move(other.digits)) {}

    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            digits = std::move(other.digits);
        }
        return *this;
    }

    big_integer operator+(const big_integer& other) const {
        big_integer result;
        result.digits.clear();
        size_t n = std::max(digits.size(), other.digits.size());
        int carry = 0;
        for (size_t i = 0; i < n || carry; ++i) {
            int sum = carry;
            if (i < digits.size())      sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        result.normalize();
        return result;
    }

    big_integer operator*(int multiplier) const {
        if (multiplier == 0) return big_integer("0");
        big_integer result;
        result.digits.clear();
        int carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            long long product = carry;
            if (i < digits.size()) {
                product += 1LL * digits[i] * multiplier;
            }
            result.digits.push_back(product % 10);
            carry = static_cast<int>(product / 10);
        }
        result.normalize();
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        if (num.digits.empty()) {
            os << '0';
            return os;
        }
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }
};

int main() 
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << "114575 + 78524 = " << result << std::endl;

    auto mult = number1 * 3;
    std::cout << "114575 * 3 = " << mult << std::endl;

    big_integer number3 = big_integer("12345678901234567890");
    big_integer number4 = std::move(number3);
    std::cout << "After move: " << number4 << std::endl;

    return 0;
}