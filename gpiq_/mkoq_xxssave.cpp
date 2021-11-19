#include "mkoq_xxssave.h"
#include "ui_mkoq_xxssave.h"

mkoq_xxssave::mkoq_xxssave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_xxssave)
{
    ui->setupUi(this);
    connect(ui->mkoq_xxssave_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_xxssave_exit_cClick()));
}

mkoq_xxssave::~mkoq_xxssave()
{
    delete ui;
}

void mkoq_xxssave::mkoq_xxssave_exit_cClick() {
    this->close();
}
