#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage *img;
    int slider=0; //1-lewoPrawo 2-goraDol 3-obrot 4-skaowanie1 5-skalownie2 6-cos tam 1 7-cos tam2
    int wartosc=0;
private:
    void przesunPoziom()
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
};
#endif // MAINWINDOW_H
