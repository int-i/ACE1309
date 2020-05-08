#include <iostream>
#include "account.h"

int main() {
    int amount;
    Account account1(50);
    Account account2(25);

    std::cout << "account1 balance: $" << account1.get_balance() << std::endl
              << "account2 balance: $" << account2.get_balance() << std::endl
              << std::endl;

    std::cout << "Enter withdrawal account for account1: ";
    std::cin >> amount;
    std::cout << "Attempting to subtract " << amount << " from account1 balance." << std::endl
              << std::endl;
    account1.debit(amount);

    std::cout << "account1 balance: $" << account1.get_balance() << std::endl
              << "account2 balance: $" << account2.get_balance() << std::endl
              << std::endl;

    std::cout << "Enter withdrawal account for account2: ";
    std::cin >> amount;
    std::cout << "Attempting to subtract " << amount << " from account2 balance." << std::endl
              << std::endl;
    account2.debit(amount);

    std::cout << "account1 balance: $" << account1.get_balance() << std::endl
              << "account2 balance: $" << account2.get_balance() << std::endl
              << std::endl;
    return 0;
}
