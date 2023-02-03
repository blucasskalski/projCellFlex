#include "traitement.h"
#include <math.h>

#include <iostream>

Traitement::Traitement(QObject *parent) :
    QObject(parent)
    ,m_srcImg( NULL )
    ,m_dstImg( NULL )
{
}

void Traitement::setSrcImage(QImage* img ){ m_srcImg = img ; }

void Traitement::setDstImage(QImage* img ){ m_dstImg = img ; }

// ------------------------------------------------------------------------
// opérations de base
// ------------------------------------------------------------------------

// opération avec image masque
void Traitement::mask(QImage maskImg, Operator op)
{
    // TODO
    Q_UNUSED( maskImg ) ;
    Q_UNUSED( op ) ;
}

// binarisation simple/double seuil
// retourne densité entre les seuils en pourcentage

double Traitement::binarization(int low, int high )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return 0 ;

    normalize( low ) ;
    normalize( high ) ;

    m_lastCall = QString("binarization( %1 , %2 )").arg(low).arg(high) ;

    uint	nbPix = 0 ;
    uint	n = 0 ;
    QRgb	colorIn  = qRgb(0,0,0) ;
    QRgb	colorOut = qRgb(255,255,255) ;

    if ( low > high ) {
        colorIn  = qRgb(255,255,255) ;
        colorOut = qRgb(0,0,0) ;
        int tmp = low ; low = high ; high = tmp ;
    }

    normalize( low ) ;
    normalize( high ) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {

            int val = qGray( m_srcImg->pixel(i, j ) ) ;

            if ( ( val >= low )&&( val <= high ) ) {
                m_dstImg->setPixel( i, j, colorIn ) ;
                n++ ;
            }
            else	m_dstImg->setPixel( i, j, colorOut ) ;

            nbPix++ ;
        }
    }
    return 100.0 * ( n / (double)nbPix ) ;
}



// convolution matricielle

void Traitement::matrix(Filter filter )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    int m[3][3] ;

    switch ( filter ) {
        case Embossing :
            m[0][0] = -2 ; m[0][1] = -1 ; m[0][2] =  0 ;
            m[1][0] = -1 ; m[1][1] =  1 ; m[1][2] =  1 ;
            m[2][0] =  0 ; m[2][1] =  1 ; m[2][2] =  2 ;
            break ;
        case HighPass :
            m[0][0] =  0 ; m[0][1] = -1 ; m[0][2] =  0 ;
            m[1][0] = -1 ; m[1][1] =  5 ; m[1][2] = -1 ;
            m[2][0] =  0 ; m[2][1] = -1 ; m[2][2] =  0 ;
            break ;
        case SobelH :
            m[0][0] = -1 ; m[0][1] =  0 ; m[0][2] =  1 ;
            m[1][0] = -2 ; m[1][1] =  0 ; m[1][2] =  2 ;
            m[2][0] = -1 ; m[2][1] =  0 ; m[2][2] =  1 ;
            break ;
        case SobelV :
            m[0][0] = -1 ; m[0][1] = -2 ; m[0][2] = -1 ;
            m[1][0] =  0 ; m[1][1] =  0 ; m[1][2] =  0 ;
            m[2][0] =  1 ; m[2][1] =  2 ; m[2][2] =  1 ;
            break ;
        case Laplace :
            m[0][0] = -1 ; m[0][1] = -1 ; m[0][2] = -1 ;
            m[1][0] = -1 ; m[1][1] =  8 ; m[1][2] = -1 ;
            m[2][0] = -1 ; m[2][1] = -1 ; m[2][2] = -1 ;
        case Blur :
        default :
            m[0][0] =  1 ; m[0][1] =  1 ; m[0][2] =  1 ;
            m[1][0] =  1 ; m[1][1] =  1 ; m[1][2] =  1 ;
            m[2][0] =  1 ; m[2][1] =  1 ; m[2][2] =  1 ;
            break ;
    }

    m_lastCall = QString("matrix( %1 )").arg( filterAsString(filter) ) ;

    int corr  = m[0][0] + m[0][1] + m[0][2] ;
        corr += m[1][0] + m[1][1] + m[1][2] ;
        corr += m[2][0] + m[2][1] + m[2][2] ;
    if ( !corr ) 	corr = 1 ;


    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 1 ; j < h - 1 ; j++ ) {
        for ( int i = 1 ; i < w - 1 ; i++ ) {

            int sumR = 0 , sumG = 0 , sumB = 0 ;

            for ( int y = j - 1 ; y <= ( j + 1 ) ; y++ ) {
                for ( int x = i - 1 ; x <= ( i + 1 ) ; x++ ) {

                    int	mult = m[ y - j + 1 ][ x - i + 1 ] ;

                    QRgb rgb = m_srcImg->pixel(x, y ) ;
                    sumR += qRed( rgb ) * mult ;
                    sumG += qGreen( rgb ) * mult ;
                    sumB += qBlue( rgb ) * mult ;
                }
            }

            sumR /= corr ; normalize( sumR ) ;
            sumG /= corr ; normalize( sumG ) ;
            sumB /= corr ; normalize( sumB ) ;
            m_dstImg->setPixel(i, j, qRgb(sumR, sumG, sumB ) ) ;
        }
    }
}

QString Traitement::filterAsString(Filter filter )
{
    QString s( this->metaObject()->className() ) ;

    if ( filter == Embossing )	return s + "::Embossing" ;
    if ( filter == HighPass )	return s + "::HighPass" ;
    if ( filter == SobelH )		return s + "::SobelH" ;
    if ( filter == SobelV )		return s + "::SobelV" ;
    if ( filter == Laplace )	return s + "::Laplace" ;
    return s + "::Blur" ;
}


//niveau de gris
void Traitement::grayScale(int method )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    if ( method < 0 )	method = 0 ;
    if ( method > 3 )	method = 3 ;

    m_lastCall = QString("grayScale( %1 )").arg(method) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;
            int gray ;
            switch( method ) {
                case 1 :	gray = (int)( 0.2125 * r + 0.7154 * g + 0.0721 * b ) ;	break ;
                case 2 :	gray = (int)( 0.299 * r + 0.587 * g + 0.114 * b ) ;	break ;
                case 3 :	gray = qGray( rgb ) ; break ; // 0.344*r + 0.5*g + 0.156*b
                default :	gray = ( r + g + b ) / 3 ;
            }
            normalize( gray ) ;
            m_dstImg->setPixel(i, j, qRgb(gray, gray, gray ) ) ;
        }
    }
}





//renforcement du blanc
void Traitement::enhanceWhite(int threshold, int gap )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    normalize( threshold ) ;
    m_lastCall = QString("enhanceWhite( %1 , %2 )").arg(threshold).arg(gap) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;
            int ng = qGray( rgb ) ;

            if ( ( ng >= threshold )&&
                 ( r >= ng - gap )&&( r <= ng + gap )&&
                 ( g >= ng - gap )&&( g <= ng + gap )&&
                 ( b >= ng - gap )&&( b <= ng + gap ) )
                r = g = b = 255 ;

            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}


void Traitement::gamma(int val, PrimaryColor color )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("gamma( %1 , %2 )").arg(val).arg( primaryColorAsString(color) ) ;

    double v = val / 10.0 ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;

            if (( color == Rgb )||( color == Red )) {
                r = (int)( pow( (double)r / 255 , v ) * 255 ) ;
                normalize( r ) ;
            }
            if (( color == Rgb )||( color == Green )) {
                g = (int)( pow( (double)g / 255 , v ) * 255 ) ;
                normalize( g ) ;
            }
            if (( color == Rgb )||( color == Blue )) {
                b = (int)( pow( (double)b / 255 , v ) * 255 ) ;
                normalize( b ) ;
            }

            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}




void Traitement::normalize(int& value )
{
    if ( value > 255 )		value = 255 ;
    else if ( value < 0 )	value = 0 ;
}


// ------------------------------------------------------------------------
// opérations de rotation
// ------------------------------------------------------------------------

void Traitement::rotate(double angle, Interpolation interpolation )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("rotate( %1, %2 )").arg(angle).arg( interpolationAsString(interpolation) ) ;

    double rad = angle * M_PI / 180.0 ;		// angle en radians

    QSize newSize = containerRect(m_srcImg->size(), rad ) ;
    int w = newSize.width() ;
    int h = newSize.height() ;

    //std::cout << w << " x " << h << std::endl ;

    *m_dstImg = m_dstImg->scaled( w, h ) ;
    *m_dstImg = m_dstImg->convertToFormat( QImage::Format_ARGB32_Premultiplied ) ;

    int	xsrc = m_srcImg->width() / 2 ;		// coord. de l'axe de rotation
    int ysrc = m_srcImg->height() / 2 ;		// sur plan image source

    int	xdst = w / 2 ;						// coord. de l'axe de rotation
    int ydst = h / 2 ;						// sur plan image destination

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {

            double xr = ( i - xdst ) * cos ( rad ) - ( ydst - j ) * sin( rad ) ;
            double yr = ( i - xdst ) * sin ( rad ) + ( ydst - j ) * cos( rad ) ;
            xr = xr + xsrc ;
            yr = ysrc - yr ;

            int xi = (int)xr ;
            int yi = (int)yr ;
            double dx = xr - xi ;
            double dy = yr - yi ;

            if ( ( xi < 0 )||( xi >= m_srcImg->width() )||
                 ( yi < 0 )||( yi >= m_srcImg->height() ) ) {
                m_dstImg->setPixel( i, j, qRgba(0,0,0,0) ) ;	// transparent
            }
            else {
                QRgb rgb ;
                switch( interpolation ) {
                case Nearest :	rgb = nearest(dx, dy, xi, yi ) ; break ;
                case Bilinear :	rgb = bilinear(dx, dy, xi, yi ) ; break ;
                default :		rgb = bicubic(dx, dy, xi, yi, interpolation ) ;
                }
                m_dstImg->setPixel(i, j, rgb ) ;
            }
        }
    }
}

// ------------------------------------------------------------------------
// test
// ------------------------------------------------------------------------

QString Traitement::interpolationAsString(Interpolation interpolation )
{
    QString s( this->metaObject()->className() ) ;
    if ( interpolation == Bilinear )			return s + "::Bilinear" ;
    if ( interpolation == MitchellNetravali )	return s + "::MitchellNetravali" ;
    if ( interpolation == CatmullRom )			return s + "::CatmullRom" ;
    if ( interpolation == BSpline )				return s + "::BSpline" ;
    if ( interpolation == Hermite )				return s + "::Hermite" ;
    if ( interpolation == Lanczos )				return s + "::Lanczos" ;
    return s + "::Nearest" ;
}


/*********************************************************************/

QSize Traitement::containerRect(QSize size, double angle )
{
    QSize radius = size / 2 ;
    int xmin = 0, xmax = 0 ;
    int ymin = 0, ymax = 0 ;
    double co = cos(angle) ;
    double si = sin(angle) ;
    int w , h ;

    w = radius.width() * co - radius.height() * si ;
    h = radius.width() * si + radius.height() * co ;
    xmin = qMin( xmin, w ) ; xmax = qMax( xmax, w ) ;
    ymin = qMin( ymin, h ) ; ymax = qMax( ymax, h ) ;

    w = -radius.width() * co - radius.height() * si ;
    h = -radius.width() * si + radius.height() * co ;
    xmin = qMin( xmin, w ) ; xmax = qMax( xmax, w ) ;
    ymin = qMin( ymin, h ) ; ymax = qMax( ymax, h ) ;

    w = radius.width() * co + radius.height() * si ;
    h = radius.width() * si - radius.height() * co ;
    xmin = qMin( xmin, w ) ; xmax = qMax( xmax, w ) ;
    ymin = qMin( ymin, h ) ; ymax = qMax( ymax, h ) ;

    w = -radius.width() * co + radius.height() * si ;
    h = -radius.width() * si - radius.height() * co ;
    xmin = qMin( xmin, w ) ; xmax = qMax( xmax, w ) ;
    ymin = qMin( ymin, h ) ; ymax = qMax( ymax, h ) ;

    return QSize( xmax - xmin, ymax - ymin ) ;
}

/****************************************************************************/

QRgb Traitement::bilinear(double dx, double dy, int xi, int yi )
{
    if ( xi < 0 )	xi = 0 ;
    if ( xi >= m_srcImg->width() - 1 )	xi = m_srcImg->width() - 2 ;
    if ( yi < 0 )	yi = 0 ;
    if ( yi >= m_srcImg->height() - 1 ) yi = m_srcImg->height() - 2 ;

    int r  = ( 1 - dx ) * ( 1 - dy ) * qRed( m_srcImg->pixel(xi, yi ) ) ;
        r += ( 1 - dx ) * dy * qRed( m_srcImg->pixel(xi, yi + 1 ) ) ;
        r += dx * ( 1 - dy ) * qRed( m_srcImg->pixel(xi + 1, yi ) ) ;
        r += dx * dy * qRed( m_srcImg->pixel(xi + 1, yi + 1 ) ) ;
    normalize( r ) ;

    int g  = ( 1 - dx ) * ( 1 - dy ) * qGreen( m_srcImg->pixel(xi, yi ) ) ;
        g += ( 1 - dx ) * dy * qGreen( m_srcImg->pixel(xi, yi + 1 ) ) ;
        g += dx * ( 1 - dy ) * qGreen( m_srcImg->pixel(xi + 1, yi ) ) ;
        g += dx * dy * qGreen( m_srcImg->pixel(xi + 1, yi + 1 ) ) ;
    normalize( g ) ;

    int b  = ( 1 - dx ) * ( 1 - dy ) * qBlue( m_srcImg->pixel(xi, yi ) ) ;
        b += ( 1 - dx ) * dy * qBlue( m_srcImg->pixel(xi, yi + 1 ) ) ;
        b += dx * ( 1 - dy ) * qBlue( m_srcImg->pixel(xi + 1, yi ) ) ;
        b += dx * dy * qBlue( m_srcImg->pixel(xi + 1, yi + 1 ) ) ;
    normalize( b ) ;

    return qRgb(r, g, b ) ;
}

// correction de contraste

void Traitement::contrast(int val, PrimaryColor color )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("contrast( %1 , %2 )").arg(val).arg( primaryColorAsString(color) ) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;

            if (( color == Rgb )||( color == Red )) {
                r = (int)( -val * sin( r * 2 * M_PI / 255 ) + r ) ;
                normalize( r ) ;
            }
            if (( color == Rgb )||( color == Green )) {
                g = (int)( -val * sin( g * 2 * M_PI / 255 ) + g ) ;
                normalize( g ) ;
            }
            if (( color == Rgb )||( color == Blue )) {
                b = (int)( -val * sin( b * 2 * M_PI / 255 ) + b ) ;
                normalize( b ) ;
            }

            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}

// correction de luminosité

void Traitement::brightness(int val , PrimaryColor color )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("brightness( %1 , %2 )").arg(val).arg( primaryColorAsString(color) ) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;

            if (( color == Rgb )||( color == Red )) {
                r += val ;  normalize( r ) ;
            }
            if (( color == Rgb )||( color == Green )) {
                g += val ;  normalize( g ) ;
            }
            if (( color == Rgb )||( color == Blue )) {
                b += val ;  normalize( b ) ;
            }
            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}



/****************************************************************************/

// interpolation 'au plus près'

QRgb Traitement::nearest(double dx, double dy, int xi, int yi )
{
    if ( dx >= 0.5 )	xi++ ;
    if ( dy >= 0.5 )	yi++ ;
    if ( xi < 0 )	xi = 0 ;
    if ( xi >= m_srcImg->width() )		xi = m_srcImg->width() - 1 ;
    if ( yi < 0 )	yi = 0 ;
    if ( yi >= m_srcImg->height() ) 	yi = m_srcImg->height() - 1 ;
    return m_srcImg->pixel(xi, yi ) ;
}

/******************************************************************************/

// interpolation bicubique

QRgb Traitement::bicubic(double dx, double dy, int xi, int yi, Interpolation interpolation )
{
    if ( ( xi < 1 )||( xi > m_srcImg->width() - 2 ) )	return bilinear(dx, dy, xi, yi ) ;
    if ( ( yi < 1 )||( yi > m_srcImg->height() - 2 ) )	return bilinear(dx, dy, xi, yi ) ;

    double v0, v1, v2, v3 ;

    v0 = cubic( dx, qRed( m_srcImg->pixel( xi-1, yi-1 ) ), qRed( m_srcImg->pixel( xi, yi-1 ) ), qRed( m_srcImg->pixel( xi+1, yi-1 ) ), qRed( m_srcImg->pixel( xi+2, yi-1 ) ), interpolation ) ;
    v1 = cubic( dx, qRed( m_srcImg->pixel( xi-1, yi   ) ), qRed( m_srcImg->pixel( xi, yi   ) ), qRed( m_srcImg->pixel( xi+1, yi   ) ), qRed( m_srcImg->pixel( xi+2, yi   ) ), interpolation ) ;
    v2 = cubic( dx, qRed( m_srcImg->pixel( xi-1, yi+1 ) ), qRed( m_srcImg->pixel( xi, yi+1 ) ), qRed( m_srcImg->pixel( xi+1, yi+1 ) ), qRed( m_srcImg->pixel( xi+2, yi+1 ) ), interpolation ) ;
    v3 = cubic( dx, qRed( m_srcImg->pixel( xi-1, yi+2 ) ), qRed( m_srcImg->pixel( xi, yi+2 ) ), qRed( m_srcImg->pixel( xi+1, yi+2 ) ), qRed( m_srcImg->pixel( xi+2, yi+2 ) ), interpolation ) ;
    int r = (int)cubic( dy, v0, v1, v2, v3, interpolation ) ;
    normalize( r ) ;

    v0 = cubic( dx, qGreen( m_srcImg->pixel( xi-1, yi-1 ) ), qGreen( m_srcImg->pixel( xi, yi-1 ) ), qGreen( m_srcImg->pixel( xi+1, yi-1 ) ), qGreen( m_srcImg->pixel( xi+2, yi-1 ) ), interpolation ) ;
    v1 = cubic( dx, qGreen( m_srcImg->pixel( xi-1, yi   ) ), qGreen( m_srcImg->pixel( xi, yi   ) ), qGreen( m_srcImg->pixel( xi+1, yi   ) ), qGreen( m_srcImg->pixel( xi+2, yi   ) ), interpolation ) ;
    v2 = cubic( dx, qGreen( m_srcImg->pixel( xi-1, yi+1 ) ), qGreen( m_srcImg->pixel( xi, yi+1 ) ), qGreen( m_srcImg->pixel( xi+1, yi+1 ) ), qGreen( m_srcImg->pixel( xi+2, yi+1 ) ), interpolation ) ;
    v3 = cubic( dx, qGreen( m_srcImg->pixel( xi-1, yi+2 ) ), qGreen( m_srcImg->pixel( xi, yi+2 ) ), qGreen( m_srcImg->pixel( xi+1, yi+2 ) ), qGreen( m_srcImg->pixel( xi+2, yi+2 ) ), interpolation ) ;
    int g = (int)cubic( dy, v0, v1, v2, v3, interpolation ) ;
    normalize( g ) ;

    v0 = cubic( dx, qBlue( m_srcImg->pixel( xi-1, yi-1 ) ), qBlue( m_srcImg->pixel( xi, yi-1 ) ), qBlue( m_srcImg->pixel( xi+1, yi-1 ) ), qBlue( m_srcImg->pixel( xi+2, yi-1 ) ), interpolation ) ;
    v1 = cubic( dx, qBlue( m_srcImg->pixel( xi-1, yi   ) ), qBlue( m_srcImg->pixel( xi, yi   ) ), qBlue( m_srcImg->pixel( xi+1, yi   ) ), qBlue( m_srcImg->pixel( xi+2, yi   ) ), interpolation ) ;
    v2 = cubic( dx, qBlue( m_srcImg->pixel( xi-1, yi+1 ) ), qBlue( m_srcImg->pixel( xi, yi+1 ) ), qBlue( m_srcImg->pixel( xi+1, yi+1 ) ), qBlue( m_srcImg->pixel( xi+2, yi+1 ) ), interpolation ) ;
    v3 = cubic( dx, qBlue( m_srcImg->pixel( xi-1, yi+2 ) ), qBlue( m_srcImg->pixel( xi, yi+2 ) ), qBlue( m_srcImg->pixel( xi+1, yi+2 ) ), qBlue( m_srcImg->pixel( xi+2, yi+2 ) ), interpolation ) ;
    int b = (int)cubic( dy, v0, v1, v2, v3, interpolation ) ;
    normalize( b ) ;

    return qRgb(r, g, b ) ;
}


/*************************************************************/

// interpolation cubique

double Traitement::cubic(double delta, double v0, double v1, double v2, double v3, Interpolation interpolation )
{
    switch ( interpolation ) {
    case MitchellNetravali :
        return	(((( -7 * v0 + 21 * v1 - 21 * v2 + 7 * v3 )   * delta
                +  ( 15 * v0 - 36 * v1 + 27 * v2 - 6 * v3 ) ) * delta
                +  ( -9 * v0           +  9 * v2          ) ) * delta
                +  (      v0 + 16 * v1 +      v2          ) ) / 18.0 ;
    case CatmullRom :
        return	(((( -1 * v0 +  3 * v1 -  3 * v2 + 1 * v3 )   * delta
                +  (  2 * v0 -  5 * v1 +  4 * v2 - 1 * v3 ) ) * delta
                +  ( -1 * v0           +  1 * v2          ) ) * delta
                +  (            2 * v1                    ) ) / 2.0 ;
    case BSpline :
        return	(((( -1 * v0 +  3 * v1 -  3 * v2 + 1 * v3 )   * delta
                +  (  3 * v0 -  6 * v1 +  3 * v2          ) ) * delta
                +  ( -3 * v0           +  3 * v2          ) ) * delta
                +  (  1 * v0 +  4 * v1 +  1 * v2           ) ) / 6.0 ;
    case Hermite :
        return	((((  2 * v0 -  2 * v1 +  1 * v2 + 1 * v3 )   * delta
                +  ( -3 * v0 +  3 * v1 -  2 * v2 - 1 * v3 ) ) * delta
                +  (                      1 * v2          ) ) * delta
                +  (  1 * v0                              ) ) / 1.0 ;
    case Lanczos :
    default :
        return	  v0 * sinc( delta + 1 ) * sinc( ( delta + 1 ) / 2 )
                + v1 * sinc( delta )     * sinc( ( delta ) / 2 )
                + v2 * sinc( 1 - delta ) * sinc( ( 1 - delta ) / 2 )
                + v3 * sinc( 2 - delta ) * sinc( ( 2 - delta ) / 2 ) ;
    }
}

/*************************************************************************/

// sinus cardinal normalisé

double Traitement::sinc(double x )
{
    if ( x == 0.0 )	return 1 ;
    x *= M_PI ;
    return sin(x) / x ;
}

// négatif (opérateur Not)

void Traitement::negative(PrimaryColor color )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    std::cout << "lol" << std::endl;

    m_lastCall = QString("negative( %1 )").arg( primaryColorAsString(color) ) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;

            if (( color == Rgb )||( color == Red )) {
                r = 255 - r ;  normalize( r ) ;
            }
            if (( color == Rgb )||( color == Green )) {
                g = 255 - g ;  normalize( g ) ;
            }
            if (( color == Rgb )||( color == Blue )) {
                b = 255 - b ;  normalize( b ) ;
            }
            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}

QString Traitement::primaryColorAsString(PrimaryColor color )
{
    QString s( this->metaObject()->className() ) ;

    if ( color == Red )		return s + "::Red" ;
    if ( color == Green )	return s + "::Green" ;
    if ( color == Blue )	return s + "::Blue" ;
    return s + "::Rgb" ;
}

// redimensionnement (interpolation bilinéaire)

void Traitement::size(int w, int h )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("size( %1, %2 )").arg(w).arg(h) ;

    *m_dstImg = m_dstImg->scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation ) ;
}


// changement d'échelle

void Traitement::scale(double xs, double ys, Interpolation interpolation )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("scale( %1, %2, %3 )").arg(xs).arg(ys).arg( interpolationAsString(interpolation) ) ;

    int w = (int)( xs * m_srcImg->width() ) ;
    int h = (int)( ys * m_srcImg->height() ) ;

    *m_dstImg = m_dstImg->scaled( w, h ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            double xr = i / xs ;
            double yr = j / ys ;
            int xi = (int)xr ;
            int yi = (int)yr ;
            double dx = xr - xi ;
            double dy = yr - yi ;
            QRgb rgb ;
            switch( interpolation ) {
            case Nearest :	rgb = nearest(dx, dy, xi, yi ) ; break ;
            case Bilinear :	rgb = bilinear(dx, dy, xi, yi ) ; break ;
            default :		rgb = bicubic(dx, dy, xi, yi, interpolation ) ;
            }
            m_dstImg->setPixel(i, j, rgb ) ;
        }
    }
}

//découpe rectangulaire

void Traitement::cut(int x, int y, int w, int h )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("cut( %1, %2, %3, %4 )").arg(x).arg(y).arg(w).arg(h) ;

    if ( x < 0 )	x = 0 ;
    if ( y < 0 )	y = 0 ;
    if (( w < 0 )||( x + w > m_srcImg->width() ))	w = m_srcImg->width() - x - 1 ;
    if (( h < 0 )||( y + h > m_srcImg->height() ))	h = m_srcImg->height() - y - 1 ;

    *m_dstImg = m_dstImg->scaled( w, h ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            m_dstImg->setPixel(i, j, m_srcImg->pixel(x + i, y + j ) ) ;
        }
    }
}


void Traitement::inversion(int threshold, PrimaryColor color )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    normalize( threshold ) ;
    m_lastCall = QString("inversion( %1 , %2 )").arg(threshold).arg( primaryColorAsString(color) ) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;

            if (( color == Rgb )||( color == Red )) {
                if ( r >= threshold )
                        r = (int)( (double)threshold / ( threshold - 255 ) * ( r - 255 ) ) ;
                else	r = (int)( (double)( threshold - 255 ) / threshold * r + 255 ) ;
                normalize( r ) ;
            }
            if (( color == Rgb )||( color == Green )) {
                if ( g >= threshold )
                        g = (int)( (double)threshold / ( threshold - 255 ) * ( g - 255 ) ) ;
                else	g = (int)( (double)( threshold - 255 ) / threshold * g + 255 ) ;
                normalize( g ) ;
            }
            if (( color == Rgb )||( color == Blue )) {
                if ( b >= threshold )
                        b = (int)( (double)threshold / ( threshold - 255 ) * ( b - 255 ) ) ;
                else	b = (int)( (double)( threshold - 255 ) / threshold * b + 255 ) ;
                normalize( b ) ;
            }

            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}

double Traitement::density( QColor color )
{
    if ( m_dstImg == NULL )	return 0 ;

    int h = m_dstImg->height() ;
    int w = m_dstImg->width() ;
    uint nbPix = 0 ;
    uint n = 0 ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            nbPix++ ;
            if ( m_dstImg->pixel(i, j ) == color.rgba() )	n++ ;
        }
    }
    return 100.0 * ( n / (double)nbPix ) ;
}

quint64 Traitement::grid(int ppline , int margin )
{
    if ( m_dstImg == NULL )	return 0 ;

    if ( ppline < 2 )	ppline = 2 ;	// res. 4 bits
    if ( ppline > 8	)	ppline = 8 ;	// res. 64 bits
    if ( margin < 1 )	margin = 1 ;
    if ( margin > 20 )	margin = 20 ;

    m_lastCall = QString("grid( %1 , %2 )").arg(ppline).arg(margin) ;

    quint64 res = 0 ;
    int numBit = ppline * ppline - 1 ;

    int h = m_dstImg->height() ;
    int w = m_dstImg->width() ;

    int wm = (int)( w * margin / 100.0 ) ;	// marge horizontale (en pixels)
    int hm = (int)( h * margin / 100.0 ) ;	// marge verticale (en pixels)

    int wstep = (int)( (double)( w - 2 * wm ) / ( ppline - 1 ) ) ;
    int hstep = (int)( (double)( h - 2 * hm ) / ( ppline - 1 ) ) ;

    for ( int j = hm ; j <= ( h - hm ) ; j += hstep ) {
        for ( int i = wm ; i <= ( w - wm ) ; i += wstep ) {
            QRgb rgb = m_dstImg->pixel(i, j ) ;
            if ( rgb == QColor(0,0,0).rgba() ) {
                res += (quint64)1 << numBit ;
                marker(m_dstImg, i, j, 255, 0, 0 ) ;
            }
            else {
                marker(m_dstImg, i, j, 0, 0, 255 ) ;
            }
            numBit-- ;
        }
    }

    return res ;
}

void Traitement::marker(QImage* img, int x, int y, int r, int g, int b )
{
    int sz = 2 ;
    for ( int j = y - sz ; j < y + sz ; j++ ) {
        img->setPixel(x - sz, j, qRgb(r, g, b ) ) ;
        img->setPixel(x + sz, j, qRgb(r, g, b ) ) ;
    }
    for ( int i = x - sz ; i < x + sz ; i++ ) {
        img->setPixel(i, y - sz, qRgb(r, g, b ) ) ;
        img->setPixel(i, y + sz, qRgb(r, g, b ) ) ;
    }
}

quint32 Traitement::line(int w1, int h1, int w2, int h2 , int percent )
{
    if ( m_dstImg == NULL )	return 0 ;

    if ( w1 < 0	) w1 = 0 ;	if ( w1 > 100 ) w1 = 100 ;
    if ( h1 < 0	) h1 = 0 ;	if ( h1 > 100 ) h1 = 100 ;
    if ( w2 < 0	) w2 = 0 ;	if ( w2 > 100 ) w2 = 100 ;
    if ( h2 < 0	) h2 = 0 ;	if ( h2 > 100 ) h2 = 100 ;

    m_lastCall = QString("line( %1 , %2 , %3 , %4 , %5 )").arg(w1).arg(h1).arg(w2).arg(h2).arg(percent) ;

    quint32 res = 0 ;
    quint32 flag = (quint32)1 << 31 ;
    int h = m_dstImg->height() ;
    int w = m_dstImg->width() ;

    int x0 = (int)( w * w1 / 100.0 ) ;
    int x1 = (int)( w * w2 / 100.0 ) ;
    int y0 = (int)( h * h1 / 100.0 ) ;
    int y1 = (int)( h * h2 / 100.0 ) ;

    int nprev = 8 ;		// nombre de prélèvements par tronçon
    int n = 0 ;			// compteur de prélèvements
    int sum = 0 ;		// totalisateur pts noirs pour un tronçon

    double taux = (double)percent / 100.0 ;
    double inc = 1.0 / ( nprev * 32 ) ;

    for ( double t = 0.0 ; t <= 1.0 ; t += inc ) {
        int x = (int)( x0 * ( 1 - t ) + x1 * t ) ;
        int y = (int)( y0 * ( 1 - t ) + y1 * t ) ;
        QRgb rgb = m_dstImg->pixel(x, y ) ;
        if ( rgb == QColor(0,0,0).rgba() )	sum++ ;
        n++ ;
        if ( n >= nprev ) {
            n = 0 ;
            if ( (double)sum >= nprev * taux ) {
                res += flag ;
                marker(m_dstImg, x, y, 255, 0, 0 ) ;
            }
            else {
                marker(m_dstImg, x, y, 0, 0, 255 ) ;
            }
            flag >>= 1 ;
            sum = 0 ;
        }
    }

    return res ;
}

// retourne le nombre de bits différents entre 2 grilles

int Traitement::compareGrid(quint64 grid1, quint64 grid2, int ppline )
{
    if ( ppline < 2 )	ppline = 2 ;	// res. 4 bits
    if ( ppline > 8	)	ppline = 8 ;	// res. 64 bits

    int res = 0 ;
    quint64 diff = grid1 ^ grid2 ;
    for ( int i = 0 ; i < ppline * ppline ; ++i ) {
        res += diff & (quint64)1 ;
        diff >>= 1 ;
    }
    return res ;
}


QString Traitement::lineAsString(quint32 line, bool withSeparator )
{
    QString s = "" ;
    int len = sizeof(quint32) * 8 ;
    for ( int i = 0 ; i < len ; ++i ) {
        s = ( line & 1 ? "1" : "0" ) + s ;
        line >>= 1 ;
    }
    if ( withSeparator ) {
        for ( int i = 3 ; i ; --i )	s.insert(i * 8, "." ) ;
    }
    return s ;
}

QString Traitement::gridAsString(quint64 grid, int ppline , bool withSeparator )
{
    if ( ppline < 2 )	ppline = 2 ;	// res. 4 bits
    if ( ppline > 8	)	ppline = 8 ;	// res. 64 bits

    QString s = "" ;
    int len = sizeof(quint64) * 8 ;
    for ( int i = 0 ; i < len ; ++i ) {
        s = ( grid & 1 ? "1" : "0" ) + s ;
        grid >>= 1 ;
    }
    s.remove( 0, len - ppline * ppline ) ;
    if ( withSeparator ) {
        for ( int i = ppline - 1 ; i ; --i )	s.insert(i * ppline, "." ) ;
    }
    return s ;
}

quint64 Traitement::rotateGrid(quint64 grid, int ppline, int angle )
{
    if ( ppline < 2 )	ppline = 2 ;	// res. 4 bits
    if ( ppline > 8	)	ppline = 8 ;	// res. 64 bits
    if ( angle < 1 )	angle = 1 ;
    if ( angle > 3 )	angle = 3 ;

    quint64 res = 0 ;
    int mat[8][8] ;

    // remplissage matrice
    for ( int i = 0 ; i < ppline * ppline ; ++i ) {
        int numBit = ppline * ppline - 1 - i ;
        mat[ i % ppline ][ i / ppline ] = ( grid >> numBit ) & 1 ;
    }

    for ( int a = 0 ; a < angle ; ++a ) {

        // transposition
        for ( int n = 0 ; n <= ppline - 2 ; ++n )
            for ( int m = n + 1 ; m <= ppline - 1 ; ++m ) {
                int tmp = mat[n][m] ;
                mat[n][m] = mat[m][n] ;
                mat[m][n] = tmp ;
        }

        // permutation des colonnes
        for ( int j = 0 ; j < ppline ; ++j )
            for ( int i = 0 ; i < ppline / 2 ; ++i ) {
                int tmp = mat[i][j] ;
                mat[i][j] = mat[ppline-i-1][j] ;
                mat[ppline-i-1][j] = tmp ;
        }
    }

    // lecture matrice --> long mot
    for ( int j = 0 ; j < ppline ; ++j )
        for ( int i = 0 ; i < ppline ; ++i ) {
            res += (quint64)( mat[i][j] ) << ( ppline * ppline - 1 - j * ppline - i ) ;
    }

    return res ;
}

void Traitement::equalization(PrimaryColor color )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    m_lastCall = QString("equalization( %1 )").arg( primaryColorAsString(color) ) ;

    resetSpectrum() ;
    initSpectrum( m_srcImg ) ;

    // histogramme proportionné ( somme égale à 1 pour chaque couleur primaire )

    double spectr_p[256][3] ;
    double size = m_srcImg->width() * m_srcImg->height() ;

    for (int i = 0 ; i < 256 ; i++ ) {
        spectr_p[i][0] = m_spectr[i][0] / size ;
        spectr_p[i][1] = m_spectr[i][1] / size ;
        spectr_p[i][2] = m_spectr[i][2] / size ;
    }

    // histogramme cumulé

    double spectr_c[256][3] ;
    double sum[3] = { 0.0, 0.0, 0.0 } ;

    for (int i = 0 ; i < 256 ; i++ ) {
        sum[0] += spectr_p[i][0] ; spectr_c[i][0] = sum[0] ;
        sum[1] += spectr_p[i][1] ; spectr_c[i][1] = sum[1] ;
        sum[2] += spectr_p[i][2] ; spectr_c[i][2] = sum[2] ;
    }

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;

            if (( color == Rgb )||( color == Red )) {
                r = (int)( 255 * spectr_c[ r ][0] ) ;
                normalize( r ) ;
            }
            if (( color == Rgb )||( color == Green )) {
                g = (int)( 255 * spectr_c[ g ][1] ) ;
                normalize( g ) ;
            }
            if (( color == Rgb )||( color == Blue )) {
                b = (int)( 255 * spectr_c[ b ][2] ) ;
                normalize( b ) ;
            }
            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}

void Traitement::resetSpectrum()
{
    for ( int i = 0 ; i < 256 ; ++i ) {
        m_spectr[i][0] = 0 ;
        m_spectr[i][1] = 0 ;
        m_spectr[i][2] = 0 ;
    }
}

void Traitement::initSpectrum(QImage* img )
{
    for (int j = 0 ; j < img->height() ; j++ ) {
        for ( int i = 0 ; i < img->width() ; i++ ) {
            QRgb rgb = img->pixel(i, j ) ;
            m_spectr[ qRed( rgb ) ][0] += 1 ;
            m_spectr[ qGreen( rgb ) ][1] += 1 ;
            m_spectr[ qBlue( rgb ) ][2] += 1 ;
        }
    }
}

void Traitement::expansion(int val, PrimaryColor color )
{
    if ( m_srcImg == NULL || m_dstImg == NULL )	return ;

    if ( val < 0 )		val = 0 ;
    if ( val > 100 )	val = 100 ;
    m_lastCall = QString("expansion( %1 , %2 )").arg(val).arg( primaryColorAsString(color) ) ;

    resetSpectrum() ;
    initSpectrum( m_srcImg ) ;

    int lowR  = lowSpectrumThreshold(m_srcImg, val, Red ) ;
    int highR = highSpectrumThreshold(m_srcImg, val, Red ) ;
    int lowG  = lowSpectrumThreshold(m_srcImg, val, Green ) ;
    int highG = highSpectrumThreshold(m_srcImg, val, Green ) ;
    int lowB  = lowSpectrumThreshold(m_srcImg, val, Blue ) ;
    int highB = highSpectrumThreshold(m_srcImg, val, Blue ) ;

    int h = qMin( m_srcImg->height(), m_dstImg->height() ) ;
    int w = qMin( m_srcImg->width(), m_dstImg->width() ) ;

    for ( int j = 0 ; j < h ; j++ ) {
        for ( int i = 0 ; i < w ; i++ ) {
            QRgb rgb = m_srcImg->pixel(i, j ) ;
            int r = qRed( rgb ) ;
            int g = qGreen( rgb ) ;
            int b = qBlue( rgb ) ;

            if (( color == Rgb )||( color == Red )) {
                r = (int)( 255 * (double)( r - lowR ) / ( highR - lowR ) ) ;
                normalize( r ) ;
            }
            if (( color == Rgb )||( color == Green )) {
                g = (int)( 255 * (double)( g - lowG ) / ( highG - lowG ) ) ;
                normalize( g ) ;
            }
            if (( color == Rgb )||( color == Blue )) {
                b = (int)( 255 * (double)( b - lowB ) / ( highB - lowB ) ) ;
                normalize( b ) ;
            }
            m_dstImg->setPixel(i, j, qRgb(r, g, b ) ) ;
        }
    }
}


int Traitement::lowSpectrumThreshold(QImage* img, int percent, PrimaryColor color )
{
    uint nbPix = img->width() * img->height() ;
    int  value = (int)( percent * nbPix / 100.0 ) ;
    int  sum = 0 ;
    int  i = 0 ;

    for ( ; i < 256 ; ++i ) {
        if ( color == Red )		sum += m_spectr[i][0] ;
        if ( color == Green )	sum += m_spectr[i][1] ;
        if ( color == Blue )	sum += m_spectr[i][2] ;
        if ( sum > value ) break ;
    }
    return i ;
}

int Traitement::highSpectrumThreshold(QImage* img, int percent, PrimaryColor color )
{
    uint nbPix = img->width() * img->height() ;
    int  value = (int)( percent * nbPix / 100.0 ) ;
    int  sum = 0 ;
    int  i = 255 ;

    for ( ; i >= 0 ; --i ) {
        if ( color == Red )		sum += m_spectr[i][0] ;
        if ( color == Green )	sum += m_spectr[i][1] ;
        if ( color == Blue )	sum += m_spectr[i][2] ;
        if ( sum > value ) break ;
    }
    return i ;
}

