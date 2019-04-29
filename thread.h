#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(qintptr ID, QObject *parent = nullptr);
    void run();
signals:
   //void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;

    qintptr socketDescriptor;
};

#endif // THREAD_H
