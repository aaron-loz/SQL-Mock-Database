#include "editdbpopupdialog.h"
#include "ui_editdbpopupdialog.h"
#include <QDebug>
editDbPopupDialog::editDbPopupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editDbPopupDialog)
{
    ui->setupUi(this);
}

editDbPopupDialog::~editDbPopupDialog()
{
    delete ui;
}

void editDbPopupDialog::setEditableData(int &id, QString &FN, QString &LN){
    QString idString= QString::number(id);
    ui->IDEdit->setText(idString);//Quickly adds text to lineEdit for ease of use
    ui->FNEdit->setText(FN);
    ui->LNEdit->setText(LN);
    oldFN=FN;
}

void editDbPopupDialog::on_buttonBox_accepted()
{//So User can change the Query
    QSqlQuery acceptedQuery;
    int id=ui->IDEdit->text().toInt();
    QString FN=ui->FNEdit->text();
    QString LN=ui->LNEdit->text();
    acceptedQuery.exec(tr("UPDATE person SET firstname='%1', lastname='%2', id=%3 WHERE firstname='%4'").arg(FN).arg(LN).arg(id).arg(oldFN));
}
