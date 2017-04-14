#include "myserver.h"

MyServer::MyServer(QObject *parent):
    QTcpServer(parent)
{
   pool = new QThreadPool(this);
   pool->setMaxThreadCount(5);

}

void MyServer::StartServer()
{
    if(this->listen(QHostAddress::Any,1234))
    {
        qDebug() << "Server Started";
    }
    else
    {

        qDebug() << "Server Did Not  Started";
    }
}
void MyServer::incomingConnection(int handle)
{
   MyRunnable *task = new MyRunnable();
   task->setAutoDelete(true);
   task->SocketDescriptor = handle;
   pool->start(task);
}
