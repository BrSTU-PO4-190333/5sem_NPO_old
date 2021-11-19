#include "mkoq_xxsrest.h"
#include "ui_mkoq_xxsrest.h"

mkoq_xxsrest::mkoq_xxsrest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_xxsrest)
{
    ui->setupUi(this);
    connect(ui->mkoq_xxsrest_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_xxsrest_exit_cClick()));
}

mkoq_xxsrest::~mkoq_xxsrest()
{
    delete ui;
}

void mkoq_xxsrest::mkoq_xxsrest_exit_cClick() {
    this->close();
}
