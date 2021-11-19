#ifndef mkoq_XXSGRID_H
#define mkoq_XXSGRID_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class mkoq_xxsgrid;
}

class mkoq_xxsgrid : public QDialog
{
    Q_OBJECT

public:
    explicit mkoq_xxsgrid(QWidget *parent, QSqlTableModel *model, int currentIndex);
    ~mkoq_xxsgrid();

    int currentIndex;

private:
    Ui::mkoq_xxsgrid *ui;

private slots:
    void mkoq_xxsgrid_exit_cClick();
    void reject();

};

#endif // mkoq_XXSGRID_H
