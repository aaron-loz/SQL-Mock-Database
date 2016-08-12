#include "editdbdialog.h"
#include "ui_editdbdialog.h"

editDbDialog::editDbDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editDbDialog)
{
    ui->setupUi(this);
}

editDbDialog::~editDbDialog()
{
    delete ui;
}
