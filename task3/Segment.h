#pragma once

#include "Point.h"
#include <iostream>

class Segment {
private:
    Point start;
    Point end;

public:
    Segment(const Point& start, const Point& end);
    
    // Метод расчета ординаты по абсциссе
    double getY(double x) const;
    
    // Оператор сдвига влево
    Segment operator<<(double shift) const;
    
    // Статический метод чтения отрезка
    static Segment readFromStream(std::istream& is);
    
    friend std::ostream& operator<<(std::ostream& os, const Segment& s);
};
