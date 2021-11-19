#include "mkoq_tosxx.h"
#include "ui_mkoq_tosxx.h"

#include <QDebug>

mkoq_tosxx::mkoq_tosxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_tosxx)
{
    ui->setupUi(this);
    connect(ui->mkoq_tosxx_grid_c, SIGNAL(clicked()), this, SLOT(mkoq_tosxx_grid_cClick()));
    connect(ui->mkoq_tosxx_back_c, SIGNAL(clicked()), this, SLOT(mkoq_tosxx_back_cClick()));
    connect(ui->mkoq_tosxx_next_c, SIGNAL(clicked()), this, SLOT(mkoq_tosxx_next_cClick()));
    connect(ui->mkoq_tosxx_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_tosxx_exit_cClick()));
    connect(ui->mkoq_tosxx_add_c, SIGNAL(clicked()), this, SLOT(mkoq_tosxx_add_cClick()));
    connect(ui->mkoq_tosxx_del_c, SIGNAL(clicked()), this, SLOT(mkoq_tosxx_del_cClick()));

    connect(ui->mkoq_tosxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_tosxx_dbn_eTextChanged(QString)));
    connect(ui->mkoq_tosxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_tosxx_db_eTextChanged(QString)));
    connect(ui->mkoq_tosxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_tosxx_dokk_eTextChanged(QString)));
    connect(ui->mkoq_tosxx_k_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_tosxx_k_eTextChanged(QString)));
    connect(ui->mkoq_tosxx_n_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_tosxx_n_eTextChanged(QString)));
    connect(ui->mkoq_tosxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_tosxx_kr_eTextChanged(QString)));
    connect(ui->mkoq_tosxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_tosxx_krn_eTextChanged(QString)));

    model.setTable("mkoq_to");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

mkoq_tosxx::~mkoq_tosxx()
{
    delete ui;
}

void mkoq_tosxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString mkoq_to_db = model.record(currentIndex).value("Mkoq_to_db").toString();
        QString mkoq_to_dbn = model.record(currentIndex).value("Mkoq_to_dbn").toString();
        QString mkoq_to_dokk = model.record(currentIndex).value("Mkoq_to_dokk").toString();
        QString mkoq_to_k = model.record(currentIndex).value("Mkoq_to_k").toString();
        QString mkoq_to_kr = model.record(currentIndex).value("Mkoq_to_kr").toString();
        QString mkoq_to_krn = model.record(currentIndex).value("Mkoq_to_krn").toString();
        QString mkoq_to_n = model.record(currentIndex).value("Mkoq_to_n").toString();
        ui->mkoq_tosxx_db_e->setText(mkoq_to_db);
        ui->mkoq_tosxx_dbn_e->setText(mkoq_to_dbn);
        ui->mkoq_tosxx_dokk_e->setText(mkoq_to_dokk);
        ui->mkoq_tosxx_k_e->setText(mkoq_to_k);
        ui->mkoq_tosxx_kr_e->setText(mkoq_to_kr);
        ui->mkoq_tosxx_krn_e->setText(mkoq_to_krn);
        ui->mkoq_tosxx_n_e->setText(mkoq_to_n);
    }
}

void mkoq_tosxx::mkoq_tosxx_grid_cClick() {
   mkoq_xxsgrid* mkoq_xxsgrid1 = new mkoq_xxsgrid(this, &model, currentIndex);
   mkoq_xxsgrid1->setWindowTitle("mkoq_tosxx  viberi operaciu");
   mkoq_xxsgrid1->exec();
   changeEdits(mkoq_xxsgrid1->currentIndex);
}

void mkoq_tosxx::mkoq_tosxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void mkoq_tosxx::mkoq_tosxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void mkoq_tosxx::mkoq_tosxx_exit_cClick() {
    QDialog::reject();
}

void mkoq_tosxx::mkoq_tosxx_add_cClick() {
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

void mkoq_tosxx::mkoq_tosxx_del_cClick() {
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

void mkoq_tosxx::mkoq_tosxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_to_db")), text);
}

void mkoq_tosxx::mkoq_tosxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_to_dbn")), text);
}

void mkoq_tosxx::mkoq_tosxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_to_dokk")), text);
}

void mkoq_tosxx::mkoq_tosxx_k_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_to_k")), text);
}

void mkoq_tosxx::mkoq_tosxx_n_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_to_n")), text);
}

void mkoq_tosxx::mkoq_tosxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_to_kr")), text);
}

void mkoq_tosxx::mkoq_tosxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_to_krn")), text);
}
