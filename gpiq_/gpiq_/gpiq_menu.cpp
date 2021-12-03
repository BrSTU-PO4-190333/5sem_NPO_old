#include "gpiq_menu.h"
#include "ui_gpiq_menu.h"

gpiq_menu::gpiq_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gpiq_menu)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    qDebug() << QApplication::applicationDirPath();
    db.setDatabaseName("./gpiq_data.sqlite");

    if (!db.open())
        {
        qDebug() << db.lastError().text();
        }

    if (db.open())
        {
        qDebug() << "OK";
        }

    connect(ui->gpiq_menu_arch_xxsrest_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_arch_xxsrest_cClick()));
    connect(ui->gpiq_menu_arch_xxssave_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_arch_xxssave_cClick()));
    connect(ui->gpiq_menu_end_close_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_end_close_cClick()));
    connect(ui->gpiq_menu_krt_cdsnn_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_krt_cdsnn_cClick()));
    connect(ui->gpiq_menu_krt_tosxx_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_krt_tosxx_cClick()));
    connect(ui->gpiq_menu_dok_cdstt_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_dok_cdstt_cClick()));
    connect(ui->gpiq_menu_dok_pdsxx_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_dok_pdsxx_cClick()));
    connect(ui->gpiq_menu_rj_rjsxx_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_rj_rjsxx_cClick()));
    connect(ui->gpiq_menu_rj_rjtks_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_rj_rjtks_cClick()));
    connect(ui->gpiq_menu_rj_kssrr_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_rj_kssrr_cClick()));
    connect(ui->gpiq_menu_bo_cdsff_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_bo_cdsff_cClick()));
    connect(ui->gpiq_menu_bo_ksrvv_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_bo_ksrvv_cClick()));
    connect(ui->gpiq_menu_bo_ksrjj_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_bo_ksrjj_cClick()));
    connect(ui->gpiq_menu_bo_ksroo_c, SIGNAL(clicked()), this, SLOT(gpiq_menu_bo_ksroo_cClick()));
}

gpiq_menu::~gpiq_menu()
{
    delete ui;
}

void gpiq_menu::gpiq_menu_arch_xxsrest_cClick() {
    gpiq_xxsrest1 = new gpiq_xxsrest;
    gpiq_xxsrest1->setWindowFlags(gpiq_xxsrest1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_xxsrest1->show();
}

void gpiq_menu::gpiq_menu_arch_xxssave_cClick() {
    gpiq_xxssave1 = new gpiq_xxssave;
    gpiq_xxssave1->setWindowFlags(gpiq_xxssave1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_xxssave1->show();
}

void gpiq_menu::gpiq_menu_end_close_cClick(){
    exit(0);
}

void gpiq_menu::gpiq_menu_krt_cdsnn_cClick() {
    gpiq_cdsnn1 = new gpiq_cdsnn;
    gpiq_cdsnn1->setWindowFlags(gpiq_cdsnn1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_cdsnn1->show();
}

void gpiq_menu::gpiq_menu_dok_cdstt_cClick() {
    gpiq_cdstt1 = new gpiq_cdstt;
    gpiq_cdstt1->setWindowFlags(gpiq_cdstt1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_cdstt1->show();
}

void gpiq_menu::gpiq_menu_krt_tosxx_cClick() {
    gpiq_tosxx1 = new gpiq_tosxx;
    gpiq_tosxx1->setWindowFlags(gpiq_tosxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_tosxx1->show();
}

void gpiq_menu::gpiq_menu_dok_pdsxx_cClick() {
    gpiq_pdsxx1 = new gpiq_pdsxx;
    gpiq_pdsxx1->setWindowFlags(gpiq_pdsxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_pdsxx1->show();
}

void gpiq_menu::gpiq_menu_rj_rjsxx_cClick() {
    gpiq_rjsxx1 = new gpiq_rjsxx;
    gpiq_rjsxx1->setWindowFlags(gpiq_rjsxx1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_rjsxx1->show();
}

void gpiq_menu::gpiq_menu_rj_rjtks_cClick() {
    gpiq_rjtks1 = new gpiq_rjtks;
    gpiq_rjtks1->setWindowFlags(gpiq_rjtks1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_rjtks1->show();
}

void gpiq_menu::gpiq_menu_rj_kssrr_cClick() {
    gpiq_kssrr1 = new gpiq_kssrr;
    gpiq_kssrr1->setWindowFlags(gpiq_kssrr1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_kssrr1->show();
}

void gpiq_menu::gpiq_menu_bo_cdsff_cClick() {
    gpiq_cdsff1 = new gpiq_cdsff;
    gpiq_cdsff1->setWindowFlags(gpiq_cdsff1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_cdsff1->show();
}

void gpiq_menu::gpiq_menu_bo_ksrvv_cClick() {
    gpiq_ksrvv1 = new gpiq_ksrvv;
    gpiq_ksrvv1->setWindowFlags(gpiq_ksrvv1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_ksrvv1->show();
}

void gpiq_menu::gpiq_menu_bo_ksrjj_cClick() {
    gpiq_ksrjj1 = new gpiq_ksrjj;
    gpiq_ksrjj1->setWindowFlags(gpiq_ksrjj1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_ksrjj1->show();
}


void gpiq_menu::gpiq_menu_bo_ksroo_cClick() {
    gpiq_ksroo1 = new gpiq_ksroo;
    gpiq_ksroo1->setWindowFlags(gpiq_ksroo1->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    gpiq_ksroo1->show();
}

