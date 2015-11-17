#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T17:04:56
#
#-------------------------------------------------

QT       += core gui
CONFIG   += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SudokuGame
TEMPLATE = app


SOURCES += main.cpp \
    cell.cpp \
    gamefield.cpp \
    gamewidget.cpp

HEADERS  += \
    cell.h \
    gamefield.h \
    gamewidget.h

RESOURCES += \
    source.qrc
