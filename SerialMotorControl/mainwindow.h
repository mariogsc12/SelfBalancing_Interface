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
    void on_horizontalSlider_valueChanged(int value);
    void on_Button_ON_clicked();
    void on_Button_OFF_clicked();
    void on_Button_Clockwise_clicked();
    void on_Button_CounterColckwise_clicked();
    void update_message(QString msg);

private:
    Ui::MainWindow *ui;

    bool micro_is_available;
    QString port_name;
    QSerialPort *micro;
    QString micro_settings;
};
#endif // MAINWINDOW_H
