#include "mkoq_ksrjj.h"
#include "ui_mkoq_ksrjj.h"

mkoq_ksrjj::mkoq_ksrjj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_ksrjj)
{
    ui->setupUi(this);
    connect(ui->mkoq_ksrjj_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_ksrjj_exit_cClick()));
}

mkoq_ksrjj::~mkoq_ksrjj()
{
    delete ui;
}

void mkoq_ksrjj::mkoq_ksrjj_exit_cClick() {
    this->close();
}
