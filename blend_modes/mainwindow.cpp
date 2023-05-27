#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPainter>
#include <QPixmap>
#include <QListWidget>

void MainWindow::on_horizontalSlider_valueChanged(int value) //corgi
{
    list[0].a=value/100.0;
    blenduj();
}
void MainWindow::on_horizontalSlider_2_valueChanged(int value) //rower
{
    list[1].a=value/100.0;
    blenduj();
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value) //orzechy
{
    list[2].a=value/100.0;
    blenduj();
}


//mode
void MainWindow::on_listWidget_currentRowChanged(int currentRow) //corgi
{
    list[0].mode=currentRow;
    blenduj();
}
void MainWindow::on_listWidget_2_currentRowChanged(int currentRow) //rower
{
    list[1].mode=currentRow;
    blenduj();
}
void MainWindow::on_listWidget_3_currentRowChanged(int currentRow)//orzechy
{
    list[2].mode=currentRow;
    blenduj();
}
void MainWindow::blenduj() //img obraz kopiowany img2 obraz do ktorego kopiujemy
{
    czarno();
    for(int i=2;i>=0;--i)
    {
        unsigned char *ptr = list[i].img->bits();//gorny
        unsigned char *ptr2 = tlo->bits(); //tlo
        for(int y=0;y<wys;++y)
        {
            for(int x=0;x<szer;++x)
            {
                if(list[i].mode==0) //normal
                {
                    ptr2[szer*4*y + 4*x] = list[i].a*ptr[szer*4*y + 4*x] + (1-list[i].a)*ptr2[szer*4*y + 4*x];
                    ptr2[szer*4*y + 4*x + 1] = list[i].a*ptr[szer*4*y + 4*x + 1] + (1-list[i].a)*ptr2[szer*4*y + 4*x +1];
                    ptr2[szer*4*y + 4*x + 2] = list[i].a*ptr[szer*4*y + 4*x + 2] + (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                }
                else if(list[i].mode==1) //average
                {
                    ptr2[szer*4*y + 4*x] = list[i].a*((ptr[szer*4*y + 4*x] + ptr2[szer*4*y + 4*x])/2)+ (1-list[i].a)*ptr2[szer*4*y + 4*x];
                    ptr2[szer*4*y + 4*x + 1] = list[i].a*((ptr[szer*4*y + 4*x + 1] + ptr2[szer*4*y + 4*x + 1])/2) + (1-list[i].a)*ptr2[szer*4*y + 4*x +1];
                    ptr2[szer*4*y + 4*x + 2] = list[i].a*((ptr[szer*4*y + 4*x + 2] + ptr2[szer*4*y + 4*x + 2])/2) + (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                }
                else if(list[i].mode==3) //darken
                {
                    if(ptr[szer*4*y + 4*x] < ptr2[szer*4*y + 4*x]){
                        ptr2[szer*4*y + 4*x] = list[i].a*ptr2[szer*4*y + 4*x]+ (1-list[i].a)*ptr2[szer*4*y + 4*x];
                    }
                    else ptr2[szer*4*y + 4*x] = list[i].a*ptr[szer*4*y + 4*x]+ (1-list[i].a)*ptr2[szer*4*y + 4*x];

                    if(ptr[szer*4*y + 4*x + 1] < ptr2[szer*4*y + 4*x + 1]){
                        ptr2[szer*4*y + 4*x + 1] = list[i].a*ptr2[szer*4*y + 4*x + 1]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 1];
                    }
                    else ptr2[szer*4*y + 4*x + 1] = list[i].a*ptr[szer*4*y + 4*x + 1]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 1];

                    if(ptr[szer*4*y + 4*x + 2] < ptr2[szer*4*y + 4*x + 2]){
                        ptr2[szer*4*y + 4*x + 2] = list[i].a*ptr2[szer*4*y + 4*x + 2]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                    }
                    else ptr2[szer*4*y + 4*x + 2] = list[i].a*ptr[szer*4*y + 4*x + 2]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                }
                else if(list[i].mode==2) //lighten
                {
                    if(ptr[szer*4*y + 4*x] > ptr2[szer*4*y + 4*x]){
                        ptr2[szer*4*y + 4*x] = list[i].a*ptr2[szer*4*y + 4*x]+ (1-list[i].a)*ptr2[szer*4*y + 4*x];
                    }
                    else ptr2[szer*4*y + 4*x] = list[i].a*ptr[szer*4*y + 4*x]+ (1-list[i].a)*ptr2[szer*4*y + 4*x];

                    if(ptr[szer*4*y + 4*x + 1] > ptr2[szer*4*y + 4*x + 1]){
                        ptr2[szer*4*y + 4*x + 1] = list[i].a*ptr2[szer*4*y + 4*x + 1]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 1];
                    }
                    else ptr2[szer*4*y + 4*x + 1] = list[i].a*ptr[szer*4*y + 4*x + 1]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 1];

                    if(ptr[szer*4*y + 4*x + 2] > ptr2[szer*4*y + 4*x + 2]){
                        ptr2[szer*4*y + 4*x + 2] = list[i].a*ptr2[szer*4*y + 4*x + 2]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                    }
                    else ptr2[szer*4*y + 4*x + 2] = list[i].a*ptr[szer*4*y + 4*x + 2]+ (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                }
                else if(list[i].mode==4) //multiply
                {
                    ptr2[szer*4*y + 4*x] = list[i].a*((ptr[szer*4*y + 4*x] * ptr2[szer*4*y + 4*x])>>8)+ (1-list[i].a)*ptr2[szer*4*y + 4*x];
                    ptr2[szer*4*y + 4*x + 1] = list[i].a*((ptr[szer*4*y + 4*x + 1] * ptr2[szer*4*y + 4*x + 1])>>8) + (1-list[i].a)*ptr2[szer*4*y + 4*x +1];
                    ptr2[szer*4*y + 4*x + 2] = list[i].a*((ptr[szer*4*y + 4*x + 2] * ptr2[szer*4*y + 4*x + 2])>>8) + (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                }
                else if(list[i].mode==4) //differences
                {
                    ptr2[szer*4*y + 4*x] = list[i].a*(std::abs(ptr[szer*4*y + 4*x] - ptr2[szer*4*y + 4*x])>>8)+ (1-list[i].a)*ptr2[szer*4*y + 4*x];
                    ptr2[szer*4*y + 4*x + 1] = list[i].a*(std::abs(ptr[szer*4*y + 4*x + 1] - ptr2[szer*4*y + 4*x + 1])>>8) + (1-list[i].a)*ptr2[szer*4*y + 4*x +1];
                    ptr2[szer*4*y + 4*x + 2] = list[i].a*(std::abs(ptr[szer*4*y + 4*x + 2] - ptr2[szer*4*y + 4*x + 2])>>8) + (1-list[i].a)*ptr2[szer*4*y + 4*x + 2];
                }

            }
        }
    }
    update();
}
 void MainWindow::czarno()

 {
     unsigned char *ptr=tlo->bits();
     for(int y=0;y<wys;++y)
     {
         for(int x=0;x<szer;++x)
         {
             ptr[szer*4*y + 4*x] = 0;
             ptr[szer*4*y + 4*x + 1] = 0;
             ptr[szer*4*y + 4*x + 2] = 0;
         }
     }
 }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pix1 = new QImage("C:/Users/User/Desktop/grafika/blend_modes/corgi.jpg");
    pix2 = new QImage("C:/Users/User/Desktop/grafika/blend_modes/rower.jpg");
    pix3 = new QImage("C:/Users/User/Desktop/grafika/blend_modes/orzechy.jpg");
    tlo = new QImage(szer,wys,QImage::Format_RGB32);
    czarno();
    list[0].img=pix1;
    list[1].img=pix2;
    list[2].img=pix3;
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0,0,*tlo);

}
















