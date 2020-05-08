#ifndef ACE1309_WEEK11_ACCOUNT_H
#define ACE1309_WEEK11_ACCOUNT_H

class Account {
private:
    int balance;

public:
    Account(int balance);
    void credit(int amount);
    void debit(int amount);
    int get_balance() const;
    void print() const;
    void set_balance(int balance);
};

class CheckingAccount : public Account {
private:
    int balance;
    int transaction_fee;

public:
    CheckingAccount(int balance, int transaction_fee);
    void credit(int amount);
    void debit(int amount);
};

class SavingAccount : public Account {
private:
    double interest_rate;

public:
    SavingAccount(int balance, double interest_rate);
    double calculate_interest() const;
};

#endif // ACE1309_WEEK11_ACCOUNT_H
