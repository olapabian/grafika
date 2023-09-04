#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <cmath>
#include "macierz.h"
#include "macierz.cpp"
#include <math.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    img = new QImage("C:/Users/User/Desktop/grafika/przeksztalcenia2D/pszczola.png");
    img2 = new QImage(*img);
    przesuniecie =new  macierz(3,3);
    rotacja =     new  macierz(3,3);
    skalowanie =  new  macierz(3,3);
    pochylenie =  new  macierz(3,3);
    powrot=       new  macierz(3,3);
    translacja=   new  macierz(3,3);
}


MainWindow::~MainWindow()
{
    delete przesuniecie, rotacja,skalowanie, pochylenie, powrot, translacja;
    delete ui;
    delete img;
    delete img2;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0, 0, *img2);
}


macierz *MainWindow::stworzMacierze() //zwracja tablice 3x1 z przesunieciami po x i y tworzenie macierzy z wartosciami juz
{

////////////////////przesuniecie/////////////////////////////

    przesuniecie->addValue(1,0);    przesuniecie->addValue(0,1);    przesuniecie->addValue(ui->LewoPrawo->value()-272,2);
    przesuniecie->addValue(0,3);    przesuniecie->addValue(1,4);    przesuniecie->addValue(ui->GoraDol->value()-338,5);
    przesuniecie->addValue(0,6);    przesuniecie->addValue(0,7);    przesuniecie->addValue(1,8);



///////////////////rotacja////////////////////////////

    // do powrot na dobre miejsce

    powrot->addValue(1,0);    powrot->addValue(0,1);    powrot->addValue(272,2);
    powrot->addValue(0,3);    powrot->addValue(1,4);    powrot->addValue(338,5);
    powrot->addValue(0,6);    powrot->addValue(0,7);    powrot->addValue(1,8);


    //rotacja wzgl 0 0
    rotacja->addValue(std::cos(ui->Rotacja->value()*M_PI/180.0),0);    rotacja->addValue(-std::sin(ui->Rotacja->value()*M_PI/180.0),1);      rotacja->addValue(0,2);
    rotacja->addValue(std::sin(ui->Rotacja->value()*M_PI/180.0),3);    rotacja->addValue(std::cos(ui->Rotacja->value()*M_PI/180.0),4);       rotacja->addValue(0,5);
    rotacja->addValue(0,6);                                            rotacja->addValue(0,7);                                               rotacja->addValue(1,8);


    // do translacja do rogu
    translacja->addValue(1,0);    translacja->addValue(0,1);    translacja->addValue(-272,2);
    translacja->addValue(0,3);    translacja->addValue(1,4);    translacja->addValue(-338,5);
    translacja->addValue(0,6);    translacja->addValue(0,7);    translacja->addValue(1,8);


///////////////////skalowanie////////////////////////////

    //skalowanie wzgledem 0 0
    skalowanie->addValue(ui->Skalownie->value()/100.0,0);    skalowanie->addValue(0,1);                                 skalowanie->addValue(0,2);
    skalowanie->addValue(0,3);                               skalowanie->addValue(ui->Skalowanie2->value()/100.0,4);    skalowanie->addValue(0,5);
    skalowanie->addValue(0,6);                               skalowanie->addValue(0,7);                                 skalowanie->addValue(1,8);


///////////////////////pochylenie//////////////////////////


    //pochylenie
    pochylenie->addValue(1,0);                                        pochylenie->addValue(ui->horizontalSlider_6->value()/100.0,1);      pochylenie->addValue(0,2);
    pochylenie->addValue(ui->horizontalSlider_7->value()/100.0,3);    pochylenie->addValue(1,4);                                          pochylenie->addValue(0,5);
    pochylenie->addValue(0,6);                                        pochylenie->addValue(0,7);                                          pochylenie->addValue(1,8);


/////////////////////////////////////////////////
    macierz *wynik = przesuniecie->pomnoz(3,3,powrot->pomnoz(3,3,rotacja->pomnoz(3,3,translacja->pomnoz(3,3,powrot->pomnoz(3,3,skalowanie->pomnoz(3,3,translacja->pomnoz(3,3,powrot->pomnoz(3,3,pochylenie->pomnoz(3,3,translacja)))))))));
    return wynik;
}
void MainWindow::przesun()
{
    unsigned char* ptr = img->bits();
    unsigned char* ptr2 = img2->bits();
    macierz *m = stworzMacierze();
    for (int y = 0; y < wys; ++y)
    {
        for (int x = 0; x < szer; ++x)
        {
            macierz *dane = new macierz(3,1);
            dane->addValue(x,0);
            dane->addValue(y,1);
            dane->addValue(1,2);
            macierz *p = m->pomnoz(3,1,dane);
            int xP = p->tab[0];
            int yP = p->tab[1];
            if (xP > 1 && xP < szer-1 && yP > 1 && yP < wys-1)
            {
                ptr2[szer * 4 * yP + 4 * xP] = ptr[szer * 4 * y + 4 * x];
                ptr2[szer * 4 * yP + 4 * xP + 1] = ptr[szer * 4 * y + 4 * x + 1];
                ptr2[szer * 4 * yP + 4 * xP + 2] = ptr[szer * 4 * y + 4 * x + 2];
            }
            delete p;
            delete dane;
        }
    }
    delete m;
    repaint();
}


void MainWindow::on_LewoPrawo_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_GoraDol_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_Rotacja_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_Skalownie_valueChanged(int value)
{
    przesun();
}

void MainWindow::on_Skalowanie2_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_horizontalSlider_7_valueChanged(int value)
{
    przesun();
}

