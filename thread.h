#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QGraphicsScene>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(qintptr ID, QGraphicsScene *scene, QObject *parent = nullptr);
    void run();
signals:
   //void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    QGraphicsScene *Sscene;
    QImage *Simage;
    qintptr socketDescriptor;
};

#endif // THREAD_H
