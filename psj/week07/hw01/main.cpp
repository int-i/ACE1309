#include <iostream>
#include "account.h"

int main() {
    // Set annual interest rate
    SavingsAccount::modify_interest_rate(0.03);

    // Create two savers
    SavingsAccount saver1(2000);
    SavingsAccount saver2(3000);

    // Print balance for each saver
    std::cout << "saver1: ";
    saver1.print_balance();
    std::cout << "saver2: ";
    saver2.print_balance();

    // Calculate and add interest to balance
    saver1.calculate_monthly_interest();
    saver2.calculate_monthly_interest();

    // Print balance for each saver
    std::cout << "saver1: ";
    saver1.print_balance();
    std::cout << "saver2: ";
    saver2.print_balance();

    // Change annual interest rate
    SavingsAccount::modify_interest_rate(0.04);

    // Calculate and add interest to balance
    saver1.calculate_monthly_interest();
    saver2.calculate_monthly_interest();

    // Print balance for each saver
    std::cout << "saver1: ";
    saver1.print_balance();
    std::cout << "saver2: ";
    saver2.print_balance();
    return 0;
}
