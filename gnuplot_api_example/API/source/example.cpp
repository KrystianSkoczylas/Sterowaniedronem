#include <iostream>
#include "Dr3D_gnuplot_api.hh"

#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzRot.hh"
#include "Prostopadloscian.hh"
#include "GraniastoslupSzesc.hh"
#include "Dron.hh"
#include "Sruba.hh"
#include "Plaszczyzna.hh"
#include "Dno.hh"
#include "Woda.hh"
#include "Bryla.hh"
#include "DronInterfejs.hh"
#include "Przeszkoda.hh"
#include "PrzeszkodaProstopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {
  cout<<"Liczba utworzonych wektorow: "<< Wektor<double,3>::zwroc_utworzone();
  cout<<endl;
  cout<<"Liczba istniejacych wektorow: "<< Wektor<double,3>::zwroc_istniejace();
  cout<<endl;
  cout<<"Liczba utworzonych bryl: "<< Bryla::zwroc_utworzone();
  cout<<endl;
  cout<<"Liczba istniejacych bryl: "<< Bryla::zwroc_istniejace();
  cout<<endl;
 
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,0));
  std::vector<Przeszkoda*> lista_przeszkod;
  std::vector<Dron*> kolekcja_dronow;
  Dron* D;
 
  Dno Dn(199.0,199.0,-80.0);
  Dn.ustawwskaznik(api);
  lista_przeszkod.push_back(&Dn);
  Woda W(199.0,199.0,80.0);
  W.ustawwskaznik(api);
  lista_przeszkod.push_back(&W);

  Dron Dron1(30.0,25.0,15.0);
  Dron1.ustawwskaznik(api);
  kolekcja_dronow.push_back(new Dron(Dron1));
  kolekcja_dronow[0]->plyn(0,-70,lista_przeszkod);
  lista_przeszkod.push_back(kolekcja_dronow[0]);
  D=kolekcja_dronow[0];
  
  Dron Drugi(30.0,30.0,30.0);
  Drugi.ustawwskaznik(api);
  kolekcja_dronow.push_back(new Dron(Drugi));
  kolekcja_dronow[1]->plyn(0,65,lista_przeszkod);
  lista_przeszkod.push_back(kolekcja_dronow[1]);
 
  Dron Trzeci(30.0,20.0,20.0);
  Trzeci.ustawwskaznik(api);
  kolekcja_dronow.push_back(new Dron(Trzeci));
  lista_przeszkod.push_back(kolekcja_dronow[2]);

  
  PrzeszkodaProstopadloscian Pro(10,20,30);
  Pro.ustawwskaznik(api);
  lista_przeszkod.push_back(&Pro);
  PrzeszkodaProstopadloscian Pro2(15,20,10);
  Pro2.ustawwskaznik(api);
  lista_przeszkod.push_back(&Pro2);
  PrzeszkodaProstopadloscian Pro3(1,1,40);
  Pro3.ustawwskaznik(api);
  lista_przeszkod.push_back(&Pro3);
  
  Dn.rysuj();
  W.rysuj();
  
  Wektor<double,3> Wek;
  Wek[0]=80; Wek[1]=40; Wek[2]=-10;
  Pro.przesun(Wek);
  Pro.rysuj();
  Wektor<double,3> Wek2;
  Wek2[0]=0; Wek2[1]=50; Wek2[2]=-10;
  Pro2.przesun(Wek2);
  Pro2.rysuj();
  Wektor<double,3> Wek3;
  Wek3[0]=20; Wek3[1]=-70; Wek3[2]=0;
  Pro3.przesun(Wek3);
  Pro3.rysuj();
  Wektor<double,3> Wekor;
  Wekor[0]=50; Wekor[2]=50;
  
  kolekcja_dronow[0]->rysuj();
  kolekcja_dronow[1]->rysuj();
  kolekcja_dronow[2]->rysuj();
 
  cout<<"Liczba utworzonych wektorow: "<< Wektor<double,3>::zwroc_utworzone();
  cout<<endl;
  cout<<"Liczba istniejacych wektorow: "<< Wektor<double,3>::zwroc_istniejace();
  cout<<endl;
  cout<<"Liczba utworzonych bryl: "<< Bryla::zwroc_utworzone();
  cout<<endl;
  cout<<"Liczba istniejacych bryl: "<< Bryla::zwroc_istniejace();
  cout<<endl;

  
  char ktory;
  cout<<"Wybierz Drona do sterowania (domyslnie Dron 1)"<<endl;
  cout<<"1- Dron 1(Dlugi)";
  cout<<"Polozenie Drona "<<kolekcja_dronow[0]->dostan_srodek();
  cout<<endl;
  cout<<"2- Dron 2(Kostka)";
  cout<<"Polozenie Drona "<<kolekcja_dronow[1]->dostan_srodek();
  cout<<endl;
  cout<<"3- Dron 3(Srodkowy)";
  cout<<"Polozenie Drona "<<kolekcja_dronow[2]->dostan_srodek();
  cout<<endl;
  std::cin>>ktory;
  if(ktory=='1')
    D=kolekcja_dronow[0];
  if(ktory=='2')
    D=kolekcja_dronow[1];
  if(ktory=='3')
    D=kolekcja_dronow[2];

  
  cout<<"Liczba utworzonych wektorow: "<< Wektor<double,3>::zwroc_utworzone();
  cout<<endl;
  cout<<"Liczba istniejacych wektorow: "<< Wektor<double,3>::zwroc_istniejace();
  cout<<endl;
  cout<<"Liczba utworzonych bryl: "<< Bryla::zwroc_utworzone();
  cout<<endl;
  cout<<"Liczba istniejacych bryl: "<< Bryla::zwroc_istniejace();
  cout<<endl;
  cout<<"q-zakoncz"<<endl;
  cout<<"p-plyn"<<endl;
  cout<<"o-obroc"<<endl;
  cout<<"m-menu"<<endl;
  cout<<"1-zmiana na Dron 1(Dlugi) ";
  cout<<"Polozenie Drona "<<kolekcja_dronow[0]->dostan_srodek();
  cout<<endl;
  cout<<"2-zmiana na Dron 2(Kostka) ";
  cout<<"Polozenie Drona "<<kolekcja_dronow[1]->dostan_srodek();
  cout<<endl;
  cout<<"3-zmiana na Dron 3(Srodkowy) ";
  cout<<"Polozenie Drona "<<kolekcja_dronow[2]->dostan_srodek();
  cout<<endl;
  
  char wybor;
  while(wybor!='q')
    {
      std::cin>>wybor;
      switch(wybor)
	{
	case 'q':
	  {
	    std::cout<<"Koniec"<<std::endl;
	    return 0;
	  }
	case 'p':
	  {
	    double odleglosc, stopnie;
	    std::cout<<"plyn. Podaj stopnie: ";
	    std::cin>>stopnie;
	    std::cout<<"plyn. Podaj odleglosc: ";	   
	    std::cin>>odleglosc;
	    D->plyn(stopnie,odleglosc,lista_przeszkod);
	    break;
	  }
	case 'o':
	  {
	    double ile,stopnie;
	    std::cout<<"obrot. Podaj ile razy: ";
	    std::cin>>ile;
	    std::cout<<"obrot. Podaj stopnie: ";
	    std::cin>>stopnie;
	    for(int i=0;i<ile;++i)
	      {D->obrot(stopnie);}
	    break;
	  }
	case 'm':
	  {
	    cout<<"Liczba utworzonych wektorow: "<< Wektor<double,3>::zwroc_utworzone();
	    cout<<endl;
	    cout<<"Liczba istniejacych wektorow: "<< Wektor<double,3>::zwroc_istniejace();
	    cout<<endl;
	    cout<<"Liczba utworzonych bryl: "<< Bryla::zwroc_utworzone();
	    cout<<endl;
	    cout<<"Liczba istniejacych bryl: "<< Bryla::zwroc_istniejace();
	    cout<<endl;
	    cout<<"q-zakoncz"<<endl;
	    cout<<"p-plyn"<<endl;
	    cout<<"o-obroc"<<endl;
	    cout<<"m-menu"<<endl;
	    cout<<"1-zmiana na Dron 1(Dlugi) ";
	    cout<<"Polozenie Drona "<<kolekcja_dronow[0]->dostan_srodek();
	    cout<<endl;
	    cout<<"2-zmiana na Dron 2(Kostka) ";
	    cout<<"Polozenie Drona "<<kolekcja_dronow[1]->dostan_srodek();
	    cout<<endl;
	    cout<<"3-zmiana na Dron 3(Srodkowy) ";
	    cout<<"Polozenie Drona "<<kolekcja_dronow[2]->dostan_srodek();
	    cout<<endl;
	    break;
	  }
	case '1':
	  {
	    std::cout<<"zmiana na Dron 1"<<endl;
	    D=kolekcja_dronow[0];
	    break;
	  }
	case '2':
	  {
	    std::cout<<"zmiana na Dron 2"<<endl;
	    D=kolekcja_dronow[1];
	    break;
	  }
	case '3':
	  {
	    std::cout<<"zmiana na Dron 3"<<endl;
	    D=kolekcja_dronow[2];
	    break;
	  }
	default: std::cout<<"Nieznana opcja"<<std::endl;break;
	}     
    }
}
