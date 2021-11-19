#ifndef gpiq_RJTKS_H
#define gpiq_RJTKS_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include "gpiq_xxsgrid.h"

namespace Ui {
class gpiq_rjtks;
}

class gpiq_rjtks : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_rjtks(QWidget *parent = 0);
    ~gpiq_rjtks();

private:
    Ui::gpiq_rjtks *ui;
    QSqlTableModel model_rj;
    QSqlTableModel model_ks;
    int index_rj, index_ks, size_rj, size_ks;

    void changeIndexRJ(int newIndex);
    void changeIndexKS(int newIndex);

private slots:
    void gpiq_rjtks_gridrj_cClick();
    void gpiq_rjtks_gridks_cClick();
    void gpiq_rjtks_wk_cClick();
    void gpiq_rjtks_exit_cClick();
};

#endif // gpiq_RJTKS_H
