#include "wektor.cpp"

template class Wektor<double,3>;
template std::istream & operator >> (std::istream & strm,Wektor <double,3> &W);
template class Wektor<LZespolona,2>;
