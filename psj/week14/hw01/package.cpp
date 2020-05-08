#include "package.h"
#include "person.h"

Package::Package(const Person& sender, const Person& recipient, double weight, double cost)
: sender(sender),
  recipient(recipient),
  weight(weight >= 0 ? weight : 0),
  cost(cost >= 0 ? cost : 0) {}

double Package::calculate_cost() const {
    return cost * weight;
}

double Package::get_cost() const {
    return cost;
}

const Person& Package::get_recipient() const {
    return recipient;
}

const Person& Package::get_sender() const {
    return sender;
}

double Package::get_weight() const {
    return weight;
}

void Package::set_cost(double cost) {
    this->cost = cost;
}

void Package::set_sender(const Person& sender) {
    this->sender = sender;
}

void Package::set_recipient(const Person& recipient) {
    this->recipient = recipient;
}

void Package::set_weight(double weight) {
    this->weight = weight;
}

OvernightPackage::OvernightPackage(const Person& sender, const Person& recipient, double weight, double cost, double overnight_fee)
: Package(sender, recipient, weight, cost),
  overnight_fee(overnight_fee >= 0 ? overnight_fee : 0) {}

double OvernightPackage::calculate_cost() const {
    return Package::calculate_cost() + (overnight_fee * get_weight());
}

double OvernightPackage::get_overnight_fee() const {
    return overnight_fee;
}

void OvernightPackage::set_overnight_fee(double overnight_fee) {
    this->overnight_fee = overnight_fee;
}

TwoDayPackage::TwoDayPackage(const Person& sender, const Person& recipient, double weight, double cost, double flat_fee)
: Package(sender, recipient, weight, cost),
  flat_fee(flat_fee >= 0 ? flat_fee : 0) {}

double TwoDayPackage::calculate_cost() const {
    return Package::calculate_cost() + flat_fee;
}

double TwoDayPackage::get_flat_fee() const {
    return flat_fee;
}

void TwoDayPackage::set_flat_fee(double flat_fee) {
    this->flat_fee = flat_fee;
}
