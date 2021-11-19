#include "mkoq_pdsxx.h"
#include "ui_mkoq_pdsxx.h"

#include <QDebug>

mkoq_pdsxx::mkoq_pdsxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_pdsxx)
{
    ui->setupUi(this);
    connect(ui->mkoq_pdsxx_grid_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_grid_cClick()));
    connect(ui->mkoq_pdsxx_back_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_back_cClick()));
    connect(ui->mkoq_pdsxx_next_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_next_cClick()));
    connect(ui->mkoq_pdsxx_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_exit_cClick()));
    connect(ui->mkoq_pdsxx_add_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_add_cClick()));
    connect(ui->mkoq_pdsxx_del_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_del_cClick()));
    connect(ui->mkoq_pdsxx_pdtrj_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_pdtrj_cClick()));
    connect(ui->mkoq_pdsxx_to_c, SIGNAL(clicked()), this, SLOT(mkoq_pdsxx_to_cClick()));

    connect(ui->mkoq_pdsxx_dbn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_dbn_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_db_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_db_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_dokk_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_dokk_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_dokn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_dokn_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_dokd_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_dokd_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_rub_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_rub_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_kr_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_kr_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_to_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_to_eTextChanged(QString)));
    connect(ui->mkoq_pdsxx_krn_e, SIGNAL(textChanged(QString)), this, SLOT(mkoq_pdsxx_krn_eTextChanged(QString)));

    ui->mkoq_pdsxx_to_e->setStyleSheet("color: red;");
    ui->mkoq_pdsxx_dbn_e->setStyleSheet("color: red;");
    ui->mkoq_pdsxx_db_e->setStyleSheet("color: red;");
    ui->mkoq_pdsxx_kr_e->setStyleSheet("color: red;");
    ui->mkoq_pdsxx_db_l->setStyleSheet("color: red;");
    ui->mkoq_pdsxx_kr_l->setStyleSheet("color: red;");
    ui->mkoq_pdsxx_krn_e->setStyleSheet("color: red;");

    model.setTable("mkoq_pd");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    size = model.rowCount();
    currentIndex = 0;
    changeEdits(size - 1);
}

mkoq_pdsxx::~mkoq_pdsxx()
{
    delete ui;
}

void mkoq_pdsxx::changeEdits(int newIndex) {
    if (newIndex >=0 && newIndex < size) {
        currentIndex = newIndex;
        QString mkoq_pd_db = model.record(currentIndex).value("Mkoq_pd_db").toString();
        QString mkoq_pd_dbn = model.record(currentIndex).value("Mkoq_pd_dbn").toString();
        QString mkoq_pd_dokk = model.record(currentIndex).value("Mkoq_pd_dokk").toString();
        QString mkoq_pd_dokd = model.record(currentIndex).value("Mkoq_pd_dokd").toString();
        QString mkoq_pd_dokn = model.record(currentIndex).value("Mkoq_pd_dokn").toString();
        QString mkoq_pd_kr = model.record(currentIndex).value("Mkoq_pd_kr").toString();
        QString mkoq_pd_krn = model.record(currentIndex).value("Mkoq_pd_krn").toString();
        QString mkoq_pd_rub = model.record(currentIndex).value("Mkoq_pd_rub").toString();
        QString mkoq_pd_to = model.record(currentIndex).value("Mkoq_pd_to").toString();
        ui->mkoq_pdsxx_db_e->setText(mkoq_pd_db);
        ui->mkoq_pdsxx_dbn_e->setText(mkoq_pd_dbn);
        ui->mkoq_pdsxx_dokk_e->setText(mkoq_pd_dokk);
        ui->mkoq_pdsxx_dokn_e->setText(mkoq_pd_dokn);
        ui->mkoq_pdsxx_dokd_e->setText(mkoq_pd_dokd);
        ui->mkoq_pdsxx_kr_e->setText(mkoq_pd_kr);
        ui->mkoq_pdsxx_krn_e->setText(mkoq_pd_krn);
        ui->mkoq_pdsxx_rub_e->setText(mkoq_pd_rub);
        ui->mkoq_pdsxx_to_e->setText(mkoq_pd_to);
    }
}

void mkoq_pdsxx::mkoq_pdsxx_grid_cClick() {
   mkoq_xxsgrid* mkoq_xxsgrid1 = new mkoq_xxsgrid(this, &model, currentIndex);
   mkoq_xxsgrid1->setWindowTitle("mkoq_pdsxx  viberi dokument");
   mkoq_xxsgrid1->exec();
   changeEdits(mkoq_xxsgrid1->currentIndex);
}

void mkoq_pdsxx::mkoq_pdsxx_back_cClick() {
    changeEdits(currentIndex - 1);
}

void mkoq_pdsxx::mkoq_pdsxx_next_cClick() {
    changeEdits(currentIndex + 1);
}

void mkoq_pdsxx::mkoq_pdsxx_exit_cClick() {
    QDialog::reject();
}

void mkoq_pdsxx::mkoq_pdsxx_add_cClick() {
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

    QSqlQuery query("SELECT Mkoq_cd_datat FROM mkoq_cd");
    query.next();
    QString mkoq_cd_datatt = query.value(0).toString();
    ui->mkoq_pdsxx_dokd_e->setText(mkoq_cd_datatt);
}

void mkoq_pdsxx::mkoq_pdsxx_del_cClick() {
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

void mkoq_pdsxx::mkoq_pdsxx_pdtrj_cClick() {
    QSqlQuery query;
    query.prepare("INSERT INTO mkoq_rj VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue("0");
    query.addBindValue(ui->mkoq_pdsxx_dokd_e->text());
    query.addBindValue(ui->mkoq_pdsxx_dokk_e->text());
    query.addBindValue(ui->mkoq_pdsxx_dokn_e->text().toInt());
    query.addBindValue(ui->mkoq_pdsxx_dokd_e->text());
    query.addBindValue(ui->mkoq_pdsxx_to_e->text());
    query.addBindValue(ui->mkoq_pdsxx_db_e->text().toInt());
    query.addBindValue(ui->mkoq_pdsxx_dbn_e->text());
    query.addBindValue(ui->mkoq_pdsxx_kr_e->text().toInt());
    query.addBindValue(ui->mkoq_pdsxx_krn_e->text());
    query.addBindValue(ui->mkoq_pdsxx_rub_e->text().toInt());
    query.exec();
}

void mkoq_pdsxx::mkoq_pdsxx_to_cClick() {
    mkoq_togxx* mkoq_togxx1 = new mkoq_togxx(this);
    mkoq_togxx1->setWindowTitle("mkoq_pdsxx  viberi operaciu");
    mkoq_togxx1->exec();
    ui->mkoq_pdsxx_db_e->setText(mkoq_togxx1->mkoq_to_db);
    ui->mkoq_pdsxx_dbn_e->setText(mkoq_togxx1->mkoq_to_dbn);
    ui->mkoq_pdsxx_kr_e->setText(mkoq_togxx1->mkoq_to_kr);
    ui->mkoq_pdsxx_krn_e->setText(mkoq_togxx1->mkoq_to_krn);
    ui->mkoq_pdsxx_to_e->setText(mkoq_togxx1->mkoq_to_k);
}

void mkoq_pdsxx::mkoq_pdsxx_db_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_db")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_dbn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_dbn")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_dokk_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_dokk")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_dokd_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_dokd")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_dokn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_dokn")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_kr_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_kr")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_krn_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_krn")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_to_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_to")), text);
}

void mkoq_pdsxx::mkoq_pdsxx_rub_eTextChanged(QString text) {
    model.setData(model.index(currentIndex, model.fieldIndex("Mkoq_pd_rub")), text);
}
