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
    explicit TcpServer(QGraphicsScene *scene, QObject *parent = nullptr);
    void StartServer(  quint16 porta);

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
    QGraphicsScene *Sscene;

};

#endif // TCPSERVER_H
