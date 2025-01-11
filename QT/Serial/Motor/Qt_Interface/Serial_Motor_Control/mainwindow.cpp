#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>


QList<double> x_axis;
QList<double> y_axis;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Intializing interface..";


// ------------------------------------------------------------------- //
    // Configure the graph
    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("Time [s]");
    ui->customPlot->yAxis->setLabel("Angle [deg]");
    QColor color(40, 110, 255);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setPen(QPen(color.lighter(30)));

    // Configure the progress bar
    ui->progressBar_Pwm->setValue(0);

    // Configure the PWM label
    ui->label_PwmValue->setText("0");



    QSharedPointer<QCPAxisTickerDateTime> date_time_ticker(new QCPAxisTickerDateTime);
    date_time_ticker->setDateTimeFormat("mm::ss");
    ui->customPlot->xAxis->setTicker(date_time_ticker);

    // make left and bottom axes transfer their ranges to right and top axes
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    // first we create and prepare a text layout element:
    QCPTextElement *title = new QCPTextElement(ui->customPlot);
    title->setText("Pulses Real-Time Plot");
    title->setFont(QFont("sans", 12, QFont::Bold));

    // then we add it to the main plot layout:
    // insert an empty row above the axis rect
    ui->customPlot->plotLayout()->insertRow(0);
    // place the title in the empty cell we've just created
    ui->customPlot->plotLayout()->addElement(0, 0, title);
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_Button_Connect_clicked()
{
    qDebug("Connect-Disconnect Button presedd");

    // Initialize the serial thread
    QThread *thread = new QThread;
    serialThread = new SerialThread;
    serialThread->moveToThread(thread);
    thread->start();

    QObject::connect(this, &MainWindow::startSignal, serialThread, &SerialThread::startSlot);
    QObject::connect(this, &MainWindow::stopSignal, serialThread, &SerialThread::stopSlot);
    QObject::connect(serialThread, &SerialThread::updateData, this, &MainWindow::refreshGraph);
}

void MainWindow::on_Button_Disconnect_clicked()
{

}

void MainWindow::refreshGraph()
{
    double now = QDateTime::currentSecsSinceEpoch();
    if (connect_status)
    {
        // Limitar los datos a 60 segundos
        while (!x_axis.isEmpty() && x_axis.first() < now - 60)
        {
            x_axis.removeFirst();
            y_axis.removeFirst();
        }

        ui->customPlot->graph(0)->setData(x_axis, y_axis);

        // Ajustar el rango del eje X a los últimos 60 segundos
        ui->customPlot->xAxis->setRange(now - 60, now);

        ui->customPlot->replot();
    }
    qDebug() << "RefreshFunction";
}

void MainWindow::on_progressBar_Pwm_valueChanged(int value)
{

}


void MainWindow::on_Button_Start_clicked()
{
    emit startSignal();
}


void MainWindow::on_Button_Stop_clicked()
{
    emit stopSignal();
}


