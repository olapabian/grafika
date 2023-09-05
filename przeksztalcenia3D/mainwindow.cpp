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

    img = new QImage(500, 500, QImage::Format_RGB32);
    img2 = new QImage(500, 500, QImage::Format_RGB32);
    przesuniecie =new  macierz(4,4);
    wynik = new macierz(4,4);
    rotacja =     new  macierz(4,4);
    skalowanie =  new  macierz(4,4);
    pochylenie =  new  macierz(4,4);
    powrot=       new  macierz(4,4);
    translacja=   new  macierz(4,4);    
    rysujSzescian();
}


MainWindow::~MainWindow()
{
    Wierzcholki.clear();
    Krawedzie.clear();
    NoweWierzcholki.clear();
    delete wynik;
    delete  przesuniecie;// rotacja,skalowanie, pochylenie, powrot, translacja;
    delete ui;
    delete img;
    delete img2;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0, 0, *img2);
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
        if ((x>=0)&&(y>=0)&&(x<szer)&&(y<wys))
        {
            ptr[szer*4*(y) + 4*(x)] = r; // Składowa BLUE
            ptr[szer*4*(y) + 4*(x) + 1] = g; // Składowa GREEN
            ptr[szer*4*(y) + 4*(x) + 2] = b; // Składowa RED
        }
    }
    else
    {
        ptr = img2->bits();
        szer = img2->width();
        wys = img2->height();
        if (((x)>=0)&&((y)>=0)&&((x)<szer)&&((y)<wys))
        {
            ptr[szer*4*(y) + 4*(x)] = r; // Składowa BLUE
            ptr[szer*4*(y) + 4*(x) + 1] = g; // Składowa GREEN
            ptr[szer*4*(y) + 4*(x) + 2] = b; // Składowa RED
        }
    }

    update();
}


void MainWindow::rysujSzescian2()
{
    czysc2();
    kreska2(Krawedzie[0].a.X,Krawedzie[0].a.Y,Krawedzie[0].b.X,Krawedzie[0].b.Y,1);
    kreska2(Krawedzie[1].a.X,Krawedzie[1].a.Y,Krawedzie[1].b.X,Krawedzie[1].b.Y,1);
    kreska2(Krawedzie[2].a.X,Krawedzie[2].a.Y,Krawedzie[2].b.X,Krawedzie[2].b.Y,1);
    kreska2(Krawedzie[3].a.X,Krawedzie[3].a.Y,Krawedzie[3].b.X,Krawedzie[3].b.Y,1);
    kreska2(Krawedzie[4].a.X,Krawedzie[4].a.Y,Krawedzie[4].b.X,Krawedzie[4].b.Y,1);
    kreska2(Krawedzie[5].a.X,Krawedzie[5].a.Y,Krawedzie[5].b.X,Krawedzie[5].b.Y,1);
    kreska2(Krawedzie[6].a.X,Krawedzie[6].a.Y,Krawedzie[6].b.X,Krawedzie[6].b.Y,1);
    kreska2(Krawedzie[7].a.X,Krawedzie[7].a.Y,Krawedzie[7].b.X,Krawedzie[7].b.Y,1);
    kreska2(Krawedzie[8].a.X,Krawedzie[8].a.Y,Krawedzie[8].b.X,Krawedzie[8].b.Y,1);
    kreska2(Krawedzie[9].a.X,Krawedzie[9].a.Y,Krawedzie[9].b.X,Krawedzie[9].b.Y,1);
    kreska2(Krawedzie[10].a.X,Krawedzie[10].a.Y,Krawedzie[10].b.X,Krawedzie[10].b.Y,1);
    kreska2(Krawedzie[11].a.X,Krawedzie[11].a.Y,Krawedzie[11].b.X,Krawedzie[11].b.Y,1);
    update();
}
void MainWindow::rysujSzescian()
{
    point p;
    p.x=200;
    p.y=200;
    p.z=0;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    p.x=200;
    p.y=300;
    p.z=0;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    p.x=300;
    p.y=200;
    p.z=0;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    p.x=300;
    p.y=300;
    p.z=0;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    krawedz k;
    k.a=Wierzcholki[0];
    k.b=Wierzcholki[1];
    Krawedzie.push_back(k);

    k.a=Wierzcholki[0];
    k.b=Wierzcholki[2];
    Krawedzie.push_back(k);

    k.a=Wierzcholki[2];
    k.b=Wierzcholki[3];
    Krawedzie.push_back(k);

    k.a=Wierzcholki[1];
    k.b=Wierzcholki[3];
    Krawedzie.push_back(k);
    //rysowanie kwadratu
    kreska2(Krawedzie[0].a.X,Krawedzie[0].a.Y,Krawedzie[0].b.X,Krawedzie[0].b.Y,1);
    kreska2(Krawedzie[1].a.X,Krawedzie[1].a.Y,Krawedzie[1].b.X,Krawedzie[1].b.Y,1);
    kreska2(Krawedzie[2].a.X,Krawedzie[2].a.Y,Krawedzie[2].b.X,Krawedzie[2].b.Y,1);
    kreska2(Krawedzie[3].a.X,Krawedzie[3].a.Y,Krawedzie[3].b.X,Krawedzie[3].b.Y,1);

    //wierzchloek perspektywiczny dla wierzcholka 0
    p.x=Wierzcholki[0].x;
    p.y=Wierzcholki[0].y;
    p.z=Wierzcholki[0].z+2;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[0];
    k.b=Wierzcholki[4];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[4].a.X,Krawedzie[4].a.Y,Krawedzie[4].b.X,Krawedzie[4].b.Y,1);


    //wierzchloek perspektywiczny dla wierzcholka 1
    p.x=Wierzcholki[1].x;
    p.y=Wierzcholki[1].y;
    p.z=Wierzcholki[1].z+2;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[1];
    k.b=Wierzcholki[5];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[5].a.X,Krawedzie[5].a.Y,Krawedzie[5].b.X,Krawedzie[5].b.Y,1);

    //wierzchloek perspektywiczny dla wierzcholka 2
    p.x=Wierzcholki[2].x;
    p.y=Wierzcholki[2].y;
    p.z=Wierzcholki[2].z+2;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[2];
    k.b=Wierzcholki[6];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[6].a.X,Krawedzie[6].a.Y,Krawedzie[6].b.X,Krawedzie[6].b.Y,1);

    //wierzchloek perspektywiczny dla wierzcholka 3
    p.x=Wierzcholki[3].x;
    p.y=Wierzcholki[3].y;
    p.z=Wierzcholki[3].z+2;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[3];
    k.b=Wierzcholki[7];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[7].a.X,Krawedzie[7].a.Y,Krawedzie[7].b.X,Krawedzie[7].b.Y,1);

    //teraz laczenie wierzcholkow z tylu
    k.a=Wierzcholki[4];
    k.b=Wierzcholki[5];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[8].a.X,Krawedzie[8].a.Y,Krawedzie[8].b.X,Krawedzie[8].b.Y,1);

    k.a=Wierzcholki[5];
    k.b=Wierzcholki[7];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[9].a.X,Krawedzie[9].a.Y,Krawedzie[9].b.X,Krawedzie[9].b.Y,1);

    k.a=Wierzcholki[4];
    k.b=Wierzcholki[6];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[10].a.X,Krawedzie[10].a.Y,Krawedzie[10].b.X,Krawedzie[10].b.Y,1);

    k.a=Wierzcholki[6];
    k.b=Wierzcholki[7];
    Krawedzie.push_back(k);
    kreska2(Krawedzie[11].a.X,Krawedzie[11].a.Y,Krawedzie[11].b.X,Krawedzie[11].b.Y,1);

    update();
}
macierz* MainWindow::stworzMacierze()
{

////////////////////przesuniecie/////////////////////////////
    przesuniecie->addValue(static_cast<double>(ui->LewoPrawo->value()-250),3);
    przesuniecie->addValue(static_cast<double>(ui->GoraDol->value()-250),7);
    przesuniecie->addValue(static_cast<double>(ui->PrzodTyl->value()),11);

///////////////////rotacja////////////////////////////

//    // do powrot na dobre miejsce

//    powrot->addValue(272,2);
//    powrot->addValue(338,5);



//    //rotacja wzgl 0 0
//    rotacja->addValue(std::cos(ui->Rotacja->value()*M_PI/180.0),0);    rotacja->addValue(-std::sin(ui->Rotacja->value()*M_PI/180.0),1);
//    rotacja->addValue(std::sin(ui->Rotacja->value()*M_PI/180.0),3);    rotacja->addValue(std::cos(ui->Rotacja->value()*M_PI/180.0),4);



//    // do translacja do rogu
//    translacja->addValue(-272,2);
//    translacja->addValue(-338,5);



/////////////////////skalowanie////////////////////////////

//    //skalowanie wzgledem 0 0
//    skalowanie->addValue(ui->Skalownie->value()/100.0,0);
//    skalowanie->addValue(ui->Skalowanie2->value()/100.0,4);


/////////////////////////pochylenie//////////////////////////


//    //pochylenie
//    pochylenie->addValue(ui->horizontalSlider_6->value()/100.0,1);
//    pochylenie->addValue(ui->horizontalSlider_7->value()/100.0,3);


/////////////////////////////////////////////////
//    macierz *wynik = przesuniecie->pomnoz(3,3,powrot->pomnoz(3,3,rotacja->pomnoz(3,3,translacja->pomnoz(3,3,powrot->pomnoz(3,3,skalowanie->pomnoz(3,3,translacja->pomnoz(3,3,powrot->pomnoz(3,3,pochylenie->pomnoz(3,3,translacja)))))))));
    wynik = przesuniecie->pomnoz(4,4,pochylenie);
    return wynik;
}
void MainWindow::przesun()
{

    macierz *m = stworzMacierze();//4x4
    //pozamieniam  punkty wierzcholki krawedzi i narysuje szescian
    macierz *p = new macierz(4,1);
    macierz *wynik2;
    for(int i=0;i<8;++i)//iteruje po wierzchokach
    {
        p->addValue(static_cast<double>(Wierzcholki[i].x),0);
        p->addValue(static_cast<double>(Wierzcholki[i].y),1);
        p->addValue(static_cast<double>(Wierzcholki[i].z),2);
        p->addValue(1,3);
//        p->wypisz();
        wynik2 = m->pomnoz(4,1,p);

        NoweWierzcholki[i].z=wynik2->tab[2];
        NoweWierzcholki[i].x=wynik2->tab[0];
        NoweWierzcholki[i].y=wynik2->tab[1];

        NoweWierzcholki[i].X=wynik2->tab[0]*d/(NoweWierzcholki[i].z+d);
        NoweWierzcholki[i].Y=wynik2->tab[1]*d/(NoweWierzcholki[i].z+d);
    }
    //przykorzadkowac nowe wierzcholki do krawedzi
    Krawedzie[0].a=NoweWierzcholki[0];
    Krawedzie[0].b=NoweWierzcholki[1];
    Krawedzie[1].a=NoweWierzcholki[0];
    Krawedzie[1].b=NoweWierzcholki[2];
    Krawedzie[2].a=NoweWierzcholki[2];
    Krawedzie[2].b=NoweWierzcholki[3];
    Krawedzie[3].a=NoweWierzcholki[1];
    Krawedzie[3].b=NoweWierzcholki[3];
    Krawedzie[4].a=NoweWierzcholki[0];
    Krawedzie[4].b=NoweWierzcholki[4];
    Krawedzie[5].a=NoweWierzcholki[1];
    Krawedzie[5].b=NoweWierzcholki[5];
    Krawedzie[6].a=NoweWierzcholki[2];
    Krawedzie[6].b=NoweWierzcholki[6];
    Krawedzie[7].a=NoweWierzcholki[3];
    Krawedzie[7].b=NoweWierzcholki[7];
    Krawedzie[8].a=NoweWierzcholki[4];
    Krawedzie[8].b=NoweWierzcholki[5];
    Krawedzie[9].a=NoweWierzcholki[5];
    Krawedzie[9].b=NoweWierzcholki[7];
    Krawedzie[10].a=NoweWierzcholki[4];
    Krawedzie[10].b=NoweWierzcholki[6];
    Krawedzie[11].a=NoweWierzcholki[6];
    Krawedzie[11].b=NoweWierzcholki[7];
    rysujSzescian2();
    delete wynik2,p,m;
    repaint();
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


void MainWindow::on_LewoPrawo_valueChanged(int value)
{

    przesun();
}


void MainWindow::on_GoraDol_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_PrzodTyl_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_RotacjaX_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_RotacjY_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_RotacjaZ_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_SkalownieX_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_Skalowanie2_valueChanged(int value)
{
    przesun();
}


void MainWindow::on_SkalowanieZ_valueChanged(int value)
{
    przesun();
}

