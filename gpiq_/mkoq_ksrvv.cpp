#include "mkoq_ksrvv.h"
#include "ui_mkoq_ksrvv.h"

mkoq_ksrvv::mkoq_ksrvv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_ksrvv)
{
    ui->setupUi(this);
    connect(ui->mkoq_ksrvv_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_ksrvv_exit_cClick()));
}

mkoq_ksrvv::~mkoq_ksrvv()
{
    delete ui;
}

void mkoq_ksrvv::mkoq_ksrvv_exit_cClick() {
    this->close();
}
