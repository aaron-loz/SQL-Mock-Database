#ifndef EDITDBPOPUPDIALOG_H
#define EDITDBPOPUPDIALOG_H

#include <QDialog>

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
    setEditableData(int &id, QString &FN, QString &LN);
private:
    Ui::editDbPopupDialog *ui;
    int idEdit;
    QString FNedit;
    QString LNedit;
};

#endif // EDITDBPOPUPDIALOG_H
