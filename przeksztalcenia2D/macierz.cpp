#include "macierz.h"
#include <iostream>

macierz::macierz(int h, int w, double *tab)
{
    this->h = h;
    this->w = w;
    this->tab = new double[h*w];
    for(int i=0;i<h*w;++i)
    {
         this->tab[i] = tab[i];
    }
}
macierz::macierz(int h, int w)
{
    this->h = h;
    this->w = w;
    this->tab = new double[h*w];
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            if(i==j)//przekatna
            {
                this->tab[i*w+j] = 1;
            }
            else this->tab[i*w+j] = 0;
        }

    }
}
macierz::~macierz()
{
    delete[] tab;

}
macierz::macierz(const macierz& other)
{
    h = other.h;
    w = other.w;
    tab = new double[h * w];
    for (int i = 0; i < h * w; ++i)
    {
        tab[i] = other.tab[i];
    }
}
void macierz::addValue( double value, int position)
{
    tab[position] = value;
}
void macierz::wypisz()
{
    for(int i=0;i<h*w;++i)
    {
        std::cout<<tab[i]<<" ";
    }
}
macierz *macierz::pomnoz(int h2, int w2, macierz *tab2)
{
    macierz *wynik = new macierz(h,w2);
    // kolumny pierwszej == wiersze drugiej
    if(w != h2)
    {
        std::cout << "Nie można pomnożyć macierzy." << std::endl;
    }
    else
    {
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w2; j++)
            {
                double s = 0;
                for(int k = 0; k < h2; k++)
                {
                    s += tab[w*i + k] * tab2->tab[w2*k + j];
                }
                wynik->addValue(s,w2*i + j);
            }
        }
    }

    return wynik;
}

