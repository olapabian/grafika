#ifndef MACIERZ_H
#define MACIERZ_H
#include <iostream>
class macierz
{
public:
    int h, w;
    double *tab;
    macierz *pomnoz(int h2, int w2, macierz *tab2);
    void addValue(double value, int position);
    void wypisz();
    macierz(int h, int w);
    macierz(int h, int w, double *tab2);
    macierz(const macierz& other);
    ~macierz();
};

#endif // MACIERZ_H
