#ifndef mkoq_KSSRR_H
#define mkoq_KSSRR_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "mkoq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class mkoq_kssrr;
}

class mkoq_kssrr : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_kssrr(QWidget *parent = 0);
    ~mkoq_kssrr();


private:
    Ui::mkoq_kssrr *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void mkoq_kssrr_grid_cClick();
    void mkoq_kssrr_back_cClick();
    void mkoq_kssrr_next_cClick();
    void mkoq_kssrr_exit_cClick();

    void mkoq_kssrr_data_eTextChanged(QString);
    void mkoq_kssrr_dokd_eTextChanged(QString);
    void mkoq_kssrr_dokk_eTextChanged(QString);
    void mkoq_kssrr_ksn_eTextChanged(QString);
    void mkoq_kssrr_rubdb_eTextChanged(QString);
    void mkoq_kssrr_kr_eTextChanged(QString);
    void mkoq_kssrr_dokn_eTextChanged(QString);
    void mkoq_kssrr_s_eTextChanged(QString);
    void mkoq_kssrr_sn_eTextChanged(QString);
    void mkoq_kssrr_to_eTextChanged(QString);
    void mkoq_kssrr_rubkr_eTextChanged(QString);

};

#endif // mkoq_kssrr_H
