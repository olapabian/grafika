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
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *horizontalSlider_3;
    QLabel *label_7;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QLabel *label_8;
    QSlider *horizontalSlider_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(600, 40, 160, 18));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(600, 70, 160, 18));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(630, 10, 151, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(560, 30, 41, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(760, 30, 41, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(560, 60, 31, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(760, 60, 31, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(650, 110, 63, 20));
        horizontalSlider_3 = new QSlider(centralwidget);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setGeometry(QRect(600, 130, 160, 18));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(640, 180, 81, 21));
        horizontalSlider_4 = new QSlider(centralwidget);
        horizontalSlider_4->setObjectName("horizontalSlider_4");
        horizontalSlider_4->setGeometry(QRect(600, 200, 160, 18));
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_5 = new QSlider(centralwidget);
        horizontalSlider_5->setObjectName("horizontalSlider_5");
        horizontalSlider_5->setGeometry(QRect(600, 230, 160, 18));
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_6 = new QSlider(centralwidget);
        horizontalSlider_6->setObjectName("horizontalSlider_6");
        horizontalSlider_6->setGeometry(QRect(600, 300, 160, 18));
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(650, 280, 63, 20));
        horizontalSlider_7 = new QSlider(centralwidget);
        horizontalSlider_7->setObjectName("horizontalSlider_7");
        horizontalSlider_7->setGeometry(QRect(600, 330, 160, 18));
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        label->setText(QCoreApplication::translate("MainWindow", "Przesuni\304\231cie", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Lewo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prawo", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "G\303\263ra", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "D\303\263\305\202", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Rotacja", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Skalowanie", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
