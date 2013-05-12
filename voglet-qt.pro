#-------------------------------------------------
#
# Project created by QtCreator 2012-12-06T12:37:30
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = voglet-qt
TEMPLATE = app

SOURCES += src/main.cpp\
       src/mainwindow.cpp \
    src/voglet.cpp \
    src/config.cpp \
    src/xmlhelper.cpp

HEADERS  += src/mainwindow.h \
    src/voglet.h \
    src/entry.h \
    src/config.h \
    src/xmlhelper.h

FORMS    += mainwindow.ui
