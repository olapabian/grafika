#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QImage>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
struct warstwa
{
    QImage *img=nullptr;
    int mode=0;
    float a=0;//wskaznik alfa
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int obrazek=2;
    int szer = 640;
    int wys = 427;
    QImage *pix1;
    QImage *pix2;
    QImage *pix3;
    QImage *tlo;
    QImage *wynik;
    void blenduj();
    void czarno();
    struct warstwa list[3];

private slots :

    void paintEvent(QPaintEvent *event);
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_listWidget_currentRowChanged(int currentRow);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_listWidget_2_currentRowChanged(int currentRow);
    void on_listWidget_3_currentRowChanged(int currentRow);
};
#endif // MAINWINDOW_H
