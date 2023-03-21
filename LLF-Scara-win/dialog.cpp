/* ----------------------------------------------------------------------------
 |	Nom :			dialog.cpp
 |	Projet :		Cellflex - LLF Scara
 |	Sujet :     	main UI implementation
 |  Auteur :		Alain Menu
 |	Version :		1.2
 |	Création :		mars 2014
 |	Mise à jour :	17/06/2014
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

Dialog::Dialog(QWidget* parent ) 
	: QDialog(parent)
    , m_isRunning( false )
    , m_AssemblyMode( true )
{
	setupUi(this) ;

    labVersion->setText( QString("(c) by A. Menu - version %1   ").arg(LLF_SCARA_VERSION) ) ;

    m_simulation = chkSimulator->isChecked() ;
    tabManu->setEnabled( !m_simulation ) ;

    tabWidget->setStyleSheet(
        "QTabBar::tab { min-width: 200px; }" \
        "QTabBar::tab:selected { font: bold; color: darkred; }"
    ) ;

    edtScaraInfo->setFont( QFont("Courier", 10 ) ) ;
    edtModbusInfo->setFont( QFont("Courier", 10 ) ) ;
    mapView->setFont( QFont("Courier", 10 ) ) ;

    tblPoints->clear() ;
    tblPoints->setColumnCount( 5 ) ;
    for ( int i = 0 ; i < 5 ; ++i ) tblPoints->setColumnWidth(i, 60 ) ;
    tblPoints->verticalHeader()->setVisible( false ) ;
    tblPoints->setAlternatingRowColors( true ) ;
    QStringList titles ;
    titles << "Name" << "X (mm)" << "Y (mm)" << "Z (mm)" << "RZ (deg)" ;
    tblPoints->setHorizontalHeaderLabels( titles ) ;
    tblPoints->setSelectionMode( QAbstractItemView::SingleSelection ) ;
    tblPoints->setSelectionBehavior( QAbstractItemView::SelectRows ) ;

    tblRotations->clear() ;
    tblRotations->setColumnCount( 3 ) ;
    for ( int i = 0 ; i < 3 ; ++i ) tblRotations->setColumnWidth(i, 100 ) ;
    tblRotations->verticalHeader()->setVisible( false ) ;
    tblRotations->setAlternatingRowColors( true ) ;
    titles.clear() ;
    titles << "Name" << "RZ begin (deg)" << "RZ end (deg)" ;
    tblRotations->setHorizontalHeaderLabels( titles ) ;
    tblRotations->setSelectionMode( QAbstractItemView::SingleSelection ) ;
    tblRotations->setSelectionBehavior( QAbstractItemView::SelectRows ) ;

    readSettings() ;

    ledAssembly->setText("Assembly mode" ) ;
    ledDisassembly->setText("Disassembly mode" ) ;
    ledBusy->setText("Busy") ;
    ledDefault->setText("Default" ) ;

    ledAssembly->setOrientation(QamWidget::Left ) ;
    ledDisassembly->setOrientation(QamWidget::Left ) ;
    ledBusy->setOrientation(QamWidget::Left ) ;
    ledDefault->setOrientation(QamWidget::Left ) ;

    ledBusy->setState(QamWidget::Yellow ) ;
    ledDefault->setState(QamWidget::Red ) ;

    ledAssembly->on() ;
    ledDisassembly->off() ;
    ledBusy->off() ;
    ledDefault->off() ;

    m_axisName << "Tcp" << "Z-axis" << "Shoulder" << "Elbow" << "Wrist" << "Gripper" ;

    // valeurs par défaut (modifiables seulement par fichier de conf.)

    m_puzzleGap    = PUZZLE_GAP ;
    m_puzzleCols   = PUZZLE_COLS ;
    m_puzzleRows   = PUZZLE_ROWS ;
    m_zEscape      = PUZZLE_ZESCAPE ;
    m_gripperOffs  = SCARA_GRIPPER_OFFS ;
    m_gripperOpen  = SCARA_GRIPPER_OPEN ;
    m_gripperClose = SCARA_GRIPPER_CLOSE ;

    m_waypointNames << "Pa_Mon" << "Pa_Dem" ;
    for ( int i = 0 ; i < ( m_puzzleCols * m_puzzleRows ) ; ++i ) {
        m_waypointNames << QString("Pu_%1%2").arg( i / 10 ).arg( i % 10 ) ;
    }
    m_waypointNames << "PWait" << "PTrash" ;
    m_rotationNames << "Pa_to_Pu_0" << "Pa_to_Pu_1" << "Pa_to_Pu_2" << "Pa_to_Pu_3" ;

    for ( int i = 0 ; i < m_waypointNames.size() ; ++i )    addWaypoint(m_waypointNames.at(i) ) ;
    for ( int i = 0 ; i < m_rotationNames.size() ; ++i )    addRotation(m_rotationNames.at(i) ) ;

    // animation déplacement pièce

    m_labImgPalette = new QLabel( tabAuto ) ;
    m_animation = new QPropertyAnimation( m_labImgPalette, "geometry" ) ;

    connect( m_animation, SIGNAL(finished()), this, SLOT(animationEnded()) ) ;

    // init. générateur aléatoire

    QTime time = QTime::currentTime() ;
    qsrand( (uint)time.msec() ) ;

    // serveur Modbus

    m_modbusMap = new QamModbusMap(QamModbusMap::ServerMode, this ) ;

    connect( m_modbusMap, SIGNAL(info(QString,QString)),
             this, SLOT(modbusInfo(QString,QString)) ) ;

    connect( m_modbusMap, SIGNAL(valueChanged(int,QString)),
             this, SLOT(modbusValueChanged(int,QString)) ) ;

    // pilotage du robot Scara

    m_scara = new QamScara( this ) ;

    connect( m_scara, SIGNAL(positionChanged(int,float)),
             this, SLOT(positionChanged(int,float)) ) ;

    connect( m_scara, SIGNAL(tcpCartesianPositionChanged(QPointF)),
             this, SLOT(tcpCartesianPositionChanged(QPointF)) ) ;

    connect( m_scara, SIGNAL(info(QString,QString)),
             this, SLOT(info(QString,QString)) ) ;

    connect( m_scara, SIGNAL(error(QString,QString)),
             this, SLOT(error(QString,QString)) ) ;
}

// fermeture de l'application

void Dialog::closeEvent(QCloseEvent* event )
{
    m_scara->close() ;
    writeSettings() ;
    event->accept() ;
}

// mise à jour géométrie image animée

void Dialog::resizeEvent(QResizeEvent* event )
{
    Q_UNUSED( event ) ;

    m_imgRect.setTopLeft( labImgPalette->pos() ) ;
    m_imgRect.setWidth( labImgPalette->width() ) ;
    m_imgRect.setHeight( labImgPalette->height() ) ;
    m_labImgPalette->setGeometry( m_imgRect ) ;
    m_labImgPalette->raise() ;
}

// mode simulation du robot O/N

void Dialog::on_chkSimulator_toggled(bool checked )
{
    m_simulation = checked ;
    tabManu->setEnabled( !m_simulation ) ;
}

void Dialog::on_pbuHelp_clicked()
{
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( QUrl::fromLocalFile( m_configDir + "/LLFScaraHelpPage.html" ) ) ;
#endif
}

// ---------------------------------------------------------------------------
// gestion de la configuration inter-sessions
// ---------------------------------------------------------------------------

void Dialog::readSettings()
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "llfscara" ) ;

    QPoint	pos = settings.value("MainWindow/pos", QPoint(10,10) ).toPoint() ;
    QSize	size = settings.value("MainWindow/size", QSize(640,480) ).toSize() ;
    resize( size ) ;
    move( pos ) ;

    QString ld = QDir::homePath() ;
#ifdef Q_OS_MAC
    ld = ld + QDir::separator() + "*" ;
#endif
    m_configDir = settings.value("Files/configDir", ld ).toString() ;
}

void Dialog::writeSettings()
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "llfscara" ) ;

    settings.setValue("MainWindow/pos", pos() ) ;
    settings.setValue("MainWindow/size", size() ) ;
    settings.setValue("Files/configDir", m_configDir ) ;
}

// ---------------------------------------------------------------------------
// serveur Modbus
// ---------------------------------------------------------------------------

// chargement de la configuration

void Dialog::on_pbuLoadModbusConf_clicked()
{
    QString	fileName = QFileDialog::getOpenFileName(
        this,
        tr("Ouvrir..."),
        m_configDir,
        tr("Configuration Modbus (*.csv)") ) ;
    if ( !fileName.isEmpty() ) {
        // mémorisation du répertoire source utilisé
        m_configDir = QFileInfo( fileName ).absolutePath() ;
#ifdef Q_OS_MAC
        m_configDir = m_configDir + QDir::separator() + "*" ;
#endif
        // configuration du serveur métier
        m_modbusMap->loadMap( fileName ) ;
        edtPort->setText( QString("%1").arg( m_modbusMap->port() ) ) ;
        // initialisation du visualiseur
        mapView->setModbusMap( m_modbusMap ) ;
        // création du serveur TCP
        m_tcpServer = new QamTcpServer(m_modbusMap, this ) ;
        // actualisation UI
        pbuStartServer->setEnabled( true ) ;
        pbuLoadModbusConf->setEnabled( false ) ;
    }
}

// démarrage du service

void Dialog::on_pbuStartServer_clicked()
{
    m_isRunning = !m_isRunning ;
    pbuStartServer->setText( m_isRunning ? "Stop" : "Start" ) ;

    if ( m_isRunning ) {
        // demandes de connexion acceptée
        m_tcpServer->start( edtPort->text().toUShort() ) ;
        edtPort->setEnabled( false ) ;
    }
    else {
        // nouvelles demandes ignorées
        m_tcpServer->close() ;
        edtPort->setEnabled( true ) ;
    }
}

// traitement des requêtes du maitre Modbus

void Dialog::modbusValueChanged(int table,const QString& name )
{
    // bit D_Mon = 1 ?

    if (( (QamModbusMap::PrimaryTable)table == QamModbusMap::Coil )&&( name == "D_Mon" )) {

        if ( m_modbusMap->localValue( QamModbusMap::Coil, "D_Mon" ).toInt() ) {

            // activation mode montage
            m_AssemblyMode = true ;
            ledAssembly->on() ;
            ledDisassembly->off() ;

            // init. indicateurs
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Mon", "0" ) ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Dem", "0" ) ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Ok", "0" ) ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "0" ) ;
            ledBusy->on() ;
            ledDefault->off() ;

            // récupération numéro/orientation pièce
            // l'orientation est codée sur 2 bits, pas de test d'intervalle nécessaire...
            int num = m_modbusMap->localValue( QamModbusMap::HoldingRegister, "D_Tab_Num" ).toInt() ;
            int ori = m_modbusMap->localValue( QamModbusMap::HoldingRegister, "D_Tab_Ori" ).toInt() ;

            if (( num < 0 )||( num >= ( m_puzzleCols * m_puzzleRows ) )) {
                modbusError("ERROR", "Invalid piece number!") ;
                if ( !m_simulation )    trashCycle() ;
                return ;
            }

            m_pieceNum = num ;
            m_pieceOri = ori ;

            if ( puzzle->isCompleted() ) {
                modbusError("ERROR", "Puzzle already completed!") ;
//                m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "1" ) ;		// - v1.2
                if ( m_simulation ) startAnimation() ;
                else                trashCycle() ;
                return ;
            }

            if ( !puzzle->isPositionFree(m_pieceNum ) ) {
                modbusError("ERROR", "Piece requested location not free!") ;
//                m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "1" ) ;		// - v1.2
                if ( m_simulation ) startAnimation() ;
                else                trashCycle() ;
                return ;
            }

            // transfert piece palette -> puzzle
            if ( m_simulation ) startAnimation() ;
            else                assemblyCycle() ;
        }
    }

    // bit D_Dem = 1 ?

    if (( (QamModbusMap::PrimaryTable)table == QamModbusMap::Coil )&&( name == "D_Dem" )) {

        if ( m_modbusMap->localValue( QamModbusMap::Coil, "D_Dem" ).toInt() ) {

            // activation mode démontage
            m_AssemblyMode = false ;
            ledDisassembly->on() ;
            ledAssembly->off() ;

            // init. indicateurs
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Mon", "0" ) ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Dem", "0" ) ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Ok", "0" ) ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "0" ) ;
            ledBusy->on() ;
            ledDefault->off() ;

            if ( puzzle->isEmpty() ) {
                modbusError("ERROR", "No more available piece!") ;
                m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "1" ) ;
                ledBusy->off() ;
                ledDefault->on() ;
                return ;
            }

            // sélection aléatoire d'une pièce et de son orientation
            m_pieceNum = puzzle->nextBusyPositionFrom( qrand() % ( m_puzzleCols * m_puzzleRows ) ) ;
            m_pieceOri = qrand() % 4 ;

            m_modbusMap->setLocalValue( QamModbusMap::HoldingRegister, "D_Tab_Num", QString("%1").arg(m_pieceNum) ) ;
            m_modbusMap->setLocalValue( QamModbusMap::HoldingRegister, "D_Tab_Ori", QString("%1").arg(m_pieceOri) ) ;

            // transfert pièce puzzle -> palette
            if ( m_simulation ) startAnimation() ;
            else                disassemblyCycle() ;
        }
    }

    // modification du mot D_Loc ?

    if (( (QamModbusMap::PrimaryTable)table == QamModbusMap::HoldingRegister )&&( name == "D_Loc" )) {

        int num = m_modbusMap->localValue( QamModbusMap::HoldingRegister, "D_Tab_Num" ).toInt() ;
        int ori = m_modbusMap->localValue( QamModbusMap::HoldingRegister, "D_Tab_Ori" ).toInt() ;
        initAnimation(num, ori ) ;
    }

}

// ---------------------------------------------------------------------------
// cycles automatiques (n.u. en mode simulation)
// ---------------------------------------------------------------------------

void Dialog::assemblyCycle()
{
    float   oriBegin = rotationByName( QString("Pa_to_Pu_%1").arg( m_pieceOri ), 1 ).toFloat() ;
    float   oriEnd   = rotationByName( QString("Pa_to_Pu_%1").arg( m_pieceOri ), 2 ).toFloat() ;
    QString puPiece  = QString("Pu_%1%2").arg( m_pieceNum / 10 ).arg( m_pieceNum % 10 ) ;

    if ( !openGripper() )                   { defaultInCycle() ; return ; }
    if ( !gotoPoint("Pa_Mon", oriBegin ) )  { defaultInCycle() ; return ; }
    if ( !goDown() )                        { defaultInCycle() ; return ; }
    if ( !closeGripper() )                  { defaultInCycle() ; return ; }
    if ( !goUp() )                          { defaultInCycle() ; return ; }

    if ( !gotoPoint( puPiece, oriEnd ) )    { defaultInCycle() ; return ; }
    if ( !goDown() )                        { defaultInCycle() ; return ; }
    if ( !openGripper() )                   { defaultInCycle() ; return ; }
    if ( !goUp() )                          { defaultInCycle() ; return ; }

    if ( !gotoPoint("PWait" ) )             { defaultInCycle() ; return ; }

    m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Ok", "1" ) ;

    if ( puzzle->isPositionFree(m_pieceNum ) )  puzzle->addPiece( m_pieceNum ) ;
    m_labImgPalette->setPixmap( QPixmap() ) ;

    ledBusy->off() ;
}

void Dialog::disassemblyCycle()
{
    float   oriBegin = rotationByName( QString("Pa_to_Pu_%1").arg( m_pieceOri ), 2 ).toFloat() ;
    float   oriEnd   = rotationByName( QString("Pa_to_Pu_%1").arg( m_pieceOri ), 1 ).toFloat() ;
    QString puPiece  = QString("Pu_%1%2").arg( m_pieceNum / 10 ).arg( m_pieceNum % 10 ) ;

    if ( !openGripper() )                   { defaultInCycle() ; return ; }
    if ( !gotoPoint( puPiece, oriBegin ) )  { defaultInCycle() ; return ; }
    if ( !goDown() )                        { defaultInCycle() ; return ; }
    if ( !closeGripper() )                  { defaultInCycle() ; return ; }
    if ( !goUp() )                          { defaultInCycle() ; return ; }

    puzzle->removePiece(m_pieceNum ) ;

    if ( !gotoPoint("Pa_Dem", oriEnd ) )    { defaultInCycle() ; return ; }
    if ( !goDown() )                        { defaultInCycle() ; return ; }
    if ( !openGripper() )                   { defaultInCycle() ; return ; }
    if ( !goUp() )                          { defaultInCycle() ; return ; }

    if ( !gotoPoint("PWait" ) )             { defaultInCycle() ; return ; }

    m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Ok", "1" ) ;

    ledBusy->off() ;
}

void Dialog::trashCycle()
{
//    m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "1" ) ;		// - v1.2
    ledDefault->on() ;

    if ( !openGripper() )         { defaultInCycle() ; return ; }
    if ( !gotoPoint("Pa_Mon" ) )  { defaultInCycle() ; return ; }
    if ( !goDown() )              { defaultInCycle() ; return ; }
    if ( !closeGripper() )        { defaultInCycle() ; return ; }
    if ( !goUp() )                { defaultInCycle() ; return ; }

    if ( !gotoPoint("PTrash" ) )  { defaultInCycle() ; return ; }
    if ( !openGripper() )         { defaultInCycle() ; return ; }
    if ( !gotoPoint("PWait" ) )   { defaultInCycle() ; return ; }

    m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "1" ) ;		// + v1.2

    ledBusy->off() ;
}

void Dialog::defaultInCycle()
{
    m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Ok", "0" ) ;

    // TODO: coil dédié ou D_Def_Num ??
    m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "1" ) ;

    ledDefault->on() ;
    ledBusy->off() ;
}

// ---------------------------------------------------------------------------
// animation graphique
// ---------------------------------------------------------------------------

// initialise le contenu de la vignette

void Dialog::initAnimation(int num, int ori )
{
    int indl = num / m_puzzleCols ;    // indice ligne
    int indc = num % m_puzzleCols ;    // indice colonne
    QString imgName = QString(":/puzzle/images/%1%2.png").arg( QChar( 'A' + indc ) ).arg( indl + 1 ) ;
    QImage  img( imgName ) ;
    img = img.scaled( labImgPalette->width(), labImgPalette->height() ) ;
    QMatrix matrix ;
    matrix.rotate( ori * 90 ) ;
    img = img.transformed( matrix ) ;

    m_labImgPalette->setGeometry( m_imgRect ) ;
    m_labImgPalette->setPixmap( QPixmap::fromImage(img) ) ;
    m_labImgPalette->setScaledContents( true ) ;
    
//    m_labImgPalette->repaint() ;	// ? v1.2 ???? to be tested
}

// démarre l'animation de la vignette : palette <--> puzzle (mode simulation uniquement)

void Dialog::startAnimation()
{
    m_animation->setDuration( 1500 ) ;

    QRect rPalette = m_imgRect ;
    QRect rPiece = puzzle->pieceRect( m_pieceNum ) ;

    QRect rPuzzle ;
    rPuzzle.setTopLeft( puzzle->pos() +  rPiece.topLeft() ) ;
    rPuzzle.setWidth( rPiece.width() );
    rPuzzle.setHeight( rPiece.height() );

    if ( m_AssemblyMode ) {
        if ( !puzzle->isPositionFree(m_pieceNum ) ) {   // to trash...
            rPuzzle = rPalette ;
            rPuzzle.setTopLeft( rPalette.bottomRight() ) ;
        }
        m_animation->setStartValue( rPalette ) ;
        m_animation->setEndValue( rPuzzle ) ;
    }
    else {
        m_animation->setStartValue( rPuzzle ) ;
        m_animation->setEndValue( rPalette ) ;
        puzzle->removePiece(m_pieceNum ) ;
    }
    m_animation->start() ;
}

// slot d'interception de fin de l'animation (mode simulation uniquement)

void Dialog::animationEnded()
{
    if ( m_AssemblyMode ) {
        if ( puzzle->isPositionFree(m_pieceNum ) ) {
            puzzle->addPiece( m_pieceNum ) ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Ok", "1" ) ;
        }
        else {
            ledDefault->on() ;
            m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Def_Num", "1" ) ;
        }
        m_labImgPalette->setPixmap( QPixmap() ) ;
    }
    else {
        m_modbusMap->setLocalValue( QamModbusMap::Coil, "D_Ok", "1" ) ;
    }
    ledBusy->off() ;
}

// ---------------------------------------------------------------------------
// initialisation (forcée) du puzzle
// ---------------------------------------------------------------------------

void Dialog::on_pbuClean_clicked()
{
    puzzle->fill( false ) ;
}

void Dialog::on_pbuFill_clicked()
{
    puzzle->fill( true ) ;
}


// ---------------------------------------------------------------------------
// remontée des messages d'info/erreur
// ---------------------------------------------------------------------------

void Dialog::modbusInfo(const QString& source, const QString& message )
{
    showPrompt( edtModbusInfo, source.leftJustified( 6, ' ', true) + ": ") ;
    showMessage( edtModbusInfo, message + "\n", false, Qt::darkGray  ) ;
}

void Dialog::modbusError(const QString& source, const QString& message )
{
    showPrompt( edtModbusInfo, source.leftJustified( 6, ' ', true) + ": ") ;
    showMessage( edtModbusInfo, message + "\n", false, Qt::darkRed  ) ;
}

void Dialog::showPrompt(QTextEdit* edtInfo, const QString& prompt )
{
	edtInfo->moveCursor(QTextCursor::End ) ;
	edtInfo->setTextColor( Qt::darkGray ) ;
	edtInfo->setFontWeight( QFont::Normal ) ;
	edtInfo->insertPlainText( prompt ) ;
	edtInfo->moveCursor(QTextCursor::End ) ;
}

void Dialog::showMessage(QTextEdit* edtInfo, const QString& msg, bool bold, QColor color )
{
	edtInfo->moveCursor(QTextCursor::End ) ;
	edtInfo->setTextColor( color ) ;
	edtInfo->setFontWeight( bold ? QFont::Bold : QFont::Normal ) ;
	edtInfo->insertPlainText( msg ) ;
	edtInfo->moveCursor(QTextCursor::End ) ;
    edtInfo->repaint() ;
}
