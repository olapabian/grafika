#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
typedef struct point{
    int x;
    int y;
} point;
typedef struct wspolrzedne{
    int x;//pierwsze
    int y;
    int alfa; //barycentryczne
    int beta;
    int gamma;
} wspolrzedne;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage *img, *img2, *Img, *orginal, *Orginal;
private:
    Ui::MainWindow *ui;
    point a,b,c,d,e,f,A,B,C;
    int obraz=0; //0 - sowa  lub 1 - tygrys
    bool isPressed=false;
    bool isPressed2=false;
    bool isPressed3=false;
    bool AisPressed=false;
    bool BisPressed=false;
    bool CisPressed=false;
    bool DisPressed=false;
    bool EisPressed=false;
    bool FisPressed=false;
    bool BigAisPressed=false;
    bool BigBisPressed=false;
    bool BigCisPressed=false;
    int licznik;
    int licznik2;
    int licznik3;
    std::vector<point> wielokat1;//wierzcholki wielokata
    std::vector<point> wielokat2;//wierzcholki wielokata
private slots:
    void czysc3();
    double Interpolacja(int x, int y, double dx);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wstawPiksel(int x,int y, int r, int g, int b, int obrazek);
    void kreska2(int finX,int finY,int sX, int sY, int obrazek);
    void rysujTrojkat(int wielkosc);
    void kwadrat(int X,int Y,int obrazek);
    void teksturowanie();
    void czysc1();
    void czysc2();
    void on_sowa_clicked();
    void on_tygrys_clicked();
};
#endif // MAINWINDOW_H
