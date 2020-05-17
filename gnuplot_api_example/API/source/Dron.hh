#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Sruba.hh"
#include "Bryla.hh"
class Dron :public Prostopadloscian
{
  MacierzRot Bazowa_orientacja_srub;
  Wektor<double,3> Bazowe_polozenie_srubyL;
  Wektor<double,3> Bazowe_polozenie_srubyP;
public:
  
  Sruba L;
  Sruba P;
  void obrot (double stopnie);
  void plyn (double stopnie, double odleglosc);
  Dron(double a, double b, double c);
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik)override;
  void rysuj()override;

  void ustaw_bazowe_polozenie_orientacje_srub ();

  //  int wez_indeks() const;
  
};

#endif
