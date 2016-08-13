#include "editdbpopupdialog.h"
#include "ui_editdbpopupdialog.h"

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
