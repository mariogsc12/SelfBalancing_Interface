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
public slots:
    void serialManager();
private slots:

    void on_Button_ConnectDisconnect_clicked();

    void refreshGraph();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial_port;
    qint8 received_data;
    bool connect_status;

};
#endif // MAINWINDOW_H
