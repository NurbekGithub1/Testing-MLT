#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testerMLT = new TesterMLT;

    connect(testerMLT,SIGNAL(signalSocketErrorInfoToWindow(QString)),this,SLOT(slotSocketErrorInfo(QString)));
    connect(testerMLT,SIGNAL(signalSocketConnectedInfoToWindow(QAbstractSocket::SocketState)),this,SLOT(slotSocketConnectedInfo(QAbstractSocket::SocketState)));
    connect(this,SIGNAL(buttonConnectToServerClicked()),testerMLT,SLOT(slotConnectToServer()));
    connect(this,SIGNAL(buttonSendCoordinateClicked()),testerMLT,SLOT(slotSendCoordinateToServer()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotSocketErrorInfo(QString _socketError)
{
    //ui->socketErrorInfo->append(_socketError);
    ui->textBrowserConnectionState->clear();
    //ui->lineEditConnectionState->c
    ui->textBrowserConnectionState->setText(_socketError);
    ui->textBrowserConnectionState->setStyleSheet("QTextEdit{background-color:#FADBD8}");
}

void MainWindow::slotSocketConnectedInfo(QAbstractSocket::SocketState _socketState)
{
    ui->textBrowserConnectionState->clear();
    ui->textBrowserConnectionState->setText(QString(_socketState));
    ui->textBrowserConnectionState->setStyleSheet("QTextEdit{background-color:#A9DFBF}");
}



void MainWindow::on_buttonSendCoordinates_clicked()
{
    emit buttonSendCoordinateClicked();
}

void MainWindow::on_buttonConnectToServer_clicked()
{
    emit buttonConnectToServerClicked();
}
