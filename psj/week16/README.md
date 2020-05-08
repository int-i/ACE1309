# Final Exam

> 문제 유형만 같으며, 일부 문제가 누락됨

## Theory

### 1. Explain Polymorphism, and how to implement it.

### 2. Explain the difference between pure virtual and virtual.

### 3. Explain the advantages of using a template.

### 4. Explain public, protected, and private inheritance.

### 5. Write the output of the code below.

#### 1.

```cpp
#include <iostream>
#include <string>

class CreateDestroy {
private:
    std::string name;

public:
    CreateDestroy(const std::string& name)
    : name(name) {
        std::cout << "Call " << name << " constructor" << std::endl;
    }
    ~CreateDestroy() {
        std::cout << "Call " << name << " destructor" << std::endl;
    }
};

int main() {
    CreateDestroy a("A");
    CreateDestroy b("B");
    return 0;
}
```

Answer:

```text
Call A constructor
Call B constructor
Call B destructor
Call A destructor
```

### 2.

```cpp
#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Call base class constructor" << std::endl;
    }
    ~Base() {
        std::cout << "Call base class destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Call derived class constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Call derived class destructor" << std::endl;
    }
};

int main() {
    Base* base = new Base();
    Base* derived = new Derived();
    delete base;
    delete derived;
    return 0;
}
```

Answer:

```text
Call base class constructor
Call base class constructor
Call derived class constructor
Call base class destructor
Call base class destructor
```

## 6. Which of the following do not relate to inheritance?

1. `public`
2. `protected`
3. `private`
4. `static`

Answer: 4

## Practice

### 1. Solve the problem below with the given code.

1. Implement classes that allow arbitrary types with `template`.
2. Overload the `+` operator with a global function.
3. Overload the `-` operator with a member function.
4. Draw a UML of that code.
5. Draw an inheritance diagram for that code.

```cpp
#ifndef ACE1309_WEEK16_SOL01_COMPLEX_H
#define ACE1309_WEEK16_SOL01_COMPLEX_H

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real = 0, double imaginary = 0);
    Complex add(const Complex& complex) const;
    void print() const;
    Complex subtract(const Complex& complex) const;
};

#endif // ACE1309_WEEK16_SOL01_COMPLEX_H
```

See [Sol. 1](./sol01/)

### 2. Fill in the blanks so you can see the results below.

`book.h`

```cpp
#ifndef ACE1309_WEEK16_SOL02_BOOK_H
#define ACE1309_WEEK16_SOL02_BOOK_H

#include <string>

class Book {
private:
    std::string title;

public:
    Book(const std::string& title);
    virtual ~Book();
    std::string get_title() const;
    _____ void print() const;
    void set_title(const std::string& title);
};

class Novel : public Book {
public:
    Novel(const std::string& title);
    virtual ~Novel();
    virtual void print() const override;
};

class Biography : public Book {
public:
    Biography(const std::string& title);
    virtual ~Biography();
    virtual void print() const override;
};

#endif // ACE1309_WEEK16_SOL02_BOOK_H
```

`book.cpp`

```cpp
#include "book.h"
#include <iostream>
#include <string>

Book::Book(const std::string& title)
: title(title) {
    std::cout << "Call book constructor for " << get_title() << std::endl;
}

Book::~Book() {
    std::cout << "Call book destructor for " << get_title() << std::endl;
}

std::string Book::get_title() const {
    return title;
}

void Book::print() const {
    std::cout << "Book" << std::endl;
}

void Book::set_title(const std::string& title) {
    this->title = title;
}

Novel::Novel(_____ title)
: Book(title) {
    std::cout << "Call novel constructor for " << _____ << std::endl;
}

Novel::~Novel() {
    std::cout << "Call novel destructor for " << _____ << std::endl;
}

void Novel::print() const {
    std::cout << _____ << std::endl;
}

Biography::Biography(const std::string& title)
: Book(title) {
    _____
}

Biography::~Biography() {
    _____
}

void Biography::print() const {
    std::cout << _____ << std::endl;
}
```

`main.cpp`

```cpp
_____

int main() {
    _____
    return 0;
}

```

Ouput:

```text
Call book constructor for The Alchemist
Call novel constructor for The Alchemist
Call book constructor for Paulo Coelho
Call biography constructor for Paulo Coelho
Novel
Biography
Call novel destructor for The Alchemist
Call book destructor for The Alchemist
Call biography destructor for Paulo Coelho
Call book destructor for Paulo Coelho
```

See [Sol. 2](./sol02/)
