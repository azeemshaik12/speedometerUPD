#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtNetwork>
#include<QUdpSocket>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSocket= new QUdpSocket(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_textChanged(const QString &arg1){

    ui->label_2->setText(arg1);


    //mSocket->writeDatagram(arg1.toUtf8(),QHostAddress::Broadcast,1234);
    mSocket->writeDatagram(arg1.toUtf8(),QHostAddress::Broadcast,1234);
   // mSocket->writeDatagram("azeem",QHostAddress::Broadcast,1234);
}

