#include "MacierzKw.h"




//KONSTRUNKTORY
template<class TYP, int ROZMIAR>
MacierzKw<TYP,ROZMIAR>::MacierzKw()
{
    for(int i=0;i<ROZMIAR;i++)
    {
            this->tab[i]=Wektor<TYP,ROZMIAR>();
    }
}

template<class TYP, int ROZMIAR>
MacierzKw<TYP,ROZMIAR>::MacierzKw(Wektor<TYP,ROZMIAR> *w)                                 //dla tablic wektorów mniejszych niz ROZMIAR-elementowych segmentation fault
{
    for(int i=0;i<ROZMIAR;i++)
    {
            this->tab[i]=w[i];
    }
}

/*
MacierzKw::MacierzKw(double a11,double a12,double a13,
        double a21,double a22,double a23,
        double a31,double a32,double a33)
{
    this->tab[0][0]=a11;
    this->tab[0][1]=a12;
    this->tab[0][2]=a13;

    this->tab[1][0]=a21;
    this->tab[1][1]=a22;
    this->tab[1][2]=a23;

    this->tab[2][0]=a31;
    this->tab[2][1]=a32;
    this->tab[2][2]=a33;
}

MacierzKw::MacierzKw(Wektor a1, Wektor a2, Wektor a3)
{
    this->tab[0]=a1;
    this->tab[1]=a2;
    this->tab[2]=a3;
}

*/

//OPERATORY

template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator *(const Wektor<TYP,ROZMIAR> &W)const
{
    Wektor<TYP,ROZMIAR> tmp;
    TYP tmp2;
    tmp2=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp2=tmp2+this->tab[i][j]*W[j];
        }
        tmp[i]=tmp2;
        tmp2=0;
        //tmp[i]=this->tab[i][0]*W[0]+this->tab[i][1]*W[1]+this->tab[i][2]*W[2];
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator *(const MacierzKw<TYP,ROZMIAR> &W)const
{
    MacierzKw<TYP,ROZMIAR> tmp;
    TYP tmp2;
    tmp2 = 0;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0; j<ROZMIAR;j++)
        {
            for(int k=0;k<ROZMIAR;k++)
            {
                tmp2=tmp2+this->tab[j][k]*W[k][i];
            }
            tmp[i][j] = tmp2;
            //tmp[i][j] = this->tab[j][0]*W[0][i]+this->tab[j][1]*W[1][i]+this->tab[j][2]*W[2][i];
        }
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator +(const MacierzKw<TYP,ROZMIAR> &W)const
{
    MacierzKw<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[i][j]+W[i][j];
        }
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator -(const MacierzKw<TYP,ROZMIAR> &W)const
{
    MacierzKw<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[i][j]-W[i][j];
        }
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::operator *(const TYP l)const
{
    MacierzKw<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[i][j]*l;
        }
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
bool MacierzKw<TYP,ROZMIAR>::operator == (const MacierzKw<TYP,ROZMIAR> &W2) const
{
    bool tmp = true;
    for(int i=0;i<ROZMIAR;i++)
    {
        if(this->tab[i]!=W2[i])
        {
            tmp=false;
        }

    }
    return tmp;
}

template<class TYP, int ROZMIAR>
bool MacierzKw<TYP,ROZMIAR>::operator!=(const MacierzKw<TYP,ROZMIAR> &W2) const
{
    return !(*this==W2);
}


//SETTERY I GETTERY

template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> & MacierzKw<TYP,ROZMIAR>::operator[](int index) const
{
    return this->tab[index];
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & MacierzKw<TYP,ROZMIAR>::operator[] (int index)
{
    if(index<0||index>=ROZMIAR)
    {
        std::cerr<<"Poza zakresem"<<std::endl;
        exit(4);
    }
    return this->tab[index];
}

//POZOSTALE FUNKCJE

template<class TYP, int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::transponowane() const
{
    MacierzKw<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[j][i];
        }
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
void zamien(Wektor<TYP,ROZMIAR> &w1, Wektor<TYP,ROZMIAR> &w2)
{
    Wektor<TYP,ROZMIAR> tmp=w1;
    w1=w2;
    w2=tmp;
}

template<class TYP, int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::transponuj()
{
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=i;j<ROZMIAR;j++)
        {
            if(i!=j)
            {
                std::swap(this->tab[i][j],this->tab[j][i]);
            }

        }
    }
}

template<class TYP, int ROZMIAR>
TYP MacierzKw<TYP,ROZMIAR>::wyznacznik(Metoda met) const
{
    switch(met)
    {
        case Laplace:
        //DO ZROBIENIA REKURENCYJNIE KIEDY BEDZIEMY OBSLUGIWALI ROZNE ROZMIARY MACIERZY KWADRATOWYCH, TERAZ NIE MA SEMSU
        break;

        case Gauss:
        {                                                               //nawias sprawia ze zmienne ponizej istnieja tylko w tym przypadku
        MacierzKw<TYP,ROZMIAR> tmp=*this;                                            //pomocnicza macierz do operacji na wierszach potrzebnych w metodzie Gaussa
        int iloscZamian=0;                                              //ilosc zmian wierszy sugerujaca jaki znak ma wyznacznik
        TYP iloraz;                                                  //iloraz komorki ktora chcemy wyzerowac przez te ktorej wyzerowac nie chcemy
        TYP wyzn;
        wyzn=1;                                                  //1 poniewaz to element neutralny mnozenia, a pozniej bedziemy mnozyc przez wartosci na przekatnej
        for(int i=0;i<ROZMIAR;i++)
        {
            if(tmp[i][i]==0)                                          //gdyby pierwszy wiersz zaczynal sie od zera, to niemozliwy jest iloczyn np w2/w1 ,etc.
            {
                double nr_wiersza=i;                                  //zmienna istniejaca tylko jezeli pojawil sie powyzszy problem, pomocna przy szukaniu wiersza do zamiany
                TYP wartosc_pocz;                                  //zmienna przechowujaca wartosc komorki w kolumnie w ktorej szukamy komorek niezerowych ponizej badanego wiersza
                while(wartosc_pocz==0)                                //To przyrównanie do 0 będzie problematyczne (przez niedokladnosc double)
                {
                    if(nr_wiersza+1>=ROZMIAR)                         //gdy na przekatnej macierzy trojkatnej znajdzie sie zero wyznacznik jest rowny 0
                        return wyzn*0;                                //nieeleganckie
                    wartosc_pocz=tmp[++nr_wiersza][i];
                }
                zamien(tmp[i],tmp[nr_wiersza]);
                iloscZamian++;
            }
            for(int j=i+1;j<ROZMIAR;j++)
            {
                iloraz=tmp[j][i]/tmp[i][i];
                tmp[j]=tmp[j]-tmp[i]*iloraz;
            }
        }
        for(int i=0;i<ROZMIAR;i++)
        {
            wyzn=wyzn*tmp[i][i];                              //przeliczanie wartosci wyznacznika bez uwzglednienia ilosci zamian
        }
        if(iloscZamian%2==0)                           //uwzglednienie ilosci zamian
            return wyzn;
        else
            return wyzn*(-1);
        }
        break;

        case Sarrus:
        if(ROZMIAR>3)
        {
            std::cout<<"Metoda Sarrusa niemozliwa dla macierzy wiekszej niz 3x3, korzystam z metody Gaussa\n";
            wyznacznik(Gauss);
        }
        else if(ROZMIAR==0) //nigdy nie powinno sie zdarzyc
        {
            TYP a;                //nieeleganckie obejscie dla LZesolona
            a = 0;
            return a;
        }
        else if(ROZMIAR==1) //To też nigdy nie powinno sie zdarzyc
        {
            return this->tab[0][0];
        }
        else if(ROZMIAR==2)
        {
            return (this->tab[0][0]*this->tab[1][1]-this->tab[1][0]*this->tab[0][1]);
        }
        else if(ROZMIAR==3)
        {
            return (this->tab[0][0]*this->tab[1][1]*this->tab[2][2]+
                this->tab[0][1]*this->tab[1][2]*this->tab[2][0]+
                this->tab[0][2]*this->tab[1][0]*this->tab[2][1]-
                this->tab[0][2]*this->tab[1][1]*this->tab[2][0]-
                this->tab[1][2]*this->tab[2][1]*this->tab[0][0]-
                this->tab[2][2]*this->tab[0][1]*this->tab[1][0]);
        }
        else
        {
            std::cerr<<"Rozmiar macierzy ujemny\n";
            exit(5);
        }
        break;


    }
}

template<class TYP, int ROZMIAR>
TYP MacierzKw<TYP,ROZMIAR>::wyznacznik() const
{
    return wyznacznik(Sarrus);
}

template<class TYP, int ROZMIAR>
TYP MacierzKw<TYP,ROZMIAR>::dopelnienieAlgebraiczne(int i, int j) const
{
    MacierzKw<TYP,ROZMIAR-1> macierzTmp;
    short napotkano_i=0,napotkano_j=0;
    for(int k=0;k<ROZMIAR-1;k++)
    {
        if(k==i)
            napotkano_i=1;
        for(int l=0;l<ROZMIAR-1;l++)
        {
            if(l==j)
                napotkano_j=1;
            macierzTmp[l][k]=this->tab[k+napotkano_i][l+napotkano_j];
        }
        napotkano_j=0;
    }
    //std::cout<<"\n\n\n"<<macierzTmp<<"\n\n\n";
    if((i+j)%2==0)
        return macierzTmp.wyznacznik();
    else
        return macierzTmp.wyznacznik()*(-1);
}

template<class TYP, int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::macierzDopelnien() const
{
    MacierzKw<TYP,ROZMIAR> tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=dopelnienieAlgebraiczne(i,j);
        }
    }
    return tmp;
}

template<class TYP, int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> MacierzKw<TYP,ROZMIAR>::odwrotnosc() const
{
    MacierzKw<TYP,ROZMIAR> tmp;
    tmp=this->macierzDopelnien();
    tmp.transponuj();
    tmp=tmp*(1/this->wyznacznik());
    return tmp;
}

template<class TYP, int ROZMIAR>
void MacierzKw<TYP,ROZMIAR>::odwroc()
{
    TYP tmp=1/this->wyznacznik();
    *this=this->macierzDopelnien();
    this->transponuj();
    *this=*this*(1/this->wyznacznik());
}

template<class TYP, int ROZMIAR>
std::ostream & operator <<(std::ostream &strm, const MacierzKw<TYP,ROZMIAR> &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm<<W[i]<<"\n";
    }
    return strm;
}
template<class TYP, int ROZMIAR>
std::istream & operator >>(std::istream &strm, MacierzKw<TYP,ROZMIAR> &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm>>W[i];
    }
    return strm;
}

