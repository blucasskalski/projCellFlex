/* ----------------------------------------------------------------------------
 |	Nom :			qamscara.cpp
 |	Projet :		Cellflex - LLF Scara
 |	Sujet :     	LLF Scara steering
 |  Auteur :		Alain Menu
 |	Version :		1.0
 |	Création :		mars 2014
 |	Mise à jour :	04/04/2014
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

#include "qamscara.h"

QamScara::QamScara(QObject* parent )
    : QObject(parent)
    , m_device( -1 )
    , m_initString( CAN_INIT_STR )
{
    m_CCW[ Tcp ] = 1 ;
    m_CCW[ ZAxis ] = SCARA_ZAXIS_CCW ;
    m_CCW[ Shoulder ] = SCARA_SHOULDER_CCW ;
    m_CCW[ Elbow ] = SCARA_ELBOW_CCW ;
    m_CCW[ Wrist ] = SCARA_WRIST_CCW ;
    m_CCW[ Gripper ] = SCARA_GRIPPER_CCW ;

    m_isLinearAxis[ Tcp ] = true ;
    m_isLinearAxis[ ZAxis ] = true ;
    m_isLinearAxis[ Shoulder ] = false ;
    m_isLinearAxis[ Elbow ] = false ;
    m_isLinearAxis[ Wrist ] = false ;
    m_isLinearAxis[ Gripper ] = true ;

    for ( int i = 0 ; i < SCARA_NUMID ; ++i ) {
        m_velocity[i] = 0.1 ;
        m_acceleration[i] = 0.05 ;
    }
    m_lastCartesianPosition = QPointF( 0, 0 ) ;

    m_maxVel[ Tcp ] = 0.5 ;
}

bool QamScara::open()
{
    emit info("SCARA", "Opening device..." ) ;
    if ( PCube_openDevice( &m_device, m_initString.toLatin1().data() ) != 0 ) {
        emit error("SCARA", "PCube_openDevice() failed" ) ;
        return false ;
    }

    emit info("SCARA", "Getting default limits for velocity, acceleration and position..." ) ;
    for ( int i = ZAxis ; i <= Gripper ; ++i ) {
        PCube_getMaxVel(m_device, i, m_maxVel + i ) ;
        PCube_getMaxAcc(m_device, i, m_maxAcc + i ) ;
        PCube_getMinPos(m_device, i, m_minPos + i ) ;
        PCube_getMaxPos(m_device, i, m_maxPos + i ) ;
    }

    // TODO : setting context limits for position...
//    m_minPos[ Elbow ] = degToRad( -90 ) ;
//    m_maxPos[ Elbow ] = degToRad(  90 ) ;

    emit info("SCARA", "System ready!" ) ;
    return true ;
}

void QamScara::close()
{
    emit info("SCARA", "Closing device..." ) ;
    PCube_closeDevice(m_device ) ;
}

bool QamScara::reset(Axis axis )
{
    emit info("SCARA", QString("Resetting module id %1").arg(axis) ) ;
    if ( PCube_resetModule(m_device, axis ) != 0 ) {
        emit error("SCARA", QString("Reset failed for module id %1").arg(axis) ) ;
        return false ;
    }
    return true ;
}

bool QamScara::home(Axis axis )
{
    emit info("SCARA", QString("Module id %1 is going home...").arg(axis) ) ;
    if ( PCube_homeModule(m_device, axis ) != 0 ) {
        error("SCARA", QString("Home failed for module id %1").arg(axis) ) ;
        return false ;
    }
    bool ended = false ;
    unsigned long state ;
    while ( !ended ) {
        PCube_getModuleState(m_device, axis, &state ) ;
        if (( state & STATEID_MOD_RAMP_END )&&( state & STATEID_MOD_HOME ))	ended = true ;
//
        m_lastPosition[axis] = currentPosition( axis ) ;    // m | rad
        emit positionChanged(axis, m_lastPosition[axis] ) ;

        if (( axis == Shoulder )||( axis == Elbow ) ) {
            emit tcpCartesianPositionChanged( currentTcpCartesianPosition() ) ;
        }

        QCoreApplication::processEvents() ;
//
    }

    return moveAbs(axis, axis == Gripper ? 0.04 : 0.0 ) ;   // home correction
}

void QamScara::halt()   //halt= arret
{
    PCube_haltAll(m_device ) ;
    PCube_resetAll(m_device ) ;
    emit info("SCARA", "System halted!") ;
}

// visualisation "Ascii-Art" du mot d'état d'un axe

QString QamScara::state(Axis axis )
{
    unsigned long res = 0 ;
    PCube_getModuleState(m_device, axis, &res ) ;
    QString s = SCARA_STATE ;
    for ( int i = 0 ; i < 32 ; ++i ) {
        int pos = s.size() - i - 1 ;
        if ( s.at( pos ) != '-' )  s[ pos ] = ( res & 1 ? '1' : '0' ) ;
        res >>= 1 ;
    }
    s = SCARA_STATE_HEADER + s + "\n" + SCARA_STATE_FOOTER ;
    s.replace("\n", "\n    " ) ;
    s = s + "\n" ;
    return s ;
}

// axis velocity with value in meters/s or rad/s

void QamScara::setVelocity(Axis axis, float value )
{
    if (( value <= 0.0 )||( value > m_maxVel[axis] )) {
        emit error("SCARA", QString("Axis %1 velocity out of range").arg(axis) ) ;
        return ;
    }
    m_velocity[axis] = value ;
}

float QamScara::velocity(Axis axis ) const
{
    return m_velocity[axis] ;
}

// axis acceleration with value in meters/s2 or rad/s2

void QamScara::setAcceleration(Axis axis, float value )
{
    if (( value < 0.0 )||( value > m_maxAcc[axis] )) {
        emit error("SCARA", QString("Axis %1 acceleration out of range").arg(axis) ) ;
        return ;
    }
    m_acceleration[axis] = value ;
}

float QamScara::acceleration(Axis axis ) const
{
    return m_acceleration[axis] ;
}

// current axis position (meters or radians)

float QamScara::currentPosition(Axis axis ) const
{
    float value ;
    PCube_getPos(m_device, axis, &value ) ;
    return value * m_CCW[ axis ] ;                  // m | rad
}

// current Tool Center Point XY position (millimeters)

QPointF QamScara::currentTcpCartesianPosition()
{
    float q1 = currentPosition( Shoulder ) ;        // rad
    float q2 = currentPosition( Elbow ) ;           // rad

    float x = SCARA_L1 * qCos( q1 ) + SCARA_L2 * qCos( q1 + q2 ) ;
    float y = SCARA_L1 * qSin( q1 ) + SCARA_L2 * qSin( q1 + q2 ) ;

    m_lastPosition[ Shoulder ] = q1 ;               // rad
    m_lastPosition[ Elbow ] = q2 ;                  // rad
    m_lastCartesianPosition.setX( (qreal)x ) ;      // mm
    m_lastCartesianPosition.setY( (qreal)y ) ;      // mm

    return m_lastCartesianPosition ;
}

// relative axis movement with value in meters or radians

bool QamScara::moveRel(Axis axis, float value )
{
//    emit info("AXIS", QString("%1, current %2").arg(axis).arg(currentPosition(axis)) ) ;
//    emit info("AXIS", QString("%1, value   %2").arg(axis).arg(value) ) ;

    return moveAbs(axis, currentPosition(axis) + value ) ;
}

// absolute axis target position with value in meters or radians

bool QamScara::moveAbs(Axis axis, float value )
{
// interdire tout mouvement plus petit que (la moitié de) l'incrément min (0.1 mm/deg) ...
    float threshold = ( m_isLinearAxis[axis] ? ( 0.05 / 1000.0 ) : degToRad(0.05) ) ;
    if ( qAbs( value - currentPosition(axis) ) < threshold )   return true ;
//
    value *=  m_CCW[axis] ;     // CCW correction

    if (( value < m_minPos[axis] )||( value > m_maxPos[axis] )) {
        emit error("SCARA", "Target position out of range" ) ;
        return false ;
    }
    if ( PCube_moveRamp(m_device, axis, value, m_velocity[axis], m_acceleration[axis] ) != 0 ) {
        emit error("SCARA", QString("Move failed for module id %1").arg(axis) ) ;
        return false ;
    }
    bool ended = false ;
    unsigned long state ;
    while ( !ended ) {
        PCube_getModuleState(m_device, axis, &state ) ;
        if ( state & STATEID_MOD_RAMP_END )	ended = true ;

        m_lastPosition[axis] = currentPosition( axis ) ;    // m | rad
        emit positionChanged(axis, m_lastPosition[axis] ) ;

        if (( axis == Shoulder )||( axis == Elbow ) ) {
            emit tcpCartesianPositionChanged( currentTcpCartesianPosition() ) ;
        }

        QCoreApplication::processEvents() ;
    }
    return true ;
}

// relative Tool Center Point cartesian movement with values in millimeters or degrees

bool QamScara::moveRel(float x, float y, float z, float rz )
{
    currentTcpCartesianPosition() ;
    x += m_lastCartesianPosition.x() ;          // mm
    y += m_lastCartesianPosition.y() ;          // mm
    z += currentPosition( ZAxis ) * 1000.0 ;    // mm
    return moveAbs(x, y, z, rz ) ;
}

// absolute Tool Center Point target position with values in millimeters or degrees

bool QamScara::moveAbs(float x, float y, float z, float rz )
{
    bool withZAxis = ( z != 0.0 ) ;

    float term1 = x * x + y * y - ( SCARA_L1 * SCARA_L1 + SCARA_L2 * SCARA_L2 ) ;
    float term2 = 2 * SCARA_L1 * SCARA_L2 ;
    float target = term1 / term2 ;

    if (( target < -1 )||( target > 1 )) {
        emit error("SCARA", "Unreachable coordinates" ) ;
        return false ;
    }

    float q2 = qAcos( target ) ;
    float term3 = SCARA_L1 + SCARA_L2 * qCos( q2 ) ;
    float term4 = SCARA_L2 * qSin( q2 ) ;
    float q1 = qAtan( ( y * term3 - x * term4 ) / ( x * term3 + y * term4 ) ) ;

    float q3 = -( q1 + q2 ) ;   // wrist compensation
    q3 += degToRad( rz ) ;      // wrist rotation

//    emit info("SCARA", QString("Target : Shoulder %1, Elbow %2, Wrist %3").arg(radToDeg(q1)).arg(radToDeg(q2)).arg(radToDeg(q3)) ) ;

    // CCW correction

    q1 *= m_CCW[ Shoulder ] ;   // rad
    q2 *= m_CCW[ Elbow ] ;      // rad
    q3 *= m_CCW[ Wrist ] ;      // rad

    bool ok = true ;
    if (( q1 < m_minPos[Shoulder] )||( q1 > m_maxPos[Shoulder] )) {
        emit error("SCARA", "Shoulder target position out of range!" ) ;
        ok = false ;
    }
    if (( q2 < m_minPos[Elbow] )||( q2 > m_maxPos[Elbow] )) {
        emit error("SCARA", "Elbow target position out of range!" ) ;
        ok = false ;
    }
    if (( q3 < m_minPos[Wrist] )||( q3 > m_maxPos[Wrist] )) {
        emit error("SCARA", "Wrist target position out of range!" ) ;
        ok = false ;
    }
    if ( !ok ) return false ;

    // simultaneous movements

    float dx = qAbs( x - m_lastCartesianPosition.x() ) ;            // mm
    float dy = qAbs( y - m_lastCartesianPosition.y() ) ;            // mm
    float dz = 0.0 ;

    if ( withZAxis )
        dz = qAbs( z - currentPosition(ZAxis) * 1000.0 ) ;          // mm

    float dxy = qSqrt( dx * dx + dy * dy ) ;
    float distance = qSqrt( dxy * dxy + dz * dz ) / 1000 ;          // m

    float velocity = m_velocity[ Tcp ] ;                            // m/s

    unsigned short duration = distance / velocity * 1000 ;          // ms

    PCube_moveStep(m_device, Shoulder, q1, duration ) ;             // rad
    PCube_moveStep(m_device, Elbow,    q2, duration ) ;             // rad
    PCube_moveStep(m_device, Wrist,    q3, duration ) ;             // rad

    if ( withZAxis ) {
        z  *= m_CCW[ ZAxis ] ;                                      // mm
        PCube_moveStep(m_device, ZAxis, z / 1000.0, duration ) ;    // m
    }

    emit info("SCARA", QString("Movement duration %1 ms...").arg(duration) ) ;

    bool ended = false ;
    unsigned long state1 ;
    unsigned long state2 ;
    unsigned long state3 ;
    unsigned long state4 = 0 ;

    while ( !ended ) {
        PCube_getModuleState(m_device, Shoulder, &state1 ) ;
        PCube_getModuleState(m_device, Elbow, &state2 ) ;
        PCube_getModuleState(m_device, Wrist, &state3 ) ;

        if ( withZAxis )    PCube_getModuleState(m_device, ZAxis, &state4 ) ;

        if ( ( ( state1 | state2 | state3 | state4 ) & STATEID_MOD_MOTION ) == 0 )  ended = true ;

        currentTcpCartesianPosition() ;
        emit positionChanged(Shoulder, m_lastPosition[ Shoulder ] ) ;   // rad
        emit positionChanged(Elbow, m_lastPosition[ Elbow ] ) ;         // rad

        m_lastPosition[ Wrist ] = currentPosition( Wrist ) ;            // rad
        emit positionChanged(Wrist, m_lastPosition[ Wrist ] ) ;         // rad

        if ( withZAxis ) {
            m_lastPosition[ ZAxis ] = currentPosition( ZAxis ) ;        // m
            emit positionChanged(ZAxis, m_lastPosition[ ZAxis ] ) ;
        }

        emit tcpCartesianPositionChanged( m_lastCartesianPosition ) ;   // mm

        QCoreApplication::processEvents() ;
    }
    return true ;
}

