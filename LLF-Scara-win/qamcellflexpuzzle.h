/* ----------------------------------------------------------------------------
 |	Nom :			qamcellflexpuzzle.h
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

// This class modelizes a LLF puzzle as graphical widget
// used resources : A1.png .. E4.png (152x152 pixels images)

// Puzzle geometry

//         A     B     C     D     E
//      +-----+-----+-----+-----+-----+
//   1  |  0  |  1  |  2  |  3  |  4  |
//      +-----+-----+-----+-----+-----+
//   2  |  5  |  6  |  7  |  8  |  9  |
//      +-----+-----+-----+-----+-----+                      0
//   3  | 10  | 11  | 12  | 13  | 14  |                      |
//      +-----+-----+-----+-----+-----+    orientation : 1 --+-- 3
//   4  | 15  | 16  | 17  | 18  | 19  |                      |
//      +-----+-----+-----+-----+-----+                      2

#ifndef QAMCELLFLEXPUZZLE_H
#define QAMCELLFLEXPUZZLE_H

#include <QWidget>
#include <QPainter>
#include <QRect>

#define PIECE_MIN_SIZE  20      // side in pixels
#define PUZZLE_COLS     5
#define PUZZLE_ROWS     4

class QamCellflexPuzzle : public QWidget
{
    Q_OBJECT

  public:
    explicit QamCellflexPuzzle(QWidget* parent = 0 ) ;

    void fill(bool busy = true ) ;
    void addPiece(int num ) ;
    void removePiece(int num ) ;
    bool isPositionFree(int num ) const ;
    bool isEmpty() const ;
    bool isCompleted() const ;
    int  nextFreePositionFrom(int num ) const ;
    int  nextBusyPositionFrom(int num ) const ;
    QRect pieceRect(int num ) ;

  protected:
    void paintEvent(QPaintEvent* pe ) ;

  private:
    int m_puzzle[PUZZLE_COLS][PUZZLE_ROWS] ;    // -1: free, 0: busy
} ;

#endif // QAMCELLFLEXPUZZLE_H
