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
  Dno Dn(199.0,199.0,-80.0);
  Dn.ustawwskaznik(api); 
  Woda W(199.0,199.0,80.0);
  W.ustawwskaznik(api);  
  Dron D(30.0,25.0,15.0);
  D.ustawwskaznik(api);
  D.rysuj();
  Dn.rysuj();
  W.rysuj(); 
  cout<<"q-zakoncz"<<endl;
  cout<<"p-plyn"<<endl;
  cout<<"o-obroc"<<endl;
  
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
	    D.plyn(stopnie,odleglosc);
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
	default: std::cout<<"Nieznana opcja"<<std::endl;break;
	}     
    }
}
