#include "Wektor.hh"
#include <cmath>
/*!
 *\brief Definicja metody szablonu wektora
 *
 *Zawiera definicje metod szablonu wektora.
 */

/*!
 *Umozliwia wczytanie wektora na strumien.
 *
 *\param[in] Strm - Strumien
 *\param[in] Wek - Wczytywany wektor
 *\return Zwraca strumien z wczytanym wektorem.
 */
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek)
{
  for(int i=0;i<ROZMIAR;++i)
    {
      Strm>>Wek[i];
    }
  return Strm;
}
/*!
 *Umozliwia wyswietlenie wektora na strumieniu
 *
 *\param[in] Strm- Strumien
 *\param[in] Wek - Wyswietlany wektor
 *\return Zwraca strumien z wyswietlanym wektorem.
 */
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek)
{
  for(int i=0;i<ROZMIAR;++i)
    {
      Strm<<Wek[i]<<" ";
    }
  return Strm;
}
/*!
 * Wyznacza iloczyn skalarny dwoch wektorow
 *
 *\param[in] W2 - Drugi Wektor 
 *\return Zwraca wynik iloczynu skalarnego.
 */
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
/*!
 *Oblicza mnozenie wektora przez liczbe 
 *
 *\param[in] skalar - Liczba przez ktora mnozymy.
 *\return Zwraca wynik operacji mnozenie wektora przez liczbe.
 */
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
/*!
 *Oblicza dzielenie wektora przez liczbe
 *
 *\param[in] skalar - Liczba przez ktora mnozymy.
 *\return Zwraca wynik operacji dzielenia wektora przez liczbe.
 */
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
/*!
 *Oblicza mnozenie liczby przez wektor
 *
 *\param[in] skalar - Liczba mnozona przez wektor.
 *\param[in] W2 - Wektor przez ktory mnozymy.
 *\return Zwraca wynik operacji mnozenia liczby przez wektor.
 */
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
/*!
 *Oblicza dodawanie wektorow
 *
 *\param[in] W2 -drugi wekor dodawany
 *\return Zwraca wynik operacji dodawania dwoch wektorow.
 */
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
/*!
 *Oblicza odejmowanie wekorow
 *
 *\param[in] W2 -drugi wekor odejmowany
 *\return Zwraca wynik operacji odejmowania dwoch wektorow.
 */
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
/*!
 *Oblicza dlugosc wektora
 *
 *\return Zwraca wyliczona dlugosc wektora.
 */
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
