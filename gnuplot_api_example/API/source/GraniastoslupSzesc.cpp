#include "GraniastoslupSzesc.hh"

//#define T 0.86602540378443864
GraniastoslupSzesc::GraniastoslupSzesc (double a, double b)
{
  indeks=0;
  v1[0]=-a/2;   v1[1]=a*T;    v1[2]=-b/2;
  v2[0]=a/2;    v2[1]=a*T;    v2[2]=-b/2;
  v3[0]=a;      v3[1]=0;      v3[2]=-b/2;
  v4[0]=a/2;    v4[1]=-a*T;   v4[2]=-b/2;
  v5[0]=-a/2;   v5[1]=-a*T;   v5[2]=-b/2;
  v6[0]=-a;     v6[1]=0;      v6[2]=-b/2;
  v7[0]=-a/2;   v7[1]=a*T;    v7[2]=b/2;
  v8[0]=a/2;    v8[1]=a*T;    v8[2]=b/2;
  v9[0]=a;      v9[1]=0;      v9[2]=b/2;
  v10[0]=a/2;  v10[1]=-a*T;  v10[2]=b/2;
  v11[0]=-a/2; v11[1]=-a*T;  v11[2]=b/2;
  v12[0]=-a;   v12[1]=0;     v12[2]=b/2;
  g1=v1;
  g2=v2;
  g3=v3;
  g4=v4;
  g5=v5;
  g6=v6;
  g7=v7;
  g8=v8;
  g9=v9;
  g10=v10;
  g11=v11;
  g12=v12;  
}

void GraniastoslupSzesc::przesun (Wektor<double,3> przesuniecie)
{
  srodek=srodek+przesuniecie;
  g1=srodek+polozenie*v1;
  g2=srodek+polozenie*v2;
  g3=srodek+polozenie*v3;
  g4=srodek+polozenie*v4;
  g5=srodek+polozenie*v5;
  g6=srodek+polozenie*v6;
  g7=srodek+polozenie*v7;
  g8=srodek+polozenie*v8;
  g9=srodek+polozenie*v9;
  g10=srodek+polozenie*v10;
  g11=srodek+polozenie*v11;
  g12=srodek+polozenie*v12;
}

void GraniastoslupSzesc::obroc (MacierzRot obrocenie)
{
  polozenie=polozenie*obrocenie;
  g1=srodek+polozenie*v1;
  g2=srodek+polozenie*v2;
  g3=srodek+polozenie*v3;
  g4=srodek+polozenie*v4;
  g5=srodek+polozenie*v5;
  g6=srodek+polozenie*v6;
  g7=srodek+polozenie*v7;
  g8=srodek+polozenie*v8;
  g9=srodek+polozenie*v9;
  g10=srodek+polozenie*v10;
  g11=srodek+polozenie*v11;
  g12=srodek+polozenie*v12;
}

void GraniastoslupSzesc::rysuj ()
{//int a;
   indeks=api->draw_polyhedron(vector<vector<Point3D> > {{
	 drawNS::Point3D(g1[0],g1[1],g1[2]), drawNS::Point3D(g2[0],g2[1],g2[2]), drawNS::Point3D(g3[0],g3[1],g3[2]), drawNS::Point3D(g4[0],g4[1],g4[2]), drawNS::Point3D(g5[0],g5[1],g5[2]), drawNS::Point3D(g6[0],g6[1],g6[2])
      },{
	 drawNS::Point3D(g7[0],g7[1],g7[2]), drawNS::Point3D(g8[0],g8[1],g8[2]), drawNS::Point3D(g9[0],g9[1],g9[2]), drawNS::Point3D(g10[0],g10[1],g10[2]), drawNS::Point3D(g11[0],g11[1],g11[2]), drawNS::Point3D(g12[0],g12[1],g12[2])	
	  }},"red");


   // return a;
}

void GraniastoslupSzesc::ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik)
{
  api=wskaznik;
}

void GraniastoslupSzesc::zmien_srodek (Wektor<double,3> nowy_srodek)
{
  srodek[0]=nowy_srodek[0];
  srodek[1]=nowy_srodek[1];
  srodek[2]=nowy_srodek[2];
}

void GraniastoslupSzesc::zmien_orientacje (MacierzRot nowy_obrot)
{
  polozenie[0][0]=nowy_obrot[0][0];  polozenie[0][1]=nowy_obrot[0][1];  polozenie[0][2]=nowy_obrot[0][2];
  polozenie[1][0]=nowy_obrot[1][0];  polozenie[1][1]=nowy_obrot[1][1];  polozenie[1][2]=nowy_obrot[1][2];
  polozenie[2][0]=nowy_obrot[2][0];  polozenie[2][1]=nowy_obrot[2][1];  polozenie[2][2]=nowy_obrot[2][2];
}
