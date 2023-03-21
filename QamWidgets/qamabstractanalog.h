/*  ---------------------------------------------------------------------------
 *  nom         :   qamabstractanalog.h
 *  
 *  description :   INTERFACE classe de base abstraite QamAbstractAnalog
 *  				
 *  création    :   jan 2012
 *  version     :   4.5
 *  maj			:	04/03/2012
 *  ---------------------------------------------------------------------------
 *  Copyright (c) 2004-2012 by Alain Menu   <alain.menu@ac-creteil.fr>
 * 
 *  This file is part of "Qam Custom Widgets for Qt4 Project"
 * 
 *  This program is free software ;  you can  redistribute it and/or  modify it
 *  under the terms of the  GNU General Public License as published by the Free
 *  Software Foundation ; either version 2 of the License, or  (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY ; without even the  implied  warranty  of  MERCHANTABILITY  or
 *  FITNESS FOR  A PARTICULAR PURPOSE. See the  GNU General Public License  for
 *  more details < http://www.gnu.org/licenses/gpl.txt >.
 *  ---------------------------------------------------------------------------
 */

#ifndef QAMABSTRACTANALOG_H
#define QAMABSTRACTANALOG_H

#include "qamwidget.h"
#include <QPixmap>
#include <QPainter>
#include <QtDesigner/QDesignerExportWidget>

#ifdef QAM_WIDGET_PLUGIN
class QDESIGNER_WIDGET_EXPORT QamAbstractAnalog : public QamWidget
#else
class QamAbstractAnalog : public QamWidget
#endif
{
	Q_OBJECT
	Q_PROPERTY( Orientation orientation READ orientation WRITE setOrientation DESIGNABLE isOrientationDesignable )
	Q_PROPERTY( double minimum READ minimum WRITE setMinimum )
	Q_PROPERTY( double maximum READ maximum WRITE setMaximum )
	Q_PROPERTY( double lowThreshold READ lowThreshold WRITE setLowThreshold DESIGNABLE isThresholdDesignable )
	Q_PROPERTY( double highThreshold READ highThreshold WRITE setHighThreshold DESIGNABLE isThresholdDesignable )
	Q_PROPERTY( double value READ value WRITE setValue )
	Q_PROPERTY( QString unit READ unit WRITE setUnit )
	Q_PROPERTY( QColor lowColor READ lowColor WRITE setLowColor DESIGNABLE isThresholdDesignable )
	Q_PROPERTY( QColor normalColor READ normalColor WRITE setNormalColor DESIGNABLE isThresholdDesignable )
	Q_PROPERTY( QColor highColor READ highColor WRITE setHighColor DESIGNABLE isThresholdDesignable )
	Q_PROPERTY( bool shining READ isShining WRITE setShining )
	
  public :
	QamAbstractAnalog(QWidget* parent = 0 ) ;
	virtual ~QamAbstractAnalog() ;

	QamWidget::Orientation orientation() const ;
	double	minimum() const ;
	double	maximum() const ;
	double	lowThreshold() const ;
	double	highThreshold() const ;
	double	value() const ;
	QString	unit() const ;

	void	setOrientation(QamWidget::Orientation orientation ) ;
	void	setMinimum(double min ) ;
	void	setMaximum(double max ) ;
	void	setLowThreshold(double low ) ;
	void	setHighThreshold(double high ) ;
	void	setUnit(const QString& unit ) ;

	bool	isLowLevel() const ;
	bool	isHighLevel() const ;
	bool	isNormalLevel() const ;

	QColor	lowColor() const ;
	QColor	normalColor() const ;
	QColor	highColor() const ;
	bool 	isShining() const ;
	
	void	setLowColor(const QColor& color ) ;
	void	setNormalColor(const QColor& color ) ;
	void	setHighColor(const QColor& color ) ;
	void 	setShining(bool shining = true ) ;

  public slots :
  	void	setValue(int value ) ;
	void	setValue(double value ) ;

  signals:
	void 	lowLevel() ;
	void 	normalLevel() ;
	void 	highLevel() ;
	void 	valueChanged( double value ) ;

  protected :
	virtual bool isOrientationDesignable() const { return true ; }
	virtual bool isThresholdDesignable() const { return true ; }

  	virtual void drawBackground(QPainter& painter ) = 0 ;
  	void	updateWithBackground() ;
	void 	showBackground() ;		// dessin du fond

  private :
  	bool		m_redraw ;			// indique si le fond doit être redessiné
	QPixmap*	m_background ;		// image de fond

  private :
	QamWidget::Orientation m_orientation ;
	double	m_minimum ;
	double	m_maximum ;
	double	m_lowThreshold ;
	double	m_highThreshold ;
	double	m_value ;
	QString	m_unit ;
	QColor	m_lowColor ;
	QColor	m_normalColor ;
	QColor	m_highColor ;
	bool	m_shining ;
} ;

#endif

