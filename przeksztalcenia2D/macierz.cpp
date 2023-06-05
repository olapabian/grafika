#include "macierz.h"
#include <iostream>

macierz::macierz(int h, int w, double **tab)
{
    this->h = h;
    this->w = w;
    this->tab = new double*[h];
    for(int i = 0; i < h; ++i)
    {
        this->tab[i] = new double[w];
        for(int j = 0; j < w; ++j)
        {
            this->tab[i][j] = tab[i][j];
        }
    }
}

macierz::~macierz()
{
    for(int i = 0; i < h; ++i)
    {
        delete[] tab[i];
    }
    delete[] tab;
}

macierz::macierz(const macierz& other)
{
    h = other.h;
    w = other.w;
    tab = new double*[h];
    for (int i = 0; i < h; ++i)
    {
        tab[i] = new double[w];
        for (int j = 0; j < w; ++j)
        {
            tab[i][j] = other.tab[i][j];
        }
    }
}

double** macierz::pomnoz(int h2, int w2, double **tab2)
{
    double **tab3 = new double*[h];
    for(int i = 0; i < h; ++i)
    {
        tab3[i] = new double[w2];
    }

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
                int s = 0;
                for(int k = 0; k < h2; k++)
                {
                    s += tab[i][k] * tab2[k][j];
                }
                tab3[i][j] = s;
            }
        }
    }

    return tab3;
}
double** macierz::dodaj(int h2, int w2, double **tab2)
{
    double **tab3 = new double*[h];
    for(int i = 0; i < h; ++i)
    {
        tab3[i] = new double[w];
    }


    if(h != h2 || w!=w2)
    {
        std::cout << "Nie można dodac macierzy." << std::endl;
    }
    else
    {
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                tab3[i][j] = tab[i][j]+tab2[i][j];
            }
        }
    }
    return tab3;
}
