#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzRot.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

class Bryla
{

protected:
  std::shared_ptr<drawNS::Draw3DAPI> api;
  int indeks;
  Wektor<double,3> srodek;
  MacierzRot polozenie;

public:
  virtual void rysuj ()=0;
  //virtual void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik)=0;
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik);
};

#endif

