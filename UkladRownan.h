#ifndef UKLADROWNAN_H
#define UKLADROWNAN_H
#include "MacierzKw.h"

class UkladRownan{
    MacierzKw A;
    Wektor b;

public:
    UkladRownan():A(),b(){};
    UkladRownan(MacierzKw _A, Wektor _b):A(_A),b(_b){};
    const MacierzKw & get_A() const;
    const Wektor & get_b() const;
    void set_A(const MacierzKw & in);
    void set_b(const Wektor & in);

    Wektor Oblicz() const;

};

std::istream & operator >> (std::istream & strm, UkladRownan & ukl);
std::ostream & operator << (std::ostream & strm, const UkladRownan & ukl);


#endif
