#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Prostopadloscian.hh"

class Dron :public Prostopadloscian
{

public:
  void obrot (double stopnie);
  //Dron(double a, double b, double c): Prostopadloscian(double a, double b, double c); {}
};

#endif
