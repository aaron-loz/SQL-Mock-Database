#-------------------------------------------------
#
# Project created by QtCreator 2016-08-07T16:17:09
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQLPracticing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adddbdialog.cpp

HEADERS  += mainwindow.h \
    createconnection.h \
    adddbdialog.h

FORMS    += mainwindow.ui \
    adddbdialog.ui
