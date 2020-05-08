#include <iostream>
#include "complex.h"

int main() {
    Complex a(1, 7);
    Complex b(9, 2);
    Complex c(10, 1);
    Complex d(11, 5);

    a.print();
    std::cout << " + ";
    b.print();
    std::cout << " = ";
    a.add(b);
    a.print();
    std::cout << std::endl;

    c.print();
    std::cout << " - ";
    d.print();
    std::cout << " = ";
    c.subtract(d);
    c.print();
    return 0;
}
