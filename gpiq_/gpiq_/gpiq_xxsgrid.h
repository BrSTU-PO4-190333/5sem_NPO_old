#ifndef gpiq_XXSGRID_H
#define gpiq_XXSGRID_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class gpiq_xxsgrid;
}

class gpiq_xxsgrid : public QDialog
{
    Q_OBJECT

public:
    explicit gpiq_xxsgrid(QWidget *parent, QSqlTableModel *model, int currentIndex);
    ~gpiq_xxsgrid();

    int currentIndex;

private:
    Ui::gpiq_xxsgrid *ui;

private slots:
    void gpiq_xxsgrid_exit_cClick();
    void reject();

};

#endif // gpiq_XXSGRID_H
