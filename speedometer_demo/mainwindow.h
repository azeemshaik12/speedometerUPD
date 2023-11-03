#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qpainter>//below three headers needed for painter
#include <QObject>
#include <QPainterPath>
#include <QtNetwork>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QUdpSocket;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     int x=0;
 virtual void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    QUdpSocket *mSocket;
};
#endif // MAINWINDOW_H
