#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzRot.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Bryla.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

class Prostopadloscian :public Bryla
{
protected:
  Wektor<double,3> v1;
  Wektor<double,3> v2;
  Wektor<double,3> v3;
  Wektor<double,3> v4;
  Wektor<double,3> v5;
  Wektor<double,3> v6;
  Wektor<double,3> v7;
  Wektor<double,3> v8;
  Wektor<double,3> g1;
  Wektor<double,3> g2;
  Wektor<double,3> g3;
  Wektor<double,3> g4;
  Wektor<double,3> g5;
  Wektor<double,3> g6;
  Wektor<double,3> g7;
  Wektor<double,3> g8;
  Prostopadloscian () {}
public:
  Prostopadloscian (double a, double b, double c);
  
  void przesun (Wektor<double,3> przesuniecie);
  void obroc (MacierzRot obrocenie);
  void rysuj ()  override;
};

#endif
