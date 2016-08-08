#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if(!createConnection(db)){
        QMessageBox::critical(this, "SQL couldnt start", "There was an error starting SQL Service");
        return;
    }
    QSqlQuery mainQuery;
    if(mainQuery.exec("SELECT * FROM person")){
        QSqlRecord testRecord=mainQuery.record();
        qDebug()<<"Number of Columns: "<< testRecord.count();
        int fieldNum=testRecord.indexOf("firstname");
        while(mainQuery.next()){//indexes the 2nd column, firstname, and outputs it into qDebug
            qDebug()<<mainQuery.value(fieldNum).toString();
        }
    }
}

void MainWindow::addData(){

}

MainWindow::~MainWindow()
{
    delete ui;
}
