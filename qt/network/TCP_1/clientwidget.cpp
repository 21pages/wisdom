#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    socket=new QTcpSocket(this);
    connect(socket,&QTcpSocket::connected,
            [=]()
            {
                ui->editGet->append(QString("成功与服务器建立连接!"));
            }

            );
    connect(socket,&QTcpSocket::readyRead,
            [=]()
            {
                QByteArray bytes=socket->readAll();
                ui->editGet->append(QString(bytes));
            }

            );
    connect(socket,&QTcpSocket::disconnected,
            [=]()
            {
                ui->editGet->append(QString("连接已取消!"));
            }

            );
    setWindowTitle(QString("客户端"));
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    QString ip=ui->editIP->text();
    quint16 port=ui->editPort->text().toInt();
    socket->connectToHost(QHostAddress(ip),port);
}

void ClientWidget::on_buttonClose_clicked()
{
    if(socket==NULL)
    {
        return;
    }
    socket->disconnectFromHost();
    socket->close();
    //socket=NULL;
}

void ClientWidget::on_buttonSend_clicked()
{
    QString sendText=ui->editSend->toPlainText();
    socket->write(sendText.toUtf8());
}
