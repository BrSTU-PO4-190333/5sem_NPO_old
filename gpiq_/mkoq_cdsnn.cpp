#include "mkoq_cdsnn.h"
#include "ui_mkoq_cdsnn.h"

mkoq_cdsnn::mkoq_cdsnn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_cdsnn)
{
    ui->setupUi(this);
    connect(ui->mkoq_cdsnn_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_cdsnn_exit_cClick()));
    QSqlQuery query("SELECT Mkoq_cd_firma FROM mkoq_cd");
    query.next();
    QString mkoq_cd_firma = query.value(0).toString();
    ui->mkoq_cdsnn_firma_e->setText(mkoq_cd_firma);
}

void mkoq_cdsnn::mkoq_cdsnn_exit_cClick() {
    this->reject();
}

void mkoq_cdsnn::reject() {
    QSqlQuery query;
    query.prepare("UPDATE mkoq_cd SET Mkoq_cd_firma = :Mkoq_cd_firma");
    QString mkoq_cd_firma = ui->mkoq_cdsnn_firma_e->text();
    query.bindValue(":Mkoq_cd_firma", mkoq_cd_firma);
    query.exec();
    QDialog::reject();
}

mkoq_cdsnn::~mkoq_cdsnn()
{
    delete ui;
}
