#include "myserver.h"
MyServer::MyServer(QObject *parent) : QObject(parent)
{
   server = new QTcpServer(this);
   connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
   if(!server->listen(QHostAddress::Any,30180))
   {
       qDebug() <<    "Server Could Not Star! ";
   }
   else
   {
       qDebug() <<    "Server Started ";
   }
}
void MyServer::newConnection()
{
    QTcpSocket *socket  =  server->nextPendingConnection();
    socket->write("Hello Client \r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
}
