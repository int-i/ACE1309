#include "complex.h"
#include <iostream>

template<typename T>
Complex<T>::Complex(T real, T imaginary)
: real(real), imaginary(imaginary) {}

template<typename T>
Complex<T> Complex<T>::add(const Complex<T>& complex) const {
    real += complex.real;
    imaginary += complex.imaginary;
}

template<typename T>
void Complex<T>::print() const {
    std::cout << "(" << real << ", " << imaginary << ")";
}

template<typename T>
Complex<T> Complex<T>::subtract(const Complex<T>& complex) const {
    real -= complex.real;
    imaginary -= complex.imaginary;
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex& complex) const {
    return subtract(complex);
}
