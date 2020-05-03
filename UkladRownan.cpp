#include "UkladRownan.h"


template<class TYP,int ROZMIAR>
const MacierzKw<TYP, ROZMIAR> & UkladRownan<TYP, ROZMIAR>::get_A() const
{
    return this->A;
}

template<class TYP,int ROZMIAR>
const Wektor<TYP, ROZMIAR> & UkladRownan<TYP, ROZMIAR>::get_b() const
{
    return this->b;
}

template<class TYP,int ROZMIAR>
void UkladRownan<TYP, ROZMIAR>::set_A(const MacierzKw<TYP, ROZMIAR> & in)
{
    this->A = in;
}

template<class TYP,int ROZMIAR>
void UkladRownan<TYP, ROZMIAR>::set_b(const Wektor<TYP, ROZMIAR> & in)
{
    this->b = in;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> UkladRownan<TYP, ROZMIAR>::Oblicz() const
{
    Wektor<TYP, ROZMIAR> tmp;
    tmp=this->A.odwrotnosc()* b;
    return tmp;
}

template<class TYP,int ROZMIAR>
std::istream & operator >> (std::istream & strm, UkladRownan<TYP, ROZMIAR> & ukl)
{
    MacierzKw<TYP, ROZMIAR> tmp;
    Wektor<TYP, ROZMIAR> tmp2;
    strm>>tmp;
    ukl.set_A(tmp.transponowane());
    strm>>tmp2;
    ukl.set_b(tmp2);
    return strm;
}

template<class TYP,int ROZMIAR>
std::ostream & operator << (std::ostream & strm, const UkladRownan<TYP, ROZMIAR> & ukl)
{
    strm<<ukl.get_A()<<"\n"<<ukl.get_b();
    return strm;
}



