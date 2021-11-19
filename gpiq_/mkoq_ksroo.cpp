#include "mkoq_ksroo.h"
#include "ui_mkoq_ksroo.h"
#include <QSqlQuery>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <cstdio>
#include <QDate>
#include <QDebug>

mkoq_ksroo::mkoq_ksroo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkoq_ksroo)
{
    ui->setupUi(this);
    connect(ui->mkoq_ksroo_exit_c, SIGNAL(clicked()), this, SLOT(mkoq_ksroo_exit_cClick()));
    QSqlQuery query("SELECT Mkoq_cd_s, Mkoq_cd_datad, Mkoq_cd_datas FROM mkoq_cd");
    query.next();
    QString mkoq_cd_s = query.value(0).toString();
    QString mkoq_cd_datad = query.value(1).toString();
    QDate mkoq_cd_datado = QDate::fromString(mkoq_cd_datad, "dd.MM.yyyy");
    QString mkoq_cd_datas = query.value(2).toString();
    QDate mkoq_cd_dataso = QDate::fromString(mkoq_cd_datas, "dd.MM.yyyy");
    FILE* file;
    file = fopen("mkoq_otchet.txt", "w");
    fprintf(file, "%85s\n", "");
    fprintf(file, "%4s%-20.20s%8s%s%13s%s%2s\n", "", "=Mialik K.O.=", "", "oborotno-saldovaa vedomost", "", "=mkoq_krsoo=", "");
    fprintf(file, "%8s%s%4s%4s%13s%s%4s%10s%s%10s     \n", "", "schet", "", mkoq_cd_s.toLocal8Bit().data(), "", "interval s", "", mkoq_cd_datas.toLocal8Bit().data(), "      do    ", mkoq_cd_datad.toLocal8Bit().data());
    fprintf(file, "%85s\n", "");
    fprintf(file, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(file, "   data      | dokument   | schet | korr schet | vx | oborot db kr | isx      \n");
    fprintf(file, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(file, "%85s\n", "");
    QSqlQuery query_ks("SELECT Mkoq_ks_data, Mkoq_ks_dokk, Mkoq_ks_s, Mkoq_ks_ks, Mkoq_ks_rubdb, Mkoq_ks_rubkr, Mkoq_ks_dokn, Mkoq_ks_dokd FROM mkoq_ks");

    int mkoq_sumkr = 0;
    int mkoq_sumdb = 0;

    while (query_ks.next()) {
        QString mkoq_ks_data = query_ks.value(0).toString();
        QDate mkoq_ks_datat = QDate::fromString(mkoq_ks_data, "dd.MM.yyyy");
        QString mkoq_ks_dokk;
        QString mkoq_ks_s = query_ks.value(2).toString();
        QString mkoq_ks_ks;
        QString mkoq_ks_rubdb;
        QString mkoq_ks_rubkr;
        QString mkoq_ks_dokn;
        QString mkoq_ks_dokd;

        if( mkoq_cd_s == mkoq_ks_s && mkoq_cd_dataso < mkoq_ks_datat &&
                mkoq_ks_datat < mkoq_cd_datado) {
            mkoq_ks_dokk = query_ks.value(1).toString();
            mkoq_ks_s = query_ks.value(2).toString();
            mkoq_ks_ks = query_ks.value(3).toString();
            mkoq_ks_rubdb = query_ks.value(4).toString();
            mkoq_ks_rubkr = query_ks.value(5).toString();
            mkoq_sumdb += query_ks.value(4).toInt();
            mkoq_sumkr += query_ks.value(5).toInt();
            mkoq_ks_dokn = query_ks.value(6).toString();
            mkoq_ks_dokd = query_ks.value(7).toString();

            fprintf(file, "  %10s   %-4s%10s%4s%9s%4s%9s%5s%7s%5s%6s\n",
                mkoq_ks_data.toLocal8Bit().data(),
                mkoq_ks_dokk.toLocal8Bit().data(),
                "",
                mkoq_ks_s.toLocal8Bit().data(),
                "",
                mkoq_ks_ks.toLocal8Bit().data(),
                "",
                mkoq_ks_rubdb.toLocal8Bit().data(),
                "",
                mkoq_ks_rubkr.toLocal8Bit().data(),
                "");
            fprintf(file, "%22s%-4s%59s\n", "", mkoq_ks_dokn.toLocal8Bit().data(), "");
            fprintf(file, "%22s%-10s%53s\n", "", mkoq_ks_dokd.toLocal8Bit().data(), "");
            fprintf(file, "%85s\n", "");
        }
    }
    fprintf(file, "%85s\n", "");

    //-
    QSqlQuery query_sum("SELECT SUM(Mkoq_ks_rubdb), SUM(Mkoq_ks_rubkr) FROM mkoq_ks");
    query_sum.next();
    //-

    QString mkoq_ks_rubdb_sum; mkoq_ks_rubdb_sum.setNum(mkoq_sumdb); //query_sum.value(0).toString();
    QString mkoq_ks_rubkr_sum; mkoq_ks_rubkr_sum.setNum(mkoq_sumkr); //query_sum.value(1).toString();
    fprintf(file, "%39s%s%3s%5s%7s%5s%6s\n", "", "mkoq_itogo po schetu", "", mkoq_ks_rubdb_sum.toLocal8Bit().data(), "", mkoq_ks_rubkr_sum.toLocal8Bit().data(), "");
    fprintf(file, "%85s\n", "");
    fclose(file);
    QFile qfile("mkoq_otchet.txt");
    if (!qfile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "info", qfile.errorString());
    }
    QTextStream in(&qfile);
    ui->mkoq_ksroo_qr->setText(in.readAll());
}

mkoq_ksroo::~mkoq_ksroo()
{
    delete ui;
}

void mkoq_ksroo::mkoq_ksroo_exit_cClick() {
    this->close();
}

void mkoq_ksroo::on_mkoq_ksroo_print_c_clicked()
{
    QMessageBox::about(this, "Printing", "Your otchet is printed");
}
