#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QThread>
#include "crc.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void TCP(QString ip, quint16 porta, QByteArray data, int check);
    void UDP(QString ip, quint16 porta, QByteArray data, int check);

signals:

public slots:
    void connected( );
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void readyReadu();
private:
      QTcpSocket *socket;
      QUdpSocket *socketudp;
      int cont=0;
      QByteArray *Cdata;
      int Ccheck=0;
      QHostAddress *IP;
};

#endif // CLIENT_H
