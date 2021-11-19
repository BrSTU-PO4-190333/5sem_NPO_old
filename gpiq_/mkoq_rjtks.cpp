#include "mkoq_rjtks.h"
#include "ui_mkoq_rjtks.h"

mkoq_rjtks::mkoq_rjtks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_rjtks)
{
    ui->setupUi(this);
    connect(ui->mkoq_rjtks_gridrj_c, SIGNAL(clicked()), this, SLOT(mkoq_rjtks_gridrj_cClick()));
    connect(ui->mkoq_rjtks_gridks_c, SIGNAL(clicked()), this, SLOT(mkoq_rjtks_gridks_cClick()));
    connect(ui->mkoq_rjtks_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_rjtks_exit_cClick()));
    connect(ui->mkoq_rjtks_wk_c, SIGNAL(clicked()), this, SLOT(mkoq_rjtks_wk_cClick()));

    model_rj.setTable("mkoq_rj");
    model_rj.select();
    model_rj.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_rj = model_rj.rowCount();
    index_rj = size_rj - 1;

    model_ks.setTable("mkoq_ks");
    model_ks.select();
    model_ks.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_ks = model_ks.rowCount();
    index_ks = size_ks - 1;

}

mkoq_rjtks::~mkoq_rjtks()
{
    delete ui;
}

void mkoq_rjtks::changeIndexRJ(int newIndex) {
    if (newIndex >=0 && newIndex < size_rj) {
        index_rj = newIndex;
    }
}

void mkoq_rjtks::changeIndexKS(int newIndex) {
    if (newIndex >=0 && newIndex < size_ks) {
        index_ks = newIndex;
    }
}

void mkoq_rjtks::mkoq_rjtks_gridrj_cClick() {
    mkoq_xxsgrid* mkoq_xxsgrid1 = new mkoq_xxsgrid(this, &model_rj, index_rj);
    mkoq_xxsgrid1->setWindowTitle("mkoq_rjtks  posmotri reg jurnal i viidi");
    mkoq_xxsgrid1->exec();
    changeIndexRJ(mkoq_xxsgrid1->currentIndex);
}

void mkoq_rjtks::mkoq_rjtks_gridks_cClick() {
    mkoq_xxsgrid* mkoq_xxsgrid1 = new mkoq_xxsgrid(this, &model_ks, index_ks);
    mkoq_xxsgrid1->setWindowTitle("mkoq_rjtks  posmotri knigu schetov i viidi");
    mkoq_xxsgrid1->exec();
    changeIndexKS(mkoq_xxsgrid1->currentIndex);
}

void mkoq_rjtks::mkoq_rjtks_exit_cClick() {
    QDialog::reject();
}

void mkoq_rjtks::mkoq_rjtks_wk_cClick() {
    QSqlQuery query;
    query.prepare("DELETE FROM mkoq_ks");
    query.exec();

    for (int i = 0; i < size_rj; i++) {
        query.prepare("INSERT INTO mkoq_ks VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_data").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dokk").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dokn").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dokd").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_to").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_db").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dbn").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_kr").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_krn").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_rub").toString());
        query.addBindValue("0");
        query.exec();

        query.prepare("INSERT INTO mkoq_ks VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_data").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dokk").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dokn").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dokd").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_to"));
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_kr").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_krn").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_db").toString());
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_dbn").toString());
        query.addBindValue("0");
        query.addBindValue(model_rj.record(i).value("Mkoq_rj_rub").toString());
        query.exec();
    }

    model_ks.setTable("mkoq_ks");
    model_ks.select();
    model_ks.setEditStrategy(QSqlTableModel::OnFieldChange);

    size_ks = model_ks.rowCount();
    index_ks = size_ks - 1;
}

