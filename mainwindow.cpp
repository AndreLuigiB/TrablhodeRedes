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
         QImage image(FileName);
         scene->addPixmap(QPixmap::fromImage(image));
         ui->Nome->setText(FileName);
         ui->ClientImg->setScene(scene);
         ui->ClientImg->show();
         ui->Enviar->setEnabled(true);

    }

}

void MainWindow::on_Enviar_clicked()
{
    server=new TcpServer(this);
    server->StartServer( );
    client= new  Client(this);
    client->Test();

}
