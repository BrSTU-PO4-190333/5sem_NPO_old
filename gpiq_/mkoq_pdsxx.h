#ifndef mkoq_PDSXX_H
#define mkoq_PDSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include "mkoq_xxsgrid.h"
#include "mkoq_togxx.h"

#include <QSqlError>

namespace Ui {
class mkoq_pdsxx;
}

class mkoq_pdsxx : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_pdsxx(QWidget *parent = 0);
    ~mkoq_pdsxx();


private:
    Ui::mkoq_pdsxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void mkoq_pdsxx_grid_cClick();
    void mkoq_pdsxx_back_cClick();
    void mkoq_pdsxx_next_cClick();
    void mkoq_pdsxx_exit_cClick();
    void mkoq_pdsxx_add_cClick();
    void mkoq_pdsxx_del_cClick();
    void mkoq_pdsxx_pdtrj_cClick();
    void mkoq_pdsxx_to_cClick();

    void mkoq_pdsxx_dbn_eTextChanged(QString);
    void mkoq_pdsxx_db_eTextChanged(QString);
    void mkoq_pdsxx_dokk_eTextChanged(QString);
    void mkoq_pdsxx_dokn_eTextChanged(QString);
    void mkoq_pdsxx_dokd_eTextChanged(QString);
    void mkoq_pdsxx_kr_eTextChanged(QString);
    void mkoq_pdsxx_to_eTextChanged(QString);
    void mkoq_pdsxx_rub_eTextChanged(QString);
    void mkoq_pdsxx_krn_eTextChanged(QString);
};

#endif // mkoq_PDSXX_H
