#include "testermlt.h"


TesterMLT::TesterMLT()
{
    tcpClientTester = new TCP_Client_Tester(hostAddr,portNumber);

    connect(tcpClientTester,SIGNAL(signalSocketError(QString)),this,SLOT(slotSocketErrorInfo(QString)));
}

void TesterMLT::slotSocketErrorInfo(QString _socketError)
{
    emit signalSocketErrorInfoToWindow(_socketError);
}
