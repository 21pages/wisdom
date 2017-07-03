#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSerialPort();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//打开串口
void MainWindow::on_openButton_clicked()
{

    //按钮显示包括"打开串口"和"关闭串口"
    //当前串口处于关闭状态
    if(ui->openButton->text()==QString("打开串口"))
    {
        //将openButton设置为"关闭串口"
        ui->openButton->setText(QString("关闭串口"));
        //关闭设置菜单使能
        ui->portNameBox->setEnabled(false);
        ui->baudRateBox->setEnabled(false);
        ui->dataBitsBox->setEnabled(false);
        ui->parityBox->setEnabled(false);
        ui->stopBitsBox->setEnabled(false);
        //将串口设置为窗口设置的状态
        //设置串口名
        serial->setPortName(ui->portNameBox->currentText());
        //打开串口,必须先打开串口
        //[virtual] bool QSerialPort::open(OpenMode mode)
        bool openresult=serial->open(QIODevice::ReadWrite);
        if(!openresult)
        {
            QMessageBox::information(this,"提示信息","串口打开失败");
            return;
        }
        //设置波特率
        //Note: If the setting is set before opening the port,
        //the actual serial port setting is done automatically in the QSerialPort::open() method right after that the opening of the port succeeds.
        serial->setBaudRate(ui->baudRateBox->currentText().toInt());
        //设置数据位
        switch(ui->dataBitsBox->currentIndex())
        {
        case 0:
            serial->setDataBits(QSerialPort::Data8);
            break;
        case 1:
            serial->setDataBits(QSerialPort::Data7);
            break;
        case 2:
            serial->setDataBits(QSerialPort::Data6);
            break;
        case 3:
            serial->setDataBits(QSerialPort::Data5);
            break;
        default:
            serial->setDataBits(QSerialPort::UnknownDataBits);
            break;
        }
        //设置校验位
        switch(ui->parityBox->currentIndex())
        {
        case 0:
            serial->setParity(QSerialPort::NoParity);
            break;
        case 1:
            serial->setParity(QSerialPort::EvenParity);
            break;
        case 2:
            serial->setParity(QSerialPort::OddParity);
            break;
        case 3:
            serial->setParity(QSerialPort::SpaceParity);
            break;
        case 4:
            serial->setParity(QSerialPort::MarkParity);
            break;
        default:
             serial->setParity(QSerialPort::UnknownParity);
            break;
        }
        //设置停止位
        switch(ui->stopBitsBox->currentIndex())
        {
        case 0:
            serial->setStopBits(QSerialPort::OneStop);
            break;
        case 1:
            serial->setStopBits(QSerialPort::OneAndHalfStop);
            break;
        case 2:
            serial->setStopBits(QSerialPort::TwoStop);
            break;
        default:
            serial->setStopBits(QSerialPort::UnknownStopBits);
            break;
        }
        //设置流控制
        serial->setFlowControl(QSerialPort::NoFlowControl);

        //read之前必须调用readyRead()
        connect(serial,&QSerialPort::readyRead,this,MainWindow::readData);
    }
    //如果在串口打开状态下点击button
    else if(ui->openButton->text()==QString("关闭串口"))
    {
            //丢弃串口中的数据
            serial->clear();
            //关闭串口
            serial->close();
            //The object will be deleted when control returns to the event loop.
            //serial->deleteLater();

            //恢复菜单使能
            ui->portNameBox->setEnabled(true);
            ui->baudRateBox->setEnabled(true);
            ui->dataBitsBox->setEnabled(true);
            ui->parityBox->setEnabled(true);
            ui->stopBitsBox->setEnabled(true);
            //button文字改为"打开串口"
            ui->openButton->setText(QString("打开串口"));
    }
}
//清除接收窗口的数据
void MainWindow::on_clearButton_clicked()
{
    ui->getEdit->clear();
}
//发送数据
void MainWindow::on_sendButton_clicked()
{
    //检查发送窗口是否为空
    QString sendText=ui->sendEdit->toPlainText();
    if(sendText.isEmpty())
    {
        QMessageBox::information(this,"提示消息","发送信息为空!");
        return;
    }
    //下位机以接收到回车换行为数据接收成功的标志
    sendText+="\r\n";
    //QIODevice::write(const QByteArray &byteArray)
    serial->write(sendText.toUtf8());
}
//串口读取数据
void MainWindow::readData()
{
    //QByteArray QIODevice::readAll ()
    QByteArray byteData=serial->readAll();
    //检查是否读取到数据
//    if(byteData==NULL)
//    {
//        QMessageBox::information(this,"提示消息","没有读取到信息!");
//        return;
//    }
    //新读取到的信息要追加到窗口
    QString oldText=ui->getEdit->toPlainText();
    QString newText=oldText+=QString(byteData);
    ui->getEdit->clear();
    ui->getEdit->setText(newText);
    //Clears the contents of the byte array and makes it null.
    //byteData.clear();
}

void MainWindow::initSerialPort()
{
    QList<QSerialPortInfo> infos=QSerialPortInfo::availablePorts();
    //检查是否有可用串口
    if(infos.isEmpty())
    {
        QMessageBox::information(this,"提示信息","没有可用串口!");
        //return;
    }
    //初始化串口名
    foreach(QSerialPortInfo info,infos)
    {
        ui->portNameBox->addItem(info.portName());
    }

    //初始化波特率，默认9600
    QStringList baudRateItems;
    baudRateItems<<"115200"<<"57600"<<"38400"<<"19200"
                 <<"9600"<<"4800"<<"2400"<<"1200";
    ui->baudRateBox->addItems(baudRateItems);
    ui->baudRateBox->setCurrentIndex(4);

    //初始化数据位，默认8
    QStringList dataBitsItems;
    dataBitsItems<<"8"<<"7"<<"6"<<"5";
    ui->dataBitsBox->addItems(dataBitsItems);
    ui->dataBitsBox->setCurrentIndex(0);

    //初始化校验位,默认无校验
    QStringList parityItems;
    parityItems<<"无校验"<<"偶校验"<<"奇校验"<<"SpaceParity"<<"MarkParity";
    ui->parityBox->addItems(parityItems);
    ui->parityBox->setCurrentIndex(0);

    //初始化停止位，默认1
    QStringList stopBitsItems;
    stopBitsItems<<"1"<<"1.5"<<"2";
    ui->stopBitsBox->addItems(stopBitsItems);
    ui->stopBitsBox->setCurrentIndex(0);

    //其他
    //新建一个串口对象
    serial=new QSerialPort;

    //接收窗口设置为只读
    ui->getEdit->setReadOnly(true);
}
