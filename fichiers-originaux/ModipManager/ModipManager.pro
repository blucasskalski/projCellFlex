#-------------------------------------------------
#
# Project created by QtCreator 2014-02-01T16:44:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModipManager
TEMPLATE = app

UI_DIR		= .uic
RCC_DIR		= .uic
MOC_DIR		= .moc
OBJECTS_DIR	= .obj

INCLUDEPATH += ../ModipTcp ../ModipMap

SOURCES += main.cpp\
		dialog.cpp \
	../ModipTcp/qamtcpclient.cpp \
	../ModipTcp/qamabstractserver.cpp \
	../ModipMap/qammodbusmap.cpp \
	../ModipMap/qammodbusdata.cpp \
	../ModipMap/qammodbusmapviewer.cpp

HEADERS  += dialog.h \
	../ModipTcp/qamtcpclient.h \
	../ModipTcp/qamabstractserver.h \
	../ModipMap/qammodbusmap.h \
	../ModipMap/qammodbusdata.h \
	../ModipMap/qammodbusmapviewer.h

FORMS    += dialog.ui

RESOURCES += \
    modipmanager.qrc

macx:ICON = images/qam47.icns
