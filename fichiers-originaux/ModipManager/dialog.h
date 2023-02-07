/* ----------------------------------------------------------------------------
 |	Nom :			dialog.h
 |	Projet :		Qam Modbus over TCP/IP : application ModipManager
 |	Sujet :     	Maître Modbus TCP multi-esclaves
 |  Auteur :		Alain Menu
 |	Version :		1.0
 |	Création :		janvier 2014
 |	Mise à jour :	08/02/2014
 |	Fabrication :	Qt4 / Qt5 OpenSource (Desktop)
 + ------------------------------------------------------------------------- */
/*
 |	Copyright (c) 2014 by Alain Menu <alain.menu@ac-creteil.fr>
 |
 |  This file is part of "Qam Modbus over TCP/IP project"
 |
 |  This program is free software ;  you can  redistribute it and/or  modify it
 |  under the terms of the  GNU General Public License as published by the Free
 |  Software Foundation ; either version 2 of the License, or  (at your option)
 |  any later version.
 |
 |  This program is distributed in the hope that it will be useful, but WITHOUT
 |  ANY WARRANTY ; without even the  implied  warranty  of  MERCHANTABILITY  or
 |  FITNESS FOR  A PARTICULAR PURPOSE. See the  GNU General Public License  for
 |  more details < http://www.gnu.org/licenses/gpl.txt >.
 + ------------------------------------------------------------------------- */

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QCloseEvent>
#include <QSettings>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"

#define ABOUTMESSAGE \
	"<p><h3>ModipManager - version %1</h3>" \
	"<p>Modbus over TCP/IP Supervisor Tool" \
	"<p><i>based on %2</i>" \
	"<p>Copyright (c)2014 by Alain Menu " \
	"<a href=\"mailto:alain.menu@ac-creteil.fr\">alain.menu@ac-creteil.fr</a>"

#define	VERSION "1.0"


class Dialog : public QDialog, private Ui::Dialog
{
	Q_OBJECT

  public:
	explicit Dialog(QWidget* parent = 0 ) ;

  protected:
	void closeEvent(QCloseEvent* event ) ;

  public slots:
	void on_pbuLogo_clicked() ;
	void on_pbuNew_clicked() ;
	void on_pbuConnect_clicked() ;
	void on_pbuReset_clicked() ;
	void on_pbuReadAll_clicked() ;
	void on_pbuRead_clicked() ;
	void on_tabWidget_currentChanged(int index ) ;
	void on_tabWidget_tabCloseRequested(int index ) ;
	void info(const QString& source, const QString& message ) ;
	void valueChanged(int table,const QString& name ) ;

  private:
	void readSettings() ;
	void writeSettings() ;
	void showPrompt(const QString& prompt ) ;
	void showMessage(const QString& msg, bool bold = false, QColor color = Qt::black ) ;

  private:
	QString		m_configDir ;

	QList<QamModbusMap *>		m_modbusMap ;
	QList<QamTcpClient *>		m_tcpCLient ;
	QList<QamModbusMapViewer *>	m_modbusMapViewer ;
} ;

#endif // DIALOG_H
