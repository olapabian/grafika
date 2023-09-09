#ifndef SCIANA_H
#define SCIANA_H
#include <vector>
typedef struct point{
int x;
int y;
int z;
int X;//ten zrzutowany na d2
int Y;//ten zrzutowany na d2
} point;
typedef struct punkt{
    int x;
    int y;
} punkt;
typedef struct krawedz{
    point a;
    point b;
} krawedz;

class sciana
{
public:
    sciana();
    ~sciana();
    sciana(krawedz k0,krawedz k1, krawedz k2, krawedz k3, int d,point w0, point w1, point w2, point w3);
    std::vector <krawedz> Krawedzie;
    std::vector <point> Punkty;
    int d;
};

#endif // SCIANA_H
