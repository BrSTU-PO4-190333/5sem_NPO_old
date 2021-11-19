#ifndef gpiq_XXSREST_H
#define gpiq_XXSREST_H

#include <QDialog>

namespace Ui {
class gpiq_xxsrest;
}

class gpiq_xxsrest : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_xxsrest(QWidget *parent = 0);
    ~gpiq_xxsrest();

private:
    Ui::gpiq_xxsrest *ui;

private slots:
    void gpiq_xxsrest_exit_cClick();
};

#endif // gpiq_XXSREST_H
