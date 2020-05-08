# Midterm Exam

> 문제 유형만 같으며, 일부 문제가 누락됨

## Theory

### 1. Explain `#pragma once`.

Specifies that the compiler includes the header file only once, when compiling a source code file.

See [Microsoft Docs](https://docs.microsoft.com/en-us/cpp/preprocessor/once)

### 2. Explain `this` pointer.

The `this` pointer is a pointer accessible only within the nonstatic member functions of a class, struct, or union type. It points to the object for which the member function is called.

See [Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/this-pointer)

### 3. Explain the default arguments in the constructor.

A default argument is a value provided in a function declaration that is automatically assigned by the compiler if the caller of the function doesn’t provide a value for the argument with a default value.

See [GeeksforGeeks](https://www.geeksforgeeks.org/default-arguments-c/)

### 4. Explain composition in C++.

A common form of software reusability is composition, in which a class has objects of other classes as members.

### 5. For the following questions, check O for True or X for False.

1. C is an object-oriented language. (X)
2. C++ is an object-oriented language. (O)
3. Binary scope resolution operator is used to define functions outside of classes. (O)
4. The dot(.) operator is used for direct member selection via object name. (O)
5. Private member variables cannot be accessed from outside the class. (X)
6. Objects can be used as arrays. (O)
7. In pointer objects, you need to access members using the arrow(->) operator. (O)
8. The constructor of the class and the default constructor have the same meaning. (X)
9. Destructors are always called in reverse order of the constructor. (X)
10. Const objects can only call const functions. (O)

### 6. Fix errors.

#### 1.

```cpp
class Noon {
private:
    const int hour;
    const int minute;
    const int second;

public:
    Noon() {
        hour = 12;
        minute = 12;
        second = 12;
    }
    void greet() {
        cout << "Hello" << endl;
    }
};
```

Answer:

```cpp
#include <iostream>

class Noon {
private:
    const int hour;
    const int minute;
    const int second;

public:
    Noon(): hour(12), minute(0), second(0) {}
    void greet() {
        std::cout << "Hello" << std::endl;
    }
};
```

#### 2.

```cpp
class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int = 0, int = 0, int);
    void print();
};
```

```cpp
Time time;
Time* time_ptr = &time;
time_ptr.print();
```

Answer:

```cpp
class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int = 0, int = 0, int = 0);
    void print();
};
```

```cpp
Time time;
Time* time_ptr = &time;
time_ptr->print();
```

#### 3.

```cpp
class Time {
public:
    int hour;
    int minute;
    int second;
}
```

```cpp
Time time;
Time* time_ptr = &time;
*time_ptr.hour = 12;
```

Answer:

```cpp
class Time {
public:
    int hour;
    int minute;
    int second;
};
```

```cpp
Time time;
Time* time_ptr = &time;
(*time_ptr).hour = 12;
```

### 7. Write the output of the code below.

```cpp
#include <iostream>

class Date {
public:
    Date() {
        std::cout << "Date created" << std::endl;
    }
    ~Date() {
        std::cout << "Date destroyed" << std::endl;
    }
};

class Employee {
private:
    Date hireDate;

public:
    Employee() {
        std::cout << "Employee created" << std::endl;
    }
    ~Employee() {
        std::cout << "Employee destroyed" << std::endl;
    }
};

void func() {
    static Date date1;
    Date date2;
    Employee employee2;
}

int main() {
    Employee employee1;
    func();
    return 0;
}
```

Answer:

```text
Date created
Employee created
Date created
Date created
Date created
Employee created
Employee destroyed
Date destroyed
Date destroyed
Employee destroyed
Date destroyed
Date destroyed
```

## Practice

### 1. Fill in the blanks so you can see the results below.

`time.h`

```cpp
#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(_____); // must provide default arguments
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    void print_standard() const;
    void print_universal() const;
    void set_hour(int);
    void set_minute(int);
    void set_second(int);
    void set_time(int, int, int);
    void tick();
};

#endif
```

`time.cpp`

```cpp
_____ // include headers and set namespaces

Time::Time(int h, int m, int s) {
    set_time(h, m, s);
}

int Time::get_hour() const {
    return hour;
}

int Time::get_minute() const {
    return minute;
}

int Time::get_second() const {
    return second;
}

void Time::print_standard() const {
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << (hour < 12 ? " AM" : " PM");
}

void Time::print_universal() const {
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second;
}

void Time::set_hour(int h) {
    _____ // check hour range(0~23)
}

void Time::set_minute(int m) {
    _____ // check minute range(0~59)
}

void Time::set_second(int s) {
    _____ // check second range(0~59)
}

void Time::set_time(int h, int m, int s) {
    set_hour(h);
    set_minute(m);
    set_second(s);
}

void Time::tick() {
    _____
}
```

`main.cpp`

```cpp
#include <iostream>
#include "time.h"

using std::cout;
using std::endl;

int main() {
    _____
    return 0;
}
```

Ouput:

```text
11:59:57 PM
11:59:58 PM
11:59:59 PM
12:00:00 AM
12:00:01 AM
12:00:02 AM
12:00:03 AM
12:00:04 AM
12:00:05 AM
00:00:06
00:00:07
00:00:08
00:00:09
00:00:10
00:00:11
00:00:12
00:00:13
00:00:14
```

See [Sol. 1](./sol01/)
