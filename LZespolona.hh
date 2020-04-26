#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <math.h>
#include <iostream>

using std::cout;


class  LZespolona {
public:
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */


LZespolona():re(0), im(0) {}
explicit LZespolona(double liczba): re(liczba), im(0) {}
explicit LZespolona(double liczba, double liczba2): re(liczba), im(liczba2) {}

LZespolona  operator + (LZespolona  Skl2) const;
LZespolona  operator - (LZespolona Skl2) const;
LZespolona  operator * (LZespolona Skl2) const;
LZespolona  operator / (LZespolona Skl2) const;
LZespolona operator / (double re) const;
LZespolona operator = (double liczba);

bool operator == (LZespolona Skl2) const;
bool operator != (LZespolona Skl2) const;

double Modul() const;
LZespolona Sprzezenie() const;
};





std::istream &operator >> (std::istream &strm, LZespolona &lzesp);
std::ostream &operator << (std::ostream &strm, const LZespolona lzesp);



#endif
