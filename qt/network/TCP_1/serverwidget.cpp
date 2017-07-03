#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHostAddress>
ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    server=new QTcpServer(this);
    server->listen(QHostAddress::Any,const_port);
    connect(server,&QTcpServer::newConnection,
            [=]()
            {
                socket=server->nextPendingConnection();
                QString ip=socket->peerAddress().toString();
                quint16 port=socket->peerPort();
                QString str=QString("[%1:%2]连接成功!").arg(ip).arg(port);
                ui->editGet->append(str);

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
            }
            );
    setWindowTitle(QString("server%1:%2").arg("127.0.0.1").arg(const_port));
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonClose_clicked()
{
    if(socket==NULL)
    {
        return;
    }
    socket->disconnectFromHost();
    socket->close();
    //socket=NULL;
}

void ServerWidget::on_buttonSend_clicked()
{
    if(socket==NULL)
    {
        return;
    }
    QString sendText=ui->editSend->toPlainText();
    socket->write(sendText.toUtf8());
}
