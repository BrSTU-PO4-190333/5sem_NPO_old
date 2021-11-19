#include "gpiq_rjsxx.h"
#include "ui_gpiq_rjsxx.h"

#include <QDebug>

gpiq_rjsxx::gpiq_rjsxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_rjsxx)
{
    ui->setupUi(this);
    connect(ui->gpiq_rjsxx_grid_c, SIGNAL(clicked()), this, SLOT(gpiq_rjsxx_grid_cClick()));
    connect(ui->gpiq_rjsxx_back_c, SIGNAL(clicked()), this, SLOT(gpiq_rjsxx_back_cClick()));
    connect(ui->gpiq_rjsxx_next_c, SIGNAL(clicked()), this, SLOT(gpiq_rjsxx_next_cClick()));
    connect(ui->gpiq_rjsxx_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_rjsxx_exit_cClick()));

    connect(ui->gpiq_rjsxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_dbn_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_db_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_dokk_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_data_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_data_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_dokn_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_dokd_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_kr_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_krn_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_to_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_to_eTextChanged(QString)));
    connect(ui->gpiq_rjsxx_rub_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_rjsxx_rub_eTextChanged(QString)));

    model.setTable("gpiq_rj");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);

    ui->gpiq_rjsxx_dbn_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_db_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_dokk_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_data_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_dokn_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_dokd_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_kr_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_krn_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_to_e->setStyleSheet("color: red;");
    ui->gpiq_rjsxx_rub_e->setStyleSheet("color: red;");
}

gpiq_rjsxx::~gpiq_rjsxx()
{
    delete ui;
}

void gpiq_rjsxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString gpiq_rj_db = model.record(currentIndex).value("Gpiq_rj_db").toString();
        QString gpiq_rj_dbn = model.record(currentIndex).value("Gpiq_rj_dbn").toString();
        QString gpiq_rj_dokk = model.record(currentIndex).value("Gpiq_rj_dokk").toString();
        QString gpiq_rj_dokd = model.record(currentIndex).value("Gpiq_rj_dokd").toString();
        QString gpiq_rj_dokn = model.record(currentIndex).value("Gpiq_rj_dokn").toString();
        QString gpiq_rj_data = model.record(currentIndex).value("Gpiq_rj_data").toString();
        QString gpiq_rj_to = model.record(currentIndex).value("Gpiq_rj_to").toString();
        QString gpiq_rj_kr = model.record(currentIndex).value("Gpiq_rj_kr").toString();
        QString gpiq_rj_krn = model.record(currentIndex).value("Gpiq_rj_krn").toString();
        QString gpiq_rj_rub = model.record(currentIndex).value("Gpiq_rj_rub").toString();
        ui->gpiq_rjsxx_db_e->setText(gpiq_rj_db);
        ui->gpiq_rjsxx_dbn_e->setText(gpiq_rj_dbn);
        ui->gpiq_rjsxx_dokk_e->setText(gpiq_rj_dokk);
        ui->gpiq_rjsxx_dokd_e->setText(gpiq_rj_dokd);
        ui->gpiq_rjsxx_dokn_e->setText(gpiq_rj_dokn);
        ui->gpiq_rjsxx_data_e->setText(gpiq_rj_data);
        ui->gpiq_rjsxx_kr_e->setText(gpiq_rj_kr);
        ui->gpiq_rjsxx_krn_e->setText(gpiq_rj_krn);
        ui->gpiq_rjsxx_rub_e->setText(gpiq_rj_rub);
        ui->gpiq_rjsxx_to_e->setText(gpiq_rj_to);
    }
}

void gpiq_rjsxx::gpiq_rjsxx_grid_cClick() {
   gpiq_xxsgrid* gpiq_xxsgrid1 = new gpiq_xxsgrid(this, &model, currentIndex);
   gpiq_xxsgrid1->setWindowTitle("gpiq_rjsxx  viberi dokument");
   gpiq_xxsgrid1->exec();
   changeEdits(gpiq_xxsgrid1->currentIndex);
}

void gpiq_rjsxx::gpiq_rjsxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void gpiq_rjsxx::gpiq_rjsxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void gpiq_rjsxx::gpiq_rjsxx_exit_cClick() {
    QDialog::reject();
}

void gpiq_rjsxx::gpiq_rjsxx_add_cClick() {
    model.insertRow(size);
    model.setData(model.index(size,0), 0);
    if(model.submitAll()) {
        model.database().commit();
    } else {
        model.database().rollback();
                qDebug() << "Database Write Error" <<
                     "The database reported an error: " <<
                       model.lastError().text();

    }
    size++;
    changeEdits(size - 1);
}

void gpiq_rjsxx::gpiq_rjsxx_del_cClick() {
    model.removeRow(currentIndex);
    if(model.submitAll()) {
        model.database().commit();
    } else {
        model.database().rollback();
                qDebug() << "Database Write Error" <<
                     "The database reported an error: " <<
                       model.lastError().text();

    }
    size--;
    model.select();
    changeEdits(currentIndex - 1);
}

void gpiq_rjsxx::gpiq_rjsxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_db")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_dbn")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_dokk")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_kr")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_krn")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_data_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_data")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_dokn")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_dokd")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_to")), text);
}

void gpiq_rjsxx::gpiq_rjsxx_rub_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Gpiq_rj_rub")), text);
}
