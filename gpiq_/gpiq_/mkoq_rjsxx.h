#ifndef mkoq_RJSXX_H
#define mkoq_RJSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "mkoq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class mkoq_rjsxx;
}

class mkoq_rjsxx : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_rjsxx(QWidget *parent = 0);
    ~mkoq_rjsxx();

private:
    Ui::mkoq_rjsxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void mkoq_rjsxx_grid_cClick();
    void mkoq_rjsxx_back_cClick();
    void mkoq_rjsxx_next_cClick();
    void mkoq_rjsxx_exit_cClick();
    void mkoq_rjsxx_add_cClick();
    void mkoq_rjsxx_del_cClick();

    void mkoq_rjsxx_dbn_eTextChanged(QString);
    void mkoq_rjsxx_db_eTextChanged(QString);
    void mkoq_rjsxx_dokk_eTextChanged(QString);
    void mkoq_rjsxx_dokd_eTextChanged(QString);
    void mkoq_rjsxx_dokn_eTextChanged(QString);
    void mkoq_rjsxx_data_eTextChanged(QString);
    void mkoq_rjsxx_kr_eTextChanged(QString);
    void mkoq_rjsxx_krn_eTextChanged(QString);
    void mkoq_rjsxx_to_eTextChanged(QString);
    void mkoq_rjsxx_rub_eTextChanged(QString);
};

#endif // mkoq_RJSXX_H

