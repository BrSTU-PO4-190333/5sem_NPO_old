#include "gpiq_xxssave.h"
#include "ui_gpiq_xxssave.h"

gpiq_xxssave::gpiq_xxssave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_xxssave)
{
    ui->setupUi(this);
    connect(ui->gpiq_xxssave_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_xxssave_exit_cClick()));
}

gpiq_xxssave::~gpiq_xxssave()
{
    delete ui;
}

void gpiq_xxssave::gpiq_xxssave_exit_cClick() {
    this->close();
}
