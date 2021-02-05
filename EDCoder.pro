#-------------------------------------------------
#
# Project created by QtCreator 2018-03-27T02:20:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EDCoder
TEMPLATE = app
CONFIG += c++11


SOURCES += \
        main.cpp\
        src/mainwindow.cpp \
        src/CEDCoder.cpp    \
        src/SM4.c  \
        src/SM3.c   \
 #       src/SM2.c

HEADERS  += \
    include/mainwindow.h \
    include/CEDCoder.h \
    include/EDCoderCommon.h\
    include/SM4.h   \
    include/SM3.h  \
#    include/SM2.h

FORMS    += mainwindow.ui
