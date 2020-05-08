# Inheritance 2

## Exercise

### 1-1.

`commission_employee.h`

```cpp
#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>

using namespace std;

class CommissionEmployee {
protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
    double earnings() const;
    double getCommissionRate() const;
    string getFirstName() const;
    double getGrossSales() const;
    string getLastName() const;
    string getSocialSecurityNumber() const;
    void print() const;
    void setCommissionRate(double);
    void setFirstName(const string&);
    void setGrossSales(double);
    void setLastName(const string&);
    void setSocialSecurityNumber(const string&);
};

#endif
```

`commission_employee.cpp`

```cpp
#include "commission_employee.h"
#include <iostream>
#include <string>

using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}

double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

string CommissionEmployee::getFirstName() const {
    return firstName;
}

double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

string CommissionEmployee::getLastName() const {
    return lastName;
}

string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void CommissionEmployee::print() const {
    cout << "commission employee: " << firstName << ' ' << lastName << endl
         << "social security number: " << socialSecurityNumber << endl
         << "gross sales: " << grossSales << endl
         << "commission rate: " << commissionRate << endl;
}

void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0;
}

void CommissionEmployee::setFirstName(const string& first) {
    firstName = first;
}

void CommissionEmployee::setGrossSales(double sales) {
    grossSales = sales < 0.0 ? 0 : sales;
}

void CommissionEmployee::setLastName(const string& last) {
    lastName = last;
}

void CommissionEmployee::setSocialSecurityNumber(const string& ssn) {
    socialSecurityNumber = ssn;
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

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate, double salary)
: CommissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + commissionRate * grossSales;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried commission employee: " << firstName << ' ' << lastName << endl
         << "social security number: " << socialSecurityNumber << endl
         << "gross sales: " << grossSales << endl
         << "commission rate: " << commissionRate << endl
         << "base salary: " << baseSalary << endl;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary < 0.0 ? 0 : salary;
}
```

### 1-2.

`commission_employee.h`

```cpp
#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>

using namespace std;

class CommissionEmployee {
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
    double earnings() const;
    double getCommissionRate() const;
    string getFirstName() const;
    double getGrossSales() const;
    string getLastName() const;
    string getSocialSecurityNumber() const;
    void print() const;
    void setCommissionRate(double);
    void setFirstName(const string&);
    void setGrossSales(double);
    void setLastName(const string&);
    void setSocialSecurityNumber(const string&);
};

#endif
```

`commission_employee.cpp`

```cpp
#include "commission_employee.h"
#include <iostream>
#include <string>

using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
: firstName(first), lastName(lastName), socialSecurityNumber(ssn) {
    setGrossSales(sales);
    setCommissionRate(rate);
}

double CommissionEmployee::earnings() const {
    return getCommissionRate() * getGrossSales();
}

double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

string CommissionEmployee::getFirstName() const {
    return firstName;
}

double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

string CommissionEmployee::getLastName() const {
    return lastName;
}

string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void CommissionEmployee::print() const {
    cout << "commission employee: " << getFirstName() << ' ' << getLastName() << endl
         << "social security number: " << getSocialSecurityNumber << endl
         << "gross sales: " << getGrossSales() << endl
         << "commission rate: " << getCommissionRate() << endl;
}

void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0;
}

void CommissionEmployee::setFirstName(const string& first) {
    firstName = first;
}

void CommissionEmployee::setGrossSales(double sales) {
    grossSales = sales < 0.0 ? 0 : sales;
}

void CommissionEmployee::setLastName(const string& last) {
    lastName = last;
}

void CommissionEmployee::setSocialSecurityNumber(const string& ssn) {
    socialSecurityNumber = ssn;
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
    cout << "base-salaried " << endl;
    CommissionEmployee::print();
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary < 0.0 ? 0 : salary;
}
```

### 1-3.

`main.cpp`

```cpp
#include <iomanip>
#include <iostream>
#include "base_plus_commission_employee.h"

using namespace std;

int main() {
    BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);
    cout << fixed << setprecision(2);
    cout << "Employee information obtained by get functions: " << endl
         << "First name is " << employee.getFirstName() << endl
         << "Last name is " << employee.getLastName() << endl
         << "Social security number is " << employee.getSocialSecurityNumber() << endl
         << "Gross sales is " << employee.getGrossSales() << endl
         << "Commission rate is " << employee.getCommissionRate() << endl
         << "Base salary is " << employee.getBaseSalary() << endl;

    employee.setBaseSalary(1000);

    cout << "Updated employee information output by print function: " << endl;
    employee.print();

    cout << "Employee's earnings: $" << employee.earnings() << endl;
    return 0;
}
```

### 1-4.

`commission_employee.cpp`

```cpp
#include "commission_employee.h"
#include <iostream>
#include <string>

using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
: firstName(first), lastName(lastName), socialSecurityNumber(ssn) {
    setGrossSales(sales);
    setCommissionRate(rate);
    cout << "CommissionEmployee constructor: " << endl;
    print();
    cout << endl;
}

CommissionEmployee::~CommissionEmployee() {
    cout << "CommissionEmployee destructor: " << endl;
    print();
    cout << endl;
}
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
    cout << "BasePlusCommissionEmployee constructor: " << endl;
    print();
    cout << endl;
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
    cout << "BasePlusCommissionEmployee destructor: " << endl;
    print();
    cout << endl;
}
```

`main.cpp`

```cpp
#include <iomanip>
#include <iostream>
#include "base_plus_commission_employee.h"
#include "commission_employee.h"

using namespace std;

int main() {
    cout << fixed << setprecision(2);
    {
        CommissionEmployee employee1("Bob", 5000);
    }
    cout << endl;
    BasePlusCommissionEmployee employee2("Lisa", 2000, 800);
    cout << endl;
    BasePlusCommissionEmployee employee3("Mark", 8000, 2000);
    cout << endl;
    return 0;
}
```

## Homework

### 1. 수하물 서비스에 대한 클래스를 정의를 이해하고, 파생되는 `TwoDayPackage`와 `OvernightPackage`서비스를 `Package` 클래스를 상속하도록 구현하라.

1. 기본 클래스 `Package`는 다음과 같은 데이터 멤버를 가지고 있다.
    - `sender`
        - `name`
        - `address`
        - `city`
        - `state`
        - `zip code`
    - `recipient`
        - `name`
        - `address`
        - `city`
        - `state`
        - `zip code`
    - `weight` (ounce)
    - `cost` (per ounce)
2. `TwoDayPackage` 클래스는 `Package`의 함수와 변수를 상속받고 `flat_fee`라는 데이터 멤버를 포함해야 한다.
    - `TwoDayPackage`의 요금은 추가 요금이 발생한다.
    - `Package`를 상속받는 `TwoDayPackage` 클래스와 생성자를 정의
    - `flat_fee`에 대한 `get/set` 함수를 정의
    - `flat_fee`를 고려한 운임 요금을 반환하는 함수를 정의
3. `OvernightPackage` 클래스는 `Package`의 함수와 변수를 상속받고 `overnight_fee`라는 데이터 멤버를 포함해야 한다.
    - `OvernightPackage`의 요금은 추가 요금이 발생한다.
    - `Package`를 상속받는 `OvernightPackage` 클래스와 생성자를 정의
    - `overnight_fee`에 대한 `get/set` 함수를 정의
    - `overnight_fee`를 고려한 운임 요금을 반환하는 함수를 정의

See [HW 1](./hw01/)
