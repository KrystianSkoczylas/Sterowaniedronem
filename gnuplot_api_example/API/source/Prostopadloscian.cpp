#include "Prostopadloscian.hh"


Prostopadloscian::Prostopadloscian (double a, double b, double c)
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
}

void Prostopadloscian::przesun (Wektor<double,3> przesuniecie)
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
}

void Prostopadloscian::obroc (MacierzRot obrocenie)
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
  
}

int Prostopadloscian::rysuj (std::shared_ptr<drawNS::Draw3DAPI> api) const
{ int a;
  /* g1=srodek+polozenie*this->v1;
  g2=srodek+polozenie*this->v2;
  g3=srodek+polozenie*this->v3;
  g4=srodek+polozenie*this->v4;
  g5=srodek+polozenie*this->v5;
  g6=srodek+polozenie*this->v6;
  g7=srodek+polozenie*this->v7;
  g8=srodek+polozenie*this->v8;*/
 a=api->draw_polyhedron(vector<vector<Point3D> > {{
       drawNS::Point3D(g1[0],g1[1],g1[2]), drawNS::Point3D(g2[0],g2[1],g2[2]), drawNS::Point3D(g3[0],g3[1],g3[2]), drawNS::Point3D(g4[0],g4[1],g4[2])
      },{
       drawNS::Point3D(g5[0],g5[1],g5[2]), drawNS::Point3D(g6[0],g6[1],g6[2]), drawNS::Point3D(g7[0],g7[1],g7[2]), drawNS::Point3D(g8[0],g8[1],g8[2])	
	  }},"blue");
 return a;
}
