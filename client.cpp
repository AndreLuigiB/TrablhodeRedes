#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}


void Client::Test( ){
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting,..";

    socket->connectToHost("192.168.25.22", 1234);

    if(!socket->waitForConnected(1000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}


void Client::connected()
{
    qDebug() << "Connected!";

    socket->write("~~~~~Mensagem~~~~~");
}

void Client::disconnected()
{
    socket->close();
    socket->deleteLater();
    qDebug() << "Disconnected!";
}

void Client::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}

void Client::readyRead()
{
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
    socket->write("~~~~~Mensagem2~~~~~");
    cont++;
    if (cont==10){this->disconnected();}
}

