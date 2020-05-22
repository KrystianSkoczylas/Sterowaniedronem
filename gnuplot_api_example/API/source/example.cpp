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
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,0));
  std::vector<Przeszkoda* > lista_przeszkod;
  Dno Dn(199.0,199.0,-80.0);
  Dn.ustawwskaznik(api);
  lista_przeszkod.push_back(&Dn);
  Woda W(199.0,199.0,80.0);
  W.ustawwskaznik(api);
  lista_przeszkod.push_back(&W);
  Dron D(30.0,25.0,15.0);
  D.ustawwskaznik(api);
  lista_przeszkod.push_back(&D);
  Dron Drugi(30.0,30.0,30.0);
  Drugi.ustawwskaznik(api);
  lista_przeszkod.push_back(&Drugi);
 
  
  PrzeszkodaProstopadloscian Pro(10,20,30);
  Pro.ustawwskaznik(api);
  lista_przeszkod.push_back(&Pro);
  PrzeszkodaProstopadloscian Pro2(15,20,10);
  Pro2.ustawwskaznik(api);
  lista_przeszkod.push_back(&Pro2);
  PrzeszkodaProstopadloscian Pro3(1,1,40);
  Pro3.ustawwskaznik(api);
  lista_przeszkod.push_back(&Pro3);
  D.rysuj();
  Dn.rysuj();
  W.rysuj();
  Wektor<double,3> Wek;
  Wek[0]=80; Wek[2]=-10;
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
  Drugi.przesun_dron(Wekor);
  Drugi.rysuj();
  D.rysuj();
  
  cout<<"q-zakoncz"<<endl;
  cout<<"p-plyn"<<endl;
  cout<<"o-obroc"<<endl;
  cout<<"m-menu"<<endl;
  
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
	    //D.plyn(stopnie,odleglosc);//
	    D.plyn(stopnie,odleglosc,lista_przeszkod);//
	    
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
	      {D.obrot(stopnie);}
	    break;
	  }
	case 'm':
	  {
	    cout<<"q-zakoncz"<<endl;
	    cout<<"p-plyn"<<endl;
	    cout<<"o-obroc"<<endl;
	    cout<<"m-menu"<<endl;
	    break;
	  }
	default: std::cout<<"Nieznana opcja"<<std::endl;break;
	}     
    }
}
