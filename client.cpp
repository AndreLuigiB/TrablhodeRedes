#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}


void Client::TCP(QString ip, quint16 porta, QByteArray data, int check ){
    socket = new QTcpSocket(this);

    Cdata= new QByteArray;
    *Cdata=data;
    Ccheck=check;

    connect(socket, SIGNAL(connected( )), this, SLOT(connected( )));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting,..";

    socket->connectToHost(ip, porta);

    if(!socket->waitForConnected(1000))
    {
        qDebug() << "Error: " << socket->errorString();
    }

}

void Client::UDP(QString ip, quint16 porta, QByteArray data, int check ){
/*
    Cdata= new QByteArray;
    *Cdata=data;
    Ccheck=check;
*/
    IP= new QHostAddress(ip);
    socketudp = new QUdpSocket(this);
    socketudp->bind(*IP, porta);

    connect(socketudp, SIGNAL(readyRead()), this, SLOT(readyReadu()));

    qDebug() << "Connecting,..";

     if(!socketudp->waitForConnected(1000))
    {
        qDebug() << "Error: " << socketudp->errorString();
    }

}


void Client::connected( )
{
    qDebug() << "Connected!";
    socket->write(*Cdata);
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
    //qDebug() << socket->readAll();
    if (Ccheck==1){
    char *checksum = new char(qChecksum(*Cdata,Cdata->size()));
    QByteArray CS(checksum);
    socket->write(CS);
    }
    if (Ccheck==2){
    char *crc = new char(CRC::Calculate(Cdata->data(),Cdata->size(),CRC::CRC_32()));
    QByteArray CR(crc);
    socket->write(CR);
    }
    //qDebug()<<"Check - ------- - ------- - ------- - ------- - " << socket->readAll();
    this->disconnected();
}

void Client::readyReadu()
{

}
