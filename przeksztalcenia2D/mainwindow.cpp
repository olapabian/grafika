#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img = new QImage("C:/Users/User/Desktop/grafika/przeksztalcenia2D/pszczola.png");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0,0,*img);

}

void MainWindow::przesunPoziom()
{
    unsigned char *obraz=img->bits();
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer-warto;++x)
        {
            ptr[szer*4*y+4*x]=255;
            ptr[szer*4*y+4*x+1]=0;
            ptr[szer*4*y+4*x+2]=0;
        }
    }
}
void MainWindow::on_LewoPrawo_valueChanged(int value)
{
    slider=1;
    wartosc=value-50;//o tyle w prawo jak na minusie to w lewo
    przesunPoziom();
}


void MainWindow::on_GoraDol_valueChanged(int value)
{
    slider=2;
    wartosc=value;
}


void MainWindow::on_Rotacja_valueChanged(int value)
{
    slider=3;
    wartosc=value;
}


void MainWindow::on_Skalownie_valueChanged(int value)
{
    slider=4;
    wartosc=value;
}

void MainWindow::on_Skalowanie2_valueChanged(int value)
{
    slider=5;
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

