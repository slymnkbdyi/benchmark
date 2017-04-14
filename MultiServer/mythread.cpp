#include "mythread.h"
MyThread::MyThread(int ID,QObject *parent) :
    QThread(parent)
{
    this->SocketDescriptor= ID;
}
void MyThread::run()
{
    // thread start here
    qDebug() << SocketDescriptor << " Starting Thread ";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->SocketDescriptor))
    {
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection)       ;
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    qDebug() << SocketDescriptor << " Client Connected ";
    exec();

}
void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();
    qDebug() << SocketDescriptor << " Data in : " << Data;
    socket->write(Data);
}
void MyThread::disconnected()
{
    qDebug() << SocketDescriptor << " Disconnected   " ;
    socket->deleteLater();
    exit(0);
}

