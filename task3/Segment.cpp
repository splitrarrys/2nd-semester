#include "Segment.h"
#include <stdexcept>

Segment::Segment(const Point& start, const Point& end) : start(start), end(end) {
    if (start.x > end.x) {
        throw std::invalid_argument("Start point must have x-coordinate less than or equal to end point");
    }
}

double Segment::getY(double x) const {
    if (x < start.x || x > end.x) {
        throw std::out_of_range("X-coordinate is outside the segment");
    }
    
    // Линейная интерполяция: y = y1 + (y2 - y1) * (x - x1) / (x2 - x1)
    return start.y + (end.y - start.y) * (x - start.x) / (end.x - start.x);
}

Segment Segment::operator<<(double shift) const {
    return Segment(Point(start.x - shift, start.y), Point(end.x - shift, end.y));
}

Segment Segment::readFromStream(std::istream& is) {
    Point p1, p2;
    is >> p1 >> p2;
    return Segment(p1, p2);
}

std::ostream& operator<<(std::ostream& os, const Segment& s) {
    os << "Segment from " << s.start << " to " << s.end;
    return os;
}