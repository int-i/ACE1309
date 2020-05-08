# Templates

## Exercise

### 1.

`main.cpp`

```cpp
#include <iostream>

using namespace std;

template<typename T>
void printArray(const T* array, int count) {
    for (int i = 0; i < count; i += 1) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main() {
    const int ACOUNT = 5;
    const int BCOUNT = 7;
    const int CCOUNT = 6;

    int a[ACOUNT] = { 1, 2, 3, 4, 5 };
    double b[BCOUNT] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    char c[CCOUNT] = "HELLO";

    cout << "Array a contains:" << endl;
    printArray(a, ACOUNT);

    cout << "Array b contains:" << endl;
    printArray(b, BCOUNT);

    cout << "Array c contains:" << endl;
    printArray(c, CCOUNT);
    return 0;
}
```

### 2-1.

`stack.h`

```cpp
#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
private:
    int size;
    int top;
    T* stackPtr;

public:
    Stack(int = 10);
    ~Stack() {
        delete[] stackPtr;
    }
    bool push(const T&);
    bool pop(T&);
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == size - 1;
    }
};

template<typename T>
Stack<T>::Stack(int s)
: size(s > 0 ? s : 0),
  top(-1),
  stackPtr(new T[size]) {}

template<typename T>
bool Stack<T>::push(const T& pushValue) {
    if (!isFull()) {
        stackPtr[++top] = pushValue;
        return true;
    }
    return false;
}

template<typename T>
bool Stack<T>::pop(T& popValue) {
    if (!isEmpty()) {
        popValue = stackPtr[top--];
        return true;
    }
    return false;
}

#endif
```

`main.cpp`

```cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack<double> doubleStack(5);
    double doubleValue = 1.1;
    cout << "Pushing elements onto doubleStack" << endl;
    while (doubleStack.push(doubleValue)) {
        cout << doubleValue << ' ';
        doubleValue += 1.1;
    }
    cout << endl
         << "Stack is full. Cannot push " << doubleValue << endl
         << endl
         << "Popping elements from doubleStack" << endl;
    while (doubleStack.pop(doubleValue)) {
        cout << doubleValue << ' ';
    }
    cout << endl
         << "Stack is empty. Cannot pop" << endl
         << endl;

    Stack<int> intStack;
    int intValue = 1;
    cout << "Pushing elements onto intStack" << endl;
    while (intStack.push(intValue)) {
        cout << intValue << ' ';
        intValue += 1;
    }
    cout << endl
         << "Stack is full. Cannot push " << intValue << endl
         << endl
         << "Popping elements from intStack" << endl;
    while (intStack.pop(intValue)) {
        cout << intValue << ' ';
    }
    cout << endl
         << "Stack is empty. Cannot pop" << endl;
    return 0;
}
```

### 2-2.

`main.cpp`

```cpp
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

template<typename T>
void testStack(Stack<T>& theStack, T value, T increment, const string& stackName) {
    cout << "Pushing elements onto " << stackName << endl;
    while (theStack.push(value)) {
        cout << value << ' ';
        value += increment;
    }
    cout << endl
         << "Stack is full. Cannot push " << value << endl
         << endl
         << "Poping elements from " << stackName << endl;
    while (theStack.pop(value)) {
        cout << value << ' ';
    }
    cout << endl
         << "Stack is empty. Cannot pop" << endl
         << endl;
}

int main() {
    Stack<double> doubleStack(5);
    Stack<int> intStack;
    testStack(doubleStack, 1.1, 1.1, "doubleStack");
    testStack(intStack, 1, 1, "intStack");
    return 0;
}
```

## Homework

### 1. 숫자나 문자를 정렬해주는 프로그램을 만드시오.

1. 사용자로부터 입력받은 내용을 숫자(`int` 또는 `float`)나 문자(`char`)에 상관없이 오름차순 정렬할 수 있는 프로그램이다.
2. 메인 함수에서는 입력만 받고 정렬함수와 출력함수를 통해 프로그램을 완성한다.
3. 같은 크기의 숫자나 문자에 대해서는 그 순서를 신경 쓰지 않는다.
4. 다음은 프로그램 구동 예이다.

```text
Data items in original order
> 6 4 8 10 12 89 68 45 37
Data items in ascending order
> 4 6 8 10 12 37 45 68 89
Data items in original order
> 5.2 36.5 3.4 12.8 1.9 6.8 24.3
Data items in ascending order
> 1.9 3.4 5.2 6.8 12.8 24.3 36.5
Data items in original order
> I n h a U n i v .
Data items in ascending order
> . I U a h i n n v
```

See [HW 1](./hw01/main.cpp)

Hint:

```cpp
#include <algorithm>
#include <iostream>

constexpr int INTS_SIZE = 8;
constexpr int FLOATS_SIZE = 7;
constexpr int CHARS_SIZE = 9;

template<typename T>
void print_aray(const T const* array, const int size) {
    for (int i = 0; i < size; i += 1) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    int ints[INTS_SIZE] = { 6, 4, 10, 12, 89, 68, 45, 37 };
    float floats[FLOATS_SIZE] = { 5.2, 36.5, 3.4, 12.8, 1.9, 6.8, 24.3 };
    char chars[CHARS_SIZE + 1] = "InhaUniv.";

    std::cout << "Data items in original order" << std::endl;
    print_aray(ints, INTS_SIZE);
    std::cout << "Data items in ascending order" << std::endl;
    std::sort(ints, ints + INTS_SIZE);
    print_aray(ints, INTS_SIZE);

    std::cout << "Data items in original order" << std::endl;
    print_aray(floats, FLOATS_SIZE);
    std::cout << "Data items in ascending order" << std::endl;
    std::sort(floats, floats + FLOATS_SIZE);
    print_aray(floats, FLOATS_SIZE);

    std::cout << "Data items in original order" << std::endl;
    print_aray(chars, CHARS_SIZE);
    std::cout << "Data items in ascending order" << std::endl;
    std::sort(chars, chars + CHARS_SIZE);
    print_aray(chars, CHARS_SIZE);
    return 0;
}
```
