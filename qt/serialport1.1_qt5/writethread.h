#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class WriteThread : public QObject
{
    Q_OBJECT
public:
    explicit WriteThread(QObject *parent = 0);
    void writeData(QSerialPort *serial,QByteArray *bytes);


signals:

public slots:
};

#endif // WRITETHREAD_H
