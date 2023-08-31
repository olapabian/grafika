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
    licznik=0;
    licznik2=0;
    licznik3=0;

    a.x = 0; b.x = 0; c.x = 0;
    a.y = 0; b.y = 0; c.y = 0; // punkty na sowie

    A.x = 0; B.x = 0; C.x = 0;
    A.y = 0; B.y = 0; C.y = 0; // punkty na czarnym
}


MainWindow::~MainWindow()
{
    licznik=0;
    licznik2=0;
    delete img;
    delete orginal;
    delete img2;
    delete imgMemory;
    delete img2Memory;
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
    int xPom = event->x();
    int yPom = event->y();
    point Point;
    Point.x = xPom;
    Point.y = yPom;

    if (event->button() == Qt::LeftButton)
    {
        if (xPom <= 510 && xPom >= 10 && yPom >= 10 && yPom <= 510) // Pierwszy obrazek
        {
            isPressed = true;
            if (licznik == 0)
            {
                licznik++;
                a=Point;
                wielokat1.push_back(Point);
            }
            else  if(licznik==1)
            {
                licznik++;
                b=Point;
                wielokat1.push_back(Point);
            }
            else  if(licznik==2)
            {
                licznik++;
                c=Point;               
                wielokat1.push_back(Point);
                rysujTrojkat(0);
            }
            else if(xPom < a.x + 7 && xPom > a.x - 7 && yPom > a.y - 7 && yPom < a.y + 7)
            {
                AisPressed = true;
            }
            else if(xPom < b.x + 7 && xPom > b.x - 7 && yPom > b.y - 7 && yPom < b.y + 7)
            {
                BisPressed = true;
            }
            else if(xPom < c.x + 7 && xPom > c.x - 7 && yPom > c.y - 7 && yPom < c.y + 7)
            {
                CisPressed = true;
            }
        }
        else if(xPom <= 1100 && xPom >= 600 && yPom >= 10 && yPom <= 510) // Czarny obrazek
        {
            isPressed2 = true;
            if (licznik2 == 0)
            {
                licznik2++;
                A=Point;
                wielokat2.push_back(Point);

            }
            else if (licznik2 == 1)
            {
                licznik2++;
                B=Point;
                wielokat2.push_back(Point);

            }
            else if (licznik2 == 2)
            {
                licznik2++;
                C=Point;
                wielokat2.push_back(Point);

                rysujTrojkat(1);
                teksturowanie();

            }
            else if (xPom < A.x + 7 && xPom > A.x - 7 && yPom > A.y - 7 && yPom < A.y + 7)
            {
                BigAisPressed = true;
            }
            else if (xPom < B.x + 7 && xPom > B.x - 7 && yPom > B.y - 7 && yPom < B.y + 7)
            {
                BigBisPressed = true;
            }
            else if (xPom < C.x + 7 && xPom > C.x - 7 && yPom > C.y - 7 && yPom < C.y + 7)
            {
                BigCisPressed = true;
            }

        }
    }
    update();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int xPom = event->x();
    int yPom = event->y();
    point Point;
    Point.x = xPom;
    Point.y = yPom;
    if((event->buttons() == Qt::LeftButton) && isPressed)
    {
        czysc1();
        if(AisPressed)
        {
            a=Point;
            wielokat1[0]=Point;
        }
        else if(BisPressed)
        {
            b=Point;
            wielokat1[1]=Point;
        }
        else if(CisPressed)
        {
            c=Point;
            wielokat1[2]=Point;
        }
        rysujTrojkat(0);
    }
    if((event->buttons() == Qt::LeftButton) && isPressed2)
    {
        czysc2();
        if(BigAisPressed)
        {
            A=Point;
            wielokat2[0]=Point;
        }
        else if(BigBisPressed)
        {
            B=Point;
            wielokat2[1]=Point;
        }
        else if(BigCisPressed)
        {
            C=Point;
            wielokat2[2]=Point;
        }

        rysujTrojkat(1);

    }

    update();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
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
        kreska2(c.x,c.y,b.x,b.y,wielkosc);
        kreska2(a.x,a.y,c.x,c.y,wielkosc);

        kwadrat(b.x,b.y,wielkosc);

        kwadrat(a.x,a.y,wielkosc);

        kwadrat(c.x,c.y,wielkosc);
    }
    else
    {

        kreska2(B.x,B.y,A.x,A.y,wielkosc);
        kreska2(C.x,C.y,B.x,B.y,wielkosc);
        kreska2(A.x,A.y,C.x,C.y,wielkosc);

        kwadrat(B.x,B.y,wielkosc);

        kwadrat(A.x,A.y,wielkosc);

        kwadrat(C.x,C.y,wielkosc);
    }
    update();
}

void MainWindow::teksturowanie()
{
    unsigned char *ptr;
    ptr = img->bits();
    int wys = img->height();
    int szer = img->width();
    std::vector<wspolrzedne> Wspolrzedne;
    for(int y = 0; y < wys; y++)
    {
        std::vector <int> przeciecia;//przechowuje przecieciaprostej poziomej
        for(int i=0;i<wielokat1.size()-1;i++)//szukanie przeciec
        {
            if((wielokat1[i].y>y && wielokat1[i+1].y<=y) || (wielokat1[i].y<=y && wielokat1[i+1].y>y))
            {
                int x = wielokat1[i].x + (y-wielokat1[i].y)*(wielokat1[i+1].x-wielokat1[i].x)/(wielokat1[i+1].y-wielokat1[i].y);
                przeciecia.push_back(x);
            }
        }
        if((wielokat1.back().y > y && wielokat1.front().y <= y) || (wielokat1.back().y <= y && wielokat1.front().y > y))
        {
            int x = wielokat1.back().x + (y - wielokat1.back().y) * (wielokat1.front().x - wielokat1.back().x) / (wielokat1.front().y - wielokat1.back().y);
            przeciecia.push_back(x);
        }
        std::sort(przeciecia.begin(),przeciecia.end());

        for(int i=0;i<przeciecia.size();i+=2)
        {
            for(int x = przeciecia[i]; x < przeciecia[i+1]; x++)
            {
                wspolrzedne pom;
                 //Oblicz współrzędne barycentryczne piksela
                pom.alfa = ((float)((b.y - c.y) * x + (c.x - b.x) * y + b.x * c.y - b.y * c.x)) /
                              ((float)((b.y - c.y) * a.x + (c.x - b.x) * a.y + b.x * c.y - b.y * c.x));
                pom.beta = ((float)((c.y - a.y) * x + (a.x - c.x) * y + c.x * a.y - c.y * a.x)) /
                             ((float)((b.y - c.y) * a.x + (c.x - b.x) * a.y + b.x * c.y - b.y * c.x));
                pom.gamma = 1.0f - pom.alfa - pom.beta;
                if(licznik3==0)
                {
                    Wspolrzedne.push_back(pom);
                }
                else Wspolrzedne[0]=pom;
            }
        }
        przeciecia.clear();
    }
    unsigned char *ptr2;
    ptr2 = img2->bits();
    for(int y = 0; y < wys; y++)
    {
        std::vector <int> przeciecia2;//przechowuje przecieciaprostej poziomej
        for(int i=0;i<wielokat2.size()-1;i++)//szukanie przeciec
        {
            if((wielokat2[i].y>y && wielokat2[i+1].y<=y) || (wielokat2[i].y<=y && wielokat2[i+1].y>y))
            {
                int x = wielokat2[i].x + (y-wielokat2[i].y)*(wielokat2[i+1].x-wielokat2[i].x)/(wielokat2[i+1].y-wielokat2[i].y);
                przeciecia2.push_back(x);
            }
        }
        if((wielokat2.back().y > y && wielokat2.front().y <= y) || (wielokat2.back().y <= y && wielokat2.front().y > y))
        {
            int x = wielokat2.back().x + (y - wielokat2.back().y) * (wielokat2.front().x - wielokat2.back().x) / (wielokat2.front().y - wielokat2.back().y);
            przeciecia2.push_back(x);
        }
        std::sort(przeciecia2.begin(),przeciecia2.end());

        for(int i=0;i<przeciecia2.size();i+=2)
        {
            for(int x = przeciecia2[i]; x < przeciecia2[i+1]; x++)
            {
//                ptr2[static_cast<int>(std::round(Wspolrzedne[x].alfa*B->x + Wspolrzedne[x].beta*B->x + Wspolrzedne[x].gamma*C->x))]=ptr[szer*4*(y-10) + 4*(x-10)]; // Składowa BLUE
//                ptr2[static_cast<int>(std::round(Wspolrzedne[x].alfa*B->x + Wspolrzedne[x].beta*B->x + Wspolrzedne[x].gamma*C->x)) + 1]=ptr[szer*4*(y-10) + 4*(x-10)+1]; // Składowa GREEN
//                ptr2[static_cast<int>(std::round(Wspolrzedne[x].alfa*B->x + Wspolrzedne[x].beta*B->x + Wspolrzedne[x].gamma*C->x)) + 2]=ptr[szer*4*(y-10) + 4*(x-10)+2]; // Składowa RED
                // Calculate pixel coordinates and components
//                          int pixel_x = static_cast<int>(std::round(Wspolrzedne[x].alfa * B->x + Wspolrzedne[x].beta * B->x + Wspolrzedne[x].gamma * C->x));
//                          int pixel_y = static_cast<int>(std::round(Wspolrzedne[y].alfa * B->y + Wspolrzedne[y].beta * B->y + Wspolrzedne[y].gamma * C->y));
//                          int blue_component = ptr[szer * 4 * (pixel_y - 10) + 4 * (pixel_x - 10)];
//                          int green_component = ptr[szer * 4 * (pixel_y - 10) + 4 * (pixel_x - 10) + 1];
//                          int red_component = ptr[szer * 4 * (pixel_y - 10) + 4 * (pixel_x - 10) + 2];

//                          // Set pixel values using wstawPiksel or other appropriate method
//                          wstawPiksel(x, y, blue_component, green_component, red_component, 1);
                int pixel_x = static_cast<int>(std::round(Wspolrzedne[0].alfa * a.x + Wspolrzedne[0].beta * b.x + Wspolrzedne[0].gamma * c.x));
                                int pixel_y = static_cast<int>(std::round(Wspolrzedne[0].alfa * a.y + Wspolrzedne[0].beta * b.y + Wspolrzedne[0].gamma * c.y));

                                // Ensure the calculated pixel coordinates are within bounds
                                pixel_x = std::max(0, std::min(szer - 1, pixel_x));
                                pixel_y = std::max(0, std::min(wys - 1, pixel_y));

                                // Copy color components from the original image to the textured image
                                ptr2[(y * szer + x) * 4] = ptr[(pixel_y * szer + pixel_x) * 4];         // Blue
                                ptr2[(y * szer + x) * 4 + 1] = ptr[(pixel_y * szer + pixel_x) * 4 + 1]; // Green
                                ptr2[(y * szer + x) * 4 + 2] = ptr[(pixel_y * szer + pixel_x) * 4 + 2]; // Red
                                ptr2[(y * szer + x) * 4 + 3] = 255; // Alpha (assuming 4-channel BGRA)
                            }

                //wstawPiksel(x, y, static_cast<int>(std::round(Wspolrzedne[x].alfa*B->x + Wspolrzedne[x].beta*B->x + Wspolrzedne[x].gamma*C->x)), static_cast<int>(std::round(Wspolrzedne[x].alfa*B->x + Wspolrzedne[x].beta*B->x + Wspolrzedne[x].gamma*C->x)) + 1, static_cast<int>(std::round(Wspolrzedne[x].alfa*B->x + Wspolrzedne[x].beta*B->x + Wspolrzedne[x].gamma*C->x)) + 2, 1);
            }
        przeciecia2.clear();
    }
}
