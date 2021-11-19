#include "gpiq_ksrjj.h"
#include "ui_gpiq_ksrjj.h"

gpiq_ksrjj::gpiq_ksrjj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_ksrjj)
{
    ui->setupUi(this);
    connect(ui->gpiq_ksrjj_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_ksrjj_exit_cClick()));
}

gpiq_ksrjj::~gpiq_ksrjj()
{
    delete ui;
}

void gpiq_ksrjj::gpiq_ksrjj_exit_cClick() {
    this->close();
}
