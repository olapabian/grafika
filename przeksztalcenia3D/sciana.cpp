#include "sciana.h"
#include  <algorithm>
#include <cmath>
sciana::sciana()
{

}
sciana::~sciana()
{
    Krawedzie.clear();
    Punkty.clear();
}
sciana::sciana(krawedz k0,krawedz k1, krawedz k2, krawedz k3, int d,point w0, point w1, point w2, point w3)
{
    this->d=d;
    Krawedzie.push_back(k0);
    Krawedzie.push_back(k1);
    Krawedzie.push_back(k2);
    Krawedzie.push_back(k3);
    int minX, minY, minZ;
    int maxX, maxY, maxZ;
    Punkty.push_back(w0);
    Punkty.push_back(w1);
    Punkty.push_back(w2);
    Punkty.push_back(w3);

}

