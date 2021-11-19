#ifndef mkoq_XXSREST_H
#define mkoq_XXSREST_H

#include <QDialog>

namespace Ui {
class mkoq_xxsrest;
}

class mkoq_xxsrest : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_xxsrest(QWidget *parent = 0);
    ~mkoq_xxsrest();

private:
    Ui::mkoq_xxsrest *ui;

private slots:
    void mkoq_xxsrest_exit_cClick();
};

#endif // mkoq_XXSREST_H
