#include "qamimghistogram.h"
#include <QDebug>
#include <QPainter>

QamImgHistogram::QamImgHistogram(QWidget *parent)
	: QWidget(parent)
	, isInit( false )
	, margin(10)
{
}

void QamImgHistogram::clear()
{
	for ( int i = 0 ; i < 256 ; ++i ) {
		spectr[i][0] = 0 ;
		spectr[i][1] = 0 ;
		spectr[i][2] = 0 ;
	}
}

// calcul du spectre d'une image

void QamImgHistogram::setImage(QImage& img )
{
	clear() ;
	for (int j = 0 ; j < img.height() ; j++ ) {
		for ( int i = 0 ; i < img.width() ; i++ ) {
			QRgb rgb = img.pixel(i, j ) ;
			spectr[ qRed( rgb ) ][0] += 1 ;
			spectr[ qGreen( rgb ) ][1] += 1 ;
			spectr[ qBlue( rgb ) ][2] += 1 ;
		}
	}
	isInit = true ;
	update() ;
}

// tracé de l'histogramme

void QamImgHistogram::paintEvent(QPaintEvent* /* pe */ )
{
	if ( !isInit )	return ;

	QPainter	paint(this) ;

	uint max = 0 ;
	for ( int i = 0 ; i < 256 ; ++i ) {
		for ( int j = 0 ; j < 3 ; ++j ) {
			if ( spectr[i][j] > max )	max = spectr[i][j] ;
		}
	}

	paint.save() ;

	int xMin = margin ;
	int xMax = width() - margin ;
	int yMin = height() - margin ;
	int yMax = 0 ;

	paint.setPen( Qt::gray ) ;
	paint.drawLine(xMin, yMin, xMax, yMin ) ;
	paint.drawLine(xMin, yMin, xMin, yMax ) ;

	int mx, my0, my1, my2 ;

	for ( int i = 0 ; i < 256 ; ++i ) {
		int x  = xMin + (int)( i * (double)(xMax -xMin) / 255 ) ;
		int y0 = yMin - (int)( spectr[i][0] * (double)(yMin - yMax) / max ) ;
		int y1 = yMin - (int)( spectr[i][1] * (double)(yMin - yMax) / max ) ;
		int y2 = yMin - (int)( spectr[i][2] * (double)(yMin - yMax) / max ) ;

		if ( i ) {
			if (( y0 == y1 )&&( y0 == y2 )) {
				paint.setPen( Qt::black ) ;
				paint.drawLine(mx, my0, x, y0 ) ;
			}
			else {
				paint.setPen( Qt::red ) ;
				paint.drawLine(mx, my0, x, y0 ) ;
				paint.setPen( Qt::green ) ;
				paint.drawLine(mx, my1, x, y1 ) ;
				paint.setPen( Qt::blue ) ;
				paint.drawLine(mx, my2, x, y2 ) ;
			}
		}
		else {
			if (( y0 == y1 )&&( y0 == y2 )) {
				paint.setPen( Qt::black ) ;
				paint.drawPoint(x, y0 ) ;
			}
			else {
				paint.setPen( Qt::red ) ;
				paint.drawPoint(x, y0 ) ;
				paint.setPen( Qt::green ) ;
				paint.drawPoint(x, y1 ) ;
				paint.setPen( Qt::blue ) ;
				paint.drawPoint(x, y2 ) ;
			}
		}
		mx = x ; my0 = y0 ; my1 = y1 ; my2 = y2 ;
	}

	paint.restore() ;
}

// détection souris sur histogramme

void QamImgHistogram::enterEvent(QEvent* event )
{
	this->setMouseTracking( true ) ;

	QWidget::enterEvent(event) ;
}

void QamImgHistogram::leaveEvent(QEvent* event )
{
	this->setMouseTracking( false ) ;
	emit xTracking(-1) ;
	QWidget::leaveEvent(event) ;
}

// conversion abscisse souris -> abscisse histogramme

int QamImgHistogram::xMouse(QMouseEvent* event )
{
	int x = event->pos().x() ;
	int xMin = margin ;
	int xMax = width() - margin ;

	x = (int)( (double)( x - xMin ) / ( xMax - xMin ) * 255 ) ;
	if ( ( x < 0 )||( x > 255) )	x = -1 ;

	return x ;
}

// 'tracking' seuil sur histogramme

void QamImgHistogram::mouseMoveEvent(QMouseEvent* event )
{
	emit xTracking( xMouse(event) ) ;
	QWidget::mouseMoveEvent(event) ;
}

// seuil prélevé par clic sur histogramme

void QamImgHistogram::mousePressEvent(QMouseEvent* event )
{
	emit xClic( xMouse(event) ) ;
	QWidget::mousePressEvent(event) ;
}
