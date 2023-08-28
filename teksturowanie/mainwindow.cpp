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
    orginal = new QImage("C:/Users/User/Desktop/grafika/teksturowanie/sowa.jpg");
    img2 = new QImage(500, 500, QImage::Format_RGB32);
    imgMemory = new QImage(500, 500, QImage::Format_RGB32);
    img2Memory = new QImage(500, 500, QImage::Format_RGB32);
}


MainWindow::~MainWindow()
{
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




void MainWindow::czysc1()
{
    unsigned char *ptr2 = orginal->bits();
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            ptr[szer*4*y + 4*x] = ptr2[szer*4*y + 4*x]; // Składowa BLUE
            ptr[szer*4*y + 4*x + 1] = ptr2[szer*4*y + 4*x + 1]; // Składowa GREEN
            ptr[szer*4*y + 4*x + 2] = ptr2[szer*4*y + 4*x + 2]; // Składowa RED
        }
    }
}
void MainWindow::czysc2()
{
    unsigned char *ptr2 = img2Memory->bits();
    unsigned char *ptr = img2->bits();
    int szer = img->width();
    int wys = img->height();
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            ptr[szer*4*y + 4*x] = 0; // Składowa BLUE
            ptr[szer*4*y + 4*x + 1] = 0; // Składowa GREEN
            ptr[szer*4*y + 4*x + 2] = 0; // Składowa RED
        }
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton)
    {
        if(x<=510 && x>=10 && y>=10 && y <=510) //pierwszy obrazek
        {
            isPressed=true;
            if(licznik==0)
            {
                a.x=x;
                a.y=y;
                licznik++;
            }
            else  if(licznik==1)
            {
                b.x=x;
                b.y=y;
                licznik++;
            }
            else  if(licznik==2)
            {
                c.x=x;
                c.y=y;
                licznik++;
                rysujTrojkat(0);
            }
            else if(x<a.x+7 && x>a.x-7 && y>a.y-7 && y<a.y+7)
            {
                AisPressed=true;
            }
            else if(x<b.x+7 && x>b.x-7 && y>b.y-7 && y<b.y+7)
            {
                BisPressed=true;
            }
            else if(x<c.x+7 && x>c.x-7 && y>c.y-7 && y<c.y+7)
            {
                CisPressed=true;
            }
        }
        else if(x<=1100 && x>=600 && y>=10 && y <=510)//czrny obrazek
        {
            isPressed2=true;
            if(licznik2==0)
            {
                A.x=x;
                A.y=y;
                licznik2++;
            }
            else  if(licznik2==1)
            {
                B.x=x;
                B.y=y;
                licznik2++;
            }
            else  if(licznik2==2)
            {
                C.x=x;
                C.y=y;
                rysujTrojkat(1);
                licznik2++;
            }
            else if(x<A.x+7 && x>A.x-7 && y>A.y-7 && y<A.y+7)
            {
                BigAisPressed=true;
            }
            else if(x<B.x+7 && x>B.x-7 && y>B.y-7 && y<B.y+7)
            {
                BigBisPressed=true;
            }
            else if(x<C.x+7 && x>C.x-7 && y>C.y-7 && y<C.y+7)
            {
                BigCisPressed=true;
            }
        }
    }
    update();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if((event->buttons() == Qt::LeftButton) && isPressed)
    {
        czysc1();
        if(AisPressed)
        {
            a.x=x;
            a.y=y;
        }
        else if(BisPressed)
        {
            b.x=x;
            b.y=y;
        }
        else if(CisPressed)
        {
            c.x=x;
            c.y=y;
        }
        rysujTrojkat(0);
        update();
    }
    if((event->buttons() == Qt::LeftButton) && isPressed2)
    {
        czysc2();
        if(BigAisPressed)
        {
            A.x=x;
            A.y=y;
        }
        else if(BigBisPressed)
        {
            B.x=x;
            B.y=y;
        }
        else if(BigCisPressed)
        {
            C.x=x;
            C.y=y;
        }
        rysujTrojkat(1);
        update();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton)
    {
        isPressed=false;
        AisPressed=false;
        BisPressed=false;
        CisPressed=false;
        isPressed2=false;
        BigAisPressed=false;
        BigBisPressed=false;
        BigCisPressed=false;
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
void MainWindow::kwadrat(int X,int Y,int obrazek)
{
    for(int i=X-7;i<=X+7;i++)
    {
        for(int j=Y-7;j<Y+7;++j)
        {
            wstawPiksel(i,j,255,0,0,obrazek);
        }
    }
}
void MainWindow::rysujTrojkat(int wielkosc) //wielkosc litery 0 - mala 1 -duza
{
    if(wielkosc==0)
    {
        kreska2(b.x,b.y,a.x,a.y,wielkosc);
        kwadrat(b.x,b.y,wielkosc);
        kreska2(c.x,c.y,b.x,b.y,wielkosc);
        kwadrat(a.x,a.y,wielkosc);
        kreska2(a.x,a.y,c.x,c.y,wielkosc);
        kwadrat(c.x,c.y,wielkosc);
    }
    else
    {
        kreska2(B.x,B.y,A.x,A.y,wielkosc);
        kreska2(C.x,C.y,B.x,B.y,wielkosc);
        kreska2(A.x,A.y,C.x,C.y,wielkosc);
        kwadrat(A.x,A.y,wielkosc);
        kwadrat(B.x,B.y,wielkosc);
        kwadrat(C.x,C.y,wielkosc);
    }
    update();
}
