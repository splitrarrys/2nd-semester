#include <iostream>
#include "Segment.h"
#include "RegularShape.h"

int main() {
    try {
        // Пример работы с отрезком
        Point p1(0, 0);
        Point p2(2, 4);
        Segment segment(p1, p2);
        
        std::cout << "Segment: " << segment << std::endl;
        std::cout << "Y at x=1: " << segment.getY(1.0) << std::endl;
        
        Segment shifted = segment << 1.0;
        std::cout << "Shifted segment: " << shifted << std::endl;
        
        // Пример чтения отрезка из потока
        std::cout << "Enter segment (x1 y1 x2 y2): ";
        Segment s = Segment::readFromStream(std::cin);
        std::cout << "You entered: " << s << std::endl;
        
        // Пример работы с абстрактной фигурой
        std::cout << "Enter shape type: ";
        auto shape = RegularShape::readFromInput(std::cin);
        std::cout << "Shape surface area: " << shape->calculateSurfaceArea() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}