#include "macierz.h"
#include <iostream>

macierz::macierz(int h, int w, std::vector<double> &tab)
{
    this->h = h;
    this->w = w;
    for(int i=0;i<h*w;++i)
    {
        this->tab.push_back(tab[i]);
    }
}
macierz::~macierz()
{
    tab.clear();
}

macierz macierz::pomnoz(int h2, int w2, std::vector <double>tab2)
{
    std::vector <double> Vwynik;
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
                    s += tab[w*i + k] * tab2[w2*k + j];
                }
                Vwynik.push_back(s);
            }
        }
    }
    macierz wynik = macierz(h,w2,Vwynik);
    return wynik;
}

