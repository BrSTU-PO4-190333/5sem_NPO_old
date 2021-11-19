#ifndef gpiq_KSRVV_H
#define gpiq_KSRVV_H

#include <QDialog>

namespace Ui {
class gpiq_ksrvv;
}

class gpiq_ksrvv : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_ksrvv(QWidget *parent = 0);
    ~gpiq_ksrvv();

private:
    Ui::gpiq_ksrvv *ui;

private slots:
    void gpiq_ksrvv_exit_cClick();
};

#endif // gpiq_KSRVV_H
