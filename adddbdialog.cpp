#include "adddbdialog.h"
#include "ui_adddbdialog.h"

addDbDialog::addDbDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDbDialog)
{//extra dialog created for ease of use
    ui->setupUi(this);
}

addDbDialog::~addDbDialog()
{
    delete ui;
}

void addDbDialog::on_addDbDialog_accepted()
{
    // on MW, Query will add the params from a mock, public SqlQuery.
    queryLine = tr("INSERT INTO person (firstname, lastname) VALUES ('%1', '%2')").arg(ui->FNLineEdit->text()).arg(ui->LNLineEdit->text());
}
