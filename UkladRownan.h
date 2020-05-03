#ifndef UKLADROWNAN_H
#define UKLADROWNAN_H
#include "MacierzKw.h"

template<class TYP,int ROZMIAR>
class UkladRownan{
    MacierzKw<TYP, ROZMIAR> A;
    Wektor<TYP, ROZMIAR> b;

public:
    UkladRownan():A(),b(){};
    UkladRownan(MacierzKw<TYP, ROZMIAR>  _A, Wektor<TYP, ROZMIAR>  _b):A(_A),b(_b){};
    const MacierzKw<TYP, ROZMIAR>  & get_A() const;
    const Wektor<TYP, ROZMIAR>  & get_b() const;
    void set_A(const MacierzKw<TYP, ROZMIAR>  & in);
    void set_b(const Wektor<TYP, ROZMIAR>  & in);

    Wektor<TYP, ROZMIAR> Oblicz() const;

};

template<class TYP, int ROZMIAR>
std::istream & operator >> (std::istream & strm, UkladRownan<TYP, ROZMIAR>  & ukl);
template<class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream & strm, const UkladRownan<TYP, ROZMIAR>  & ukl);


#endif
