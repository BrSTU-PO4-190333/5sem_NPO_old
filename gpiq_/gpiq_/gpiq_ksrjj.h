#ifndef gpiq_KSRJJ_H
#define gpiq_KSRJJ_H

#include <QDialog>

namespace Ui {
class gpiq_ksrjj;
}

class gpiq_ksrjj : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_ksrjj(QWidget *parent = 0);
    ~gpiq_ksrjj();

private:
    Ui::gpiq_ksrjj *ui;

private slots:
    void gpiq_ksrjj_exit_cClick();
};

#endif // gpiq_KSRJJ_H
