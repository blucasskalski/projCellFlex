#include "cc3.h"
#include <QMessageBox>
#include <QFileDialog>



CC3::CC3(QWidget *parent)
    : QMainWindow(parent)

{
    setupUi(this);

    QSize CC3 = this->sizeHint();
    this->setMaximumSize(CC3);

    connect(pbuReset, SIGNAL(clicked()), this, SLOT(Reset()));

    connect(pbuPince, SIGNAL(clicked()), this, SLOT(Pince()));
    connect(pbuVerver, SIGNAL(clicked()), this, SLOT(Verver()));
    connect(pbuVerhori, SIGNAL(clicked()), this, SLOT(Verhori()));
    connect(pbuMoteur1, SIGNAL(clicked()), this, SLOT(Moteur1()));
    connect(pbuMoteur2, SIGNAL(clicked()), this, SLOT(Moteur2()));
    connect(pbuVersT2, SIGNAL(clicked()), this, SLOT(TransfertVersT2()));
    connect(pbuVersT1, SIGNAL(clicked()), this, SLOT(TransfertVersT1()));

    connect(piece, SIGNAL(clicked()), this, SLOT(Piece1()));
    connect(piece_2, SIGNAL(clicked()), this, SLOT(Piece2()));
    connect(piece_3, SIGNAL(clicked()), this, SLOT(Piece3()));
    connect(piece_4, SIGNAL(clicked()), this, SLOT(Piece4()));
    connect(piece_5, SIGNAL(clicked()), this, SLOT(Piece5()));
    connect(piece_6, SIGNAL(clicked()), this, SLOT(Piece6()));
    connect(piece_7, SIGNAL(clicked()), this, SLOT(Piece7()));
    connect(piece_8, SIGNAL(clicked()), this, SLOT(Piece8()));
    connect(piece_9, SIGNAL(clicked()), this, SLOT(Piece9()));
    connect(piece_10, SIGNAL(clicked()), this, SLOT(Piece10()));
    connect(piece_11, SIGNAL(clicked()), this, SLOT(Piece11()));
    connect(piece_12, SIGNAL(clicked()), this, SLOT(Piece12()));
    connect(piece_13, SIGNAL(clicked()), this, SLOT(Piece13()));
    connect(piece_14, SIGNAL(clicked()), this, SLOT(Piece14()));
    connect(piece_15, SIGNAL(clicked()), this, SLOT(Piece15()));
    connect(piece_16, SIGNAL(clicked()), this, SLOT(Piece16()));
    connect(piece_17, SIGNAL(clicked()), this, SLOT(Piece17()));
    connect(piece_18, SIGNAL(clicked()), this, SLOT(Piece18()));
    connect(piece_19, SIGNAL(clicked()), this, SLOT(Piece19()));
    connect(piece_20, SIGNAL(clicked()), this, SLOT(Piece20()));

    connect(buteA, SIGNAL(stateChanged(int)), this, SLOT(ButeA(int)));
    connect(buteV, SIGNAL(stateChanged(int)), this, SLOT(ButeV(int)));
    connect(buteS, SIGNAL(stateChanged(int)), this, SLOT(ButeS(int)));
    connect(buteAtt, SIGNAL(stateChanged(int)), this, SLOT(ButeS(int)));


    pbuReadAll->setEnabled( false ) ;
    pbuRead->setEnabled( false ) ;

    readSettings() ;	// chargement configuration session précédente

    // Cartographie Modbus
    for(int i = 0 ; i < 3 ; i++)
    {
        map[i] = new QamModbusMap(QamModbusMap::ClientMode, this);
        map[i]->setVerbose(false);
        connect(map[i], SIGNAL(info(QString, QString)), this, SLOT(info(QString, QString)));
    }

    // Client TCP
    for(int i = 0 ; i < 3 ; i++)
        tcpClient[i] = new QamTcpClient(map[i], this);

    for(int i = 0 ; i < 3 ; i++)
        tcpClientOk[i] = false;

}

CC3::~CC3()
{
    delete ui;

}


// fermeture -> sauvegarde de la configuration courante

void CC3::closeEvent(QCloseEvent* event )
{
    writeSettings() ;
    event->accept() ;
}

// référencement d'un nouveau serveur

void CC3::on_pbuNew_clicked()
{
    /* QString	fileName = QFileDialog::getOpenFileName(
        this,
        tr("Ouvrir..."),
        m_configDir,
        tr("Configuration Modbus (*.csv)") ) ; */

        // mémorisation du répertoire source utilisé
        m_configDir = QFileInfo( csv1 ).absolutePath() ;
        //m_configDir = QFileInfo( csv2 ).absolutePath() ;
        //m_configDir = QFileInfo( csv3 ).absolutePath() ;

        // configuration du serveur métier

        QamModbusMap* map = new QamModbusMap(QamModbusMap::ClientMode, this ) ;
        QamTcpClient* client = new QamTcpClient(map, this ) ;
        QamModbusMapViewer* viewer = new QamModbusMapViewer( this ) ;

        connect( map, SIGNAL(info(QString,QString)),
                 this, SLOT(info(QString,QString)) ) ;

        map->loadMap( csv1 ) ;
        //map->loadMap( csv2 ) ;
        //map->loadMap( csv3 ) ;
        // map->loadMap( fileName ) ;
        viewer->setModbusMap( map ) ;

        m_modbusMap << map ;
        m_tcpCLient << client ;
        m_modbusMapViewer << viewer ;

        // création nouvel onglet

        int i = tabWidget->addTab(m_modbusMapViewer.last(), map->description() ) ;

//		tabWidget->setTabToolTip( i, map->host() + ":" + QString("%1").arg( map->port() ) ) ;	// new 1.1
        edtHost->setText( map->host() ) ;
        edtPort->setText( QString("%1").arg( map->port() ) ) ;

        tabWidget->setCurrentIndex( i ) ;
}

// connexion on/off au serveur (pour l'onglet actif)

void CC3::on_pbuConnect_clicked()
{
    int index = tabWidget->currentIndex() ;

    bool connected = m_tcpCLient.at( index )->state() == QAbstractSocket::ConnectedState ;
    if ( connected ) {

        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "CC1_CC2", "0" );
        m_modbusMap.at(i)->setValue(table, "CC1_A_Pom", "0" );

        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Air_On", "0" );
        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Power_On", "0" );
        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Aru", "1" );

        m_tcpCLient.at( index )->sockClose() ;
        pbuConnect->setText("Connection") ;
        pbuReadAll->setEnabled( false ) ;
        pbuRead->setEnabled( false ) ;

        edtHost->setEnabled( true ) ;	// new 1.1
        edtPort->setEnabled( true ) ;
        //labHost->setEnabled( true ) ;
        //labPort->setEnabled( true ) ;
        m_modbusMap.at(i)->setValue(table, "CC1_A_Pom", "1" );
    }
    else {
//		QString host = m_modbusMap.at( index )->host() ;	// new 1.1
//		quint16 port = m_modbusMap.at( index )->port() ;
        QString host = edtHost->text() ;
        quint16 port = edtPort->text().toUInt() ;

        m_tcpCLient.at( index )->sockConnect(host, port ) ;
        if ( m_tcpCLient.at( index )->waitForConnected(3000) ) {
            pbuConnect->setText("Déconnection") ;
            pbuReadAll->setEnabled( true ) ;
            pbuRead->setEnabled( true ) ;

            edtHost->setEnabled( false ) ;					// new 1.1
            edtPort->setEnabled( false ) ;
            //labHost->setEnabled( false ) ;
            //labPort->setEnabled( false ) ;

            int i = tabWidget->currentIndex() ;
            QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
            m_modbusMap.at(i)->setValue(table, "CC1_CC2", "1" );
            m_modbusMap.at(i)->setValue(table, "CC1_A_Pom", "1" );

            m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Aru", "1" );
            sleep(1);
            m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Aru", "0" );

            m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Power_On", "1" );
            sleep(1);
            m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Power_On", "0" );

            m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Air_On", "1" );

        }
        else {												// new 1.1
            info("tcp/ip", "Connection failed!" ) ;
        }
    }
}

// RAZ de toutes les valeurs (cartographie locale)

void CC3::on_pbuReset_clicked()
{
    int i = tabWidget->currentIndex() ;
    if ( i < 0 )	return ;

    QamModbusMap::PrimaryTable	table ;

    table = QamModbusMap::Coil ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        m_modbusMap.at(i)->setLocalValue(table, name, "0" ) ;
    }
    table = QamModbusMap::DiscretInput ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        m_modbusMap.at(i)->setLocalValue(table, name, "0" ) ;
    }
    table = QamModbusMap::InputRegister ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        QString display = m_modbusMap.at(i)->display(table, name ) ;
        QString value = "0" ;
        if ( display == "Ascii" )	value = "" ;
        if (( display == "Str8" )||( display == "Str16" ))		value = "" ;
        m_modbusMap.at(i)->setLocalValue(table, name, value ) ;
    }
    table = QamModbusMap::HoldingRegister ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        QString display = m_modbusMap.at(i)->display(table, name ) ;
        QString value = "0" ;
        if ( display == "Ascii" )	value = "" ;
        if (( display == "Str8" )||( display == "Str16" ))		value = "" ;
        m_modbusMap.at(i)->setLocalValue(table, name, value ) ;
    }

}

// demande d'actualisation de toutes les données
// par interrogations du serveur

void CC3::on_pbuReadAll_clicked()
{
    int i = tabWidget->currentIndex() ;
    if ( i < 0 )	return ;

    QamModbusMap::PrimaryTable	table ;

    table = QamModbusMap::Coil ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        m_modbusMap.at(i)->remoteValue(table, name ) ;
    }
    table = QamModbusMap::DiscretInput ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        m_modbusMap.at(i)->remoteValue(table, name ) ;
    }
    table = QamModbusMap::InputRegister ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        m_modbusMap.at(i)->remoteValue(table, name ) ;
    }
    table = QamModbusMap::HoldingRegister ;
    foreach(QString name, m_modbusMap.at(i)->nameList( table ) ) {
        m_modbusMap.at(i)->remoteValue(table, name ) ;
    }
}

// demande d'actualisation de la donnée sélectionnée
// par interrogation du serveur

void CC3::on_pbuRead_clicked()
{
    int i = tabWidget->currentIndex() ;

    int table = m_modbusMapViewer.at(i)->currentTable() ;
    if ( table == -1 )	return ;
    QString name = m_modbusMapViewer.at(i)->currentName() ;

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, name ) ;
}

// changement d'onglet

void CC3::on_tabWidget_currentChanged(int index )
{
    bool connected = m_tcpCLient.at( index )->state() == QAbstractSocket::ConnectedState ;
    pbuConnect->setText( connected ? "Close" : "Connexion" ) ;
    pbuConnect->setEnabled( true ) ;
    pbuReadAll->setEnabled( connected ) ;
    pbuRead->setEnabled( connected ) ;

    edtHost->setText( m_modbusMap.at( index )->host() ) ;						// new 1.1
    edtPort->setText( QString("%1").arg( m_modbusMap.at( index )->port() ) ) ;
    edtHost->setEnabled( !connected ) ;
    edtPort->setEnabled( !connected ) ;
    //labHost->setEnabled( !connected ) ;
    //labPort->setEnabled( !connected ) ;
}

// suppression d'un référencement serveur

void CC3::on_tabWidget_tabCloseRequested(int index )
{
    bool connected = m_tcpCLient.at( index )->state() == QAbstractSocket::ConnectedState ;	// new 1.1
    if ( connected ) m_tcpCLient.at( index )->sockClose() ;

    m_tcpCLient.removeAt( index ) ;

    m_modbusMapViewer.removeAt( index ) ;
    m_modbusMap.removeAt( index ) ;

    tabWidget->removeTab( index ) ;

    if ( tabWidget->count() == 0 ) {		// new 1.1
        edtHost->setText( "" ) ;
        edtPort->setText( "" ) ;
    }
}

// gestion de la configuration inter-sessions

void CC3::readSettings()
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "modipmanager" ) ;

    QPoint	pos = settings.value("MainWindow/pos", QPoint(10,10) ).toPoint() ;
    QSize	size = settings.value("MainWindow/size", QSize(640,480) ).toSize() ;
    resize( size ) ;
    move( pos ) ;

    QString ld = QDir::homePath() ;

    m_configDir = settings.value("Files/configDir", ld ).toString() ;
}

void CC3::writeSettings()
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "modipmanager" ) ;

    settings.setValue("MainWindow/pos", pos() ) ;
    settings.setValue("MainWindow/size", size() ) ;
    settings.setValue("Files/configDir", m_configDir ) ;
}

// remontée des messages d'info.

void CC3::info(const QString& source, const QString& message )
{
    showPrompt( source + ": ") ;
    showMessage( message + "\n", false, Qt::darkGray  ) ;
}

void CC3::valueChanged(int table,const QString& name )
{
    showPrompt( "value : ") ;
    showMessage( QamModbusMap::tableAsString( (QamModbusMap::PrimaryTable)table ) + " / " + name + " changed\n", false, Qt::darkRed  ) ;
}

void CC3::showPrompt(const QString& prompt )
{
    edtDialog->moveCursor(QTextCursor::End ) ;
    edtDialog->setTextColor( Qt::darkGray ) ;
    edtDialog->setFontWeight( QFont::Normal ) ;
    edtDialog->insertPlainText( prompt ) ;
    edtDialog->moveCursor(QTextCursor::End ) ;
}

void CC3::showMessage(const QString& msg, bool bold, QColor color )
{
    edtDialog->moveCursor(QTextCursor::End ) ;
    edtDialog->setTextColor( color ) ;
    edtDialog->setFontWeight( bold ? QFont::Bold : QFont::Normal ) ;
    edtDialog->insertPlainText( msg ) ;
    edtDialog->moveCursor(QTextCursor::End ) ;

}
