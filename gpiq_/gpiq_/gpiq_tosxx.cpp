#include "gpiq_tosxx.h"
#include "ui_gpiq_tosxx.h"

#include <QDebug>

gpiq_tosxx::gpiq_tosxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_tosxx)
{
    ui->setupUi(this);
    connect(ui->gpiq_tosxx_grid_c, SIGNAL(clicked()), this, SLOT(gpiq_tosxx_grid_cClick()));
    connect(ui->gpiq_tosxx_back_c, SIGNAL(clicked()), this, SLOT(gpiq_tosxx_back_cClick()));
    connect(ui->gpiq_tosxx_next_c, SIGNAL(clicked()), this, SLOT(gpiq_tosxx_next_cClick()));
    connect(ui->gpiq_tosxx_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_tosxx_exit_cClick()));
    connect(ui->gpiq_tosxx_add_c, SIGNAL(clicked()), this, SLOT(gpiq_tosxx_add_cClick()));
    connect(ui->gpiq_tosxx_del_c, SIGNAL(clicked()), this, SLOT(gpiq_tosxx_del_cClick()));

    connect(ui->gpiq_tosxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_tosxx_dbn_eTextChanged(QString)));
    connect(ui->gpiq_tosxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_tosxx_db_eTextChanged(QString)));
    connect(ui->gpiq_tosxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_tosxx_dokk_eTextChanged(QString)));
    connect(ui->gpiq_tosxx_k_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_tosxx_k_eTextChanged(QString)));
    connect(ui->gpiq_tosxx_n_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_tosxx_n_eTextChanged(QString)));
    connect(ui->gpiq_tosxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_tosxx_kr_eTextChanged(QString)));
    connect(ui->gpiq_tosxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_tosxx_krn_eTextChanged(QString)));

    model.setTable("gpiq_to");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

gpiq_tosxx::~gpiq_tosxx()
{
    delete ui;
}

void gpiq_tosxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString gpiq_to_db = model.record(currentIndex).value("gpiq_to_db").toString();
        QString gpiq_to_dbn = model.record(currentIndex).value("gpiq_to_dbn").toString();
        QString gpiq_to_dokk = model.record(currentIndex).value("gpiq_to_dokk").toString();
        QString gpiq_to_k = model.record(currentIndex).value("gpiq_to_k").toString();
        QString gpiq_to_kr = model.record(currentIndex).value("gpiq_to_kr").toString();
        QString gpiq_to_krn = model.record(currentIndex).value("gpiq_to_krn").toString();
        QString gpiq_to_n = model.record(currentIndex).value("gpiq_to_n").toString();
        ui->gpiq_tosxx_db_e->setText(gpiq_to_db);
        ui->gpiq_tosxx_dbn_e->setText(gpiq_to_dbn);
        ui->gpiq_tosxx_dokk_e->setText(gpiq_to_dokk);
        ui->gpiq_tosxx_k_e->setText(gpiq_to_k);
        ui->gpiq_tosxx_kr_e->setText(gpiq_to_kr);
        ui->gpiq_tosxx_krn_e->setText(gpiq_to_krn);
        ui->gpiq_tosxx_n_e->setText(gpiq_to_n);
    }
}

void gpiq_tosxx::gpiq_tosxx_grid_cClick() {
   gpiq_xxsgrid* gpiq_xxsgrid1 = new gpiq_xxsgrid(this, &model, currentIndex);
   gpiq_xxsgrid1->setWindowTitle("gpiq_tosxx  viberi operaciu");
   gpiq_xxsgrid1->exec();
   changeEdits(gpiq_xxsgrid1->currentIndex);
}

void gpiq_tosxx::gpiq_tosxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void gpiq_tosxx::gpiq_tosxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void gpiq_tosxx::gpiq_tosxx_exit_cClick() {
    QDialog::reject();
}

void gpiq_tosxx::gpiq_tosxx_add_cClick() {
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

void gpiq_tosxx::gpiq_tosxx_del_cClick() {
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

void gpiq_tosxx::gpiq_tosxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_to_db")), text);
}

void gpiq_tosxx::gpiq_tosxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_to_dbn")), text);
}

void gpiq_tosxx::gpiq_tosxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_to_dokk")), text);
}

void gpiq_tosxx::gpiq_tosxx_k_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_to_k")), text);
}

void gpiq_tosxx::gpiq_tosxx_n_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_to_n")), text);
}

void gpiq_tosxx::gpiq_tosxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_to_kr")), text);
}

void gpiq_tosxx::gpiq_tosxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_to_krn")), text);
}
