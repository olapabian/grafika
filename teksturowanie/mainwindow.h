#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    QImage *img, *img2, *imgMemory, *img2Memory;
private:
    Ui::MainWindow *ui;
    point a,b,c,A,B,C;
private slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wstawPiksel(int x,int y, int r, int g, int b, int obrazek);
    void kreska2(int finX,int finY,int sX, int sY, int obrazek);
    void rysujTrojkat(int wielkosc);

};
#endif // MAINWINDOW_H
