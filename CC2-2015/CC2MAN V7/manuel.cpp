#include "manuel.h"
#include <QMessageBox>
#include <QFileDialog>

manuel::manuel(QWidget *parent)
    : QMainWindow(parent)

{
    setupUi(this);

    QSize manuel = this->sizeHint();
    this->setMaximumSize(manuel);
    connect(pbuPinceOuverte, SIGNAL(clicked()), this, SLOT(PinceOuverte()));
    connect(pbuPinceFerme, SIGNAL(clicked()), this, SLOT(PinceFerme()));
    connect(pbuMonter, SIGNAL(clicked()), this, SLOT(Monter()));
    connect(pbuDescendre, SIGNAL(clicked()), this, SLOT(Descendre()));
    connect(pbuVersPalette, SIGNAL(clicked()), this, SLOT(VersPalette()));
    connect(pbuVersTable, SIGNAL(clicked()), this, SLOT(VersTable()));
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
    connect(buteAtt, SIGNAL(stateChanged(int)), this, SLOT(ButeAtt(int)));
    connect(pbuReset, SIGNAL(clicked()), this, SLOT(Reset()));
    connect(pbuAuto, SIGNAL(clicked()), this, SLOT(Auto()));
    connect(pbuPom, SIGNAL(clicked()), this, SLOT(Pom()));



#ifdef Q_OS_MAC
    edtDialog->setFont( QFont("Monaco", 12 ) ) ;
#else
    edtDialog->setFont( QFont("Courier", 10 ) ) ;
#endif

    pbuReadAll->setEnabled( false ) ;
    //pbuRead->setEnabled( false ) ;

    readSettings() ;	// chargement configuration session précédente


    //chargement csv automatique//
    QString	fileName =  "/home/cellflex-cc2/Bureau/CC2MAN V6/CC2MAN/csv/cellflex_api.csv";
    QString	fileName2 =  "/home/cellflex-cc2/Bureau/CC2MAN V6/CC2MAN/csv/cellflex_scara.csv";
    QString	fileName3 =  "/home/cellflex-cc2/Bureau/CC2MAN V6/CC2MAN/csv/cellflex_vision.csv";


     if ( !fileName.isEmpty()) {
          //mémorisation du répertoire source utilisé
         m_configDir = QFileInfo( fileName ).absolutePath() ;
 #ifdef Q_OS_MAC
        m_configDir = m_configDir + QDir::separator() + "*" ;
 #endif
         // configuration du serveur métier



         QamModbusMap* map = new QamModbusMap(QamModbusMap::ClientMode, this ) ;
         QamTcpClient* client = new QamTcpClient(map, this ) ;
         QamModbusMapViewer* viewer = new QamModbusMapViewer( this ) ;

         connect( map, SIGNAL(info(QString,QString)),
                  this, SLOT(info(QString,QString)) ) ;



         map->loadMap( fileName ) ;
         viewer->setModbusMap( map ) ;

         m_modbusMap << map ;
         m_tcpCLient << client ;
         m_modbusMapViewer << viewer ;

         // création nouvel onglet

         int i = tabWidget->addTab(m_modbusMapViewer.last(), map->description() ) ;



         tabWidget->setTabToolTip( i, map->host() + ":" + QString("%1").arg( map->port() ) ) ;	// new 1.1
         //edtHost->setText( map->host() ) ;
         //edtPort->setText( QString("%1").arg( map->port() ) ) ;

         tabWidget->setCurrentIndex( i ) ;
     }

     if ( !fileName2.isEmpty()) {
          //mémorisation du répertoire source utilisé
         m_configDir = QFileInfo( fileName2 ).absolutePath() ;
 #ifdef Q_OS_MAC
        m_configDir = m_configDir + QDir::separator() + "*" ;
 #endif
         // configuration du serveur métier



         QamModbusMap* map = new QamModbusMap(QamModbusMap::ClientMode, this ) ;
         QamTcpClient* client = new QamTcpClient(map, this ) ;
         QamModbusMapViewer* viewer = new QamModbusMapViewer( this ) ;

         connect( map, SIGNAL(info(QString,QString)),
                  this, SLOT(info(QString,QString)) ) ;



         map->loadMap( fileName2 ) ;
         viewer->setModbusMap( map ) ;

         m_modbusMap << map ;
         m_tcpCLient << client ;
         m_modbusMapViewer << viewer ;

         // création nouvel onglet

         int i = tabWidget->addTab(m_modbusMapViewer.last(), map->description() ) ;



         tabWidget->setTabToolTip( i, map->host() + ":" + QString("%1").arg( map->port() ) ) ;	// new 1.1
         //edtHost->setText( map->host() ) ;
         //edtPort->setText( QString("%1").arg( map->port() ) ) ;




     }

     if ( !fileName3.isEmpty()) {
          //mémorisation du répertoire source utilisé
         m_configDir = QFileInfo( fileName3 ).absolutePath() ;
 #ifdef Q_OS_MAC
        m_configDir = m_configDir + QDir::separator() + "*" ;
 #endif
         // configuration du serveur métier



         QamModbusMap* map = new QamModbusMap(QamModbusMap::ClientMode, this ) ;
         QamTcpClient* client = new QamTcpClient(map, this ) ;
         QamModbusMapViewer* viewer = new QamModbusMapViewer( this ) ;

         connect( map, SIGNAL(info(QString,QString)),
                  this, SLOT(info(QString,QString)) ) ;



         map->loadMap( fileName3 ) ;
         viewer->setModbusMap( map ) ;

         m_modbusMap << map ;
         m_tcpCLient << client ;
         m_modbusMapViewer << viewer ;

         // création nouvel onglet

         int i = tabWidget->addTab(m_modbusMapViewer.last(), map->description() ) ;



         tabWidget->setTabToolTip( i, map->host() + ":" + QString("%1").arg( map->port() ) ) ;	// new 1.1
         //edtHost->setText( map->host() ) ;
         //edtPort->setText( QString("%1").arg( map->port() ) ) ;




     }


     //fin chargement csv//
}

manuel::~manuel()
{
    delete ui;

}


// fermeture -> sauvegarde de la configuration courante

void manuel::closeEvent(QCloseEvent* event )
{
    writeSettings() ;
    event->accept() ;
}


// connexion on/off au serveur (pour l'onglet actif)

void manuel::on_pbuConnect_clicked()
{
    int index = 0 ;
    int index2 = 1;
    int index3 = 2;

    bool connected = m_tcpCLient.at( index )->state() == QAbstractSocket::ConnectedState ;


    if ( connected ) {

        int i = 0 ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "CC1_CC2", "0" );


        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Air_On", "0" );
        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Power_On", "0" );
        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Aru", "1" );

        m_tcpCLient.at( index )->sockClose() ;
        m_tcpCLient.at( index2 )->sockClose() ;
        m_tcpCLient.at( index3 )->sockClose() ;
        pbuConnect->setText("Demarrer") ;
        pbuReadAll->setEnabled( false ) ;
        //pbuRead->setEnabled( false ) ;

        //edtHost->setEnabled( true ) ;	// new 1.1
        //edtPort->setEnabled( true ) ;
        //labHost->setEnabled( true ) ;
       // labPort->setEnabled( true ) ;
        pbuPom->setEnabled( false) ;
        pbuMoteur1->setEnabled( false ) ;
        pbuMoteur2->setEnabled( false ) ;
        pbuMonter->setEnabled( false ) ;
        pbuDescendre->setEnabled( false ) ;
        pbuPinceFerme->setEnabled( false ) ;
        pbuPinceOuverte->setEnabled( false ) ;
        pbuVersPalette->setEnabled( false ) ;
        pbuVersTable->setEnabled( false ) ;
        pbuVersT1->setEnabled( false ) ;
        pbuVersT2->setEnabled( false ) ;
        buteA->setEnabled( false ) ;
        buteS->setEnabled( false ) ;
        buteV->setEnabled( false ) ;
        buteAtt->setEnabled( false ) ;
        pbuReset->setEnabled( false) ;
        pbuAuto->setEnabled( false) ;
        pbuPom->setEnabled( false) ;
        piece->setEnabled( false) ;
        piece_2->setEnabled( false) ;
        piece_3->setEnabled( false) ;
        piece_4->setEnabled( false) ;
        piece_5->setEnabled( false) ;
        piece_6->setEnabled( false) ;
        piece_7->setEnabled( false) ;
        piece_8->setEnabled( false) ;
        piece_9->setEnabled( false) ;
        piece_10->setEnabled( false) ;
        piece_11->setEnabled( false) ;
        piece_12->setEnabled( false) ;
        piece_13->setEnabled( false) ;
        piece_14->setEnabled( false) ;
        piece_15->setEnabled( false) ;
        piece_16->setEnabled( false) ;
        piece_17->setEnabled( false) ;
        piece_18->setEnabled( false) ;
        piece_19->setEnabled( false) ;
        piece_20->setEnabled( false) ;

    }

    else {

        QString host = "192.168.3.3" ;
        quint16 port = 502 ;

        QString host2 = "192.168.3.7" ;
        quint16 port2 = 502 ;

        QString host3 = "192.168.3.5" ;
        quint16 port3 = 502 ;


       m_tcpCLient.at(index)->sockConnect(host, port ) ;
       m_tcpCLient.at( index2 )->sockConnect(host2, port2 ) ;
       m_tcpCLient.at( index3)->sockConnect(host3, port3 ) ;

        if ( m_tcpCLient.at(index)->waitForConnected(3000) )  /*&& ( m_tcpCLient.at(index2)->waitForConnected(3000) ) && ( m_tcpCLient.at(index3)->waitForConnected(3000) ))*/{
            pbuConnect->setText("Arrêter") ;

            //pbuRead->setEnabled( true ) ;
           // edtHost->setEnabled( false ) ;					// new 1.1
            //edtPort->setEnabled( false ) ;
            //labHost->setEnabled( false ) ;
            //labPort->setEnabled( false ) ;
            pbuPom->setEnabled( true ) ;
            pbuReadAll->setEnabled(true);
            pbuPom->setEnabled(true);
            pbuMoteur1->setEnabled( true ) ;
            pbuMoteur2->setEnabled( true ) ;
            pbuMonter->setEnabled( true ) ;
            pbuDescendre->setEnabled( true ) ;
            pbuPinceFerme->setEnabled( true ) ;
            pbuPinceOuverte->setEnabled( true ) ;
            pbuVersPalette->setEnabled( true ) ;
            pbuVersTable->setEnabled( true ) ;
            pbuVersT1->setEnabled( true ) ;
            pbuVersT2->setEnabled( true ) ;
            buteA->setEnabled( true ) ;
            buteS->setEnabled( true ) ;
            buteV->setEnabled( true ) ;
            buteAtt->setEnabled( true ) ;
            pbuReset->setEnabled( true ) ;
            pbuAuto->setEnabled( true );
            piece->setEnabled( true) ;
            piece_2->setEnabled( true) ;
            piece_3->setEnabled( true) ;
            piece_4->setEnabled( true) ;
            piece_5->setEnabled( true) ;
            piece_6->setEnabled( true) ;
            piece_7->setEnabled( true) ;
            piece_8->setEnabled( true) ;
            piece_9->setEnabled( true) ;
            piece_10->setEnabled( true) ;
            piece_11->setEnabled( true) ;
            piece_12->setEnabled( true) ;
            piece_13->setEnabled( true) ;
            piece_14->setEnabled( true) ;
            piece_15->setEnabled( true) ;
            piece_16->setEnabled( true) ;
            piece_17->setEnabled( true) ;
            piece_18->setEnabled( true) ;
            piece_19->setEnabled( true) ;
            piece_20->setEnabled( true) ;
            pbuPom->setEnabled( true) ;

            int i = 0 ;
            QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
            m_modbusMap.at(i)->setValue(table, "CC1_CC2", "1" );


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
            QString listServeur;

                if (!m_tcpCLient.at(index)->waitForConnected(1000))
                {
                    listServeur += "\n";
                    listServeur += m_modbusMap.at(0)->host() + ":" + QString::number(m_modbusMap.at(0)->port()) + " )" ;
                }


                if (!m_tcpCLient.at(index2)->waitForConnected(1000))
                {
                    listServeur += "\n";
                    listServeur += m_modbusMap.at(1)->host() + ":" + QString::number(m_modbusMap.at(1)->port()) + " )" ;
                }

                if (!m_tcpCLient.at(index3)->waitForConnected(1000))
                {
                    listServeur += "\n";
                    listServeur += m_modbusMap.at(2)->host() + ":" + QString::number(m_modbusMap.at(2)->port()) + " )" ;
                }

            QMessageBox::warning(this, "Erreur de connexion", "Impossible de se connecter au(x) serveur(s) :" + listServeur);

                    m_tcpCLient.at( index )->sockClose() ;
                    m_tcpCLient.at( index2 )->sockClose() ;
                    m_tcpCLient.at( index3 )->sockClose() ;


            }


        }
    }


// RAZ de toutes les valeurs (cartographie locale)



// demande d'actualisation de toutes les données
// par interrogations du serveur

void manuel::on_pbuReadAll_clicked()
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

/*void manuel::on_pbuRead_clicked()
{
    int i = tabWidget->currentIndex() ;

    int table = m_modbusMapViewer.at(i)->currentTable() ;
    if ( table == -1 )	return ;
    QString name = m_modbusMapViewer.at(i)->currentName() ;

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, name ) ;
}*/

// changement d'onglet

void manuel::on_tabWidget_currentChanged(int index )
{
    bool connected = m_tcpCLient.at( index )->state() == QAbstractSocket::ConnectedState ;
    pbuConnect->setText( connected ? "Arrêter" : "Demarrer" ) ;
    pbuConnect->setEnabled( true ) ;
    pbuReadAll->setEnabled( connected ) ;
    //pbuRead->setEnabled( connected ) ;

    //edtHost->setText( m_modbusMap.at( index )->host() ) ;						// new 1.1
    //edtPort->setText( QString("%1").arg( m_modbusMap.at( index )->port() ) ) ;
    //edtHost->setEnabled( !connected ) ;
    //edtPort->setEnabled( !connected ) ;
    //labHost->setEnabled( !connected ) ;
    //labPort->setEnabled( !connected ) ;
}

// suppression d'un référencement serveur

void manuel::on_tabWidget_tabCloseRequested(int index )
{
    bool connected = m_tcpCLient.at( index )->state() == QAbstractSocket::ConnectedState ;	// new 1.1
    if ( connected ) m_tcpCLient.at( index )->sockClose() ;

    m_tcpCLient.removeAt( index ) ;

    m_modbusMapViewer.removeAt( index ) ;
    m_modbusMap.removeAt( index ) ;

    tabWidget->removeTab( index ) ;

    if ( tabWidget->count() == 0 ) {		// new 1.1
        //edtHost->setText( "" ) ;
        //edtPort->setText( "" ) ;
    }
}

// gestion de la configuration inter-sessions

void manuel::readSettings()
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "modipmanager" ) ;

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

void manuel::writeSettings()
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "modipmanager" ) ;

    settings.setValue("MainWindow/pos", pos() ) ;
    settings.setValue("MainWindow/size", size() ) ;
    settings.setValue("Files/configDir", m_configDir ) ;
}

// remontée des messages d'info.

void manuel::info(const QString& source, const QString& message )
{
    showPrompt( source + ": ") ;
    showMessage( message + "\n", false, Qt::darkBlue  ) ;
}

void manuel::valueChanged(int table,const QString& name )
{
    showPrompt( "value : ") ;
    showMessage( QamModbusMap::tableAsString( (QamModbusMap::PrimaryTable)table ) + " / " + name + " changed\n", false, Qt::darkRed  ) ;
}

void manuel::showPrompt(const QString& prompt )
{
    edtDialog->moveCursor(QTextCursor::End ) ;
    edtDialog->setTextColor( Qt::darkGray ) ;
    edtDialog->setFontWeight( QFont::Normal ) ;
    edtDialog->insertPlainText( prompt ) ;
    edtDialog->moveCursor(QTextCursor::End ) ;
}

void manuel::showMessage(const QString& msg, bool bold, QColor color )
{
    edtDialog->moveCursor(QTextCursor::End ) ;
    edtDialog->setTextColor( color ) ;
    edtDialog->setFontWeight( bold ? QFont::Bold : QFont::Normal ) ;
    edtDialog->insertPlainText( msg ) ;
    edtDialog->moveCursor(QTextCursor::End ) ;

}

//****************MODE AUTOMATIQUE*******************
void manuel::Auto()
{
    int i = 0 ;
    stop=0;
    a =18; // Compteur des 20 pièces
    y=0;

    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;


    // *************SECURITES
    pbuPom->setEnabled( false), pbuMoteur1->setEnabled( false ), pbuMoteur2->setEnabled( false ), pbuMonter->setEnabled( false ), pbuDescendre->setEnabled( false ),
    pbuPinceFerme->setEnabled( false ) ,pbuPinceOuverte->setEnabled( false ), pbuVersPalette->setEnabled( false ), pbuVersTable->setEnabled( false ),
    pbuVersT1->setEnabled( false ), pbuVersT2->setEnabled( false ), buteA->setEnabled( false ), buteS->setEnabled( false ), buteV->setEnabled( false ),
    buteAtt->setEnabled( false ), piece->setEnabled( false), piece_2->setEnabled( false), piece_3->setEnabled( false), piece_4->setEnabled( false),
    piece_5->setEnabled( false), piece_6->setEnabled( false), piece_7->setEnabled( false), piece_8->setEnabled( false), piece_9->setEnabled( false),
    piece_10->setEnabled( false), piece_11->setEnabled( false), piece_12->setEnabled( false), piece_13->setEnabled( false), piece_14->setEnabled( false),
    piece_15->setEnabled( false), piece_16->setEnabled( false), piece_17->setEnabled( false), piece_18->setEnabled( false), piece_19->setEnabled( false),
    piece_20->setEnabled( false);


    // *************DEBUT MODE MONTAGE
    m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "1" );
    m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "1" );
    m_modbusMap.at(i)->setValue(table, "C_But", "1" );
    m_modbusMap.at(i)->setValue(table, "D_But", "1" );

    while ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Mon_Cap") == "0") )
    {
       //SCAN
    }

    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Mon_Cap") == "1") )
    {
       m_modbusMap.at(i)->setValue(table, "E_But", "1" );
       usleep(200000);
       m_modbusMap.at(i)->setValue(table, "E_But", "0" );
    }


//***********BOUCLE MONTAGE
    while(1)
{
        if ((a==20) && (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Mon_Cap") == "0"))
        {
            sleep(3);
            break;
            break;
        }

        //*********TRANSFERT T1**************

        if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
        {
        //********SCAN
        }

        if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
        {

           m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
           m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

        }

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
        {
        //***********SCAN
        }

        if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
        {
            m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
            m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
            m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
        }


        //*********TRANSFERT T2***************

        if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
        {
        //***********SCAN
        }

        if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
        {

           m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
           m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
        }


        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
        {
        //***********SCAN
        }

        if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
        {
            m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
            m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
        }



       /*
        //*********POSTE SCARA***************

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1")
        {
          m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero );
          m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation );
          m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
          m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "0" );


          while (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "0")
          {

          }

          if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
          {

            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_but", "1" );
          }

          if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_but") == "1")
          {
            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_but", "0" );
          }
        }



        //*********POSTE VISION***************

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1")
        {
          m_modbusMap.at(2)->setValue(QamModbusMap::Coil, "C_Mon", "1" );
          m_modbusMap.at(2)->setValue(QamModbusMap::Coil, "C_Mon", "0" );

          while (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0")
          {

          }

          if (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1")
          {
            numero = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
            orientation = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_but", "1" );
          }

          if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_but") == "1")
          {
            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_but", "0" );
          }
        }

       */

        //*********BOUCLE POSTE A***************

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Mon_Cap") == "1")
        {

         m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "1" );

             while((m_modbusMap.at(0)->value(QamModbusMap::Coil, tableau[a]) == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
             {
             //***********SCAN

                 //*********TRANSFERT T1**************

                 if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                 {
                 //********SCAN
                 }

                 if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                 {

                    m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                    m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                 }

                 if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                 {
                 //***********SCAN
                 }

                 if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                 {
                     m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                     m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                     m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                 }


                 //*********TRANSFERT T2***************

                 if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                 {
                 //***********SCAN
                 }

                 if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                 {

                    m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                    m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                 }


                 if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                 {
                 //***********SCAN
                 }

                 if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                 {
                     m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                     m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                 }
             }
        }

       if((m_modbusMap.at(0)->value(QamModbusMap::Coil, tableau[a]) == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) )
        {

         m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "0" );
         a++;
         m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "0" );
         m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "1" );

             while(m_modbusMap.at(0)->value(table, "A_Cap_ZBas") == "0" )
             {

                 //*********TRANSFERT T1**************

                 if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                 {
                 //********SCAN
                 }

                 if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                 {

                    m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                    m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                 }

                 if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                 {
                 //***********SCAN
                 }

                 if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                 {
                     m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                     m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                     m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                 }


                 //*********TRANSFERT T2***************

                 if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                 {
                 //***********SCAN
                 }

                 if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                 {

                    m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                    m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                 }

                 if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                 {
                 //***********SCAN
                 }

                 if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                 {
                     m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                     m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                 }

             }
        }

        if(m_modbusMap.at(0)->value(table, "A_Cap_ZBas") == "1" )
        {

            m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "1" );
            m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "0" );
            m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "1" );

                while(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "0" )
                {

                    //*********TRANSFERT T1**************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                    }


                    //*********TRANSFERT T2***************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                    }

                }

                if(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "1" )
                {
                m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "1" );
                m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "0" );
                }

                while(m_modbusMap.at(0)->value(table, "A_Cap_XPal") == "0" )
                {

                    //*********TRANSFERT T1**************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                    }


                    //*********TRANSFERT T2***************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                    }


                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                    }

                }

                if(m_modbusMap.at(0)->value(table, "A_Cap_XPal") == "1" )
                {
                    m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "1" );

                        while(m_modbusMap.at(0)->value(table, "A_Cap_ZBas") == "0" )
                        {

                            //*********TRANSFERT T1**************

                            if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                            {
                            //********SCAN
                            }

                            if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                            {

                               m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                               m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                            }

                            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                            {
                            //***********SCAN
                            }

                            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                            {
                                m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                                m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                                m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                            }


                            //*********TRANSFERT T2***************

                            if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                            {
                            //***********SCAN
                            }

                            if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                            {

                               m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                               m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                            }

                            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                            {
                            //***********SCAN
                            }

                            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                            {
                                m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                                m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                            }

                        }

                        if(m_modbusMap.at(0)->value(table, "A_Cap_ZBas") == "1" )
                        {
                            m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "0" );
                            m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "0" );
                            m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "1" );

                        }

                        while(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "0" )
                        {

                            //*********TRANSFERT T1**************

                            if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                            {
                            //********SCAN
                            }

                            if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                            {

                               m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                               m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                            }

                            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                            {
                            //***********SCAN
                            }

                            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                            {
                                m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                                m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                                m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                            }


                            //*********TRANSFERT T2***************

                            if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                            {
                            //***********SCAN
                            }

                            if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                            {

                               m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                               m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                            }

                            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                            {
                            //***********SCAN
                            }

                            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                            {
                                m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                                m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                            }

                        }

                        if(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "1" )
                        {
                        m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "0" );
                        m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "1" );
                        }


                        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                        m_modbusMap.at(i)->setValue(table, "A_Mon_but", "1" );


                        if((m_modbusMap.at(0)->value(table, "A_Dem_but") == "1" ) && (m_modbusMap.at(0)->value(table, "A_Mon_but") == "1" ))
                        {

                        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "0" );
                        m_modbusMap.at(i)->setValue(table, "A_Mon_but", "0" );
                        m_modbusMap.at(i)->setValue(table, "E_But", "1" );

                            if((m_modbusMap.at(0)->value(table, "A_Dem_but") == "0" ) && (m_modbusMap.at(0)->value(table, "A_Mon_but") == "0" ))
                            {
                            m_modbusMap.at(i)->setValue(table, "E_But", "0" );
                            }

                        }
                }
        }

    //ARRET DU CYCLE
    if(stop==1)
    {

    // ************* RECATIVATION DES BOUTONS MANUELS
    pbuPom->setEnabled( true ), pbuMoteur1->setEnabled( true ), pbuMoteur2->setEnabled( true ), pbuMonter->setEnabled( true ), pbuDescendre->setEnabled( true ),
    pbuPinceFerme->setEnabled( true ) ,pbuPinceOuverte->setEnabled( true ), pbuVersPalette->setEnabled( true ), pbuVersTable->setEnabled( true ),
    pbuVersT1->setEnabled( true ), pbuVersT2->setEnabled( true ), buteA->setEnabled( true ), buteS->setEnabled( true ), buteV->setEnabled( true ),
    buteAtt->setEnabled( true ), piece->setEnabled( true), piece_2->setEnabled( true), piece_3->setEnabled( true), piece_4->setEnabled( true),
    piece_5->setEnabled( true), piece_6->setEnabled( true), piece_7->setEnabled( true), piece_8->setEnabled( true), piece_9->setEnabled( true),
    piece_10->setEnabled( true), piece_11->setEnabled( true), piece_12->setEnabled( true), piece_13->setEnabled( true), piece_14->setEnabled( true),
    piece_15->setEnabled( true), piece_16->setEnabled( true), piece_17->setEnabled( true), piece_18->setEnabled( true), piece_19->setEnabled( true),
    piece_20->setEnabled( true);

    break;
    return;
    }

} // *************FIN BOUCLE MONTAGE


    // *************PREPARATION MODE DEMONTAGE

    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "1" );
    m_modbusMap.at(i)->setValue(table, "C_But", "1" );
    m_modbusMap.at(i)->setValue(table, "D_But", "1" );
    y=0;

    TransfertVersT1();

    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
    {
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );

    }

    while(y < 2)
    {
        qDebug() << y();
    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0"))
    {
        pbuVersT1->setEnabled( false ) ;
    }

    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
    {
       pbuVersT1->setEnabled( true ) ;
       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
       m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
       y++;

    }


    while(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1")
    {
        m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "T2_Dem_Cap_Dep" ) ;
         m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "T2_Dem_Cap_Arr" ) ;
    }

    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
    {
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );

    }
    }

    sleep(8);
    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "0" );
    m_modbusMap.at(i)->setValue(table, "C_But", "0" );
    m_modbusMap.at(i)->setValue(table, "D_But", "0" );
    m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "0" );
    m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "0" );

// *************PREPARATION TERMINE
// *************FIN DU MODE MONTAGE
// *************DEBUT MODE DEMONTAGE

    usleep(200000);

    m_modbusMap.at(i)->setValue(table, "BT2_Dem_Mot", "1" );
    m_modbusMap.at(i)->setValue(table, "BT1_Dem_Mot", "1" );
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "1" );
    m_modbusMap.at(i)->setValue(table, "C_But", "1" );

//*********************************************************

    // *************BOUCLE MODE DEMONTAGE
    while(1)
    {
        if ((a==20) && (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Mon_Cap") == "0"))
        {
            break;
        }

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
        {

         sleep(3);
         m_modbusMap.at(0)->setValue(table, "E_But", "1" );
         usleep(200000);
         m_modbusMap.at(0)->setValue(table, "E_But", "0" );
        }

        //*********TRANSFERT T1**************

        if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
        {
        //********SCAN
        }

        if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
        {

           m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
           m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

        }

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
        {
        //***********SCAN
        }

        if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
        {
            m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
            m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
            m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
        }


        //*********TRANSFERT T2***************

        if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
        {
        //***********SCAN
        }

        if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
        {

           m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
           m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
        }

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
        {
        //***********SCAN
        }

        if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
        {
            m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
            m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
        }

        //*********POSTE A***************

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Dem_Cap") == "1")
        {

            m_modbusMap.at(0)->setValue(table, "A_Ver_XTab", "0" );
            m_modbusMap.at(0)->setValue(table, "A_Ver_XPal", "1" );

            while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XPal") == "0")
            {
                //******SCAN

                //*********TRANSFERT T1**************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                }


                //*********TRANSFERT T2***************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                }
            }

            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XPal") == "1")
            {
                m_modbusMap.at(0)->setValue(table, "A_ver_ZHaut", "0" );
                m_modbusMap.at(0)->setValue(table, "A_ver_ZBas", "1" );
            }

            while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "0")
            {
                //******SCAN

                //*********TRANSFERT T1**************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                }


                //*********TRANSFERT T2***************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                }
            }

            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "1")
            {
                m_modbusMap.at(0)->setValue(table, "A_Ver_Pince", "1" );
                m_modbusMap.at(0)->setValue(table, "A_ver_ZBas", "0" );
                m_modbusMap.at(0)->setValue(table, "A_ver_ZHaut", "1" );

            }

            while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "0")
            {
                //*********TRANSFERT T1**************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                }


                //*********TRANSFERT T2***************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                }
            }

            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "1")
            {

                m_modbusMap.at(0)->setValue(table, "A_Ver_XPal", "0" );
                m_modbusMap.at(0)->setValue(table, "A_Ver_XTab", "1" );

            }

            while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XTab") == "0")
            {
                //SCAN

                //*********TRANSFERT T1**************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                }


                //*********TRANSFERT T2***************

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                {

                   m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                   m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                }

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                {
                //***********SCAN
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                {
                    m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                    m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                }
            }

            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XTab") == "1")
            {

                m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "1" );

                while((m_modbusMap.at(0)->value(QamModbusMap::Coil, tableau[a]) == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
                {

                    //SCAN

                    //*********TRANSFERT T1**************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                    }


                    //*********TRANSFERT T2***************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                    }

                }

                if ((m_modbusMap.at(0)->value(QamModbusMap::Coil, tableau[a]) == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) )
                {
                    m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "0" );
                    a++;
                    m_modbusMap.at(0)->setValue(table, "A_ver_ZHaut", "0" );
                    m_modbusMap.at(0)->setValue(table, "A_ver_ZBas", "1" );

                }

                while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "0")
                {
                    //SCAN

                    //*********TRANSFERT T1**************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                    }


                    //*********TRANSFERT T2***************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                    }
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "1")
                {
                    m_modbusMap.at(0)->setValue(table, "A_Ver_Pince", "0" );
                    m_modbusMap.at(0)->setValue(table, "A_ver_ZBas", "0" );
                    m_modbusMap.at(0)->setValue(table, "A_ver_ZHaut", "1" );
                }

                while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "0")
                {
                    //SCAN

                    //*********TRANSFERT T1**************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );

                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
                        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                    }


                    //*********TRANSFERT T2***************

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "0")) //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
                    {

                       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
                       m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
                    }

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "1") //TESTER en COMMENTAIRE
                    {
                    //***********SCAN
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
                    {
                        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
                        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
                    }
                }

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "0")
                {
                    m_modbusMap.at(0)->setValue(table, "A_Dem_but", "1" );
                    usleep(200000);
                    m_modbusMap.at(0)->setValue(table, "A_Dem_but", "0" );
                }

        }
        }



        //ARRET DU CYCLE
        if(stop==1)
        {

        // ************* RECATIVATION DES BOUTONS MANUELS
        pbuPom->setEnabled( true ), pbuMoteur1->setEnabled( true ), pbuMoteur2->setEnabled( true ), pbuMonter->setEnabled( true ), pbuDescendre->setEnabled( true ),
        pbuPinceFerme->setEnabled( true ) ,pbuPinceOuverte->setEnabled( true ), pbuVersPalette->setEnabled( true ), pbuVersTable->setEnabled( true ),
        pbuVersT1->setEnabled( true ), pbuVersT2->setEnabled( true ), buteA->setEnabled( true ), buteS->setEnabled( true ), buteV->setEnabled( true ),
        buteAtt->setEnabled( true ), piece->setEnabled( true), piece_2->setEnabled( true), piece_3->setEnabled( true), piece_4->setEnabled( true),
        piece_5->setEnabled( true), piece_6->setEnabled( true), piece_7->setEnabled( true), piece_8->setEnabled( true), piece_9->setEnabled( true),
        piece_10->setEnabled( true), piece_11->setEnabled( true), piece_12->setEnabled( true), piece_13->setEnabled( true), piece_14->setEnabled( true),
        piece_15->setEnabled( true), piece_16->setEnabled( true), piece_17->setEnabled( true), piece_18->setEnabled( true), piece_19->setEnabled( true),
        piece_20->setEnabled( true);

        break;
        return;
        }

    }//FIN BOUCLE DEMONTAGE


    //TO DO REMETTRE PALETTES POUR NOUVEAU CYCLE

    if(stop==0)
    {
    //Auto(); REDEMARAGE DU CYCLE MONTAGE + DEMONTAGE
    }


}
//****************FIN DU MODE AUTOMATIQUE*******************

