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
    QImage *img, *img2, *imgMemory, *img2Memory, *orginal;
private:
    Ui::MainWindow *ui;
    point a,b,c,A,B,C;
    //point *Point;
    bool isPressed=false;
    bool isPressed2=false;
    bool AisPressed=false;
    bool BisPressed=false;
    bool CisPressed=false;
    bool BigAisPressed=false;
    bool BigBisPressed=false;
    bool BigCisPressed=false;
    int licznik;
    int licznik2;
    int licznik3;
    std::vector<point> wielokat1;//wierzcholki wielokata
    std::vector<point> wielokat2;//wierzcholki wielokata
private slots:
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
};
#endif // MAINWINDOW_H
