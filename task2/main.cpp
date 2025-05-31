#include <iostream>
#include "Rectangle.h"
#include "Point.h"

int main() {
    try {
        Point p1(0, 0);
        Point p2(4, 0);
        Point p3(4, 3);
        Point p4(0, 3);

        Rectangle rect(p1, p2, p3, p4);

        std::cout << "Rectangle properties:" << std::endl;
        std::cout << "Length: " << rect.getLength() << std::endl;
        std::cout << "Width: " << rect.getWidth() << std::endl;
        std::cout << "Perimeter: " << rect.calculatePerimeter() << std::endl;
        std::cout << "Area: " << rect.calculateArea() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}