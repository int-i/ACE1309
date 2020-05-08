#include <iostream>
#include "employee.h"

int main() {
    Employee lisa("Lisa", "Robert", 4500);
    Employee mark("Mark", "Stein", 4000);

    std::cout << "Employees' yearly salaries: " << std::endl
              << lisa.get_first_name() << " " << lisa.get_last_name() << ": $" << (lisa.get_monthly_salary() * 12) << std::endl
              << mark.get_first_name() << " " << mark.get_last_name() << ": $" << (mark.get_monthly_salary() * 12) << std::endl
              << std::endl;

    lisa.set_monthly_salary(lisa.get_monthly_salary() * 1.1);
    mark.set_monthly_salary(mark.get_monthly_salary() * 1.1);

    std::cout << "Employees' yearly salaries after 10% raises: " << std::endl
              << lisa.get_first_name() << " " << lisa.get_last_name() << ": $" << (lisa.get_monthly_salary() * 12) << std::endl
              << mark.get_first_name() << " " << mark.get_last_name() << ": $" << (mark.get_monthly_salary() * 12) << std::endl;
    return 0;
}
