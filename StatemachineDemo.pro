#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T11:55:26
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StatemachineDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    demostatemachine.cpp \
    displaydemostatemachineimagewidget.cpp

HEADERS  += mainwindow.h \
    demostatemachine.h \
    displaydemostatemachineimagewidget.h

FORMS    += mainwindow.ui \
    displaydemostatemachineimagewidget.ui

RESOURCES += \
    resources.qrc
