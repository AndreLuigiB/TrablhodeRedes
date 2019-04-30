#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ok_clicked()
{QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    FileName = QFileDialog::getOpenFileName(this,
       tr("Open Images"), "/home/rpi/Desktop/Picture/Sample Pictures", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!FileName.isEmpty())
    {
         scene =  new QGraphicsScene;
         image = new QImage(FileName);
         scene->addPixmap(QPixmap::fromImage(*image));
         ui->Nome->setText(FileName);
         ui->ClientImg->setScene(scene);
         ui->ClientImg->show();
         ui->Enviar->setEnabled(true);
         ip =  ui->IPin->text();
         porta = ui->PORTin->text().toShort();

         QBuffer buffer(&data);
         image->save(&buffer, "PNG");

    }

}

void MainWindow::on_Enviar_clicked()
{
    if(protocol==1){
        server=new TcpServer(scene, this);
        server->StartServer(porta);
        client= new  Client(this);
        client->TCP(ip, porta, data, check);
        ui->ServerImg->setScene(scene);
        ui->ServerImg->show();
    }
    if(protocol==2){
        serverudp=new UdpServer(porta, this);
        server->StartServer(porta);
        client= new  Client(this);
        client->UDP(ip, porta, data, check);
//        ui->ServerImg->setScene(scene);
//        ui->ServerImg->show();
    }


}


void MainWindow::on_checsumBX_stateChanged(int arg1)
{
    if(ui->checsumBX->isChecked()){
        ui->crcBX->setChecked(false);
        check=1;
    }else{
        check=0;
    }
    qDebug()<<check<<" Check";
}

void MainWindow::on_crcBX_stateChanged(int arg1)
{
    if(ui->crcBX->isChecked()){
        ui->checsumBX->setChecked(false);
        check=2;
    }else{
        check=0;
    }
    qDebug()<<check<<" Check";
}

void MainWindow::on_tcpBX_stateChanged(int arg1)
{
    if(ui->tcpBX->isChecked()){
        ui->udpBX->setChecked(false);
        protocol=1;
    }else{
        ui->udpBX->setChecked(true);
        protocol=2;
    }
    qDebug()<<protocol<<" protocol";
}

void MainWindow::on_udpBX_stateChanged(int arg1)
{
    if(ui->udpBX->isChecked()){
        ui->tcpBX->setChecked(false);
        protocol=2;
    }else{
        ui->tcpBX->setChecked(true);
        protocol=1;
    }
    qDebug()<<protocol<<" protocol";

}
