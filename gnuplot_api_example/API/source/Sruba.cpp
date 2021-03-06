#include "Sruba.hh"

Sruba::Sruba (double a, double b)
{
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

void Sruba::przesun_srube (Wektor<double,3> W)
{
  przesun(W); 
  api->erase_shape(indeks);
  rysuj(); 
}

void Sruba::ustaw_srube (double a, double b)
{
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
