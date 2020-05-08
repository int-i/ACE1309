# Operator Overloading

## Exercise

### 1.

`array.h`

```cpp
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array {
    friend ostream& operator<<(ostream&, const Array&);
    friend istream& operator>>(istream&, Array&);

private:
    int size;
    int* ptr;

public:
    Array(int = 10);
    Array(const Array&);
    ~Array();
    int getSize() const;
    const Array& operator=(const Array&);
    bool operator==(const Array&) const;
    bool operator!=(const Array& right) const {
        return !(*this == right);
    }
    int& operator[](int);
    int operator[](int) const;
};

#endif
```

`array.cpp`

```cpp
#include "array.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

Array::Array(int arraySize) {
    size = arraySize > 0 ? arraySize : 10;
    ptr = new int[size];
    for (int i = 0; i < size; i += 1) {
        ptr[i] = 0;
    }
}

Array::Array(const Array& arrayToCopy)
: size(arrayToCopy.size) {
    ptr = new int[size];
    for (int i = 0; i < size; i += 1) {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

Array::~Array() {
    delete[] ptr;
}

int Array::getSize() const {
    return size;
}

const Array& Array::operator=(const Array& right) {
    if (&right != this) {
        if (size != right.size) {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }
        for (int i = 0; i < size; i += 1) {
            ptr[i] = right.ptr[i];
        }
    }
    return *this;
}

bool Array::operator==(const Array& right) const {
    if (size != right.size) {
        return false;
    }
    for (int i = 0; i < size; i += 1) {
        if (ptr[i] != right.ptr[i]) {
            return false;
        }
    }
    return true;
}

int& Array::operator[](int subscript) {
    if (subscript < 0 && subscript >= size) {
        cerr << "Error: Subscript " << subscript << " out of range" << endl;
        exit(1);
    }
    return ptr[subscript];
}

int Array::operator[](int subscript) const {
    if (subscript < 0 && subscript >= size) {
        cerr << "Error: Subscript " << subscript << " out of range" << endl;
        exit(1);
    }
    return ptr[subscript];
}

istream& operator>>(istream& input, Array& a) {
    for (int i = 0; i < a.size; i += 1) {
        input >> a.ptr[i];
    }
    return input;
}

ostream& operator<<(ostream& output, const Array& a) {
    int i;
    for (i = 0; i < a.size; i += 1) {
        output << setw(12) << a.ptr[i];
        if ((i + 1) % 4 == 0) {
            output << endl;
        }
    }
    if (i % 4 != 0) {
        output << endl;
    }
    return output;
}
```

`main.cpp`

```cpp
#include <iostream>
#include "array.h"

using namespace std;

int main() {
    Array integers1(7);
    Array integers2;
    cout << "size of Array integers1 is " << integers1.getSize() << endl
         << "Array after initialization: " << endl
         << integers1 << endl;
    cout << "size of Array integers2 is " << integers2.getSize() << endl
         << "Array after initialization: " << endl
         << integers2 << endl;

    cout << "Enter 17 integers" << endl;
    cin >> integers1 >> integers2;

    cout << "After input, the Arrays contains:" << endl
         << "integers1: " << endl
         << integers1 << endl
         << "integers2: " << endl
         << integers2 << endl;

    cout << "Evaluating: integers1 != integers2" << endl;
    if (integers1 != integers2) {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    Array integers3(integers1);
    cout << "size of Array integers3 is " << integers3.getSize() << endl
         << "Array after initialization: " << endl
         << integers3 << endl;

    cout << "Assigning integers2 to integers1: " << endl;
    integers1 = integers2;

    cout << "integers1: " << endl
         << integers1 << endl;
    cout << "integers2: " << endl
         << integers2 << endl;

    cout << "Evaluating: integers1 == integers2" << endl;
    if (integers1 == integers2) {
        cout << "integers1 and integers2 are equal" << endl;
    }

    cout << "integers1[5] is " << integers1[5] << endl;

    cout << "Assigning 1000 to integers1[5]: " << endl;
    integers1[5] = 1000;
    cout << "integers1: " << endl
         << integers1 << endl;

    cout << "Assigning 1000 to integers1[15]: " << endl;
    integers1[15] = 1000; // Error
    return 0;
}
```

### 2.

`date.h`

```cpp
#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
    friend ostream& operator<<(ostream&, const Date&);

private:
    int month;
    int day;
    int year;
    static const int days[];
    void helpIncrement();

public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date& operator++();
    Date operator++(int);
    const Date& operator+=(int);
    bool leapYear(int) const;
    bool endOfMonth(int) const;
};

#endif
```

`date.cpp`

```cpp
#include "date.h"
#include <iostream>

const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

void Date::setDate(int mm, int dd, int yy) {
    month = (mm >= 1 && mm <= 12) ? mm : 1;
    year = (yy >= 1900 && yy <= 2100) ? yy : 1900;
    if (month == 2 && leapYear(year)) {
        day = (dd >= 1 && dd <= 29) ? dd : 1;
    } else {
        day = (dd >= 1 && dd <= days[month]) ? dd : 1;
    }
}

Date& Date::operator++() {
    helpIncrement();
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    helpIncrement();
    return temp;
}

const Date& Date::operator+=(int additionalDays) {
    for (int i = 0; i < additionalDays; i += 1) {
        helpIncrement();
    }
    return *this;
}

bool Date::leapYear(int testYear) const {
    return testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0);
}

bool Date::endOfMonth(int testDay) const {
    if (month == 2 && leapYear(year)) {
        return testDay == 29;
    } else {
        return testDay == days[month];
    }
}

void Date::helpIncrement() {
    if (!endOfMonth(day)) {
        day += 1;
    } else {
        if (month < 12) {
            month += 1;
            day = 1;
        } else {
            year += 1;
            month = 1;
            day = 1;
        }
    }
}

ostream& operator<<(ostream& output, const Date& d) {
    static const char* monthName[13] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    output << monthName[d.month] << " " << d.day << ", " << d.year;
    return output;
}
```

`main.cpp`

```cpp
#include <iostream>
#include "date.h"

int main() {
    Date d1;
    Date d2(12, 27, 1992);
    Date d3(0, 99, 8045);
    cout << "d1 is " << d1 << endl
         << "d2 is " << d2 << endl
         << "d3 is " << d3 << endl;
    cout << "d2 += 7 is " << (d2 += 7) << endl;
    d3.setDate(2, 28, 1992);
    cout << "d3 is " << d3 << endl;
    cout << "++d3 is " << ++d3 << " (leap year allow 29th)" << endl;
    Date d4(7, 13, 2002);
    cout << "Testing the prefix increment operator: " << endl
         << "d4 is " << d4 << endl;
    cout << "++d4 is " << ++d4 << endl;
    cout << "d4 is " << d4 << endl;
    cout << "Testing the postfix increment operator:" << endl
         << "d4 is " << d4 << endl
         << "d4++ is " << d4++ << endl
         << "d4 is " << d4 << endl;
    return 0;
}
```

### 3.

`main.cpp`

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1("happy");
    string s2(" birthday");
    string s3;

    cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2 << "\"; s3 is \"" << s3 << "\"" << endl
         << endl
         << "The results of comparing s2 and s1:" << endl
         << "s2 == s1 yields " << (s2 == s1 ? "true" : "false") << endl
         << "s2 != s1 yields " << (s2 != s1 ? "true" : "false") << endl
         << "s2 > s1 yields " << (s2 > s1 ? "true" : "false") << endl
         << "s2 < s1 yields " << (s2 < s1 ? "true" : "false") << endl
         << "s2 >= s1 yields " << (s2 >= s1 ? "true" : "false") << endl
         << "s2 <= s1 yields " << (s2 <= s1 ? "true" : "false") << endl
         << endl;

    cout << "Testing s3.empty(): " << endl;
    if (s3.empty()) {
        cout << "s3 is empty; assigning s1 to s3;" << endl;
        s3 = s1;
        cout << "s3 is \"" << s3 << "\"";
    }

    cout << "s1 += s2 yields s1 = ";
    s1 += s2;
    cout << s1 << endl;

    cout << "s1 += \" to you\" yields s1 = ";
    s1 += " to you";
    cout << s1 << endl;

    cout << "The substring of s1 starting at location 0 for 14 chars, s1.substr(0, 14), is: " << s1.substr(0, 14) << endl;
    cout << "The substring of s1 starting at location 0 for 15 chars, s1.substr(0, 15), is: " << s1.substr(0, 15) << endl;

    string* s4Ptr = new string(s1);
    cout << "*sPtr = " << *s4Ptr << endl;

    cout << "assigning *s4Ptr to *s4Ptr" << endl;
    *s4Ptr = *s4Ptr;
    cout << "*sPtr = " << *s4Ptr << endl;

    delete s4Ptr;

    s1[0] = 'H';
    s1[6] = 'B';
    cout << "s1 after s1[0] = 'H' and s1[6] = 'B' is: " << s1 << endl;
    cout << "Attempt to assign 'd' to s1.at(30) yields: " << endl;
    s1.at(30) = 'd'; // Error
    return 0;
}
```

## Homework

### 1. String 클래스의 결합 연산자를 오버로딩하라.

1. 스트링 결합에는 두 피연산자가 필요하다.
2. 피연산자는 결합에 사용될 두 개의 스트링이다.
3. 다음과 같은 동작을 허용하는 `operator+`를 구현하라: `string1 = string2 + string3`
4. 다중 결합을 허용하는 `operator+`를 구현하라: `string1 = string2 + string3 + string4`

See [HW 1](./hw01/main.cpp)

Note: `string + string`은 rvalue이기 때문에 `string&&`를 인자로 가진 함수가 우선적으로 호출된다. 하지만 오버로딩한 연산자에서 반환타입을 `const string`으로 정의하게 된다면, `const string`는 인자가 `const string&`으로 정의된 함수를 우선적으로 호출한다. 따라서 `operator+`는 다중 결합을 허용한다.
