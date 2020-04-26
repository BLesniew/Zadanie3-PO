#include "wektor.h"

//KONSTRUKTORY
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor()
{
    for(int i=0;i<ROZMIAR;i++)
    {
            this->tab[i]=0;
    }
}
/*
Wektor::Wektor(double x, double y, double z)
{
    this->tab[0]=x;
    this->tab[1]=y;
    this->tab[2]=z;
}
*/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor(TYP *tab)                            //dla tablic mniejszych niz ROZMIAR-elementowych segmentation fault
{
    for(int i=0;i<ROZMIAR;i++)
    {
        this->tab[i]=tab[i];
    }
}

//OPERATORY

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator+(const Wektor<TYP,ROZMIAR> &W2) const
{
    Wektor<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
            tmp[i]=(this->tab[i]+W2[i]);
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator-(const Wektor<TYP,ROZMIAR> &W2) const
{
    Wektor<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
            tmp[i]=(this->tab[i]-W2[i]);
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator*(const Wektor<TYP,ROZMIAR> &W2) const
{
    TYP tmp;
    tmp = 0;
    for(int i=0;i<ROZMIAR;i++)
    {
        tmp=tmp+this->tab[i]*W2[i];
    }
    return tmp;
}

/*template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator *(TYP li) const;
{
    Wektor<TYP,ROZMIAR> tmp = 0;
    for(int i=0;i<ROZMIAR;i++)
    {
            tmp[i]=(this->tab[i]*li);
    }
    return tmp;
}*/

/*template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator==(const Wektor<TYP,ROZMIAR> &W2)const
{
    bool tmp = true;
    for(int i=0;i<ROZMIAR;i++)
    {
        if(abs(W2[i]-this->tab[i])>BLAD_PRZYROWNANIA);
            tmp = false;
    }
    return tmp;
}


template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator!=(const Wektor<TYP,ROZMIAR> &W2)const
{
    return !(W2==*this);
}*/

//FUNKCJE DODATKOWE

/*template<class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::dlugosc() const
{
    TYP tmp;
    tmp=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        tmp=tmp+this->tab[i]*this->tab[i];
    }
    return sqrt(tmp*tmp);
}*/                                                            //DLUGOSC NIE DZIALA DLA TYP = LZespolona

//GETTERY I SETTERY

template<class TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator[](int index)
{
    if(index<0||index>=ROZMIAR)
    {
        std::cerr<<"Poza zakresem"<<std::endl;
        exit(2);
    }
    return this->tab[index];
}

template<class TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator[](int index) const
{
    return this->tab[index];
}

template<class TYP,int ROZMIAR>
std::ostream &operator <<(std::ostream &strm, const Wektor<TYP,ROZMIAR> &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm<<W[i]<<" ";
    }
    //strm<<W[0]<<" "<<W[1]<<" "<<W[2];
    return strm;
}

template<class TYP,int ROZMIAR>
std::istream &operator >>(std::istream &strm, Wektor<TYP,ROZMIAR> &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm>>W[i];
    }
    return strm;
}

template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> operator *(double l1,const Wektor<TYP,ROZMIAR> &W2)
{
    Wektor<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        tmp[i]=W2[i]*l1;
    }
    return tmp;
}


/*template<>
double Wektor<LZespolona,5>::dlugosc() const
{
    return sqrt(*this * *this.sprzezenie());
}*/
