#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <testermlt.h>

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
    QString serverHostAddress;
    int serverPortNumber;

private slots:
    void on_buttonRandomCoordinates_2_released();

    void on_checkBox_toggled(bool checked);

    void on_buttonRandomCoordinates_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
