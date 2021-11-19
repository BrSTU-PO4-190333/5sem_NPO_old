#include "mkoq_togxx.h"
#include "ui_mkoq_togxx.h"

mkoq_togxx::mkoq_togxx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_togxx)
{
    ui->setupUi(this);

    connect(ui->mkoq_togxx_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_togxx_exit_cClick()));

    model.setTable("mkoq_to");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    int size = model.rowCount();
    currentIndex = size - 1;

    ui->mkoq_togxx_g->setModel(&model);
    ui->mkoq_togxx_g->setCurrentIndex(model.index(currentIndex, 0));
}

void mkoq_togxx::mkoq_togxx_exit_cClick() {
    this->reject();
}

void mkoq_togxx::reject() {
    currentIndex = ui->mkoq_togxx_g->currentIndex().row();
    mkoq_to_k = model.record(currentIndex).value("Mkoq_to_k").toString();
    mkoq_to_db = model.record(currentIndex).value("Mkoq_to_db").toString();
    mkoq_to_dbn = model.record(currentIndex).value("Mkoq_to_dbn").toString();
    mkoq_to_kr = model.record(currentIndex).value("Mkoq_to_kr").toString();
    mkoq_to_krn = model.record(currentIndex).value("Mkoq_to_krn").toString();
    QDialog::reject();
}

mkoq_togxx::~mkoq_togxx()
{
    delete ui;
}
