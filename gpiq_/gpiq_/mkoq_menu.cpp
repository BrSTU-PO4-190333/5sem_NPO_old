#include "mkoq_menu.h"
#include "ui_mkoq_menu.h"

mkoq_menu::mkoq_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mkoq_menu)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    qDebug() << QApplication::applicationDirPath();
    db.setDatabaseName("D:/3-Kypc-ProgII/NPO/mkoq_/mkoq_data.sqlite");
    if (!db.open()) {
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "OK";

    }
    connect(ui->mkoq_menu_arch_xxsrest_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_arch_xxsrest_cClick()));
    connect(ui->mkoq_menu_arch_xxssave_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_arch_xxssave_cClick()));
    connect(ui->mkoq_menu_end_close_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_end_close_cClick()));
    connect(ui->mkoq_menu_krt_cdsnn_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_krt_cdsnn_cClick()));
    connect(ui->mkoq_menu_krt_tosxx_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_krt_tosxx_cClick()));
    connect(ui->mkoq_menu_dok_cdstt_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_dok_cdstt_cClick()));
    connect(ui->mkoq_menu_dok_pdsxx_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_dok_pdsxx_cClick()));
    connect(ui->mkoq_menu_rj_rjsxx_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_rj_rjsxx_cClick()));
    connect(ui->mkoq_menu_rj_rjtks_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_rj_rjtks_cClick()));
    connect(ui->mkoq_menu_rj_kssrr_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_rj_kssrr_cClick()));
    connect(ui->mkoq_menu_bo_cdsff_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_bo_cdsff_cClick()));
    connect(ui->mkoq_menu_bo_ksrvv_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_bo_ksrvv_cClick()));
    connect(ui->mkoq_menu_bo_ksrjj_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_bo_ksrjj_cClick()));
    connect(ui->mkoq_menu_bo_ksroo_c, SIGNAL(clicked()), this, SLOT(mkoq_menu_bo_ksroo_cClick()));
}

mkoq_menu::~mkoq_menu()
{
    delete ui;
}

void mkoq_menu::mkoq_menu_arch_xxsrest_cClick() {
    mkoq_xxsrest1 = new mkoq_xxsrest;
    mkoq_xxsrest1->setWindowFlags(mkoq_xxsrest1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_xxsrest1->show();
}

void mkoq_menu::mkoq_menu_arch_xxssave_cClick() {
    mkoq_xxssave1 = new mkoq_xxssave;
    mkoq_xxssave1->setWindowFlags(mkoq_xxssave1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_xxssave1->show();
}

void mkoq_menu::mkoq_menu_end_close_cClick(){
    exit(0);
}

void mkoq_menu::mkoq_menu_krt_cdsnn_cClick() {
    mkoq_cdsnn1 = new mkoq_cdsnn;
    mkoq_cdsnn1->setWindowFlags(mkoq_cdsnn1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_cdsnn1->show();
}

void mkoq_menu::mkoq_menu_dok_cdstt_cClick() {
    mkoq_cdstt1 = new mkoq_cdstt;
    mkoq_cdstt1->setWindowFlags(mkoq_cdstt1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_cdstt1->show();
}

void mkoq_menu::mkoq_menu_krt_tosxx_cClick() {
    mkoq_tosxx1 = new mkoq_tosxx;
    mkoq_tosxx1->setWindowFlags(mkoq_tosxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_tosxx1->show();
}

void mkoq_menu::mkoq_menu_dok_pdsxx_cClick() {
    mkoq_pdsxx1 = new mkoq_pdsxx;
    mkoq_pdsxx1->setWindowFlags(mkoq_pdsxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_pdsxx1->show();
}

void mkoq_menu::mkoq_menu_rj_rjsxx_cClick() {
    mkoq_rjsxx1 = new mkoq_rjsxx;
    mkoq_rjsxx1->setWindowFlags(mkoq_rjsxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_rjsxx1->show();
}

void mkoq_menu::mkoq_menu_rj_rjtks_cClick() {
    mkoq_rjtks1 = new mkoq_rjtks;
    mkoq_rjtks1->setWindowFlags(mkoq_rjtks1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_rjtks1->show();
}

void mkoq_menu::mkoq_menu_rj_kssrr_cClick() {
    mkoq_kssrr1 = new mkoq_kssrr;
    mkoq_kssrr1->setWindowFlags(mkoq_kssrr1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_kssrr1->show();
}

void mkoq_menu::mkoq_menu_bo_cdsff_cClick() {
    mkoq_cdsff1 = new mkoq_cdsff;
    mkoq_cdsff1->setWindowFlags(mkoq_cdsff1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_cdsff1->show();
}

void mkoq_menu::mkoq_menu_bo_ksrvv_cClick() {
    mkoq_ksrvv1 = new mkoq_ksrvv;
    mkoq_ksrvv1->setWindowFlags(mkoq_ksrvv1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_ksrvv1->show();
}

void mkoq_menu::mkoq_menu_bo_ksrjj_cClick() {
    mkoq_ksrjj1 = new mkoq_ksrjj;
    mkoq_ksrjj1->setWindowFlags(mkoq_ksrjj1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_ksrjj1->show();
}


void mkoq_menu::mkoq_menu_bo_ksroo_cClick() {
    mkoq_ksroo1 = new mkoq_ksroo;
    mkoq_ksroo1->setWindowFlags(mkoq_ksroo1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    mkoq_ksroo1->show();
}

