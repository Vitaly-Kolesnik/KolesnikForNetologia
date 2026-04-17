#include <iostream>
#include <string>

struct BankAccount {
    int accountNumber;
    std::string ownerName;
    double balance;
};

void updateBalance(BankAccount& account, double newBalance) 
{
    account.balance = newBalance;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    BankAccount userAccount;
    std::cout << "¬ведите номер счЄта: ";
    std::cin >> userAccount.accountNumber;
    std::cout << "¬ведите им€ владельца: ";
    std::cin >> userAccount.ownerName;
    std::cout << "¬ведите баланс: ";
    std::cin >> userAccount.balance;

    double newBalance;
    std::cout << "¬ведите новый баланс: ";
    std::cin >> newBalance;

    updateBalance(userAccount, newBalance);

    std::cout << "¬аш счЄт: " << userAccount.ownerName << ", "
        << userAccount.accountNumber << ", "
        << userAccount.balance << std::endl;

    return 0;
}