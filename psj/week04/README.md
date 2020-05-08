# Classes 1

## Exercise

### 1.

`time.h`

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
    void printStandard();
    void printUniversal();
    void setTime(int, int, int);
};

#endif
```

`time.c`

```cpp
#include "time.h"
#include <iomanip>
#include <iostream>

using namespace std;

Time::Time()
{
    hour = minute = second = 0;
}

void Time::printStandard()
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << (hour < 12 ? " AM" : " PM") << endl;
}

void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << endl;
}

void Time::setTime(int h, int m, int s)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}
```

`main.cpp`

```cpp
#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    Time t;
    cout << "The initial universal time is ";
    t.printUniversal();
    cout << "The initial standard time is ";
    t.printStandard();

    t.setTime(13, 27, 6);

    cout << "Universal time after setTime is ";
    t.printUniversal();
    cout << "Standard time after setTime is ";
    t.printStandard();

    t.setTime(99, 99, 99);
    cout << "After attempting invalid settings: " << endl;
    cout << "Universal Time: ";
    t.printUniversal();
    cout << "Standard Time: ";
    t.printStandard();
    return 0;
}
```

### 2.

`main.cpp`

```cpp
#include <iostream>

using namespace std;

class Count
{
private:
    int x;

public:
    Count();
    void setX(int value)
    {
        x = value;
    }
    void print()
    {
        cout << x << endl;
    }
};

int main()
{
    Count counter;
    Count *counterPtr = &counter;
    Count &counterRef = counter;

    cout << "Set x to 1 and print using the object's member" << endl;
    counter.setX(1);
    counter.print();

    cout << "Set x to 2 and print using a reference to an object" << endl;
    counterRef.setX(2);
    counterRef.print();

    cout << "Set x to 3 and print using a pointer to an object" << endl;
    counterPtr->setX(3);
    counterPtr->print();
}
```

### 3.

`time.h`

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
    Time(int = 0, int = 0, int = 0);
    int getHour();
    int getMinute();
    int getSecond();
    void printStandard();
    void printUniversal();
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    void setTime(int, int, int);
};

#endif
```

`time.cpp`

```cpp
#include "time.h"
#include <iomanip>
#include <iostream>

using namespace std;

Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}

void Time::printStandard()
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << (hour < 12 ? " AM" : " PM") << endl;
}

void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << endl;
}

void Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}
```

`main.cpp`

```cpp
#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    Time t1;
    Time t2(2);
    Time t3(21, 34);
    Time t4(12, 25, 42);
    Time t5(27, 74, 99);

    cout << "Constructed with:\n\n1: all arguments defaulted" << endl;
    t1.printUniversal();
    t1.printStandard();

    cout << "\n\n2: hour specified; minute and second defaulted" << endl;
    t2.printUniversal();
    t2.printStandard();

    cout << "\n\n3: hour and minute specified; second defaulted" << endl;
    t3.printUniversal();
    t3.printStandard();

    cout << "\n\n4: hour, minute and second specified" << endl;
    t4.printUniversal();
    t4.printStandard();

    cout << "\n\n5: all invalid valued specified" << endl;
    t5.printUniversal();
    t5.printStandard();
    return 0;
}
```

## Homework

### 1. 복소수를 이용하여 산술 연산을 수행하는 Complex 라는 클래스를 작성하라.

1. 클래스의 `private` 데이터를 표현하기 위해 `double`형 변수를 사용한다.
2. 이 클래스의 오브젝트를 선언할 때 초기화 하는 생성자를 작성하라.
3. 생성자는 어떤 초기화 값을 지정하지 않을때 사용할 디폴트 값을 지정해야 한다.
4. 다음을 수행하는 `public` 멤버함수를 제공하라
    - 두 복소수 더하기: 실수 부분을 더하고 서수 부분을 더한다.
    - 두 복소수 빼기: 오른쪽 피연산자의 실수 부분을 왼쪽 피연산자의 실수 부분에서 빼고 오른쪽 피연산자의 허수 부분을 왼쪽 피연산자의 허수부분에서 뺀다.
    - (a, b) 형식으로 복소수를 출력하기.

See [HW 1](./hw01/)
