#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <cmath>
#include "macierz.h"
#include "macierz.cpp"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      img(new QImage("C:/Users/User/Desktop/przeksztalcenia2D/pszczola.png")),
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


macierz MainWindow::stworzMacierze() //zwracja tablice 3x1 z przesunieciami po x i y tworzenie macierzy z wartosciami juz
{   
    std::vector <double>pom;

////////////////////przesuniecie/////////////////////////////

    pom={1,0,ui->LewoPrawo->value()-272,
         0,1,ui->GoraDol->value()-338,
         0,0,1};
    macierz wynik = macierz(3,3,pom);

///////////////////rotacja////////////////////////////

    //powrot na dobre miejsce
    pom={1,0,272,
         0,1,338,
         0,0,1};
    wynik=wynik.pomnoz(3,3,pom);

    //rotacja wzgl 0 0
    pom={std::cos(ui->Rotacja->value()),-std::sin(ui->Rotacja->value()),0,
         std::sin(ui->Rotacja->value()),std::cos(ui->Rotacja->value()),0,
         0,0,1};
    wynik = wynik.pomnoz(3,3,pom);

    //translacja do rogu
    pom={1,0,-272,
         0,1,-338,
         0,0,1};
    wynik = wynik.pomnoz(3,3,pom);

///////////////////skalowanie////////////////////////////

    //powrot na dobre miejsce

    pom={1,0,272,
         0,1,338,
         0,0,1};
    wynik=wynik.pomnoz(3,3,pom);

    //skalowanie wzgledem 0 0
    pom={ui->Skalownie->value()/100.0,0,0,
         0,ui->Skalowanie2->value()/100.0,0,
         0,0,1};
    wynik=wynik.pomnoz(3,3,pom);

    //translacja do rogu

    pom={1,0,-272,
         0,1,-338,
         0,0,1};
    wynik=wynik.pomnoz(3,3,pom);


/////////////////////////////////////////////////
///////////////////////////////////////////////

    //translacja do rogu

//    pom={1,0,272,
//         0,1,338,
//         0,0,1};



//    wynik=wynik.pomnoz(3,3,pom);

    //pochylenie
//    pom={0,ui->horizontalSlider_6->value()/100.0,0,
//         ui->horizontalSlider_7->value()/100.0,0,0,
//         0,0,1};
//    wynik=wynik.pomnoz(3,3,pom);

    //powrot na dobre miejsce

//    pom={1,0,-272,
//         0,1,-338,
//         0,0,1};

//    wynik=wynik.pomnoz(3,3,pom);


/////////////////////////////////////////////////


    return wynik;
}
void MainWindow::przesun()
{
    unsigned char* ptr = img->bits();
    unsigned char* ptr2 = img2->bits();
    macierz m =stworzMacierze();
    for (int y = 0; y < wys; ++y)
    {
        for (int x = 0; x < szer; ++x)
        {
            std::vector <double> pom = {x,y,1};
            macierz p = m.pomnoz(3,1,pom);
            int xP = p.tab[0];
            int yP = p.tab[1];
            if (xP > 1 && xP < szer-1 && yP > 1 && yP < wys-1)
            {
                ptr2[szer * 4 * yP + 4 * xP] = ptr[szer * 4 * y + 4 * x];
                ptr2[szer * 4 * yP + 4 * xP + 1] = ptr[szer * 4 * y + 4 * x + 1];
                ptr2[szer * 4 * yP + 4 * xP + 2] = ptr[szer * 4 * y + 4 * x + 2];
            }
        }
    }
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
    przeksztalcenie = 2;
    przesun();
}


void MainWindow::on_Skalownie_valueChanged(int value)
{
    przeksztalcenie = 1;
    przesun();
}

void MainWindow::on_Skalowanie2_valueChanged(int value)
{
    przeksztalcenie = 2;
    przesun();
}


void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{

}


void MainWindow::on_horizontalSlider_7_valueChanged(int value)
{
}

