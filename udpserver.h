#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>

class UdpServer :public QObject
{
    Q_OBJECT
public:
    UdpServer(quint16 porta,QObject *parent);
public slots:
    void readyRead();
    void disconnected();
    //void connected();
private:
    QUdpSocket *socket;
};

#endif // UDPSERVER_H
