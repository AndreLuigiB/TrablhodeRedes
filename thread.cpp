#include "thread.h"

Thread::Thread(qintptr ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor=ID;
}

void Thread::run()
{
    qDebug() << "Thread criada "<<socketDescriptor;
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        //emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug()<<"Cliente conectado " <<socketDescriptor;

    exec();
}
void Thread::readyRead()
{
    QByteArray Data = socket -> readAll();
    qDebug()<<socketDescriptor<<"Dados Lidos: "<< Data;

    socket->write(Data);
}

void Thread::disconnected()
{
    qDebug()<<socketDescriptor<<" desconectado";
    socket->close();
    socket->deleteLater();

    exit(0);

}

