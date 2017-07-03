#include "writethread.h"
#include <QDebug>
#include <QThread>
WriteThread::WriteThread(QObject *parent) : QObject(parent)
{

}

void WriteThread::writeData(QSerialPort *serial, QByteArray *bytes)
{
       qDebug()<<"线程号3:"<<QThread::currentThread();
       QSerialPort *mserial=serial;
       QByteArray *mbytes=bytes;
       mserial->write(*mbytes);
}
