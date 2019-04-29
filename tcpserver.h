#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include "thread.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);
    void StartServer( );

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // TCPSERVER_H
