#include "mywindow.h"
#include "ui_mywindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
{
    ui->setupUi(this);
    szer = ui->rysujFrame->width();
    wys = ui->rysujFrame->height();
    poczX = ui->rysujFrame->x();
    poczY = ui->rysujFrame->y();

    img = new QImage(szer,wys,QImage::Format_RGB32);
}
void MyWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0,0,*img);
}
MyWindow::~MyWindow()
{
    delete ui;
}


void MyWindow::on_verticalSliderR_sliderPressed()
{
    suwak='R';
    rysuj();
}


void MyWindow::on_verticalSliderR_sliderMoved(int position)
{
    pozycja=position;
    rysuj();
}


void MyWindow::on_verticalSliderG_sliderPressed()
{
    suwak='G';
    rysuj();
}


void MyWindow::on_verticalSliderG_sliderMoved(int position)
{
    pozycja=position;
    rysuj();
}


void MyWindow::on_verticalSliderB_sliderPressed()
{
    suwak='B';
    rysuj();
}


void MyWindow::on_verticalSliderB_sliderMoved(int position)
{
    pozycja=position;
    rysuj();
}


void MyWindow::on_verticalSliderH_sliderPressed()
{
    suwak='H';
    rysuj();
}


void MyWindow::on_verticalSliderH_sliderMoved(int position)
{
    pozycja=position;
    rysuj();
}


void MyWindow::on_verticalSliderS_sliderPressed()
{
    suwak='S';
    rysuj();
}


void MyWindow::on_verticalSliderS_sliderMoved(int position)
{
    pozycja=position;
    rysuj();
}


void MyWindow::on_verticalSlider_6_sliderPressed()
{
    suwak='V';
    rysuj();
}


void MyWindow::on_verticalSlider_6_sliderMoved(int position)
{
    pozycja=position;
    rysuj();
}
void MyWindow::wstawPiksel(int i,int j,int r, int g,int b)
{
    unsigned char *ptr;
    ptr = img->bits();
    ptr[szer*4*i + 4*j]=b; // Skladowa BLUE
    ptr[szer*4*i + 4*j + 1] = g; // Skladowa GREEN
    ptr[szer*4*i + 4*j + 2] = r; // Skladowa RED
}
void MyWindow::rysuj()
{
    unsigned char *ptr;
    ptr = img->bits();
    if(suwak=='R' || suwak=='G' || suwak=='B')
    {
        for(int i=0; i<wys; i++)
        {
            for(int j=0; j<szer; j++)
            {
                if(suwak=='R')
                {
                    wstawPiksel(i,j,pozycja,j/2,(wys-i)/2);
                }
                else if(suwak=='G')
                {
                    wstawPiksel(i,j,j/2,pozycja,(wys-i)/2);
                }
                else if(suwak=='B')
                {
                    wstawPiksel(i,j,(wys-i)/2,j/2,pozycja);
                }
            }
        }
    }
    else
    {
        float p=0;
        if(suwak=='S' || suwak=='V')
        {
            p=(float)pozycja/100.0;
        }
        else p=(float)pozycja;
        for(int i=0; i<wys; i++)
        {
            for(int j=0; j<szer; j++)
            {
                if(suwak=='H')
                {
                    float H=p/60.0;
                    float c=((j)/(float)wys)*((wys-i)/(float)szer);
                    float X=c*(1-std::abs(fmod(H,2)-1));
                    float m=((j)/(float)wys)-c;
                    if(H>=0 && H<=1)
                    {
                        wstawPiksel(i,j,(c+m)*255,(X+m)*255,m*255);
                    }
                    else if(H<=2)
                    {
                        wstawPiksel(i,j,(X+m)*255,(c+m)*255,m*255);
                    }
                    else if(H<=3)
                    {
                        wstawPiksel(i,j,m*255,(c+m)*255,(X+m)*255);
                    }
                    else if(H<=4)
                    {
                        wstawPiksel(i,j,m*255,(X+m)*255,(c+m)*255);
                    }
                    else if(H<=5)
                    {
                        wstawPiksel(i,j,(X+m)*255,m*255,(c+m)*255);
                    }
                    else if(H<=6)
                    {
                        wstawPiksel(i,j,(c+m)*255,m*255,(X+m)*255);
                    }
                    else
                    {
                        wstawPiksel(i,j,0,0,0);
                    }
                }
                else if(suwak=='S')
                {

                    float H=(((szer-j)/(float)szer)/60.0)*360;
                    float c=((wys-i)/(float)wys)*p;
                    float X=c*(1-std::abs(fmod(H,2)-1));
                    float m=((wys-i)/(float)wys)-c;
                    if(H>=0 && H<=1)
                    {
                        wstawPiksel(i,j,(c+m)*255,(X+m)*255,m*255);
                    }
                    else if(H<=2)
                    {
                        wstawPiksel(i,j,(X+m)*255,(c+m)*255,m*255);
                    }
                    else if(H<=3)
                    {
                        wstawPiksel(i,j,m*255,(c+m)*255,(X+m)*255);
                    }
                    else if(H<=4)
                    {
                        wstawPiksel(i,j,m*255,(X+m)*255,(c+m)*255);
                    }
                    else if(H<=5)
                    {
                        wstawPiksel(i,j,(X+m)*255,m*255,(c+m)*255);
                    }
                    else if(H<=6)
                    {
                        wstawPiksel(i,j,(c+m)*255,m*255,(X+m)*255);
                    }
                    else
                    {
                        wstawPiksel(i,j,0,0,0);
                    }
                }
                else if(suwak=='V')
                {

                    float H=(((szer-j)/(float)szer)/60.0)*360;
                    float c=((wys-i)/(float)szer)*p;
                    float X=c*(1-std::abs(fmod(H,2)-1));
                    float m=p-c;
                    if(H>=0 && H<=1)
                    {
                        wstawPiksel(i,j,(c+m)*255,(X+m)*255,m*255);
                    }
                    else if(H<=2)
                    {
                        wstawPiksel(i,j,(X+m)*255,(c+m)*255,m*255);
                    }
                    else if(H<=3)
                    {
                        wstawPiksel(i,j,m*255,(c+m)*255,(X+m)*255);
                    }
                    else if(H<=4)
                    {
                        wstawPiksel(i,j,m*255,(X+m)*255,(c+m)*255);
                    }
                    else if(H<=5)
                    {
                        wstawPiksel(i,j,(X+m)*255,m*255,(c+m)*255);
                    }
                    else if(H<=6)
                    {
                        wstawPiksel(i,j,(c+m)*255,m*255,(X+m)*255);
                    }
                    else
                    {
                        wstawPiksel(i,j,0,0,0);
                    }
                }

            }
        }
    }
    update();
}

