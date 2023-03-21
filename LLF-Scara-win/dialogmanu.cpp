/* ----------------------------------------------------------------------------
 |	Nom :			dialogmanu.cpp
 |	Projet :		Cellflex - LLF Scara
 |	Sujet :     	main UI implementation
 |  Auteur :		Alain Menu
 |	Version :		1.0
 |	Création :		mars 2014
 |	Mise à jour :	03/04/2014
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

#include "dialog.h"

// ---------------------------------------------------------------------------
// pilotage du robot
// ---------------------------------------------------------------------------

void Dialog::on_pbuOpen_clicked()
{
    if ( !m_scara->open() ) return ;

    pbuOpen->setEnabled( false ) ;
    pbuHome->setEnabled( true ) ;
    pbuReset->setEnabled( true ) ;
    pbuState->setEnabled( true ) ;
    pbuHalt->setEnabled( true ) ;
}

void Dialog::on_pbuReset_clicked()
{
    getSelectedAxis() ;
//	info("RESET", "In progress for all selected axis..." ) ;
    for ( int i = 0 ; i < SCARA_NUMID ; ++i ) {
        if ( m_selected[i] )   m_scara->reset( (QamScara::Axis)i ) ;
    }
//  info("RESET", "Completed" ) ;
}

void Dialog::on_pbuHome_clicked()
{
    getSelectedAxis() ;
//	info("HOME", "In progress for all selected axis..." ) ;
    for ( int i = 0 ; i < SCARA_NUMID ; ++i ) {
        if ( m_selected[i] )   m_scara->home( (QamScara::Axis)i ) ;

    }
//  info("HOME", "Completed" ) ;
}

void Dialog::on_pbuHalt_clicked()
{
    m_scara->halt() ;
}

void Dialog::on_pbuState_clicked()
{
    getSelectedAxis() ;
    for ( int i = 0 ; i < SCARA_NUMID ; ++i ) {
        if ( !m_selected[i] )   continue ;
        QString state = m_scara->state( (QamScara::Axis)i ) ;
        info("STATE", m_axisName.at(i) + "\n" + state ) ;
    }
}

// interception des info. de changement de position des axes

void Dialog::positionChanged(int axis, float pos )
{
    if ( axis == QamScara::ZAxis ) {
        edtZaxis->setText( floatAsString( pos * 1000.0, 2 ) ) ;
        edtZaxis->repaint() ;
        edtTcpZ->setText( floatAsString( pos * 1000.0, 2 ) ) ;
        edtTcpZ->repaint() ;

        // TODO : contrôler enabled de pbuTcpDown ?
    }
    if ( axis == QamScara::Shoulder ) {
        edtShoulder->setText( floatAsString( radToDeg(pos), 2 ) ) ;
        edtShoulder->repaint() ;
    }
    if ( axis == QamScara::Elbow ) {
        edtElbow->setText( floatAsString( radToDeg(pos), 2 ) ) ;
        edtElbow->repaint() ;
    }
    if ( axis == QamScara::Wrist ) {
        edtWrist->setText( floatAsString( radToDeg(pos), 2 ) ) ;
        edtWrist->repaint() ;

        // TODO : contrôler enabled de pbuWristCCW et pbuWristCW ?
    }
    if ( axis == QamScara::Gripper ) {
        edtGripper->setText( floatAsString( pos * 1000.0, 2 ) ) ;
        edtGripper->repaint() ;
    }
}

void Dialog::tcpCartesianPositionChanged(QPointF pos )
{
    edtXaxis->setText( floatAsString( pos.x(), 2 ) ) ;
    edtXaxis->repaint() ;
    edtYaxis->setText( floatAsString( pos.y(), 2 ) ) ;
    edtYaxis->repaint() ;

    edtTcpX->setText( floatAsString( pos.x(), 2 ) ) ;
    edtTcpX->repaint() ;
    edtTcpY->setText( floatAsString( pos.y(), 2 ) ) ;
    edtTcpY->repaint() ;
}

// ---------------------------------------------------------------------------

// ouverture/fermeture de la pince (mouvements absolus)

bool Dialog::openGripper()
{
    return moveAxis(QamScara::Gripper, ( m_gripperOpen - m_gripperOffs ) / 1000.0, false ) ;
}

bool Dialog::closeGripper()
{
    return moveAxis(QamScara::Gripper, ( m_gripperClose - m_gripperOffs ) / 1000.0, false ) ;
}

// échappement vertical de la pince

bool Dialog::goUp()
{
    return moveAxis(QamScara::ZAxis,  m_zEscape / 1000.0 ) ;
}

bool Dialog::goDown()
{
    return moveAxis(QamScara::ZAxis, -m_zEscape / 1000.0 ) ;
}

// déplacement absolu vers un waypoint avec rotation de la main

bool Dialog::gotoPoint(const QString& pointName, float gripperOrientation )
{
    float x, y, z, rz ;
    bool  okx, oky, okz, okr ;

    x  = waypointByName(pointName, 1 ).toFloat(&okx) ;      // mm
    y  = waypointByName(pointName, 2 ).toFloat(&oky) ;      // mm
    z  = waypointByName(pointName, 3 ).toFloat(&okz) ;      // mm
    rz = waypointByName(pointName, 4 ).toFloat(&okr) ;      // deg

    if ( ( okx && oky && okz && okr ) == false ) {
        error("GOTO", QString("Point %1, invalid float coordinate!").arg(pointName) ) ;
        return false ;
    }
    if ( x * y * z == 0.0 ) {
        error("GOTO", QString("Missing or nul point %1!").arg(pointName) ) ;
        return false ;
    }

    z  += m_zEscape ;
    rz += gripperOrientation ;

    m_scara->setVelocity(QamScara::Tcp, getVel( QamScara::Tcp ) ) ;

    info("GOTO", QString("Point %1").arg(pointName) ) ;

    return m_scara->moveAbs( x, y, z, rz ) ;      // mm / deg
}

// ---------------------------------------------------------------------------

// go to user defined absolute position X, Y, Z
// or waypoint X, Y, Z (escaped) with RZ compensation

void Dialog::on_pbuGoto_clicked()
{
    float x, y, z, rz = 0.0 ;
    bool  okx, oky, okz, okr = true ;

    if ( rbuGotoCoord->isChecked() ) {
        x = edtTcpX->text().toFloat(&okx ) ;
        y = edtTcpY->text().toFloat(&oky ) ;
        z = edtTcpZ->text().toFloat(&okz ) ;
    }
    else {
        QList<QTableWidgetItem*> selection = tblPoints->selectedItems() ;
        if ( !selection.isEmpty() ) {
            x = selection.at(1)->text().toFloat(&okx ) ;
            y = selection.at(2)->text().toFloat(&oky ) ;
            z = selection.at(3)->text().toFloat(&okz ) ;
            rz = selection.at(4)->text().toFloat(&okr ) ;
            z += m_zEscape ;
        }
        else {
            error("GOTO", "No selected point!" ) ;
            return ;
        }
    }

    if ( ( okx && oky && okz && okr ) == false ) {
        error("GOTO", "Invalid float coordinate!" ) ;
        return ;
    }

    info("GOTO", QString("TCP moving to ( %1 , %2 , %3 )...").arg( floatAsString(x) ).arg( floatAsString(y) ).arg( floatAsString(z) ) ) ;

    m_scara->setVelocity(QamScara::Tcp, getVel( QamScara::Tcp ) ) ;

    m_scara->moveAbs( x, y, z, rz ) ;      // mm / deg
}

// current user moving step in millimeters or degrees

float Dialog::getStep()
{
    float	step = 0.1 ;
    if ( rbuStep05->isChecked() )		step = 0.5 ;
    else if ( rbuStep1->isChecked() )	step = 1.0 ;
    else if ( rbuStep5->isChecked() )	step = 5.0 ;
    else if ( rbuStep10->isChecked() )	step = 10.0 ;
    return step ;
}

// [de]select all axis

void Dialog::selectAllAxis(bool select )
{
    chkZaxis->setChecked(select ) ;
    chkShoulder->setChecked(select ) ;
    chkElbow->setChecked(select ) ;
    chkWrist->setChecked(select ) ;
    chkGripper->setChecked(select ) ;
}

// get current axis selection for home or reset

void Dialog::getSelectedAxis()
{
    m_selected[ QamScara::Tcp ] = false ;
    m_selected[ QamScara::ZAxis ] = chkZaxis->isChecked() ;
    m_selected[ QamScara::Shoulder ] = chkShoulder->isChecked() ;
    m_selected[ QamScara::Elbow ] = chkElbow->isChecked() ;
    m_selected[ QamScara::Wrist ] = chkWrist->isChecked() ;
    m_selected[ QamScara::Gripper ] = chkGripper->isChecked() ;
}

// get scara axis and TCP current position

float Dialog::getCurrentPos(QamScara::Axis axis )
{
    float value = m_scara->currentPosition(axis) ;
    positionChanged(axis, value ) ;

    tcpCartesianPositionChanged( m_scara->currentTcpCartesianPosition() ) ;

    return value ;
}

// single axis absolute or relative movement in meters or radians

bool Dialog::moveAxis(QamScara::Axis axis, float offset, bool relative )
{
    m_scara->setVelocity(axis, getVel(axis) ) ;
    m_scara->setAcceleration(axis, getAcc(axis) ) ;

    if ( relative ) return m_scara->moveRel(axis, offset ) ;

    return m_scara->moveAbs(axis, offset ) ;
}

// cartesian XY relative movement in millimeters

bool Dialog::moveTcp(float offsetX, float offsetY )
{
    m_scara->setVelocity(QamScara::Tcp, getVel( QamScara::Tcp ) ) ;
    return m_scara->moveRel(offsetX, offsetY ) ;
}

QString Dialog::floatAsString(float value, int precision )
{
    return QString("%1").arg( value, 0, 'f', precision ) ;
}

// information messages

void Dialog::info(const QString& source, const QString& message )
{
    showPrompt( edtScaraInfo, source.leftJustified( 6, ' ', true) + ": ") ;
    showMessage( edtScaraInfo, message + "\n", false, Qt::darkGray  ) ;
}

void Dialog::error(const QString& source, const QString& message )
{
    showPrompt( edtScaraInfo, source.leftJustified( 6, ' ', true ) + ": ") ;
    showMessage( edtScaraInfo, message + "\n", false, Qt::darkRed  ) ;
}

