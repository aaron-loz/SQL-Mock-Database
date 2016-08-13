#include "editdbdialog.h"
#include "ui_editdbdialog.h"

editDbDialog::editDbDialog(QWidget *parent) :
    QDialog(parent),
    popupDialog(new editDbPopupDialog),
    ui(new Ui::editDbDialog)
{
    ui->setupUi(this);
}

editDbDialog::~editDbDialog()
{
    delete ui;
}
void editDbDialog::updateTable(){
    mainQueryModel.setQuery("SELECT * FROM person");
    ui->tableView->setModel(&mainQueryModel);
}

void editDbDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(popupDialog->exec()){

    }
}
