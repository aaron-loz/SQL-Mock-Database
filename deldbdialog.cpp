#include "deldbdialog.h"
#include "ui_deldbdialog.h"

delDbDialog::delDbDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delDbDialog)
{//!Initializes TableView, user double clicks/selects one of the database persons. Then QMessageBox confirms deletion,
    //!Then sends Delete command for sqlQuery
    ui->setupUi(this);
    setWindowTitle(tr("Delete Person From Database"));
}

void delDbDialog::setupTable(){
}

delDbDialog::~delDbDialog()
{
    delete ui;
}
