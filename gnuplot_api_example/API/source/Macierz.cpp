#include "Macierz.hh"

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac) /*wczytanie macierzy */
{
  for(int i=0;i<ROZMIAR;++i)
    {
      Strm>>Mac[i];
    }
  return Strm;
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac)/*wyswietlenie macierzy */
{
  for(int i=0;i<ROZMIAR;++i)
    {
      Strm<<Mac[i]<<" "<<std::endl;
    }
  return Strm;
}

template <class TYP, int ROZMIAR>
 Macierz<TYP,ROZMIAR>  Macierz<TYP,ROZMIAR>::operator + (const Macierz<TYP,ROZMIAR> & W) const
{ // dziala bez &
  Macierz<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      for(int j=0;j<ROZMIAR;++j)
	{
	  wyn[i][j]=tab[i][j]+W[i][j];
	}
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
 Macierz<TYP,ROZMIAR>  Macierz<TYP,ROZMIAR>::operator - (const Macierz<TYP,ROZMIAR> & W) const
{// dziala bez &
  Macierz<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      for(int j=0;j<ROZMIAR;++j)
	{
	  wyn[i][j]=tab[i][j]-W[i][j];
	}
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
 Macierz<TYP,ROZMIAR>  Macierz<TYP,ROZMIAR>::operator * (const Macierz<TYP,ROZMIAR> & W) const /*mnozeniemacie */
{//dziala bez &
  Macierz<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      for(int j=0;j<ROZMIAR;++j)
	{ 
	  for(int k=0;k<ROZMIAR;++k)
	  wyn[i][j]+=tab[i][k]*W[k][j];
	}
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
 Wektor<TYP,ROZMIAR>  Macierz<TYP,ROZMIAR>::operator * (const Wektor<TYP,ROZMIAR> & W) const /*macierzyprzezwer */
{//dziala bez &
  Wektor<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      for(int j=0;j<ROZMIAR;++j)
	{
	  wyn[i]+=W[j]*tab[i][j];//OK OK
	}
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
 Macierz<TYP,ROZMIAR>  Macierz<TYP,ROZMIAR>::transpozycja() const
{// dziala bez &
  Macierz<TYP,ROZMIAR> wyn;
  for(int i=0;i<ROZMIAR;++i)
    {
      for(int j=0;j<ROZMIAR;++j)
	{
	 wyn[i][j]=tab[j][i];
	}
    }
  return wyn;
}

template <class TYP, int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::Wyznacznik()const
{
  bool wylaczoneWiersze[ROZMIAR];
  bool wylaczone_kolumny[ROZMIAR];
  for(int i=0;i<ROZMIAR;++i)
    {
      wylaczoneWiersze[i] = false;
      wylaczone_kolumny[i] = false;
    }
  return wyznacznikRekurencyjny(wylaczoneWiersze, wylaczone_kolumny);
}

template <class TYP, int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::wyznacznikRekurencyjny(bool wylaczoneWiersze[ROZMIAR], bool wylaczone_kolumny[ROZMIAR]) const
{
  if(sumujTrue(wylaczoneWiersze) == ROZMIAR-1 && sumujTrue(wylaczone_kolumny) == ROZMIAR-1)
    {
      for(int i=0;i<ROZMIAR;++i)
	{
	  for(int j=0;j<ROZMIAR;++j) if(!wylaczoneWiersze[i] && !wylaczone_kolumny[j]) return tab[i][j];
	}
      exit(1);
    }
	
  int j = 0;
  TYP det;
  det=0;
  TYP minus;
  minus=1;
  int prawdziwy_nr_wiersza = 0;
	
  while(wylaczone_kolumny[j]) { j++; }
	
  wylaczone_kolumny[j] = true;
  for(int i=0;i<ROZMIAR;++i)
    {
      if(wylaczoneWiersze[i]) continue;
      if((prawdziwy_nr_wiersza)%2 == 0) minus = 1; else minus=-1;
      wylaczoneWiersze[i] = true;
      det = det+(minus * tab[i][j] * wyznacznikRekurencyjny(wylaczoneWiersze, wylaczone_kolumny));
      wylaczoneWiersze[i] = false;
      prawdziwy_nr_wiersza++;
    }
  wylaczone_kolumny[j] = false;
  return det;
}

template <class TYP, int ROZMIAR>
int Macierz<TYP,ROZMIAR>::sumujTrue(bool array[ROZMIAR]) const
{
  int suma = 0;
  for(int i=0;i<ROZMIAR;++i)
    {
      if(array[i]) suma++;
    }
  return suma;
}

