/*  ---------------------------------------------------------------------------
 *  nom         :   qamabstractdigital.cpp
 *  
 *  description :   IMPLEMENTATION classe de base abstraite QamAbstractDigital
 *  				
 *  création    :   jan 2004
 *  version     :   4.5
 *  maj			:	20/02/2012
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

#include "qamabstractdigital.h"

QamAbstractDigital::QamAbstractDigital(QWidget* parent )
	: QamWidget( parent )
	, m_state( QamWidget::Green )
	, m_oldState( QamWidget::Green )
	, m_blink( QamWidget::Fixed )
	, m_customColor( Qt::black )
	, m_alphaOff( 0 )
	, m_shining( true )
	, m_it( NULL )
	, m_flash( false )	
{
	m_background = new QPixmap( size() ) ;
	m_redraw = false ;

	m_it = new QTimer( this ) ;
	connect( m_it, SIGNAL( timeout() ), SLOT( timeout() ) ) ;
	m_it->stop() ;
}

QamAbstractDigital::~QamAbstractDigital()
{
	m_it->stop() ;
	delete m_it ;

	delete m_background ;
}

void QamAbstractDigital::showBackground()
{
	if (( m_background->size() != size() )||( m_redraw )) {
		delete m_background ;
//// modif. 30/11/2012 (Mac)
//        if ( size().isNull() ) m_background = new QPixmap( QSize(16,16) ) ;
//        else
////
        m_background = new QPixmap( size() ) ;
        QPainter	painter( m_background ) ;
		drawBackground(painter) ;
		m_redraw = false ;
	}
    QPainter painter(this);
    painter.drawPixmap(0, 0, *m_background ) ;
}

void QamAbstractDigital::updateWithBackground()
{
	m_redraw = true ;
	update() ;
}

// état courant on/off

QamWidget::State 	QamAbstractDigital::state() const { return m_state ; }

void 	QamAbstractDigital::setState(QamWidget::State state )
{
	m_state = state ; 
	if ( m_state != QamWidget::Off ) m_oldState = m_state ; 
	update() ; 
}

bool 	QamAbstractDigital::isOn() const 
{
	return (bool)( state() != QamWidget::Off ) ;
}

void 	QamAbstractDigital::off() { setState( QamWidget::Off ) ; }		// slot

void 	QamAbstractDigital::on() { setState( m_oldState ) ; }			// slot

void	QamAbstractDigital::toggle()									// slot
{
	if ( state() == QamWidget::Off )	on() ;
	else								off() ;
	update() ;
}

// effet de brillance par gradient

bool 	QamAbstractDigital::isShining() const { return m_shining ; }

void 	QamAbstractDigital::setShining(bool shining ) 
{
	m_shining = shining ;
	update() ;
}

bool QamAbstractDigital::isGradient() const { return isShining() ; }				// obsolète
void QamAbstractDigital::setGradient(bool gradient ) { setShining(gradient ) ; }	// obsolète

// couleur personnalisée

QColor	QamAbstractDigital::customColor() const	{ return m_customColor ; }

void 	QamAbstractDigital::setCustomColor(const QColor& color )
{
	m_customColor = color ;
	update() ;
}

// effet de transparence quand état = Off

int		QamAbstractDigital::alphaOff() const { return m_alphaOff ; }

void	QamAbstractDigital::setAlphaOff(int alphaOff )
{
	if ( alphaOff < 0 )	alphaOff = 0 ;
	m_alphaOff = alphaOff % 256 ;
	update() ;
}

// couleur état = On

QColor	QamAbstractDigital::onColor() const
{
	QColor	color = QBrush( palette().background() ).color() ;
	switch( m_oldState ) {
		case QamWidget::Off : break ;
		case QamWidget::Green :		color = Qt::green ;  break ;
		case QamWidget::Yellow :	color = Qt::yellow ; break ;
		case QamWidget::Red :		color = Qt::red ;    break ;
		default :					color = customColor() ;    break ;
	}
	return color ;
}

// couleur état = Off

QColor	QamAbstractDigital::offColor() const
{
	QColor	color = QBrush( palette().background() ).color() ;
	
	if ( alphaOff() ) {
		color = onColor() ;
		color.setAlpha( alphaOff() ) ;
	}
	return color ;
}

// horloge pour clignotement / flash

void	QamAbstractDigital::timeout()									// slot
{
	if ( m_flash ) {
		m_it->stop() ;
		m_flash = false ;
		m_blink = QamWidget::Fixed ;
		off() ;
		emit flashEnded() ;
	}
	else {
		toggle() ;
	}
	update() ;
}

// clignotement

QamWidget::Blink 	QamAbstractDigital::blink() const { return m_blink ; }

void 	QamAbstractDigital::setBlink(QamWidget::Blink blink )
{
	m_blink = blink ;
	if ( m_blink == QamWidget::Fixed )	{
		m_it->stop() ;
		on() ;
	}
	if ( m_blink == QamWidget::Slow )	m_it->start( 500 ) ;
	if ( m_blink == QamWidget::Fast )	m_it->start( 250 ) ;
}

// allumage temporisé

void	QamAbstractDigital::setFlash(QamWidget::State state, int ms )
{
	setState(state ) ;
	if ( !isOn() ) 	return ;
	m_it->start( ms ) ;
	m_flash = true ;
}

