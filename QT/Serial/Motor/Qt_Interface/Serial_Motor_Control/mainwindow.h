#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <serialthread.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void startSignal();
    void stopSignal();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

private slots:

    void refreshGraph();

    void on_progressBar_Pwm_valueChanged(int value);

    void on_Button_Start_clicked();

    void on_Button_Stop_clicked();

    void on_Button_Connect_clicked();

    void on_Button_Disconnect_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial_micro;
    QByteArray serialBuffer;
    bool connect_status;
    SerialThread *serialThread;

};
#endif // MAINWINDOW_H
