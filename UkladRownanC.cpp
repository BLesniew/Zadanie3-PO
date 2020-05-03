#include "UkladRownan.cpp"



template class UkladRownan<double,3>;
template std::istream & operator >> (std::istream & strm,UkladRownan<double,3> &W);
template std::ostream & operator << (std::ostream & strm,const UkladRownan<double,3> &W);
