#include <iostream>

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
    std::cout << "Ââåäèòå íîìåð ñ÷¸òà: ";
    std::cin >> userAccount.accountNumber;
    std::cout << "Ââåäèòå èìÿ âëàäåëüöà: ";
    std::cin >> userAccount.ownerName;
    std::cout << "Ââåäèòå áàëàíñ: ";
    std::cin >> userAccount.balance;

    double newBalance;
    std::cout << "Ââåäèòå íîâûé áàëàíñ: ";
    std::cin >> newBalance;

    updateBalance(userAccount, newBalance);

    std::cout << "Âàø ñ÷¸ò: " << userAccount.ownerName << ", "
        << userAccount.accountNumber << ", "
        << userAccount.balance << std::endl;

    return 0;
}
