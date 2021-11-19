#ifndef gpiq_PDSXX_H
#define gpiq_PDSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include "gpiq_xxsgrid.h"
#include "gpiq_togxx.h"

#include <QSqlError>

namespace Ui {
class gpiq_pdsxx;
}

class gpiq_pdsxx : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_pdsxx(QWidget *parent = 0);
    ~gpiq_pdsxx();


private:
    Ui::gpiq_pdsxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void gpiq_pdsxx_grid_cClick();
    void gpiq_pdsxx_back_cClick();
    void gpiq_pdsxx_next_cClick();
    void gpiq_pdsxx_exit_cClick();
    void gpiq_pdsxx_add_cClick();
    void gpiq_pdsxx_del_cClick();
    void gpiq_pdsxx_pdtrj_cClick();
    void gpiq_pdsxx_to_cClick();

    void gpiq_pdsxx_dbn_eTextChanged(QString);
    void gpiq_pdsxx_db_eTextChanged(QString);
    void gpiq_pdsxx_dokk_eTextChanged(QString);
    void gpiq_pdsxx_dokn_eTextChanged(QString);
    void gpiq_pdsxx_dokd_eTextChanged(QString);
    void gpiq_pdsxx_kr_eTextChanged(QString);
    void gpiq_pdsxx_to_eTextChanged(QString);
    void gpiq_pdsxx_rub_eTextChanged(QString);
    void gpiq_pdsxx_krn_eTextChanged(QString);
};

#endif // gpiq_PDSXX_H
