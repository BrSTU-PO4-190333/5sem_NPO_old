#ifndef mkoq_TOGXX_H
#define mkoq_TOGXX_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class mkoq_togxx;
}

class mkoq_togxx : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_togxx(QWidget *parent);
    ~mkoq_togxx();

    QSqlTableModel model;
    int currentIndex;
    QString mkoq_to_k, mkoq_to_db, mkoq_to_dbn, mkoq_to_kr, mkoq_to_krn;

private:
    Ui::mkoq_togxx *ui;

private slots:
    void mkoq_togxx_exit_cClick();
    void reject();

};

#endif // mkoq_TOGXX_H
