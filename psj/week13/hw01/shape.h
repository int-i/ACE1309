#ifndef ACE1309_WEEK13_SHAPE_H
#define ACE1309_WEEK13_SHAPE_H

class Shape {
public:
    virtual void print() const = 0;
    virtual double get_area() const = 0;
};

class TwoDimensionalShape : public Shape {};

class ThreeDimensionalShape : public Shape {
public:
    virtual double get_volumn() const = 0;
};

class Circle : public TwoDimensionalShape {
private:
    double radius;

public:
    Circle(double radius = 0);
    virtual double get_area() const override;
    double get_radius() const;
    virtual void print() const override;
    void set_radius(double radius);
};

class Square : public TwoDimensionalShape {
private:
    double length;

public:
    Square(double length = 0);
    virtual double get_area() const override;
    double get_length() const;
    virtual void print() const override;
    void set_length(double length);
};

class Sphere : public ThreeDimensionalShape {
private:
    double radius;

public:
    Sphere(double radius = 0);
    virtual double get_area() const override;
    double get_radius() const;
    virtual double get_volumn() const override;
    virtual void print() const override;
    void set_radius(double radius);
};

class Cube : public ThreeDimensionalShape {
private:
    double length;

public:
    Cube(double length = 0);
    virtual double get_area() const override;
    double get_length() const;
    virtual double get_volumn() const override;
    virtual void print() const override;
    void set_length(double length);
};

#endif // ACE1309_WEEK13_SHAPE_H
