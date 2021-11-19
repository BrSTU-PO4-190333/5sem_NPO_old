#-------------------------------------------------
#
# Project created by QtCreator 2018-12-22T14:16:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gpiq_prj
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
    gpiq_cdsff.cpp \
    gpiq_cdsnn.cpp \
    gpiq_cdstt.cpp \
    gpiq_ksrjj.cpp \
    gpiq_ksroo.cpp \
    gpiq_ksrvv.cpp \
    gpiq_kssrr.cpp \
    gpiq_menu.cpp \
    gpiq_pdsxx.cpp \
    gpiq_rjsxx.cpp \
    gpiq_rjtks.cpp \
    gpiq_togxx.cpp \
    gpiq_tosxx.cpp \
    gpiq_xxsgrid.cpp \
    gpiq_xxsrest.cpp \
    gpiq_xxssave.cpp \

HEADERS += \
    gpiq_cdsff.h \
    gpiq_cdsnn.h \
    gpiq_cdstt.h \
    gpiq_ksrjj.h \
    gpiq_ksroo.h \
    gpiq_ksrvv.h \
    gpiq_kssrr.h \
    gpiq_menu.h \
    gpiq_pdsxx.h \
    gpiq_rjsxx.h \
    gpiq_rjtks.h \
    gpiq_togxx.h \
    gpiq_tosxx.h \
    gpiq_xxsgrid.h \
    gpiq_xxsrest.h \
    gpiq_xxssave.h \

FORMS += \
    gpiq_cdsff.ui \
    gpiq_cdsnn.ui \
    gpiq_cdstt.ui \
    gpiq_ksrjj.ui \
    gpiq_ksroo.ui \
    gpiq_ksrvv.ui \
    gpiq_kssrr.ui \
    gpiq_menu.ui \
    gpiq_pdsxx.ui \
    gpiq_rjsxx.ui \
    gpiq_rjtks.ui \
    gpiq_togxx.ui \
    gpiq_tosxx.ui \
    gpiq_xxsgrid.ui \
    gpiq_xxsrest.ui \
    gpiq_xxssave.ui \

DISTFILES += \
    gpiq_data.sqlite \
