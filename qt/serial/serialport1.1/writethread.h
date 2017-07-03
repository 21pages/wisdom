#ifndef WRITETHREAD_H
#define WRITETHREAD_H
#include <QThread>
#include <QtSerialPort/QSerialPort>

class MainWindow;
class WriteThread : public QThread
{
public:
    WriteThread(QSerialPort *serial,MainWindow *window);
protected:
    void run();
private:
    QSerialPort *serial;
    MainWindow *window;
    QString sendText;
};

#endif // WRITETHREAD_H
