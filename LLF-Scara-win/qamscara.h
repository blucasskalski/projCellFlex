/* ----------------------------------------------------------------------------
 |	Nom :			qamscara.h
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

#ifndef QAMSCARA_H
#define QAMSCARA_H

#include <QObject>
#include <QCoreApplication>
#include <QPointF>
#include <qmath.h>
#include <m5apiw32.h>

#define PI              3.14159265359

#define radToDeg(RAD)	( (RAD) * 180.0 / PI )
#define degToRad(DEG)	( (DEG) * PI / 180.0 )

#define CAN_INIT_STR    "ESD:0,250"
#define	SCARA_NUMAXIS	5
#define SCARA_NUMID     ( SCARA_NUMAXIS + 1 )

// Scara rotary axis counterclockwise

#define SCARA_ZAXIS_CCW      1
#define SCARA_SHOULDER_CCW   1
#define SCARA_ELBOW_CCW     -1
#define SCARA_WRIST_CCW     -1
#define SCARA_GRIPPER_CCW    1

// Scara geometry (in millimeters and degrees)

#define	SCARA_L1             350.0      // length shoulder-elbow
#define	SCARA_L2             350.0      // length elbow-wrist

// Scara axis state

#define SCARA_STATE_HEADER "\n" \
    "RAMP_STEADY -----------------+ +----------------- MOTION\n" \
    "RAMP_END ------------------+ | | +---------- BRAKEACTIVE\n" \
    "FULLBUFFER --------------+ | | | | +---------------- SW1\n" \
    "POW_FET_TEMP ----------+ | | | | | | +------- COMM_ERROR\n" \
    "POW_INTEGRAL_ERR --+   | | | | | | | | +----- POWERFAULT\n" \
    "BEYOND_SOFT ----+  |   | | | | | | | | | |+----- HOME_OK\n" \
    "                |  |   | | | | | | | | | | \n"
#define SCARA_STATE \
    "           ----EEE-E---EEIIIIIIIIIIIIEEEIIE"
#define SCARA_STATE_FOOTER \
    "               | |      | | | | | | | | | |\n" \
    "LOGIC_VOLT ----+ |      | | | | | | | | | +------- ERROR\n" \
    "BEYOND_HARD -----+      | | | | | | | | +-------- HALTED\n" \
    "POW_VOLT_ERR -----------+ | | | | | | +------- TOW_ERROR\n" \
    "INPROGRESS ---------------+ | | | | +--------------- SWR\n" \
    "RAMP_DEC -------------------+ | | +----------------- SW2\n" \
    "RAMP_ACC ---------------------+ +-------------- CURLIMIT\n"

class QamScara : public QObject
{
    Q_OBJECT

  public:
    explicit QamScara(QObject* parent = 0 ) ;

    // Module Id 1..5 (Tcp=0 is used for simultaneous movements)
    typedef enum {Tcp, ZAxis, Shoulder, Elbow, Wrist, Gripper } Axis ;

    bool open() ;
    void close() ;
    bool reset(Axis axis ) ;
    bool home(Axis axis ) ;

    QString state(Axis axis ) ;

    float velocity(Axis axis ) const ;
    float acceleration(Axis axis ) const ;
    float currentPosition(Axis axis ) const ;
    QPointF currentTcpCartesianPosition() ;

    void setVelocity(Axis axis, float value ) ;
    void setAcceleration(Axis axis, float value ) ;

    bool moveRel(Axis axis, float value ) ;
    bool moveAbs(Axis axis, float value ) ;
    bool moveRel(float x, float y, float z = 0.0, float rz = 0.0 ) ;
    bool moveAbs(float x, float y, float z = 0.0, float rz = 0.0 ) ;

  public slots:
    void halt() ;

  signals:
    void info(const QString& source, const QString& message ) ;
    void error(const QString& source, const QString& message ) ;
    void positionChanged(int axis, float pos ) ;
    void tcpCartesianPositionChanged(QPointF pos ) ;

  private:
    int		m_device ;
    QString	m_initString ;

    float   m_CCW[ SCARA_NUMID ] ;
    bool    m_isLinearAxis[ SCARA_NUMID ] ;
    float   m_velocity[ SCARA_NUMID ] ;
    float   m_acceleration[ SCARA_NUMID ] ;
    float	m_maxVel[ SCARA_NUMID ] ;
    float	m_maxAcc[ SCARA_NUMID ] ;
    float	m_minPos[ SCARA_NUMID ] ;
    float	m_maxPos[ SCARA_NUMID ] ;

    float   m_lastPosition[ SCARA_NUMID ] ;
    QPointF m_lastCartesianPosition ;
} ;

#endif // QAMSCARA_H
