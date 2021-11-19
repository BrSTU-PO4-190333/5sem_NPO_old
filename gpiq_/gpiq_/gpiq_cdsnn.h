#ifndef gpiq_CDSNN_H
#define gpiq_CDSNN_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class gpiq_cdsnn;
}

class gpiq_cdsnn : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_cdsnn(QWidget *parent = 0);
    ~gpiq_cdsnn();

private:
    Ui::gpiq_cdsnn *ui;

private slots:
    void gpiq_cdsnn_exit_cClick();
    void reject();
};

#endif // gpiq_CDSNN_H
