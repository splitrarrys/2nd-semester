#include "LinearInterpolation.h"
#include <sstream>

LinearInterpolation::LinearInterpolation(const std::vector<Point>& points) {
    this->points = points;
    sortPoints();
    validatePoints();
    buildSegments();
}

LinearInterpolation::LinearInterpolation(std::initializer_list<Point> points) {
    this->points = points;
    sortPoints();
    validatePoints();
    buildSegments();
}

void LinearInterpolation::buildSegments() {
    segments.clear();
    for (size_t i = 1; i < points.size(); ++i) {
        segments.emplace_back(points[i-1], points[i]);
    }
}

double LinearInterpolation::getY(double x) const {
    if (points.empty()) throw std::runtime_error("No points");
    if (x < points.front().x || x > points.back().x) {
        throw std::out_of_range("X out of range");
    }
    
    for (const auto& segment : segments) {
        if (x >= segment.getStart().x && x <= segment.getEnd().x) {
            return segment.getY(x);
        }
    }
    
    return points.back().y;
}

std::string LinearInterpolation::toString() const {
    std::ostringstream oss;
    oss << "LinearInterpolation with " << points.size() << " points: [";
    for (const auto& p : points) {
        oss << " (" << p.x << "," << p.y << ")";
    }
    oss << " ]";
    return oss.str();
}

void LinearInterpolation::addPoint(const Point& point) {
    PiecewiseLinearFunction::addPoint(point);
    buildSegments();
}

LinearInterpolation LinearInterpolation::operator<<(double shift) const {
    std::vector<Point> shifted_points;
    for (const auto& p : points) {
        shifted_points.emplace_back(p.x - shift, p.y);
    }
    return LinearInterpolation(shifted_points);
}

LinearInterpolation LinearInterpolation::readFromStream(std::istream& is) {
    std::vector<Point> points;
    Point p;
    while (is >> p.x >> p.y) {
        points.push_back(p);
    }
    return LinearInterpolation(points);
}