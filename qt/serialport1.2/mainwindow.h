#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_clearButton_clicked();

    void on_sendButton_clicked();

    void updateGet();

    void updateSend();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    QSerialPort *serial;
    void initSerialPort();
};

#endif // MAINWINDOW_H
