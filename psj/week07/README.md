# Classes 4

## Exercise

### 1.

`employee.h`

```cpp
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
    static int count;
    char* firstName;
    char* lastName;

public:
    static int getCount();
    Employee(const char* const, const char* const);
    ~Employee();
    const char* getFirstName() const;
    const char* getLastName() const;
};

#endif
```

`employee.cpp`

```cpp
#include "Employee.h"
#include <cstring>
#include <iostream>

using namespace std;

int Employee::count = 0;

int Employee::getCount() {
    return count;
}

Employee::Employee(const char* const first, const char* const last) {
    firstName = new char[strlen(first) + 1];
    strcpy(firstName, first);

    lastName = new char[strlen(last) + 1];
    strcpy(lastName, last);

    count++;

    cout << "Employee object constructor for " << firstName << " " << lastName << " called" << endl;
}

Employee::~Employee() {
    cout << "~Employee() called for  " << firstName << " " << lastName << endl;
    delete[] firstName;
    delete[] lastName;
    count--;
}

const char* Employee::getFirstName() const {
    return firstName;
}

const char* Employee::getLastName() const {
    return lastName;
}
```

`main.cpp`

```cpp
#include <iostream>
#include "Employee.h"

using namespace std;

int main() {
    cout << "Number of employees before instantiation of any objects is " << Employee::getCount() << endl;

    Employee* e1Ptr = new Employee("Susan", "Baker");
    Employee* e2Ptr = new Employee("Robert", "Jones");

    cout << "Number of employees after objects are instantiationd is " << e1Ptr->getCount() << endl;

    cout << "Employee 1: " << e1Ptr->getFirstName() << " " << e1Ptr->getLastName() << endl
         << "Employee 2: " << e2Ptr->getFirstName() << " " << e2Ptr->getLastName() << endl;

    delete e1Ptr;
    e1Ptr = 0;
    delete e2Ptr;
    e2Ptr = 0;

    cout << "Number of employees after objects are deleted is " << Employee::getCount() << endl;
    return 0;
}
```

## Homework

### 1. 주어진 UML 구조와 기능 설명을 이용하여 SavingAccount 클래스와 이를 테스트하는 코드를 작성하라.

1. 각 예금자의 연이율을 저장하기 위해 정적 데이터 멤버 `annualInterestRate`를 사용한다
2. 클래스의 각 멤버는 예금자가 현재 예금 잔고에 보유한 금액을 가리키는 `private` 데이터 멤버 `savingBalance`를 포함한다.
3. `savingBalance`와 `annualinterestrate`를 곱하고 12로 나누어 월 이자를 계산하는 멤버함수 `calculatemonthlyinterest`를 제공하라.
4. 이 이자를 `savingsBalance`에 더 더해야 한다.
5. 정적 `annualInterestRate`를 새 값으로 설정하는 정적 멤버함수 `modifyInterestRate`를 제공하라.
6. 클래스 `SavingAccount`의 두 오브젝트 `saver1`과 `saver2`를 생성하고 각각 $2000.00과 $3000.00의 금액으로 초기화한다.
7. `anualInterestRate`를 3%로 설정한다.
8. 월 이자를 계산하고 각 예금자의 새로운 잔고를 출력한다.
9. 그리고 `annualInterestRate`를 4%로 설정하고 다음달의 이자를 계산하고 각 예금자의 새로운 잔고를 출력한다.

See [HW 1](./hw01/)
