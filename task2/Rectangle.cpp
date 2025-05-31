#include "Rectangle.h"
#include <cmath>
#include <stdexcept>

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;

    if (!isValidRectangle()) {
        throw std::invalid_argument("The given points do not form a valid rectangle.");
    }
}

bool Rectangle::isValidRectangle() const {
    double sideAB = points[0].distanceTo(points[1]);
    double sideBC = points[1].distanceTo(points[2]);
    double sideCD = points[2].distanceTo(points[3]);
    double sideDA = points[3].distanceTo(points[0]);

    double diagAC = points[0].distanceTo(points[2]);
    double diagBD = points[1].distanceTo(points[3]);

    const double epsilon = 1e-6;
    return (std::abs(sideAB - sideCD) < epsilon) &&
           (std::abs(sideBC - sideDA) < epsilon) &&
           (std::abs(diagAC - diagBD) < epsilon);
}

double Rectangle::getLength() const {
    return points[0].distanceTo(points[1]);
}

double Rectangle::getWidth() const {
    return points[1].distanceTo(points[2]);
}

double Rectangle::calculatePerimeter() const {
    return 2 * (getLength() + getWidth());
}

double Rectangle::calculateArea() const {
    return getLength() * getWidth();
}