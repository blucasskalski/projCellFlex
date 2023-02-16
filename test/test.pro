#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T14:08:29
#
#IP::192.168.3.14
#passerelle:: 192.168.3.1
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

INCLUDEPATH += ./QamScara ./lib ./ModipMap ./ModipTcp

SOURCES += main.cpp\
        widget.cpp \
    QamScara/qamscara.cpp \
    ModipMap/qammodbusdata.cpp \
    ModipMap/qammodbusmap.cpp \
    ModipMap/qammodbusmapviewer.cpp \
    ModipTcp/qamabstractserver.cpp \
    ModipTcp/qamtcpclient.cpp \
    ModipTcp/qamtcpconnection.cpp \
    ModipTcp/qamtcpserver.cpp

HEADERS  += widget.h \
    QamScara/qamscara.h \
    lib/m5apiw32.h \
    lib/M5Scara.h \
    ModipMap/qammodbusdata.h \
    ModipMap/qammodbusmap.h \
    ModipMap/qammodbusmapviewer.h \
    ModipTcp/qamabstractserver.h \
    ModipTcp/qamtcpclient.h \
    ModipTcp/qamtcpconnection.h \
    ModipTcp/qamtcpserver.h

FORMS    += \
    widget.ui

LIBS += -L"C:\Documents and Settings\Scara\Bureau\test\lib"
LIBS += -lm5apiw32 -lm5scara
