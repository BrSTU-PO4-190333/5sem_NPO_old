#include "gpiq_pdsxx.h"
#include "ui_gpiq_pdsxx.h"

#include <QDebug>

gpiq_pdsxx::gpiq_pdsxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_pdsxx)
{
    ui->setupUi(this);
    connect(ui->gpiq_pdsxx_grid_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_grid_cClick()));
    connect(ui->gpiq_pdsxx_back_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_back_cClick()));
    connect(ui->gpiq_pdsxx_next_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_next_cClick()));
    connect(ui->gpiq_pdsxx_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_exit_cClick()));
    connect(ui->gpiq_pdsxx_add_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_add_cClick()));
    connect(ui->gpiq_pdsxx_del_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_del_cClick()));
    connect(ui->gpiq_pdsxx_pdtrj_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_pdtrj_cClick()));
    connect(ui->gpiq_pdsxx_to_c, SIGNAL(clicked()), this, SLOT(gpiq_pdsxx_to_cClick()));

    connect(ui->gpiq_pdsxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_dbn_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_db_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_dokk_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_dokn_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_dokd_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_rub_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_rub_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_kr_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_to_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_to_eTextChanged(QString)));
    connect(ui->gpiq_pdsxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(gpiq_pdsxx_krn_eTextChanged(QString)));

    ui->gpiq_pdsxx_to_e->setStyleSheet("color: red;");
    ui->gpiq_pdsxx_dbn_e->setStyleSheet("color: red;");
    ui->gpiq_pdsxx_db_e->setStyleSheet("color: red;");
    ui->gpiq_pdsxx_kr_e->setStyleSheet("color: red;");
    ui->gpiq_pdsxx_db_l->setStyleSheet("color: red;");
    ui->gpiq_pdsxx_kr_l->setStyleSheet("color: red;");
    ui->gpiq_pdsxx_krn_e->setStyleSheet("color: red;");

    model.setTable("gpiq_pd");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

gpiq_pdsxx::~gpiq_pdsxx()
{
    delete ui;
}

void gpiq_pdsxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString gpiq_pd_db = model.record(currentIndex).value("gpiq_pd_db").toString();
        QString gpiq_pd_dbn = model.record(currentIndex).value("gpiq_pd_dbn").toString();
        QString gpiq_pd_dokk = model.record(currentIndex).value("gpiq_pd_dokk").toString();
        QString gpiq_pd_dokd = model.record(currentIndex).value("gpiq_pd_dokd").toString();
        QString gpiq_pd_dokn = model.record(currentIndex).value("gpiq_pd_dokn").toString();
        QString gpiq_pd_kr = model.record(currentIndex).value("gpiq_pd_kr").toString();
        QString gpiq_pd_krn = model.record(currentIndex).value("gpiq_pd_krn").toString();
        QString gpiq_pd_rub = model.record(currentIndex).value("gpiq_pd_rub").toString();
        QString gpiq_pd_to = model.record(currentIndex).value("gpiq_pd_to").toString();
        ui->gpiq_pdsxx_db_e->setText(gpiq_pd_db);
        ui->gpiq_pdsxx_dbn_e->setText(gpiq_pd_dbn);
        ui->gpiq_pdsxx_dokk_e->setText(gpiq_pd_dokk);
        ui->gpiq_pdsxx_dokn_e->setText(gpiq_pd_dokn);
        ui->gpiq_pdsxx_dokd_e->setText(gpiq_pd_dokd);
        ui->gpiq_pdsxx_kr_e->setText(gpiq_pd_kr);
        ui->gpiq_pdsxx_krn_e->setText(gpiq_pd_krn);
        ui->gpiq_pdsxx_rub_e->setText(gpiq_pd_rub);
        ui->gpiq_pdsxx_to_e->setText(gpiq_pd_to);
    }
}

void gpiq_pdsxx::gpiq_pdsxx_grid_cClick() {
   gpiq_xxsgrid* gpiq_xxsgrid1 = new gpiq_xxsgrid(this, &model, currentIndex);
   gpiq_xxsgrid1->setWindowTitle("gpiq_pdsxx  viberi dokument");
   gpiq_xxsgrid1->exec();
   changeEdits(gpiq_xxsgrid1->currentIndex);
}

void gpiq_pdsxx::gpiq_pdsxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void gpiq_pdsxx::gpiq_pdsxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void gpiq_pdsxx::gpiq_pdsxx_exit_cClick() {
    QDialog::reject();
}

void gpiq_pdsxx::gpiq_pdsxx_add_cClick() {
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

    QSqlQuery query("SELECT gpiq_cd_datat FROM gpiq_cd");
    query.next();
    QString gpiq_cd_datatt = query.value(0).toString();
    ui->gpiq_pdsxx_dokd_e->setText(gpiq_cd_datatt);
}

void gpiq_pdsxx::gpiq_pdsxx_del_cClick() {
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

void gpiq_pdsxx::gpiq_pdsxx_pdtrj_cClick() {
    QSqlQuery query;
    query.prepare("INSERT INTO gpiq_rj VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue("0");
    query.addBindValue(ui->gpiq_pdsxx_dokd_e->text());
    query.addBindValue(ui->gpiq_pdsxx_dokk_e->text());
    query.addBindValue(ui->gpiq_pdsxx_dokn_e->text().toInt());
    query.addBindValue(ui->gpiq_pdsxx_dokd_e->text());
    query.addBindValue(ui->gpiq_pdsxx_to_e->text());
    query.addBindValue(ui->gpiq_pdsxx_db_e->text().toInt());
    query.addBindValue(ui->gpiq_pdsxx_dbn_e->text());
    query.addBindValue(ui->gpiq_pdsxx_kr_e->text().toInt());
    query.addBindValue(ui->gpiq_pdsxx_krn_e->text());
    query.addBindValue(ui->gpiq_pdsxx_rub_e->text().toInt());
    query.exec();
}

void gpiq_pdsxx::gpiq_pdsxx_to_cClick() {
    gpiq_togxx* gpiq_togxx1 = new gpiq_togxx(this);
    gpiq_togxx1->setWindowTitle("gpiq_pdsxx  viberi operaciu");
    gpiq_togxx1->exec();
    ui->gpiq_pdsxx_db_e->setText(gpiq_togxx1->gpiq_to_db);
    ui->gpiq_pdsxx_dbn_e->setText(gpiq_togxx1->gpiq_to_dbn);
    ui->gpiq_pdsxx_kr_e->setText(gpiq_togxx1->gpiq_to_kr);
    ui->gpiq_pdsxx_krn_e->setText(gpiq_togxx1->gpiq_to_krn);
    ui->gpiq_pdsxx_to_e->setText(gpiq_togxx1->gpiq_to_k);
}

void gpiq_pdsxx::gpiq_pdsxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_db")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_dbn")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_dokk")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_dokd")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_dokn")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_kr")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_krn")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_to")), text);
}

void gpiq_pdsxx::gpiq_pdsxx_rub_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("gpiq_pd_rub")), text);
}
