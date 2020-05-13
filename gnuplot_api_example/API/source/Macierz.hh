#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"

template <class TYP, int ROZMIAR>
class Macierz {
protected:
  Wektor<TYP,ROZMIAR> tab[ROZMIAR];
  TYP wyznacznikRekurencyjny(bool wylaczoneWiersze[ROZMIAR], bool wylaczone_kolumny[ROZMIAR]) const;
  int sumujTrue(bool array[ROZMIAR]) const;
public:
  const Wektor<TYP,ROZMIAR> & operator[] (int ind) const {
    if (ind < 0 || ind > ROZMIAR) {
      std::cerr << "blad: poza zakresem" << std::endl;
      exit(1);
    }
    return tab[ind];
  };

  Wektor<TYP,ROZMIAR> & operator[] (int ind) {
    if (ind < 0 || ind > ROZMIAR) {
      std::cerr << "blad: poza zakresem" <<  std::endl;
      exit(1);
    }
    return tab[ind];
  };
  
  Macierz<TYP,ROZMIAR>  operator + (const Macierz<TYP,ROZMIAR> & W) const;//OKbez& bez const
  Macierz<TYP,ROZMIAR>  operator - (const Macierz<TYP,ROZMIAR> & W) const;//OKbez& bez const
  Macierz<TYP,ROZMIAR>  operator * (const Macierz<TYP,ROZMIAR> & W) const; //OKbez& macierzrazymacierz bez const
  Wektor<TYP,ROZMIAR>  operator * (const Wektor<TYP,ROZMIAR> & W) const;//OKbez& macierz razy wektor bez const
  
  Macierz<TYP,ROZMIAR>  transpozycja() const;//OK bez &
  
  TYP Wyznacznik() const;//OK
};

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac);//OK

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac);//OK

#endif
