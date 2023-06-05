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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete img;
    delete img2;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0, 0, *img2);
}
void MainWindow::kopiuj()
{
    unsigned char* ptr = img->bits();
    unsigned char* ptr2 = img2->bits();

    for (int y = 0; y < wys; ++y)
    {
        for (int x = 0; x < szer; ++x)
        {
            ptr[szer * 4 * y + 4 * x] = ptr2[szer * 4 * y + 4 * x];
            ptr[szer * 4 * y + 4 * x + 1] = ptr2[szer * 4 * y + 4 * x + 1];
            ptr[szer * 4 * y + 4 * x + 2] = ptr2[szer * 4 * y + 4 * x + 2];
        }
    }
}
//, int operacja/*0-dodawanie 1-mnozenie*/,int przeksztalcenie/*0-przesuniecie w pozniomie 1- w pionie 2-rotacja*/
double** MainWindow::stworzMacierze(int x, int y)
{

    macierz* m2;
    //talica na wspolzedne
    double** tab = new double*[3];
    for (int i = 0; i < 3; ++i)
    {
        tab[i] = new double[1];
    }
    tab[0][0] = x;
    tab[1][0] = y;
    tab[2][0] = 1;


    if (przeksztalcenie == 0) //przesuniecie poziom
    {
        przesuniecie[0][0] = 1;
        przesuniecie[0][1] = 0;
        przesuniecie[0][2] = wartosc;
        przesuniecie[1][0] = 0;
        przesuniecie[1][1] = 1;
        if(pierwszaOperacja)
        {
            przesuniecie[1][2] = 0; //jak nie jest pierwsza operacja to nie modyfikuje nie modyfikuje
            pierwszaOperacja=false;
        }
        przesuniecie[2][0] = 0;
        przesuniecie[2][1] = 0;
        przesuniecie[2][2] = 1;
    }
    else if(przeksztalcenie==1)//przesuniecie pion po y
    {
        przesuniecie[0][0] =1;
        przesuniecie[0][1] = 0;
        if(pierwszaOperacja)
        {
            przesuniecie[0][2] = 0; //jak nie jest pierwsza operacja to nie modyfikuje nie modyfikuje
            pierwszaOperacja=false;
        }
    }
    else if(przeksztalcenie==2) //rotacja
    {
        double w=wartosc;
//        tab2[0][0] = cos(w);
//        tab2[0][1] = -sin(w);
//        tab2[1][0] = sin(w);
//        tab2[1][1] = cos(w);
        tab2[0][0] = (x-szer/2)*cos(w);
        tab2[0][1] = (y-wys/2)*(-sin(w));
        tab2[1][0] = (x-szer/2)*sin(w);
        tab2[1][1] = (y-wys/2)*cos(w);
    }
    macierz* m1 = new macierz(2, 1, tab);

    if(operacja==0)
    {
        m2 = new macierz(2, 1, tab2);
    }
    else m2 = new macierz(2, 2, tab2);

    double** tab3;
    if (operacja == 0)
    {
        tab3 = m1->dodaj(2, 1, tab2);
    }
    else
    {
        tab3 = m2->pomnoz(2, 1, tab);
    }


    //delokacja-------------------------------------
    for (int i = 0; i < 2; ++i)
    {
        delete[] tab[i];
        if(operacja==0)
        {
            delete[] tab2[i];
        }
    }
    delete[] tab;
    delete[] tab2;

    delete m1;
    delete m2;

    return tab3;
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
            tab = stworzMacierze(x, y);
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
    delete[] tab;
    repaint();
}


void MainWindow::on_LewoPrawo_valueChanged(int value)
{
    //0-544 272 - pozycja 0
    wartosc=value-272;//o tyle w prawo jak na minusie to w lewo
    operacja=0;
    przeksztalcenie=0;
    przesun();
    //std::cout<<value<<std::endl;
}


void MainWindow::on_GoraDol_valueChanged(int value)
{
    //wys=676     338 - pozycja 0;
    wartosc=value - 338;
    operacja=0;
    przeksztalcenie=1;
    przesun();
}


void MainWindow::on_Rotacja_valueChanged(int value)
{
    wartosc=value;
    operacja=1;//mnozenie
    przeksztalcenie=2; //rotacja
    przesun();

}


void MainWindow::on_Skalownie_valueChanged(int value)
{

    wartosc=value;
}

void MainWindow::on_Skalowanie2_valueChanged(int value)
{
    wartosc=value;
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

//void MainWindow::on_LewoPrawo_sliderReleased()
//{
//    kopiuj();
//}

//void MainWindow::on_GoraDol_sliderReleased()
//{
//    kopiuj();
//}


//void MainWindow::on_Rotacja_sliderReleased()
//{
//    kopiuj();
//}

