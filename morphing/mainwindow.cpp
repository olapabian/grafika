#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <qevent.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    img = new QImage("C:/Users/User/Desktop/grafika/morphing/sowa.jpg");
    orginal = new QImage("C:/Users/User/Desktop/grafika/morphing/sowa.jpg");
    Img = new QImage("C:/Users/User/Desktop/grafika/morphing/tygrys.jpg");
    Orginal = new QImage("C:/Users/User/Desktop/grafika/morphing/tygrys.jpg");
    img2 = new QImage(500, 500, QImage::Format_RGB32);
    pqr = new QImage(500, 500, QImage::Format_RGB32);
    PQR = new QImage(500, 500, QImage::Format_RGB32);
    n=0;
    licznik=0;
    licznik2=0;
    licznik3=0;
    aInitialized = false;
    bInitialized = false;
    cInitialized = false;
    dInitialized = false;
    eInitialized = false;
    fInitialized = false;
}


MainWindow::~MainWindow()
{
    licznik=0;
    licznik2=0;
    licznik3=0;
    delete img;
    delete Img;
    delete img2;
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    int x = ui->frame->x();
    int y = ui->frame->y();
    if(obraz == 1)
    {
        p.drawImage(10, 10, *Img);
    }
    else p.drawImage(10, 10, *img);
//    p.drawImage(x, y, *img2);
//    p.drawImage(x, y, *pqr);
    p.drawImage(x, y, *PQR);
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
    //czyszczenmi trojakta sowy
    ptr = pqr->bits();
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            ptr[szer*4*y + 4*x] = 0; // Składowa BLUE
            ptr[szer*4*y + 4*x + 1] = 0; // Składowa GREEN
            ptr[szer*4*y + 4*x + 2] = 0; // Składowa RED
        }
    }
    //czysczenie trojkata tygrysa
    ptr = img2->bits();
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
void MainWindow::czysc3()
{
    unsigned char *ptr2 = Orginal->bits();
    unsigned char *ptr = Img->bits();
    int szer = Img->width();
    int wys = Img->height();
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
            if(obraz == 0)
            {
                isPressed = true;
                if (licznik == 0)
                {
                    licznik++;
                    a=Point;
                    aInitialized = true;
                }
                else  if(licznik==1)
                {
                    licznik++;
                    b=Point;
                    bInitialized = true;
                }
                else  if(licznik==2)
                {
                    licznik++;
                    c=Point;
                    cInitialized = true;
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
            else if (obraz == 1)
            {
                isPressed3 = true;
                if (licznik3 == 0)
                {
                    licznik3++;
                    d=Point;
                    dInitialized = true;
                }
                else  if(licznik3==1)
                {
                    licznik3++;
                    e=Point;
                    eInitialized = true;
                }
                else  if(licznik3==2)
                {
                    licznik3++;
                    f=Point;
                    fInitialized = true;
                    rysujTrojkat(2);
                }
                else if(xPom < d.x + 7 && xPom > d.x - 7 && yPom > d.y - 7 && yPom < d.y + 7)
                {
                    DisPressed = true;
                }
                else if(xPom < e.x + 7 && xPom > e.x - 7 && yPom > e.y - 7 && yPom < e.y + 7)
                {
                    EisPressed = true;
                }
                else if(xPom < f.x + 7 && xPom > f.x - 7 && yPom > f.y - 7 && yPom < f.y + 7)
                {
                    FisPressed = true;
                }
            }

        }

    update();
}
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
        if(obraz == 0)
        {
            czysc1();
            if(AisPressed)
            {
                a=Point;
            }
            else if(BisPressed)
            {
                b=Point;
            }
            else if(CisPressed)
            {
                c=Point;
            }
            rysujTrojkat(0);

        }
    }
    else if((event->buttons() == Qt::LeftButton) && isPressed3)
    {
        if(obraz == 1)
        {
            czysc3();
            if(DisPressed)
            {
                d=Point;
            }
            else if(EisPressed)
            {
                e=Point;
            }
            else if(FisPressed)
            {
                f=Point;
            }
            rysujTrojkat(2);
        }
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
        DisPressed=false;
        EisPressed=false;
        FisPressed=false;
        isPressed2=false;
        isPressed3=false;
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
    if(obrazek==0)//sowa
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
    else if(obrazek == 1)//czarny
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
    else if(obrazek == 2)//tygrys
    {
        ptr = Img->bits();
        szer = Img->width();
        wys = Img->height();
        if ((x-10>=0)&&(y-10>=0)&&(x-10<szer)&&(y-10<wys))
        {
            ptr[szer*4*(y-10) + 4*(x-10)] = r; // Składowa BLUE
            ptr[szer*4*(y-10) + 4*(x-10) + 1] = g; // Składowa GREEN
            ptr[szer*4*(y-10) + 4*(x-10) + 2] = b; // Składowa RED
        }
    }
    else if(obrazek == 3)//trojkat z sowy
    {
        ptr = pqr->bits();
        szer = pqr->width();
        wys = pqr->height();
        if (((x-600)>=0)&&((y-10)>=0)&&((x-600)<szer)&&((y-10)<wys))
        {
            ptr[szer*4*(y-10) + 4*(x-600)] = r; // Składowa BLUE
            ptr[szer*4*(y-10) + 4*(x-600) + 1] = g; // Składowa GREEN
            ptr[szer*4*(y-10) + 4*(x-600) + 2] = b; // Składowa RED
        }
    }
    else if(obrazek == 4)//trojkat z tygrysa
    {
        ptr = PQR->bits();
        szer = PQR->width();
        wys = PQR->height();
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
    if(wielkosc==0 && aInitialized && bInitialized && cInitialized)
    {
        kreska2(b.x,b.y,a.x,a.y,wielkosc);
        kreska2(c.x,c.y,b.x,b.y,wielkosc);
        kreska2(a.x,a.y,c.x,c.y,wielkosc);

        kwadrat(b.x,b.y,wielkosc);

        kwadrat(a.x,a.y,wielkosc);

        kwadrat(c.x,c.y,wielkosc);
    }
    else if (dInitialized && eInitialized && fInitialized)
    {

        kreska2(e.x,e.y,d.x,d.y,wielkosc);
        kreska2(f.x,f.y,e.x,e.y,wielkosc);
        kreska2(d.x,d.y,f.x,f.y,wielkosc);

        kwadrat(e.x,e.y,wielkosc);

        kwadrat(d.x,d.y,wielkosc);

        kwadrat(f.x,f.y,wielkosc);
    }
    teksturowanie();
    update();
}

void MainWindow::teksturowanie()
{
    if (aInitialized && bInitialized && cInitialized && dInitialized && eInitialized && fInitialized)
    {
        czysc2();
        std::vector <point> wielokat2;
        point A,B,C;
        A.x = (1 - n/10.0)*(a.x + 590) + (n/10.0)*(d.x + 590);
        A.y = (1 - n/10.0)*(a.y) + (n/10.0)*(d.y);
        B.x = (1 - n/10.0)*(b.x + 590) + (n/10.0)*(e.x + 590);
        B.y = (1 - n/10.0)*(b.y) + (n/10.0)*(e.y);
        C.x = (1 - n/10.0)*(c.x + 590) + (n/10.0)*(f.x + 590);
        C.y = (1 - n/10.0)*(c.y) + (n/10.0)*(f.y);
        wielokat2.push_back(A);
        wielokat2.push_back(B);
        wielokat2.push_back(C);
        int wys = img->height();
        int szer = img->width();
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
                        if (alfa >= 0  && beta >= 0 && beta < 1 && gamma >= 0 && gamma < 1)
                        {
                            //SOWA
                            double x1 = alfa * a.x + beta * b.x + gamma * c.x;
                            double y1 = alfa * a.y + beta * b.y + gamma * c.y;



                            //teksturuje troajkat z sowy do pqr
                            if (x1 >= 0 && x1 < szer && y1 >= 0 && y1 < wys)
                            {
                                int r2 = InterpolacjaDwuliniowa(x1,y1,0).r;
                                int g2 = InterpolacjaDwuliniowa(x1,y1,0).g;
                                int b2 = InterpolacjaDwuliniowa(x1,y1,0).b;
                                wstawPiksel(x, y, r2, g2, b2, 3);
                            }
                            //TYGRYS
                            double x2 = alfa * d.x + beta * e.x + gamma * f.x;
                            double y2 = alfa * d.y + beta * e.y + gamma * f.y;
                            //teksturuje troajkat z tygrysa do PQR
                            if (x2 >= 0 && x2 < szer && y2 >= 0 && y2 < wys)
                            {
                                int r3 = InterpolacjaDwuliniowa(x2,y2,1).r;
                                int g3 = InterpolacjaDwuliniowa(x2,y2,1).g;
                                int b3 = InterpolacjaDwuliniowa(x2,y2,1).b;
                                wstawPiksel(x, y, r3, g3, b3, 4);
                            }


                            int r2 = miksuj(x,y).r;
                            int g2 = miksuj(x,y).g;
                            int b2 = miksuj(x,y).b;
                            wstawPiksel(x, y, r2, g2, b2, 1);

                        }
                    }
                }
                przeciecia2.clear();
            }
        }
    }
    update();
}

// Funkcja do interpolacji dwuliniowej
Color MainWindow::InterpolacjaDwuliniowa( double x, double y,int obraz) {
    unsigned char *img;
    if(obraz == 0)
    {
        img = orginal->bits();//sowa
    }
    else img = Orginal->bits();//tygrys

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
Color MainWindow::miksuj( int x, int y) {
    unsigned char *ptr, *PTR;
    ptr = pqr->bits();
    PTR = PQR->bits();
    int szer = PQR->width();

        // Pobierz kolory pikseli pqr (sowy)
        Color c;
        c.r = ptr[szer*4*(y-10) + 4*(x-600)];
        c.g = ptr[szer*4*(y-10) + 4*(x-600) + 1];
        c.b = ptr[szer*4*(y-10) + 4*(x-600) + 2];

        // Pobierz kolory pikseli pqr (tygrysa)
        Color k;
        k.r = PTR[szer*4*(y-10) + 4*(x-600)];
        k.g = PTR[szer*4*(y-10) + 4*(x-600) + 1];
        k.b = PTR[szer*4*(y-10) + 4*(x-600) + 2];


        // teraz miksowanie
        Color K;
        K.r = (1 - n/10.0)*c.r + (n/10.0)*k.r;
        K.g = (1 - n/10.0)*c.g + (n/10.0)*k.g;
        K.b = (1 - n/10.0)*c.b + (n/10.0)*k.b;

        return K;
}


void MainWindow::on_sowa_clicked()
{
    obraz = 0;
    update();
}


void MainWindow::on_tygrys_clicked()
{
    obraz = 1;
    update();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    n=static_cast<double>(value);
    //std::cout<<n;
    teksturowanie();
    update();
}

