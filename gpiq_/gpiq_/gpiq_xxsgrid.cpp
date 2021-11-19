#include "gpiq_xxsgrid.h"
#include "ui_gpiq_xxsgrid.h"

gpiq_xxsgrid::gpiq_xxsgrid(QWidget *parent, QSqlTableModel *model, int currentIndex) :
    QDialog(parent),
    ui(new Ui::gpiq_xxsgrid)
{
    ui->setupUi(this);

    connect(ui->gpiq_xxsgrid_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_xxsgrid_exit_cClick()));
    this->currentIndex = currentIndex;
    ui->gpiq_xxsgrid_g->setModel(model);
    ui->gpiq_xxsgrid_g->setCurrentIndex(model->index(currentIndex, 0));
}

void gpiq_xxsgrid::gpiq_xxsgrid_exit_cClick() {
    this->reject();
}

void gpiq_xxsgrid::reject() {
    currentIndex = ui->gpiq_xxsgrid_g->currentIndex().row();
    QDialog::reject();
}

gpiq_xxsgrid::~gpiq_xxsgrid()
{
    delete ui;
}
