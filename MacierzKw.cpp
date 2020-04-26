#include "MacierzKw.h"

//KONSTRUNKTORY

MacierzKw::MacierzKw()
{
    for(int i=0;i<ROZMIAR;i++)
    {
            this->tab[i]=Wektor();
    }
}

MacierzKw::MacierzKw(Wektor *w)                                 //dla tablic wektorów mniejszych niz ROZMIAR-elementowych segmentation fault
{
    for(int i=0;i<ROZMIAR;i++)
    {
            this->tab[i]=w[i];
    }
}

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

//OPERATORY

const Wektor MacierzKw::operator *(const Wektor &W)const
{
    Wektor tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        tmp[i]=this->tab[i][0]*W[0]+this->tab[i][1]*W[1]+this->tab[i][2]*W[2];
    }
    return tmp;
}

const MacierzKw MacierzKw::operator *(const MacierzKw &W)const
{
    MacierzKw tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0; j<ROZMIAR;j++)
        {
            tmp[i][j] = this->tab[j][0]*W[0][i]+this->tab[j][1]*W[1][i]+this->tab[j][2]*W[2][i];
        }
    }
    return tmp;
}

const MacierzKw MacierzKw::operator +(const MacierzKw &W)const
{
    MacierzKw tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[i][j]+W[i][j];
        }
    }
    return tmp;
}

const MacierzKw MacierzKw::operator -(const MacierzKw &W)const
{
    MacierzKw tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[i][j]-W[i][j];
        }
    }
    return tmp;
}

const MacierzKw MacierzKw::operator *(const double l)const
{
    MacierzKw tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[i][j]*l;
        }
    }
    return tmp;
}

bool MacierzKw::operator == (const MacierzKw &W2) const
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

bool MacierzKw::operator!=(const MacierzKw &W2) const
{
    return !(*this==W2);
}


//SETTERY I GETTERY

const Wektor & MacierzKw::operator[](int index) const
{
    return this->tab[index];
}

Wektor & MacierzKw::operator[] (int index)
{
    if(index<0||index>=ROZMIAR)
    {
        std::cerr<<"Poza zakresem"<<std::endl;
        exit(4);
    }
    return this->tab[index];
}

//POZOSTALE FUNKCJE

const MacierzKw MacierzKw::transponowane() const
{
    MacierzKw tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=this->tab[j][i];
        }
    }
    return tmp;
}

void zamien(double &a, double &b)
{
    double tmp=a;
    a=b;
    b=tmp;
}

void zamien(Wektor &w1, Wektor &w2)
{
    Wektor tmp=w1;
    w1=w2;
    w2=tmp;
}

void MacierzKw::transponuj()
{
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=i;j<ROZMIAR;j++)
        {
            if(i!=j)
            {
                zamien(this->tab[i][j],this->tab[j][i]);
            }

        }
    }
}

double MacierzKw::wyznacznik(Metoda met, int rozmiarMacierzy) const
{
    switch(met)
    {
        case Laplace:
        //DO ZROBIENIA REKURENCYJNIE KIEDY BEDZIEMY OBSLUGIWALI ROZNE ROZMIARY MACIERZY KWADRATOWYCH, TERAZ NIE MA SEMSU
        break;

        case Gauss:
        {                                                               //nawias sprawia ze zmienne ponizej istnieja tylko w tym przypadku
        MacierzKw tmp=*this;                                            //pomocnicza macierz do operacji na wierszach potrzebnych w metodzie Gaussa
        int iloscZamian=0;                                              //ilosc zmian wierszy sugerujaca jaki znak ma wyznacznik
        double iloraz;                                                  //iloraz komorki ktora chcemy wyzerowac przez te ktorej wyzerowac nie chcemy
        double wyzn=1;                                                  //1 poniewaz to element neutralny mnozenia, a pozniej bedziemy mnozyc przez wartosci na przekatnej
        for(int i=0;i<ROZMIAR;i++)
        {
            if(tmp[i][i]==0)                                          //gdyby pierwszy wiersz zaczynal sie od zera, to niemozliwy jest iloczyn np w2/w1 ,etc.
            {
                double nr_wiersza=i;                                  //zmienna istniejaca tylko jezeli pojawil sie powyzszy problem, pomocna przy szukaniu wiersza do zamiany
                double wartosc_pocz;                                  //zmienna przechowujaca wartosc komorki w kolumnie w ktorej szukamy komorek niezerowych ponizej badanego wiersza
                while(wartosc_pocz==0)                                //To przyrównanie do 0 będzie problematyczne (przez niedokladnosc double)
                {
                    if(nr_wiersza+1>=ROZMIAR)                         //gdy na przekatnej macierzy trojkatnej znajdzie sie zero wyznacznik jest rowny 0
                        return 0;
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
            wyzn*=tmp[i][i];                              //przeliczanie wartosci wyznacznika bez uwzglednienia ilosci zamian
        }
        if(iloscZamian%2==0)                           //uwzglednienie ilosci zamian
            return wyzn;
        else
            return -wyzn;
        }
        break;

        case Sarrus:
        if(rozmiarMacierzy>3)
        {
            std::cout<<"Metoda Sarrusa niemozliwa dla macierzy wiekszej niz 3x3, korzystam z metody Gaussa\n";
            wyznacznik(Gauss, rozmiarMacierzy);
        }
        else if(rozmiarMacierzy==0) //nigdy nie powinno sie zdarzyc
        {
            return 0;
        }
        else if(rozmiarMacierzy==1) //To też nigdy nie powinno sie zdarzyc
        {
            return this->tab[0][0];
        }
        else if(rozmiarMacierzy==2)
        {
            return (this->tab[0][0]*this->tab[1][1]-this->tab[1][0]*this->tab[0][1]);
        }
        else if(rozmiarMacierzy==3)
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

double MacierzKw::wyznacznik(Metoda met) const
{
    wyznacznik(met, ROZMIAR);
}

double MacierzKw::wyznacznik(int rozMacierzy) const
{
    wyznacznik(Sarrus, rozMacierzy);
}

double MacierzKw::wyznacznik() const
{
    wyznacznik(Sarrus, ROZMIAR);
}

double MacierzKw::dopelnienieAlgebraiczne(int i, int j) const   //tylko dla 3x3, wykorzystana metoda Sarrusa, nieeleganckie
{
    MacierzKw macierzTmp;
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
        return macierzTmp.wyznacznik(2);
    else
        return -macierzTmp.wyznacznik(2);
}

const MacierzKw MacierzKw::macierzDopelnien() const
{
    MacierzKw tmp;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            tmp[i][j]=dopelnienieAlgebraiczne(i,j);
        }
    }
    return tmp;
}

const MacierzKw MacierzKw::odwrotnosc() const
{
    MacierzKw tmp;
    tmp=this->macierzDopelnien();
    tmp.transponuj();
    tmp=tmp*(1/this->wyznacznik());
    return tmp;
}

void MacierzKw::odwroc()
{
    double tmp=1/this->wyznacznik();
    *this=this->macierzDopelnien();
    this->transponuj();
    *this=*this*(1/this->wyznacznik());
}

std::ostream & operator <<(std::ostream &strm, const MacierzKw &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm<<W[i]<<"\n";
    }
    return strm;
}
std::istream & operator >>(std::istream &strm, MacierzKw &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm>>W[i];
    }
    return strm;
}

