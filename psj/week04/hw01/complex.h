#ifndef ACE1309_WEEK04_HW01_COMPLEX_H
#define ACE1309_WEEK04_HW01_COMPLEX_H

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real = 0, double imaginary = 0);
    void add(Complex complex);
    void print() const;
    void subtract(Complex complex);
};

#endif // ACE1309_WEEK04_HW01_COMPLEX_H
