#include "adddbdialog.h"
#include "ui_adddbdialog.h"

addDbDialog::addDbDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDbDialog)
{
    ui->setupUi(this);
    //!Adds the Lineedits params, mainly no numbers
    foreach(QLineEdit *lineEdit,this->findChildren<QLineEdit*>()){
        if(!lineEdit){

        }
    }
}

addDbDialog::~addDbDialog()
{
    delete ui;
}

void addDbDialog::on_addDbDialog_accepted()
{
    //!If the lineEdit's params are met to be added to the QsqlQuery, this will continue,
    //! on MW, Query will add the params from a mock, public SqlQuery.
    i++;
    queryLine = tr("INSERT INTO person VAL%UES(%1, '%2', '%3')").arg(i).arg(ui->FNLineEdit->text()).arg(ui->LNLineEdit->text());
}
