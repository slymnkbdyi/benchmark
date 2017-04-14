#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QDebug>
#include<QTcpSocket>
#include<QThread>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int ID,QObject *parent = 0 );
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots :
    void readyRead();
    void disconnected();
private :
    QTcpSocket *socket;
    int SocketDescriptor;
};
#endif // MYTHREAD_H
