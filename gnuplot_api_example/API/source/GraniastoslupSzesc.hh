#ifndef GRANIASTOSLUPSZESC_HH
#define GRANIASTOSLUPSZESC_HH

#define T 0.86602540378443864
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

class GraniastoslupSzesc :public Bryla
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
  Wektor<double,3> v9;
  Wektor<double,3> v10;
  Wektor<double,3> v11;
  Wektor<double,3> v12;
  Wektor<double,3> g1;
  Wektor<double,3> g2;
  Wektor<double,3> g3;
  Wektor<double,3> g4;
  Wektor<double,3> g5;
  Wektor<double,3> g6;
  Wektor<double,3> g7;
  Wektor<double,3> g8;
  Wektor<double,3> g9;
  Wektor<double,3> g10;
  Wektor<double,3> g11;
  Wektor<double,3> g12;
  GraniastoslupSzesc () {}
public:
  GraniastoslupSzesc (double a, double b);
  
  void przesun (Wektor<double,3> przesuniecie);
  void obroc (MacierzRot obrocenie);
  void zmien_srodek (Wektor<double,3> nowy_srodek);
  void zmien_orientacje (MacierzRot nowy_obrot);
  void rysuj () override;
};

#endif
