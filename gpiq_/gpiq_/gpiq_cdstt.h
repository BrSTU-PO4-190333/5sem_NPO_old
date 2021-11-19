#ifndef gpiq_CDSTT_H
#define gpiq_CDSTT_H

#include <QDialog>
#include <QDebug>
#include <QtSql>

namespace Ui {
class gpiq_cdstt;
}

class gpiq_cdstt : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_cdstt(QWidget *parent = 0);
    ~gpiq_cdstt();

private:
    Ui::gpiq_cdstt *ui;

private slots:
    void gpiq_cdstt_exit_cClick();
    void reject();
};

#endif // gpiq_CDSTT_H
