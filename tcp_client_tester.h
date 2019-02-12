#ifndef TCP_CLIENT_TESTER_H
#define TCP_CLIENT_TESTER_H

#include <QObject>
#include <QWidget>
#include <QtNetwork/QTcpSocket>


class TCP_Client_Tester
{
public:
    TCP_Client_Tester();
    QTcpSocket* TcpSocket;
};

#endif // TCP_CLIENT_TESTER_H
