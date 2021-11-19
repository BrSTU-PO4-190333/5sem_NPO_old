#include "gpiq_ksroo.h"
#include "ui_gpiq_ksroo.h"
#include <QSqlQuery>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <cstdio>
#include <QDate>
#include <QDebug>

gpiq_ksroo::gpiq_ksroo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpiq_ksroo)
{
    ui->setupUi(this);
    connect(ui->gpiq_ksroo_exit_c, SIGNAL(clicked()), this, SLOT(gpiq_ksroo_exit_cClick()));
    QSqlQuery query("SELECT Gpiq_cd_s, Gpiq_cd_datad, Gpiq_cd_datas FROM gpiq_cd");
    query.next();
    QString gpiq_cd_s = query.value(0).toString();
    QString gpiq_cd_datad = query.value(1).toString();
    QDate gpiq_cd_datado = QDate::fromString(gpiq_cd_datad, "dd.MM.yyyy");
    QString gpiq_cd_datas = query.value(2).toString();
    QDate gpiq_cd_dataso = QDate::fromString(gpiq_cd_datas, "dd.MM.yyyy");
    FILE* file;
    file = fopen("gpiq_otchet.txt", "w");
    fprintf(file, "%85s\n", "");
    fprintf(file, "%4s%-20.20s%8s%s%13s%s%2s\n", "", "=Galanin P. I.=", "", "оборотно-сальдова ведомость", "", "=gpiq_krsoo=", "");
    fprintf(file, "%8s%s%4s%4s%13s%s%4s%10s%s%10s     \n", "", "schet", "", gpiq_cd_s.toLocal8Bit().data(), "", "interval s", "", gpiq_cd_datas.toLocal8Bit().data(), "      do    ", gpiq_cd_datad.toLocal8Bit().data());
    fprintf(file, "%85s\n", "");
    fprintf(file, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(file, "   data      | dokument   | schet | korr schet | vx | oborot db kr | isx      \n");
    fprintf(file, "  %s  \n", "---------------------------------------------------------------------------------");
    fprintf(file, "%85s\n", "");
    QSqlQuery query_ks("SELECT Gpiq_ks_data, Gpiq_ks_dokk, Gpiq_ks_s, Gpiq_ks_ks, Gpiq_ks_rubdb, Gpiq_ks_rubkr, Gpiq_ks_dokn, Gpiq_ks_dokd FROM gpiq_ks");

    int gpiq_sumkr = 0;
    int gpiq_sumdb = 0;

    while (query_ks.next()) {
        QString gpiq_ks_data = query_ks.value(0).toString();
        QDate gpiq_ks_datat = QDate::fromString(gpiq_ks_data, "dd.MM.yyyy");
        QString gpiq_ks_dokk;
        QString gpiq_ks_s = query_ks.value(2).toString();
        QString gpiq_ks_ks;
        QString gpiq_ks_rubdb;
        QString gpiq_ks_rubkr;
        QString gpiq_ks_dokn;
        QString gpiq_ks_dokd;

        if( gpiq_cd_s == gpiq_ks_s && gpiq_cd_dataso < gpiq_ks_datat &&
                gpiq_ks_datat < gpiq_cd_datado) {
            gpiq_ks_dokk = query_ks.value(1).toString();
            gpiq_ks_s = query_ks.value(2).toString();
            gpiq_ks_ks = query_ks.value(3).toString();
            gpiq_ks_rubdb = query_ks.value(4).toString();
            gpiq_ks_rubkr = query_ks.value(5).toString();
            gpiq_sumdb += query_ks.value(4).toInt();
            gpiq_sumkr += query_ks.value(5).toInt();
            gpiq_ks_dokn = query_ks.value(6).toString();
            gpiq_ks_dokd = query_ks.value(7).toString();

            fprintf(file, "  %10s   %-4s%10s%4s%9s%4s%9s%5s%7s%5s%6s\n",
                gpiq_ks_data.toLocal8Bit().data(),
                gpiq_ks_dokk.toLocal8Bit().data(),
                "",
                gpiq_ks_s.toLocal8Bit().data(),
                "",
                gpiq_ks_ks.toLocal8Bit().data(),
                "",
                gpiq_ks_rubdb.toLocal8Bit().data(),
                "",
                gpiq_ks_rubkr.toLocal8Bit().data(),
                "");
            fprintf(file, "%22s%-4s%59s\n", "", gpiq_ks_dokn.toLocal8Bit().data(), "");
            fprintf(file, "%22s%-10s%53s\n", "", gpiq_ks_dokd.toLocal8Bit().data(), "");
            fprintf(file, "%85s\n", "");
        }
    }
    fprintf(file, "%85s\n", "");

    //-
    QSqlQuery query_sum("SELECT SUM(Gpiq_ks_rubdb), SUM(Gpiq_ks_rubkr) FROM gpiq_ks");
    query_sum.next();
    //-

    QString gpiq_ks_rubdb_sum; gpiq_ks_rubdb_sum.setNum(gpiq_sumdb); //query_sum.value(0).toString();
    QString gpiq_ks_rubkr_sum; gpiq_ks_rubkr_sum.setNum(gpiq_sumkr); //query_sum.value(1).toString();
    fprintf(file, "%39s%s%3s%5s%7s%5s%6s\n", "", "gpiq_itogo po schetu", "", gpiq_ks_rubdb_sum.toLocal8Bit().data(), "", gpiq_ks_rubkr_sum.toLocal8Bit().data(), "");
    fprintf(file, "%85s\n", "");
    fclose(file);
    QFile qfile("gpiq_otchet.txt");
    if (!qfile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "info", qfile.errorString());
    }
    QTextStream in(&qfile);
    ui->gpiq_ksroo_qr->setText(in.readAll());
}

gpiq_ksroo::~gpiq_ksroo()
{
    delete ui;
}

void gpiq_ksroo::gpiq_ksroo_exit_cClick() {
    this->close();
}

void gpiq_ksroo::on_gpiq_ksroo_print_c_clicked()
{
    QMessageBox::about(this, "Printing", "Your otchet is printed");
}
