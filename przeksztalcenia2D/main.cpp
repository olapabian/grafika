#include "mainwindow.h"
#include "macierz.h"
#include "macierz.cpp"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
//    int **tab = new int*[3];
//    for(int i = 0; i < 3; ++i)
//    {
//        tab[i] = new int[2];
//    }
//    tab[0][0] = 1;
//    tab[0][1] = 3;
//    tab[1][0] = 2;
//    tab[1][1] = -2;
//    tab[2][0] = -1;
//    tab[2][1] = 4;

//    int **tab2 = new int*[2];
//    for(int i = 0; i < 2; ++i)
//    {
//        tab2[i] = new int[3];
//    }

//    tab2[0][0] = 2;
//    tab2[0][1] = 1;
//    tab2[0][2] = 3;
//    tab2[1][0] = -1;
//    tab2[1][1] = 2;
//    tab2[1][2] = 4;

//    macierz *m1 = new macierz(3, 2, tab);
//    macierz *m2 = new macierz(2, 3, tab2);
//    int **tab3=m1->pomnoz(2,3,tab2);
//    for(int i=0;i<3;++i)
//    {
//        for(int j=0;j<3;++j)
//        {
//            std::cout<<tab3[i][j]<<std::endl;
//        }
//        std::cout<<std::endl;
//    }
//    //zwalanianie pamieci
//    for(int i = 0; i < 3; ++i)
//    {
//        delete[] tab[i];
//    }
//    delete[] tab;

//    for(int i = 0; i < 2; ++i)
//    {
//        delete[] tab2[i];
//    }
//    delete[] tab2;
//    delete m1;
//    delete m2;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
