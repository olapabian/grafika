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
    QPushButton *wielokatButton;

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
        wielokatButton = new QPushButton(groupBox);
        wielokatButton->setObjectName("wielokatButton");
        wielokatButton->setGeometry(QRect(110, 190, 75, 23));
        wielokatButton->raise();
        kreskaButton->raise();
        koloButton->raise();
        cleanButton->raise();
        exitButton->raise();
        elipsaButton->raise();
        olowekButton->raise();
        suwak->raise();
        textEdit->raise();
        textEdit_2->raise();
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
        wielokatButton->setText(QCoreApplication::translate("MyWindow", "wielokat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWindow: public Ui_MyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
