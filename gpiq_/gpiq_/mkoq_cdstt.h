#ifndef mkoq_CDSTT_H
#define mkoq_CDSTT_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class mkoq_cdstt;
}

class mkoq_cdstt : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_cdstt(QWidget *parent = 0);
    ~mkoq_cdstt();

private:
    Ui::mkoq_cdstt *ui;

private slots:
    void mkoq_cdstt_exit_cClick();
    void reject();
};

#endif // mkoq_CDSTT_H
