/* ----------------------------------------------------------------------------
 |	Nom :			qamcellflexpuzzle.cpp
 |	Projet :		Cellflex - LLF Scara
 |	Sujet :     	Widget puzzle logo LLF
 |  Auteur :		Alain Menu
 |	Version :		1.0
 |	Création :		mars 2014
 |	Mise à jour :	27/03/2014
 |	Fabrication :	Qt4 / Qt5 OpenSource (Desktop)
 + ------------------------------------------------------------------------- */
/*
 |	Copyright (c) 2014 by Alain Menu <alain.menu@ac-creteil.fr>
 |
 |  This file is part of "Qam LLF Scara project"
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

#include "qamcellflexpuzzle.h"

// constructeur

QamCellflexPuzzle::QamCellflexPuzzle(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize( PIECE_MIN_SIZE * ( PUZZLE_COLS + 1 ), PIECE_MIN_SIZE * ( PUZZLE_ROWS + 1 ) ) ;

    QFont   font = this->font() ;
    font.setPointSize( 12 ) ;
    font.setBold( true ) ;
    this->setFont( font ) ;

    fill( false ) ;
}

// supprime toutes les pièces

void QamCellflexPuzzle::fill(bool busy )
{
    for ( int i = 0 ; i < PUZZLE_COLS * PUZZLE_ROWS ; ++i ) {
        m_puzzle[ i %  PUZZLE_COLS ][ i / PUZZLE_COLS ] = ( busy ? 0 : -1 ) ;
    }
    this->update() ;
}

// ajoute la pièce d'indice num

void QamCellflexPuzzle::addPiece(int num )
{
    if (( num < 0 )||( num >= (PUZZLE_COLS * PUZZLE_ROWS) ))    return ;
    m_puzzle[ num %  PUZZLE_COLS ][ num / PUZZLE_COLS ] = 0 ;
    this->update() ;
}

// retire la pièce d'indice num

void QamCellflexPuzzle::removePiece(int num )
{
    if (( num < 0 )||( num >= (PUZZLE_COLS * PUZZLE_ROWS) ))    return ;
    m_puzzle[ num %  PUZZLE_COLS ][ num / PUZZLE_COLS ] = -1 ;
    this->update() ;
}

// indique si l'emplacement num est libre

bool QamCellflexPuzzle::isPositionFree(int num ) const
{
    if (( num < 0 )||( num >= (PUZZLE_COLS * PUZZLE_ROWS) ))    return false ;
    return ( m_puzzle[ num %  PUZZLE_COLS ][ num / PUZZLE_COLS ] == -1 ) ;

}

// indique si le puzzle est vide

bool QamCellflexPuzzle::isEmpty() const
{
    for ( int i = 0 ; i < PUZZLE_COLS * PUZZLE_ROWS ; ++i ) {
        if ( m_puzzle[ i %  PUZZLE_COLS ][ i / PUZZLE_COLS ] != -1 )    return false ;
    }
    return true ;
}

// indique si le puzzle est plein

bool QamCellflexPuzzle::isCompleted() const
{
    for ( int i = 0 ; i < PUZZLE_COLS * PUZZLE_ROWS ; ++i ) {
        if ( m_puzzle[ i %  PUZZLE_COLS ][ i / PUZZLE_COLS ] == -1 )    return false ;
    }
    return true ;
}

// prochaine position libre/occupée à partir de l'indice num inclus
// recherche circulaire, retourne -1 si respectivement plein/vide ou num invalide

int  QamCellflexPuzzle::nextFreePositionFrom(int num ) const
{
    if ( isCompleted() )    return -1 ;
    if (( num < 0 )||( num >= (PUZZLE_COLS * PUZZLE_ROWS) ))    return -1 ;

    for ( int i = num ; i < PUZZLE_COLS * PUZZLE_ROWS ; ++i ) {
        if ( m_puzzle[ i %  PUZZLE_COLS ][ i / PUZZLE_COLS ] == -1 )    return i ;
    }
    for ( int i = 0 ; i < num ; ++i ) {
        if ( m_puzzle[ i %  PUZZLE_COLS ][ i / PUZZLE_COLS ] == -1 )    return i ;
    }
    return -1 ;
}

int  QamCellflexPuzzle::nextBusyPositionFrom(int num ) const
{
    if ( isEmpty() )    return -1 ;
    if (( num < 0 )||( num >= (PUZZLE_COLS * PUZZLE_ROWS) ))    return -1 ;

    for ( int i = num ; i < PUZZLE_COLS * PUZZLE_ROWS ; ++i ) {
        if ( m_puzzle[ i %  PUZZLE_COLS ][ i / PUZZLE_COLS ] != -1 )    return i ;
    }
    for ( int i = 0 ; i < num ; ++i ) {
        if ( m_puzzle[ i %  PUZZLE_COLS ][ i / PUZZLE_COLS ] != -1 )    return i ;
    }
    return -1 ;
}

// rectangle d'inscription de la pièce d'indice num p/r origine widget

QRect QamCellflexPuzzle::pieceRect(int num )
{
    if (( num < 0 )||( num >= (PUZZLE_COLS * PUZZLE_ROWS) ))    return QRect() ;

    int s = this->width() / (float)( PUZZLE_COLS + 1 ) ;
    int indl = num / PUZZLE_COLS ;
    int indc = num % PUZZLE_COLS ;
    return QRect(s * (indc + 1), s * (indl + 1), s, s ) ;
}

// dessin du puzzle

void QamCellflexPuzzle::paintEvent(QPaintEvent* pe )
{
    Q_UNUSED( pe ) ;

    QPainter	paint(this) ;

    paint.save() ;
    paint.setRenderHint(QPainter::Antialiasing ) ;

    // conservation de la proportion largeur/hauteur
    int w = this->width() / (float)( PUZZLE_COLS + 1 ) ;
    int h = this->height() / (float)( PUZZLE_ROWS + 1 ) ;
    int s = qMin(w, h ) ;
    this->resize( s * ( PUZZLE_COLS + 1 ) + 1, s * ( PUZZLE_ROWS + 1 ) + 1 ) ;

    // fond gris
    paint.fillRect(s - 1,s - 1,s * PUZZLE_COLS + 2, s * PUZZLE_ROWS + 2, QBrush( QColor(192, 192, 192 ) ) ) ;

    // abscisse A, B, C, ...
    for ( int i = 1 ; i < ( PUZZLE_COLS + 1 ) ; ++i ) {
        paint.drawText(s * i, 0, s, s, Qt::AlignHCenter | Qt::AlignVCenter, QString("%1").arg( QChar('A' + i - 1 ) ) ) ;
    }
    // ordonnée 1, 2, 3, ...
    for ( int i = 1 ; i < ( PUZZLE_ROWS + 1 ) ; ++i ) {
        paint.drawText(0, s * i, s, s, Qt::AlignHCenter | Qt::AlignVCenter, QString("%1").arg(i) ) ;
    }

    // vignettes des pièces
    for ( int i = 0 ; i < PUZZLE_COLS * PUZZLE_ROWS ; ++i ) {
        int indl = i / PUZZLE_COLS ;    // indice ligne
        int indc = i % PUZZLE_COLS ;    // indice colonne
        if ( m_puzzle[ indc ][ indl ] == -1 )   continue ;
        QRect   rect(s * (indc + 1), s * (indl + 1), s, s ) ;
        QString imgName = QString(":/puzzle/images/%1%2.png").arg( QChar( 'A' + indc ) ).arg( indl + 1 ) ;
        paint.drawImage(rect, QImage( imgName ) ) ;
    }

    paint.restore() ;
}
