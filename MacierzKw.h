#ifndef MacierzKw_H
#define MacierzKw_H
#include "wektor.h"

enum Metoda{Laplace, Gauss, Sarrus};

//ZACHOWANIE KONWENCJI MATEMATYCNZEJ
//PRZYJMUJĘ KONWENCJĘ, ŻE Macierz[0][1] ZWRACAĆ BĘDZIE KOMÓRKĘ MACIERZY O ADRESIE 1,2 (a12)



template<class TYP,int ROZMIAR>
class MacierzKw{
    Wektor<TYP, ROZMIAR> tab[ROZMIAR];

public:
    MacierzKw();
    MacierzKw(Wektor<TYP,ROZMIAR> *w);

    /*
    MacierzKw(double a11,double a12,double a13,
        double a21,double a22,double a23,
        double a31,double a32,double a33);
    MacierzKw(Wektor a1, Wektor a2, Wektor a3);
    */


    const MacierzKw<TYP, ROZMIAR> transponowane() const;
    void transponuj();
    const MacierzKw<TYP,ROZMIAR> odwrotnosc() const;
    void odwroc();
    TYP wyznacznik(Metoda met) const;
    TYP wyznacznik() const;


    const Wektor<TYP, ROZMIAR> operator *(const Wektor<TYP, ROZMIAR> &W)const;
    const MacierzKw<TYP, ROZMIAR> operator *(const MacierzKw<TYP, ROZMIAR> &W)const;
    const MacierzKw<TYP, ROZMIAR> operator +(const MacierzKw<TYP, ROZMIAR> &W)const;
    const MacierzKw<TYP, ROZMIAR> operator -(const MacierzKw<TYP, ROZMIAR> &W)const;
    const MacierzKw<TYP, ROZMIAR> operator *(const TYP l)const;

    bool operator == (const MacierzKw<TYP, ROZMIAR> &W2) const;
    bool operator != (const MacierzKw<TYP, ROZMIAR> &W2) const;

    const Wektor<TYP, ROZMIAR> & operator[](int index) const;
    Wektor<TYP, ROZMIAR> & operator[] (int index);

private:
    TYP dopelnienieAlgebraiczne(int i, int j) const;
    const MacierzKw<TYP, ROZMIAR> macierzDopelnien() const;


};

template<class TYP, int ROZMIAR>
std::ostream & operator <<(std::ostream &strm, const MacierzKw<TYP, ROZMIAR> &W);
template<class TYP, int ROZMIAR>
std::istream & operator >>(std::istream &strm, MacierzKw<TYP, ROZMIAR> &W);

template<class TYP, int ROZMIAR>
const MacierzKw<TYP, ROZMIAR> & operator *(double l1,const MacierzKw<TYP, ROZMIAR> &W2);

void zamien(double &a, double &b);

template<class TYP, int ROZMIAR>
void zamien(Wektor<TYP, ROZMIAR> &w1, Wektor<TYP, ROZMIAR> &w2);


#endif // MacierzKw_H
