#ifndef mkoq_MENU_H
#define mkoq_MENU_H

#include <QMainWindow>
#include "mkoq_xxsrest.h"
#include "mkoq_xxssave.h"
#include "mkoq_cdsnn.h"
#include "mkoq_cdstt.h"
#include "mkoq_tosxx.h"
#include "mkoq_pdsxx.h"
#include "mkoq_rjsxx.h"
#include "mkoq_rjtks.h"
#include "mkoq_kssrr.h"
#include "mkoq_cdsff.h"
#include "mkoq_ksrjj.h"
#include "mkoq_ksrvv.h"
#include "mkoq_ksroo.h"

namespace Ui {
class mkoq_menu;
}

class mkoq_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mkoq_menu(QWidget *parent = 0);
    ~mkoq_menu();

    mkoq_xxsrest* mkoq_xxsrest1;
    mkoq_xxssave* mkoq_xxssave1;
    mkoq_cdsnn* mkoq_cdsnn1;
    mkoq_cdstt* mkoq_cdstt1;
    mkoq_tosxx* mkoq_tosxx1;
    mkoq_pdsxx* mkoq_pdsxx1;
    mkoq_rjsxx* mkoq_rjsxx1;
    mkoq_rjtks* mkoq_rjtks1;
    mkoq_kssrr* mkoq_kssrr1;
    mkoq_cdsff* mkoq_cdsff1;
    mkoq_ksrvv* mkoq_ksrvv1;
    mkoq_ksrjj* mkoq_ksrjj1;
    mkoq_ksroo* mkoq_ksroo1;

private:
    Ui::mkoq_menu *ui;
    QSqlDatabase db;

private slots:
    void mkoq_menu_arch_xxsrest_cClick();
    void mkoq_menu_arch_xxssave_cClick();
    void mkoq_menu_end_close_cClick();
    void mkoq_menu_krt_cdsnn_cClick();
    void mkoq_menu_krt_tosxx_cClick();
    void mkoq_menu_dok_cdstt_cClick();
    void mkoq_menu_dok_pdsxx_cClick();
    void mkoq_menu_rj_rjsxx_cClick();
    void mkoq_menu_rj_rjtks_cClick();
    void mkoq_menu_rj_kssrr_cClick();
    void mkoq_menu_bo_cdsff_cClick();
    void mkoq_menu_bo_ksrvv_cClick();
    void mkoq_menu_bo_ksrjj_cClick();
    void mkoq_menu_bo_ksroo_cClick();
};

#endif // mkoq_MENU_H

