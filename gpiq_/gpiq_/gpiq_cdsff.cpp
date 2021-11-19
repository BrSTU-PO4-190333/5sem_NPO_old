#include "gpiq_cdsff.h"
#include "ui_gpiq_cdsff.h"

gpiq_cdsff::gpiq_cdsff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_cdsff)
{
    ui->setupUi(this);
    connect(ui->gpiq_cdsff_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_cdsff_exit_cClick()));

    QSqlQuery query("SELECT Gpiq_cd_datas, Gpiq_cd_datad, Gpiq_cd_s FROM gpiq_cd");

    query.next();
    QString gpiq_cd_datas = query.value(0).toString();
    QString gpiq_cd_datad = query.value(1).toString();
    QString gpiq_cd_s = query.value(2).toString();
    ui->gpiq_cdsff_datas_e->setText(gpiq_cd_datas);
    ui->gpiq_cdsff_datad_e->setText(gpiq_cd_datad);
    ui->gpiq_cdsff_s_e->setText(gpiq_cd_s);
}

void gpiq_cdsff::gpiq_cdsff_exit_cClick() {
    this->reject();
}

void gpiq_cdsff::reject() {
    QSqlQuery query;
    query.prepare("UPDATE gpiq_cd SET Gpiq_cd_datas = :datas, Gpiq_cd_datad = :datad, Gpiq_cd_s = :s");
    QString gpiq_cd_datas = ui->gpiq_cdsff_datas_e->text();
    QString gpiq_cd_datad = ui->gpiq_cdsff_datad_e->text();
    QString gpiq_cd_s = ui->gpiq_cdsff_s_e->text();
    query.bindValue(":datas", gpiq_cd_datas);
    query.bindValue(":datad", gpiq_cd_datad);
    query.bindValue(":s", gpiq_cd_s);
    query.exec();
    QDialog::reject();
}

gpiq_cdsff::~gpiq_cdsff()
{
    delete ui;
}
