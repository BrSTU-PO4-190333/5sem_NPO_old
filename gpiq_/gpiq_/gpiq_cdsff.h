#ifndef gpiq_CDSFF_H
#define gpiq_CDSFF_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class gpiq_cdsff;
}

class gpiq_cdsff : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_cdsff(QWidget *parent = 0);
    ~gpiq_cdsff();

private:
    Ui::gpiq_cdsff *ui;

private slots:
    void gpiq_cdsff_exit_cClick();
    void reject();
};

#endif // gpiq_CDSFF_H
