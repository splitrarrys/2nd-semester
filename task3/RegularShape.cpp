#include "RegularShape.h"
#include <stdexcept>

std::unique_ptr<RegularShape> RegularShape::readFromInput(std::istream& is) {
    std::string shapeType;
    is >> shapeType;
    
    // Здесь можно добавить реализацию для конкретных фигур
    throw std::runtime_error("Shape type not implemented: " + shapeType);
}