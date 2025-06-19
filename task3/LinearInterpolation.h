#ifndef LINEAR_INTERPOLATION_H
#define LINEAR_INTERPOLATION_H

#include "PiecewiseLinearFunction.h"
#include "Segment.h"

class LinearInterpolation : public PiecewiseLinearFunction {
public:
    // Конструкторы
    LinearInterpolation() = default;
    LinearInterpolation(const std::vector<Point>& points);
    LinearInterpolation(std::initializer_list<Point> points);
    
    // Реализация абстрактных методов
    double getY(double x) const override;
    std::string toString() const override;
    
    // Переопределение виртуальных методов
    void addPoint(const Point& point) override;
    
    // Специфичные методы
    LinearInterpolation operator<<(double shift) const;
    static LinearInterpolation readFromStream(std::istream& is);
    
private:
    std::vector<Segment> segments;
    void buildSegments();
};

#endif // LINEAR_INTERPOLATION_H