#include "mkoq_xxsgrid.h"
#include "ui_mkoq_xxsgrid.h"

mkoq_xxsgrid::mkoq_xxsgrid(QWidget *parent, QSqlTableModel *model, int currentIndex) :
    QDialog(parent),
    ui(new Ui::mkoq_xxsgrid)
{
    ui->setupUi(this);

    connect(ui->mkoq_xxsgrid_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_xxsgrid_exit_cClick()));
    this->currentIndex = currentIndex;
    ui->mkoq_xxsgrid_g->setModel(model);
    ui->mkoq_xxsgrid_g->setCurrentIndex(model->index(currentIndex, 0));
}

void mkoq_xxsgrid::mkoq_xxsgrid_exit_cClick() {
    this->reject();
}

void mkoq_xxsgrid::reject() {
    currentIndex = ui->mkoq_xxsgrid_g->currentIndex().row();
    QDialog::reject();
}

mkoq_xxsgrid::~mkoq_xxsgrid()
{
    delete ui;
}
