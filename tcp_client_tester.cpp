#include "tcp_client_tester.h"


TCP_Client_Tester::TCP_Client_Tester()
{

}

TCP_Client_Tester::TCP_Client_Tester(QString _hostAddr, quint16 _portNumber)
{
    hostAddr = _hostAddr;
    portNumber = _portNumber;

    clientTcpSocket->connectToHost(hostAddr,portNumber);
    connect(clientTcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
    connect(clientTcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
    connect(clientTcpSocket,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    connect(clientTcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));

}

void TCP_Client_Tester::slotConnected()
{

}

void TCP_Client_Tester::slotDisconnected()
{

}

void TCP_Client_Tester::slotError(QAbstractSocket::SocketError)
{

}

void TCP_Client_Tester::slotSendToServer()
{

}

void TCP_Client_Tester::slotReadyRead()
{

}
