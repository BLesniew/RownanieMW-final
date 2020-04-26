#ifndef MacierzKw_H
#define MacierzKw_H
#include "wektor.h"

enum Metoda{Laplace, Gauss, Sarrus};

//ZACHOWANIE KONWENCJI MATEMATYCNZEJ
//PRZYJMUJĘ KONWENCJĘ, ŻE Macierz[0][1] ZWRACAĆ BĘDZIE KOMÓRKĘ MACIERZY O ADRESIE 1,2 (a12)

class MacierzKw{
    Wektor tab[ROZMIAR];

public:
    MacierzKw();
    MacierzKw(Wektor *w);
    MacierzKw(double a11,double a12,double a13,
        double a21,double a22,double a23,
        double a31,double a32,double a33);
    MacierzKw(Wektor a1, Wektor a2, Wektor a3);

    const MacierzKw transponowane() const;
    void transponuj();
    const MacierzKw odwrotnosc() const;
    void odwroc();
    double wyznacznik(Metoda met, int rozmiarMacierzy) const;
    double wyznacznik(Metoda met) const;
    double wyznacznik(int rozmiarMacierzy) const;
    double wyznacznik() const;
    double dopelnienieAlgebraiczne(int i, int j) const;
    const MacierzKw macierzDopelnien() const;

    const Wektor operator *(const Wektor &W)const;
    const MacierzKw operator *(const MacierzKw &W)const;
    const MacierzKw operator +(const MacierzKw &W)const;
    const MacierzKw operator -(const MacierzKw &W)const;
    const MacierzKw operator *(const double l)const;

    bool operator == (const MacierzKw &W2) const;
    bool operator != (const MacierzKw &W2) const;

    const Wektor & operator[](int index) const;
    Wektor & operator[] (int index);


};

std::ostream & operator <<(std::ostream &strm, const MacierzKw &W);
std::istream & operator >>(std::istream &strm, MacierzKw &W);

const MacierzKw & operator *(double l1,const MacierzKw &W2);

void zamien(double &a, double &b);
void zamien(Wektor &w1, Wektor &w2);


#endif // MacierzKw_H
