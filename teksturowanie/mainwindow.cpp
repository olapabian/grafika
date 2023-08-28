#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <qevent.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    img = new QImage("C:/Users/User/Desktop/grafika/teksturowanie/sowa.jpg");
    img2 = new QImage(500, 500, QImage::Format_RGB32);

    a.x = -1; b.x = -1; c.x = -1;
    a.y = -1; b.y = -1; c.y = -1; // punkty na sowie

    A.x = -1; B.x = -1; C.x = -1;
    A.y = -1; B.y = -1; C.y = -1; // punkty na czarnym
}


MainWindow::~MainWindow()
{
    a.x = -1; b.x = -1; c.x = -1;
    a.y = -1; b.y = -1; c.y = -1; // punkty na sowie

    A.x = -1; B.x = -1; C.x = -1;
    A.y = -1; B.y = -1; C.y = -1; // punkty na czarnym
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    int x = ui->frame->x();
    int y = ui->frame->y();
    p.drawImage(10, 10, *img);
    p.drawImage(x, y, *img2);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton)
    {
        if(x<600) //pierwszy obrazek
        {
            if(a.x==-1)
            {
                a.x=x;
                a.y=y;
            }
            else  if(b.x==-1)
            {
                b.x=x;
                b.y=y;
            }
            else  if(c.x==-1)
            {
                c.x=x;
                c.y=y;
                rysujTrojkat(0);
            }
        }
        else //czrny obrazek
        {
            if(A.x==-1)
            {
                A.x=x;
                A.y=y;
            }
            else  if(B.x==-1)
            {
                B.x=x;
                B.y=y;
            }
            else  if(C.x==-1)
            {
                C.x=x;
                C.y=y;
                rysujTrojkat(1);
            }
        }

    }
    update();
}
void MainWindow::wstawPiksel(int x,int y, int r, int g, int b,int obrazek)
{
    unsigned char *ptr;
    int szer, wys;
    if(obrazek==0)
    {
        ptr = img->bits();
        szer = img->width();
        wys = img->height();
        if ((x-10>=0)&&(y-10>=0)&&(x-10<szer)&&(y-10<wys))
        {
            ptr[szer*4*(y-10) + 4*(x-10)] = r; // Składowa BLUE
            ptr[szer*4*(y-10) + 4*(x-10) + 1] = g; // Składowa GREEN
            ptr[szer*4*(y-10) + 4*(x-10) + 2] = b; // Składowa RED
        }
    }
    else
    {
        ptr = img2->bits();
        szer = img2->width();
        wys = img2->height();
        if (((x-600)>=0)&&((y-10)>=0)&&((x-600)<szer)&&((y-10)<wys))
        {
            ptr[szer*4*(y-10) + 4*(x-600)] = r; // Składowa BLUE
            ptr[szer*4*(y-10) + 4*(x-600) + 1] = g; // Składowa GREEN
            ptr[szer*4*(y-10) + 4*(x-600) + 2] = b; // Składowa RED
        }
    }

    update();
}
void MainWindow::kreska2(int finX,int finY,int sX, int sY,int obrazek) //obrazek 0 - pierszy 1 - drugi
{
    float a=1,b=0;
    int x,y;
    if(sX==finX)//pionowa
    {
        x=sX;
        if(sY<=finY)
        {
            for(int y=sY;y<=finY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y,255,0,0,obrazek);
            }
        }
        else
        {
            for(int y=finY;y<=sY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y,255,0,0,obrazek);
            }
        }
    }
    else
    {
        a=float(finY-sY)/float(finX-sX);
        b=sY-a*sX;
        if(abs(a)<=1)
        {
            y=sY;
            if(sX>finX)
            {
                for(int x=finX;x<=sX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5),255,0,0,obrazek);
                }
            }
            else
            {
                for(int x=sX;x<=finX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5),255,0,0,obrazek);
                }
            }

        }
        else
        {
            if(sY<=finY)
            {
                for(int y=sY;y<=finY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y,255,0,0,obrazek);
                }
            }
            else
            {
                for(int y=finY;y<=sY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y,255,0,0,obrazek);
                }
            }
        }
    }
    update();
}
void MainWindow::rysujTrojkat(int wielkosc) //wielkosc litery 0 - mala 1 -duza
{
    if(wielkosc==0)
    {
        kreska2(b.x,b.y,a.x,a.y,wielkosc);
        kreska2(c.x,c.y,b.x,b.y,wielkosc);
        kreska2(a.x,a.y,c.x,c.y,wielkosc);
    }
    else
    {
        kreska2(B.x,B.y,A.x,A.y,wielkosc);
        kreska2(C.x,C.y,B.x,B.y,wielkosc);
        kreska2(A.x,A.y,C.x,C.y,wielkosc);
    }
    update();
}
