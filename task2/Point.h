#pragma once
class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0);
    double distanceTo(const Point& other) const;
};