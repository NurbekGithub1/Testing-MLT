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
    QString hostAddr = "127.0.0.1";
    quint16 portNumber = 32001;

private slots:
    void slotSocketErrorInfo(QString);
    void slotSocketConnectedInfo();


signals:
    void signalSocketErrorInfoToWindow(QString);
    void signalSocketConnectedInfoToWindow();

};

#endif // TESTERMLT_H
