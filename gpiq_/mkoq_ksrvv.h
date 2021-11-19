#ifndef mkoq_KSRVV_H
#define mkoq_KSRVV_H

#include <QDialog>

namespace Ui {
class mkoq_ksrvv;
}

class mkoq_ksrvv : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_ksrvv(QWidget *parent = 0);
    ~mkoq_ksrvv();

private:
    Ui::mkoq_ksrvv *ui;

private slots:
    void mkoq_ksrvv_exit_cClick();
};

#endif // mkoq_KSRVV_H
