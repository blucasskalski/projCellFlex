/* ----------------------------------------------------------------------------
 |	Nom :			qammodbusmapviewer.h
 |	Projet :		Qam Modbus over TCP/IP
 |	Sujet :     	Visualiseur arborescent d'un objet QamModbusMap
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

#ifndef QAMMODBUSMAPVIEWER_H
#define QAMMODBUSMAPVIEWER_H

/*!
  @file
  @brief Visualiseur arborescent de cartographie d'un équipement Modbus
 */

/*!
 @class QamModbusMapViewer
 @brief Visualiseur arborescent de cartographie d'un équipement Modbus.

 La classe QamModbusMapViewer permet de visualiser sous forme d'arbre la
 cartographie d'un serveur Modbus encapsulée dans un objet de classe
 QamModbusMap ; l'unique opération à effectuer consiste à initialiser
 le visualiseur au moyen de la méthode setModbusMap().

 QamModbusMapViewer autorise l'édition de la valeur des données,
 les saisies sont contrôlées et automatiquement formatées par l'objet
 QamModbusMap.

 QamModbusMapViewer dérive de QTreeView. Un objet de classe QamModbusMapViewer
 peut donc être inséré directement à partir de Qt Designer sur une interface
 utilisateur grâce au mécanisme de promotion de widgets.
 */

#include <QTreeView>
#include <QStandardItemModel>
#include "qammodbusmap.h"

class QamModbusMapViewer : public QTreeView
{
	Q_OBJECT

  public:
	explicit QamModbusMapViewer(QWidget* parent = 0 ) ;

	void setModbusMap(QamModbusMap* map ) ;
	int currentTable() ;
	QString currentName() ;

  private slots:
	void itemChanged(QStandardItem* item ) ;
	void updateModbusData(int table, const QString& name ) ;

  private:
	QamModbusMap::PrimaryTable rowToTable( int row ) ;
	int tableToRow(QamModbusMap::PrimaryTable table ) ;
	void setModbusTable(QamModbusMap::PrimaryTable table, quint16 baseNumber, int treeRow, bool isWords ) ;
	QStandardItem* newItem(const QString& item, bool editable = false, QColor bkColor = Qt::white ) ;

  private:
	int						m_iName ;
	int						m_iHex ;
	int						m_iDisplay ;
	int						m_iValue ;
	bool					m_internalUpdate ;
	QStandardItemModel*		m_model ;
	QStringList				m_labels ;
	QList<QStandardItem *>	m_tables ;
	QamModbusMap*			m_modbusMap ;
} ;

#endif // QAMMODBUSMAPVIEWER_H
