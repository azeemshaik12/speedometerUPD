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
     ui->label->setStyleSheet("color:#CDCDFD");
    connect(mSocket, &QUdpSocket::readyRead,[&]()
            {

                QByteArray datagram;
                datagram.resize(mSocket->pendingDatagramSize());
                mSocket->readDatagram(datagram.data(), datagram.size());
                ui->label->setText(QString(datagram));
                x=datagram.toInt();
                if(x<100)
                ui->label->setStyleSheet("color:#CDCDFD");
                else if(x<200)
                ui->label->setStyleSheet("color:yellow");
                else
                ui->label->setStyleSheet("color:red");
                update();
                backingStore();
            }

            );
    mSocket->bind(QHostAddress::Any,1234);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    auto rect = QRect(0,0,1300,650);
    auto rect_gauge = QRect(0,0,500,500);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    QPainterPath myPath;
    myPath.moveTo(rect_gauge.width()/2,rect_gauge.height()/2);
    myPath.arcTo(rect_gauge,218,-x*1.0625);//218  322

    QRectF source(0, 0, 500, 500);
    QRectF bgsource(0, 0, 1300, 650);

    //painter.drawPath(myPath);
    QPixmap bg(":/images/Rectangle 1.png");
    QPixmap circle(":/images/MicrosoftTeams-image (1).png");
    QPixmap needle(":/images/Component 1_prev_ui.png");
    QPixmap last(":/images/New Project (1).png");
    QPixmap last_2(":/images/New Project (2).png");
    painter.drawPixmap(rect,bg,bgsource);
    painter.translate(400,75);

    painter.save();
    painter.setClipPath(myPath);
    painter.drawPixmap(rect_gauge,last,source);
    painter.drawPixmap(rect_gauge,last_2,source);
    painter.restore();

    painter.save();
    painter.translate(rect_gauge.height()/2,rect_gauge.height()/2);
    painter.rotate(x*1.0625);
    painter.translate(rect_gauge.height()/-2,rect_gauge.height()/-2);
    painter.drawPixmap(rect_gauge,needle,source);
    painter.restore();

    painter.drawPixmap(rect_gauge,circle,source);
//    if(x==240)
//        painter.eraseRect(rect_gauge);
    }

