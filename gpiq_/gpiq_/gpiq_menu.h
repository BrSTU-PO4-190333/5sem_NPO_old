#ifndef gpiq_MENU_H
#define gpiq_MENU_H

#include <QMainWindow>
#include "gpiq_xxsrest.h"
#include "gpiq_xxssave.h"
#include "gpiq_cdsnn.h"
#include "gpiq_cdstt.h"
#include "gpiq_tosxx.h"
#include "gpiq_pdsxx.h"
#include "gpiq_rjsxx.h"
#include "gpiq_rjtks.h"
#include "gpiq_kssrr.h"
#include "gpiq_cdsff.h"
#include "gpiq_ksrjj.h"
#include "gpiq_ksrvv.h"
#include "gpiq_ksroo.h"

namespace Ui {
class gpiq_menu;
}

class gpiq_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit gpiq_menu(QWidget *parent = 0);
    ~gpiq_menu();

    gpiq_xxsrest* gpiq_xxsrest1;
    gpiq_xxssave* gpiq_xxssave1;
    gpiq_cdsnn* gpiq_cdsnn1;
    gpiq_cdstt* gpiq_cdstt1;
    gpiq_tosxx* gpiq_tosxx1;
    gpiq_pdsxx* gpiq_pdsxx1;
    gpiq_rjsxx* gpiq_rjsxx1;
    gpiq_rjtks* gpiq_rjtks1;
    gpiq_kssrr* gpiq_kssrr1;
    gpiq_cdsff* gpiq_cdsff1;
    gpiq_ksrvv* gpiq_ksrvv1;
    gpiq_ksrjj* gpiq_ksrjj1;
    gpiq_ksroo* gpiq_ksroo1;

private:
    Ui::gpiq_menu *ui;
    QSqlDatabase db;

private slots:
    void gpiq_menu_arch_xxsrest_cClick();
    void gpiq_menu_arch_xxssave_cClick();
    void gpiq_menu_end_close_cClick();
    void gpiq_menu_krt_cdsnn_cClick();
    void gpiq_menu_krt_tosxx_cClick();
    void gpiq_menu_dok_cdstt_cClick();
    void gpiq_menu_dok_pdsxx_cClick();
    void gpiq_menu_rj_rjsxx_cClick();
    void gpiq_menu_rj_rjtks_cClick();
    void gpiq_menu_rj_kssrr_cClick();
    void gpiq_menu_bo_cdsff_cClick();
    void gpiq_menu_bo_ksrvv_cClick();
    void gpiq_menu_bo_ksrjj_cClick();
    void gpiq_menu_bo_ksroo_cClick();
};

#endif // gpiq_MENU_H

