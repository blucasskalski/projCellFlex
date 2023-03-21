/* ----------------------------------------------------------------------------
 |	Nom :			dialogconf.cpp
 |	Projet :		Cellflex - LLF Scara
 |	Sujet :     	main UI implementation
 |  Auteur :		Alain Menu
 |	Version :		1.0
 |	Création :		mars 2014
 |	Mise à jour :	02/04/2014
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
#include "cellflex_template.h"

// chargement fichier de configuration

void Dialog::on_pbuLoadList_clicked()
{
    QString	fileName = QFileDialog::getOpenFileName(
        this,
        tr("Ouvrir..."),
        m_configDir,
        tr("Scara Configuration File (*.csv)") ) ;
    if ( !fileName.isEmpty() ) {
        // mémorisation du répertoire source utilisé
        m_configDir = QFileInfo( fileName ).absolutePath() ;
#ifdef Q_OS_MAC
        m_configDir = m_configDir + QDir::separator() + "*" ;
#endif
        loadScaraConf( fileName ) ;
    }
}

bool Dialog::loadScaraConf(const QString& filename )
{
    QFile	file( filename ) ;

    if ( file.open( QIODevice::ReadOnly) ) {
        QByteArray fileBytes = file.readAll() ;
        fileBytes.replace("\r\n", "\n" ) ;
        fileBytes.replace("\r", "\n" ) ;
        QTextStream in( fileBytes ) ;

        in.setCodec( "UTF-8" ) ;

        QString line = in.readLine() ;
        int nline = 1 ;

        info("CONFIG", "Loading " + filename + "..." ) ;

        while ( !line.isNull() ) {

            if (( line.isEmpty() )||( line.startsWith("#") )) {
                line = in.readLine() ;
                nline++ ;
                continue;
            }

            QStringList	parse = line.split(";") ;
            for ( int i = 0 ; i < parse.size() ; ++i ) {
                parse[i] = parse[i].trimmed() ;
            }

            if ( parse.size() == 7 ) {
                if ( parse.at(0) == "Velocity" ) {
                    for ( int v = 0 ; v < 6 ; ++v )    setVel( (QamScara::Axis)v, parse.at( v + 1 ).toFloat() ) ;
                }
                else if ( parse.at(0) == "Acceleration" ) {
                    for ( int v = 0 ; v < 6 ; ++v )    setAcc( (QamScara::Axis)v, parse.at( v + 1 ).toFloat() ) ;
                }
                else error("CONFIG", QString("Line %1: unknown or wrong entry!").arg( nline ) ) ;
            }
            else if (( parse.size() == 5 )&&( m_waypointNames.contains(parse.at(0)) )) {
                setWaypointByName(parse.at(0), 1, parse.at(1) ) ;
                setWaypointByName(parse.at(0), 2, parse.at(2) ) ;
                setWaypointByName(parse.at(0), 3, parse.at(3) ) ;
                setWaypointByName(parse.at(0), 4, parse.at(4) ) ;
            }
            else if (( parse.size() == 3 )&&( m_rotationNames.contains(parse.at(0)) )) {
                setRotationByName(parse.at(0), 1, parse.at(1) ) ;
                setRotationByName(parse.at(0), 2, parse.at(2) ) ;
            }
            else if ( parse.size() == 2 ) {
                if      ( parse.at(0) == "PuzzleGap" )      m_puzzleGap = parse.at(1).toFloat() ;
                else if ( parse.at(0) == "PuzzleCols" )     m_puzzleCols = parse.at(1).toInt() ;
                else if ( parse.at(0) == "PuzzleRows" )     m_puzzleRows = parse.at(1).toInt() ;
                else if ( parse.at(0) == "ZEscape" )        m_zEscape = parse.at(1).toFloat() ;
                else if ( parse.at(0) == "GripperOffs" )    m_gripperOffs = parse.at(1).toFloat() ;
                else if ( parse.at(0) == "GripperOpen" )    m_gripperOpen = parse.at(1).toFloat() ;
                else if ( parse.at(0) == "GripperClose" )   m_gripperClose = parse.at(1).toFloat() ;
                else error("CONFIG", QString("Line %1: unknown or wrong entry!").arg( nline ) ) ;
            }
            else {
                error("CONFIG", QString("Line %1: invalid format!").arg( nline ) ) ;
            }

            line = in.readLine() ;
            nline++ ;
        }
        file.close() ;
        return true ;
    }
    error("CONFIG", filename + " not found!") ;
    return false ;
}

// mise à jour du point sélectionné avec la position courante

void Dialog::on_pbuUpdatePoint_clicked()
{
    QList<QTableWidgetItem*> selection = tblPoints->selectedItems() ;
    if ( selection.isEmpty() ) {
        error("UPDATE", "No selected point!" ) ;
        return ;
    }

    float x, y, z ;
    float rz = 0.0 ;
    bool  okx, oky, okz ;

    // position cartésienne courante
    // prélevée dans les widgets non éditables...
    x = edtXaxis->text().toFloat(&okx ) ;
    y = edtYaxis->text().toFloat(&oky ) ;
    z = edtZaxis->text().toFloat(&okz ) ;
    z -= m_zEscape ;

    // calcul de rz = compensation OX+
    float q1 = m_scara->currentPosition(QamScara::Shoulder ) ;
    float q2 = m_scara->currentPosition(QamScara::Elbow ) ;
    float q3 = m_scara->currentPosition(QamScara::Wrist ) ;
    rz = radToDeg( q1 + q2 + q3 ) ;

    if ( ( okx && oky && okz ) == false ) {
        error("UPDATE", "Invalid float coordinate!" ) ;
        return ;
    }

    selection.at(1)->setText( floatAsString(x, 2 ) ) ;
    selection.at(2)->setText( floatAsString(y, 2 ) ) ;
    selection.at(3)->setText( floatAsString(z, 2 ) ) ;
    selection.at(4)->setText( floatAsString(rz, 2 ) ) ;

    info("UPDATE", "Point " + selection.at(0)->text() + " updated" ) ;
}

// calcul automatique des points Pu_01 à Pu_18

void Dialog::on_pbuCalculatePoints_clicked()
{
    info("CELLFLEX", "Calculate points coordinates..." ) ;

    float x0 = waypointByName("Pu_00", 1 ).toFloat() ;  // centre pièce num.  0
    float y0 = waypointByName("Pu_00", 2 ).toFloat() ;
    float z0 = waypointByName("Pu_00", 3 ).toFloat() ;
    float rz0 = waypointByName("Pu_00", 4 ).toFloat() ;

    float x1 = waypointByName("Pu_19", 1 ).toFloat() ;  // centre pièce num. 19
    float y1 = waypointByName("Pu_19", 2 ).toFloat() ;
    float z1 = waypointByName("Pu_19", 3 ).toFloat() ;
    float rz1 = waypointByName("Pu_19", 4 ).toFloat() ;

    float x2 ;          // centre pièce num.  4
    float y2 ;

    int npa = m_puzzleRows ;                // nombre de pièces = npa x npb
    int npb = m_puzzleCols ;
    float a = m_puzzleGap * ( npa - 1 ) ;   // distance entre centres Pu_04 et Pu_19
    float b = m_puzzleGap * ( npb - 1 ) ;   // distance entre centres Pu_00 et Pu_04

    float d = qSqrt( a * a + b * b ) ;      // diamètre du cercle circonscrit
    float xc = x0 + ( x1 - x0 ) / 2.0 ;     // centre du cercle circonscrit
    float yc = y0 + ( y1 - y0 ) / 2.0 ;

    x0 -= xc ;      // décalage d'origine Oz sur centre du cercle
    y0 -= yc ;
    x1 -= xc ;
    y1 -= yc ;

    float beta = ( qAsin( a / d ) + qAcos( b / d ) ) / 2.0 ;    // angle Pu_04,Pu_00,Pu_19

    x2 = x1 * qCos( 2 * beta ) - y1 * qSin( 2 * beta ) ;        // Pu_04 = rotation 2.beta
    y2 = y1 * qCos( 2 * beta ) + x1 * qSin( 2 * beta ) ;        // de Pu_19 autour du centre...

    x0 += xc ;          // retour référentiel Oz robot
    y0 += yc ;
    x1 += xc ;
    y1 += yc ;
    x2 += xc ;
    y2 += yc ;

    float x[npb][npa] ; // proportionnalité pour les 20 centres
    float y[npb][npa] ;

    for ( int i = 0 ; i < npa * npb ; ++i ) {
        int ia = i / npb ;  // indice ligne de 0 à ( npa - 1 )
        int ib = i % npb ;  // indice colonne de 0 à ( npb - 1 )
        x[ib][ia] = x0 + ia * ( x1 - x2 ) / ( npa - 1 ) + ib * ( x2 - x0 ) / ( npb - 1 ) ;
        y[ib][ia] = y0 + ia * ( y1 - y2 ) / ( npa - 1 ) + ib * ( y2 - y0 ) / ( npb - 1 ) ;

        if (( i == 0 )||( i == npa * npb - 1 ))   continue ;

        QString pointName( QString("Pu_%1%2").arg( i / 10 ).arg( i % 10 ) ) ;
        setWaypointByName(pointName, 1, floatAsString( x[ib][ia], 2 ) ) ;
        setWaypointByName(pointName, 2, floatAsString( y[ib][ia], 2 ) ) ;

        // profondeur calculée au prorata z1 - z0
        float xp = x[ib][ia] - x0 ;
        float yp = y[ib][ia] - y0 ;
        float d0 = sqrt( xp * xp + yp * yp ) ;
        float z = z0 + d0 / d * ( z1 - z0 ) ;
        setWaypointByName(pointName, 3, floatAsString( z, 2 ) ) ;

        // compensation RZ théoriquement constante...
        setWaypointByName(pointName, 4, floatAsString( ( rz0 + rz1 ) / 2.0, 2 ) ) ;
    }
    info("CELLFLEX", "Done for Pu_01 to Pu_18" ) ;
}

// sauvegarde de la configuration

void Dialog::on_pbuSaveList_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Enregistrer sous..."),
        m_configDir,
        tr("Scara Configuration File (*.csv)") ) ;
    if ( !fileName.isEmpty() ) {
        // mémorisation du répertoire source utilisé
        m_configDir = QFileInfo( fileName ).absolutePath() ;
#ifdef Q_OS_MAC
        m_configDir = m_configDir + QDir::separator() + "*" ;
#endif
        if ( !fileName.endsWith(".csv") )    fileName += ".csv" ;
        saveScaraConf( fileName ) ;
    }
}

bool Dialog::saveScaraConf(const QString& filename )
{
    QString fileTemplate = CELLFLEX_SCARA_CONF ;
    QString entry ;

    entry = QFileInfo(filename).fileName() ;
    fileTemplate.replace("##FileName##", entry ) ;
    entry = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") ;
    fileTemplate.replace("##Dating##", entry ) ;

    entry = QString("PuzzleGap; %1").arg( floatAsString(m_puzzleGap, 2 ) ) ;
    fileTemplate.replace("##PuzzleGap##", entry ) ;
    entry = QString("PuzzleCols; %1").arg(m_puzzleCols ) ;
    fileTemplate.replace("##PuzzleCols##", entry ) ;
    entry = QString("PuzzleRows; %1").arg(m_puzzleRows ) ;
    fileTemplate.replace("##PuzzleRows##", entry ) ;
    entry = QString("ZEscape; %1").arg( floatAsString(m_zEscape, 2 ) ) ;
    fileTemplate.replace("##ZEscape##", entry ) ;
    entry = QString("GripperOffs; %1").arg( floatAsString(m_gripperOffs, 2 ) ) ;
    fileTemplate.replace("##GripperOffs##", entry ) ;
    entry = QString("GripperOpen; %1").arg( floatAsString(m_gripperOpen, 2 ) ) ;
    fileTemplate.replace("##GripperOpen##", entry ) ;
    entry = QString("GripperClose; %1").arg( floatAsString(m_gripperClose, 2 ) ) ;
    fileTemplate.replace("##GripperClose##", entry ) ;

    entry = QString("Velocity") ;
    for ( int i = 0 ; i < SCARA_NUMID ; ++i ) entry += QString("; %1").arg( floatAsString(getVel( (QamScara::Axis)i ), 2 ) ) ;
    fileTemplate.replace("##Velocity##", entry ) ;
    entry = QString("Acceleration") ;
    for ( int i = 0 ; i < SCARA_NUMID ; ++i ) entry += QString("; %1").arg( floatAsString(getAcc( (QamScara::Axis)i ), 2 ) ) ;
    fileTemplate.replace("##Acceleration##", entry ) ;

    for ( int i = 0 ; i < m_waypointNames.size() ; ++i ) {
        entry = m_waypointNames.at(i) ;
        for ( int j = 1 ; j <= 4 ; j++ ) {
            float v = waypointByName(m_waypointNames.at(i), j ).toFloat() ;
            entry += QString("; %1").arg( floatAsString( v, 2 ) ) ;
        }
        fileTemplate.replace( QString("##%1##").arg(m_waypointNames.at(i)), entry ) ;
    }

    for ( int i = 0 ; i < m_rotationNames.size() ; ++i ) {
        entry = m_rotationNames.at(i) ;
        for ( int j = 1 ; j <= 2 ; j++ ) {
            float v = rotationByName(m_rotationNames.at(i), j ).toFloat() ;
            entry += QString("; %1").arg( floatAsString( v, 2 ) ) ;
        }
        fileTemplate.replace( QString("##%1##").arg(m_rotationNames.at(i)), entry ) ;
    }

    QFile file( filename ) ;
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text ) ) {
        error("CONFIG", "Error while opening " + filename + "!" ) ;
        return false ;
    }
    QTextStream out( &file ) ;
    out << fileTemplate ;
    file.close() ;
    info("CONFIG", "Configuration saved in " + filename ) ;

//    info("TEST", fileTemplate ) ;

    return true ;
}

// current user values for velocity and acceleration

float Dialog::getVel(QamScara::Axis axis )
{
    if ( axis == QamScara::Tcp )        return edtTcpVel->text().toFloat() ;
    if ( axis == QamScara::ZAxis )		return edtZaxisVel->text().toFloat() ;
    if ( axis == QamScara::Shoulder )	return edtShoulderVel->text().toFloat() ;
    if ( axis == QamScara::Elbow )		return edtElbowVel->text().toFloat() ;
    if ( axis == QamScara::Wrist )		return edtWristVel->text().toFloat() ;
    if ( axis == QamScara::Gripper )	return edtGripperVel->text().toFloat() ;
    return 0.0 ;
}

void Dialog::setVel(QamScara::Axis axis, float value )
{
    if ( axis == QamScara::Tcp )        edtTcpVel->setText( floatAsString(value) ) ;
    if ( axis == QamScara::ZAxis )		edtZaxisVel->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Shoulder )	edtShoulderVel->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Elbow )		edtElbowVel->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Wrist )		edtWristVel->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Gripper )	edtGripperVel->setText( floatAsString(value) ) ;
}

float Dialog::getAcc(QamScara::Axis axis )
{
    if ( axis == QamScara::ZAxis )		return edtZaxisAcc->text().toFloat() ;
    if ( axis == QamScara::Shoulder )	return edtShoulderAcc->text().toFloat() ;
    if ( axis == QamScara::Elbow )		return edtElbowAcc->text().toFloat() ;
    if ( axis == QamScara::Wrist )		return edtWristAcc->text().toFloat() ;
    if ( axis == QamScara::Gripper )	return edtGripperAcc->text().toFloat() ;
    return 0.0 ;
}

void Dialog::setAcc(QamScara::Axis axis, float value )
{
    if ( axis == QamScara::ZAxis )		edtZaxisAcc->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Shoulder )	edtShoulderAcc->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Elbow )		edtElbowAcc->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Wrist )		edtWristAcc->setText( floatAsString(value) ) ;
    if ( axis == QamScara::Gripper )	edtGripperAcc->setText( floatAsString(value) ) ;
}

QTableWidgetItem* Dialog::newItem(const QString& s )
{
    QTableWidgetItem*   item = new QTableWidgetItem ;
    item->setTextAlignment( Qt::AlignRight ) ;
    item->setText( s ) ;
    return item ;
}

void Dialog::addWaypoint(const QString& name, float x, float y, float z, float rz )
{
    int i = tblPoints->rowCount() ;
    tblPoints->setRowCount( i + 1 ) ;
    tblPoints->setRowHeight( i, 20 ) ;
    QTableWidgetItem* item = newItem( name ) ;
    Qt::ItemFlags flags = item->flags() ;
    flags &= ~Qt::ItemIsEditable ;
    item->setFlags(flags) ;
    item->setTextAlignment( Qt::AlignHCenter ) ;
    tblPoints->setItem(i, 0, item ) ;
    tblPoints->setItem(i, 1, newItem( floatAsString( x ) ) ) ;
    tblPoints->setItem(i, 2, newItem( floatAsString( y ) ) ) ;
    tblPoints->setItem(i, 3, newItem( floatAsString( z ) ) ) ;
    tblPoints->setItem(i, 4, newItem( floatAsString( rz ) ) ) ;
}

void Dialog::addRotation(const QString& name , float rzBegin, float rzEnd )
{
    int i = tblRotations->rowCount() ;
    tblRotations->setRowCount( i + 1 ) ;
    tblRotations->setRowHeight( i, 20 ) ;
    QTableWidgetItem* item = newItem( name ) ;
    Qt::ItemFlags flags = item->flags() ;
    flags &= ~Qt::ItemIsEditable ;
    item->setFlags(flags) ;
    item->setTextAlignment( Qt::AlignHCenter ) ;
    tblRotations->setItem(i, 0, item ) ;
    tblRotations->setItem(i, 1, newItem( floatAsString( rzBegin ) ) ) ;
    tblRotations->setItem(i, 2, newItem( floatAsString( rzEnd ) ) ) ;
}

QString Dialog::waypointByName(const QString& name, int column )
{
    if (( column < 1 )||( column > 4 )) return "0" ;
    int rows = tblPoints->rowCount() ;
    for ( int i = 0 ; i < rows ; ++i ) {
        if ( tblPoints->item(i, 0 )->text() == name ) return tblPoints->item(i, column )->text() ;
    }
    return "0" ;
}

void Dialog::setWaypointByName(const QString& name, int column, const QString& s )
{
    if (( column < 1 )||( column > 4 )) return ;
    int rows = tblPoints->rowCount() ;
    for ( int i = 0 ; i < rows ; ++i ) {
        if ( tblPoints->item(i, 0 )->text() == name ) tblPoints->item(i, column )->setText( s ) ;
    }
}

QString Dialog::rotationByName(const QString& name, int column )
{
    if (( column < 1 )||( column > 2 ))  return "0" ;
    int rows = tblRotations->rowCount() ;
    for ( int i = 0 ; i < rows ; ++i ) {
        if ( tblRotations->item(i, 0 )->text() == name ) return tblRotations->item(i, column )->text() ;
    }
    return "0" ;
}

void Dialog::setRotationByName(const QString& name, int column, const QString& s )
{
    if (( column < 1 )||( column > 2 )) return ;
    int rows = tblRotations->rowCount() ;
    for ( int i = 0 ; i < rows ; ++i ) {
        if ( tblRotations->item(i, 0 )->text() == name ) tblRotations->item(i, column )->setText( s ) ;
    }
}
