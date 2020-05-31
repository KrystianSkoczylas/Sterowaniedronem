#include "Wektor.cpp"
#include "Macierz.cpp"

template class Wektor<double,3>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,3> &Wek);
template Wektor<double,3> operator * (double skalar, const Wektor<double,3> & W2);

template class Macierz<double,3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,3> &Mac);
