#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "macierz.h"
#include "sciana.h"

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
    int d=360;
    std::vector <point> Wierzcholki;
    std::vector <point> NoweWierzcholki;
    std::vector <krawedz> Krawedzie;
    std::vector <sciana> Sciany;
    std::vector <sciana> WidoczneSciany;
    macierz *wynik;
    macierz  *przesuniecie, *rotacjaX, *rotacjaY, *rotacjaZ, *skalowanie, *pochylenie, *powrot, *powrotX, *powrotY, *translacja, *translacjaX, *translacjaY;
    void przesun();
    void rysujSzescian();
    void kreska2(int finX,int finY,int sX, int sY,int obrazek);

    void kwardrat(int X,int Y,int obrazek);
    void wstawPiksel(int x,int y, int r, int g, int b,int obrazek);
    bool ch=false;
    bool czyTekstura = false;
    macierz *stworzMacierze();
    Ui::MainWindow *ui;
private slots:
    void nalozTeksture();
    void widoczneSciany();
    void rysujPoScianach();
    void paintEvent(QPaintEvent*);
    void czysc2();
    void on_LewoPrawo_valueChanged(int value);
    void on_GoraDol_valueChanged(int value);
    void on_PrzodTyl_valueChanged(int value);
    void on_RotacjaX_valueChanged(int value);
    void on_RotacjaY_valueChanged(int value);
    void on_RotacjaZ_valueChanged(int value);
    void on_SkalownieX_valueChanged(int value);
    void on_Skalowanie2_valueChanged(int value);
    void on_SkalowanieZ_valueChanged(int value);
    void on_Widoczne_clicked(bool checked);
    void on_Wszystkie_clicked();
    void on_Tekstura_clicked();
    void on_UsunTekstura_clicked();
};
#endif // MAINWINDOW_H
