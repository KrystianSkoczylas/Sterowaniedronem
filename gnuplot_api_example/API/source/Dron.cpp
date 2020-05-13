#include "Dron.hh"

Dron::Dron (double a, double b, double c)
{
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
  L.ustaw_srube(a/2,a/2);
  P.ustaw_srube(a/2,a/2);
  
}

void Dron::obrot (double stopnie)
{
  for(double i=0;i<=stopnie;++i)
    { 
      MacierzRot R(1,'z');
      obroc(R);
      //lewa_sruba.zmien_orientacje(polozenie * bazowa_orientacja+sruby)
      //praw_sruba.zmien_orientacje(polozenie * bazowa_orientacja+sruby)
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
      //lewa_sruba.zmien_srodek(srodek + polozenie * bazowa_przesuniecieL)
      //prawa_sruba.zmien_srodek(srodek + polozenie * bazowa_przesuniecieP)
      rysuj();
      
      //std::cout<<i;
    }
}

void Dron::ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik)
{
  Prostopadloscian::ustawwskaznik(wskaznik);
  L.ustawwskaznik(wskaznik);
  P.ustawwskaznik(wskaznik);
}

void Dron::rysuj() {
  if(indeks != 0)
     api->erase_shape(indeks);
  Prostopadloscian::rysuj();
  //lewa_sruba.rysuj()
  //prawa_sruba.rysuj()
}

/*
j = uklad_bazowy
i - uklad_lokalny
A_ij(p) = sr + orint * p
A_ij(A_jk(p)) = sr_ij + orient_ij * (sr_jk + orient_jk * p)
A_ik(p) = sr_ij + orient_ij * sr_jk + orient_ij * orient_jk * p 
sr_ik = sr_ij + orient_ij * sr_jk
orient_ik = orient_ij * orient_jk

sr_jk = (-3,-1,0)
orient = Rot(y,pi/2)

*/

void Dron::ustaw_bazowe_polozenie_orientacje_srub ()
{
  MacierzRot R(90,'y');
  Bazowa_orientacja_srub=R;
  Bazowe_polozenie_srubyL[0]=-5; Bazowe_polozenie_srubyL[0]=-2; Bazowe_polozenie_srubyL[0]=0; 
  Bazowe_polozenie_srubyP[0]=-5; Bazowe_polozenie_srubyP[0]=-2;  Bazowe_polozenie_srubyP[0]=0;
}
