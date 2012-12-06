#-------------------------------------------------
#
# Project created by QtCreator 2012-12-06T12:37:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = voglet-qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    voglet.cpp \
    tinyxml2.cpp

HEADERS  += mainwindow.h \
    voglet.h \
    entry.h \
    tinyxml2.h

FORMS    += mainwindow.ui
