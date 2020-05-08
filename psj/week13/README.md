# Polymorphism 1

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
    cout << "commission employee: " << getFirstName()<< ' ' << getLastName() << endl
         << "social security number: " << getSocialSecurityNumber() << endl
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
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "base salary: " << baseSalary << endl;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary < 0.0 ? 0 : salary;
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
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, 0.6);
    CommissionEmployee* commissionEmployeePtr = 0;
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);
    BasePlusCommissionEmployee* basePlusCommissionEmployeePtr = 0;

    cout << fixed << setprecision(2);

    cout << "Print base-class and derived-class objects:" << endl;
    commissionEmployee.print();
    cout << endl;
    basePlusCommissionEmployee.print();
    cout << endl;

    commissionEmployeePtr = &commissionEmployee;
    cout << "Calling print with base-class pointer to base-class object invokes base-class print function:" << endl;
    commissionEmployeePtr->print();
    cout << endl;

    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "Calling print with derived-class pointer to derived-class object invokes derived-class print function:" << endl;
    basePlusCommissionEmployeePtr->print();
    cout << endl;

    commissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "Calling print with base-class pointer to derived-class object invokes base-class print function on that derived-class object:" << endl;
    commissionEmployeePtr->print();
    cout << endl;
    return 0;
}
```

### 1-2.

`main.cpp`

```cpp
#include "base_plus_commission_employee.h"
#include "commission_employee.h"

int main() {
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, 0.06);
    BasePlusCommissionEmployee* basePlusCommissionEmployeePtr = 0;
    basePlusCommissionEmployeePtr = &commissionEmployee; // error
    return 0;
}
```

### 1-3.

`main.cpp`

```cpp
#include <iomanip>
#include <iostream>
#include <string>
#include "base_plus_commission_employee.h"
#include "commission_employee.h"

using namespace std;

int main() {
    CommissionEmployee* commissionEmployeePtr = 0;
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);

    commissionEmployeePtr = &basePlusCommissionEmployee;

    string firstName = commissionEmployeePtr->getFirstName();
    string lastName = commissionEmployeePtr->getLastName();
    string ssn = commissionEmployeePtr->getSocialSecurityNumber();
    double grossSales = commissionEmployeePtr->getGrossSales();
    double commissionRate = commissionEmployeePtr->getCommissionRate();

    // error
    double baseSalary = commissionEmployeePtr->getBaseSalay();
    commissionEmployeePtr->setBaseSalary(500);
    return 0;
}
```

### 1-4.

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
    virtual double earnings() const;
    double getCommissionRate() const;
    string getFirstName() const;
    double getGrossSales() const;
    string getLastName() const;
    string getSocialSecurityNumber() const;
    virtual void print() const;
    void setCommissionRate(double);
    void setFirstName(const string&);
    void setGrossSales(double);
    void setLastName(const string&);
    void setSocialSecurityNumber(const string&);
};

#endif
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
    virtual double earnings() const;
    double getBaseSalary() const;
    virtual void print() const;
    void setBaseSalary(double);
};

#endif
```

`main.cpp`

```cpp
#include <iomanip>
#include <iostream>
#include "base_plus_commission_employee.h"
#include "commission_employee.h"

using namespace std;

int main() {
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, 0.6);
    CommissionEmployee* commissionEmployeePtr = 0;
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);
    BasePlusCommissionEmployee* basePlusCommissionEmployeePtr = 0;

    cout << fixed << setprecision(2);

    cout << "Invoking print function on base-class and derived-class objects with static binding:" << endl;
    commissionEmployee.print();
    cout << endl;
    basePlusCommissionEmployee.print();
    cout << endl;

    cout << "Invoking print function on base-class and derived-class objects with dynamic binding:" << endl;

    commissionEmployeePtr = &commissionEmployee;
    cout << "Calling virtual function print with base-class pointer to base-class object invokes base-class print function:" << endl;
    commissionEmployeePtr->print();
    cout << endl;

    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "Calling virtual function print with derived-class pointer to derived-class object invokes derived-class print function:" << endl;
    basePlusCommissionEmployeePtr->print();
    cout << endl;

    commissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "Calling virtual function print with base-class pointer to derived-class object invokes derived-class print function:" << endl;
    commissionEmployeePtr->print();
    cout << endl;
    return 0;
}
```

## Homework

### 1. 아래와 같이 설계된 `Shape` 계층을 구현하라.

1. 각 `TwoDimensionalShape`는 2차원 도형의 면적을 계산하는 함수 `getArea`를 제공해야 한다.
2. 각 `ThreeDimensionalShape`는 3차원 도형의 표면적과 부피를 계산하는 멤버함수 `getArea`와 `getVolume`을 제공해야 한다.
3. 계층의 각 구체 클래스 오브젝트에 대한 `Shape` 포인터의 벡터를 사용하는 프로그램을 작성하라.
4. 프로그램은 각 벡터 요소가 가리키는 오브젝트를 출력해야 한다. 또 벡터의 모든 도형을 처리하는 루프에서 각 도형이 `TwoDimensionalShape`인지 `ThreeDimensionalShape`인지 결정한다.
5. 도형이 `TwoDimensionalShape`이면 면적을 출력하라.
6. 도형이 `ThreeDimensionalShape`이면 면적과 부피를 출력하라.

See [HW 1](./hw01/)
