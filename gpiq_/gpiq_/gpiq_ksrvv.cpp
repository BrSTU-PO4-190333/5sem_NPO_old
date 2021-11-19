#include "gpiq_ksrvv.h"
#include "ui_gpiq_ksrvv.h"

gpiq_ksrvv::gpiq_ksrvv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_ksrvv)
{
    ui->setupUi(this);
    connect(ui->gpiq_ksrvv_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_ksrvv_exit_cClick()));
}

gpiq_ksrvv::~gpiq_ksrvv()
{
    delete ui;
}

void gpiq_ksrvv::gpiq_ksrvv_exit_cClick() {
    this->close();
}
