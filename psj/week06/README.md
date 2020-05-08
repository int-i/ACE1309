# Classes 3

## Exercise

### 1.

`date.h`

```cpp
#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int month;
    int day;
    int year;
    int checkDay(int) const;

public:
    Date(int = 1, int = 1, int = 1900);
    ~Date();
    void print() const;
};

#endif
```

`date.cpp`

```cpp
#include "date.h"
#include <iostream>

using namespace std;

Date::Date(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= 12)
    {
        month = mn;
    }
    else
    {
        month = 1;
        cout << "Invaild month (" << mn << ") set to 1." << endl;
    }

    year = yr;
    day = checkDay(dy);

    cout << "Date object constructor for date ";
    print();
    cout << endl;
}

Date::~Date()
{
    cout << "Date object destructor for date ";
    print();
    cout << endl;
}

int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (testDay > 0 && testDay <= daysPerMonth[month])
    {
        return testDay;
    }

    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    {
        return testDay;
    }

    cout << "Invalid day (" << testDay << ") set to  1." << endl;
    return 1;
}

void Date::print() const
{
    cout << month << "/" << day << "/" << year;
}
```

`employee.h`

```cpp
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "date.h"

class Employee
{
private:
    char firstName[25];
    char lastName[25];
    const Date birthDate;
    const Date hireDate;

public:
    Employee(const char *const, const char *const, const Date &, const Date &);
    ~Employee();
    void print() const;
};

#endif
```

`employee.cpp`

```cpp
#include "employee.h"
#include <cstring>
#include <iostream>

using namespace std;

Employee::Employee(const char *const first, const char *const last, const Date &dateOfBirth, const Date &dateOfHire)
    : birthDate(dateOfBirth),
      hireDate(dateOfHire)
{
    int length = strlen(first);
    length = (length < 25 ? length : 24);
    strncpy(firstName, first, length);
    firstName[length] = '\0';

    length = strlen(last);
    length = (length < 25 ? length : 24);
    strncpy(lastName, last, length);
    lastName[length] = '\0';

    cout << "Employee object constructor: " << firstName << " " << lastName << endl;
}

Employee::~Employee()
{
    cout << "Employee object destructor: " << firstName << " " << lastName << endl;
}

void Employee::print() const
{
    cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();
    cout << endl;
}
```

`main.cpp`

```cpp
#include <iostream>
#include "date.h"
#include "employee.h"

using namespace std;

int main()
{
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Employee manager("Bob", "Blue", birth, hire);

    cout << endl;
    manager.print();
    cout << endl;

    cout << "Test Date constructor with invalid values: " << endl;
    Date lastDayOff(14, 35, 1994);
    cout << endl;
    return 0;
}
```

### 2-1.

`main.cpp`

```cpp
#include <iostream>

using namespace std;

class Count
{
    friend void setX(Count &, int);

private:
    int x;

public:
    Count() : x(0){};
    void print() const
    {
        cout << x << endl;
    }
};

void setX(Count &c, int val)
{
    c.x = val;
}

int main()
{
    Count counter;
    cout << "counter.x after instantiation: ";
    counter.print();

    setX(counter, 8);
    cout << "counter.x after call to setX friend function: ";
    counter.print();
    return 0;
}
```

### 2-2.

`main.cpp`

```cpp
#include <iostream>

using namespace std;

class Count
{
private:
    int x;

public:
    Count() : x(0){};
    void print() const
    {
        cout << x << endl;
    }
};

void cannotSetX(Count &c, int val)
{
    c.x = val; // error
}

int main()
{
    Count counter;
    cannotSetX(counter, 3);
    return 0;
}
```

### 3.

`main.cpp`

```cpp
#include <iostream>

using namespace std;

class Test
{
private:
    int x;

public:
    Test(int = 0);
    void print() const;
};

Test::Test(int value) : x(value) {}

void Test::print() const
{
    cout << "        x=" << x << endl;
    cout << "  this->x=" << this->x << endl;
    cout << "(*this).x=" << (*this).x << endl;
}

int main()
{
    Test testObject(12);
    testObject.print();
    return 0;
}
```

## Homework

### 1. 주어진 멤버함수들과 UML 구조를 이용하여 다음 기능을 포함하도록 Date 클래스를 수정하라.

1. 다음과 같은 다중 형식으로 날짜를 출력한다.
    - `DDD YYY`
    - `MM/DD/YY`
    - `June 14, 1992`
2. 위와 같은 형식의 날짜를 이용하여 Date 오브젝트를 생성하고 초기화하기 위해 오버로딩된 생성자를 사용하라
3. `<ctime>` 헤더의 표준 라이브러리 함수를 사용하여 시스템 날짜를 읽고 Data 맴버를 설정하는 Data 생성자를 작성하라.

See [HW 1](./hw01/)
