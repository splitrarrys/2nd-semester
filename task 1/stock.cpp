#pragma once
#include <string>
#include <iostream>
#include "Person.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Person person("Панычев", "Дмитрий", "Александрович");
    std::cout << "ФИ: ";
    person.showFIO();
    std::cout << "ФИО: ";
    person.showFormal();
    return 0;
}
