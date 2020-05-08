# Introduction to Classes and Objects 1

## Exercise

### 1.

```cpp
#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time();
    void set_time(int, int, int);
    void print_universal();
    void print_standard();
};

#endif
```

### 2-1.

`grade_book.h`

```cpp
#pragma once

class GradeBook
{
public:
    void display_message();
};
```

`grade_book.cpp`

```cpp
#include "grade_book.h"
#include <iostream>

using namespace std;

void GradeBook::display_message()
{
    cout << "Welcome to the Grade Book" << endl;
}
```

`main.cpp`

```cpp
#include "grade_book.h"

int main()
{
    GradeBook grade_book;
    grade_book.display_message();
    return 0;
}
```

### 2-2.

`grade_book.h`

```cpp
#pragma once
#include <string>

using namespace std;

class GradeBook
{
public:
    void display_message(string course_name);
};
```

`grade_book.cpp`

```cpp
#include "grade_book.h"
#include <iostream>
#include <string>

using namespace std;

void GradeBook::display_message(string course_name)
{
    cout << "Welcome to the Grade Book for " << course_name << endl;
}
```

`main.cpp`

```cpp
#include "grade_book.h"
#include <iostream>

using namespace std;

int main()
{
    GradeBook grade_book;
    string course_name;
    cout << "Please enter the course name:" << endl;
    getline(cin, course_name);
    grade_book.display_message(course_name);
    return 0;
}
```

### 2-3.

`grade_book.h`

```cpp
#pragma once
#include <string>

using namespace std;

class GradeBook
{
private:
    string course_name;

public:
    void display_message();
    string get_course_name();
    void set_course_name(string name);
};
```

`grade_book.cpp`

```cpp
#include "grade_book.h"
#include <iostream>
#include <string>

using namespace std;

void GradeBook::display_message()
{
    cout << "Welcome to the Grade Book for " << get_course_name() << endl;
}

string GradeBook::get_course_name()
{
    return course_name;
}

void GradeBook::set_course_name(string name)
{
    course_name = name;
}
```

`main.cpp`

```cpp
#include "grade_book.h"
#include <iostream>

using namespace std;

int main()
{
    GradeBook grade_book;
    string course_name;
    cout << "Initial course name is: " << grade_book.get_course_name() << endl;
    cout << "Please enter the course name:" << endl;
    getline(cin, course_name);
    cout << endl;
    grade_book.set_course_name(course_name);
    grade_book.display_message();
    return 0;
}
```

## Homework

### 1. 은행이 고객의 은행 계좌를 표현하는데 사용할 수 있는 Account 클래스를 작성하시오.

1. 계좌의 잔액을 표현하는 int 형의 데이터멤버를 포함해라.
2. 초기 잔액을 받아들이고 데이터 멤버를 이 값으로 초기화하는 생성자를 제공하라.
3. 생성자는 초기 잔액이 0보다 크거나 같은지 확인하기 위해 검증을 수행해야 한다.
4. 초기 잔액이 유효하지 않으면 잔액을 0으로 설정하고 값이 유효하지 않음을 가리키는 오류메시지를 출력한다.
5. 세 멤버 함수를 제공한다.
    - 멤버 함수 `credit` 은 현재 잔액에 일정액을 더해야 한다.
    - 멤버 함수 `debit` 양이 잔액을 초과하면 잔액은 바뀌지 않고 그대로 유지되며, 함수는 `Debit amount exceeded account balance`를 가리키는 메시지를 출력한다.
    - 함수 `getBalance`는 현재 잔액을 반환해야 한다.
6. 두 개의 `Account` 오브젝트를 생성하고 클래스 `Account`의 멤버 함수를 테스트하는 프로그램을 작성하라.

See [HW 1](./hw01/)
