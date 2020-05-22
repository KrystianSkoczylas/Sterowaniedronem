#include "PrzeszkodaProstopadloscian.hh"

PrzeszkodaProstopadloscian::PrzeszkodaProstopadloscian(double a, double b, double c)
{
  indeks=0;
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

bool PrzeszkodaProstopadloscian::czy_kolizja (DronInterfejs* D)
{
  if(
     (D->dostan_srodek()[0] > (g4[0] - D->dostan_Promien()) ) &&
     (D->dostan_srodek()[0] < (g6[0] + D->dostan_Promien()) ) &&
     (D->dostan_srodek()[1] > (g4[1] - D->dostan_Promien()) ) &&
     (D->dostan_srodek()[1] < (g6[1] + D->dostan_Promien()) ) &&
     (D->dostan_srodek()[2] > (g4[2] - D->dostan_Promien()) ) &&
     (D->dostan_srodek()[2] < (g6[2] + D->dostan_Promien()) )
     )
    { std::cout<<"Kolizja z Przeszkoda"<<std::endl; return 1; } 
  else
    return 0;
}
