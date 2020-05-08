#include <iostream>
#include "account.h"

int main() {
    Account account(1000);
    std::cout << "account" << std::endl;
    account.credit(500);
    account.print();
    account.debit(300);
    account.print();
    std::cout << std::endl;

    CheckingAccount checking_account(1000, 100);
    std::cout << "checking_account" << std::endl;
    checking_account.credit(500);
    checking_account.print();
    checking_account.debit(300);
    checking_account.print();
    std::cout << std::endl;

    SavingAccount saving_account(1000, 0.1);
    std::cout << "saving_account" << std::endl;
    saving_account.print();
    std::cout << "calculate_interest: " << saving_account.calculate_interest() << std::endl;
    return 0;
}
