#-------------------------------------------------
#
# Project created by QtCreator 2018-12-22T14:16:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mkoq_prj
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    mkoq_cdsff.cpp \
    mkoq_cdsnn.cpp \
    mkoq_cdstt.cpp \
    mkoq_ksrjj.cpp \
    mkoq_ksroo.cpp \
    mkoq_ksrvv.cpp \
    mkoq_kssrr.cpp \
    mkoq_menu.cpp \
    mkoq_pdsxx.cpp \
    mkoq_rjsxx.cpp \
    mkoq_rjtks.cpp \
    mkoq_togxx.cpp \
    mkoq_tosxx.cpp \
    mkoq_xxsgrid.cpp \
    mkoq_xxsrest.cpp \
    mkoq_xxssave.cpp \

HEADERS += \
    mkoq_cdsff.h \
    mkoq_cdsnn.h \
    mkoq_cdstt.h \
    mkoq_ksrjj.h \
    mkoq_ksroo.h \
    mkoq_ksrvv.h \
    mkoq_kssrr.h \
    mkoq_menu.h \
    mkoq_pdsxx.h \
    mkoq_rjsxx.h \
    mkoq_rjtks.h \
    mkoq_togxx.h \
    mkoq_tosxx.h \
    mkoq_xxsgrid.h \
    mkoq_xxsrest.h \
    mkoq_xxssave.h \

FORMS += \
    mkoq_cdsff.ui \
    mkoq_cdsnn.ui \
    mkoq_cdstt.ui \
    mkoq_ksrjj.ui \
    mkoq_ksroo.ui \
    mkoq_ksrvv.ui \
    mkoq_kssrr.ui \
    mkoq_menu.ui \
    mkoq_pdsxx.ui \
    mkoq_rjsxx.ui \
    mkoq_rjtks.ui \
    mkoq_togxx.ui \
    mkoq_tosxx.ui \
    mkoq_xxsgrid.ui \
    mkoq_xxsrest.ui \
    mkoq_xxssave.ui \

DISTFILES += \
    mkoq_data.sqlite \
