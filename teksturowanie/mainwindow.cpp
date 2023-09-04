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

    aInitialized = false;
    bInitialized = false;
    cInitialized = false;

    AInitialized = false;
    BInitialized = false;
    CInitialized = false;
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
                a = Point;
                aInitialized = true;
                wielokat1.push_back(Point);
            }
            else if (licznik == 1)
            {
                licznik++;
                b = Point;
                bInitialized = true;
                wielokat1.push_back(Point);
            }
            else if (licznik == 2)
            {
                licznik++;
                c = Point;
                cInitialized = true;
                wielokat1.push_back(Point);
                rysujTrojkat(0);
            }
            else if (xPom < a.x + 7 && xPom > a.x - 7 && yPom > a.y - 7 && yPom < a.y + 7)
            {
                AisPressed = true;
            }
            else if (xPom < b.x + 7 && xPom > b.x - 7 && yPom > b.y - 7 && yPom < b.y + 7)
            {
                BisPressed = true;
            }
            else if (xPom < c.x + 7 && xPom > c.x - 7 && yPom > c.y - 7 && yPom < c.y + 7)
            {
                CisPressed = true;
            }
        }
        else if (xPom <= 1100 && xPom >= 600 && yPom >= 10 && yPom <= 510) // Czarny obrazek
        {
            isPressed2 = true;
            if (licznik2 == 0)
            {
                licznik2++;
                A = Point;
                AInitialized = true;
                wielokat2.push_back(Point);
            }
            else if (licznik2 == 1)
            {
                licznik2++;
                B = Point;
                BInitialized = true;
                wielokat2.push_back(Point);
            }
            else if (licznik2 == 2)
            {
                licznik2++;
                C = Point;
                CInitialized = true;
                wielokat2.push_back(Point);
//                teksturowanie();
                rysujTrojkat(1);
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
void MainWindow::rysujTrojkat(int wielkosc)
{
    if (wielkosc == 0)
    {
        if (aInitialized && bInitialized && cInitialized)
        {
            kreska2(b.x,b.y,a.x,a.y,wielkosc);
            kreska2(c.x,c.y,b.x,b.y,wielkosc);
            kreska2(a.x,a.y,c.x,c.y,wielkosc);

            kwadrat(b.x,b.y,wielkosc);

            kwadrat(a.x,a.y,wielkosc);

            kwadrat(c.x,c.y,wielkosc);
            update();
        }
    }
    else if (wielkosc == 1)
    {
        if (AInitialized && BInitialized && CInitialized)
        {
            kreska2(B.x,B.y,A.x,A.y,wielkosc);
            kreska2(C.x,C.y,B.x,B.y,wielkosc);
            kreska2(A.x,A.y,C.x,C.y,wielkosc);

            kwadrat(B.x,B.y,wielkosc);

            kwadrat(A.x,A.y,wielkosc);

            kwadrat(C.x,C.y,wielkosc);
            update();
        }
    }
    teksturowanie();
    update();
}

void MainWindow::teksturowanie()
{
    if (aInitialized && bInitialized && cInitialized && AInitialized && BInitialized && CInitialized)
    {
        unsigned char *ptr;
        ptr = orginal->bits();
        int wys = img->height();
        int szer = img->width();
        std::vector<wspolrzedne> Wspolrzedne;
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
                    if((((B.y - C.y) * (A.x - C.x)) + ((C.x - B.x) * (A.y - C.y)))!=0)
                    {
                        double alfa = static_cast<double>(((x - C.x) * (B.y - C.y)) + ((C.x - B.x) * (y - C.y))) / (((B.y - C.y) * (A.x - C.x)) + ((C.x - B.x) * (A.y - C.y)));
                        double beta = static_cast<double>(((A.x - C.x) * (y - C.y)) + ((x - C.x) * (C.y - A.y))) / (((B.y - C.y) * (A.x - C.x)) + ((C.x - B.x) * (A.y - C.y)));
                        double gamma = 1.0 - alfa - beta;
                        if (alfa >= 0 && alfa < 1 && beta >= 0 && beta < 1 && gamma >= 0 && gamma < 1)
                        {                           
                            double x1 = alfa * a.x + beta * b.x + gamma * c.x;
                            double y1 = alfa * a.y + beta * b.y + gamma * c.y;

                            if (x1 >= 0 && x1 < szer && y1 >= 0 && y1 < wys)
                            {
                                int r2 = InterpolacjaDwuliniowa(x1,y1).r;
                                int g2 = InterpolacjaDwuliniowa(x1,y1).g;
                                int b2 = InterpolacjaDwuliniowa(x1,y1).b;

                                wstawPiksel(x, y, r2, g2, b2, 1);
                            }
                        }
                    }
                }
                przeciecia2.clear();
            }
        }
    }
}

// Funkcja do interpolacji dwuliniowej
Color MainWindow::InterpolacjaDwuliniowa( double x, double y) {
    unsigned char *img;
    img = orginal->bits();
    int wys = orginal->height();
    int szer = orginal->width();

    int x0 = static_cast<int>(x);
    int y0 = static_cast<int>(y);
    int x1 = x0 + 1;
    int y1 = y0 + 1;

    double alpha = x - x0;
    double beta = y - y0;

    // Upewnij się, że punkty (x0, y0) i (x1, y1) są w granicach obrazu
    if (x0 >= 0 && x1 < szer && y0 >= 0 && y1 < wys) {
        // Oblicz wagi
        double w00 = (1 - alpha) * (1 - beta);
        double w01 = alpha * (1 - beta);
        double w10 = (1 - alpha) * beta;
        double w11 = alpha * beta;

        // Pobierz kolory pikseli
        Color c00, c01, c10,c11;
        c00.r = img[szer*4*(y0-10) + 4*(x0-10)];
        c00.g = img[szer*4*(y0-10) + 4*(x0-10) + 1];
        c00.b = img[szer*4*(y0-10) + 4*(x0-10) + 2];
        c01.r = img[szer*4*(y0-10) + 4*(x1-10)];
        c01.g = img[szer*4*(y0-10) + 4*(x1-10) + 1];
        c01.b = img[szer*4*(y0-10) + 4*(x1-10) + 2];
        c10.r = img[szer*4*(y1-10) + 4*(x0-10)];
        c10.g = img[szer*4*(y1-10) + 4*(x0-10) + 1];
        c10.b = img[szer*4*(y1-10) + 4*(x0-10) + 2];
        c11.r = img[szer*4*(y1-10) + 4*(x1-10)];
        c11.g = img[szer*4*(y1-10) + 4*(x1-10) + 1];
        c11.b = img[szer*4*(y1-10) + 4*(x1-10) + 2];

        // Wykonaj interpolację kolorów
        Color result;
        result.r = static_cast<int>(w00 * c00.r + w01 * c01.r + w10 * c10.r + w11 * c11.r);
        result.g = static_cast<int>(w00 * c00.g + w01 * c01.g + w10 * c10.g + w11 * c11.g);
        result.b = static_cast<int>(w00 * c00.b + w01 * c01.b + w10 * c10.b + w11 * c11.b);

        return result;
    } else {
        // Jeśli punkty nie mieszczą się w granicach obrazu, zwróć domyślny kolor lub obsłuż błąd
        return Color{0, 0, 0}; // Czarny kolor w przypadku błędu
    }
}


//void MainWindow::teksturowanie()
//{
//    unsigned char *ptr;
//    ptr = orginal->bits();
//    int wys = img->height();
//    int szer = img->width();
//    int minX = std::min({A.x,B.x,C.x});
//    int maxX = std::max({A.x,B.x,C.x});
//    int minY = std::min({A.y,B.y,C.y});
//    int maxY = std::max({A.y,B.y,C.y});

//    for(int y = minY; y < maxY; y++)
//    {
//        for(int x = minX; x < maxX; x++)
//        {
//            float alfa = (((x - A.x) * (A.y - A.y)) - ((C.x - A.x) * (y - A.y))) / (((B.x - A.x) * (C.y - A.y)) - ((C.x - A.x) * (B.y - B.y)));
//            float beta = (((A.x - A.x) * (y - A.y)) - ((x - A.x) * (B.y - A.y))) / (((B.x - A.x) * (C.y - A.y)) - ((C.x - A.x) * (B.y - B.y)));
//            float gamma = 1 - alfa - beta;
//            if (alfa > 0 && alfa < 1 && beta > 0 && beta < 1 && gamma > 0 && gamma < 1)
//            {
//                float A = alfa * a.x + beta * b.x + gamma * c.x;
//                float B = alfa * a.y + beta * b.y + gamma * c.y;
//                int x = static_cast<int>(A);
//                int y = static_cast<int>(B);
//                int x2 = x + 1;
//                int y2 = y + 1;
//                A -=x;
//                B -=y;
//                if(y2 == wys)
//                    y2--;
//                if(x2 == szer)
//                    x2--;

//                int r2 = static_cast<int>(round(Interpolacja(static_cast<int>(Interpolacja(ptr[szer*4*(y) + 4*(x) + 2],ptr[szer*4*(y2) + 4*(x) + 2],B)),static_cast<int>(Interpolacja(ptr[szer*4*(y) + 4*(x2) + 2],ptr[szer*4*(y2) + 4*(x2) + 2],B)),A)));
//                int g2 = static_cast<int>(round(Interpolacja(static_cast<int>(Interpolacja(ptr[szer*4*(y) + 4*(x) + 1],ptr[szer*4*(y2) + 4*(x) + 1],B)),static_cast<int>(Interpolacja(ptr[szer*4*(y) + 4*(x2) + 1],ptr[szer*4*(y2) + 4*(x2) + 1],B)),A)));
//                int b2 = static_cast<int>(round(Interpolacja(static_cast<int>(Interpolacja(ptr[szer*4*(y) + 4*(x)],ptr[szer*4*(y2) + 4*(x)],B)),static_cast<int>(Interpolacja(ptr[szer*4*(y) + 4*(x2)],ptr[szer*4*(y2) + 4*(x2)],B)),A)));

//                wstawPiksel(x, y, r2, g2, b2, 1);
//            }
//        }
//    }
//    update();
//}
