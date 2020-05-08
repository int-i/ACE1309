# Inheritance 1

## Exercise

### 1.

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

`main.cpp`

```cpp
#include <iomanip>
#include <iostream>
#include "commission_employee.h"

using namespace std;

int main() {
    CommissionEmployee employee("Sue", "Jones", "222-22-2222", 10000, 0.06);
    cout << fixed << setprecision(2);
    cout << "Employee information obtained by getter funtions:" << endl
         << "First name is " << employee.getFirstName() << endl
         << "Last name is " << employee.getLastName() << endl
         << "Social security number is " << employee.getSocialSecurityNumber() << endl
         << "Gross sales is " << employee.getGrossSales() << endl
         << "Commission rate is " << employee.getCommissionRate() << endl;
    employee.setGrossSales(8000);
    employee.setCommissionRate(0.1);
    cout << "Updated employee information output by print function:" << endl;
    employee.print();
    cout << "Employee's earnings: $" << employee.earnings() << endl;
    return 0;
}
```

### 2-1.

`base_plus_commission_employee.h`

```cpp
#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include <string>

using namespace std;

class BasePlusCommissionEmployee {
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
    double baseSalary;

public:
    BasePlusCommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
    double earnings() const;
    double getBaseSalary() const;
    double getCommissionRate() const;
    string getFirstName() const;
    double getGrossSales() const;
    string getLastName() const;
    string getSocialSecurityNumber() const;
    void print() const;
    void setBaseSalary(double);
    void setCommissionRate(double);
    void setFirstName(const string&);
    void setGrossSales(double);
    void setLastName(const string&);
    void setSocialSecurityNumber(const string&);
};

#endif
```

`base_plus_commission_employee.cpp`

```cpp
#include "base_plus_commission_employee.h"
#include <iostream>
#include <string>

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate, double salary) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + commissionRate * grossSales;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

double BasePlusCommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

string BasePlusCommissionEmployee::getFirstName() const {
    return firstName;
}

double BasePlusCommissionEmployee::getGrossSales() const {
    return grossSales;
}

string BasePlusCommissionEmployee::getLastName() const {
    return lastName;
}

string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void BasePlusCommissionEmployee::print() const {
    cout << "commission employee: " << firstName << ' ' << lastName << endl
         << "social security number: " << socialSecurityNumber << endl
         << "gross sales: " << grossSales << endl
         << "commission rate: " << commissionRate << endl
         << "base salary: " << baseSalary << endl;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary < 0.0 ? 0 : salary;
}

void BasePlusCommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0;
}

void BasePlusCommissionEmployee::setFirstName(const string& first) {
    firstName = first;
}

void BasePlusCommissionEmployee::setGrossSales(double sales) {
    grossSales = sales < 0.0 ? 0 : sales;
}

void BasePlusCommissionEmployee::setLastName(const string& last) {
    lastName = last;
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const string& ssn) {
    socialSecurityNumber = ssn;
}
```

### 2-2.

`base_plus_commission_employee.h`

```cpp
#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include "commission_employee.h"
#include <string>

using namespace std;

class BasePlusCommissionEmployee:public CommissionEmployee {
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
    cout << "commission employee: " << firstName << ' ' << lastName << endl
         << "social security number: " << socialSecurityNumber << endl
         << "gross sales: " << grossSales << endl
         << "commission rate: " << commissionRate << endl
         << "base salary: " << baseSalary << endl;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary < 0.0 ? 0 : salary;
}
```

## Homework

### 1. 아래 설명을 만족하는 클래스를 작성하라.

은행의 모든 고객들은 계좌에 돈을 입금하고 계좌로부터 돈을 인출할 수 있다.
또한 여러 가지 형태의 계좌들이 존재한다.
기본적은 은행 입출금에 대한 함수를 포함하는 `Account` 클래스를 기본 클래스로 정의하고, 이를 상속받는 예금계좌 `SavingAccount` 클래스와 입출금 계좌 `CheckingAccount` 클래스를 정의하라.

1. `SavingAccount`의 생성자는 초기 잔고와 함께 `SavingAccount`의 이율에 대한 초기값을 전달받아야 한다.
2. `SavingAccount`는 계좌에 적립된 이자를 가리키는 `double`형 값을 반환하는 `public` 멤버 함수 `calculate_interest`를 제공해야 한다. `calculate_interest`는 계좌의 잔고에 `interest_rate`를 곱하여 이자를 계산해야 한다.
3. `CheckingAccount` 클래스는 `Account` 클래스의 함수화 변수를 상속받고 추가적으로 `transaction_fee`를 생성자에서 초기값을 전달받아야 한다.
4. `CheckingAccount` 클래스에는 `credit`, `debit` 맴버 함수를 호출 시 거래에 따른 `transaction_fee`가 발생하여 수수료를 부과해야 한다. (거래 시 계좌 잔고가 수수료를 계산한 금액보다 적을 경우 거래 실패 메시지를 출력한다)

See [HW 1](./hw01/)
