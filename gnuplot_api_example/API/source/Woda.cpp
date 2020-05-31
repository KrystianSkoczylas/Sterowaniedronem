#include "Woda.hh"

Woda::Woda (double a, double b, double c)
{
  indeks=0;
  v1[0]=-a/2;   v1[1]=b/2;   v1[2]=c;
  v2[0]=-a/6;   v2[1]=b/2;   v2[2]=c;
  v3[0]=a/6;    v3[1]=b/2;   v3[2]=c;
  v4[0]=a/2;    v4[1]=b/2;   v4[2]=c;
  v5[0]=-a/2;   v5[1]=b/6;   v5[2]=c;
  v6[0]=-a/6;    v6[1]=b/6;   v6[2]=c;
  v7[0]=a/6;    v7[1]=b/6;  v7[2]=c;
  v8[0]=a/2;   v8[1]=b/6;  v8[2]=c;
  v9[0]=-a/2;   v9[1]=-b/6;   v9[2]=c;
  v10[0]=-a/6;  v10[1]=-b/6;  v10[2]=c;
  v11[0]=a/6;  v11[1]=-b/6; v11[2]=c;
  v12[0]=a/2; v12[1]=-b/6; v12[2]=c;
  v13[0]=-a/2; v13[1]=-b/2;  v13[2]=c;
  v14[0]=-a/6;  v14[1]=-b/2;  v14[2]=c;
  v15[0]=a/6;  v15[1]=-b/2; v15[2]=c;
  v16[0]=a/2; v16[1]=-b/2; v16[2]=c;
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
  g13=v13;
  g14=v14;
  g15=v15;
  g16=v16;
}

void Woda::rysuj ()
{
  indeks=api->draw_surface(vector<vector<Point3D> > {{
      drawNS::Point3D(g1[0],g1[1],g1[2]), drawNS::Point3D(g2[0],g2[1],g2[2]), drawNS::Point3D(g3[0],g3[1],g3[2]), drawNS::Point3D(g4[0],g4[1],g4[2])
	  },{
      drawNS::Point3D(g5[0],g5[1],g5[2]), drawNS::Point3D(g6[0],g6[1],g6[2]), drawNS::Point3D(g7[0],g7[1],g7[2]), drawNS::Point3D(g8[0],g8[1],g8[2])       
	  },{
      drawNS::Point3D(g9[0],g9[1],g9[2]), drawNS::Point3D(g10[0],g10[1],g10[2]), drawNS::Point3D(g11[0],g11[1],g11[2]), drawNS::Point3D(g12[0],g12[1],g12[2])       
	  },{
      drawNS::Point3D(g13[0],g13[1],g13[2]), drawNS::Point3D(g14[0],g14[1],g14[2]), drawNS::Point3D(g15[0],g15[1],g15[2]), drawNS::Point3D(g16[0],g16[1],g16[2])       
	  }},"blue");
}

void Woda::ustawwskaznik (std::shared_ptr<drawNS::Draw3DAPI> wskaznik)
{
   Plaszczyzna::ustawwskaznik(wskaznik);
}

bool Woda::czy_kolizja (DronInterfejs* D)
{
  if(D->dostan_srodek()[2] > (g1[2]) )
    { std::cout<<"Kolizja z Woda"<<std::endl; return 1;} 
  else
    return 0;
}
