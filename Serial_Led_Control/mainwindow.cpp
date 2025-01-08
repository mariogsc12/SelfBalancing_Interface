#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    microcontroller = new QSerialPort;
    microcontroller_is_available = false;
    microcontroller_port_name = "";

    qDebug()<<"Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Port Name:" << serialPortInfo.portName();
        qDebug() << "Description:" << serialPortInfo.description();
        qDebug() << "Manufacturer:" << serialPortInfo.manufacturer();
        qDebug() << "Has Vendor ID:" << serialPortInfo.hasVendorIdentifier();
        qDebug() << "Vendor ID:" << serialPortInfo.vendorIdentifier();
        qDebug() << "Has Product ID:" << serialPortInfo.hasProductIdentifier();
        qDebug() << "Product ID:" << serialPortInfo.productIdentifier();
    }

    if(microcontroller_is_available){
        //microcontroller->setPortName();
        microcontroller->open(QSerialPort::WriteOnly);
        microcontroller->setBaudRate(QSerialPort::Baud115200);
        microcontroller->setDataBits(QSerialPort::Data8);
        microcontroller->setParity(QSerialPort::NoParity);
        microcontroller->setStopBits(QSerialPort::OneStop);
        microcontroller->setFlowControl(QSerialPort::NoFlowControl);
    }
    else{

    }
}

MainWindow::~MainWindow()
{
    if(microcontroller->isOpen()){
        microcontroller->close();
    }
    delete ui;
}

void MainWindow::on_Button_ON_clicked()
{
    serialMessage("1");
    qDebug()<<"Button ON pressed";
}


void MainWindow::on_pushButton_2_clicked()
{
    serialMessage("0");
    qDebug()<<"Button OFF pressed";
}

void MainWindow::serialMessage(QString msg){
    if(microcontroller->isWritable()){
        microcontroller->write(msg.toStdString().c_str());
    }
    else{
        qDebug() << "Could't write to serial";
    }
}

