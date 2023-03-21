/* ----------------------------------------------------------------------------
 |	Nom :			dialog.h
 |	Projet :		Cellflex - LLF Scara
 |	Sujet :     	main UI interface
 |  Auteur :		Alain Menu
 |	Version :		1.3
 |	Création :		mars 2014
 |	Mise à jour :	22/05/2015
 |	Fabrication :	Qt4 / Qt5 OpenSource (Desktop)
 + ------------------------------------------------------------------------- */
/*
 |	Copyright (c) 2014-2015 by Alain Menu <alain.menu@ac-creteil.fr>
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

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include "qamscara.h"
#include <QCloseEvent>
#include <QResizeEvent>
#include <QSettings>
#include <QDir>
#include <QFileDialog>
#include <QTime>
#include <QThread>
#include <QPropertyAnimation>
#include <QDesktopServices>

#include <qamtcpserver.h>
#include <qammodbusmap.h>
#include <qammodbusmapviewer.h>

#define LLF_SCARA_VERSION     "1.3"


// some default values (mm)...

#define PUZZLE_GAP            65.0      // gap between puzzle's centers
#define PUZZLE_COLS            5
#define PUZZLE_ROWS            4
#define PUZZLE_ZESCAPE        50.0
#define SCARA_GRIPPER_OFFS    27.2      // gap between fingers interior spacing and axis value
#define SCARA_GRIPPER_OPEN    62.0
#define SCARA_GRIPPER_CLOSE   60.0

// Puzzle geometry

//         A     B     C     D     E
//      +-----+-----+-----+-----+-----+
//   1  |  0  |  1  |  2  |  3  |  4  | --
//      +-----+-----+-----+-----+-----+  | PUZZLE_GAP
//   2  |  5  |  6  |  7  |  8  |  9  | --
//      +-----+-----+-----+-----+-----+                            0
//   3  | 10  | 11  | 12  | 13  | 14  |                            |
//      +-----+-----+-----+-----+-----+    piece orientation : 1 --+-- 3
//   4  | 15  | 16  | 17  | 18  | 19  |                            |
//      +-----+-----+-----+-----+-----+                            2
//         |     |
//        >|-----|<-- PUZZLE_GAP



class Dialog : public QDialog, private Ui::Dialog
{
	Q_OBJECT

  // application general members (see dialog.cpp)
  // -----------------------------------------------------------------------

  public:
	explicit Dialog(QWidget* parent = 0 ) ;

  protected:
	void closeEvent(QCloseEvent* event ) ;
    void resizeEvent(QResizeEvent* event ) ;

  private slots:
    void on_chkSimulator_toggled(bool checked ) ;
    void on_pbuClean_clicked() ;
    void on_pbuFill_clicked() ;
    void on_pbuHelp_clicked() ;

  private:
    void readSettings() ;
    void writeSettings() ;
    void showPrompt(QTextEdit* edtInfo, const QString& prompt ) ;
    void showMessage(QTextEdit* edtInfo, const QString& msg, bool bold = false, QColor color = Qt::black ) ;

    QString floatAsString(float value, int precision = 2 ) ;

  // automatic mode members (see dialog.cpp)
  // -----------------------------------------------------------------------

  public slots:
    void modbusInfo(const QString& source, const QString& message ) ;
    void modbusError(const QString& source, const QString& message ) ;
    void modbusValueChanged(int table,const QString& name ) ;

  private slots:
    void on_pbuLoadModbusConf_clicked() ;
    void on_pbuStartServer_clicked() ;

    void animationEnded() ;

  private:
    void initAnimation(int num, int ori ) ;
    void startAnimation() ;

    void assemblyCycle() ;
    void disassemblyCycle() ;
    void trashCycle() ;
    void defaultInCycle() ;

  // manual mode members (see dialogmanu.cpp)
  // -----------------------------------------------------------------------

  public:
    bool openGripper() ;
    bool closeGripper() ;
    bool goUp() ;
    bool goDown() ;
    bool gotoPoint(const QString& pointName, float gripperOrientation = 0.0 ) ;

  public slots:
    void info(const QString& source, const QString& message ) ;
    void error(const QString& source, const QString& message ) ;
    void positionChanged(int axis, float pos ) ;
    void tcpCartesianPositionChanged(QPointF pos ) ;

  private slots:
    void on_pbuOpen_clicked() ;
    void on_pbuSelectAll_clicked()		{ selectAllAxis( true ) ; }
    void on_pbuDeselectAll_clicked()	{ selectAllAxis( false ) ; }
    void on_pbuReset_clicked() ;
    void on_pbuHome_clicked() ;
    void on_pbuHalt_clicked() ;
    void on_pbuState_clicked() ;

    void on_pbuZaxisDec_clicked()		{ moveAxis(QamScara::ZAxis,   -getStep() / 1000.0 ) ; }
    void on_pbuZaxisInc_clicked()		{ moveAxis(QamScara::ZAxis,    getStep() / 1000.0 ) ; }
    void on_pbuShoulderDec_clicked()	{ moveAxis(QamScara::Shoulder, degToRad( -getStep() ) ) ; }
    void on_pbuShoulderInc_clicked()	{ moveAxis(QamScara::Shoulder, degToRad(  getStep() ) ) ; }
    void on_pbuElbowDec_clicked()		{ moveAxis(QamScara::Elbow,    degToRad( -getStep() ) ) ; }
    void on_pbuElbowInc_clicked()		{ moveAxis(QamScara::Elbow,    degToRad(  getStep() ) ) ; }
    void on_pbuWristDec_clicked()		{ moveAxis(QamScara::Wrist,    degToRad( -getStep() ) ) ; }
    void on_pbuWristInc_clicked()		{ moveAxis(QamScara::Wrist,    degToRad(  getStep() ) ) ; }
    void on_pbuGripperDec_clicked()		{ moveAxis(QamScara::Gripper, -getStep() / 1000.0 ) ; }
    void on_pbuGripperInc_clicked()		{ moveAxis(QamScara::Gripper,  getStep() / 1000.0 ) ; }

    void on_pbuXaxisDec_clicked()		{ moveTcp( -getStep(), 0.0 ) ; }
    void on_pbuXaxisInc_clicked()		{ moveTcp(  getStep(), 0.0 ) ; }
    void on_pbuYaxisDec_clicked()		{ moveTcp( 0.0, -getStep() ) ; }
    void on_pbuYaxisInc_clicked()		{ moveTcp( 0.0,  getStep() ) ; }

    void on_pbuGoto_clicked() ;
    void on_rbuGotoCoord_clicked()      { rbuGotoPoint->toggle() ; }
    void on_rbuGotoPoint_clicked()      { rbuGotoCoord->toggle() ; }

//    void on_pbuTcpDown_clicked()        { goDown() ; }
//    void on_pbuTcpUp_clicked()          { goUp() ; }
	// new 1.3 
	void on_pbuTcpDown_clicked()        { goDown() ; pbuTcpDown->setEnabled(false) ; }
    void on_pbuTcpUp_clicked()          { goUp() ;   pbuTcpDown->setEnabled(true) ; }

    void on_pbuWristCCW_clicked()       { moveAxis(QamScara::Wrist,  degToRad( 90.0 ) ) ; }
    void on_pbuWristCW_clicked()        { moveAxis(QamScara::Wrist, -degToRad( 90.0 ) ) ; }
    void on_pbuOpenGripper_clicked()    { openGripper() ; }
    void on_pbuCloseGripper_clicked()   { closeGripper() ; }

  private:
    float getStep() ;
    float getCurrentPos(QamScara::Axis axis ) ;
    void selectAllAxis(bool select = true ) ;
    void getSelectedAxis() ;
    bool moveAxis(QamScara::Axis axis, float offset, bool relative = true ) ;
    bool moveTcp(float offsetX, float offsetY ) ;

  // Scara configuration (see dialogconf.cpp)
  // -----------------------------------------------------------------------

  private slots :
    void on_pbuLoadList_clicked() ;
    void on_pbuSaveList_clicked() ;
    void on_pbuUpdatePoint_clicked() ;
    void on_pbuCalculatePoints_clicked() ;

  private:
    bool loadScaraConf(const QString& filename ) ;
    bool saveScaraConf(const QString& filename ) ;
    float getVel(QamScara::Axis axis ) ;
    void setVel(QamScara::Axis axis, float value ) ;
    float getAcc(QamScara::Axis axis ) ;
    void setAcc(QamScara::Axis axis, float value ) ;

    QTableWidgetItem* newItem(const QString& s ) ;

    void addWaypoint(const QString& name, float x = 0.0, float y = 0.0, float z = 0.0, float rz = 0.0 ) ;
    void addRotation(const QString& name, float rzBegin = 0.0, float rzEnd = 0.0 ) ;
    QString waypointByName(const QString& name, int column ) ;
    void setWaypointByName(const QString& name, int column, const QString& s ) ;
    QString rotationByName(const QString& name, int column ) ;
    void setRotationByName(const QString& name, int column, const QString& s ) ;

  // data members
  // -----------------------------------------------------------------------

  private:
    QString             m_configDir ;

    QamModbusMap*		m_modbusMap ;       // Modbus server
    QamTcpServer*		m_tcpServer ;
    bool				m_isRunning ;

    bool                m_simulation ;      // mode
    bool                m_AssemblyMode ;
    int                 m_pieceNum ;
    int                 m_pieceOri ;

    QRect               m_imgRect ;         // piece animation
    QLabel*             m_labImgPalette ;
    QPropertyAnimation* m_animation ;

    QamScara*           m_scara ;
    bool                m_selected[ SCARA_NUMID ] ;
    QStringList         m_axisName ;

    float               m_puzzleGap ;       // config file data
    int                 m_puzzleCols ;
    int                 m_puzzleRows ;
    float               m_zEscape ;
    float               m_gripperOffs ;
    float               m_gripperOpen ;
    float               m_gripperClose ;

    QStringList         m_waypointNames ;
    QStringList         m_rotationNames ;

//    float               m_velocity[ SCARA_NUMID ] ;
//    float               m_acceleration[ SCARA_NUMID ] ;
} ;

#endif // DIALOG_H
