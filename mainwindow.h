#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createconnection.h"
#include "adddbdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_viewDbButton_clicked();

    void on_EditDbButton_clicked();

    void on_DelDbButton_clicked();

    void on_addDbButton_clicked();

private:
    QSqlQuery mainQuery;
    addDbDialog *addDialog;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
