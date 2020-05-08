#include "shape.h"
#include <cmath>
#include <iostream>

constexpr double PI = 3.1415926535897932385;

Circle::Circle(double radius)
: radius(radius) {};

double Circle::get_area() const {
    return PI * std::pow(radius, 2);
}

double Circle::get_radius() const {
    return radius;
}

void Circle::print() const {
    std::cout << "Circle { area: " << get_area() << " }" << std::endl;
}

void Circle::set_radius(double radius) {
    this->radius = radius;
}

Square::Square(double length)
: length(length) {};

double Square::get_area() const {
    return std::pow(length, 2);
}

double Square::get_length() const {
    return length;
}

void Square::print() const {
    std::cout << "Square { area: " << get_area() << " }" << std::endl;
}

void Square::set_length(double length) {
    this->length = length;
}

Sphere::Sphere(double radius)
: radius(radius) {};

double Sphere::get_area() const {
    return 4 * PI * std::pow(radius, 2);
}

double Sphere::get_radius() const {
    return radius;
}

double Sphere::get_volumn() const {
    return (4.0 / 3) * PI * std::pow(radius, 3);
}

void Sphere::print() const {
    std::cout << "Sphere { area: " << get_area() << ", volumn: " << get_volumn() << " }" << std::endl;
}

void Sphere::set_radius(double radius) {
    this->radius = radius;
}

Cube::Cube(double length)
: length(length) {}

double Cube::get_area() const {
    return 6 * std::pow(length, 2);
}

double Cube::get_length() const {
    return length;
}

double Cube::get_volumn() const {
    return std::pow(length, 3);
}

void Cube::print() const {
    std::cout << "Cube { area: " << get_area() << ", volumn: " << get_volumn() << " }" << std::endl;
}

void Cube::set_length(double length) {
    this->length = length;
}
