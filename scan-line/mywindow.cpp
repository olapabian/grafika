// Dolaczamy plik naglowkowy naszej klasy MyWindow
#include "mywindow.h"

// Dolaczamy plik naglowkowy zawierajacy definicje GUI
// Plik ten jest generowany automatycznie
// z pliku XML "mywindow.ui"
#include "ui_mywindow.h"

// Definicja konstruktora, wywolujemy najpierw
// konstruktor klasy nadrzednej, nastepnie tworzymy
// obiekt klasy Ui_MyWindow reprezentujacy GUI
MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    // Wywolujemy funkcje tworzaca elementy GUI
    // Jej definicja znajduje sie w pliku "ui_mywindow.h"
    ui->setupUi(this);

    // Pobieramy wymiary i wspolrzedne lewego gornego naroznika ramki
    // i ustawiamy wartosci odpowiednich pol
    // Uwaga: ramke "rysujFrame" wykorzystujemy tylko do
    // wygodnego ustaiwenia tych wymiarow. Rysunek bedziemy wyswietlac
    // bezposrednio w glownym oknie aplikacji.
    szer = ui->rysujFrame->width();
    wys = ui->rysujFrame->height();
    poczX = ui->rysujFrame->x();
    poczY = ui->rysujFrame->y();

    // Tworzymy obiekt klasy QImage, o odpowiedniej szerokosci
    // i wysokosci. Ustawiamy format bitmapy na 32 bitowe RGB
    // (0xffRRGGBB).
    img = new QImage(szer,wys,QImage::Format_RGB32);
    img2 = new QImage(szer,wys,QImage::Format_RGB32);

}

// Definicja destruktora
MyWindow::~MyWindow()
{
    delete ui;
}

// Funkcja (slot) wywolywana po nacisnieciu przycisku "Wyjscie" (exitButton)
// Uwaga: polaczenie tej funkcji z sygnalem "clicked"
// emitowanym przez przycisk jest realizowane
// za pomoca funkcji QMetaObject::connectSlotsByName(MyWindow)
// znajdujacej sie w automatycznie generowanym pliku "ui_mywindow.h"
// Nie musimy wiec sami wywolywac funkcji "connect"
void MyWindow::on_exitButton_clicked()
{
    // qApp to globalny wskaznik do obiektu reprezentujacego aplikacje
    // quit() to funkcja (slot) powodujaca zakonczenie aplikacji z kodem 0 (brak bledu)
    qApp->quit();
}


// Funkcja "odmalowujaca" komponent
void MyWindow::paintEvent(QPaintEvent*)
{
    // Obiekt klasy QPainter pozwala nam rysowac na komponentach
    QPainter p(this);

    // Rysuje obrazek "img" w punkcie (poczX,poczY)
    // (tu bedzie lewy gorny naroznik)
    p.drawImage(0,0,*img);
}


// Funkcja (slot) wywolywana po nacisnieciu przycisku "Czysc" (cleanButton)
void MyWindow::on_cleanButton_clicked()
{
    czysc();
    update();
}
void MyWindow::on_olowekButton_clicked()
{
    figura=0;
}
void MyWindow::on_kreskaButton_clicked()
{
    figura=1;
}
void MyWindow::on_koloButton_clicked()
{
    figura=2;
}
void MyWindow::on_elipsaButton_clicked()
{
    figura=3;
}

void MyWindow::on_suwak_valueChanged(int value)
{
    gestosc=value;
}
void MyWindow::on_wielokatButton_clicked()
{
    figura=4;
}
void MyWindow::czysc()
{
    // Wskaznik za pomoca, ktorego bedziemy modyfikowac obraz
    unsigned char *ptr;
    unsigned char *ptr2;

    // Funkcja "bits()" zwraca wskaznik do pierwszego piksela danych
    ptr2 = img2->bits();
    ptr = img->bits();
    int i,j;

    // Przechodzimy po wszystkich wierszach obrazu
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr2[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr2[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr2[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    ileP=0;
    wielokat.clear();
}
void MyWindow::czysc2() //czysci bez usuniecia wektora Krzywe
{
    // Wskaznik za pomoca, ktorego bedziemy modyfikowac obraz
    unsigned char *ptr;
    unsigned char *ptr2;

    // Funkcja "bits()" zwraca wskaznik do pierwszego piksela danych
    ptr2 = img2->bits();
    ptr = img->bits();
    int i,j;

    // Przechodzimy po wszystkich wierszach obrazu
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr2[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr2[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr2[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    ileP=0;
}
void MyWindow::wstawPiksel(int x,int y)
{
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    if ((x>=0)&&(y>=0)&&(x<szer)&&(y<wys))
    {
        ptr[szer*4*y + 4*x] = 255; // SkĹ‚adowa BLUE
        ptr[szer*4*y + 4*x + 1] = 255; // SkĹ‚adowa GREEN
        ptr[szer*4*y + 4*x + 2] = 255; // SkĹ‚adowa RED
    }

}
void MyWindow::schowek()
{
    unsigned char *ptr2 = img2->bits();
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();

    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            ptr2[szer*4*y + 4*x] = ptr[szer*4*y + 4*x]; // SkĹ‚adowa BLUE
            ptr2[szer*4*y + 4*x + 1] = ptr[szer*4*y + 4*x + 1]; // SkĹ‚adowa GREEN
            ptr2[szer*4*y + 4*x + 2] = ptr[szer*4*y + 4*x + 2]; // SkĹ‚adowa RED
        }
    }

}
void MyWindow::z_powrotem()
{
    unsigned char *ptr2 = img2->bits();
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            ptr[szer*4*y + 4*x] = ptr2[szer*4*y + 4*x]; // SkĹ‚adowa BLUE
            ptr[szer*4*y + 4*x + 1] = ptr2[szer*4*y + 4*x + 1]; // SkĹ‚adowa GREEN
            ptr[szer*4*y + 4*x + 2] = ptr2[szer*4*y + 4*x + 2]; // SkĹ‚adowa RED
        }
    }
}
void MyWindow::kreska(int finX,int finY)
{
    float a=1,b=0;
    int x,y;
    if(startX==finX)//pionowa
    {
        x=startX;
        if(startY<=finY)
        {
            for(int y=startY;y<=finY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);
            }
        }
        else
        {
            for(int y=finY;y<=startY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);
            }
        }
    }
    else
    {
        a=float(finY-startY)/float(finX-startX);
        b=startY-a*startX;
        if(abs(a)<=1)
        {
            y=startY;
            if(startX>finX)
            {
                for(int x=finX;x<=startX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5));
                }
            }
            else
            {
                for(int x=startX;x<=finX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5));
                }
            }

        }
        else
        {
            if(startY<=finY)
            {
                for(int y=startY;y<=finY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y);
                }
            }
            else
            {
                for(int y=finY;y<=startY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y);
                }
            }
        }
    }
    update();
}
void MyWindow::kreska2(int finX,int finY,int sX, int sY)
{
    point p;
    float a=1,b=0;
    int x,y;
    if(sX==finX)//pionowa
    {
        x=sX;
        if(sY<=finY)
        {
            for(int y=sY;y<=finY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);               
                p.x=(int)floor(x+0.5);
                p.y=y;
                wielokatCaly.push_back(p);
            }
        }
        else
        {
            for(int y=finY;y<=sY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);
                p.x=(int)floor(x+0.5);
                p.y=y;
                wielokatCaly.push_back(p);
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
                    wstawPiksel(x,(int)floor(y+0.5));
                    p.x=x;
                    p.y=(int)floor(y+0.5);
                    wielokatCaly.push_back(p);
                }
            }
            else
            {
                for(int x=sX;x<=finX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5));
                    p.x=x;
                    p.y=(int)floor(y+0.5);
                    wielokatCaly.push_back(p);
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
                    wstawPiksel((int)floor(x+0.5),y);
                    p.x=(int)floor(x+0.5);
                    p.y=y;
                    wielokatCaly.push_back(p);
                }
            }
            else
            {
                for(int y=finY;y<=sY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y);
                    p.x=(int)floor(x+0.5);
                    p.y=y;
                    wielokatCaly.push_back(p);
                }
            }
        }
    }
    update();
}
void MyWindow::wstaw8(int x, int y)
{
    wstawPiksel(x + startX, (int)floor(y+0.5) +startY);
    wstawPiksel(x + startX, -(int)floor(y+0.5) +startY);
    wstawPiksel(-x + startX, (int)floor(y+0.5) +startY);
    wstawPiksel(-x + startX, -(int)floor(y+0.5) +startY);
    wstawPiksel((int)floor(y+0.5)+ startX, x +startY);
    wstawPiksel(-(int)floor(y+0.5)+ startX, x +startY);
    wstawPiksel((int)floor(y+0.5)+ startX, -x +startY);
    wstawPiksel(-(int)floor(y+0.5)+ startX, -x +startY);
}
void MyWindow::kolo(int finX,int finY)
{
    float R=std::sqrt(std::pow(finX-startX,2)+std::pow(finY-startY,2));
    float a=(R/std::sqrt(2));
    for(float x=0;x<=a;++x)
    {
        float y=std::sqrt(std::pow(R,2)-std::pow(x,2));
        wstaw8(x,y);
    }
}
void MyWindow::elipsa(int finX, int finY,float step)
{
    float a = std::abs(finX - startX) ;
    float b = std::abs(finY - startY) ;
    step*=(2*M_PI); //0.1-min 0.01-maxymalna liczba kropek -tak bedzie na suwaku
    float t=0;
    float pastX=a * cos(t)+startX;
    float pastY=b * sin(t)+startY;
    float pomX=pastX;
    float pomY=pastY;
    for (t = step; t<=2*M_PI; t+=step) {
        float y = b * sin(t);
        float x = a * cos(t);
        kreska2(startX + x,startY+y,pastX,pastY);
        pastX=x+startX;
        pastY=y+startY;
    }
    kreska2(pomX,pomY,pastX,pastY);
    update();
}
bool MyWindow::czyTlo(int x,int y)
{
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    if ((x>=0)&&(y>=0)&&(x<szer)&&(y<wys))
    {
        if((ptr[szer*4*y + 4*x] == 0) && (ptr[szer*4*y + 4*x + 1] == 0) && (ptr[szer*4*y + 4*x + 2] == 0))
        {
            return true;
        }
        else return false;
    }
}
bool MyWindow::czyNalezy(point p)//czy nalezy do obrazka
{
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    if ((p.x>=0)&&(p.y>=0)&&(p.x<szer)&&(p.y<wys))
    {
        return true;
    }
    else return false;
}

void MyWindow::rysujWielokat()
{
    if(wielokat.size()>1)
    {
        for(int i=0;i<wielokat.size()-1;++i)
        {
            kreska2(wielokat[i+1].x,wielokat[i+1].y,wielokat[i].x,wielokat[i].y);
        }
    }

}
void MyWindow::scan_line()
{
    unsigned char *ptr;
    ptr = img->bits();
    int i,j;
    // Przechodzimy po wszystkich wierszach obrazu
    for(i=0; i<wys; i++)//y
    {
        for(j=0; j<szer; j++)//x
        {
            ptr[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr[szer*4*i + 4*j + 1] = 250; // Skladowa GREEN
            ptr[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
}
void MyWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton )
    {
        startX=x;
        startY=y;
        isPressed=true;
        if(figura==4)
        {
            point p;
            p.x=x;
            p.y=y;
            wielokat.push_back(p);
            wielokatCaly.push_back(p);
            rysujWielokat();
        }
    }
    else if(event->button() == Qt::RightButton )
    {
        //scan_line();
    }
    update();
}

void MyWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if((event->buttons() == Qt::LeftButton) && isPressed)
    {
        z_powrotem();
        if(figura==1)
        {
            kreska(x,y);
        }
        else if(figura==2)
        {
            kolo(x,y);
        }
        else if(figura==0)
        {
            wstawPiksel(x,y);
            schowek();
        }
        else if(figura==3)
        {
            elipsa(x,y,gestosc/1000);
        }

        update();
    }
}

void MyWindow::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton)
    {
        isPressed=false;
    }

    schowek();
    update();
}
























