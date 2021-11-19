#ifndef mkoq_TOSXX_H
#define mkoq_TOSXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "mkoq_xxsgrid.h"

#include <QSqlError>

namespace Ui {
class mkoq_tosxx;
}

class mkoq_tosxx : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_tosxx(QWidget *parent = 0);
    ~mkoq_tosxx();


private:
    Ui::mkoq_tosxx *ui;

    void changeEdits(int newIndex);

    QSqlTableModel model;
    int size;
    int currentIndex;

private slots:
    void mkoq_tosxx_grid_cClick();
    void mkoq_tosxx_back_cClick();
    void mkoq_tosxx_next_cClick();
    void mkoq_tosxx_exit_cClick();
    void mkoq_tosxx_add_cClick();
    void mkoq_tosxx_del_cClick();

    void mkoq_tosxx_dbn_eTextChanged(QString);
    void mkoq_tosxx_db_eTextChanged(QString);
    void mkoq_tosxx_dokk_eTextChanged(QString);
    void mkoq_tosxx_k_eTextChanged(QString);
    void mkoq_tosxx_n_eTextChanged(QString);
    void mkoq_tosxx_kr_eTextChanged(QString);
    void mkoq_tosxx_krn_eTextChanged(QString);
};

#endif // mkoq_TOSXX_H
