#include"UkladRownan.h"


int main()
{
    Wektor<double,3> W;
    double tab[] = {2,3,4};
    Wektor<double,3>U(tab);
    Wektor<double,3>V;
    V=U*3;
    cout<<V<<"\n";
    Wektor<LZespolona,5>ZW;
    ZW[0]=5;
    std::cout<<ZW[0];
    std::cout<<std::endl<<ZW.dlugosc()<<"\n";

    MacierzKw<double,3> MKw;
    std::cin>>MKw;
    std::cout<<MKw.wyznacznik()<<"\n\n";

    UkladRownan<double, 3> Ukl;
    Ukl.set_A(MKw);
    Ukl.set_b(U);
    V=Ukl.Oblicz();
    std::cout<<V;

    return 0;
}
