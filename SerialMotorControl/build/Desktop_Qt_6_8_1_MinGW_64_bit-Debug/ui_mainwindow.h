/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Button_OFF;
    QTextEdit *textEdit;
    QPushButton *Button_Clockwise;
    QLabel *label;
    QLabel *Label_ValuePWM;
    QSlider *horizontalSlider;
    QPushButton *Button_CounterColckwise;
    QPushButton *Button_ON;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(662, 283);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Button_OFF = new QPushButton(centralwidget);
        Button_OFF->setObjectName("Button_OFF");
        Button_OFF->setGeometry(QRect(270, 100, 61, 51));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 10, 661, 64));
        Button_Clockwise = new QPushButton(centralwidget);
        Button_Clockwise->setObjectName("Button_Clockwise");
        Button_Clockwise->setGeometry(QRect(480, 110, 161, 51));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 170, 61, 21));
        Label_ValuePWM = new QLabel(centralwidget);
        Label_ValuePWM->setObjectName("Label_ValuePWM");
        Label_ValuePWM->setGeometry(QRect(320, 170, 61, 21));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(220, 210, 221, 16));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        Button_CounterColckwise = new QPushButton(centralwidget);
        Button_CounterColckwise->setObjectName("Button_CounterColckwise");
        Button_CounterColckwise->setGeometry(QRect(480, 170, 161, 51));
        Button_ON = new QPushButton(centralwidget);
        Button_ON->setObjectName("Button_ON");
        Button_ON->setGeometry(QRect(350, 100, 61, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 662, 17));
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
        Button_OFF->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; color:#00aaff;\">MOTOR CONTROL INTERFACE</span></p></body></html>", nullptr));
        Button_Clockwise->setText(QCoreApplication::translate("MainWindow", "CLOCKWISE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PWM value:", nullptr));
        Label_ValuePWM->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Button_CounterColckwise->setText(QCoreApplication::translate("MainWindow", "COUNTERCLOCKWISE", nullptr));
        Button_ON->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
