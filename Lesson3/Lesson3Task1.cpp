#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Operator: ||\n";
    std::cout << "true   " << "true   " << (true || true) << "\n";
    std::cout << "false  " << "true   " << (false || true) << "\n";
    std::cout << "true   " << "false  " << (true || false) << "\n";
    std::cout << "false  " << "false  " << (false || false) << "\n";

    std::cout << "\n";

    std::cout << "Operator: &&\n";
    std::cout << "true   " << "true   " << (true || true) << "\n";
    std::cout << "false  " << "true   " << (false || true) << "\n";
    std::cout << "true   " << "false  " << (true || false) << "\n";
    std::cout << "false  " << "false  " << (false || false) << "\n";

    return EXIT_SUCCESS;
}

