#ifndef READTHREAD_H
#define READTHREAD_H
#include <QThread>
#include <QtSerialPort/QSerialPort>

class MainWindow;
class ReadThread : public QThread
{
public:
    ReadThread(QSerialPort *serial,MainWindow *window);
protected:
    void run();
private:
    QSerialPort *serial;
    MainWindow *window;
};

#endif // READTHREAD_H
