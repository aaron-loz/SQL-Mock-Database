#include "editdbdialog.h"
#include "ui_editdbdialog.h"
#include <QSqlRecord>
editDbDialog::editDbDialog(QWidget *parent) :
    QDialog(parent),
    popupDialog(new editDbPopupDialog),
    ui(new Ui::editDbDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Edit Database"));
}

editDbDialog::~editDbDialog()
{
    delete ui;
}
void editDbDialog::updateTable(){//Allows table to update constantly with any change
    mainQueryModel.setQuery("SELECT * FROM person");
    ui->tableView->setModel(&mainQueryModel);
}

void editDbDialog::on_tableView_doubleClicked(const QModelIndex &index)
{//Instead of relying on Ok Button, double click is the one used.
    QString firstIndex = mainQueryModel.record(index.row()).value("firstname").toString();
    QString lastIndex = mainQueryModel.record(index.row()).value("lastname").toString();
    int idIndex = mainQueryModel.record(index.row()).value("id").toInt();
    popupDialog->setEditableData(idIndex, firstIndex, lastIndex);
    if(popupDialog->exec()){
        updateTable();
    }
}
