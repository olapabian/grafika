#include "mainwindow.h"
#include "macierz.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    double tab[6] = {2,1,3,-1,2,4} , tab2[6] ={1,3,2,-2,-1,4} ;

//    macierz *m1 = new macierz(2, 3, tab);
//    macierz *m2 = new macierz(3, 2, tab2);
//    macierz m3 = m1->pomnoz(3,2,tab2);
//    for(int i=0;i<4;++i)
//    {
//        std::cout<<m3.tab[i]<<std::endl;
//    }
    //powinno byc 1 16 -1 9


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
