#ifndef MACIERZ_H
#define MACIERZ_H
#include <iostream>
class macierz
{
public:
    int h, w;
    std::vector <double> tab;
    macierz pomnoz(int h2, int w2, std::vector <double>tab2);
    macierz(int h, int w, std::vector<double> &tab);
    macierz(const macierz& other);
    ~macierz();
};

#endif // MACIERZ_H
