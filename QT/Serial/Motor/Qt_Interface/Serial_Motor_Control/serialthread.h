#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

class SerialThread : public QObject
{
    Q_OBJECT
public:
    SerialThread();
    ~SerialThread();
public slots:
    void readSerial();
    void startSlot();
    void stopSlot();

    bool getStatus();
    QString getPortName();
signals:
    void updateData(int x, int y);
private slots:

private:
    QSerialPort *serialObj;
    QByteArray data;
    QString buffer;
    bool status;
    bool isAvailable;
    QString portName;
    static const quint16 vendorId = 4292;
    static const quint16 productId = 60000;
};

#endif // SERIALTHREAD_H
