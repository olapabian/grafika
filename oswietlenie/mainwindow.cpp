#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <cmath>
#include "macierz.h"
#include "macierz.cpp"
#include <math.h>
#include <cstdlib>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    img = new QImage(500, 500, QImage::Format_RGB32);
    img2 = new QImage(500, 500, QImage::Format_RGB32);
    przesuniecie =new  macierz(4,4);
    wynik = new macierz(4,4);
    rotacjaX =     new  macierz(4,4);
    rotacjaY =     new  macierz(4,4);
    rotacjaZ =     new  macierz(4,4);
    skalowanie =  new  macierz(4,4);
    pochylenie =  new  macierz(4,4);
    powrot=       new  macierz(4,4);
    powrotX=       new  macierz(4,4);
    powrotY=       new  macierz(4,4);
    translacja=   new  macierz(4,4);
    translacjaX=   new  macierz(4,4);
    translacjaY=   new  macierz(4,4);
    Bufor = new macierz(500,500);
    rysujSzescian();
}


MainWindow::~MainWindow()
{
    Wierzcholki.clear();
    Krawedzie.clear();
    NoweWierzcholki.clear();
    Sciany.clear();
    delete Bufor;
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
void MainWindow::widoczneSciany(){


    for(int i = 0; i < 6; i++){
        float w1[3] = {(float)Sciany[i].Punkty[1].x - (float)Sciany[i].Punkty[0].x, (float)Sciany[i].Punkty[1].y - (float)Sciany[i].Punkty[0].y, (float)Sciany[i].Punkty[1].z - (float)Sciany[i].Punkty[0].z};
        float w2[3] = {(float)Sciany[i].Punkty[3].x - (float)Sciany[i].Punkty[0].x, (float)Sciany[i].Punkty[3].y - (float)Sciany[i].Punkty[0].y, (float)Sciany[i].Punkty[3].z - (float)Sciany[i].Punkty[0].z};

            //wektor prostopadly do tej sciany liczymy iloczyn wektorowy dwoch powyzszych
        float wSciany[3] = {w2[1] * w1[2] - (w1[1] * w2[2]),
                            w2[2] * w1[0] - (w1[2] * w2[0]),
                            w2[0] * w1[1] - (w1[0] * w2[1])};

        float wObserwatora[3] = { (float)Sciany[i].Punkty[0].x - 0,
                                  (float)Sciany[i].Punkty[0].y - 0,
                                  (float)Sciany[i].Punkty[0].z + d};

        float iloczynSkalarny = (wSciany[0] * wObserwatora[0]) + (wSciany[1] * wObserwatora[1]) + (wSciany[2] * wObserwatora[2]);

        if(iloczynSkalarny > 0){
            WidoczneSciany.push_back(Sciany[i]);
        }
    }
}

void MainWindow::rysujSzescian2()
{
    czysc2();
    if(!ch)
    {
        for(int i=0;i<Krawedzie.size();++i)
        {
            kreska2(Krawedzie[i].a.X,Krawedzie[i].a.Y,Krawedzie[i].b.X,Krawedzie[i].b.Y,1);
        }
    }
    else
    {
        rysujPoScianach();
//        int minZ,maxZ,minX,maxX,minY,maxY;
//        for(int y=0; y<500; ++y)
//        {
//            for(int x = 0; x<500; ++x)
//            {
//                Bufor->addValue(1000,y*500 + x);
//            }
//        }
//        for(int i=0;i<Krawedzie.size();++i)
//        {
//            minZ=std::min(Krawedzie[i].a.z,Krawedzie[i].b.z) ;
//            maxZ=std::max(Krawedzie[i].a.z,Krawedzie[i].b.z);
//            minX=std::min(Krawedzie[i].a.X,Krawedzie[i].b.X) ;
//            maxX=std::max(Krawedzie[i].a.X,Krawedzie[i].b.X);
//            minY=std::min(Krawedzie[i].a.Y,Krawedzie[i].b.Y) ;
//            maxY=std::max(Krawedzie[i].a.Y,Krawedzie[i].b.Y);
//            int x = Krawedzie[i].a.X;
//            int y = Krawedzie[i].a.Y;
//            kreskaBufor(maxX,maxY,minX,minY,minZ,maxZ);

//        }
//        for(int i=0;i<Sciany.size();++i)
//        {
//            for(int j=0;j<Sciany[i].Punkty.size();++j)
//            {
//                int z = Sciany[i].Punkty[j].z;
//                int x = Sciany[i].Punkty[j].X;
//                int y = Sciany[i].Punkty[j].Y;
//                wstawPiksel(x,y,255,0,0,1);
//                //                rysujPoScianach();
//                if(z<Bufor.tab[y*500 + x])
//                {
//                    Bufor.addValue(z,y*500 + x);
//                }
//            }
//        }
    }
    WidoczneSciany.clear();
    Sciany.clear();
    repaint();
}
void MainWindow::rysujPoScianach()
{
    for(int i=0;i<WidoczneSciany.size();++i)
    {
        for(int j=0;j<WidoczneSciany[i].Krawedzie.size();++j)
        {
            kreska2(WidoczneSciany[i].Krawedzie[j].a.X,WidoczneSciany[i].Krawedzie[j].a.Y,WidoczneSciany[i].Krawedzie[j].b.X,WidoczneSciany[i].Krawedzie[j].b.Y,1);
        }
    }
}
void MainWindow::rysujSzescian()
{
    point p;
    p.x=200;
    p.y=200;
    p.z=1;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    p.x=200;
    p.y=300;
    p.z=1;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    p.x=300;
    p.y=200;
    p.z=1;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    p.x=300;
    p.y=300;
    p.z=1;
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


    //wierzchloek perspektywiczny dla wierzcholka 0
    p.x=Wierzcholki[0].x;
    p.y=Wierzcholki[0].y;
    p.z=-Wierzcholki[0].z;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[0];
    k.b=Wierzcholki[4];
    Krawedzie.push_back(k);



    //wierzchloek perspektywiczny dla wierzcholka 1
    p.x=Wierzcholki[1].x;
    p.y=Wierzcholki[1].y;
    p.z=-Wierzcholki[1].z;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[1];
    k.b=Wierzcholki[5];
    Krawedzie.push_back(k);


    //wierzchloek perspektywiczny dla wierzcholka 2
    p.x=Wierzcholki[2].x;
    p.y=Wierzcholki[2].y;
    p.z=-Wierzcholki[2].z;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[2];
    k.b=Wierzcholki[6];
    Krawedzie.push_back(k);


    //wierzchloek perspektywiczny dla wierzcholka 3
    p.x=Wierzcholki[3].x;
    p.y=Wierzcholki[3].y;
    p.z=-Wierzcholki[3].z;
    p.X=p.x*d/(p.z+d);
    p.Y=p.y*d/(p.z+d);
    Wierzcholki.push_back(p);
    NoweWierzcholki.push_back(p);

    k.a=Wierzcholki[3];
    k.b=Wierzcholki[7];
    Krawedzie.push_back(k);

//    kreska2(Krawedzie[7].a.X,Krawedzie[7].a.Y,Krawedzie[7].b.X,Krawedzie[7].b.Y,1);

    //teraz laczenie wierzcholkow z tylu
    k.a=Wierzcholki[4];
    k.b=Wierzcholki[5];
    Krawedzie.push_back(k);

    kreska2(Krawedzie[8].a.X,Krawedzie[8].a.Y,Krawedzie[8].b.X,Krawedzie[8].b.Y,1);

    k.a=Wierzcholki[5];
    k.b=Wierzcholki[7];
    Krawedzie.push_back(k);


    k.a=Wierzcholki[4];
    k.b=Wierzcholki[6];
    Krawedzie.push_back(k);

    kreska2(Krawedzie[10].a.X,Krawedzie[10].a.Y,Krawedzie[10].b.X,Krawedzie[10].b.Y,1);

    k.a=Wierzcholki[6];
    k.b=Wierzcholki[7];
    Krawedzie.push_back(k);


    rysujSzescian2();
    update();
}
macierz* MainWindow::stworzMacierze()
{

////////////////////przesuniecie/////////////////////////////
    przesuniecie->addValue(static_cast<double>(ui->LewoPrawo->value()-250),3);
    przesuniecie->addValue(static_cast<double>(ui->GoraDol->value()-250),7);
    przesuniecie->addValue(static_cast<double>(ui->PrzodTyl->value()),11);

///////////////////rotacjaX////////////////////////////



    //rotacja wzgl 0 0
    rotacjaX->addValue(std::cos(ui->RotacjaX->value()*M_PI/180.0),5);    rotacjaX->addValue((-1)*std::sin(ui->RotacjaX->value()*M_PI/180.0),6);
    rotacjaX->addValue(std::sin(ui->RotacjaX->value()*M_PI/180.0),9);    rotacjaX->addValue(std::cos(ui->RotacjaX->value()*M_PI/180.0),10);



///////////////////rotacjaY////////////////////////////




    rotacjaY->addValue(std::cos(ui->RotacjaY->value()*M_PI/180.0),0);    rotacjaY->addValue(-std::sin(ui->RotacjaY->value()*M_PI/180.0),8);
    rotacjaY->addValue(std::sin(ui->RotacjaY->value()*M_PI/180.0),2);    rotacjaY->addValue( std::cos(ui->RotacjaY->value()*M_PI/180.0),10);




    ///////////////////rotacjaZ////////////////////////////

    powrot->addValue(250,3);//przesuwam sie po x i y
    powrot->addValue(250,7);

    rotacjaZ->addValue(std::cos(ui->RotacjaZ->value()*M_PI/180.0),0);    rotacjaZ->addValue(-std::sin(ui->RotacjaZ->value()*M_PI/180.0),1);
    rotacjaZ->addValue(std::sin(ui->RotacjaZ->value()*M_PI/180.0),4);    rotacjaZ->addValue( std::cos(ui->RotacjaZ->value()*M_PI/180.0),5);

    translacja->addValue(-250,3);
    translacja->addValue(-250,7);


/////////////////////skalowanie////////////////////////////

    skalowanie->addValue(ui->SkalownieX->value()/100.0,0);
    skalowanie->addValue(ui->Skalowanie2->value()/100.0,5);
    skalowanie->addValue(ui->SkalowanieZ->value(),10);




/////////////////////////////////////////////////
    wynik = przesuniecie->pomnoz(4,4,powrot->pomnoz(4,4,rotacjaX->pomnoz(4,4,translacja->pomnoz(4,4,powrot->pomnoz(4,4,rotacjaY->pomnoz(4,4,translacja->pomnoz(4,4,powrot->pomnoz(4,4,rotacjaZ->pomnoz(4,4,translacja->pomnoz(4,4,powrot->pomnoz(4,4,skalowanie->pomnoz(4,4,translacja))))))))))));
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

        wynik2 = m->pomnoz(4,1,p);

        NoweWierzcholki[i].z=wynik2->tab[2];
//        std::cout<<NoweWierzcholki[i].z<<std::endl;
        NoweWierzcholki[i].x=wynik2->tab[0];
        NoweWierzcholki[i].y=wynik2->tab[1];

        NoweWierzcholki[i].X=wynik2->tab[0]*d/(NoweWierzcholki[i].z+d);
        NoweWierzcholki[i].Y=wynik2->tab[1]*d/(NoweWierzcholki[i].z+d);
    }
    //przykorzadkowac nowe wierzcholki do krawedzi
    Krawedzie[0].a=NoweWierzcholki[1];
    Krawedzie[0].b=NoweWierzcholki[0];
    Krawedzie[1].a=NoweWierzcholki[0];
    Krawedzie[1].b=NoweWierzcholki[2];
    Krawedzie[2].a=NoweWierzcholki[2];
    Krawedzie[2].b=NoweWierzcholki[3];
    Krawedzie[3].a=NoweWierzcholki[3];
    Krawedzie[3].b=NoweWierzcholki[1];

    Krawedzie[4].a=NoweWierzcholki[4];
    Krawedzie[4].b=NoweWierzcholki[0];
    Krawedzie[5].a=NoweWierzcholki[1];
    Krawedzie[5].b=NoweWierzcholki[5];
    Krawedzie[6].a=NoweWierzcholki[2];
    Krawedzie[6].b=NoweWierzcholki[6];
    Krawedzie[7].a=NoweWierzcholki[7];
    Krawedzie[7].b=NoweWierzcholki[3];

    Krawedzie[8].a=NoweWierzcholki[5];
    Krawedzie[8].b=NoweWierzcholki[4];
    Krawedzie[9].a=NoweWierzcholki[5];
    Krawedzie[9].b=NoweWierzcholki[7];
    Krawedzie[10].a=NoweWierzcholki[6];
    Krawedzie[10].b=NoweWierzcholki[4];
    Krawedzie[11].a=NoweWierzcholki[6];
    Krawedzie[11].b=NoweWierzcholki[7];

    sciana S0(Krawedzie[0],Krawedzie[1],Krawedzie[2],Krawedzie[3],d,NoweWierzcholki[0],NoweWierzcholki[2],NoweWierzcholki[3],NoweWierzcholki[1]);
    Sciany.push_back(S0);

    sciana S1(Krawedzie[11],Krawedzie[6],Krawedzie[2],Krawedzie[7],d,NoweWierzcholki[2],NoweWierzcholki[6],NoweWierzcholki[7],NoweWierzcholki[3]);
    Sciany.push_back(S1);

    sciana S2(Krawedzie[8],Krawedzie[9],Krawedzie[11],Krawedzie[10],d,NoweWierzcholki[6],NoweWierzcholki[4],NoweWierzcholki[5],NoweWierzcholki[7]);
    Sciany.push_back(S2);

    sciana S3(Krawedzie[8],Krawedzie[5],Krawedzie[0],Krawedzie[4],d,NoweWierzcholki[4],NoweWierzcholki[0],NoweWierzcholki[1],NoweWierzcholki[5]);
    Sciany.push_back(S3);

    sciana S4(Krawedzie[5],Krawedzie[3],Krawedzie[7],Krawedzie[9],d,NoweWierzcholki[1],NoweWierzcholki[3],NoweWierzcholki[7],NoweWierzcholki[5]);
    Sciany.push_back(S4);

    sciana S5(Krawedzie[4],Krawedzie[1],Krawedzie[6],Krawedzie[10],d,NoweWierzcholki[4],NoweWierzcholki[6],NoweWierzcholki[2],NoweWierzcholki[0]);
    Sciany.push_back(S5);
    widoczneSciany();
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
void MainWindow::kreskaBufor(int finX,int finY,int sX, int sY,int minZ,int maxZ) //obrazek 0 - pierszy 1 - drugi
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
                    for(int z=minZ;z<maxZ;z++)
                    {
                    if(z<Bufor->tab[y*500 + x])
                    {
                        wstawPiksel((int)floor(x+0.5),y,255,0,0,1);
                        Bufor->addValue(z,y*500 + x);
                    }
                    }
                }
            }
            else
            {
                for(int y=finY;y<=sY;++y)
                {
                    for(int z=minZ;z<maxZ;z++)
                    {
                    if(z<Bufor->tab[y*500 + x])
                    {
                        wstawPiksel((int)floor(x+0.5),y,255,0,0,1);
                        Bufor->addValue(z,y*500 + x);
                    }
                    }
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
                        for(int z=minZ;z<maxZ;z++)
                        {
                        if(z<Bufor->tab[y*500 + x])
                        {
                            wstawPiksel(x,(int)floor(y+0.5),255,0,0,1);
                            Bufor->addValue(z,y*500 + x);
                        }
                        }
                    }
                }
                else
                {
                    for(int x=sX;x<=finX;++x)
                    {

                        y=a*x+b;
                        for(int z=minZ;z<maxZ;z++)
                        {
                        if(z<Bufor->tab[y*500 + x])
                        {
                            wstawPiksel(x,(int)floor(y+0.5),255,0,0,1);
                            Bufor->addValue(z,y*500 + x);
                        }
                        }
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
                        for(int z=minZ;z<maxZ;z++)
                        {
                        if(z<Bufor->tab[y*500 + x])
                        {
                            wstawPiksel((int)floor(x+0.5),y,255,0,0,1);
                            Bufor->addValue(z,y*500 + x);
                        }
                        }
                    }
                }
                else
                {
                    for(int y=finY;y<=sY;++y)
                    {
                        x=(y-b)/a;
                        for(int z=minZ;z<maxZ;z++)
                        {
                        if(z<Bufor->tab[y*500 + x])
                        {
                            wstawPiksel((int)floor(x+0.5),y,255,0,0,1);
                            Bufor->addValue(z,y*500 + x);
                        }
                        }
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


void MainWindow::on_RotacjaY_valueChanged(int value)
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



void MainWindow::on_Widoczne_clicked(bool checked)
{
    ch=true;
    przesun();
}


void MainWindow::on_Wszystkie_clicked()
{
    ch=false;
    przesun();
}

