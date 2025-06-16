#include <iostream>
#include <vector>
#include "Point.h"
#include "Segment.h"
#include "PiecewiseLinearApproximation.h"

void demonstrate_segment() {
    std::cout << "=== Segment Demonstration ===\n";
    
    // Создание отрезка
    Segment seg(Point(1.0, 1.0), Point(3.0, 3.0));
    std::cout << "Created segment: " << seg << std::endl;
    
    // Линейная интерполяция
    std::cout << "Y at x=2.0: " << seg.getY(2.0) << std::endl;
    
    // Сдвиг отрезка
    Segment shifted = seg << 1.0;
    std::cout << "Shifted segment (<<1.0): " << shifted << std::endl;
    
    // Чтение отрезка из потока
    std::istringstream input("0.0 0.0 2.0 2.0");
    Segment from_stream = Segment::readFromStream(input);
    std::cout << "Segment from stream: " << from_stream << std::endl;
}

void demonstrate_piecewise_linear() {
    std::cout << "\n=== Piecewise Linear Approximation Demonstration ===\n";
    
    // Создание аппроксимации разными способами
    PiecewiseLinearApproximation approx1({
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 0.0}
    });
    
    std::vector<Point> points = {{0.0, 1.0}, {1.0, 2.0}, {2.0, 1.0}};
    PiecewiseLinearApproximation approx2(points);
    
    std::cout << "Approximation 1 points:\n";
    for (const auto& p : approx1.getPoints()) {
        std::cout << p << std::endl;
    }
    
    // Добавление точки
    approx1.addPoint({1.5, 1.5});
    std::cout << "\nAfter adding point (1.5, 1.5):\n";
    for (const auto& p : approx1.getPoints()) {
        std::cout << p << std::endl;
    }
    
    // Получение значений
    std::cout << "\nInterpolated values:\n";
    std::cout << "Y at x=0.5: " << approx1.getY(0.5) << std::endl;
    std::cout << "Y at x=1.25: " << approx1.getY(1.25) << std::endl;
    
    // Чтение точек из потока
    std::istringstream points_input("0.0 0.0\n1.0 1.0\n2.0 0.0");
    auto read_points = PiecewiseLinearApproximation::readPointsFromStream(points_input);
    std::cout << "\nPoints read from stream:\n";
    for (const auto& p : read_points) {
        std::cout << p << std::endl;
    }
}

int main() {
    try {
        demonstrate_segment();
        demonstrate_piecewise_linear();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}