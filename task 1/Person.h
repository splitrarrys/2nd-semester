#pragma once
#include <iostream>
#include <string>

class Person {
private:
    std::string LastName;
    std::string Name;
    std::string Patronymic;
public:
    Person() : LastName(""), Name(""), Patronymic("") {}
    Person(const std::string& ln, const std::string& n, const std::string& p)
    : LastName(ln), Name(n), Patronymic(p) {}

    void showFIO() const {
        std::cout << LastName << " " << Name << std::endl;
    }

    void showFormal() const {
        std::cout << LastName << " " << Name << " " << Patronymic << std::endl;
    }
};
