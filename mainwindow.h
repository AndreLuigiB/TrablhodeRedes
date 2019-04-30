#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QLabel>
#include <QGraphicsScene>
#include <QBuffer>
#include "tcpserver.h"
#include "client.h"
#include "udpserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ok_clicked();
    void on_Enviar_clicked();
    void on_checsumBX_stateChanged(int arg1);

    void on_crcBX_stateChanged(int arg1);

    void on_tcpBX_stateChanged(int arg1);

    void on_udpBX_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QString FileName=nullptr;
    QGraphicsScene *scene;
    Client *client;
    TcpServer *server;
    UdpServer *serverudp;
    QString ip;
    quint16 porta;
    QImage *image;
    QByteArray data;
    int check=0;
    int protocol =1;
};

#endif // MAINWINDOW_H
