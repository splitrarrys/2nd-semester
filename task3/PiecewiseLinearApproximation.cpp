#include "PiecewiseLinearApproximation.h"
#include <algorithm>

void PiecewiseLinearApproximation::validatePoints() const {
    if (points.size() < 2) {
        throw std::invalid_argument("At least two points are required");
    }
    
    for (size_t i = 1; i < points.size(); ++i) {
        if (points[i-1].x >= points[i].x) {
            throw std::invalid_argument("Points must be sorted by x-coordinate and have unique x-values");
        }
    }
}

void PiecewiseLinearApproximation::buildSegments() {
    segments.clear();
    if (points.size() < 2) return;
    
    for (size_t i = 1; i < points.size(); ++i) {
        segments.emplace_back(points[i-1], points[i]);
    }
}

PiecewiseLinearApproximation::PiecewiseLinearApproximation(const std::vector<Point>& points) 
    : points(points) {
    std::sort(this->points.begin(), this->points.end());
    validatePoints();
    buildSegments();
}

PiecewiseLinearApproximation::PiecewiseLinearApproximation(std::initializer_list<Point> points) 
    : points(points) {
    std::sort(this->points.begin(), this->points.end());
    validatePoints();
    buildSegments();
}

void PiecewiseLinearApproximation::addPoint(const Point& point) {
    points.push_back(point);
    std::sort(points.begin(), points.end());
    validatePoints();
    buildSegments();
}

double PiecewiseLinearApproximation::getY(double x) const {
    if (points.empty()) {
        throw std::runtime_error("No points in approximation");
    }
    
    if (x < points.front().x || x > points.back().x) {
        throw std::out_of_range("X is outside approximation bounds");
    }
    
    for (const auto& segment : segments) {
        if (x >= segment.getStart().x && x <= segment.getEnd().x) {
            return segment.getY(x);
        }
    }
    
    return points.back().y; 
}

std::vector<Point> PiecewiseLinearApproximation::readPointsFromStream(std::istream& is) {
    std::vector<Point> result;
    Point p;
    while (is >> p) {
        result.push_back(p);
    }
    return result;
}