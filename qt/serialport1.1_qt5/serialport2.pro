#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T22:04:59
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serialport2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    readthread.cpp \
    writethread.cpp

HEADERS  += mainwindow.h \
    readthread.h \
    writethread.h

FORMS    += mainwindow.ui
