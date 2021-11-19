#ifndef mkoq_CDSNN_H
#define mkoq_CDSNN_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class mkoq_cdsnn;
}

class mkoq_cdsnn : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_cdsnn(QWidget *parent = 0);
    ~mkoq_cdsnn();

private:
    Ui::mkoq_cdsnn *ui;

private slots:
    void mkoq_cdsnn_exit_cClick();
    void reject();
};

#endif // mkoq_CDSNN_H
