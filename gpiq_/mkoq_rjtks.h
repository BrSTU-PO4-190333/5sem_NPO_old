#ifndef mkoq_RJTKS_H
#define mkoq_RJTKS_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include "mkoq_xxsgrid.h"

namespace Ui {
class mkoq_rjtks;
}

class mkoq_rjtks : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_rjtks(QWidget *parent = 0);
    ~mkoq_rjtks();

private:
    Ui::mkoq_rjtks *ui;
    QSqlTableModel model_rj;
    QSqlTableModel model_ks;
    int index_rj, index_ks, size_rj, size_ks;

    void changeIndexRJ(int newIndex);
    void changeIndexKS(int newIndex);

private slots:
    void mkoq_rjtks_gridrj_cClick();
    void mkoq_rjtks_gridks_cClick();
    void mkoq_rjtks_wk_cClick();
    void mkoq_rjtks_exit_cClick();
};

#endif // mkoq_RJTKS_H
