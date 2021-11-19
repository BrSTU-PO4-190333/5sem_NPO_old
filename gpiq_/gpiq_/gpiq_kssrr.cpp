#include "gpiq_kssrr.h"
#include "ui_gpiq_kssrr.h"

#include <QDebug>

gpiq_kssrr::gpiq_kssrr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_kssrr)
{
    ui->setupUi(this);
    connect(ui->gpiq_kssrr_grid_c, SIGNAL(clicked()), this, SLOT(gpiq_kssrr_grid_cClick()));
    connect(ui->gpiq_kssrr_back_c, SIGNAL(clicked()), this, SLOT(gpiq_kssrr_back_cClick()));
    connect(ui->gpiq_kssrr_next_c, SIGNAL(clicked()), this, SLOT(gpiq_kssrr_next_cClick()));
    connect(ui->gpiq_kssrr_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_kssrr_exit_cClick()));

    connect(ui->gpiq_kssrr_data_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_data_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_dokd_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_dokk_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_ksn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_ksn_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_rubdb_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_rubdb_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_kr_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_kr_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_dokn_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_s_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_s_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_sn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_sn_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_to_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_to_eTextChanged(QString)));
    connect(ui->gpiq_kssrr_rubkr_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_kssrr_rubkr_eTextChanged(QString)));

    model.setTable("gpiq_ks");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);

    ui->gpiq_kssrr_data_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_dokd_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_dokk_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_ksn_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_rubdb_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_kr_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_dokn_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_s_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_sn_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_to_e->setStyleSheet("color: red;");
    ui->gpiq_kssrr_rubkr_e->setStyleSheet("color: red;");
}

gpiq_kssrr::~gpiq_kssrr()
{
    delete ui;
}

void gpiq_kssrr::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString gpiq_ks_data = model.record(currentIndex).value("Gpiq_ks_data").toString();
        QString gpiq_ks_dokd = model.record(currentIndex).value("Gpiq_ks_dokd").toString();
        QString gpiq_ks_dokk = model.record(currentIndex).value("Gpiq_ks_dokk").toString();
        QString gpiq_ks_rubdb = model.record(currentIndex).value("Gpiq_ks_rubdb").toString();
        QString gpiq_ks_kr = model.record(currentIndex).value("Gpiq_ks_ks").toString();
        QString gpiq_ks_ksn = model.record(currentIndex).value("Gpiq_ks_ksn").toString();
        QString gpiq_ks_dokn = model.record(currentIndex).value("Gpiq_ks_dokn").toString();
        QString gpiq_ks_s = model.record(currentIndex).value("Gpiq_ks_s").toString();
        QString gpiq_ks_sn = model.record(currentIndex).value("Gpiq_ks_sn").toString();
        QString gpiq_ks_to = model.record(currentIndex).value("Gpiq_ks_to").toString();
        QString gpiq_ks_rubkr = model.record(currentIndex).value("Gpiq_ks_rubkr").toString();
        ui->gpiq_kssrr_dokd_e->setText(gpiq_ks_data);
        ui->gpiq_kssrr_data_e->setText(gpiq_ks_dokd);
        ui->gpiq_kssrr_dokk_e->setText(gpiq_ks_dokk);
        ui->gpiq_kssrr_ksn_e->setText(gpiq_ks_ksn);
        ui->gpiq_kssrr_kr_e->setText(gpiq_ks_kr);
        ui->gpiq_kssrr_dokn_e->setText(gpiq_ks_dokn);
        ui->gpiq_kssrr_rubdb_e->setText(gpiq_ks_rubdb);
        ui->gpiq_kssrr_s_e->setText(gpiq_ks_s);
        ui->gpiq_kssrr_sn_e->setText(gpiq_ks_sn);
        ui->gpiq_kssrr_to_e->setText(gpiq_ks_to);
        ui->gpiq_kssrr_rubkr_e->setText(gpiq_ks_rubkr);
    }
}

void gpiq_kssrr::gpiq_kssrr_grid_cClick() {
   gpiq_xxsgrid* gpiq_xxsgrid1 = new gpiq_xxsgrid(this, &model, currentIndex);
   gpiq_xxsgrid1->setWindowTitle("gpiq_kssrr  viberi operaciu");
   gpiq_xxsgrid1->exec();
   changeEdits(gpiq_xxsgrid1->currentIndex);
}

void gpiq_kssrr::gpiq_kssrr_back_cClick() {
    changeEdits(currentIndex - 1);
}

void gpiq_kssrr::gpiq_kssrr_next_cClick() {
    changeEdits(currentIndex + 1);
}

void gpiq_kssrr::gpiq_kssrr_exit_cClick() {
    QDialog::reject();
}

void gpiq_kssrr::gpiq_kssrr_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_dokd")), text);
}

void gpiq_kssrr::gpiq_kssrr_data_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_data")), text);
}

void gpiq_kssrr::gpiq_kssrr_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_dokk")), text);
}

void gpiq_kssrr::gpiq_kssrr_ksn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_ksn")), text);
}

void gpiq_kssrr::gpiq_kssrr_rubdb_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_rubdb")), text);
}

void gpiq_kssrr::gpiq_kssrr_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_kr")), text);
}

void gpiq_kssrr::gpiq_kssrr_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_dokn")), text);
}

void gpiq_kssrr::gpiq_kssrr_s_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_s")), text);
}

void gpiq_kssrr::gpiq_kssrr_sn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_sn")), text);
}

void gpiq_kssrr::gpiq_kssrr_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_to")), text);
}

void gpiq_kssrr::gpiq_kssrr_rubkr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_ks_rubkr")), text);
}
