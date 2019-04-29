#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QLabel>
#include <QGraphicsScene>
#include "tcpserver.h"
#include "client.h"

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


private:
    Ui::MainWindow *ui;
    QString FileName=nullptr;
    QGraphicsScene *scene;
    Client *client;
    TcpServer *server;
};

#endif // MAINWINDOW_H
