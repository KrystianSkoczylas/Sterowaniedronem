#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Sruba.hh"

class Dron :public Prostopadloscian
{
  //Sruba L;
  // Sruba P;
  
public:
  
  Sruba L;
  Sruba P;
  void obrot (double stopnie);
  void plyn (double stopnie, double odleglosc);
  Dron(double a, double b, double c);
};

#endif
