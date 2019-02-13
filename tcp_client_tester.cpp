#include "tcp_client_tester.h"


TCP_Client_Tester::TCP_Client_Tester()
{

}

TCP_Client_Tester::TCP_Client_Tester(QString _hostAddr, quint16 _portNumber)
{
    hostAddr = _hostAddr;
    portNumber = _portNumber;
    clientTcpSocket = new QTcpSocket;

    if(!(QAbstractSocket::ConnectedState == clientTcpSocket->state()))
        clientTcpSocket->connectToHost(hostAddr,portNumber,QIODevice::ReadWrite);

    clientTcpSocket->waitForConnected(3000);

    connect(clientTcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()),Qt::ConnectionType::QueuedConnection);
    connect(clientTcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()),Qt::ConnectionType::QueuedConnection);
    connect(clientTcpSocket,SIGNAL(readyRead()),this,SLOT(slotReadyRead()),Qt::ConnectionType::QueuedConnection);
    connect(clientTcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));

}


void TCP_Client_Tester::slotConnected()
{
    emit signalConnected();
}

void TCP_Client_Tester::slotDisconnected()
{

}

void TCP_Client_Tester::slotError(QAbstractSocket::SocketError _socketError)
{

    QString socketErrorString  = "Error: ";

    switch(_socketError)
    {
    case 0:
        socketErrorString = "The connection was refused by the peer (or timed out)";
        break;
    case 1:
        socketErrorString = "The remote host closed the connection";
        break;
    case 2:
        socketErrorString = "The host address was not found";
        break;
    case 3:
        socketErrorString = "The socket operation failed because the application lacked the required privileges";
        break;
    case 4:
        socketErrorString = "The local system ran out of resources (e.g., too many sockets)";
        break;
    case 5:
        socketErrorString = "The socket operation timed out";
        break;
    case 6:
        socketErrorString = "The datagram was larger than the operating system's limit (which can be as low as 8192 bytes)";
        break;
    case 7:
        socketErrorString = "An error occurred with the network (e.g., the network cable was accidentally plugged out)";
        break;
    case 8:
        socketErrorString = "The address specified to QAbstractSocket::bind() is already in use and was set to be exclusive";
        break;
    case 9:
        socketErrorString = "The address specified to QAbstractSocket::bind() does not belong to the host";
        break;
    case 10:
        socketErrorString = "The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support)";
        break;
    case 11:
        socketErrorString = "Used by QAbstractSocketEngine only, The last operation attempted has not finished yet (still in progress in the background)";
        break;
    case 12:
        socketErrorString = "The socket is using a proxy, and the proxy requires authentication";
        break;
    case 13:
        socketErrorString = "The SSL/TLS handshake failed, so the connection was closed";
        break;
    case 14:
        socketErrorString = "Could not contact the proxy server because the connection to that server was denied";
        break;
    case 15:
        socketErrorString = "The connection to the proxy server was closed unexpectedly (before the connection to the final peer was established)";
        break;
    case 16:
        socketErrorString = "The connection to the proxy server timed out or the proxy server stopped responding in the authentication phase";
        break;
    case 17:
        socketErrorString = "The proxy address set with setProxy() (or the application proxy) was not found";
        break;
    case 18:
        socketErrorString = "The connection negotiation with the proxy server failed, because the response from the proxy server could not be understood";
        break;
    case 19:
        socketErrorString = "An operation was attempted while the socket was in a state that did not permit it";
        break;
    case 20:
        socketErrorString = "The SSL library being used reported an internal error. This is probably the result of a bad installation or misconfiguration of the library";
        break;
    case 21:
        socketErrorString = "Invalid data (certificate, key, cypher, etc.) was provided and its use resulted in an error in the SSL library";
        break;
    case 22:
        socketErrorString = "A temporary error occurred (e.g., operation would block and socket is non-blocking)";
        break;
    case -1:
        socketErrorString = "An unidentified error occurred";
        break;
    default:
        socketErrorString = "";
        break;
    }

    emit signalSocketError(socketErrorString);

}

void TCP_Client_Tester::slotSendToServer()
{
    signalConnected();

}

void TCP_Client_Tester::slotReadyRead()
{

}
