# Polymorphism 2

## Exercise

### 1.

`employee.h`

```cpp
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;

public:
    Employee(const string&, const string&, const string&);
    virtual double earnings() const = 0;
    string getFirstName() const;
    string getLastName() const;
    string getSocialSecurityNumber() const;
    virtual void print() const;
    void setFirstName(const string&);
    void setLastName(const string&);
    void setSocialSecurityNumber(const string&);
};

#endif
```

`employee.cpp`

```cpp
#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

Employee::Employee(const string& first, const string& last, const string& ssn)
: firstName(first), lastName(last), socialSecurityNumber(ssn) {}

string Employee::getFirstName() const {
    return firstName;
}

string Employee::getLastName() const {
    return lastName;
}

string Employee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void Employee::print() const {
    cout << getFirstName() << ' ' << getLastName() << endl
         << "social security number: " << getSocialSecurityNumber() << endl;
}

void Employee::setFirstName(const string& first) {
    firstName = first;
}

void Employee::setLastName(const string& last) {
    lastName = last;
}

void Employee::setSocialSecurityNumber(const string& ssn) {
    socialSecurityNumber = ssn;
}
```

`salaried_employee.h`

```cpp
#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;

class SalariedEmployee : public Employee {
protected:
    double weeklySalary;

public:
    SalariedEmployee(const string&, const string&, const string&, double = 0.0);
    double earnings() const;
    double getWeeklySalary() const;
    void print() const;
    void setWeeklySalary(double);
};

#endif
```

`salaried_employee.cpp`

```cpp
#include "salaried_employee.h"
#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

SalariedEmployee::SalariedEmployee(const string& first, const string& last, const string& ssn, double salary)
: Employee(first, last, ssn) {
    setWeeklySalary(salary);
}

double SalariedEmployee::earnings() const {
    return getWeeklySalary();
}

double SalariedEmployee::getWeeklySalary() const {
    return weeklySalary;
}

void SalariedEmployee::print() const {
    cout << "salaried employee: ";
    Employee::print();
    cout << "weekly salary: " << getWeeklySalary() << endl;
}

void SalariedEmployee::setWeeklySalary(double salary) {
    weeklySalary = (salary < 0) ? 0 : salary;
}
```

`hourly_employee.h`

```cpp
#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;

class HourlyEmployee : public Employee {
protected:
    double wage;
    double hours;

public:
    HourlyEmployee(const string&, const string&, const string&, double = 0.0, double =0.0);
    double earnings() const;
    double getHours() const;
    double getWage() const;
    void print() const;
    void setHours(double);
    void setWage(double);
};

#endif
```

`hourly_employee.cpp`

```cpp
#include "hourly_employee.h"
#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

HourlyEmployee::HourlyEmployee(const string& first, const string& last, const string& ssn, double hourlyWage, double hoursWorked)
: Employee(first, last, ssn) {
    setWage(hourlyWage);
    setHours(hoursWorked);
}

double HourlyEmployee::earnings() const {
    if (getHours() <= 40) {
        return getWage() * getHours();
    }
    return 40 * getWage() + (getHours() - 40) * getWage() * 1.5;
}

double HourlyEmployee::getHours() const {
    return hours;
}

double HourlyEmployee::getWage() const {
    return wage;
}

void HourlyEmployee::print() const {
    cout << "hourly employee: ";
    Employee::print();
    cout << "hourly wage: " << getWage() << endl
         << "hours worked: " << getHours() << endl;
}

void HourlyEmployee::setHours(double hoursWorked) {
    hours = hoursWorked >= 0 && hoursWorked <= 168 ? hoursWorked : 0;
}

void HourlyEmployee::setWage(double hourlyWage) {
    wage = hourlyWage < 0 ? 0 : hourlyWage;
}
```

`commission_employee.h`

```cpp
#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;

class CommissionEmployee : public Employee {
protected:
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
    virtual double earnings() const;
    double getCommissionRate() const;
    double getGrossSales() const;
    virtual void print() const;
    void setCommissionRate(double);
    void setGrossSales(double);
};

#endif
```

`commission_employee.cpp`

```cpp
#include "commission_employee.h"
#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
: Employee(first, last, ssn) {
    setGrossSales(sales);
    setCommissionRate(rate);
}

double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}

double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

void CommissionEmployee::print() const {
    cout << "commission employee: ";
    Employee::print();
    cout << "gross sales: " << getGrossSales() << endl
         << "commission rate: " << getCommissionRate() << endl;
}

void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = rate > 0 && rate < 1 ? rate : 0;
}

void CommissionEmployee::setGrossSales(double sales) {
    grossSales = sales < 0 ? 0 : sales;
}
```

`base_plus_commission_employee.h`

```cpp
#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include <string>
#include "commission_employee.h"

using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
    double earnings() const;
    double getBaseSalary() const;
    void print() const;
    void setBaseSalary(double);
};

#endif
```

`base_plus_commission_employee.cpp`

```cpp
#include "base_plus_commission_employee.h"
#include <iostream>
#include <string>
#include "commission_employee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate, double salary)
: CommissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionEmployee::earnings();
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "base salary: " << baseSalary << endl;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary < 0 ? 0 : salary;
}
```

`main.cpp`

```cpp
#include <iomanip>
#include <iostream>
#include <vector>
#include "base_plus_commission_employee.h"
#include "commission_employee.h"
#include "employee.h"
#include "hourly_employee.h"
#include "salaried_employee.h"

using namespace std;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main() {
    cout << fixed << setprecision(2);

    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800);
    HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, 0.06);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, 0.04, 300);

    cout << "Employees processed individually using static binding: " << endl
         << endl;
    salariedEmployee.print();
    cout << "earned $" << salariedEmployee.earnings() << endl
         << endl;
    hourlyEmployee.print();
    cout << "earned $" << hourlyEmployee.earnings() << endl
         << endl;
    commissionEmployee.print();
    cout << "earned $" << commissionEmployee.earnings() << endl
         << endl;
    basePlusCommissionEmployee.print();
    cout << "earned $" << basePlusCommissionEmployee.earnings() << endl
         << endl;

    vector<Employee*> employees{ &salariedEmployee, &hourlyEmployee, &commissionEmployee, &basePlusCommissionEmployee };
    cout << "Employees processed polymorphically via dynamic binding: " << endl
         << endl;

    cout << "Virtual function calls made off base-class pointers: " << endl
         << endl;
    for (Employee* employee : employees) {
        virtualViaPointer(employee);
    }

    cout << "Virtual function calls made off base-class references: " << endl
         << endl;
    for (Employee* employee : employees) {
        virtualViaReference(*employee);
    }
    return 0;
}

void virtualViaPointer(const Employee* const baseClassPtr) {
    baseClassPtr->print();
    cout << "earned $" << baseClassPtr->earnings() << endl
         << endl;
}

void virtualViaReference(const Employee& baseClassRef) {
    baseClassRef.print();
    cout << "earned $" << baseClassRef.earnings() << endl
         << endl;
}
```

## Homework

### 1. 다형성을 이용하여 아래의 조건을 만족하는 프로그램을 구현하라.

프로그램은 클래스 `TwoDayPackage`와 `OvernightPackage` 오브젝트에 대한 `Package` 포인터의 벡터를 사용하도록 한다. 각각의 `Package`는 `get` 함수를 사용하여 발송자와 수신자의 정보를 나타낸다. 운임 요금을 나타내는 `calculate_cost` 함수는 다형성을 이용하여 각각의 `Package`에 맞는 운임 요금을 출력해 주어야 한다.

1. 12주 차 과제에 정의한 클래스를 사용한다.
2. `Package`의 포인터형 객체의 `vector`를 사용하여 동적 바인딩을 한다.
3. 운임 요금을 반환하는 함수는 가상함수로 정의하여 호출하도록 한다.
4. 아래의 실행 코드를 이용하여 출력문이 나타나도록 각각의 헤더 파일을 재정의한다.

See [HW 1](./hw01/)
