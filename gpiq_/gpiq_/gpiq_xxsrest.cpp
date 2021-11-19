#include "gpiq_xxsrest.h"
#include "ui_gpiq_xxsrest.h"

gpiq_xxsrest::gpiq_xxsrest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_xxsrest)
{
    ui->setupUi(this);
    connect(ui->gpiq_xxsrest_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_xxsrest_exit_cClick()));
}

gpiq_xxsrest::~gpiq_xxsrest()
{
    delete ui;
}

void gpiq_xxsrest::gpiq_xxsrest_exit_cClick() {
    this->close();
}
