#include "serialthread.h"
#include <QMessageBox>

SerialThread::SerialThread():
      serialObj(nullptr)
    , buffer("")
    , status(false)
    , isAvailable(false)
    , portName("")
{
    // Initialize the combo box with the available ports
    if(QSerialPortInfo::availablePorts().length() > 0){
        qDebug()<<"Number of available ports: " << QSerialPortInfo::availablePorts().length();

        foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts())
        {
            if(portInfo.hasVendorIdentifier() && portInfo.hasProductIdentifier())
            {
                if(portInfo.vendorIdentifier() == vendorId && portInfo.productIdentifier() == productId)
                {
                    portName = portInfo.portName();
                    isAvailable = true;
                }
            }
        }
    }
    else{
        qDebug()<<"ERROR - There aren't any serial connection available";
        QMessageBox::critical(nullptr,
                              "Port Error",
                              "There aren't any serial connection available...");
    }

    if(isAvailable)
    {
        // Configure the serial object
        serialObj= new QSerialPort(this);
        serialObj->setPortName(portName);
        serialObj->setBaudRate(QSerialPort::Baud115200);
        serialObj->setDataBits(QSerialPort::Data8);
        serialObj->setParity(QSerialPort::NoParity);
        serialObj->setStopBits(QSerialPort::OneStop);
        //serialObj->setReadBufferSize(7);
        serialObj->setFlowControl( QSerialPort::NoFlowControl );
        serialObj->open(QSerialPort::ReadOnly);

        QObject::connect(serialObj, SIGNAL(readyRead()), this, SLOT(readSerial()));

        // Show a message box to indicate a successful connection
        QMessageBox::information(nullptr,
                                 "Serial Connection",
                                 QString("Connected to port: %1").arg(portName),
                                 QMessageBox::Ok);
    }


}

SerialThread::~SerialThread()
{
}

void SerialThread::readSerial()
{
    while(serialObj->bytesAvailable())
    {
        data.append(serialObj->readAll());

        // Check the end of message
        if(data.contains("\r\n"))
        {
            buffer += QString::fromStdString(data.toStdString());

            // Clear previous data
            data.clear();

            // Split the message
            QStringList splitData = buffer.split(',');

            // Ensure that the message has two elements
            if (splitData.size() == 2) {
                bool ok1, ok2;

                // Convert data to int
                int controlAction = splitData[0].toInt(&ok1);
                int angle = splitData[1].toInt(&ok2);

                // Check correct conversion
                if (ok1 && ok2) {
                    qDebug() << "controlAction:" << controlAction << "angle:" << angle;
                    emit updateData(controlAction,angle);

                } else {
                    qDebug() << "ERROR - Unable to parse the data!";
                }
            } else {
                qDebug() << "ERROR - Invalid data format!";
            }

            buffer.clear();
            break;
        }
    }
}

void SerialThread::startSlot()
{
    if(isAvailable)
    {
        status = true;
        qDebug() << "start slot ran";
    }
    else
    {
        qDebug() << "Couldn't find serial connection";
    }
}

void SerialThread::stopSlot()
{
    qDebug() << "stop slot ran";
    if(status)
    {
        status = false;
    }

}

bool SerialThread::getStatus()
{
    return status;
}

QString SerialThread::getPortName()
{
    return portName;
}
