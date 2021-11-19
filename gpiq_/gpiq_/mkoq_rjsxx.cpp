#include "mkoq_rjsxx.h"
#include "ui_mkoq_rjsxx.h"

#include <QDebug>

mkoq_rjsxx::mkoq_rjsxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_rjsxx)
{
    ui->setupUi(this);
    connect(ui->mkoq_rjsxx_grid_c, SIGNAL(clicked()), this, SLOT(mkoq_rjsxx_grid_cClick()));
    connect(ui->mkoq_rjsxx_back_c, SIGNAL(clicked()), this, SLOT(mkoq_rjsxx_back_cClick()));
    connect(ui->mkoq_rjsxx_next_c, SIGNAL(clicked()), this, SLOT(mkoq_rjsxx_next_cClick()));
    connect(ui->mkoq_rjsxx_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_rjsxx_exit_cClick()));

    connect(ui->mkoq_rjsxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_dbn_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_db_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_dokk_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_data_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_data_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_dokn_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_dokd_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_kr_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_krn_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_to_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_to_eTextChanged(QString)));
    connect(ui->mkoq_rjsxx_rub_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_rjsxx_rub_eTextChanged(QString)));

    model.setTable("mkoq_rj");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);

    ui->mkoq_rjsxx_dbn_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_db_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_dokk_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_data_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_dokn_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_dokd_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_kr_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_krn_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_to_e->setStyleSheet("color: red;");
    ui->mkoq_rjsxx_rub_e->setStyleSheet("color: red;");
}

mkoq_rjsxx::~mkoq_rjsxx()
{
    delete ui;
}

void mkoq_rjsxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString mkoq_rj_db = model.record(currentIndex).value("Mkoq_rj_db").toString();
        QString mkoq_rj_dbn = model.record(currentIndex).value("Mkoq_rj_dbn").toString();
        QString mkoq_rj_dokk = model.record(currentIndex).value("Mkoq_rj_dokk").toString();
        QString mkoq_rj_dokd = model.record(currentIndex).value("Mkoq_rj_dokd").toString();
        QString mkoq_rj_dokn = model.record(currentIndex).value("Mkoq_rj_dokn").toString();
        QString mkoq_rj_data = model.record(currentIndex).value("Mkoq_rj_data").toString();
        QString mkoq_rj_to = model.record(currentIndex).value("Mkoq_rj_to").toString();
        QString mkoq_rj_kr = model.record(currentIndex).value("Mkoq_rj_kr").toString();
        QString mkoq_rj_krn = model.record(currentIndex).value("Mkoq_rj_krn").toString();
        QString mkoq_rj_rub = model.record(currentIndex).value("Mkoq_rj_rub").toString();
        ui->mkoq_rjsxx_db_e->setText(mkoq_rj_db);
        ui->mkoq_rjsxx_dbn_e->setText(mkoq_rj_dbn);
        ui->mkoq_rjsxx_dokk_e->setText(mkoq_rj_dokk);
        ui->mkoq_rjsxx_dokd_e->setText(mkoq_rj_dokd);
        ui->mkoq_rjsxx_dokn_e->setText(mkoq_rj_dokn);
        ui->mkoq_rjsxx_data_e->setText(mkoq_rj_data);
        ui->mkoq_rjsxx_kr_e->setText(mkoq_rj_kr);
        ui->mkoq_rjsxx_krn_e->setText(mkoq_rj_krn);
        ui->mkoq_rjsxx_rub_e->setText(mkoq_rj_rub);
        ui->mkoq_rjsxx_to_e->setText(mkoq_rj_to);
    }
}

void mkoq_rjsxx::mkoq_rjsxx_grid_cClick() {
   mkoq_xxsgrid* mkoq_xxsgrid1 = new mkoq_xxsgrid(this, &model, currentIndex);
   mkoq_xxsgrid1->setWindowTitle("mkoq_rjsxx  viberi dokument");
   mkoq_xxsgrid1->exec();
   changeEdits(mkoq_xxsgrid1->currentIndex);
}

void mkoq_rjsxx::mkoq_rjsxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void mkoq_rjsxx::mkoq_rjsxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void mkoq_rjsxx::mkoq_rjsxx_exit_cClick() {
    QDialog::reject();
}

void mkoq_rjsxx::mkoq_rjsxx_add_cClick() {
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

void mkoq_rjsxx::mkoq_rjsxx_del_cClick() {
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

void mkoq_rjsxx::mkoq_rjsxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_db")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_dbn")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_dokk")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_kr")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_krn")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_data_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_data")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_dokn")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_dokd")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_to")), text);
}

void mkoq_rjsxx::mkoq_rjsxx_rub_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_rj_rub")), text);
}
