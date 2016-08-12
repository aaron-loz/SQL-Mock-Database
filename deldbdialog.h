#ifndef DELDBDIALOG_H
#define DELDBDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

namespace Ui {
class delDbDialog;
}

class delDbDialog : public QDialog
{
    Q_OBJECT

public:
    explicit delDbDialog(QWidget *parent = 0);
    ~delDbDialog();
private:
    Ui::delDbDialog *ui;
    QSqlQueryModel mainQueryModel;
    QString *tempFirstName[10];
    QString *tempLastName[10];
    int *id[10];
public slots:
    void queryIntoModel();
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_buttonBox_rejected();
};

#endif // DELDBDIALOG_H
