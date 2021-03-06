#include "udpserver.h"

UdpServer::UdpServer(quint16 porta,QObject *parent):
    QObject(parent)
{

    socket = new QUdpSocket(this);

    if(!socket->bind(QHostAddress::Any, porta)){
        qDebug()<<"Não foi possível iniciar o server";
    }else {
           qDebug()<<"Server ouvindo";
        }
    connect(socket , SIGNAL(readyRead()), this, SIGNAL(readyRead()),Qt::DirectConnection);
    QByteArray Data;
      Data.append("Hello from UDP land");

      socket->writeDatagram(Data,QHostAddress::LocalHost,porta);

}


void UdpServer::readyRead(){
    QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
        //                 QHostAddress * address = 0, quint16 * port = 0)
        // Receives a datagram no larger than maxSize bytes and stores it in data.
        // The sender's host address and port is stored in *address and *port
        // (unless the pointers are 0).

        socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        qDebug() << "Message from: " << sender.toString();
        qDebug() << "Message port: " << senderPort;
        qDebug() << "Message: " << buffer;

}
void UdpServer::disconnected(){

}

