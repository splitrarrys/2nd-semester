#ifndef REGULAR_SHAPE_H
#define REGULAR_SHAPE_H

#include <string>
#include <iostream>
#include <memory>

class RegularShape {
public:
    virtual ~RegularShape() = default;
    
    // Чисто виртуальные методы
    virtual double calculateSurfaceArea() const = 0;
    virtual double calculateVolume() const = 0;
    virtual std::string toString() const = 0;
    virtual ~RegularShape() = default;  // деструктор виртуальный

    // Статический метод чтения фигуры
    static std::unique_ptr<RegularShape> readFromInput(std::istream& is);
    friend std::ostream& operator<<(std::ostream& os, const Segment& s);
};

#endif // REGULAR_SHAPE_H