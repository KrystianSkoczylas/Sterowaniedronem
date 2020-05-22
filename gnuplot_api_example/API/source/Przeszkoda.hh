#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
//#include "Wektor.hh"
//#include "Macierz.hh"
//#include "MacierzRot.hh"
//#include "Dr3D_gnuplot_api.hh"
#include "DronInterfejs.hh"

class Przeszkoda
{

public:
  virtual bool czy_kolizja (DronInterfejs* D)=0;

};

#endif
