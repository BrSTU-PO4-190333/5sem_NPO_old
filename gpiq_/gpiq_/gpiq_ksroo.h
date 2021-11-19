#ifndef gpiq_KSROO_H
#define gpiq_KSROO_H

#include <QDialog>

namespace Ui {
class gpiq_ksroo;
}

class gpiq_ksroo : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_ksroo(QWidget *parent = 0);
    ~gpiq_ksroo();

private:
    Ui::gpiq_ksroo *ui;

private slots:
    void gpiq_ksroo_exit_cClick();
    void on_gpiq_ksroo_print_c_clicked();
};

#endif // gpiq_KSROO_H
