#ifndef ADDDBDIALOG_H
#define ADDDBDIALOG_H

#include <QDialog>

namespace Ui {
class addDbDialog;
}

class addDbDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDbDialog(QWidget *parent = 0);
    ~addDbDialog();
    QString queryLine;

private slots:
    void on_addDbDialog_accepted();

private:
    Ui::addDbDialog *ui;
};

#endif // ADDDBDIALOG_H
