#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serial_port(new QSerialPort)
{
    ui->setupUi(this);

    qDebug() << "Intializing interface";

}

MainWindow::~MainWindow()
{
    if(serial_port != nullptr){
        serial_port->close();
        delete serial_port;
    }

    delete ui;
}

void MainWindow::on_Button_ON_clicked()
{


    qDebug()<<"Button ON pressed";

    if(! serial_port->isOpen())
    {
        QMessageBox::critical(this,"Port Error","Port is not opened...");
        return;
    }
    else
    {
        serialMessage("1");
    }



}


void MainWindow::on_Button_OFF_clicked()
{

    qDebug()<<"Button OFF pressed";

    if(! serial_port->isOpen())
    {
        QMessageBox::critical(this,"Port Error","Port is not opened...");
        return;
    }
    else
    {
        serialMessage("0");
    }
}

void MainWindow::serialMessage(const QByteArray &data)
{

    serial_port->write(data);

}


void MainWindow::on_Button_Ports_clicked()
{
    qDebug() << "Button Ports pressed";

    if(QSerialPortInfo::availablePorts().length() > 0){
        qDebug()<<"Number of available ports: " << QSerialPortInfo::availablePorts().length();

        foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Port Name:" << portInfo.portName();
            ui->comboBox_Ports->addItem(portInfo.portName());
        }
    }
    else{
        qDebug()<<"There aren't any serial connection available";
    }
}


void MainWindow::on_Button_Open_clicked()
{

    qDebug() << "Button Open pressed";

    serial_port->setPortName("COM10");
    serial_port->setBaudRate(QSerialPort::Baud115200);
    serial_port->setDataBits(QSerialPort::Data8);
    serial_port->setParity(QSerialPort::NoParity);
    serial_port->setStopBits(QSerialPort::OneStop);

    if(serial_port->open(QIODeviceBase::WriteOnly))
    {
        QMessageBox::information(this,"Result","Port opened succesfully");
        qDebug() << "Serial port initialized and opened successfully.";
    }
    else
    {
        QMessageBox::critical(this,"Port Error","Unable to open specified port...");
    }


}

