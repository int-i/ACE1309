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

void Account::print() const {
    std::cout << "balance: " << balance << std::endl;
}

void Account::set_balance(int balance) {
    this->balance = balance;
}

CheckingAccount::CheckingAccount(int balance, int transaction_fee)
: Account(balance) {
    if (transaction_fee >= 0) {
        this->transaction_fee = transaction_fee;
    } else {
        this->transaction_fee = 0;
        std::cout << "The given transaction_fee must be at least 0." << std::endl;
    }
}

void CheckingAccount::credit(int amount) {
    int total = get_balance() + amount - transaction_fee;
    if (total >= 0) {
        set_balance(total);
    } else {
        std::cout << "Total amount exceeded account balance." << std::endl;
    }
}

void CheckingAccount::debit(int amount) {
    int total = get_balance() - amount - transaction_fee;
    if (total >= 0) {
        set_balance(total);
    } else {
        std::cout << "Total amount exceeded account balance." << std::endl;
    }
}

SavingAccount::SavingAccount(int balance, double interest_rate)
: Account(balance) {
    if (interest_rate >= 0) {
        this->interest_rate = interest_rate;
    } else {
        this->interest_rate = 0;
        std::cout << "The given interest_rate must be at least 0." << std::endl;
    }
}

double SavingAccount::calculate_interest() const {
    return interest_rate * get_balance();
}
