#include "account.h"
#include <iostream>

Account::Account(int balance) {
    if (balance >= 0) {
        this->balance = balance;
    } else {
        this->balance = 0;
        std::cout << "The given balance must be at least 0." << std::endl;
    }
}

void Account::credit(int amount) {
    balance += amount;
}

void Account::debit(int amount) {
    if (balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    }
}

int Account::get_balance() const {
    return balance;
}
