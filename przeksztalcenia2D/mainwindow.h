#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "macierz.h"

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
    macierz *przesuniecie, *rotacja, *skalowanie, *pochylenie, *powrot, *translacja;
    void przesun();
    macierz *stworzMacierze();
    Ui::MainWindow *ui;
private slots:
    void paintEvent(QPaintEvent *event);
    void on_LewoPrawo_valueChanged(int value);
    void on_GoraDol_valueChanged(int value);
    void on_Rotacja_valueChanged(int value);
    void on_Skalownie_valueChanged(int value);
    void on_Skalowanie2_valueChanged(int value);
    void on_horizontalSlider_6_valueChanged(int value);
    void on_horizontalSlider_7_valueChanged(int value);  
//    void on_LewoPrawo_sliderReleased();
//    void on_GoraDol_sliderReleased();
//    void on_Rotacja_sliderReleased();
};
#endif // MAINWINDOW_H
