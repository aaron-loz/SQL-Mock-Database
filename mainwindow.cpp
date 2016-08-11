#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    addDialog(new addDbDialog),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if(!createConnection(db)){
        QMessageBox::critical(this, "SQL couldnt start", "There was an error starting SQL Service");
        return;
    }
}

MainWindow::~MainWindow()
{
    QSqlQuery endTestQuery;
    //!Deletes any test runs, remove before finished version
    if(endTestQuery.exec("DELETE FROM person")){
        qDebug()<<"deleted.";
    }
    delete ui;
}

void MainWindow::on_viewDbButton_clicked()
{
    QSqlQuery viewQuery;
    if(viewQuery.exec("SELECT * FROM person")){
        QSqlRecord testRecord=viewQuery.record();
        int fieldNum=testRecord.indexOf("firstname");
        QString labelText;

        while(viewQuery.next()){//indexes the 2nd column, firstname, and outputs it into qDebug for debugging
            qDebug()<<viewQuery.value(fieldNum).toString();
            labelText+="\n";
            labelText+=viewQuery.value(fieldNum).toString();
        }
        ui->label->setText(labelText);
    }
}

void MainWindow::on_EditDbButton_clicked()
{
   QSqlQuery editQuery;
   //!Create dialog that asks what person to edit,
   //!  then implements user input into editQuery, wherein brings up data for person to user,
   //!  then replaces data with whatever user edits data
}
void MainWindow::on_DelDbButton_clicked()
{
//!Creates Dialog with model of database for user to click,
//! Whichever one is selected, runs delQuery that,
//!Deletes whatever person's data is that the user identifies,
//! Then sends messagebox saying that data was deleted
}

void MainWindow::on_addDbButton_clicked()
{//for user to easily add more data to the database.
    QSqlQuery addQuery;
    if(addDialog->exec()){
    if(addQuery.exec(addDialog->queryLine)){
    QMessageBox::information(this, "Person Added", "The User was added. Press the 'view List' button to view the data");
    }
        else{//Only happens if data entered is not a string`
        QMessageBox::critical(this, "Error Adding Person", "Person's Data could not be added! \nInvalid!");
        }
    }
}
