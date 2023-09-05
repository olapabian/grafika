#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "macierz.h"
typedef struct point{
    int x;
    int y;
    int z;
    int X;//ten zrzutowany na d2
    int Y;//ten zrzutowany na d2
} point;
typedef struct krawedz{
    point a;
    point b;
} krawedz;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage *img,*img2;
    int szer=544;
    int wys=676;
    bool pierwszaOperacja=true;
private:
    int d=500;
    std::vector <point> Wierzcholki;
    std::vector <point> NoweWierzcholki;
    std::vector <krawedz> Krawedzie;
    macierz *wynik;
    macierz *szescian, *przesuniecie, *rotacja, *skalowanie, *pochylenie, *powrot, *translacja;
    void przesun();
    void rysujSzescian();
    void rysujSzescian2();
    void kreska2(int finX,int finY,int sX, int sY,int obrazek);
    void kwardrat(int X,int Y,int obrazek);
    void wstawPiksel(int x,int y, int r, int g, int b,int obrazek);
    macierz *stworzMacierze();
    Ui::MainWindow *ui;
private slots:
    void paintEvent(QPaintEvent*);
    void czysc2();
    void on_LewoPrawo_valueChanged(int value);
    void on_GoraDol_valueChanged(int value);
    void on_PrzodTyl_valueChanged(int value);
    void on_RotacjaX_valueChanged(int value);
    void on_RotacjY_valueChanged(int value);
    void on_RotacjaZ_valueChanged(int value);
    void on_SkalownieX_valueChanged(int value);
    void on_Skalowanie2_valueChanged(int value);
    void on_SkalowanieZ_valueChanged(int value);
};
#endif // MAINWINDOW_H
