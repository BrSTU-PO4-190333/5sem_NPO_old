#include "mkoq_kssrr.h"
#include "ui_mkoq_kssrr.h"

#include <QDebug>

mkoq_kssrr::mkoq_kssrr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_kssrr)
{
    ui->setupUi(this);
    connect(ui->mkoq_kssrr_grid_c, SIGNAL(clicked()), this, SLOT(mkoq_kssrr_grid_cClick()));
    connect(ui->mkoq_kssrr_back_c, SIGNAL(clicked()), this, SLOT(mkoq_kssrr_back_cClick()));
    connect(ui->mkoq_kssrr_next_c, SIGNAL(clicked()), this, SLOT(mkoq_kssrr_next_cClick()));
    connect(ui->mkoq_kssrr_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_kssrr_exit_cClick()));

    connect(ui->mkoq_kssrr_data_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_data_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_dokd_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_dokk_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_ksn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_ksn_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_rubdb_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_rubdb_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_kr_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_kr_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_dokn_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_s_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_s_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_sn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_sn_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_to_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_to_eTextChanged(QString)));
    connect(ui->mkoq_kssrr_rubkr_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_kssrr_rubkr_eTextChanged(QString)));

    model.setTable("mkoq_ks");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);

    ui->mkoq_kssrr_data_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_dokd_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_dokk_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_ksn_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_rubdb_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_kr_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_dokn_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_s_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_sn_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_to_e->setStyleSheet("color: red;");
    ui->mkoq_kssrr_rubkr_e->setStyleSheet("color: red;");
}

mkoq_kssrr::~mkoq_kssrr()
{
    delete ui;
}

void mkoq_kssrr::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString mkoq_ks_data = model.record(currentIndex).value("Mkoq_ks_data").toString();
        QString mkoq_ks_dokd = model.record(currentIndex).value("Mkoq_ks_dokd").toString();
        QString mkoq_ks_dokk = model.record(currentIndex).value("Mkoq_ks_dokk").toString();
        QString mkoq_ks_rubdb = model.record(currentIndex).value("Mkoq_ks_rubdb").toString();
        QString mkoq_ks_kr = model.record(currentIndex).value("Mkoq_ks_ks").toString();
        QString mkoq_ks_ksn = model.record(currentIndex).value("Mkoq_ks_ksn").toString();
        QString mkoq_ks_dokn = model.record(currentIndex).value("Mkoq_ks_dokn").toString();
        QString mkoq_ks_s = model.record(currentIndex).value("Mkoq_ks_s").toString();
        QString mkoq_ks_sn = model.record(currentIndex).value("Mkoq_ks_sn").toString();
        QString mkoq_ks_to = model.record(currentIndex).value("Mkoq_ks_to").toString();
        QString mkoq_ks_rubkr = model.record(currentIndex).value("Mkoq_ks_rubkr").toString();
        ui->mkoq_kssrr_dokd_e->setText(mkoq_ks_data);
        ui->mkoq_kssrr_data_e->setText(mkoq_ks_dokd);
        ui->mkoq_kssrr_dokk_e->setText(mkoq_ks_dokk);
        ui->mkoq_kssrr_ksn_e->setText(mkoq_ks_ksn);
        ui->mkoq_kssrr_kr_e->setText(mkoq_ks_kr);
        ui->mkoq_kssrr_dokn_e->setText(mkoq_ks_dokn);
        ui->mkoq_kssrr_rubdb_e->setText(mkoq_ks_rubdb);
        ui->mkoq_kssrr_s_e->setText(mkoq_ks_s);
        ui->mkoq_kssrr_sn_e->setText(mkoq_ks_sn);
        ui->mkoq_kssrr_to_e->setText(mkoq_ks_to);
        ui->mkoq_kssrr_rubkr_e->setText(mkoq_ks_rubkr);
    }
}

void mkoq_kssrr::mkoq_kssrr_grid_cClick() {
   mkoq_xxsgrid* mkoq_xxsgrid1 = new mkoq_xxsgrid(this, &model, currentIndex);
   mkoq_xxsgrid1->setWindowTitle("mkoq_kssrr  viberi operaciu");
   mkoq_xxsgrid1->exec();
   changeEdits(mkoq_xxsgrid1->currentIndex);
}

void mkoq_kssrr::mkoq_kssrr_back_cClick() {
    changeEdits(currentIndex - 1);
}

void mkoq_kssrr::mkoq_kssrr_next_cClick() {
    changeEdits(currentIndex + 1);
}

void mkoq_kssrr::mkoq_kssrr_exit_cClick() {
    QDialog::reject();
}

void mkoq_kssrr::mkoq_kssrr_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_dokd")), text);
}

void mkoq_kssrr::mkoq_kssrr_data_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_data")), text);
}

void mkoq_kssrr::mkoq_kssrr_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_dokk")), text);
}

void mkoq_kssrr::mkoq_kssrr_ksn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_ksn")), text);
}

void mkoq_kssrr::mkoq_kssrr_rubdb_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_rubdb")), text);
}

void mkoq_kssrr::mkoq_kssrr_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_kr")), text);
}

void mkoq_kssrr::mkoq_kssrr_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_dokn")), text);
}

void mkoq_kssrr::mkoq_kssrr_s_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_s")), text);
}

void mkoq_kssrr::mkoq_kssrr_sn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_sn")), text);
}

void mkoq_kssrr::mkoq_kssrr_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_to")), text);
}

void mkoq_kssrr::mkoq_kssrr_rubkr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_ks_rubkr")), text);
}
