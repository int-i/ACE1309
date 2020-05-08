#ifndef ACE1309_WEEK02_HW01_ACCOUNT_H
#define ACE1309_WEEK02_HW01_ACCOUNT_H

class Account {
private:
    int balance;

public:
    Account(int balance);
    void credit(int amount);
    void debit(int amount);
    int get_balance() const;
};

#endif // ACE1309_WEEK02_HW01_ACCOUNT_H
