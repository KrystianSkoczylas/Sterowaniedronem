#include "MacierzRot.hh"
#include "math.h"
#define PI 3.141592653589793238

MacierzRot::MacierzRot(double a, char os)
{
  if(os=='x')
    {
      (*this)[0][0]=1; (*this)[0][1]=0;               (*this)[0][2]=0;
      (*this)[1][0]=0; (*this)[1][1]=cos((a*PI)/180); (*this)[1][2]=-sin((a*PI)/180);
      (*this)[2][0]=0; (*this)[2][1]=sin((a*PI)/180); (*this)[2][2]=cos((a*PI)/180);
    }

  else  if(os=='y')
    {
      (*this)[0][0]=cos((a*PI)/180);  (*this)[0][1]=0; (*this)[0][2]=sin((a*PI)/180);
      (*this)[1][0]=0;                (*this)[1][1]=1; (*this)[1][2]=0;
      (*this)[2][0]=-sin((a*PI)/180); (*this)[2][1]=0; (*this)[2][2]=cos((a*PI)/180);
    }
     
  else if(os=='z')
    {
      (*this)[0][0]=cos((a*PI)/180); (*this)[0][1]=-sin((a*PI)/180); (*this)[0][2]=0;
      (*this)[1][0]=sin((a*PI)/180); (*this)[1][1]=cos((a*PI)/180);  (*this)[1][2]=0;
      (*this)[2][0]=0;               (*this)[2][1]=0;                (*this)[2][2]=1;
    }
  else
    {
      (*this)[0][0]=1; (*this)[0][1]=0; (*this)[0][2]=0;
      (*this)[1][0]=0; (*this)[1][1]=1; (*this)[1][2]=0;
      (*this)[2][0]=0; (*this)[2][1]=0; (*this)[2][2]=1;
    }
 
}

MacierzRot::MacierzRot()
{
  (*this)[0][0]=1; (*this)[0][1]=0; (*this)[0][2]=0;
  (*this)[1][0]=0; (*this)[1][1]=1; (*this)[1][2]=0;
  (*this)[2][0]=0; (*this)[2][1]=0; (*this)[2][2]=1;
}

MacierzRot MacierzRot::operator = (Macierz<double,3> M)
{
  if(M.Wyznacznik()<0.999999 && M.Wyznacznik()>1.00000001)
    { std::cout<<"Wyznaczik rozny od 1"; exit(1);}
  if(M[0]*M[1]<-0.000000001 && M[0]*M[1]>0.00000001)
    { std::cout<<"Iloczyn skalarny rozny od 0"; exit(1);}
  if(M[1]*M[2]<-0.000000001 && M[0]*M[1]>0.00000001)
    { std::cout<<"Iloczyn skalarny rozny od 0"; exit(1);}
  if(M[0]*M[2]<-0.000000001 && M[0]*M[1]>0.00000001)
    { std::cout<<"Iloczyn skalarny rozny od 0"; exit(1);}

  for(int i=0;i<3;++i)
    {
      (*this)[i]=M[i];
    }
  return *this;
}
