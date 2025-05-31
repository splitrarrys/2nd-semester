#pragma once

#include "Point.h"
#include <stdexcept>

class Rectangle {
private:
    Point points[4];  // точки прямоугольника в порядке A, B, C, D
    bool isValidRectangle() const;

public:
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    double getLength() const;
    double getWidth() const;
    double calculatePerimeter() const;
    double calculateArea() const;
};
