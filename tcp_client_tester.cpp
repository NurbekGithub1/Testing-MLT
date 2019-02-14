#include "tcp_client_tester.h"


TCP_Client_Tester::TCP_Client_Tester()
{

}

TCP_Client_Tester::TCP_Client_Tester(QString _hostAddr, quint16 _portNumber)
{
    hostAddr = _hostAddr;
    portNumber = _portNumber;
    clientTcpSocket = new QTcpSocket;

    connect(clientTcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()),Qt::ConnectionType::QueuedConnection);
    connect(clientTcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()),Qt::ConnectionType::QueuedConnection);
    connect(clientTcpSocket,SIGNAL(readyRead()),this,SLOT(slotReadyRead()),Qt::ConnectionType::QueuedConnection);
    connect(clientTcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));
    // qDebug() << clientTcpSocket->state();
}

void TCP_Client_Tester::slotConnectToServer()
{
    qDebug() << " CONNECTING TO SERVER (_log) ";
    qDebug() << clientTcpSocket->state();
    clientTcpSocket->connectToHost(QHostAddress::LocalHost,portNumber,QIODevice::ReadWrite);
    qDebug() << clientTcpSocket->state();

}

void TCP_Client_Tester::slotConnected()
{
    if(clientTcpSocket->state() == QAbstractSocket::SocketState::ConnectedState)
        emit signalConnected(clientTcpSocket->state());
}

void TCP_Client_Tester::slotDisconnected()
{
    qDebug() << " slot disconnected!!!";
}

void TCP_Client_Tester::slotSendToServer()
{
    qDebug() << "Sending to server!!!";

}

void TCP_Client_Tester::slotReadyRead()
{
    qDebug() << "Slot readyRead!!!";
}

void TCP_Client_Tester::slotError(QAbstractSocket::SocketError _socketError)
{

    QString socketErrorString  = "Error: ";

    switch(_socketError)
    {
    case 0:
        socketErrorString = "Соединение было разорвано другим узлом (или по тайм-ауту).";
        break;
    case 1:
        socketErrorString = "Удалённый хост закрыл соединение. ";
        break;
    case 2:
        socketErrorString = "Адрес узла не найден.";
        break;
    case 3:
        socketErrorString = "Операция с сокетом была прервана, так как приложение не получило необходимых прав.";
        break;
    case 4:
        socketErrorString = "У текущей системы не хватило ресурсов (например, слишком много сокетов).";
        break;
    case 5:
        socketErrorString = "Время для операции с сокетом истекло.";
        break;
    case 6:
        socketErrorString = "Дейтаграмма больше, чем установленное ограничение в операционной системе (которое может быть меньше, чем 8192 байт).";
        break;
    case 7:
        socketErrorString = "Произошла ошибка в сети (например, сетевой кабель был неожиданно отключён).";
        break;
    case 8:
        socketErrorString = "Адрес, определённый в QUdpSocket::bind(), уже используется и установлен в состояние эксклюзивного использования.";
        break;
    case 9:
        socketErrorString = "Адрес, определённый в QUdpSocket::bind(), не найден на узле.";
        break;
    case 10:
        socketErrorString = "Запрашиваемая операция с сокетом не поддерживается текущей операционной системой (например, отсутствует поддержка IPv6).";
        break;
    case 11:
        socketErrorString = "Used by QAbstractSocketEngine only, The last operation attempted has not finished yet (still in progress in the background)";
        break;
    case 12:
        socketErrorString = "Сокет использует прокси, который запрашивает аутентификацию.";
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

