#include <iostream>

int main(int argc, char** argv)
{
    int a = 0;
    short b = 0;
    long c = 0;
    long long d = 0;
    float e = 0;
    double f = 0;
    long double g = 0;
    bool h = 0;

    std::cout << "int: " << &a << " " << sizeof(a) << std::endl;
    std::cout << "short: " << &b << " " << sizeof(b) << std::endl;
    std::cout << "long: " << &c << " " << sizeof(c) << std::endl;
    std::cout << "long long: " << &d << " " << sizeof(d) << std::endl;
    std::cout << "float: " << &e << " " << sizeof(e) << std::endl;
    std::cout << "double: " << &f << " " << sizeof(f) << std::endl;
    std::cout << "long double: " << &g << " " << sizeof(g) << std::endl;
    std::cout << "bool: " << &h << " " << sizeof(h) << std::endl;

    return 0;
}