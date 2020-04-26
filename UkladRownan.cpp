#include "UkladRownan.h"

/*
class UkladRownan{
    MacierzKw A;
    Wektor b;

public:
    UkladRownan();
    UkladRownan(MacierzKw _A, Wektor _b):A(_A),b(_b){};
    const MacierzKw & get_A() const;
    const Wektor & get_b() const;
    void set_A(const MacierzKw & in);
    void set_B(const Wektor & in);

    Wektor Oblicz() const;

};

std::istream & operator >> (std::istream & strm, UkladRownan ukl);
std::ostream & operator << (std::ostream & strm, const UkladRownan ukl);
*/

const MacierzKw & UkladRownan::get_A() const
{
    return this->A;
}

const Wektor & UkladRownan::get_b() const
{
    return this->b;
}

void UkladRownan::set_A(const MacierzKw & in)
{
    this->A = in;
}

void UkladRownan::set_b(const Wektor & in)
{
    this->b = in;
}

Wektor UkladRownan::Oblicz() const
{
    Wektor tmp;
    tmp=this->A.odwrotnosc()* b;
    return tmp;
}

std::istream & operator >> (std::istream & strm, UkladRownan & ukl)
{
    MacierzKw tmp;
    Wektor tmp2;
    strm>>tmp;
    ukl.set_A(tmp.transponowane());
    strm>>tmp2;
    ukl.set_b(tmp2);
    return strm;
}

std::ostream & operator << (std::ostream & strm, const UkladRownan & ukl)
{
    strm<<ukl.get_A()<<"\n"<<ukl.get_b();
    return strm;
}



