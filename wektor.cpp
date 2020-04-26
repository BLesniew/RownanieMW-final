#include "wektor.h"

//KONSTRUKTORY

Wektor::Wektor()
{
    for(int i=0;i<ROZMIAR;i++)
    {
            this->tab[i]=0;
    }
}

Wektor::Wektor(double x, double y, double z)
{
    this->tab[0]=x;
    this->tab[1]=y;
    this->tab[2]=z;
}

Wektor::Wektor(double *tab)                            //dla tablic mniejszych niz ROZMIAR-elementowych segmentation fault
{
    for(int i=0;i<ROZMIAR;i++)
    {
        this->tab[i]=tab[i];
    }
}

//OPERATORY

const Wektor Wektor::operator+(const Wektor &W2) const
{
    Wektor tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
            tmp[i]=(this->tab[i]+W2[i]);
    }
    return tmp;
}

const Wektor Wektor::operator-(const Wektor &W2) const
{
    Wektor tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
            tmp[i]=(this->tab[i]-W2[i]);
    }
    return tmp;
}

double Wektor::operator*(const Wektor &W2) const
{
    return this->tab[0]*W2[0]+this->tab[1]*W2[1]+this->tab[2]*W2[2];
}

const Wektor Wektor::operator *(double li) const
{
    Wektor tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
            tmp[i]=(this->tab[i]*li);
    }
    return tmp;
}

bool Wektor::operator==(const Wektor &W2)const
{
    bool tmp = true;
    for(int i=0;i<ROZMIAR;i++)
    {
        if(abs(W2[i]-this->tab[i])>BLAD_PRZYROWNANIA);
            tmp = false;
    }
    return tmp;
}



bool Wektor::operator!=(const Wektor &W2)const
{
    return !(W2==*this);
}

//FUNKCJE DODATKOWE

double Wektor::dlugosc() const
{
    double tmp=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        tmp=tmp+this->tab[i]*this->tab[i];
    }
    return sqrt(tmp*tmp);
}

//GETTERY I SETTERY

double & Wektor::operator[](int index)
{
    if(index<0||index>=ROZMIAR)
    {
        std::cerr<<"Poza zakresem"<<std::endl;
        exit(2);
    }
    return this->tab[index];
}

const double & Wektor::operator[](int index) const
{
    return this->tab[index];
}

std::ostream &operator <<(std::ostream &strm, const Wektor &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm<<W[i]<<" ";
    }
    //strm<<W[0]<<" "<<W[1]<<" "<<W[2];
    return strm;
}

std::istream &operator >>(std::istream &strm, Wektor &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm>>W[i];
    }
    return strm;
}

const Wektor operator *(double l1,const Wektor &W2)
{
    Wektor tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        tmp[i]=W2[i]*l1;
    }
    return tmp;
}
