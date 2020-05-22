#ifndef WODA_HH
#define WODA_HH

#include <iostream>
#include "Plaszczyzna.hh"

#include "Przeszkoda.hh"
#include "DronInterfejs.hh"

class Woda :public Plaszczyzna, public Przeszkoda
{

public:
  Woda (double a, double b, double c);
  Woda() {}
  
  void rysuj ();
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik);

  bool czy_kolizja (DronInterfejs* D) override;
};

#endif
