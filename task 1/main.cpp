#include <string>

#include <iostream>

#include "Person.h"



int main() 

{

    Person person("Панычев", "Дмитрий", "Александрович");



    cout << "ФИ: ";

    person.showFIO();



    cout << "ФИО: ";

    person.showFormal();



    return 0;
