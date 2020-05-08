#include "employee.h"
#include <string>

Employee::Employee(const std::string& first_name, const std::string& last_name, int monthly_salary)
: first_name(first_name),
  last_name(last_name),
  monthly_salary(monthly_salary > 0 ? monthly_salary : 0) {}

std::string Employee::get_first_name() const {
    return first_name;
}

std::string Employee::get_last_name() const {
    return last_name;
}

int Employee::get_monthly_salary() const {
    return monthly_salary;
}

void Employee::set_first_name(std::string first_name) {
    first_name = first_name;
}

void Employee::set_last_name(std::string last_name) {
    last_name = last_name;
}

void Employee::set_monthly_salary(int monthly_salary) {
    this->monthly_salary = monthly_salary > 0 ? monthly_salary : 0;
}
