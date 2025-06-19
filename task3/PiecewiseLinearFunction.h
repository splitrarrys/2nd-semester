#ifndef PIECEWISE_LINEAR_FUNCTION_H
#define PIECEWISE_LINEAR_FUNCTION_H

#include "Point.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class PiecewiseLinearFunction {
public:
    // Чисто виртуальные методы (интерфейс)
    virtual double getY(double x) const = 0;          // Получить Y по X
    virtual std::string toString() const = 0;         // Сериализация в строку
    
    // Виртуальные методы с реализацией по умолчанию
    virtual void addPoint(const Point& point);        // Добавить точку
    virtual const std::vector<Point>& getPoints() const; // Получить все точки
    
    // Статические методы
    static std::unique_ptr<PiecewiseLinearFunction> createFromInput(std::istream& is);
    
    // Виртуальный деструктор
    virtual ~PiecewiseLinearFunction() = default;
    
protected:
    std::vector<Point> points;  // Коллекция точек
    
    // Защищённые вспомогательные методы
    void validatePoints() const;
    void sortPoints();
};

#endif // PIECEWISE_LINEAR_FUNCTION_H