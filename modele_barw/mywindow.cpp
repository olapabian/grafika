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
                    ptr[szer*4*i + 4*j]=(wys-i)/2; // Skladowa BLUE
                    ptr[szer*4*i + 4*j + 1] = j/2; // Skladowa GREEN
                    ptr[szer*4*i + 4*j + 2] = pozycja; // Skladowa RED
                }
                else if(suwak=='G')
                {
                    ptr[szer*4*i + 4*j]=(wys-i)/2; // Skladowa BLUE
                    ptr[szer*4*i + 4*j + 1] = pozycja; // Skladowa GREEN
                    ptr[szer*4*i + 4*j + 2] = j/2; // Skladowa RED
                }
                else if(suwak=='B')
                {
                    ptr[szer*4*i + 4*j]=pozycja; // Skladowa BLUE
                    ptr[szer*4*i + 4*j + 1] = j/2; // Skladowa GREEN
                    ptr[szer*4*i + 4*j + 2] = (wys-i)/2; // Skladowa RED
                }
            }
        }
    }
    else
    {
        if(suwak=='S' || suwak=='V')
        {
            float p;
            p=pozycja/10000.0;
        }
        for(int i=0; i<wys; i++)
        {
            for(int j=0; j<szer; j++)
            {
                if(suwak=='H')
                {
                    float H=pozycja/60.0;
                    float c=(i/510.0)*(j/510.0);
                    float X=c*(1-std::abs(fmod(H,2)-1));
                    float m=(i/510.0)-c;
                    if(H>=0 && H<=1)
                    {
                        ptr[szer*4*i + 4*j]=c+m;
                        ptr[szer*4*i + 4*j + 1] = X+m;
                        ptr[szer*4*i + 4*j + 2] = 0+m;
                    }
                    else if(H<=2)
                    {
                            ptr[szer*4*i + 4*j]=X+m;
                            ptr[szer*4*i + 4*j + 1] = c+m;
                            ptr[szer*4*i + 4*j + 2] = 0+m;
                    }
                    else if(H<=3)
                    {
                        ptr[szer*4*i + 4*j]=0+m;
                        ptr[szer*4*i + 4*j + 1] = c+m;
                        ptr[szer*4*i + 4*j + 2] = X+m;
                    }
                    else if(H<=4)
                    {
                        ptr[szer*4*i + 4*j]=0+m;
                        ptr[szer*4*i + 4*j + 1] = X+m;
                        ptr[szer*4*i + 4*j + 2] = c+m;
                    }
                    else if(H<=5)
                    {
                        ptr[szer*4*i + 4*j]=X+m;
                        ptr[szer*4*i + 4*j + 1] = 0+m;
                        ptr[szer*4*i + 4*j + 2] = c+m;
                    }
                    else if(H<=6)
                    {
                        ptr[szer*4*i + 4*j]=c+m;
                        ptr[szer*4*i + 4*j + 1] = 0+m;
                        ptr[szer*4*i + 4*j + 2] = X+m;
                    }
                }
            }
        }
    }
    update();
}

