#ifndef ACE1309_WEEK16_SOL01_COMPLEX_H
#define ACE1309_WEEK16_SOL01_COMPLEX_H

template<typename T>
class Complex {
private:
    T real;
    T imaginary;

public:
    Complex(T real = 0, T imaginary = 0);
    Complex add(const Complex& complex) const;
    void print() const;
    Complex subtract(const Complex& complex) const;
    Complex operator-(const Complex& complex) const;
};

template<typename T>
Complex<T> operator+(const Complex<T>& lhs, const Complex<T>& rhs) {
    return lhs.add(rhs);
}

#endif // ACE1309_WEEK16_SOL01_COMPLEX_H
