#include"MacierzKw.cpp"

template class MacierzKw<double, 3>;
template std::istream & operator >> (std::istream & strm,MacierzKw <double,3> &W);
template std::ostream & operator << (std::ostream & strm,const MacierzKw <double,3> &W);
template class MacierzKw<LZespolona,5>;
template std::istream & operator >> (std::istream & strm,MacierzKw <LZespolona,5> &W);
template std::ostream & operator << (std::ostream & strm,const MacierzKw <LZespolona,5> &W);
