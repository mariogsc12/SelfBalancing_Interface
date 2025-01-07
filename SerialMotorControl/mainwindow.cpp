#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update_message(QString msg){
    qDebug() << "Update message";
}

void MainWindow::on_Button_OFF_clicked()
{
    qDebug()<< "Button OFF pressed";
    foreach(auto &port,QSerialPortInfo::availablePorts()){
        qDebug()<<port.portName();
    }
}


void MainWindow::on_Button_ON_clicked()
{
    qDebug()<< "Button ON pressed";
}


void MainWindow::on_Button_Clockwise_clicked()
{
    qDebug()<< "Button Clockwise pressed";
}


void MainWindow::on_Button_CounterColckwise_clicked()
{
    qDebug()<< "Button CounterClockwise pressed";
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<"Slider value modified";
}

