#-------------------------------------------------
#
# Project created by QtCreator 2014-03-18T08:41:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LLF-Scara
TEMPLATE = app

UI_DIR		= .uic
RCC_DIR		= .uic
MOC_DIR		= .moc
OBJECTS_DIR	= .obj

INCLUDEPATH += ../ModipTcp ../ModipMap ../QamWidgets

SOURCES += main.cpp\
        dialog.cpp \
		dialogconf.cpp \
		dialogmanu.cpp \
		../ModipTcp/qamtcpserver.cpp \
		../ModipTcp/qamabstractserver.cpp \
		../ModipTcp/qamtcpconnection.cpp \
		../ModipMap/qammodbusmap.cpp \
		../ModipMap/qammodbusdata.cpp \
		../ModipMap/qammodbusmapviewer.cpp \
		../QamWidgets/qamabstractdigital.cpp \
		../QamWidgets/qamled.cpp \
		qamcellflexpuzzle.cpp \
		qamscara.cpp

HEADERS += dialog.h \
		../ModipTcp/qamtcpserver.h \
		../ModipTcp/qamabstractserver.h \
		../ModipTcp/qamtcpconnection.h \
		../ModipMap/qammodbusmap.h \
		../ModipMap/qammodbusdata.h \
		../ModipMap/qammodbusmapviewer.h \
		../QamWidgets/qamwidget.h \
		../QamWidgets/qamabstractdigital.h \
		../QamWidgets/qamled.h \
		qamcellflexpuzzle.h \
		qamscara.h \
		cellflex_template.h

FORMS    += dialog.ui

INCLUDEPATH +=".\Scara\include"


LIBS += -L".\Scara\lib"
LIBS += -lm5apiw32 -lm5scara

RESOURCES += \
    llf-scara.qrc
