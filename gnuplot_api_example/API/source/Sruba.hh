#ifndef SRUBA_HH
#define SRUBA_HH

#include <iostream>
#include "GraniastoslupSzesc.hh"
#include "Bryla.hh"
class Sruba :public GraniastoslupSzesc
{
 
public:
  Sruba () {}
  Sruba(double a, double b);
  void przesun_srube (Wektor<double,3> W);
  void ustaw_srube (double a, double b);

};

#endif
