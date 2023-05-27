#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"
#include <QPainter>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img = new QImage("C:/Users/User/Desktop/grafika/morfologia/mis.png");
    view=img;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0,0,*view);

}
bool MainWindow::czyKolor(int x, int y,int w) //czy ktorykolwiek sasiad piksela jest czarny lub bialy w zaleznosci od w 0-czarny 1-bialy
{
    unsigned char *ptr = img->bits();
    if(y<1 && x<1)
    {
        if(ptr[szer*4*(y+1) + 4*x]==w && ptr[szer*4*(y+1) + 4*x + 1] == w && ptr[szer*4*(y+1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x+1)]==w && ptr[szer*4*(y) + 4*(x+1) + 1] == w && ptr[szer*4*(y) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*(x+1)]==w && ptr[szer*4*(y+1) + 4*(x+1) + 1] == w && ptr[szer*4*(y+1) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        return false;
    }
    else if(y<1)
    {
        if(ptr[szer*4*(y+1) + 4*x]==w && ptr[szer*4*(y+1) + 4*x + 1] == w && ptr[szer*4*(y+1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x-1)]==w && ptr[szer*4*(y) + 4*(x-1) + 1] == w && ptr[szer*4*(y) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x+1)]==w && ptr[szer*4*(y) + 4*(x+1) + 1] == w && ptr[szer*4*(y) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*(x-1)]==w && ptr[szer*4*(y+1) + 4*(x-1) + 1] == w && ptr[szer*4*(y+1) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*(x+1)]==w && ptr[szer*4*(y+1) + 4*(x+1) + 1] == w && ptr[szer*4*(y+1) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        return false;
    }
    else if(x<1)
    {
        if(ptr[szer*4*(y-1) + 4*x]==w && ptr[szer*4*(y-1) + 4*x + 1] == w && ptr[szer*4*(y-1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*x]==w && ptr[szer*4*(y+1) + 4*x + 1] == w && ptr[szer*4*(y+1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x+1)]==w && ptr[szer*4*(y) + 4*(x+1) + 1] == w && ptr[szer*4*(y) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y-1) + 4*(x+1)]==w && ptr[szer*4*(y-1) + 4*(x+1) + 1] == w && ptr[szer*4*(y-1) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*(x+1)]==w && ptr[szer*4*(y+1) + 4*(x+1) + 1] == w && ptr[szer*4*(y+1) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        return false;
    }
    else if(x>=szer-1 && y>wys-1)
    {
        //bez x+1 I BEZ Y+1
        if(ptr[szer*4*(y-1) + 4*x]==w && ptr[szer*4*(y-1) + 4*x + 1] == w && ptr[szer*4*(y-1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y-1) + 4*(x-1)]==w && ptr[szer*4*(y-1) + 4*(x-1) + 1] == w && ptr[szer*4*(y-1) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x-1)]==w && ptr[szer*4*(y) + 4*(x-1) + 1] == w && ptr[szer*4*(y) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarn
        return false;
    }
    else if(y>wys-2)
    {
        //BEZ Y+1
        if(ptr[szer*4*(y-1) + 4*x]==w && ptr[szer*4*(y-1) + 4*x + 1] == w && ptr[szer*4*(y-1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y-1) + 4*(x-1)]==w && ptr[szer*4*(y-1) + 4*(x-1) + 1] == w && ptr[szer*4*(y-1) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x-1)]==w && ptr[szer*4*(y) + 4*(x-1) + 1] == w && ptr[szer*4*(y) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x+1)]==w && ptr[szer*4*(y) + 4*(x+1) + 1] == w && ptr[szer*4*(y) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y-1) + 4*(x+1)]==w && ptr[szer*4*(y-1) + 4*(x+1) + 1] == w && ptr[szer*4*(y-1) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        return false;
    }
    else if(x>=szer-2)
    {
        //bez x+1
        if(ptr[szer*4*(y-1) + 4*x]==w && ptr[szer*4*(y-1) + 4*x + 1] == w && ptr[szer*4*(y-1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y-1) + 4*(x-1)]==w && ptr[szer*4*(y-1) + 4*(x-1) + 1] == w && ptr[szer*4*(y-1) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*x]==w && ptr[szer*4*(y+1) + 4*x + 1] == w && ptr[szer*4*(y+1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x-1)]==w && ptr[szer*4*(y) + 4*(x-1) + 1] == w && ptr[szer*4*(y) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*(x-1)]==w && ptr[szer*4*(y+1) + 4*(x-1) + 1] == w && ptr[szer*4*(y+1) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        return false;
    }
    else
    {
        if(ptr[szer*4*(y-1) + 4*x]==w && ptr[szer*4*(y-1) + 4*x + 1] == w && ptr[szer*4*(y-1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y-1) + 4*(x-1)]==w && ptr[szer*4*(y-1) + 4*(x-1) + 1] == w && ptr[szer*4*(y-1) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*x]==w && ptr[szer*4*(y+1) + 4*x + 1] == w && ptr[szer*4*(y+1) + 4*x + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x-1)]==w && ptr[szer*4*(y) + 4*(x-1) + 1] == w && ptr[szer*4*(y) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y) + 4*(x+1)]==w && ptr[szer*4*(y) + 4*(x+1) + 1] == w && ptr[szer*4*(y) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*(x-1)]==w && ptr[szer*4*(y+1) + 4*(x-1) + 1] == w && ptr[szer*4*(y+1) + 4*(x-1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y-1) + 4*(x+1)]==w && ptr[szer*4*(y-1) + 4*(x+1) + 1] == w && ptr[szer*4*(y-1) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        if(ptr[szer*4*(y+1) + 4*(x+1)]==w && ptr[szer*4*(y+1) + 4*(x+1) + 1] == w && ptr[szer*4*(y+1) + 4*(x+1) + 2] == w) return true; //jesli sasiad jest czarny
        return false;
    }
}

void MainWindow::zmiana()
{   
    unsigned char *obraz=img->bits();
    unsigned char *wynik=view->bits();
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            if(tryb==1)
            {               
                //erozja
                if(obraz[szer*4*y+4*x]==0 && obraz[szer*4*y+4*x+1]==0 && obraz[szer*4*y+4*x+2]==0)//jezeli piksel jest czarny
                {
                    if(czyKolor(x,y,255))//jesli sasiedzi sa biali jakikolwiek
                    {
                        wynik[szer*4*y+4*x]=255;//zapalam na niebiesko
                        wynik[szer*4*y+4*x+1]=0;
                        wynik[szer*4*y+4*x+2]=0;
                    }
                }
            }
            else if(tryb==2)
            {
                //dylacja
                if(obraz[szer*4*y+4*x]==255 && obraz[szer*4*y+4*x+1]==255 && obraz[szer*4*y+4*x+2]==255) //jesli jest bialy (tlo)
                {
                    if(czyKolor(x,y,0))//jesli sasiedzi sa czarni jakikolwiek
                    {
                        wynik[szer*4*y+4*x]=255;//zapalam na niebiesko
                        wynik[szer*4*y+4*x+1]=0;
                        wynik[szer*4*y+4*x+2]=0;
                    }
                }
            }
            else if(tryb==3)
            {
                //otwarcie
            }
            else if(tryb==4)
            {
                //zamkniecie najpierw dylacja pozniej erozja
                //dylacja
                if(obraz[szer*4*y+4*x]==255 && obraz[szer*4*y+4*x+1]==255 && obraz[szer*4*y+4*x+2]==255) //jesli jest bialy (tlo)
                {
                    if(czyKolor(x,y,0))//jesli sasiedzi sa czarni jakikolwiek
                    {
                        wynik[szer*4*y+4*x]=255;//zapalam na niebiesko
                        wynik[szer*4*y+4*x+1]=0;
                        wynik[szer*4*y+4*x+2]=0;
                    }
                }
            }
        }
    }
    //ZAPALENIE NIEBIESKICH NA ODPOWIEDNIE
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            if(tryb==1 || tryb==3) //erozja zrobiona
            {
                if(wynik[szer*4*y+4*x]==255 && wynik[szer*4*y+4*x+1]==0 && wynik[szer*4*y+4*x+2]==0)//jesli jest niezbieski
                {
                    wynik[szer*4*y+4*x]=255;// zapalam na bialo
                    wynik[szer*4*y+4*x+1]=255;
                    wynik[szer*4*y+4*x+2]=255;
                }
            }
            else if(tryb==2 || tryb==4)//dylacja zrobiona
            {
                if(wynik[szer*4*y+4*x]==255 && wynik[szer*4*y+4*x+1]==0 && wynik[szer*4*y+4*x+2]==0)//jesli jest niezbieski
                {
                    wynik[szer*4*y+4*x]=0;// zapalam na czarno
                    wynik[szer*4*y+4*x+1]=0;
                    wynik[szer*4*y+4*x+2]=0;
                }
            }
        }
    }
    //DRUGA EDYCJA DLA OTWARCIA I ZAMKNIECIA
    if(tryb==3 || tryb==4)
    {
        for(int y=0;y<wys;++y)
        {
            for(int x=0;x<szer;++x)
            {
                if(tryb==3) //to trzeba jeszcze zrobic dylacje
                {
                    if(obraz[szer*4*y+4*x]==255 && obraz[szer*4*y+4*x+1]==255 && obraz[szer*4*y+4*x+2]==255) //jesli jest bialy (tlo)
                    {
                        if(czyKolor(x,y,0))//jesli sasiedzi sa czarni jakikolwiek
                        {
                            wynik[szer*4*y+4*x]=255;//zapalam na niebiesko
                            wynik[szer*4*y+4*x+1]=0;
                            wynik[szer*4*y+4*x+2]=0;
                        }
                    }
                }
                else if(tryb==4)//dylacja trzeba jeszcze zrobic erozje
                {
                    if(obraz[szer*4*y+4*x]==0 && obraz[szer*4*y+4*x+1]==0 && obraz[szer*4*y+4*x+2]==0)//jezeli piksel jest czarny
                    {
                        if(czyKolor(x,y,255))//jesli sasiedzi sa biali jakikolwiek
                        {
                            wynik[szer*4*y+4*x]=255;//zapalam na niebiesko
                            wynik[szer*4*y+4*x+1]=0;
                            wynik[szer*4*y+4*x+2]=0;
                        }
                    }
                }
            }
        }
    }
    //ZAPALENIE NIEBIESKICH NA ODPOWIEDNIE
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            if(tryb==3) //dylacja byla ostatnio
            {
                if(wynik[szer*4*y+4*x]==255 && wynik[szer*4*y+4*x+1]==0 && wynik[szer*4*y+4*x+2]==0)//jesli jest niezbieski
                {
                    wynik[szer*4*y+4*x]=0;// zapalam na czarno
                    wynik[szer*4*y+4*x+1]=0;
                    wynik[szer*4*y+4*x+2]=0;
                }
            }
            else if(tryb==4)//erozja byla ostatnio
            {
                if(wynik[szer*4*y+4*x]==255 && wynik[szer*4*y+4*x+1]==0 && wynik[szer*4*y+4*x+2]==0)//jesli jest niezbieski
                {
                    wynik[szer*4*y+4*x]=255;// zapalam na bialo
                    wynik[szer*4*y+4*x+1]=255;
                    wynik[szer*4*y+4*x+2]=255;
                }
            }
        }
    }
    update();
}
void MainWindow::on_erozja_clicked()
{
    tryb=1;
    zmiana();
}


void MainWindow::on_dylacja_clicked()
{
    tryb=2;
    zmiana();
}


void MainWindow::on_otwarcie_clicked()
{
    tryb=3;
    zmiana();
}


void MainWindow::on_zamkniecie_clicked()
{
    tryb=4;
    zmiana();
}

