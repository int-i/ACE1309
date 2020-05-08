#include "account.h"
#include <iostream>

double SavingsAccount::annual_interest_rate = 0.03;

void SavingsAccount::modify_interest_rate(double rate) {
    SavingsAccount::annual_interest_rate = rate > 0 ? rate : 0.03;
}

SavingsAccount::SavingsAccount(double balance) {
    savings_balance = balance >= 0 ? balance : 0;
}

void SavingsAccount::calculate_monthly_interest() {
    savings_balance *= 1 + SavingsAccount::annual_interest_rate / 12;
}

void SavingsAccount::print_balance() const {
    std::cout << "$" << savings_balance << std::endl;
}
