#ifndef DELDBDIALOG_H
#define DELDBDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

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
public slots:
    void setupTable();
private slots:
};

#endif // DELDBDIALOG_H
