#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{

}

void TcpServer::StartServer( )
{
    if(!this->listen(QHostAddress::Any,1234))
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
    Thread*  thread = new  Thread(socketDescriptor, this);
    connect(thread, SIGNAL (finished()),thread, SLOT(disconnected()));
    thread->start();
}
