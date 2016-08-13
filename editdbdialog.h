#ifndef EDITDBDIALOG_H
#define EDITDBDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>
#include "editdbpopupdialog.h"
namespace Ui {
class editDbDialog;
}

class editDbDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editDbDialog(QWidget *parent = 0);
    ~editDbDialog();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
public slots:
    void updateTable();

private:
    editDbPopupDialog *popupDialog;
    Ui::editDbDialog *ui;
    QSqlQueryModel mainQueryModel;
};

#endif // EDITDBDIALOG_H
