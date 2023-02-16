#-------------------------------------------------
#
# Project created by QtCreator 2015-06-05T16:04:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OK
TEMPLATE = app

INCLUDEPATH += ./lib

SOURCES += main.cpp\
        widget.cpp\
    qamscara.cpp

HEADERS  += widget.h\
    lib/m5apiw32.h \
    lib/M5Scara.h \
    qamscara.h

FORMS    += widget.ui

LIBS += -L"C:\Scara\OK\lib"
LIBS += -lm5apiw32 -lm5scara

