#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"
#include <stdexcept>
#include <iostream>

class Segment {
private:
    Point start;
    Point end;

    void validateSegment() const;

public:
    Segment(const Point& start, const Point& end);
    
    double getY(double x) const;
    Segment operator<<(double shift) const;
    
    static Segment readFromStream(std::istream& is);
    
    const Point& getStart() const { return start; }
    const Point& getEnd() const { return end; }
    
    friend std::ostream& operator<<(std::ostream& os, const Segment& s);
};

#endif // SEGMENT_H