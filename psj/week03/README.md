# Introduction to Classes and Objects 2

## Exercise

### 1-1.

`main.cpp`

```cpp
#include <iostream>
#include <string>

using namespace std;

class GradeBook
{
private:
    string course_name;

public:
    GradeBook(string name)
    {
        set_course_name(name);
    }

    void display_message()
    {
        cout << "Welcome to the grade book for " << get_course_name() << "!" << endl;
    }

    string get_course_name()
    {
        return course_name;
    }

    void set_course_name(string name)
    {
        course_name = name;
    }
};

int main()
{
    GradeBook grade_book1("CS101 Introduction to C++ Programming");
    GradeBook grade_book2("CS102 Data Structures in C++");
    cout << "grade_book1 created for course: " << grade_book1.get_course_name() << endl
         << "grade_book2 created for course: " << grade_book2.get_course_name() << endl;
    return 0;
}
```

### 1-2.

`grade_book.h`

```cpp
#include <iostream>
#include <string>

using namespace std;

class GradeBook
{
private:
    string course_name;

public:
    GradeBook(string name)
    {
        set_course_name(name);
    }

    void display_message()
    {
        cout << "Welcome to the grade book for " << get_course_name() << "!" << endl;
    }

    string get_course_name()
    {
        return course_name;
    }

    void set_course_name(string name)
    {
        course_name = name;
    }
};
```

`main.cpp`

```cpp
#include "grade_book.h"
#include <iostream>

using namespace std;

int main()
{
    GradeBook grade_book1("CS101 Introduction to C++ Programming");
    GradeBook grade_book2("CS102 Data Structures in C++");
    cout << "grade_book1 created for course: " << grade_book1.get_course_name() << endl
         << "grade_book2 created for course: " << grade_book2.get_course_name() << endl;
    return 0;
}
```

### 1-3.

`grade_book.h`

```cpp
#include <iostream>
#include <string>

using namespace std;

class GradeBook
{
private:
    string course_name;

public:
    GradeBook(string name);
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

GradeBook::GradeBook(string name)
{
    set_course_name(name);
}

void GradeBook::display_message()
{
    cout << "Welcome to the grade book for " << get_course_name() << "!" << endl;
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
    GradeBook grade_book1("CS101 Introduction to C++ Programming");
    GradeBook grade_book2("CS102 Data Structures in C++");
    cout << "grade_book1 created for course: " << grade_book1.get_course_name() << endl
         << "grade_book2 created for course: " << grade_book2.get_course_name() << endl;
    return 0;
}
```

### 1-4.

`grade_book.h`

```cpp
#include <iostream>
#include <string>

using namespace std;

class GradeBook
{
private:
    string course_name;

public:
    GradeBook(string name);
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

GradeBook::GradeBook(string name)
{
    set_course_name(name);
}

void GradeBook::display_message()
{
    cout << "Welcome to the grade book for " << get_course_name() << "!" << endl;
}

string GradeBook::get_course_name()
{
    return course_name;
}

void GradeBook::set_course_name(string name)
{
    if (name.length() <= 25)
    {
        course_name = name;
    }
    else
    {
        course_name = name.substr(0, 25);
        cout << "Name \"" << name << "\" exceeds maximum length(25)." << endl
             << "Limiting course_name to first 25 characters." << endl;
    }
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
    GradeBook grade_book1("CS101 Introduction to Programming in C++");
    GradeBook grade_book2("CS102 C++ Data Structures");
    cout << "grade_book1's initial course name is " << grade_book1.get_course_name() << endl
         << "grade_book2's initial course name is " << grade_book2.get_course_name() << endl;
    grade_book1.set_course_name("CS101 C++ Programming");
    cout << "grade_book1's course name is " << grade_book1.get_course_name() << endl
         << "grade_book2's course name is " << grade_book2.get_course_name() << endl;
    return 0;
}
```

## Homework

### 1. 세가지 정보를 데이터 멤버로 포함하는 Employee 클래스를 작성하시오.

1. 각 데이터 멤버는 이름(string), 성(string), 월급(int)이다.
2. 이 클래스는 세 데이터 멤버를 초기화하는 생성자를 제공해야 한다.
3. 각 데이터 멤버에 대한 set과 get 함수를 제공하라.
4. 월급이 양수가 아니라면 0으로 설정한다.
5. 클래스 `Employee`의 기능을 보여주는 테스트 프로그램을 작성하시오.
6. 두 `Employee` 오브젝트를 생성하고 각 오브젝트의 연봉을 출력한다.
7. `Employee`에 10%의 성과급을 반영하고 각 `Employee`의 연봉을 다시 출력한다.

See [HW 1](./hw01/)
