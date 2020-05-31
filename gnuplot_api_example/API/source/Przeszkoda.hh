#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include "DronInterfejs.hh"

class Przeszkoda
{

public:
  virtual bool czy_kolizja (DronInterfejs* D)=0;

};

#endif
