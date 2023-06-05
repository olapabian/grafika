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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *erozja;
    QPushButton *dylacja;
    QPushButton *otwarcie;
    QPushButton *zamkniecie;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(719, 698);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, -3, 471, 611));
        erozja = new QPushButton(centralwidget);
        erozja->setObjectName("erozja");
        erozja->setGeometry(QRect(610, 30, 83, 29));
        dylacja = new QPushButton(centralwidget);
        dylacja->setObjectName("dylacja");
        dylacja->setGeometry(QRect(610, 70, 83, 29));
        otwarcie = new QPushButton(centralwidget);
        otwarcie->setObjectName("otwarcie");
        otwarcie->setGeometry(QRect(610, 110, 83, 29));
        zamkniecie = new QPushButton(centralwidget);
        zamkniecie->setObjectName("zamkniecie");
        zamkniecie->setGeometry(QRect(610, 150, 83, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 719, 25));
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
        label->setText(QString());
        erozja->setText(QCoreApplication::translate("MainWindow", "erozja", nullptr));
        dylacja->setText(QCoreApplication::translate("MainWindow", "dylacja", nullptr));
        otwarcie->setText(QCoreApplication::translate("MainWindow", "otwarcie", nullptr));
        zamkniecie->setText(QCoreApplication::translate("MainWindow", "zamkni\304\231cie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
