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
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *Skalownie;
    QLabel *label_7;
    QLabel *label_9;
    QSlider *horizontalSlider_6;
    QSlider *LewoPrawo;
    QSlider *GoraDol;
    QSlider *Rotacja;
    QSlider *Skalowanie2;
    QSlider *horizontalSlider_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(881, 905);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(650, 110, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(780, 40, 41, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(640, 260, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(560, 40, 41, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(780, 70, 31, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(640, 20, 151, 16));
        Skalownie = new QSlider(centralwidget);
        Skalownie->setObjectName("Skalownie");
        Skalownie->setGeometry(QRect(600, 180, 160, 16));
        Skalownie->setMinimum(0);
        Skalownie->setMaximum(200);
        Skalownie->setPageStep(1);
        Skalownie->setValue(100);
        Skalownie->setSliderPosition(100);
        Skalownie->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(570, 70, 31, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(640, 160, 81, 21));
        horizontalSlider_6 = new QSlider(centralwidget);
        horizontalSlider_6->setObjectName("horizontalSlider_6");
        horizontalSlider_6->setGeometry(QRect(600, 280, 160, 18));
        horizontalSlider_6->setMinimum(-100);
        horizontalSlider_6->setMaximum(100);
        horizontalSlider_6->setPageStep(1);
        horizontalSlider_6->setValue(0);
        horizontalSlider_6->setSliderPosition(0);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        LewoPrawo = new QSlider(centralwidget);
        LewoPrawo->setObjectName("LewoPrawo");
        LewoPrawo->setGeometry(QRect(600, 40, 160, 18));
        LewoPrawo->setMaximum(544);
        LewoPrawo->setPageStep(10);
        LewoPrawo->setValue(272);
        LewoPrawo->setSliderPosition(272);
        LewoPrawo->setOrientation(Qt::Horizontal);
        GoraDol = new QSlider(centralwidget);
        GoraDol->setObjectName("GoraDol");
        GoraDol->setGeometry(QRect(600, 80, 160, 18));
        GoraDol->setMaximum(676);
        GoraDol->setPageStep(10);
        GoraDol->setValue(338);
        GoraDol->setSliderPosition(338);
        GoraDol->setOrientation(Qt::Horizontal);
        Rotacja = new QSlider(centralwidget);
        Rotacja->setObjectName("Rotacja");
        Rotacja->setGeometry(QRect(600, 130, 160, 18));
        Rotacja->setMinimum(0);
        Rotacja->setMaximum(360);
        Rotacja->setPageStep(1);
        Rotacja->setValue(0);
        Rotacja->setSliderPosition(0);
        Rotacja->setOrientation(Qt::Horizontal);
        Rotacja->setTickPosition(QSlider::NoTicks);
        Rotacja->setTickInterval(1);
        Skalowanie2 = new QSlider(centralwidget);
        Skalowanie2->setObjectName("Skalowanie2");
        Skalowanie2->setGeometry(QRect(600, 210, 160, 18));
        Skalowanie2->setMaximum(200);
        Skalowanie2->setPageStep(1);
        Skalowanie2->setValue(100);
        Skalowanie2->setSliderPosition(100);
        Skalowanie2->setOrientation(Qt::Horizontal);
        horizontalSlider_7 = new QSlider(centralwidget);
        horizontalSlider_7->setObjectName("horizontalSlider_7");
        horizontalSlider_7->setGeometry(QRect(600, 310, 160, 18));
        horizontalSlider_7->setMinimum(-100);
        horizontalSlider_7->setMaximum(100);
        horizontalSlider_7->setPageStep(1);
        horizontalSlider_7->setValue(0);
        horizontalSlider_7->setSliderPosition(0);
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 881, 21));
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
        label_6->setText(QCoreApplication::translate("MainWindow", "Rotacja", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prawo", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Pochylenie", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Lewo", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "D\303\263\305\202", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Przesuni\304\231cie", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "G\303\263ra", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Skalowanie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
