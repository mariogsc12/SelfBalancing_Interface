#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_ON_clicked();

    void on_Button_OFF_clicked();

    void serialMessage(const QByteArray &data);


    void on_Button_Ports_clicked();

    void on_Button_Open_clicked();


private:
    Ui::MainWindow *ui;
    QSerialPort *serial_port;

};
#endif // MAINWINDOW_H
