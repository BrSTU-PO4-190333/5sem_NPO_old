#ifndef mkoq_KSROO_H
#define mkoq_KSROO_H

#include <QDialog>

namespace Ui {
class mkoq_ksroo;
}

class mkoq_ksroo : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_ksroo(QWidget *parent = 0);
    ~mkoq_ksroo();

private:
    Ui::mkoq_ksroo *ui;

private slots:
    void mkoq_ksroo_exit_cClick();
    void on_mkoq_ksroo_print_c_clicked();
};

#endif // mkoq_KSROO_H
