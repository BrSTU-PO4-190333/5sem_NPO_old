#include "gpiq_cdstt.h"
#include "ui_gpiq_cdstt.h"

gpiq_cdstt::gpiq_cdstt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_cdstt)
{
    ui->setupUi(this);
    connect(ui->gpiq_cdstt_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_cdstt_exit_cClick()));
    QSqlQuery query("SELECT gpiq_cd_datat FROM gpiq_cd");
    query.next();
    QString gpiq_cd_datat = query.value(0).toString();
    ui->gpiq_cdstt_datat_e->setText(gpiq_cd_datat);
}

void gpiq_cdstt::gpiq_cdstt_exit_cClick() {
    this->reject();
}

void gpiq_cdstt::reject() {
    QSqlQuery query;
    query.prepare("UPDATE gpiq_cd SET gpiq_cd_datat = :gpiq_cd_datat");
    QString gpiq_cd_datat = ui->gpiq_cdstt_datat_e->text();
    query.bindValue(":gpiq_cd_datat", gpiq_cd_datat);
    query.exec();
    QDialog::reject();
}

gpiq_cdstt::~gpiq_cdstt()
{
    delete ui;
}
