#ifndef ACE1309_WEEK14_PACKAGE_H
#define ACE1309_WEEK14_PACKAGE_H

#include "person.h"

class Package {
private:
    Person sender;
    Person recipient;
    double weight; // [oz]
    double cost; // [$/oz]
public:
    Package(const Person& sender, const Person& recipient, double weight, double cost);
    virtual ~Package() = default;
    virtual double calculate_cost() const;
    double get_cost() const;
    const Person& get_recipient() const;
    const Person& get_sender() const;
    double get_weight() const;
    void set_cost(double cost);
    void set_sender(const Person& sender);
    void set_recipient(const Person& recipient);
    void set_weight(double weight);
};

class OvernightPackage : public Package {
private:
    double overnight_fee;

public:
    OvernightPackage(const Person& sender, const Person& recipient, double weight, double cost, double overnight_fee);
    virtual ~OvernightPackage() = default;
    virtual double calculate_cost() const override;
    double get_overnight_fee() const;
    void set_overnight_fee(double overnight_fee);
};

class TwoDayPackage : public Package {
private:
    double flat_fee;

public:
    TwoDayPackage(const Person& sender, const Person& recipient, double weight, double cost, double flat_fee);
    virtual ~TwoDayPackage() = default;
    virtual double calculate_cost() const override;
    double get_flat_fee() const;
    void set_flat_fee(double flat_fee);
};

#endif // ACE1309_WEEK14_PACKAGE_H
