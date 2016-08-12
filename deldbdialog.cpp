#include "deldbdialog.h"
#include "ui_deldbdialog.h"
#include <QDebug>
#include <QMessageBox>


delDbDialog::delDbDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delDbDialog)
{//!Initializes TableView, user double clicks/selects one of the database persons. Then QMessageBox confirms deletion,
    //!Then sends Delete command for sqlQuery
    this->setSizeGripEnabled(false);
    ui->setupUi(this);
    for(int i=0;i<10;i++){
        //array of pointers in case of multiple mistaken deletions by the user.
    tempFirstName[i]= new QString;
    tempLastName[i]= new QString;
    id[i]=new int;
    }
    setWindowTitle(tr("Delete Person From Database"));
}

void delDbDialog::queryIntoModel(){
    mainQueryModel.setQuery("SELECT * FROM person");
    ui->tableView->setModel(&mainQueryModel);
}


delDbDialog::~delDbDialog()
{
    delete ui;
}

void delDbDialog::on_tableView_doubleClicked(const QModelIndex &index)
{//In case user mistakenly deletes name, uses temp storing to create record for reject() slot
    QString indexName = mainQueryModel.record(index.row()).value("firstname").toString();
    QString lastName = mainQueryModel.record(index.row()).value("lastname").toString();
    int tempId = mainQueryModel.record(index.row()).value("id").toInt();

    //confirm messsage in case of mistakenly double clicking
    QString confirmMessage=tr("Are you sure you want to delete %1?").arg(indexName);
    QMessageBox::StandardButton reply =QMessageBox::question(this,"Sure?",confirmMessage);

    if(reply == QMessageBox::Yes){
        mainQueryModel.setQuery(tr("DELETE FROM person WHERE firstname='%1' AND lastname='%2'").arg(indexName).arg(lastName));
        queryIntoModel();//Is Called again to update tableView without any graphical problems
        for(int i=0;i<10;i++){
            //doesnt store tempdata unless user clicks yes.Currently, array stores first ten names deleted
            if(tempFirstName[i]->isEmpty()){
            *tempFirstName[i]=indexName;
            qDebug()<<i<<": ";
            qDebug()<<*tempFirstName[i];
            *tempLastName[i]=lastName;
            *id[i]=tempId;
            break;
            }
        }
    }
}

void delDbDialog::on_buttonBox_rejected()
{//If user clicks cancel, re-adds all the names previously removed from the query. Works for up to 10 removed data.
    QSqlQuery rejectQuery;
    for(int i=0;i<10;i++){
        if(!tempFirstName[i]->isEmpty())
        rejectQuery.exec(tr("INSERT INTO person (id, firstname, lastname) VALUES (%0, '%1','%2')")
                         .arg(*id[i]).arg(*tempFirstName[i]).arg(*tempLastName[i]));
    }
}
//!Planning on sorting via column through tableView data
