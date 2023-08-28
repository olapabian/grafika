#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
typedef struct point{
    int x;
    int y;
} point;
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
    bool isPressed=false;
    bool isPressed2=false;
    bool AisPressed=false;
    bool BisPressed=false;
    bool CisPressed=false;
    bool BigAisPressed=false;
    bool BigBisPressed=false;
    bool BigCisPressed=false;
    int licznik=0;
    int licznik2=0;
private slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wstawPiksel(int x,int y, int r, int g, int b, int obrazek);
    void kreska2(int finX,int finY,int sX, int sY, int obrazek);
    void rysujTrojkat(int wielkosc);
    void kwadrat(int X,int Y,int obrazek);
    void czysc1();
    void czysc2();
};
#endif // MAINWINDOW_H
