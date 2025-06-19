#include "PiecewiseLinearFunction.h"
#include <algorithm>
#include <stdexcept>

void PiecewiseLinearFunction::validatePoints() const {
    if (points.size() < 2) {
        throw std::invalid_argument("Need at least 2 points");
    }
    
    for (size_t i = 1; i < points.size(); ++i) {
        if (points[i-1].x >= points[i].x) {
            throw std::invalid_argument("Points must be sorted by x");
        }
    }
}

void PiecewiseLinearFunction::sortPoints() {
    std::sort(points.begin(), points.end(), 
        [](const Point& a, const Point& b) { return a.x < b.x; });
}

void PiecewiseLinearFunction::addPoint(const Point& point) {
    points.push_back(point);
    sortPoints();
}

const std::vector<Point>& PiecewiseLinearFunction::getPoints() const {
    return points;
}

std::unique_ptr<PiecewiseLinearFunction> PiecewiseLinearFunction::createFromInput(std::istream& is) {
    throw std::runtime_error("Must be implemented in derived class");
}