#ifndef TESTERMLT_H
#define TESTERMLT_H

#include <QObject>
#include <tcp_client_tester.h>

class TesterMLT: public QObject
{
    Q_OBJECT

public:
    TesterMLT();

    //objects
    TCP_Client_Tester* tcpClientTester;

    //functions

private:
    QString hostAddr = "localhost";
    quint16 portNumber = 32002;

private slots:
    void slotSocketErrorInfo(QString);


signals:
    void signalSocketErrorInfoToWindow(QString);

};

#endif // TESTERMLT_H
