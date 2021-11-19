#ifndef mkoq_KSRJJ_H
#define mkoq_KSRJJ_H

#include <QDialog>

namespace Ui {
class mkoq_ksrjj;
}

class mkoq_ksrjj : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_ksrjj(QWidget *parent = 0);
    ~mkoq_ksrjj();

private:
    Ui::mkoq_ksrjj *ui;

private slots:
    void mkoq_ksrjj_exit_cClick();
};

#endif // mkoq_KSRJJ_H
