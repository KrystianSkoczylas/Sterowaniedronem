#include "Wektor.hh"
#include <cmath>

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek)
{
  for(int i=0;i<ROZMIAR;++i)
    {
      Strm>>Wek[i];
    }
  return Strm;
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek)
{
  for(int i=0;i<ROZMIAR;++i)
    {
      Strm<<Wek[i]<<" ";
    }
  return Strm;
}

template <class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator * (const Wektor<TYP,ROZMIAR> & W2) const /*mnozenie wektorow iloczyn skalarny*/
{
  TYP wyn;
  wyn=0;
  for (int i=0;i<ROZMIAR;++i) {
    // wyn = wyn + tab[i] * W2.tab[i];
    wyn += tab[i] * W2.tab[i]; //Obie ok
  }
  return wyn;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (TYP skalar) const /*mnozeniewektoraprzezliczbe*/
{//W*2
  Wektor<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      wyn[i]=tab[i]*skalar;
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (TYP skalar) const
{// W/2
  Wektor<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      wyn[i]=tab[i]/skalar;
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP skalar, const Wektor<TYP,ROZMIAR> & W2) /*mnozenie liczby przez wektor*/
{//2*W
  Wektor<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      wyn[i]=skalar*W2[i];
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>  Wektor<TYP,ROZMIAR>::operator + (const Wektor<TYP,ROZMIAR> & W2) const /*dodawaniewektorow*/
{//dziala bez &
  Wektor<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      wyn[i]=tab[i]+W2[i];
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>  Wektor<TYP,ROZMIAR>::operator - (const Wektor<TYP,ROZMIAR> & W2) const /*odejmowaniewektoro*/
{
  Wektor<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      wyn[i]=tab[i]-W2[i];
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::dlugosc() const
{
  TYP wyn=0;
  for (int i=0;i<ROZMIAR;++i)
    {
      wyn += tab[i] * tab[i]; 
    }
  return sqrt(wyn);
  
}
