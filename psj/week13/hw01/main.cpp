#include <iostream>
#include <vector>
#include "shape.h"

int main() {
    Circle circle(2);
    Square square(3);
    Sphere sphere(4);
    Cube cube(5);
    std::vector<Shape*> shape_ptrs{ &circle, &square, &sphere, &cube };
    for (const Shape* const shape_ptr : shape_ptrs) {
        shape_ptr->print();
    }
    return 0;
}
