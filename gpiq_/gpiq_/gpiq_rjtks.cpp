#include "gpiq_rjtks.h"
#include "ui_gpiq_rjtks.h"

gpiq_rjtks::gpiq_rjtks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_rjtks)
{
    ui->setupUi(this);
    connect(ui->gpiq_rjtks_gridrj_c, SIGNAL(clicked()), this, SLOT(gpiq_rjtks_gridrj_cClick()));
    connect(ui->gpiq_rjtks_gridks_c, SIGNAL(clicked()), this, SLOT(gpiq_rjtks_gridks_cClick()));
    connect(ui->gpiq_rjtks_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_rjtks_exit_cClick()));
    connect(ui->gpiq_rjtks_wk_c, SIGNAL(clicked()), this, SLOT(gpiq_rjtks_wk_cClick()));

    model_rj.setTable("gpiq_rj");
    model_rj.select();
    model_rj.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_rj = model_rj.rowCount();
    index_rj = size_rj - 1;

    model_ks.setTable("gpiq_ks");
    model_ks.select();
    model_ks.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_ks = model_ks.rowCount();
    index_ks = size_ks - 1;

}

gpiq_rjtks::~gpiq_rjtks()
{
    delete ui;
}

void gpiq_rjtks::changeIndexRJ(int newIndex) {
    if (newIndex >=0 && newIndex < size_rj) {
        index_rj = newIndex;
    }
}

void gpiq_rjtks::changeIndexKS(int newIndex) {
    if (newIndex >=0 && newIndex < size_ks) {
        index_ks = newIndex;
    }
}

void gpiq_rjtks::gpiq_rjtks_gridrj_cClick() {
    gpiq_xxsgrid* gpiq_xxsgrid1 = new gpiq_xxsgrid(this, &model_rj, index_rj);
    gpiq_xxsgrid1->setWindowTitle("gpiq_rjtks  posmotri reg jurnal i viidi");
    gpiq_xxsgrid1->exec();
    changeIndexRJ(gpiq_xxsgrid1->currentIndex);
}

void gpiq_rjtks::gpiq_rjtks_gridks_cClick() {
    gpiq_xxsgrid* gpiq_xxsgrid1 = new gpiq_xxsgrid(this, &model_ks, index_ks);
    gpiq_xxsgrid1->setWindowTitle("gpiq_rjtks  posmotri knigu schetov i viidi");
    gpiq_xxsgrid1->exec();
    changeIndexKS(gpiq_xxsgrid1->currentIndex);
}

void gpiq_rjtks::gpiq_rjtks_exit_cClick() {
    QDialog::reject();
}

void gpiq_rjtks::gpiq_rjtks_wk_cClick() {
    QSqlQuery query;
    query.prepare("DELETE FROM gpiq_ks");
    query.exec();

    for (int i = 0; i < size_rj; i++) {
        query.prepare("INSERT INTO gpiq_ks VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("gpiq_rj_data").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dokk").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dokn").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dokd").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_to").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_db").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dbn").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_kr").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_krn").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_rub").toString());
        query.addBindValue("0");
        query.exec();

        query.prepare("INSERT INTO gpiq_ks VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("gpiq_rj_data").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dokk").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dokn").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dokd").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_to"));
        query.addBindValue(model_rj.record(i).value("gpiq_rj_kr").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_krn").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_db").toString());
        query.addBindValue(model_rj.record(i).value("gpiq_rj_dbn").toString());
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("gpiq_rj_rub").toString());
        query.exec();
    }

    model_ks.setTable("gpiq_ks");
    model_ks.select();
    model_ks.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_ks = model_ks.rowCount();
    index_ks = size_ks - 1;
}

