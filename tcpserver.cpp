#include "tcpserver.h"

TcpServer::TcpServer(QGraphicsScene *scene, QObject *parent) : QTcpServer(parent)
{
    Sscene=scene;
}

void TcpServer::StartServer(  quint16 porta)
{
    if(!this->listen(QHostAddress::Any,porta))
    {
        qDebug()<<"Não foi possível iniciar o server";
    }
    else
    {
        qDebug()<<"Server ouvindo";
    }
}
void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<< socketDescriptor <<" conectando ";
    Thread*  thread = new  Thread(socketDescriptor, Sscene, this);
    connect(thread, SIGNAL (finished()),thread, SLOT(disconnected()));
    thread->start();
}
