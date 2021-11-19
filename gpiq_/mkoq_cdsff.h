#ifndef mkoq_CDSFF_H
#define mkoq_CDSFF_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class mkoq_cdsff;
}

class mkoq_cdsff : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_cdsff(QWidget *parent = 0);
    ~mkoq_cdsff();

private:
    Ui::mkoq_cdsff *ui;

private slots:
    void mkoq_cdsff_exit_cClick();
    void reject();
};

#endif // mkoq_CDSFF_H
