#ifndef gpiq_KSSRR_H
#define gpiq_KSSRR_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "gpiq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class gpiq_kssrr;
}

class gpiq_kssrr : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_kssrr(QWidget *parent = 0);
    ~gpiq_kssrr();


private:
    Ui::gpiq_kssrr *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void gpiq_kssrr_grid_cClick();
    void gpiq_kssrr_back_cClick();
    void gpiq_kssrr_next_cClick();
    void gpiq_kssrr_exit_cClick();

    void gpiq_kssrr_data_eTextChanged(QString);
    void gpiq_kssrr_dokd_eTextChanged(QString);
    void gpiq_kssrr_dokk_eTextChanged(QString);
    void gpiq_kssrr_ksn_eTextChanged(QString);
    void gpiq_kssrr_rubdb_eTextChanged(QString);
    void gpiq_kssrr_kr_eTextChanged(QString);
    void gpiq_kssrr_dokn_eTextChanged(QString);
    void gpiq_kssrr_s_eTextChanged(QString);
    void gpiq_kssrr_sn_eTextChanged(QString);
    void gpiq_kssrr_to_eTextChanged(QString);
    void gpiq_kssrr_rubkr_eTextChanged(QString);

};

#endif // gpiq_kssrr_H
