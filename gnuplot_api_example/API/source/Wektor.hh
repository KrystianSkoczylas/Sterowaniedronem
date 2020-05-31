#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
/*!
 *\brief Definicja Szablonu Wektora
 *
 *Plik zawiera definicje szablonu wektora, jest to klasa podstawowa.
 *Mozliwe jest okreslenie typu i rozmiaru wektora.
 */
template <class TYP, int ROZMIAR>
class Wektor {
  /*!
   *\brief Wektor reprezentowany jako tablica
   *
   *Tablica o zadanym typie i rozmiarze jest przedstawieniem danego wektora.
   */
  TYP tab[ROZMIAR];
  /*!
   *\brief Ile istnieje wektorow
   *
   *Statyczne pole zawierajace inforamcje ile istnije aktulanie wektorow
   */
  static int ile_istnieje;
   /*!
   *\brief Ile utworzono wektorow
   *
   *Statyczne pole zawierajace inforamcje ile uworzono w sumie wektorow
   */
  static int ile_utworzono;
  
public:
  /*!
   *\brief Zwraca liczbe istniejacych wektorow
   *
   *return - Liczba calkowita istniejacych wektorow
   */
  static int zwroc_istniejace() {return ile_istnieje;};
   /*!
   *\brief Zwraca liczbe usworzonych wektorow
   *
   *return - Liczba calkowita utworszonych wektorow
   */
  static int zwroc_utworzone() {return ile_utworzono;};
   /*!
   *\brief Konstruktor kopiujacy
   *
   *Zastapienie domyslnego konstrukora kopiujacego. Konstruktor przypisuje starym polom
   *wektora nowe pola, oraz liczy liczbe utworzonych i stniejacych wektorow.
   *\param[in] nowy - nowy wektor na ktory bedzie przekopiowany stary
   */
  Wektor(const Wektor & nowy) { for(int i=0;i<ROZMIAR;++i) {tab[i]=nowy.tab[i];}
    ile_istnieje++; ile_utworzono++; }
   /*!
   *\brief Dekonstruktor
   *
   *Zastopienie domyslnego dekonstruktora. Dekonstruktor zmniejsza liczbe istniejacych 
   *wektorow, ale nie zmneijsz liczby utworzonych wektorow.
   */
  ~Wektor() {ile_istnieje--;} 
  /*!
   *\brief Konstruktor bezparametryczny wektora
   *
   *Konstruktor inicjalizuje wszystkie elemety wektora wartoscia 0.
   */
  Wektor() {for(int i=0;i<ROZMIAR;++i) tab[i]=0; ile_istnieje++; ile_utworzono++; } 
  /*!
   *\brief Przeciazenie nawiasow klamrowych
   *
   *Pozwala odwolywac sie do danego elementu wektora, bez mozliwosci jego zmiany.
   *\param[in] ind - indeks elemetu do ktorego chcemy sie odwolac.
   *\return Zwraca referencje do zadanego elemtu.
   */  
  const TYP & operator[] (int ind) const {
    if (ind < 0 || ind > ROZMIAR) {
      std::cerr << "blad: poza zakresem" <<  std::endl;
      exit(1); 
    }
    return tab[ind];
  };
  /*!
   *\brief Przeciazenie nawiasow klamrowych
   *
   *Pozwala odwolywac sie do danego elementu wektora, oraz daje mozliwosci jego zmiany.
   *\param[in] ind - indeks elemetu do ktorego chcemy sie odwolac.
   *return Zwraca referencje do zadanego elemtu.
   */    
  TYP & operator[] (int ind) {
    if (ind < 0 || ind > ROZMIAR) {
      std::cerr << "blad: poza zakresem" <<  std::endl;
      exit(1);
    }
    return tab[ind];
  };
  /*!
   *\brief Funkcja wuliczajaca dlugosc wektora.
   *
   *Funkcja wylicza dlugosc wektora dla ktorego zostala wywolana, zwracjac wartosc.
   */  
  TYP dlugosc() const;
  /*!
   *\brief Przeciazenie operatora mnozenia wektorow
   *
   *Umozliwia naturalny zapis iloczynu skalarnego dwoch wektorow, zwaracjac wartosc.
   */  
  TYP operator * (const Wektor<TYP,ROZMIAR> & W2) const;//OK iloczyn skalarny
  /*!
   *\brief Przeciazenie operatora mnozenia wektora i liczby
   *
   *Umolzliwia naturalny zapis mnozenia wektora przez liczbe, zwracajac wektor.
   */  
  Wektor<TYP,ROZMIAR> operator * (TYP skalar) const; // W * 2 OK
  /*!
   *\brief Przeciazenie operatora dodawania wektorow
   *
   *Umozliwia naturalny zapis dodawania dwoch wektorow, zwracajac wektor.
   */  
  Wektor<TYP,ROZMIAR>  operator + (const Wektor<TYP,ROZMIAR> & W2) const;//OK bez & bez const
  /*!
   *\brief Przeciazenie operatora odejmowania wektorow
   *
   *Umozliwia naturalny zapis odejmowania dwoch wektorow, zwracajac wektor.
   */  
  Wektor<TYP,ROZMIAR>  operator - (const Wektor<TYP,ROZMIAR> & W2) const;//OK bez &
  /*!
   *\brief Przeciazenie operatora dzielenia wektorow
   *
   *Umozliwia naturalny zapis dzielenia dwoch wektorow, zwracajac wektor.
   */  
  Wektor<TYP,ROZMIAR> operator / (TYP skalar) const;//  W / 2
};
/*!
 *\brief Przeciazenie operatora mnozenia liczby i wektora
 *
 *Umolzliwia naturalny zapis mnozenia liczby przez wektor, zwracajac wektor.
 */  
template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP skalar, const Wektor<TYP,ROZMIAR> & W2) ; // 3 * W funkcja poza klasa OK
/*!
 *\brief Przeciazenie operatora wczytywania wektora
 *
 *Umozliwia wcztywanie wektora ze strumienia i zapis wartosci do elemntow wektora.
 */  
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek); /*wczytanie wektora OK*/
/*!
 *\brief  Przeciazenie operatora wyswietlania wektora
 *
 *umozliwia wyswietlenia wektora na strumien.
 */  
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek); /*wyswietlenie wektora OK*/

#endif

