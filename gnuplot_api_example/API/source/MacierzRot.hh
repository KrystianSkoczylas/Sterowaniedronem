#ifndef MACIERZROT_HH
#define MACIERZROT_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

class MacierzRot :public Macierz<double,3>
{

public:
  MacierzRot();
  MacierzRot (Macierz<double,3> M);
  MacierzRot(double a,char os);
  MacierzRot operator = (Macierz<double,3> M); 
};



#endif

