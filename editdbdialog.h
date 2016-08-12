#ifndef EDITDBDIALOG_H
#define EDITDBDIALOG_H

#include <QDialog>

namespace Ui {
class editDbDialog;
}

class editDbDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editDbDialog(QWidget *parent = 0);
    ~editDbDialog();

private:
    Ui::editDbDialog *ui;
};

#endif // EDITDBDIALOG_H
