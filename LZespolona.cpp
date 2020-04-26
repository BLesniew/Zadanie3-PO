#include "LZespolona.hh"
#include<limits>



/*
LZespolona():re(0), im(0) {}
explicit LZespolona(double liczba): re(liczba), im(0) {}
explicit LZespolona(double liczba, double liczba2): re(liczba), im(liczba2) {}

LZespolona  operator + (LZespolona  Skl2) const;
LZespolona  operator - (LZespolona Skl2) const;
LZespolona  operator * (LZespolona Skl2) const;
LZespolona  operator / (LZespolona Skl2) const;
LZespolona operator / (double re) const;
LZespolona operator = (double liczba) const;

bool operator == (LZespolona Skl2) const;
bool operator != (LZespolona Skl2) const;

double Modul(LZespolona lzesp) const;
LZespolona Sprzezenie(LZespolona lzesp) const;
void Wyswietl(LZespolona lzesp) const;
};





std::istream &operator >> (std::istream &strm, LZespolona &lzesp) const;
std::ostream &operator << (std::ostream &strm, LZespolona lzesp) const;

*/

LZespolona  LZespolona::operator + (LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;

  return Wynik;
}



LZespolona  LZespolona::operator - (LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;

  return Wynik;
}

LZespolona  LZespolona::operator * (LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->im * Skl2.re + this->re * Skl2.im;

  return Wynik;
}

LZespolona  LZespolona::operator / (LZespolona  Skl2) const
{
  LZespolona  Wynik;
  if(Skl2.re==0&&Skl2.im==0)                                      //wyjątek gdy dzielimy przez (0+0i); nan - not a number
  {
    Wynik.im=std::numeric_limits<double>::quiet_NaN();
    Wynik.re=std::numeric_limits<double>::quiet_NaN();
  }
  else
    Wynik=*this*Skl2.Sprzezenie()/(Skl2.Modul()*Skl2.Modul());

  return Wynik;
}

LZespolona LZespolona::operator / (double re) const
{
    LZespolona Wynik;

    Wynik.re = this->re/re;
    Wynik.im = this->im/re;

    return Wynik;
}

bool  LZespolona::operator == (LZespolona  Skl2) const
{
    if(this->re==Skl2.re&&this->im==Skl2.im)
        return true;
    else
        return false;
}

bool LZespolona::operator !=(LZespolona Skl2) const
{
    return !(*this==Skl2);
}

double LZespolona::Modul() const
{
    return sqrt(this->im*this->im+this->re*this->re);
}

std::istream &operator >> (std::istream &strm, LZespolona &lzesp)  //przyjmuje tylko liczby w formacie "(a+bi)"
{
    char znak;
    std::cin>>znak;
    if(znak!='(')
    {
        strm.setstate(std::ios::failbit);
        return strm;
    }

    strm >> lzesp.re;
    strm >> lzesp.im;

    std::cin>>znak;
    if(znak!='i')
    {
        strm.setstate(std::ios::failbit);
        return strm;
    }
    std::cin>>znak;
    if(znak!=')')
        strm.setstate(std::ios::failbit);
    return strm;
}

std::ostream &operator << (std::ostream &strm, LZespolona lzesp)
{
    strm<<'('<<lzesp.re<<std::showpos<<lzesp.im<<"i)"<<std::noshowpos;
    return strm;
}

LZespolona LZespolona::Sprzezenie() const
{
    LZespolona Wynik;

    Wynik.re=this->re;
    Wynik.im=-this->im;

    return Wynik;
}


LZespolona LZespolona::operator = (double liczba)
{
    this->re=liczba;
    this->im=0;
    return *this;
}

