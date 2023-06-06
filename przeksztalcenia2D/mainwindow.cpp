#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <cmath>
#include "macierz.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      img(new QImage("C:/Users/User/Desktop/grafika/przeksztalcenia2D/pszczola.png")),
      img2(new QImage(*img))
{
    ui->setupUi(this);
    stworzPrzesuniecie();//inicjalizuje tablice zeby byly macierzami na przekatnej 1 ktore nic nie zmianaja po przemnozeniu
    stworzRotacje();
    stworzSkalowanie();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete img;
    delete img2;

    //delokacja przesuneicie
    for (int i = 0; i < 3; ++i)
    {
        delete[] przesuniecie[i];
    }
    delete[] przesuniecie;

    //delokacja rotacja
    for (int i = 0; i < 3; ++i)
    {
        delete[] rotacja[i];
    }
    delete[] rotacja;

    //delokacja skalowanie
    for (int i = 0; i < 3; ++i)
    {
        delete[] skalowanie[i];
    }
    delete[] skalowanie;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0, 0, *img2);
}

void MainWindow::stworzPrzesuniecie()
{
    przesuniecie = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        przesuniecie[i] = new double[3];
    }
    przesuniecie[0][0] = 1;
    przesuniecie[0][1] = 0;
    przesuniecie[0][2] = 0;
    przesuniecie[1][0] = 0;
    przesuniecie[1][1] = 1;
    przesuniecie[1][2] = 0;
    przesuniecie[2][0] = 0;
    przesuniecie[2][1] = 0;
    przesuniecie[2][2] = 1;
}
void MainWindow::edytujPrzesuniecie(int x,int y/*wartosc wartosc skalownie po x i y nie sa to punkt pol*/)
{
    przesuniecie[0][0] = 1;
    przesuniecie[0][1] = 0;
    przesuniecie[0][2] = x;
    przesuniecie[1][0] = 0;
    przesuniecie[1][1] = 1;
    przesuniecie[1][2] = y;
    przesuniecie[2][0] = 0;
    przesuniecie[2][1] = 0;
    przesuniecie[2][2] = 1;
}
void MainWindow::stworzRotacje()
{
    rotacja = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        rotacja[i] = new double[3];
    }
    rotacja[0][0] = 1;
    rotacja[0][1] = 0;
    rotacja[0][2] = 0;
    rotacja[1][0] = 0;
    rotacja[1][1] = 1;
    rotacja[1][2] = 0;
    rotacja[2][0] = 0;
    rotacja[2][1] = 0;
    rotacja[2][2] = 1;
}
void MainWindow::edytujRotacje(double wartosc) //to to samo tylko bez new i wogule
{
    //    rotacja[0][0] = (x-szer/2)*cos(w);
    //    rotacja[0][1] = (y-wys/2)*(-sin(w));
    //    rotacja[0][2] = 0;
    //    rotacja[1][0] = (x-szer/2)*sin(w);
    //    rotacja[1][1] = (y-wys/2)*cos(w);
    //    rotacja[1][2] = 0;
    //    rotacja[2][0] = 0;
    //    rotacja[2][1] = 0;
    //    rotacja[2][2] = 1;
    rotacja[0][0] = cos(wartosc);
    rotacja[0][1] = (-sin(wartosc));
    rotacja[0][2] = 0;
    rotacja[1][0] = sin(wartosc);
    rotacja[1][1] = cos(wartosc);
    rotacja[1][2] = 0;
    rotacja[2][0] = 0;
    rotacja[2][1] = 0;
    rotacja[2][2] = 1;
}
void MainWindow::stworzSkalowanie()
{
    skalowanie = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        skalowanie[i] = new double[3];
    }
    skalowanie[0][0] = 1;
    skalowanie[0][1] = 0;
    skalowanie[0][2] = 0;
    skalowanie[1][0] = 0;
    skalowanie[1][1] = 1;
    skalowanie[1][2] = 0;
    skalowanie[2][0] = 0;
    skalowanie[2][1] = 0;
    skalowanie[2][2] = 1;
}
void MainWindow::edytujSkalowanie(int x,int y/*wartosc skalownie po x i y nie sa to punkt pol*/)
{
    skalowanie[0][0] = x;
    skalowanie[0][1] = 0;
    skalowanie[0][2] = 0;
    skalowanie[1][0] = 0;
    skalowanie[1][1] = y;
    skalowanie[1][2] = 0;
    skalowanie[2][0] = 0;
    skalowanie[2][1] = 0;
    skalowanie[2][2] = 1;
}
//, int operacja/*0-dodawanie 1-mnozenie*/,int przeksztalcenie/*0-przesuniecie w pozniomie 1- w pionie 2-rotacja*/
void MainWindow::stworzMacierze() //zwracja tablice 3x1 z przesunieciami po x i y tworzenie macierzy z wartosciami juz
{   
    if (przeksztalcenie == 0) //przesuniecie poziom
    {
        edytujPrzesuniecie(wartosc,przesuniecieY);//bo po x
        przesuniecieX=wartosc;
    }
    else if(przeksztalcenie==1)//przesuniecie pion po y
    {
        edytujPrzesuniecie(przesuniecieX,wartosc);//bo po y
        przesuniecieY=wartosc;
    }
    else if(przeksztalcenie==2) //rotacja
    {
        edytujRotacje((double)wartosc);
    }
    else if(przeksztalcenie==3)//skalowanie poziom
    {
        edytujSkalowanie(wartosc,skalowanieY);
        skalowanieX=wartosc;
    }
    else if(przeksztalcenie==4)//skalowanie pion
    {
        edytujSkalowanie(skalowanieX,wartosc);
        skalowanieY=wartosc;
    }
}
double** MainWindow::nowePunkty(int x,int y)
{
    //talica na wspolzedne na poczatku
    double** tab = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        tab[i] = new double[1];
    }
    tab[0][0] = x;
    tab[1][0] = y;
    tab[2][0] = 1;
    //tablica wynik 3x1
    double** wynik = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        wynik[i] = new double[1];
    }


    //tablica pomocnicza do mnozenia 3x3
    double** pom = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        pom[i] = new double[3];
    }

    //tablica pomocnicza do mnozenia 3x3
    double** pom2 = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        pom2[i] = new double[3];
    }


    //tworzenie macierzy skalowanie
    macierz* m1 = new macierz(3, 3, skalowanie);

    //mnozenie skalowanie*rotacja wychodzi tablica 3x3
    pom=m1->pomnoz(3,3,rotacja);

//    for(int i=0;i<3;++i)
//    {
//        for(int j=0;j<3;++j)
//        {
//            std::cout<<pom[i][j]<<" ";
//        }
//        std::cout<<std::endl;
//    }
    //tworzenie macierzy pom
    macierz *m2 = new macierz(3,3,pom);


    //mnoznie pom razy przesuniecie i wychodzi 3x3
    pom2=m2->pomnoz(3,3,przesuniecie);


    //tworzenie macierzy pom2 kolejny raz
    macierz *m3 = new macierz(3,3,pom2);


    //mnoznie pom razy macierz 3x1 z wspolrzednymi i wychodzi 3x1 juz wynik
    wynik=m3->pomnoz(3,1,tab);
    //delokacja tab-------------------------------------
    for (int i = 0; i < 3; ++i)
    {
        delete[] tab[i];
    }
    delete[] tab;


    //delokacja pom i pom2-------------------------------------
    for (int i = 0; i < 3; ++i)
    {
        delete[] pom[i];
        delete[] pom2[i];
    }
    delete[] pom;
    delete[] pom2;


    //macierze
    delete m1;
    delete m2;
    delete m3;


    return wynik;
}
void MainWindow::przesun()
{
    unsigned char* ptr = img->bits();
    unsigned char* ptr2 = img2->bits();
    double** tab;

    for (int y = 0; y < wys; ++y)
    {
        for (int x = 0; x < szer; ++x)
        {
            tab = nowePunkty(x, y);
            if (tab[0][0] > 1 && tab[0][0] < szer-1 && tab[1][0] > 1 && tab[1][0] < wys-1)
            {
                int yP=int(tab[1][0]);
                int xP=int(tab[0][0]);
                ptr2[szer * 4 * yP + 4 * xP] = ptr[szer * 4 * y + 4 * x];
                ptr2[szer * 4 * yP + 4 * xP + 1] = ptr[szer * 4 * y + 4 * x + 1];
                ptr2[szer * 4 * yP + 4 * xP + 2] = ptr[szer * 4 * y + 4 * x + 2];
            }
        }
    }
    delete[] tab[0];
    delete[] tab[1];
    delete[] tab[2];
    delete[] tab;
    repaint();
}


void MainWindow::on_LewoPrawo_valueChanged(int value)
{
    //0-544 272 - pozycja 0
    wartosc=value-272;//o tyle w prawo jak na minusie to w lewo
    przeksztalcenie=0;
    stworzMacierze();
    przesun();
    //std::cout<<value<<std::endl;
}


void MainWindow::on_GoraDol_valueChanged(int value)
{
    //wys=676     338 - pozycja 0;
    wartosc=value - 338;
    przeksztalcenie=1;
    stworzMacierze();
    przesun();
}


void MainWindow::on_Rotacja_valueChanged(int value)
{
    wartosc=value;
    przeksztalcenie=2; //rotacja
    stworzMacierze();
    przesun();
}


void MainWindow::on_Skalownie_valueChanged(int value)
{
    wartosc=(value)/100.0;
    przeksztalcenie=3;
    stworzMacierze();
    przesun();
}

void MainWindow::on_Skalowanie2_valueChanged(int value)
{
    wartosc=(value)/100.0;
    przeksztalcenie=4;
    stworzMacierze();
    przesun();
}


void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{
    slider=6;
    wartosc=value;
}


void MainWindow::on_horizontalSlider_7_valueChanged(int value)
{
    slider=7;
    wartosc=value;
}


