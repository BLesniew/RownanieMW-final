#ifndef WEKTOR_H
#define WEKTOR_H

#include<iostream>
#include<math.h>

#define ROZMIAR 3
#define BLAD_PRZYROWNANIA 0.0000001

class Wektor{
    double tab[ROZMIAR];

public:
    Wektor();
    Wektor(double x,double y,double z);
    Wektor(double *tab);

    //czy na pewno chcemy ??
    //const Wektor & operator += (const Wektor &W2);
    //const Wektor & operator -= (const Wektor &W2);
    //const Wektor & operator *= (double l1);


    //REZYGNACJA Z: const Wektor & operator + (const Wektor &W2) const; , ETC.
    //ZE ZNAKIEM & PROGRAM WYRZUCAŁ SEGMENTATION FAULT

    const Wektor operator + (const Wektor &W2) const;
    const Wektor operator - (const Wektor &W2) const;
    double operator * (const Wektor &W2) const;
    const Wektor operator *(double li) const;

    bool operator == (const Wektor &W2) const;
    bool operator != (const Wektor & W2) const;

    double dlugosc() const;

    const double & operator[] (int index) const;
    double & operator[] (int index);



};

std::ostream &operator <<(std::ostream &strm, const Wektor &W);
std::istream &operator >>(std::istream &strm, Wektor &W);
const Wektor operator *(double l1,const Wektor &W2);

#endif // WEKTOR_H
