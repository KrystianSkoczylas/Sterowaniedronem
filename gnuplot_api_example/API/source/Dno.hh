#ifndef DNO_HH
#define DNO_HH

#include <iostream>
#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include "DronInterfejs.hh"

class Dno :public Plaszczyzna, public Przeszkoda
{
  Dno() {}
public:
  Dno (double a, double b, double c);
  
  void rysuj ();
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik);
  bool czy_kolizja (DronInterfejs* D) override;
};

#endif
