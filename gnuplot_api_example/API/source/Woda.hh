#ifndef WODA_HH
#define WODA_HH

#include <iostream>
#include "Plaszczyzna.hh"


class Woda :public Plaszczyzna
{

public:
  Woda (double a, double b, double c);
  Woda() {}
  
  void rysuj ();
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik);
  
};

#endif
