#pragma once

#include <string>

using namespace std;



class  Person

{

private:

  string lastname;

  string name;

  string patronymic;

public:

  Person();

  Person(const string& ln, const string& n, const string p = "");

  void show(const string& lastname, const string& name); // ln + n

  void showFormal(const string& lastname, const string& name, const string& patronymic); //ln + n + p 

};
