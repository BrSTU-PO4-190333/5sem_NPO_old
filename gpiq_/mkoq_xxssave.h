#ifndef mkoq_XXSSAVE_H
#define mkoq_XXSSAVE_H

#include <QDialog>

namespace Ui {
class mkoq_xxssave;
}

class mkoq_xxssave : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_xxssave(QWidget *parent = 0);
    ~mkoq_xxssave();

private:
    Ui::mkoq_xxssave *ui;

private slots:
    void mkoq_xxssave_exit_cClick();
};

#endif // mkoq_XXSSAVE_H
