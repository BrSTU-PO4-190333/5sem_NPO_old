#include "gpiq_cdsnn.h"
#include "ui_gpiq_cdsnn.h"

gpiq_cdsnn::gpiq_cdsnn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_cdsnn)
{
    ui->setupUi(this);
    connect(ui->gpiq_cdsnn_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_cdsnn_exit_cClick()));
    QSqlQuery query("SELECT Gpiq_cd_firma FROM gpiq_cd");
    query.next();
    QString gpiq_cd_firma = query.value(0).toString();
    ui->gpiq_cdsnn_firma_e->setText(gpiq_cd_firma);
}

void gpiq_cdsnn::gpiq_cdsnn_exit_cClick() {
    this->reject();
}

void gpiq_cdsnn::reject() {
    QSqlQuery query;
    query.prepare("UPDATE gpiq_cd SET Gpiq_cd_firma = :Gpiq_cd_firma");
    QString gpiq_cd_firma = ui->gpiq_cdsnn_firma_e->text();
    query.bindValue(":Gpiq_cd_firma", gpiq_cd_firma);
    query.exec();
    QDialog::reject();
}

gpiq_cdsnn::~gpiq_cdsnn()
{
    delete ui;
}
