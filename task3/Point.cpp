#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

bool Point::operator<(const Point& other) const {
    return x < other.x;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}