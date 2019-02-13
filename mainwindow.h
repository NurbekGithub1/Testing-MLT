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
    void on_buttonRandomCoordinates_2_released();

    void on_checkBox_toggled(bool checked);

    void on_buttonRandomCoordinates_released();

    void slotSocketErrorInfo(QString);

    void slotSocketConnectedInfo();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
