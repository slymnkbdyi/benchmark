#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{
}
void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("google.com",80);
    if(socket->waitForConnected(3000))
    {
        qDebug() <<"Connected";
        socket->write("Hello World \r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading :   " << socket->bytesAvailable();
        qDebug() << socket->readAll();
        socket->close();
    }
    else
    {
        qDebug() <<"Not Connected";
    }
}
