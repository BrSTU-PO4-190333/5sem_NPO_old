#include "mkoq_cdsff.h"
#include "ui_mkoq_cdsff.h"

mkoq_cdsff::mkoq_cdsff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_cdsff)
{
    ui->setupUi(this);
    connect(ui->mkoq_cdsff_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_cdsff_exit_cClick()));

    QSqlQuery query("SELECT Mkoq_cd_datas, Mkoq_cd_datad, Mkoq_cd_s FROM mkoq_cd");

    query.next();
    QString mkoq_cd_datas = query.value(0).toString();
    QString mkoq_cd_datad = query.value(1).toString();
    QString mkoq_cd_s = query.value(2).toString();
    ui->mkoq_cdsff_datas_e->setText(mkoq_cd_datas);
    ui->mkoq_cdsff_datad_e->setText(mkoq_cd_datad);
    ui->mkoq_cdsff_s_e->setText(mkoq_cd_s);
}

void mkoq_cdsff::mkoq_cdsff_exit_cClick() {
    this->reject();
}

void mkoq_cdsff::reject() {
    QSqlQuery query;
    query.prepare("UPDATE mkoq_cd SET Mkoq_cd_datas = :datas, Mkoq_cd_datad = :datad, Mkoq_cd_s = :s");
    QString mkoq_cd_datas = ui->mkoq_cdsff_datas_e->text();
    QString mkoq_cd_datad = ui->mkoq_cdsff_datad_e->text();
    QString mkoq_cd_s = ui->mkoq_cdsff_s_e->text();
    query.bindValue(":datas", mkoq_cd_datas);
    query.bindValue(":datad", mkoq_cd_datad);
    query.bindValue(":s", mkoq_cd_s);
    query.exec();
    QDialog::reject();
}

mkoq_cdsff::~mkoq_cdsff()
{
    delete ui;
}
