#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

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

class Plaszczyzna :public Bryla
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
  Wektor<double,3> v13;
  Wektor<double,3> v14;
  Wektor<double,3> v15;
  Wektor<double,3> v16;
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
  Wektor<double,3> g13;
  Wektor<double,3> g14;
  Wektor<double,3> g15;
  Wektor<double,3> g16;
public:
  Plaszczyzna (double a, double b, double c);
  Plaszczyzna () {}
  void rysuj () override;
};

#endif
