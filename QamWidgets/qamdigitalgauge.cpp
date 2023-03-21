/*  ---------------------------------------------------------------------------
 *  nom         :   qamdigitalgauge.cpp
 *  
 *  description :   IMPLEMENTATION de la classe QamDigitalGauge
 *  				
 *  création    :   mars 2012
 *  version     :   1.0
 *  maj			:	10/03/2012
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

#define QAMDIGITALGAUGE_VERSION	"1.0"

#include "qamdigitalgauge.h"

QString QamDigitalGauge::version() { return QString( QAMDIGITALGAUGE_VERSION ) ; }

QamDigitalGauge::QamDigitalGauge(QWidget* parent )
	: QamBargraph( parent )
	, m_lowThreshold( 4 )
	, m_highThreshold( 8 )
	, m_lowColor( Qt::yellow )
	, m_normalColor( Qt::green )
	, m_highColor( Qt::red )
{
	setState( QamWidget::Custom ) ;
	setSize( 12 ) ;
	setValue( 6 ) ;
	setColors() ;
}

QamDigitalGauge::~QamDigitalGauge()
{
}

void QamDigitalGauge::setColors()
{
	for (int i = 0 ; i < size() ; ++i ) {
		if ( i < lowThreshold() )				m_leds[i].setCustomColor( lowColor() ) ;
		else if ( i >= highThreshold() - 1 )	m_leds[i].setCustomColor( highColor() ) ;
		else									m_leds[i].setCustomColor( normalColor() ) ;
	}
	setValue( value() ) ;
}

void QamDigitalGauge::setSize(int numLeds )
{
	QamBargraph::setSize( numLeds ) ;
	setColors() ;
}

int	QamDigitalGauge::lowThreshold() const { return m_lowThreshold ; }

int	QamDigitalGauge::highThreshold() const { return m_highThreshold ; }

void QamDigitalGauge::setLowThreshold(int low )
{
	m_lowThreshold = low ;
	setColors() ;
}

void QamDigitalGauge::setHighThreshold(int high )
{
	m_highThreshold = high ;
	setColors() ;
}

bool QamDigitalGauge::isLowLevel() const 
{
	return value() < lowThreshold() ;
}

bool QamDigitalGauge::isHighLevel() const 
{
	return value() > highThreshold() ;
}

bool QamDigitalGauge::isNormalLevel() const 
{
	return !( isLowLevel() || isHighLevel() ) ;
}

QColor QamDigitalGauge::lowColor() const { return m_lowColor ; }

QColor QamDigitalGauge::normalColor() const { return m_normalColor ; }

QColor QamDigitalGauge::highColor() const { return m_highColor ; }

void QamDigitalGauge::setLowColor(const QColor& color )
{
	m_lowColor = color ;
	setColors() ;
}

void QamDigitalGauge::setNormalColor(const QColor& color )
{
	m_normalColor = color ;
	setColors() ;
}

void QamDigitalGauge::setHighColor(const QColor& color )
{
	m_highColor = color ;
	setColors() ;
}

