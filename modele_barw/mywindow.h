#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QPainter>
#include <QMainWindow>
#include <QImage>
#include <QMouseEvent>
#include <algorithm>
QT_BEGIN_NAMESPACE
namespace Ui { class MyWindow; }
QT_END_NAMESPACE

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

private:
    Ui::MyWindow *ui;
    QImage *img;
    int szer;
    int wys;
    int poczX;
    int poczY;
    char suwak='N'; //R G B H S V
    int pozycja;//pozycja suwaka

    void rysuj();
    void wstawPiksel(int i,int j,int r,int g,int b);
private slots :
    void paintEvent(QPaintEvent*);
    void on_verticalSliderR_sliderPressed();
    void on_verticalSliderR_sliderMoved(int position);
    void on_verticalSliderG_sliderPressed();
    void on_verticalSliderG_sliderMoved(int position);
    void on_verticalSliderB_sliderPressed();
    void on_verticalSliderB_sliderMoved(int position);
    void on_verticalSliderH_sliderPressed();
    void on_verticalSliderH_sliderMoved(int position);
    void on_verticalSliderS_sliderPressed();
    void on_verticalSliderS_sliderMoved(int position);
    void on_verticalSlider_6_sliderPressed();
    void on_verticalSlider_6_sliderMoved(int position);
};
#endif // MYWINDOW_H
