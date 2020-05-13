#include <iostream>
#include "Dr3D_gnuplot_api.hh"

#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzRot.hh"
#include "Prostopadloscian.hh"
#include "GraniastoslupSzesc.hh"
#include "Dron.hh"
#include "Sruba.hh"

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
  std::cout<<"Halo"<<endl;
  // Wektor <double,3> W;
  // std::cin>>W;
  // std::cout<<W;
  //Macierz <double,3> M;
  //std::cin>>M;
  //std::cout<<M;
  
  //MacierzRot MR(30,'x');
  //std::cin>>MR;
  //std::cout<<MR;
  /* Prostopadloscian Dron(3,2,1);
  
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000));
  api->change_ref_time_ms(0);
  int d=Dron.rysuj(api);

  cout<<"q-zakoncz"<<endl;
  cout<<"p-przesun"<<endl;
  cout<<"o-obroc"<<endl;
  
  char wybor;
  while(wybor!='q')
    {
      wybor='a';
      std::cin>>wybor;
      switch(wybor)
	{
	case 'q':
	  {
	    std::cout<<"Koniec"<<std::endl;
	    exit(1);
	  }
	case 'p':
	  {
	    std::cout<<"przesuniecie. Podaj wektor: "<<std::endl;
	    api->erase_shape(d);
	    Wektor <double,3> W;
	    std::cin>>W;
	    Dron.przesun(W);
	    wait4key();
	    d=Dron.rysuj(api);
	    break;
	  }
	case 'o':
	  {
	    std::cout<<"obrot. Podaj stopnie i os: "<<std::endl;
	    api->erase_shape(d);
	    double stopnie;
	    char os;
	    std::cin>>stopnie;
	    std::cin>>os;
	    MacierzRot R(stopnie,os);
	    Dron.obroc(R);
	    wait4key();
	    d=Dron.rysuj(api);
	    break;
	  }
	default: std::cout<<"Nieznana opcja"<<std::endl;
	}
      
	}*/
  /*
  GraniastoslupSzesc G(3,4);
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000));
  api->change_ref_time_ms(0);
  G.rysuj();

  cout<<"q-zakoncz"<<endl;
  cout<<"p-przesun"<<endl;
  cout<<"o-obroc"<<endl;
  
  char wybor;
  while(wybor!='q')
    {
      wybor='a';
      std::cin>>wybor;
      switch(wybor)
	{
	case 'q':
	  {
	    std::cout<<"Koniec"<<std::endl;
	    exit(1);
	  }
	case 'p':
	  {
	    std::cout<<"przesuniecie. Podaj wektor: "<<std::endl;
	    api->erase_shape(G.indeks);
	    Wektor <double,3> W;
	    std::cin>>W;
	    G.przesun(W);
	    wait4key();
	    G.rysuj();
	    break;
	  }
	case 'o':
	  {
	    std::cout<<"obrot. Podaj ile razy, stopnie i os: "<<std::endl;
	    
	    //api->erase_shape(g);
	    double ile,stopnie;
	    char os;
	    std::cin>>ile;
	    std::cin>>stopnie;
	    std::cin>>os;
	    for(int i=0;i<ile;++i)
	      {
		api->erase_shape(G.indeks);
		MacierzRot R(stopnie,os);
		G.obroc(R);
		//wait4key();
		G.rysuj(); }
	    break;
	  }
	default: std::cout<<"Nieznana opcja"<<std::endl;break;
	}
      
	}*/ 

  
  Dron D(30.0,20.0,15.0);
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,1000));
  D.ustawwskaznik(api);
  D.L.ustawwskaznik(api);
  D.P.ustawwskaznik(api);
  
  api->change_ref_time_ms(0);
  D.rysuj();
   D.L.rysuj();
  
  wait4key();
  D.obrot(360);
  wait4key();
  D.plyn(45,50);
   wait4key();   
   exit(1); 

  /* Sruba S(10,7);
   std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,0));
   S.ustawwskaznik(api);
   S.rysuj();
   wait4key();

   
   exit(1); */ 
  /*
  wait4key();
  api->erase_shape(d);
  Wektor <double,3> W;
  W[0]=2; W[1]=3; W[2]=1;

  Dron.przesun(W);
  d=Dron.rysuj(api);

  wait4key();
  api->erase_shape(d);
  MacierzRot R(45,'x');
  Dron.obroc(R);
  d=Dron.rysuj(api);

  exit(1);
  */
  

  
  //std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();

  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();

  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}
