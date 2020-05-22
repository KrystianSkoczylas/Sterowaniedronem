#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Sruba.hh"
#include "Bryla.hh"
#include "DronInterfejs.hh"
#include "Przeszkoda.hh"
/*!
 *\file Plik zawierajacy klase Dron
 *\brief Definicja Klasy Dron
 *
 *Plik zawiera definicje klasy Drona, ktora jest klasa pochodna i
 *jest ona specjalizacja klasy Prostopadloscian. Klasa Drona zawiera
 *dwie sruby bedace elemetami typu klasa Sruba. 
 */

/*!
 *\brief Modeluje pojecie Drona
 *
 *Klasa modeluje pojecie drona o zadanych wymiarach,odpwiednio dlugosci,
 *szerokosci i wysokosci. Dron zawiera informacje o wszystkich swoich 
 *elemetach w tym parametry srub. Klasa umozliwia podstawowe sterowanie
 *dronem z animowanym ruchem.
 */
class Dron :public Prostopadloscian, public DronInterfejs, public Przeszkoda
//class Dron :public Prostopadloscian, public Przeszkoda
{
  /*!
   *\brief Bazowa orientacja srub
   *
   *Pole zawiera macierz rotacji okreslajace podstawowa orientacje srub
   *wzgledem podstawoej orientacji drona. Orientacja dla obu srub drona 
   *jest taka sama.
   */
  MacierzRot Bazowa_orientacja_srub;
  /*!
   *\brief Bazowe polozenie lewej sruby drona
   *
   *Pole zawiera wektor okreslajacy wspolrzedne polozenia lewej sruby
   *drona wzgledem srodka drona. Wektor posiada 3 pola odpowiadajace
   *kolejno wspolrzednym na osiach x, y, z ukladu.
   */
  Wektor<double,3> Bazowe_polozenie_srubyL;
  /*!
   *\brief Bazowe polozenie prawej sruby drona
   *
   *Pole zawiera wektor okreslajacy wspolrzedne polozenia prawej sruby
   *drona wzgledem srodka drona. Wektor posiada 3 pola odpowiadajace
   *kolejno wspolrzednym na osiach x, y, z ukladu.
   */
  Wektor<double,3> Bazowe_polozenie_srubyP;
  /*!
   *\brief Promien drona do kolizji
   *
   *Promien drona okresla niewidzialna kula wokol niego, ktora
   *sluzy do wykrywania kolizji. Jezeli przeszkoda znajdzie sie blizej
   *niz odleglosc promienia od srodka drona zostanie wykryte niebezpieczenstwo
   *kloizji drona z dana przeszkoda.
   */
  double Promien;
public:
  /*!
   *\brief Lewa sruba Drona
   *
   *Dron zawiera dwie sruby. Kazda sruba moze byc przesuwana razem z
   *dronem. Sruba posiada konkretne parametry dla danego typu drona.
   *Jest to lewa sruba drona patrzac na drona od strony tylnej scianki
   *ze srubami. 
   */
  Sruba L;
  /*!
   *\brief Prawa sruba Drona
   *
   *Dron zawiera dwie sruby. Kazda sruba moze byc przesuwana razem z
   *dronem. Sruba posiada konkretne parametry dla danego typu drona.
   *Jest to prawa sruba drona patrzac na drona od strony tylnej scianki
   *ze srubami. 
   */
  Sruba P;
  /*!
   *\brief Obraca drona wokol osi z o podane stopnie
   *
   *Metoda obraca calego drona wraz ze srubami wokol osi z o zadana
   *liczbe stopni. Podzas obrotu dron wraz ze srubami jest plynnie
   *animowany wraz z kreceniem sie srub podczas obrotu, gdyz obrot
   *sklada sie z poszczegolnych kolejno nastepujacych po sobie 
   *mniejszych obrotow. Po kazdym nowym mniejszym obrocie dron jest
   *rysowany na nowo.
   *\param[in] stopnie - Liczba stopni o jaka ma sie obrocic dron.
   */
  void obrot (double stopnie);
  /*!
   *\brief Powoduje ruch drona do przodu z opadaniem lub wznoszeniem
   *
   *Metoda umozliwia ruch drona na zadana odleglosc do przodu, z
   *jednoczesnym opadaniem jezeli podana wartosc stopni bedzie ujemna
   *(jezeli bedzie rowna -90 dron plynie pionowo w dol) lub z jednoczesnym
   *wznoszeniem jezeli podana wartosc stopni bedzie dodatnia (jezeli bedzie
   *rowna 90 dron plynie pionowo do gory) lub bez opadania ani wznoszenia,
   *jezeli wartosc stopni bedzie rowna 0 (dron porusza sie poziomo do przodu).
   *Podczas poruszania sie dron wraz z krecacymi sie srubami jest plynnie
   *animowany, gdyz ruch sklada sie poszczegolnych kolejno nastepujacych 
   *mniejszych przesuniec. Po kazdym  nowym  mniejszym przesunieciu
   *dron jest rysowany na nowo. 
   *\param[in] stopnie - Liczba stopni okreslajaca opadanie lub wznoszenie.
   *\param[in] odleglosc - Wartosc odleglosi o jaka ma poruszyc sie dron.
   */
  //void plyn (double stopnie, double odleglosc);
  void plyn (double stopnie, double odleglosc, std::vector<Przeszkoda*> l_przeszkod);
  /*!
    *\brief Konstruktor trzyparametryczny drona
    *
    *Konstruktor tworzy drona o zadanych wymiarach. Dron jest
    *reprezentowny jako prostopadloscian okreslnony dlugosciami
    *trzech bokow: dlugosciami bokow podstawy i wysokoscia.
    *Poczatkowo globalne wspolrzedne wierzcholkow drona sa takie
    *same jak jego wspolrzedne lokalne.
    *Ustawiane sa takze rozmiar, polozenie i orientacja srub drona.
    *Zmieniane sa srodki srub aby dostosowac sruby do drona.
    *\param[in] a - dlugosc drona wzdlus osi x i parametr rozmiaru srub
    *\param[in] b - dlugosc drona wzdlus osi y
    *\param[in] c - dlugosc drona wzdlus osi z
    */
  Dron(double a, double b, double c);
  /*!
   *\brief Ustawia wskaznik na drona
   *
   *Przypisuje konkretny wskaznik na konkretnego drona
   *aby mozna bylo sie pozniej do niego odwolywac.
   *Ustawia takze wskazniki na poszczegolne sruby drona.
   *\param[in] wskaznik - Do tego paramteru ustawiany jest wskaznik.
   */
  void ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik);
  /*!
   *\brief Rysuje calego drona
   *
   *Rysuje drona reprezentowanego jako prostopadloscian wraz z dwoma 
   *srubami reprezentowanymi jako granistoslupy szesciokatne foremne.
   *Sruby sa rysowane na tylnej sciance drona z odpwiednia poczatkowa
   *orientacja, ktora moze sie zmieniac w pozniejszym ruchu drona.
   */
  void rysuj()override;
  /*!
   *\brief Ustawia bazowe polozenie oraz orientacje srub drona
   *
   *Sruby sa obracane i przesuwane z parametrami dla danego drona,
   *ich polozenie wzgledem drona  jest ustalone i nie zmieniaja sie wzgledm
   *polozenia i orientacji drona. Sruby sa tak przesuwane i obracane aby
   *znalesc sie tylnej sciane danego drona.
   */
  void ustaw_bazowe_polozenie_orientacje_srub ();


  Wektor<double,3> dostan_srodek ()override ;
  double dostan_Promien ()override ;
  bool czy_kolizja (DronInterfejs* D) override; //override;
};

#endif
