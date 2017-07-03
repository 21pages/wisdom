#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class ReadThread;
class WriteThread;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startRead();

    void showReadData(QByteArray *bytes);

    void readCore();
    void writeCore();
    void dealClose();

private slots:
    void on_openButton_clicked();

    void on_clearButton_clicked();

    void on_sendButton_clicked();

signals:
    void dealRead(QSerialPort *serial);

    void dealWrite(QSerialPort *serial,QByteArray *bytes);


private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    void initSerialPort();

    ReadThread *readThread;
    WriteThread *writeThread;
    QThread *thread1;
    QThread *thread2;

    QByteArray *bytes;


};

#endif // MAINWINDOW_H
