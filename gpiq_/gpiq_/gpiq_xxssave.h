#ifndef gpiq_XXSSAVE_H
#define gpiq_XXSSAVE_H

#include <QDialog>

namespace Ui {
class gpiq_xxssave;
}

class gpiq_xxssave : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_xxssave(QWidget *parent = 0);
    ~gpiq_xxssave();

private:
    Ui::gpiq_xxssave *ui;

private slots:
    void gpiq_xxssave_exit_cClick();
};

#endif // gpiq_XXSSAVE_H
