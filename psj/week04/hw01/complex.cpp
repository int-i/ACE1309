#include "complex.h"
#include <iostream>

Complex::Complex(double real, double imaginary)
: real(real), imaginary(imaginary) {}

void Complex::add(Complex complex) {
    real += complex.real;
    imaginary += complex.imaginary;
}

void Complex::print() const {
    std::cout << "(" << real << ", " << imaginary << ")";
}

void Complex::subtract(Complex complex) {
    real -= complex.real;
    imaginary -= complex.imaginary;
}
