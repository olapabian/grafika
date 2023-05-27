#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int tryb=0; //1-erozja 2-dylacja 3-otwarcie 4-zamkniecie
    Ui::MainWindow *ui;
    QImage *img;
    QImage *view;
    int szer = 486;
    int wys = 644;
private slots:
    void zmiana();
    bool czyKolor(int x,int y,int w);
    void paintEvent(QPaintEvent *event);
    void on_erozja_clicked();
    void on_dylacja_clicked();
    void on_otwarcie_clicked();
    void on_zamkniecie_clicked();
};
#endif // MAINWINDOW_H
