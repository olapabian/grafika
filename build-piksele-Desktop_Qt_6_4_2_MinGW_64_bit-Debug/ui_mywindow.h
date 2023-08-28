/********************************************************************************
** Form generated from reading UI file 'mywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOW_H
#define UI_MYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWindow
{
public:
    QWidget *centralWidget;
    QFrame *rysujFrame;
    QGroupBox *groupBox;
    QPushButton *kreskaButton;
    QPushButton *koloButton;
    QPushButton *cleanButton;
    QPushButton *exitButton;
    QPushButton *elipsaButton;
    QPushButton *olowekButton;
    QSlider *suwak;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *krzywa;
    QPushButton *dodaj;
    QPushButton *usun;
    QPushButton *modyfikuj;
    QPushButton *krzywa_2;
    QPushButton *dodaj_2;
    QPushButton *usun_2;
    QPushButton *modyfikuj_2;

    void setupUi(QMainWindow *MyWindow)
    {
        if (MyWindow->objectName().isEmpty())
            MyWindow->setObjectName("MyWindow");
        MyWindow->resize(887, 699);
        centralWidget = new QWidget(MyWindow);
        centralWidget->setObjectName("centralWidget");
        rysujFrame = new QFrame(centralWidget);
        rysujFrame->setObjectName("rysujFrame");
        rysujFrame->setGeometry(QRect(20, 20, 581, 591));
        rysujFrame->setFrameShape(QFrame::StyledPanel);
        rysujFrame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(600, 100, 281, 511));
        kreskaButton = new QPushButton(groupBox);
        kreskaButton->setObjectName("kreskaButton");
        kreskaButton->setGeometry(QRect(110, 70, 75, 23));
        koloButton = new QPushButton(groupBox);
        koloButton->setObjectName("koloButton");
        koloButton->setGeometry(QRect(110, 100, 75, 23));
        cleanButton = new QPushButton(groupBox);
        cleanButton->setObjectName("cleanButton");
        cleanButton->setGeometry(QRect(110, 440, 75, 23));
        exitButton = new QPushButton(groupBox);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(110, 470, 75, 23));
        elipsaButton = new QPushButton(groupBox);
        elipsaButton->setObjectName("elipsaButton");
        elipsaButton->setGeometry(QRect(110, 130, 75, 23));
        olowekButton = new QPushButton(groupBox);
        olowekButton->setObjectName("olowekButton");
        olowekButton->setGeometry(QRect(110, 40, 75, 23));
        suwak = new QSlider(groupBox);
        suwak->setObjectName("suwak");
        suwak->setGeometry(QRect(70, 160, 160, 18));
        suwak->setMinimum(1);
        suwak->setMaximum(100);
        suwak->setValue(1);
        suwak->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 150, 31, 31));
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(240, 150, 31, 31));
        krzywa = new QPushButton(groupBox);
        krzywa->setObjectName("krzywa");
        krzywa->setGeometry(QRect(110, 180, 75, 23));
        dodaj = new QPushButton(groupBox);
        dodaj->setObjectName("dodaj");
        dodaj->setGeometry(QRect(110, 210, 75, 23));
        usun = new QPushButton(groupBox);
        usun->setObjectName("usun");
        usun->setGeometry(QRect(110, 240, 75, 23));
        modyfikuj = new QPushButton(groupBox);
        modyfikuj->setObjectName("modyfikuj");
        modyfikuj->setGeometry(QRect(110, 270, 121, 21));
        krzywa_2 = new QPushButton(groupBox);
        krzywa_2->setObjectName("krzywa_2");
        krzywa_2->setGeometry(QRect(110, 300, 75, 23));
        dodaj_2 = new QPushButton(groupBox);
        dodaj_2->setObjectName("dodaj_2");
        dodaj_2->setGeometry(QRect(110, 330, 75, 23));
        usun_2 = new QPushButton(groupBox);
        usun_2->setObjectName("usun_2");
        usun_2->setGeometry(QRect(110, 360, 75, 23));
        modyfikuj_2 = new QPushButton(groupBox);
        modyfikuj_2->setObjectName("modyfikuj_2");
        modyfikuj_2->setGeometry(QRect(110, 390, 121, 21));
        MyWindow->setCentralWidget(centralWidget);

        retranslateUi(MyWindow);

        QMetaObject::connectSlotsByName(MyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyWindow)
    {
        MyWindow->setWindowTitle(QCoreApplication::translate("MyWindow", "MyWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MyWindow", "Wype\305\202nianie", nullptr));
        kreskaButton->setText(QCoreApplication::translate("MyWindow", "linia", nullptr));
        koloButton->setText(QCoreApplication::translate("MyWindow", "kolo", nullptr));
        cleanButton->setText(QCoreApplication::translate("MyWindow", "Czy\305\233\304\207", nullptr));
        exitButton->setText(QCoreApplication::translate("MyWindow", "Wyj\305\233cie", nullptr));
        elipsaButton->setText(QCoreApplication::translate("MyWindow", "elipsa", nullptr));
        olowekButton->setText(QCoreApplication::translate("MyWindow", "o\305\202\303\263wek", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MyWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" dir='rtl' style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> ()</p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MyWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> &lt;&gt;</p></body></html>", nullptr));
        krzywa->setText(QCoreApplication::translate("MyWindow", "nowa krzywa", nullptr));
        dodaj->setText(QCoreApplication::translate("MyWindow", "dodaj punkt", nullptr));
        usun->setText(QCoreApplication::translate("MyWindow", "usun punkt", nullptr));
        modyfikuj->setText(QCoreApplication::translate("MyWindow", "modyfikuj punkt", nullptr));
        krzywa_2->setText(QCoreApplication::translate("MyWindow", "B-spline", nullptr));
        dodaj_2->setText(QCoreApplication::translate("MyWindow", "dodaj punkt", nullptr));
        usun_2->setText(QCoreApplication::translate("MyWindow", "usun punkt", nullptr));
        modyfikuj_2->setText(QCoreApplication::translate("MyWindow", "modyfikuj punkt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWindow: public Ui_MyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
