#include <iostream>
#include "package.h"
#include "person.h"

int main() {
    Person sender{ "Kim", "ADDRESS", "CITY", "STATE", "ZIP" };
    Person recipient{ "Lee", "address", "city", "state", "zip" };
    Package package0(sender, recipient, 100, 1.5);
    std::cout << "package0 cost: " << package0.calculate_cost() << std::endl
              << "package0 sender: " << package0.get_sender().name << std::endl
              << "package0 recipient: " << package0.get_recipient().name << std::endl;
    TwoDayPackage package1(sender, recipient, 100, 2.0, 100);
    std::cout << "package1 cost: " << package1.calculate_cost() << std::endl;
    OvernightPackage package2(sender, recipient, 100, 2.5, 0.5);
    std::cout << "package2 cost: " << package2.calculate_cost() << std::endl;
    return 0;
}
