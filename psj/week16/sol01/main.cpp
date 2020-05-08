#include <iostream>
#include "complex.h"

int main() {
    Complex a(5, 10);
    Complex b(4, 5);
    Complex c = a + b;
    Complex d = a - b;
    c.print();
    std::cout << std::endl;
    d.print();
    std::cout << std::endl;
    return 0;
}
