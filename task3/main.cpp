#include <iostream>
#include "LinearInterpolation.h"

void demonstrateAbstractClass() {
    // Создаем через указатель на базовый класс
    std::unique_ptr<PiecewiseLinearFunction> func = 
        std::make_unique<LinearInterpolation>(std::vector<Point>{{0,0}, {1,1}, {2,0}});
    
    std::cout << "Using abstract interface:\n";
    std::cout << func->toString() << "\n";
    std::cout << "f(0.5) = " << func->getY(0.5) << "\n";
    
    func->addPoint({1.5, 0.5});
    std::cout << "After adding point: " << func->toString() << "\n";
}

void demonstrateDerivedClass() {
    LinearInterpolation func{{0,0}, {1,2}, {2,1}};
    
    std::cout << "\nUsing derived class directly:\n";
    std::cout << func.toString() << "\n";
    
    auto shifted = func << 1.0;
    std::cout << "Shifted function: " << shifted.toString() << "\n";
    
    std::istringstream input("0 0\n1 1\n2 0");
    auto fromStream = LinearInterpolation::readFromStream(input);
    std::cout << "From stream: " << fromStream.toString() << "\n";
}

int main() {
    try {
        demonstrateAbstractClass();
        demonstrateDerivedClass();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}