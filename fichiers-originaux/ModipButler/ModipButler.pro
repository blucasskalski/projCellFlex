#-------------------------------------------------
#
# Project created by QtCreator 2014-01-18T10:31:32
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModipButler
TEMPLATE = app

UI_DIR		= .uic
RCC_DIR		= .uic
MOC_DIR		= .moc
OBJECTS_DIR	= .obj

INCLUDEPATH += ../ModipTcp ../ModipMap

SOURCES +=	main.cpp\
			dialog.cpp \
	../ModipTcp/qamtcpserver.cpp \
	../ModipTcp/qamtcpconnection.cpp \
	../ModipTcp/qamabstractserver.cpp \
	../ModipMap/qammodbusmap.cpp \
	../ModipMap/qammodbusdata.cpp \
	../ModipMap/qammodbusmapviewer.cpp

HEADERS  += dialog.h \
	../ModipTcp/qamtcpserver.h \
	../ModipTcp/qamtcpconnection.h \
	../ModipTcp/qamabstractserver.h \
	../ModipMap/qammodbusmap.h \
	../ModipMap/qammodbusdata.h \
	../ModipMap/qammodbusmapviewer.h

FORMS    += dialog.ui

RESOURCES += \
			modipbutler.qrc

macx:ICON = images/qam47.icns
