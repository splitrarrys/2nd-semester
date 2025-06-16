#include "Segment.h"

void Segment::validateSegment() const {
    if (start.x > end.x) {
        throw std::invalid_argument("Segment start x must be less than or equal to end x");
    }
}

Segment::Segment(const Point& start, const Point& end) : start(start), end(end) {
    validateSegment();
}

double Segment::getY(double x) const {
    if (x < start.x || x > end.x) {
        throw std::out_of_range("X is outside segment bounds");
    }
    
    if (start.x == end.x) {
        return start.y; // vertical segment
    }
    
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