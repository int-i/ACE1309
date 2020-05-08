#include <iomanip>
#include <iostream>
#include <vector>
#include "package.h"
#include "person.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Person lou{ "Lou Brown", "1 Main St.", "Boston", "MA", "11111" };
    Person mary{ "Mary Smith", "7 Elm St.", "New York", "NY", "22222" };
    Person lisa{ "Lisa Klein", "5 Broadway", "Somerville", "MA", "33333" };
    Person bob{ "Bob George", "21 Pine Rd.", "Cambridge", "MA", "44444" };
    Person ed{ "Ed Lewis", "2 Oak St.", "Boston", "MA", "55555" };
    Person don{ "Don Kelly", "9 Main St.", "Denver", "CO", "66666" };

    Package* normal_package_ptr = new Package(lou, mary, 8.5, 0.5);
    TwoDayPackage* two_day_package_ptr = new TwoDayPackage(lisa, bob, 10.5, 0.65, 2);
    OvernightPackage* overnight_package_ptr = new OvernightPackage(ed, don, 12.25, 0.7, 0.25);
    std::vector<Package*> package_ptrs = { normal_package_ptr, two_day_package_ptr, overnight_package_ptr };

    int i = 0;
    double total = 0;
    for (const Package* const package_ptr : package_ptrs) {
        const Person& sender = package_ptr->get_sender();
        const Person& recipient = package_ptr->get_recipient();
        double cost = package_ptr->calculate_cost();
        std::cout << "Package " << ++i << std::endl
                  << std::endl
                  << "Sender: " << std::endl
                  << sender.name << std::endl
                  << sender.address << std::endl
                  << sender.city << ", " << sender.state << " " << sender.zipCode << std::endl
                  << std::endl
                  << "Recipient: " << std::endl
                  << recipient.name << std::endl
                  << recipient.address << std::endl
                  << recipient.city << ", " << recipient.state << " " << recipient.zipCode << std::endl
                  << std::endl
                  << "Cost: $" << cost << std::endl
                  << std::endl;
        total += cost;
    }
    std::cout << "Total shipping cost: $" << total << std::endl;

    package_ptrs.clear();
    delete normal_package_ptr;
    delete two_day_package_ptr;
    delete overnight_package_ptr;
    return 0;
}
