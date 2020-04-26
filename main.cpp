#include "UkladRownan.h"


int main()
{
    UkladRownan Ukl;
    Wektor x,blad;
    std::cin>>Ukl;
    x = Ukl.Oblicz();
    std::cout<<"Wynik:"<<x<<"\n\n";
    blad = Ukl.get_A()*x - Ukl.get_b();
    std::cout<<"Wektor bledu:"<<blad<<"\n\nBlad:"<<blad.dlugosc()<<"\n";

    return 0;
}
