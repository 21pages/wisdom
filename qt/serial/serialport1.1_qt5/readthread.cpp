#include "readthread.h"
#include <QDebug>
#include <QThread>
ReadThread::ReadThread(QObject *parent) : QObject(parent)
{

}

void ReadThread::readData(QSerialPort *serial)
{
    qDebug()<<"线程号2"<<QThread::currentThread();
    QSerialPort *mserial=serial;
    QByteArray bytes=mserial->readAll();
    emit returnData(&bytes);
}
