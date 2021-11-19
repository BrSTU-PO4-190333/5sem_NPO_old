#ifndef gpiq_TOGXX_H
#define gpiq_TOGXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class gpiq_togxx;
}

class gpiq_togxx : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_togxx(QWidget *parent);
    ~gpiq_togxx();

    QSqlTableModel model;
    int currentIndex;
    QString gpiq_to_k, gpiq_to_db, gpiq_to_dbn, gpiq_to_kr, gpiq_to_krn;

private:
    Ui::gpiq_togxx *ui;

private slots:
    void gpiq_togxx_exit_cClick();
    void reject();

};

#endif // gpiq_TOGXX_H
