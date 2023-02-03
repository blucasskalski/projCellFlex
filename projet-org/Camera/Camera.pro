#-------------------------------------------------
#
# Project created by QtCreator 2014-01-15T09:04:49
#
#-------------------------------------------------

QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Camera
TEMPLATE = app


SOURCES += main.cpp\
        camera.cpp \
    qamtcpserver.cpp \
    qamtcpconnection.cpp \
    qammodbusmap.cpp \
    qammodbusdata.cpp \
    qamconnectionthread.cpp \
    qamabstractserver.cpp \
    communication.cpp \
    qamgraphicsscene.cpp \
    qamimgprocessor.cpp \
    qamimghistogram.cpp

HEADERS  += camera.h \
    qamtcpserver.h \
    qamtcpconnection.h \
    qammodbusmap.h \
    qammodbusdata.h \
    qamconnectionthread.h \
    qamabstractserver.h \
    communication.h \
    qamgraphicsscene.h \
    qamimgprocessor.h \
    qamimghistogram.h

FORMS    += camera.ui
