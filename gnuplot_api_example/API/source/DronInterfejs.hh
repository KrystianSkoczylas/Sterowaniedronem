#ifndef DRONINTERFEJS_HH
#define DRONINTERFEJS_HH

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

class DronInterfejs
{

public:
  virtual void obrot (double stopnie)=0;
  //  virtual void plyn (double stopnie, double odleglosc, std::vector<Przeszkoda*> l_przeszkod)=0;
  virtual Wektor<double,3> dostan_srodek ()=0;
  virtual double dostan_Promien ()=0;

};


#endif
