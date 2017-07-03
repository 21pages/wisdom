#include "writethread.h"
#include "mainwindow.h"
#include <QDebug>
WriteThread::WriteThread(QSerialPort *serial, MainWindow *window)
{
    this->serial=serial;
    this->window=window;
}


void WriteThread::run()
{
    qDebug()<<"线程号3："<<QThread::currentThread();
    window->getSendText(sendText);
    qDebug()<<"aaaaaa";

    //下位机以接收到回车换行为数据接收成功的标志
    sendText+="\r\n";
    //QIODevice::write(const QByteArray &byteArray)
    qDebug()<<"bbbbbb";

/*QObject: Cannot create children for a parent that is in a different thread.
(Parent is QSerialPort(0x9b5850), parent's thread is QThread(0x9183c0), current thread is QThread(0x9dae18)*/

    serial->write(sendText.toUtf8());
    qDebug()<<"cccccc";

}
