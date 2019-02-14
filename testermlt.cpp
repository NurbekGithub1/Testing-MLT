#include "testermlt.h"


TesterMLT::TesterMLT()
{
    tcpClientTester = new TCP_Client_Tester(hostAddr,portNumber);

    connect(tcpClientTester,SIGNAL(signalSocketError(QString)),this,SLOT(slotSocketErrorInfo(QString)));
    connect(tcpClientTester,SIGNAL(signalConnected(QAbstractSocket::SocketState)),this,SLOT(slotSocketConnectedInfo(QAbstractSocket::SocketState)));
    connect(this,SIGNAL(signalConnectToServer()),tcpClientTester,SLOT(slotConnectToServer()));
    connect(this,SIGNAL(signalSendCoordinateToServer()),tcpClientTester,SLOT(slotSendToServer()));
}

void TesterMLT::slotSocketErrorInfo(QString _socketError)
{
    emit signalSocketErrorInfoToWindow(_socketError);
}

void TesterMLT::slotSocketConnectedInfo(QAbstractSocket::SocketState _socketState)
{
    emit signalSocketConnectedInfoToWindow(_socketState);
}

void TesterMLT::slotConnectToServer()
{
    emit signalConnectToServer();
}

void TesterMLT::slotSendCoordinateToServer()
{
    emit signalSendCoordinateToServer();
}
