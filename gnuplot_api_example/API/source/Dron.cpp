#include "Dron.hh"

Dron::Dron (double a, double b, double c)
{
  indeks =0;
  v1[0]=-a/2; v1[1]=b/2; v1[2]=-c/2;
  v2[0]=a/2; v2[1]=b/2; v2[2]=-c/2;
  v3[0]=a/2; v3[1]=-b/2; v3[2]=-c/2;
  v4[0]=-a/2; v4[1]=-b/2; v4[2]=-c/2;
  v5[0]=-a/2; v5[1]=b/2; v5[2]=c/2;
  v6[0]=a/2; v6[1]=b/2; v6[2]=c/2;
  v7[0]=a/2; v7[1]=-b/2; v7[2]=c/2;
  v8[0]=-a/2; v8[1]=-b/2; v8[2]=c/2;
  g1=v1;
  g2=v2;
  g3=v3;
  g4=v4;
  g5=v5;
  g6=v6;
  g7=v7;
  g8=v8;
  L.ustaw_srube(a/4,a/4);
  P.ustaw_srube(a/4,a/4);
  ustaw_bazowe_polozenie_orientacje_srub();
  L.zmien_orientacje(Bazowa_orientacja_srub);
  P.zmien_orientacje(Bazowa_orientacja_srub);
  L.zmien_srodek(srodek + (polozenie * Bazowe_polozenie_srubyL));
  P.zmien_srodek(srodek + (polozenie * Bazowe_polozenie_srubyP));
}

void Dron::obrot (double stopnie)
{
  for(double i=0;i<=stopnie;++i)
    { 
      MacierzRot R(1,'z');
      obroc(R);
      L.zmien_srodek(srodek + (polozenie * Bazowe_polozenie_srubyL));
      P.zmien_srodek(srodek + (polozenie * Bazowe_polozenie_srubyP));
      L.zmien_orientacje(polozenie * Bazowa_orientacja_srub);
      P.zmien_orientacje(polozenie * Bazowa_orientacja_srub);
      MacierzRot Krecenie(15,'z');
      L.obroc(Krecenie);
      P.obroc(Krecenie);
      rysuj();
    }
}

void Dron::plyn (double stopnie, double odleglosc)
{
  Wektor<double,3> W;
  W[0]=odleglosc;
  W=polozenie*W;
  MacierzRot R(-stopnie,'y');
  W=R*W;
  double dlugosc_wektora=W.dlugosc();
  W=W/dlugosc_wektora;
  
  for(double i=0;i<dlugosc_wektora;++i)
    { 
      przesun(W);
      L.zmien_srodek(srodek + (polozenie * Bazowe_polozenie_srubyL));
      P.zmien_srodek(srodek + (polozenie * Bazowe_polozenie_srubyP));
      MacierzRot Krecenie(15,'z');
      L.obroc(Krecenie);
      P.obroc(Krecenie);
      rysuj();
    }
}

void Dron::ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik)
{
  Prostopadloscian::ustawwskaznik(wskaznik);
  L.ustawwskaznik(wskaznik);
  P.ustawwskaznik(wskaznik);
}

void Dron::rysuj()
{
  api->erase_shape(indeks);
  Prostopadloscian::rysuj();
  L.rysuj();
  P.rysuj();
 }

void Dron::ustaw_bazowe_polozenie_orientacje_srub ()
{
  MacierzRot R(90,'y');
  Bazowa_orientacja_srub=R;
  Bazowe_polozenie_srubyL[0]=-20; Bazowe_polozenie_srubyL[1]=10; Bazowe_polozenie_srubyL[2]=0; 
  Bazowe_polozenie_srubyP[0]=-20; Bazowe_polozenie_srubyP[1]=-10;  Bazowe_polozenie_srubyP[2]=0;
}
