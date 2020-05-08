#ifndef ACE1309_WEEK07_ACCOUNT_H
#define ACE1309_WEEK07_ACCOUNT_H

class SavingsAccount {
private:
    static double annual_interest_rate;
    double savings_balance;

public:
    static void modify_interest_rate(double);
    SavingsAccount(double);
    void calculate_monthly_interest();
    void print_balance() const;
};

#endif // ACE1309_WEEK07_ACCOUNT_H
