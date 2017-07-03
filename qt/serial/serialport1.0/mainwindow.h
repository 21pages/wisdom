#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

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

    void readData();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    void initSerialPort();
};

#endif // MAINWINDOW_H
