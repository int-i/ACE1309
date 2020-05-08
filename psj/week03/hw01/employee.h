#ifndef ACE1309_WEEK03_HW01_EMPLOYEE_H
#define ACE1309_WEEK03_HW01_EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string first_name;
    std::string last_name;
    int monthly_salary;

public:
    Employee(const std::string& first_name, const std::string& last_name, int monthly_salary);
    std::string get_first_name() const;
    std::string get_last_name() const;
    int get_monthly_salary() const;
    void set_first_name(std::string first_name);
    void set_last_name(std::string last_name);
    void set_monthly_salary(int monthly_salary);
};

#endif // ACE1309_WEEK03_HW01_EMPLOYEE_H
