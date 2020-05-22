#ifndef PRZESZKODAPROSTOPADLOSCIAN_HH
#define PRZESZKODAPROSTOPADLOSCIAN_HH

#include <iostream>

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"

class PrzeszkodaProstopadloscian :public Prostopadloscian, public Przeszkoda
{

public:
  PrzeszkodaProstopadloscian (double a, double b, double c);

  bool czy_kolizja (DronInterfejs* D) override;
};

#endif
