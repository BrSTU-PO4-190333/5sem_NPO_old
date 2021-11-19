#ifndef gpiq_TOSXX_H
#define gpiq_TOSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "gpiq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class gpiq_tosxx;
}

class gpiq_tosxx : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_tosxx(QWidget *parent = 0);
    ~gpiq_tosxx();


private:
    Ui::gpiq_tosxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void gpiq_tosxx_grid_cClick();
    void gpiq_tosxx_back_cClick();
    void gpiq_tosxx_next_cClick();
    void gpiq_tosxx_exit_cClick();
    void gpiq_tosxx_add_cClick();
    void gpiq_tosxx_del_cClick();

    void gpiq_tosxx_dbn_eTextChanged(QString);
    void gpiq_tosxx_db_eTextChanged(QString);
    void gpiq_tosxx_dokk_eTextChanged(QString);
    void gpiq_tosxx_k_eTextChanged(QString);
    void gpiq_tosxx_n_eTextChanged(QString);
    void gpiq_tosxx_kr_eTextChanged(QString);
    void gpiq_tosxx_krn_eTextChanged(QString);
};

#endif // gpiq_TOSXX_H
