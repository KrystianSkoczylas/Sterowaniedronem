#ifndef DNO_HH
#define DNO_HH

#include <iostream>
#include "Plaszczyzna.hh"


class Dno :public Plaszczyzna
{

public:
  Dno (double a, double b, double c);
  Dno() {}
  
  void rysuj ();
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik);
  
};

#endif
