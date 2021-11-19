#include "mkoq_cdstt.h"
#include "ui_mkoq_cdstt.h"

mkoq_cdstt::mkoq_cdstt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_cdstt)
{
    ui->setupUi(this);
    connect(ui->mkoq_cdstt_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_cdstt_exit_cClick()));
    QSqlQuery query("SELECT Mkoq_cd_datat FROM mkoq_cd");
    query.next();
    QString mkoq_cd_datat = query.value(0).toString();
    ui->mkoq_cdstt_datat_e->setText(mkoq_cd_datat);
}

void mkoq_cdstt::mkoq_cdstt_exit_cClick() {
    this->reject();
}

void mkoq_cdstt::reject() {
    QSqlQuery query;
    query.prepare("UPDATE mkoq_cd SET Mkoq_cd_datat = :Mkoq_cd_datat");
    QString mkoq_cd_datat = ui->mkoq_cdstt_datat_e->text();
    query.bindValue(":Mkoq_cd_datat", mkoq_cd_datat);
    query.exec();
    QDialog::reject();
}

mkoq_cdstt::~mkoq_cdstt()
{
    delete ui;
}
