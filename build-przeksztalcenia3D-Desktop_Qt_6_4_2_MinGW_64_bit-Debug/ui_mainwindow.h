/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *RotacjaX;
    QSlider *GoraDol;
    QSlider *SkalownieX;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_3;
    QSlider *Skalowanie2;
    QLabel *label_2;
    QLabel *label_5;
    QSlider *LewoPrawo;
    QLabel *label_7;
    QSlider *PrzodTyl;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QSlider *RotacjaY;
    QLabel *label_14;
    QSlider *RotacjaZ;
    QLabel *label_15;
    QLabel *label_16;
    QSlider *SkalowanieZ;
    QLabel *label_17;
    QPushButton *Widoczne;
    QPushButton *Wszystkie;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(866, 614);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        RotacjaX = new QSlider(centralwidget);
        RotacjaX->setObjectName("RotacjaX");
        RotacjaX->setGeometry(QRect(580, 130, 160, 18));
        RotacjaX->setMinimum(0);
        RotacjaX->setMaximum(360);
        RotacjaX->setPageStep(1);
        RotacjaX->setValue(0);
        RotacjaX->setSliderPosition(0);
        RotacjaX->setOrientation(Qt::Horizontal);
        RotacjaX->setTickPosition(QSlider::NoTicks);
        RotacjaX->setTickInterval(1);
        GoraDol = new QSlider(centralwidget);
        GoraDol->setObjectName("GoraDol");
        GoraDol->setGeometry(QRect(580, 50, 160, 18));
        GoraDol->setMaximum(500);
        GoraDol->setPageStep(10);
        GoraDol->setValue(250);
        GoraDol->setSliderPosition(250);
        GoraDol->setOrientation(Qt::Horizontal);
        SkalownieX = new QSlider(centralwidget);
        SkalownieX->setObjectName("SkalownieX");
        SkalownieX->setGeometry(QRect(580, 240, 160, 16));
        SkalownieX->setMinimum(0);
        SkalownieX->setMaximum(200);
        SkalownieX->setPageStep(1);
        SkalownieX->setValue(100);
        SkalownieX->setSliderPosition(100);
        SkalownieX->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(760, 40, 31, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(620, 210, 81, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(630, 110, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(750, 10, 41, 21));
        Skalowanie2 = new QSlider(centralwidget);
        Skalowanie2->setObjectName("Skalowanie2");
        Skalowanie2->setGeometry(QRect(580, 270, 160, 18));
        Skalowanie2->setMaximum(200);
        Skalowanie2->setPageStep(1);
        Skalowanie2->setValue(100);
        Skalowanie2->setSliderPosition(100);
        Skalowanie2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(540, 10, 41, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(630, 0, 151, 16));
        LewoPrawo = new QSlider(centralwidget);
        LewoPrawo->setObjectName("LewoPrawo");
        LewoPrawo->setGeometry(QRect(580, 20, 160, 18));
        LewoPrawo->setMaximum(500);
        LewoPrawo->setPageStep(10);
        LewoPrawo->setValue(250);
        LewoPrawo->setSliderPosition(250);
        LewoPrawo->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(540, 40, 31, 21));
        PrzodTyl = new QSlider(centralwidget);
        PrzodTyl->setObjectName("PrzodTyl");
        PrzodTyl->setGeometry(QRect(580, 80, 160, 18));
        PrzodTyl->setMinimum(-90);
        PrzodTyl->setMaximum(90);
        PrzodTyl->setPageStep(10);
        PrzodTyl->setValue(0);
        PrzodTyl->setSliderPosition(0);
        PrzodTyl->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(540, 70, 31, 21));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(760, 70, 31, 21));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(560, 120, 21, 21));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(560, 150, 21, 21));
        RotacjaY = new QSlider(centralwidget);
        RotacjaY->setObjectName("RotacjaY");
        RotacjaY->setGeometry(QRect(580, 160, 160, 18));
        RotacjaY->setMinimum(0);
        RotacjaY->setMaximum(360);
        RotacjaY->setPageStep(1);
        RotacjaY->setValue(0);
        RotacjaY->setSliderPosition(0);
        RotacjaY->setOrientation(Qt::Horizontal);
        RotacjaY->setTickPosition(QSlider::NoTicks);
        RotacjaY->setTickInterval(1);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(560, 180, 21, 21));
        RotacjaZ = new QSlider(centralwidget);
        RotacjaZ->setObjectName("RotacjaZ");
        RotacjaZ->setGeometry(QRect(580, 190, 160, 18));
        RotacjaZ->setMinimum(0);
        RotacjaZ->setMaximum(360);
        RotacjaZ->setPageStep(1);
        RotacjaZ->setValue(0);
        RotacjaZ->setSliderPosition(0);
        RotacjaZ->setOrientation(Qt::Horizontal);
        RotacjaZ->setTickPosition(QSlider::NoTicks);
        RotacjaZ->setTickInterval(1);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(560, 230, 21, 21));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(560, 260, 21, 21));
        SkalowanieZ = new QSlider(centralwidget);
        SkalowanieZ->setObjectName("SkalowanieZ");
        SkalowanieZ->setGeometry(QRect(580, 300, 160, 18));
        SkalowanieZ->setMinimum(1);
        SkalowanieZ->setMaximum(180);
        SkalowanieZ->setPageStep(1);
        SkalowanieZ->setValue(1);
        SkalowanieZ->setSliderPosition(1);
        SkalowanieZ->setOrientation(Qt::Horizontal);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(560, 290, 21, 21));
        Widoczne = new QPushButton(centralwidget);
        Widoczne->setObjectName("Widoczne");
        Widoczne->setGeometry(QRect(580, 360, 181, 21));
        Wszystkie = new QPushButton(centralwidget);
        Wszystkie->setObjectName("Wszystkie");
        Wszystkie->setGeometry(QRect(580, 420, 181, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 866, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "D\303\263\305\202", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Skalowanie", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Rotacja", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prawo", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Lewo", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Przesuni\304\231cie", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "G\303\263ra", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Prz\303\263d", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Ty\305\202", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        Widoczne->setText(QCoreApplication::translate("MainWindow", "Rysuj tylko widoczne", nullptr));
        Wszystkie->setText(QCoreApplication::translate("MainWindow", "Rysuj Wszystkie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
