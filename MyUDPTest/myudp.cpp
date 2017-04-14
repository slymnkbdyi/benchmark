#include "myudp.h"
MyUDP::MyUDP(QObject *parent):
    QObject(parent)
{


    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::Any,1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

}
void MyUDP::SayHello()
{
    QByteArray Data;
    Data.append("Hello from UDP ");
    socket->writeDatagram(Data,QHostAddress::LocalHost,1234);
}
void MyUDP::readyRead()
{
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);
    qDebug() << "Message From : " << sender.toString();
    qDebug() << "Message Port : " << senderPort;
    qDebug() << "Message : " << Buffer << "\n\n\n";

}
