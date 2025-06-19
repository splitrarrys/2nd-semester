#ifndef PIECEWISE_LINEAR_APPROXIMATION_H
#define PIECEWISE_LINEAR_APPROXIMATION_H

#include "Point.h"
#include "Segment.h"
#include <vector>
#include <initializer_list>
#include <stdexcept>

class PiecewiseLinearApproximation {
protected:
    std::vector<Point> points;
    std::vector<Segment> segments;

    void buildSegments();
    void validatePoints() const;

public:
    PiecewiseLinearApproximation() = default;
    PiecewiseLinearApproximation(const std::vector<Point>& points);
    PiecewiseLinearApproximation(std::initializer_list<Point> points);
    
    virtual ~PiecewiseLinearApproximation() = default;
    
    void addPoint(const Point& point);
    double getY(double x) const;
    
    const std::vector<Point>& getPoints() const { return points; }
    const std::vector<Segment>& getSegments() const { return segments; }
    
    static std::vector<Point> readPointsFromStream(std::istream& is);
};

#endif // PIECEWISE_LINEAR_APPROXIMATION_H