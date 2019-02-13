#ifndef TCP_CLIENT_TESTER_H
#define TCP_CLIENT_TESTER_H

#include <QObject>
#include <QWidget>
#include <QtNetwork/QTcpSocket>

class TCP_Client_Tester : public QObject
{
    Q_OBJECT

public:

    TCP_Client_Tester();
    TCP_Client_Tester(QString _hostAddr, quint16 _portNumber);

    QTcpSocket* clientTcpSocket;

private:
    QString hostAddr = " ";
    quint16 portNumber = 0;

private slots:
    void slotConnected();
    void slotDisconnected();
    void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotReadyRead();

signals:
    void signalSocketError(QString);
    void signalConnected();
};

#endif // TCP_CLIENT_TESTER_H
