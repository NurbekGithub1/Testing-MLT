#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <testermlt.h>
#include <enums.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    TesterMLT* testerMLT;

private slots:

    void slotSocketErrorInfo(QString);

    void slotSocketConnectedInfo(QAbstractSocket::SocketState);

    void on_buttonSendCoordinates_clicked();

    void on_buttonConnectToServer_clicked();

signals:

    void buttonConnectToServerClicked();
    void buttonSendCoordinateClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
