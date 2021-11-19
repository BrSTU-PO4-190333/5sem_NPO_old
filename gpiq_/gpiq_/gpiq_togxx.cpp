#include "gpiq_togxx.h"
#include "ui_gpiq_togxx.h"

gpiq_togxx::gpiq_togxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_togxx)
{
    ui->setupUi(this);

    connect(ui->gpiq_togxx_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_togxx_exit_cClick()));

    model.setTable("gpiq_to");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    int size = model.rowCount();
    currentIndex = size - 1;

    ui->gpiq_togxx_g->setModel(&model);
    ui->gpiq_togxx_g->setCurrentIndex(model.index(currentIndex, 0));
}

void gpiq_togxx::gpiq_togxx_exit_cClick() {
    this->reject();
}

void gpiq_togxx::reject() {
    currentIndex = ui->gpiq_togxx_g->currentIndex().row();
    gpiq_to_k = model.record(currentIndex).value("Gpiq_to_k").toString();
    gpiq_to_db = model.record(currentIndex).value("Gpiq_to_db").toString();
    gpiq_to_dbn = model.record(currentIndex).value("Gpiq_to_dbn").toString();
    gpiq_to_kr = model.record(currentIndex).value("Gpiq_to_kr").toString();
    gpiq_to_krn = model.record(currentIndex).value("Gpiq_to_krn").toString();
    QDialog::reject();
}

gpiq_togxx::~gpiq_togxx()
{
    delete ui;
}
