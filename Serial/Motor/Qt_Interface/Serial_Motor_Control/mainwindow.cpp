#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

const qint8 SECONDS_SHOW_ON_GRAPH = 120;
QList<double> x_axis;
QList<double> y_axis;
static qint64 x_data_idx = 0;
static qint64 startTime;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serial_port(new QSerialPort)
    , connect_status(false)
{
    ui->setupUi(this);
    qDebug() << "Intializing interface..";

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("Time");
    ui->customPlot->yAxis->setLabel("Pulses");
    QColor color(40, 110, 255);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine); // Estilo de línea
    ui->customPlot->graph(0)->setPen(QPen(color.lighter(30))); // Color de la línea



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

    if(QSerialPortInfo::availablePorts().length() > 0){
        qDebug()<<"Number of available ports: " << QSerialPortInfo::availablePorts().length();

        foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Port Name:" << portInfo.portName();
            ui->comboBox_Ports->addItem(portInfo.portName());
        }
    }
    else{
        qDebug()<<"There aren't any serial connection available";
        QMessageBox::critical(this,"Port Error","There aren't any serial connection available...");
    }
}

MainWindow::~MainWindow()
{

    if(serial_port != nullptr){
        serial_port->close();
        delete serial_port;
    }

    delete ui;
}

void MainWindow::serialManager()
{
    double now = QDateTime::currentSecsSinceEpoch();

    received_data = (serial_port->readAll()).toInt();
    y_axis.append(received_data);
    x_axis.append(now);
    x_data_idx++;
    qDebug()<<"Serial manager function";
}


void MainWindow::on_Button_ConnectDisconnect_clicked()
{
    qDebug("Connect-Disconnect Button presedd");
    double now;

    if(connect_status == false){
        serial_port->setPortName(ui->comboBox_Ports->currentText());
        serial_port->setBaudRate(QSerialPort::Baud115200);
        serial_port->setDataBits(QSerialPort::Data8);
        serial_port->setParity(QSerialPort::NoParity);
        serial_port->setStopBits(QSerialPort::OneStop);
        serial_port->setFlowControl( QSerialPort::NoFlowControl );

        if(serial_port->open(QIODeviceBase::ReadOnly))
        {
            connect_status = true;
            ui->Button_ConnectDisconnect->setText("Disconnect");
            connect(serial_port,SIGNAL(readyRead()), this, SLOT(serialManager()));

            // Start Timer to Refresh the graph
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &MainWindow::refreshGraph );
            //connect(timer, &QTimer::timeout, this, &MainWindow::serialManager );
            // Start Timer @ 1 second
            timer->start(200);

            startTime = QDateTime::currentSecsSinceEpoch();
            double now = startTime;
            ui->customPlot->xAxis->setRange( now, now+SECONDS_SHOW_ON_GRAPH);
            ui->customPlot->yAxis->setRange(0, 60);

            QMessageBox::information(this,"Result","Port opened succesfully");
            qDebug() << "Serial port initialized and opened successfully.";
        }
        else
        {
            QMessageBox::critical(this,"Port Error","Unable to open specified port...");
        }
    }
    else
    {
        serial_port->close();
        connect_status=false;
        ui->Button_ConnectDisconnect->setText("Connect");
    }

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
