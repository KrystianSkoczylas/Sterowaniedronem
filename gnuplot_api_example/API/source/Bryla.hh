#ifndef BRYLA_HH
#define BRYLA_HH

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

class Bryla
{

protected:
  std::shared_ptr<drawNS::Draw3DAPI> api;
  int indeks;
  //Wektor<double,3> srodek;
  MacierzRot polozenie;

  static int ile_istnieje;
  static int ile_utworzono;
public:
  //konstruktor bez param, bazowe polozenie, indeks=-1,
  //konstruktor z param std::shared_ptr<drawNS::Draw3DAPI> wskaznik, to samo co ustaw wskaznik
  //dokonstruktor tylko statystyka--
  Bryla() {indeks=-1; ile_istnieje++; ile_utworzono++;}
  Bryla(std::shared_ptr<drawNS::Draw3DAPI> wskaznik) { api=wskaznik; ile_istnieje++; ile_utworzono++;}
  ~Bryla() {ile_istnieje--;}
  
  virtual void rysuj ()=0;
  //virtual void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik)=0;
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik);//zmian nazwy: zmienwskaznik

   Wektor<double,3> srodek;
  
  static int zwroc_istniejace() {return ile_istnieje;};
  static int zwroc_utworzone() {return ile_utworzono;};
  
};

#endif

