#ifndef EDITDBPOPUPDIALOG_H
#define EDITDBPOPUPDIALOG_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class editDbPopupDialog;
}

class editDbPopupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editDbPopupDialog(QWidget *parent = 0);
    ~editDbPopupDialog();
public slots:
    void setEditableData(int &id, QString &FN, QString &LN);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::editDbPopupDialog *ui;
    QString oldFN;
};

#endif // EDITDBPOPUPDIALOG_H
