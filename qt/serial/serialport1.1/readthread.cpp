#include "readthread.h"
#include "mainwindow.h"
#include <QDebug>
ReadThread::ReadThread(QSerialPort *serial, MainWindow *window)
{
    this->serial=serial;
    this->window=window;
}

void ReadThread::run()
{
    qDebug()<<"线程号2："<<QThread::currentThread();
    QByteArray bytes=serial->readAll();
    qDebug()<<"11111111111";
    window->showReadData(bytes);
    qDebug()<<"2222222s";
}
