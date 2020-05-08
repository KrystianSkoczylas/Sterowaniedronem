#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>

template <class TYP, int ROZMIAR>
class Wektor {
  TYP tab[ROZMIAR];
public:
  Wektor() {for(int i=0;i<ROZMIAR;++i) tab[i]=0;}
  
  const TYP & operator[] (int ind) const {
    if (ind < 0 || ind > ROZMIAR) {
      std::cerr << "blad: poza zakresem" <<  std::endl;
      exit(1); 
    }
    return tab[ind];
  };
  
  TYP & operator[] (int ind) {
    if (ind < 0 || ind > ROZMIAR) {
      std::cerr << "blad: poza zakresem" <<  std::endl;
      exit(1);
    }
    return tab[ind];
  };
  
  TYP operator * (const Wektor<TYP,ROZMIAR> & W2) const;//OK iloczyn skalarny
  Wektor<TYP,ROZMIAR> operator * (TYP skalar) const; // W * 2 OK
  Wektor<TYP,ROZMIAR>  operator + (const Wektor<TYP,ROZMIAR> & W2) const;//OK bez & bez const
  Wektor<TYP,ROZMIAR>  operator - (const Wektor<TYP,ROZMIAR> & W2) const;//OK bez &
  Wektor<TYP,ROZMIAR> operator / (TYP skalar) const;//  W / 2
};

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP skalar, const Wektor<TYP,ROZMIAR> & W2) ; // 3 * W funkcja poza klasa OK

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek); /*wczytanie wektora OK*/

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek); /*wyswietlenie wektora OK*/

#endif

