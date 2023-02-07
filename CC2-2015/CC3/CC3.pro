#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T13:22:10
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CC3
TEMPLATE = app

INCLUDEPATH += ./ModipTcp ./ModipMap

SOURCES += main.cpp\
    cc3.cpp \
    ModipMap/qammodbusdata.cpp \
    ModipMap/qammodbusmap.cpp \
    ModipMap/qammodbusmapviewer.cpp \
    ModipTcp/qamabstractserver.cpp \
    ModipTcp/qamtcpclient.cpp \
    ModipTcp/qamtcpconnection.cpp \
    ModipTcp/qamtcpserver.cpp \
    bouton.cpp \
    auto.cpp

HEADERS  += cc3.h \
    ModipMap/qammodbusdata.h \
    ModipMap/qammodbusmap.h \
    ModipMap/qammodbusmapviewer.h \
    ModipTcp/qamabstractserver.h \
    ModipTcp/qamtcpclient.h \
    ModipTcp/qamtcpconnection.h \
    ModipTcp/qamtcpserver.h \
    bouton.h \
    auto.h

FORMS    += \
    cc3.ui

CONFIG += mobility
MOBILITY = 

