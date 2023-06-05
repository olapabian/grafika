#ifndef MACIERZ_H
#define MACIERZ_H

class macierz
{
public:
    int h, w;
    double **tab;
    double** pomnoz(int h2, int w2, double **tab2);
    double** dodaj(int h2, int w2, double **tab2);
    macierz(int h, int w, double **tab);
    macierz(const macierz& other);
    ~macierz();
};

#endif // MACIERZ_H
