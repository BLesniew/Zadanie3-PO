#include"wektor.h"


int main()
{
    Wektor<double,3> W;
    Wektor<LZespolona,2>ZW;
    ZW[0]=5;
    std::cout<<ZW[0];

    return 0;
}
