#ifndef READTHREAD_H
#define READTHREAD_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class ReadThread : public QObject
{
    Q_OBJECT
public:
    explicit ReadThread(QObject *parent = 0);

    void readData(QSerialPort *serial);

signals:
    void returnData(QByteArray *bytes);

public slots:
};

#endif // READTHREAD_H
