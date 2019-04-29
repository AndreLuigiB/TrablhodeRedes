#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
/*
   TcpServer server;
   server.StartServer( );
   Client  cliente;
   cliente.Test();
*/


//open 192.168.25.22 5555


    return a.exec();
}
