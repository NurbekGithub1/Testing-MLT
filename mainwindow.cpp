#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testerMLT = new TesterMLT;

    connect(testerMLT,SIGNAL(signalSocketErrorInfoToWindow(QString)),this,SLOT(slotSocketErrorInfo(QString)));
    connect(testerMLT,SIGNAL(signalSocketConnectedInfoToWindow()),this,SLOT(slotSocketConnectedInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonRandomCoordinates_2_released()
{

}

void MainWindow::on_checkBox_toggled(bool checked)
{

}

void MainWindow::on_buttonRandomCoordinates_released()
{

}

void MainWindow::slotSocketErrorInfo(QString _socketError)
{
    //ui->socketErrorInfo->append(_socketError);
    ui->textBrowserConnectionState->clear();
    //ui->lineEditConnectionState->c
    ui->textBrowserConnectionState->setText(_socketError);
    ui->textBrowserConnectionState->setStyleSheet("QTextEdit{background-color:#FADBD8}");
}

void MainWindow::slotSocketConnectedInfo()
{
    ui->textBrowserConnectionState->clear();
    ui->textBrowserConnectionState->setText("Connected!");
    ui->textBrowserConnectionState->setStyleSheet("QTextEdit{background-color:#A9DFBF}");
}


