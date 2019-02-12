#ifndef TESTERMLT_H
#define TESTERMLT_H

#include <QObject>
#include <tcp_client_tester.h>


class TesterMLT
{
public:
    TesterMLT();

    //objects
    TCP_Client_Tester* tcpClientTester;

    //functions

private:
    QString hostName = "";
    int portNumber = 2323;

};

#endif // TESTERMLT_H
