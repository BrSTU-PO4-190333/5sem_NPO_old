#ifndef gpiq_RJSXX_H
#define gpiq_RJSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "gpiq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class gpiq_rjsxx;
}

class gpiq_rjsxx : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_rjsxx(QWidget *parent = 0);
    ~gpiq_rjsxx();

private:
    Ui::gpiq_rjsxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void gpiq_rjsxx_grid_cClick();
    void gpiq_rjsxx_back_cClick();
    void gpiq_rjsxx_next_cClick();
    void gpiq_rjsxx_exit_cClick();
    void gpiq_rjsxx_add_cClick();
    void gpiq_rjsxx_del_cClick();

    void gpiq_rjsxx_dbn_eTextChanged(QString);
    void gpiq_rjsxx_db_eTextChanged(QString);
    void gpiq_rjsxx_dokk_eTextChanged(QString);
    void gpiq_rjsxx_dokd_eTextChanged(QString);
    void gpiq_rjsxx_dokn_eTextChanged(QString);
    void gpiq_rjsxx_data_eTextChanged(QString);
    void gpiq_rjsxx_kr_eTextChanged(QString);
    void gpiq_rjsxx_krn_eTextChanged(QString);
    void gpiq_rjsxx_to_eTextChanged(QString);
    void gpiq_rjsxx_rub_eTextChanged(QString);
};

#endif // gpiq_RJSXX_H

