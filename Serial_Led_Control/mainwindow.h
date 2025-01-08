#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

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

    void on_pushButton_2_clicked();

    void serialMessage(QString msg);

private:
    Ui::MainWindow *ui;
    QSerialPort *microcontroller;
    QString microcontroller_port_name;
    bool microcontroller_is_available;
};
#endif // MAINWINDOW_H
