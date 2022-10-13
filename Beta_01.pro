#-------------------------------------------------
#
# Project created by QtCreator 2022-10-05T17:31:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Beta_01
TEMPLATE = app


SOURCES += main.cpp\
    widget.cpp \
    player.cpp \
    monster.cpp

HEADERS  += widget.h \
    player.h \
    monster.h

FORMS    += widget.ui

CONFIG += c++11

RESOURCES += \
    images.qrc
