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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *Button_Connect;
    QCustomPlot *customPlot;
    QProgressBar *progressBar_Pwm;
    QLabel *label_PwmName;
    QLabel *label_PwmValue;
    QPushButton *Button_Start;
    QPushButton *Button_Stop;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(657, 531);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(-30, 0, 701, 71));
        Button_Connect = new QPushButton(centralwidget);
        Button_Connect->setObjectName("Button_Connect");
        Button_Connect->setGeometry(QRect(10, 90, 80, 21));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");
        customPlot->setGeometry(QRect(170, 130, 481, 371));
        progressBar_Pwm = new QProgressBar(centralwidget);
        progressBar_Pwm->setObjectName("progressBar_Pwm");
        progressBar_Pwm->setGeometry(QRect(10, 220, 141, 31));
        progressBar_Pwm->setValue(24);
        label_PwmName = new QLabel(centralwidget);
        label_PwmName->setObjectName("label_PwmName");
        label_PwmName->setGeometry(QRect(40, 260, 37, 12));
        label_PwmValue = new QLabel(centralwidget);
        label_PwmValue->setObjectName("label_PwmValue");
        label_PwmValue->setGeometry(QRect(80, 260, 37, 12));
        Button_Start = new QPushButton(centralwidget);
        Button_Start->setObjectName("Button_Start");
        Button_Start->setGeometry(QRect(480, 90, 80, 21));
        Button_Stop = new QPushButton(centralwidget);
        Button_Stop->setObjectName("Button_Stop");
        Button_Stop->setGeometry(QRect(570, 90, 80, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 657, 17));
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
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700;\">SERIAL MOTOR CONTROL</span></p></body></html>", nullptr));
        Button_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_PwmName->setText(QCoreApplication::translate("MainWindow", "PWM:", nullptr));
        label_PwmValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Button_Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Button_Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
