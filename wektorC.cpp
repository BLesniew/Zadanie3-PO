#include "wektor.cpp"

template class Wektor<double,3>;                                                           //To i wszystkie podobne powtórki po to żeby liczyć dopełnienia
template class Wektor<double,2>;
template std::istream & operator >> (std::istream & strm,Wektor <double,3> &W);
template std::ostream & operator << (std::ostream & strm,const Wektor <double,3> &W);
template class Wektor<LZespolona,5>;
template class Wektor<LZespolona,4>;
template std::istream & operator >> (std::istream & strm,Wektor <LZespolona,5> &W);
template std::ostream & operator << (std::ostream & strm,const Wektor <LZespolona,5> &W);


template<>                                                            //Gdy był w wektor.cpp error multiple declaration, nie wiem jak rozwiązać problem
double Wektor<LZespolona,5>::dlugosc() const
{
    double tmp = 0;
    for(int i=0;i<5;i++)
    {
        tmp+=((*this)[i] * (*this)[i].Sprzezenie()).re;
    }
    return tmp;
}

template<>
double Wektor<LZespolona,4>::dlugosc() const
{
    double tmp = 0;
    for(int i=0;i<4;i++)
    {
        tmp+=((*this)[i] * (*this)[i].Sprzezenie()).re;
    }
    return tmp;
}
