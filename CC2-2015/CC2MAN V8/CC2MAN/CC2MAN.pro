#-------------------------------------------------
#
# Project created by QtCreator 2015-02-06T15:58:15
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CC2MAN
TEMPLATE = app

INCLUDEPATH += ./ModipTcp ./ModipMap

SOURCES += main.cpp\
        manuel.cpp \
    ModipMap/qammodbusmapviewer.cpp \
    ModipMap/qammodbusmap.cpp \
    ModipMap/qammodbusdata.cpp \
    ModipTcp/qamtcpserver.cpp \
    ModipTcp/qamtcpconnection.cpp \
    ModipTcp/qamtcpclient.cpp \
    ModipTcp/qamabstractserver.cpp \
    bouton.cpp \
    threadauto.cpp

HEADERS  += manuel.h \
    ModipMap/qammodbusmapviewer.h \
    ModipMap/qammodbusmap.h \
    ModipMap/qammodbusdata.h \
    ModipTcp/qamtcpserver.h \
    ModipTcp/qamtcpconnection.h \
    ModipTcp/qamtcpclient.h \
    ModipTcp/qamabstractserver.h \
    bouton.h \
    threadauto.h

FORMS    += manuel.ui

RESOURCES += mesressources.qrc
