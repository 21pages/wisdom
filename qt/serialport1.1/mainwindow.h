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

    void showReadData(const QByteArray& bytes);
    void getSendText(QString &sendText);
    void handleReadyRead();//start()参数不为0，通过此函数间接开线程

private slots:
    void on_openButton_clicked();

    void on_clearButton_clicked();

    void on_sendButton_clicked();




private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    void initSerialPort();

    ReadThread *readThread;
    WriteThread *writeThread;


};

#endif // MAINWINDOW_H
