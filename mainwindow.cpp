#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    addDialog(new addDbDialog),
    delDialog(new delDbDialog),
    editDialog(new editDbDialog),
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
    delete ui;
}

void MainWindow::on_viewDbButton_clicked()
{
    QSqlQuery viewQuery;
    if(viewQuery.exec("SELECT * FROM person")){
        QSqlRecord testRecord=viewQuery.record();
        int firstNum=testRecord.indexOf("firstname");
        int lastNum=testRecord.indexOf("lastname");
        QString labelText;

        while(viewQuery.next()){//indexes the 2nd column, firstname, and outputs it for quick User visibility
            labelText+="\n";
            labelText+=viewQuery.value(firstNum).toString();
            labelText+=" ";
            labelText+=viewQuery.value(lastNum).toString();
        }
        ui->label->setText(labelText);
    }
}

void MainWindow::on_EditDbButton_clicked()
{
   //  then implements user input into a Query, wherein brings up data for person to user,
    editDialog->updateTable();
    if(editDialog->exec()){
    }
}
void MainWindow::on_DelDbButton_clicked()
{
//Deletes whatever person's data is that the user identifies through doubleclick
    delDialog->queryIntoModel();
    if(delDialog->exec()){
    }
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
