# Classes 2

## Exercise 

### 1.

`create_and_destroy.h`

```cpp
#ifndef CREATE_H
#define CREATE_H

#include <string>

using namespace std;

class CreateAndDestroy
{
private:
    int objectId;
    string message;

public:
    CreateAndDestroy(int, string);
    ~CreateAndDestroy();
};

#endif
```

`create_and_destroy.cpp`

```cpp
#include "create_and_destroy.h"
#include <iostream>
#include <string>

using namespace std;

CreateAndDestroy::CreateAndDestroy(int id, string messageString)
{
    objectId = id;
    message = messageString;
    cout << "object " << objectId << " constructor runs " << message << endl;
};

CreateAndDestroy::~CreateAndDestroy()
{
    cout << (objectId == 1 || objectId == 6 ? "\n" : "");
    cout << "object " << objectId << "destructor runs " << message << endl;
};
```

`main.cpp`

```cpp
#include <iostream>
#include "create_and_destroy.h"

using namespace std;

void create();

CreateAndDestroy first(1, "(global before main)");

int main()
{
    cout << "MAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy second(2, "(local automatic in main)");
    static CreateAndDestroy third(3, "(local static in main)");
    create();
    cout << "MAIN FUNCTION: EXECUTION RESUMES" << endl;
    CreateAndDestroy fourth(4, "(local automatic in main)");
    cout << "MAIN FUNCTION: EXECUTION ENDS" << endl;
    return 0;
}

void create()
{
    cout << "CREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy fifth(5, "(local automatic in create)");
    static CreateAndDestroy sixth(6, "(local static in create)");
    CreateAndDestroy seventh(7, "(local automatic in create)");
    cout << "CREATE FUNCTION: EXECUTION ENDS" << endl;
}
```

### 2.

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

public:
    Date(int = 1, int = 1, int = 2000);
    void print();
};

#endif
```

`date.cpp`

```cpp
#include "date.h"
#include <iostream>

using namespace std;

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::print()
{
    cout << month<< "/" << day << "/" << year;
}
```

`main.cpp`

```cpp
#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    Date date1(7, 4, 2000);
    Date date2;

    cout << "date1=";
    date1.print();
    cout << endl;

    cout << "date2=";
    date2.print();
    cout << endl;

    date2 = date1;

    cout << "After default memberwise assignment, date2=";
    date2.print();
    cout << endl;
    return 0;
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
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void printUniversal() const;
    void printStandard();
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

void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
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

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

int Time::getSecond() const
{
    return second;
}

void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << endl;
}

void Time::printStandard()
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << (hour < 12 ? " AM" : " PM") << endl;
}
```

`main.cpp`

```cpp
#include "time.h"

int main()
{
    Time wakeup(6, 45, 0);
    const Time noon(12, 0, 0);
    wakeup.setHour(18);
    noon.setHour(12); // error
    wakeup.getHour();
    noon.getMinute();
    noon.printUniversal();
    noon.printStandard(); // error
    return 0;
}
```

### 4.

`increment.h`

```cpp
#ifndef INCREMENT_H
#define INCREMENT_H

class Increment
{
private:
    int count;
    const int increment;

public:
    Increment(int c = 0, int i = 1);
    void addIncrement()
    {
        count += increment;
    }
    void print() const;
};

#endif
```

`increment.cpp`

```cpp
#include "increment.h"
#include <iostream>

using namespace std;

Increment::Increment(int c, int i)
    : count(c),
      increment(i) {}

void Increment::print() const
{
    cout << "count=" << count << ", increment=" << increment << endl;
}
```

`main.cpp`

```cpp
#include <iostream>
#include "increment.h"

using namespace std;

int main()
{
    Increment value(10, 5);
    cout << "Before incrementing: ";
    value.print();

    for (int j = 1; j <= 3; j++)
    {
        value.addIncrement();
        cout << "After increment " << j << ": ";
        value.print();
    }

    return 0;
}
```

## Homework

### 1. Time 객체에 저장된 시간을 1초 증가시키는 tick 맴버 함수를 포함하도록 Time 클래스를 수정하라.

1. Time 오브젝트는 항상 안정적인 상태를 유지해야 한다.
2. Tick 멤버 함수가 제대로 동작하는지 보여주기 위해 루프를 반복하는 동안 표준 형식으로 시간을 출력하는 루프를 사용하여 tick 멤버 함수를 테스트하는 프로그램을 작성하라.
3. 다음의 경우를 테스트하라.
    - 분(minute) 증가시키기
    - 시(hour) 증가시키기
    - 11:59:59 PM을 12:00:00 AM으로 바꾸며 일(day) 증가시키기
4. 작성한 클래스의 UML 구조를 작성하라.

![UML](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/Astro36/inha-univ/master/ACE1309/week05/hw01/time.puml?token=ACPZQ7XNLSVGL5XTBK2JHX25U4W2U)

See [HW 1](./hw01/)
