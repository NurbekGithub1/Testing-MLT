#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testerMLT = new TesterMLT;
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


