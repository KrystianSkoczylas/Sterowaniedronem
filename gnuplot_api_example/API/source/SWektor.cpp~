#include "Wektor.cpp"
#include "Macierz.cpp"
#include "LZespolona.hh"
#include "UkladRownanLiniowych.cpp"

template class Wektor<double,3>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,3> &Wek);
template Wektor<double,3> operator * (double skalar, const Wektor<double,3> & W2);

template class Wektor<double,4>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,4> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,4> &Wek);
template Wektor<double,4> operator * (double skalar, const Wektor<double,4> & W2);

template class Wektor<double,5>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,5> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,5> &Wek);
template Wektor<double,5> operator * (double skalar, const Wektor<double,5> & W2);

template class Wektor<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona,5> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona,5> &Wek);
template Wektor<LZespolona,5> operator * (LZespolona skalar, const Wektor<LZespolona,5> & W2);

template class Macierz<double,5>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,5> &Mac);

template class Macierz<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona,5> &Mac);

template class UkladRownanLiniowych<double,5>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<double,5> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<double,5> &UklRown);

template class UkladRownanLiniowych<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona,5> &UklRown);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<LZespolona,5> &UklRown);
