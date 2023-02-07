#include "manuel.h"
#include <QMessageBox>
#include <QFileDialog>
#include <time.h>
#include <QtGui>

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
    connect(pbuPom, SIGNAL(clicked()), this, SLOT(Pom()));
    connect(pbuAuto, SIGNAL(clicked()), this, SLOT(Auto()));
    connect(timer, SIGNAL(timeout()), this, SLOT(tempsSysteme()));
    connect(pbuArretCycle, SIGNAL(clicked()), this, SLOT(ArretFinCycle()));

    srand(time(NULL));

 #ifdef Q_OS_MAC
    edtDialog->setFont( QFont("Monaco", 12 ) ) ;
 #else
    edtDialog->setFont( QFont("Courier", 10 ) ) ;
 #endif

    pbuReadAll->setEnabled( false ) ;
    //pbuRead->setEnabled( false ) ;

    readSettings() ;	// chargement configuration session précédente

    //chargement csv automatique//
    QString	fileName =  "/home/cellflex-cc2/Bureau/CC2MAN V8/CC2MAN/csv/cellflex_api.csv";
    QString	fileName2 =  "/home/cellflex-cc2/Bureau/CC2MAN V8/CC2MAN/csv/cellflex_scara.csv";
    QString	fileName3 =  "/home/cellflex-cc2/Bureau/CC2MAN V8/CC2MAN/csv/cellflex_vision.csv";

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

     pixmap.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/0.png");
     pixmap = pixmap.scaled(this->piece1->size());

     pixmap2.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/1.png");
     pixmap2 = pixmap2.scaled(this->piece2->size());

     pixmap3.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/2.png");
     pixmap3 = pixmap3.scaled(this->piece3->size());

     pixmap4.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/3.png");
     pixmap4 = pixmap4.scaled(this->piece3->size());

     pixmap5.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/4.png");
     pixmap5 = pixmap5.scaled(this->piece3->size());

     pixmap6.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/5.png");
     pixmap6 = pixmap6.scaled(this->piece3->size());

     pixmap7.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/6.png");
     pixmap7 = pixmap7.scaled(this->piece3->size());

     pixmap8.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/7.png");
     pixmap8 = pixmap8.scaled(this->piece3->size());

     pixmap9.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/8.png");
     pixmap9 = pixmap9.scaled(this->piece3->size());

     pixmap10.load("/home/cellflex-cc2/Bureau/CC2MAN10/CC2MAN/ressources/9.png");
     pixmap10 = pixmap10.scaled(this->piece3->size());

     pixmap11.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/10.png");
     pixmap11 = pixmap11.scaled(this->piece3->size());

     pixmap12.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/11.png");
     pixmap12 = pixmap12.scaled(this->piece3->size());

     pixmap13.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/12.png");
     pixmap13 = pixmap13.scaled(this->piece3->size());

     pixmap14.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/13.png");
     pixmap14 = pixmap14.scaled(this->piece3->size());

     pixmap15.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/14.png");
     pixmap15 = pixmap15.scaled(this->piece3->size());

     pixmap16.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/15.png");
     pixmap16 = pixmap16.scaled(this->piece3->size());

     pixmap17.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/16.png");
     pixmap17 = pixmap17.scaled(this->piece3->size());

     pixmap18.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/17.png");
     pixmap18 = pixmap18.scaled(this->piece3->size());

     pixmap19.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/18.png");
     pixmap19 = pixmap19.scaled(this->piece3->size());

     pixmap20.load("/home/cellflex-cc2/Bureau/CC2MANV10/CC2MAN/ressources/19.png");
     pixmap20 = pixmap20.scaled(this->piece3->size());

     pixmap22.load("");
     pixmap22 = pixmap22.scaled(this->piecevision->size());

     scene->addPixmap(pixmap);
     scene2->addPixmap(pixmap2);
     scene3->addPixmap(pixmap3);
     scene4->addPixmap(pixmap4);
     scene5->addPixmap(pixmap5);
     scene6->addPixmap(pixmap6);
     scene7->addPixmap(pixmap7);
     scene8->addPixmap(pixmap8);
     scene9->addPixmap(pixmap9);
     scene10->addPixmap(pixmap10);
     scene11->addPixmap(pixmap11);
     scene12->addPixmap(pixmap12);
     scene13->addPixmap(pixmap13);
     scene14->addPixmap(pixmap14);
     scene15->addPixmap(pixmap15);
     scene16->addPixmap(pixmap16);
     scene17->addPixmap(pixmap17);
     scene18->addPixmap(pixmap18);
     scene19->addPixmap(pixmap19);
     scene20->addPixmap(pixmap20);
     scene22->addPixmap(pixmap22);

     this->piecevision->setScene(scene22);
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
        m_modbusMap.at(0)->setValue(table, "BT1", "0" );
        m_modbusMap.at(0)->setValue(table, "BT2", "0" );
        m_modbusMap.at(0)->setValue(table, "T1", "0" );
        m_modbusMap.at(0)->setValue(table, "T2", "0" );
        m_modbusMap.at(0)->setValue(table, "C_Vision", "0" );
        m_modbusMap.at(0)->setValue(table, "E_Attente", "0" );

        m_modbusMap.at(0)->setValue(table, "CC1_CC2", "0" );
        m_modbusMap.at(0)->setValue(QamModbusMap::Coil, "Air_On", "0" );
        m_modbusMap.at(0)->setValue(QamModbusMap::Coil, "Power_On", "0" );
        m_modbusMap.at(0)->setValue(QamModbusMap::Coil, "Aru", "1" );

        m_tcpCLient.at( index )->sockClose() ;
        m_tcpCLient.at( index2 )->sockClose() ;
        m_tcpCLient.at( index3 )->sockClose() ;
        pbuConnect->setText("Démarrage système") ;
        pbuReadAll->setEnabled( false ) ;
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
        pbuArretCycle->setEnabled( false) ;
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

        if (( m_tcpCLient.at(index)->waitForConnected(3000) ) && ( m_tcpCLient.at(index2)->waitForConnected(3000) ) && ( m_tcpCLient.at(index3)->waitForConnected(3000) )){
            pbuConnect->setText("Arrêt système") ;
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
            usleep(500000);
            m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Aru", "0" );

            m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "Power_On", "1" );
            usleep(500000);
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

void manuel::on_tabWidget_currentChanged(int index )
{
    bool connected = m_tcpCLient.at( index )->state() == QAbstractSocket::ConnectedState ;
    pbuConnect->setText( connected ? "Arrêt système" : "Démarrage système" ) ;
    pbuConnect->setEnabled( true ) ;
    pbuReadAll->setEnabled( connected ) ;
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
    showPrompt( source + " --> ") ;
    showMessage( message + "\n", false, Qt::darkGray  ) ;
}

void manuel::valueChanged(int table,const QString& name )
{
    showPrompt( "value --> ") ;
    showMessage( QamModbusMap::tableAsString( (QamModbusMap::PrimaryTable)table ) + " / " + name + " changed\n", false, Qt::darkRed  ) ;
}

void manuel::showPrompt(const QString& prompt )
{
    edtDialog->moveCursor(QTextCursor::End ) ;
    edtDialog->setTextColor( Qt::darkGreen ) ;
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

void manuel::Transfert1AutoMon()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;

    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1") )
    {
       m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
       m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );
    }

    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
    {
        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );
        m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
    }
}

void manuel::Transfert2AutoMon()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;

    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1") )
    {
       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
       m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
    }

    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Arr") == "0")
    {
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
    }
}

void manuel::Transfert1AutoDem()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;

    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Dem_Cap_Dep") == "1") )
    {
       m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
       m_modbusMap.at(i)->setValue(table, "T1_Dem_Mot", "1" );
    }

    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Dem_Cap_Arr") == "0")
    {
        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T1_Dem_Mot", "0" );
    }
}

void manuel::Transfert2AutoDem()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;

    if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Dem_Cap_Dep") == "1") )
    {
       m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
       m_modbusMap.at(i)->setValue(table, "T2_Dem_Mot", "1" );
    }

    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Dem_Cap_Arr") == "0")
    {
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T2_Dem_Mot", "0" );
    }
}

void manuel::Auto()
{

 timer->start(1000);

 vision=false;
 scara=false;
 a=0;//compteur api
 stop=0;
 b=0;//compteur scara
 f=0;//compteur vision
 stop = 0;
 g=0;
 v=0;

 pbuPom->setEnabled( false), pbuMoteur1->setEnabled( false ), pbuMoteur2->setEnabled( false ),
 pbuMonter->setEnabled( false ), pbuDescendre->setEnabled( false ), pbuPinceFerme->setEnabled( false ),
 pbuPinceOuverte->setEnabled( false ), pbuVersPalette->setEnabled( false ), pbuVersTable->setEnabled( false ),
 pbuVersT1->setEnabled( false ), pbuVersT2->setEnabled( false ), buteA->setEnabled( false ),
 buteS->setEnabled( false ), buteV->setEnabled( false ), buteAtt->setEnabled( false ), pbuReadAll->setEnabled( false ),
 pbuAuto->setEnabled( false ), piece->setEnabled( false), piece_2->setEnabled( false),
 piece_3->setEnabled( false), piece_4->setEnabled( false), piece_5->setEnabled( false),
 piece_6->setEnabled( false), piece_7->setEnabled( false), piece_8->setEnabled( false),
 piece_9->setEnabled( false), piece_10->setEnabled( false), piece_11->setEnabled( false),
 piece_12->setEnabled(false), piece_13->setEnabled( false), piece_14->setEnabled( false),
 piece_15->setEnabled(false), piece_16->setEnabled( false), piece_17->setEnabled( false),
 piece_18->setEnabled(false), piece_19->setEnabled( false), piece_20->setEnabled( false),pbuQuitter->setEnabled( false),
 pbuReset->setEnabled(true),pbuArretCycle->setEnabled(true);

 int i = 0 ;
 QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;

 m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "1" );
 m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "1" );
 m_modbusMap.at(i)->setValue(QamModbusMap::Coil, "20", "0" );
 m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "1" );
 m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "0" );

 while ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Mon_Cap") == "0") )
 {

 }

 if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Mon_Cap") == "1") )
 {
    attente=true;
    m_modbusMap.at(i)->setValue(table, "E_But", "1" );
    usleep(200000);
    m_modbusMap.at(i)->setValue(table, "E_But", "0" );
 }

 // **************************MODE MONTAGE************************** //

    while(1)
{
        if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Mon_Cap") == "1") && (attente==false ))
         {
            attente=true;

            m_modbusMap.at(i)->setValue(table, "E_But", "1" );

            if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1") )
             {
                m_modbusMap.at(i)->setValue(table, "E_But", "0" );
             }
         }

        //**********************POSTE VISION************************** //

        if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (vision==false))
        {
          Barre->setValue(v++);
          vision=true;
          m_modbusMap.at(2)->setValue(QamModbusMap::Coil, "C_Mon", "1" );
          test2=1;
        }

         //*********SCARA***************

         if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
         {
           Barre->setValue(v++);
           test=1;
           scara=true;
           m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
           m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
           m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
         }

        //*********GESTION FIN DE CYCLE MONTAGE***************

        if ((a==20) && (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Mon_Cap") == "0"))
        {
            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );

            while(b != 20)
            {
                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (vision==false))
                {
                  Barre->setValue(v++);
                  vision=true;
                  m_modbusMap.at(2)->setValue(QamModbusMap::Coil, "C_Mon", "1" );
                  test2=1;
                }

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
                {
                  Barre->setValue(v++);
                  test=1;
                  scara=true;
                  m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
                  m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
                  m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
                }

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
                {

                    if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
                    {
                    test2=0;
                    qDebug() << "Pièce non reconnu";
                    vision=false;
                    numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                    orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");

                    f++;
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                    {
                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                    }
                    }

                    if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
                    {
                      test2=0;
                      vision=false;
                      numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                      orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                      puzzleIhmVision();
                      f++;
                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                      if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                      {
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                      }
                    }
                }

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
                {

                    if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                    {
                    test=0;
                    scara=false;

                    puzzleIhmMon();

                    b++;

                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                    {
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                    }
                    }

                if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                {
                m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                test=0;
                scara=false;

                puzzleIhmMon();

                b++;

                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                {
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                }
                }

                }

                Transfert1AutoMon();
                Transfert2AutoMon();
            }

            if(b==20)
            {
                break;
            }
        }

        Transfert1AutoMon();
        Transfert2AutoMon();

        if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
        {

            if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
            {
            test=0;
            scara=false;
            puzzleIhmMon();

            b++;

            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
            {
                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
            }
            }

        if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
        {
        m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
        test=0;
        scara=false;
        puzzleIhmMon();

        b++;

        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
        {
            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
        }
        }
        }

        if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
        {

            if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
            {
            test2=0;
            qDebug() << "Pièce non reconnu";
            vision=false;
            numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
            orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");

            f++;
            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

            if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
            {
              m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
            }
            }

            if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
            {
              test2=0;
              vision=false;
              numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
              orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
              puzzleIhmVision();
              f++;
              m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

              if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
              {

                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
              }
            }
        }

        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Mon_Cap") == "1")
        {
        Barre->setValue(v++);
        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "1" );

        while((m_modbusMap.at(0)->value(QamModbusMap::Coil, tableau[a]) == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
         {

            if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
            {
              Barre->setValue(v++);
              test=1;
              scara=true;
              m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
              m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
              m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
            }

            if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
            {

                if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
                {
                test2=0;
                qDebug() << "Pièce non reconnu";
                vision=false;
                numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                f++;
                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                {
                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                }
                }
                if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
                {
                  test2=0;
                  vision=false;
                  numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                  orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                  puzzleIhmVision();
                  f++;
                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                  if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                  {

                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                  }
                }
            }

            if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
            {

                if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                {
                test=0;
                scara=false;
                puzzleIhmMon();

                b++;

                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                {
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                }
                }

            if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
            {
            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
            test=0;
            scara=false;
            puzzleIhmMon();

            b++;

            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
            {
                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
            }
            }

            }

            Transfert1AutoMon();
            Transfert2AutoMon();
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
             if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
             {
               Barre->setValue(v++);
               test=1;
               scara=true;
               m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
               m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
               m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
             }

             if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
             {

                 if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
                 {
                 test2=0;
                 qDebug() << "Pièce non reconnu";
                 vision=false;
                 numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                 orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                 f++;
                 m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                 if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                 {
                   m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                 }
                 }
                 if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
                 {
                   test2=0;
                   vision=false;
                   numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                   orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                   puzzleIhmVision();
                   f++;
                   m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                   if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                   {

                     m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                   }
                 }
             }

             if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
             {

                 if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                 {
                 test=0;
                 scara=false;
                 puzzleIhmMon();

                 b++;

                 m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                 if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                 {
                     m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                 }
                 }

             if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
             {
             m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
             test=0;
             scara=false;
             puzzleIhmMon();

             b++;

             m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

             if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
             {
                 m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
             }
             }

             }

             Transfert1AutoMon();
             Transfert2AutoMon();
         }
         }

        if(m_modbusMap.at(0)->value(table, "A_Cap_ZBas") == "1" )
        {
            m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "1" );
            m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "0" );
            m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "1" );

            while(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "0" )
            {
                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
                {
                  Barre->setValue(v++);
                  test=1;
                  scara=true;
                  m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
                  m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
                  m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
                }

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
                {

                    if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
                    {
                    test2=0;
                    qDebug() << "Pièce non reconnu";
                    vision=false;
                    numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                    orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                    f++;
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                    {
                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                    }
                    }
                    if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
                    {
                      test2=0;
                      vision=false;
                      numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                      orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                      puzzleIhmVision();
                      f++;
                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                      if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                      {

                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                      }
                    }
                }

                Transfert1AutoMon();
                Transfert2AutoMon();

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
                {

                    if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                    {
                    test=0;
                    scara=false;
                    puzzleIhmMon();

                    b++;

                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                    {
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                    }
                    }

                if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                {
                m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                test=0;
                scara=false;
                puzzleIhmMon();

                b++;

                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                {
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                }
                }

                }
            }

            if(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "1" )
            {
            m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "1" );
            m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "0" );
            }

            while(m_modbusMap.at(0)->value(table, "A_Cap_XPal") == "0" )if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
            {
                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
                {
                  Barre->setValue(v++);
                  test=1;
                  scara=true;
                  m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
                  m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
                  m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
                }

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
                {

                    if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
                    {
                    test2=0;
                    qDebug() << "Pièce non reconnu";
                    vision=false;
                    numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                    orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                    f++;
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                    {
                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                    }
                    }
                    if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
                    {
                      test2=0;
                      vision=false;
                      numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                      orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                      puzzleIhmVision();
                      f++;
                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                      if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                      {

                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                      }
                    }
                }

                if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
                {

                    if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                    {
                    test=0;
                    scara=false;
                    puzzleIhmMon();

                    b++;

                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                    {
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                    }
                    }

                if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                {
                m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                test=0;
                scara=false;
                puzzleIhmMon();

                b++;

                m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                {
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                }
                }

                }

                Transfert1AutoMon();
                Transfert2AutoMon();
            }

            if(m_modbusMap.at(0)->value(table, "A_Cap_XPal") == "1" )
            {
                m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "0" );
                m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "1" );

                while(m_modbusMap.at(0)->value(table, "A_Cap_ZBas") == "0" )
                {
                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
                    {
                      Barre->setValue(v++);
                      test=1;
                      scara=true;
                      m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
                      m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
                      m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
                    }

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
                    {

                        if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
                        {
                        test2=0;
                        qDebug() << "Pièce non reconnu";
                        vision=false;
                        numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                        orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                        f++;
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                        if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                        {
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                        }
                        }
                        if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
                        {
                          test2=0;
                          vision=false;
                          numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                          orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                          puzzleIhmVision();
                          f++;
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                          if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                          {

                            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                          }
                        }
                    }

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
                    {

                        if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                        {
                        test=0;
                        scara=false;
                        puzzleIhmMon();

                        b++;

                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                        {
                            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                        }
                        }

                    if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                    {
                    m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                    test=0;
                    scara=false;
                    puzzleIhmMon();

                    b++;

                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                    {
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                    }
                    }

                    }

                    Transfert1AutoMon();
                    Transfert2AutoMon();
                }

                if(m_modbusMap.at(0)->value(table, "A_Cap_ZBas") == "1" )
                {
                    m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "0");
                    m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "1" );
                }

                while(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "0" )
                {
                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (scara==false))
                    {
                      Barre->setValue(v++);
                      test=1;
                      scara=true;
                      m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numero[b] );
                      m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientation[b] );
                      m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Mon", "1" );
                    }

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_Mon_Cap") == "1") && (test2==1))
                    {

                        if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "1") )
                        {
                        test2=0;
                        qDebug() << "Pièce non reconnu";
                        vision=false;
                        numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                        orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                        f++;
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                        if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                        {
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                        }
                        }
                        if ((m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Mon") == "0") && (m_modbusMap.at(2)->value(QamModbusMap::Coil, "C_Def") == "0") )
                        {
                          test2=0;
                          vision=false;
                          numero[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num");
                          orientation[f] = m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Ori");
                          puzzleIhmVision();
                          f++;
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "1" );

                          if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "C_But") == "1")
                          {

                            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "C_But", "0" );
                          }
                        }
                    }

                    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Mon_Cap") == "1") && (test==1))
                    {

                        if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                        {
                        test=0;
                        scara=false;
                        puzzleIhmMon();

                        b++;

                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                        {
                            m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                        }
                        }

                    if(m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                    {
                    m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                    test=0;
                    scara=false;
                    puzzleIhmMon();

                    b++;

                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                    {
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                    }
                    }

                    }

                    Transfert1AutoMon();
                    Transfert2AutoMon();
                }

                if(m_modbusMap.at(0)->value(table, "A_Cap_ZHaut") == "1" )
                {
                    m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "1" );
                }

                m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
                m_modbusMap.at(i)->setValue(table, "A_Mon_but", "1" );

                if((m_modbusMap.at(0)->value(table, "A_Dem_but") == "1" ) && (m_modbusMap.at(0)->value(table, "A_Mon_but") == "1" ) && (a < 20))
                {
                m_modbusMap.at(i)->setValue(table, "A_Dem_but", "0" );
                m_modbusMap.at(i)->setValue(table, "A_Mon_but", "0" );


                if((m_modbusMap.at(0)->value(table, "A_Dem_but") == "0" ) && (m_modbusMap.at(0)->value(table, "A_Mon_but") == "0" ))
                {
                    attente=false;
                }
                }

                if((m_modbusMap.at(0)->value(table, "A_Dem_but") == "1" ) && (m_modbusMap.at(0)->value(table, "A_Mon_but") == "1" ) && (a == 20))
                {
                    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "0" );
                    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "0" );
                }
            }
        }

    if(stop==1)
    {
    // ************* REACTIVATION DES BOUTONS MANUELS
    pbuPom->setEnabled( true ), pbuMoteur1->setEnabled( true ), pbuMoteur2->setEnabled( true ), pbuMonter->setEnabled( true ), pbuDescendre->setEnabled( true ),
    pbuPinceFerme->setEnabled( true ) ,pbuPinceOuverte->setEnabled( true ), pbuVersPalette->setEnabled( true ), pbuVersTable->setEnabled( true ),
    pbuVersT1->setEnabled( true ), pbuVersT2->setEnabled( true ), buteA->setEnabled( true ), buteS->setEnabled( true ), buteV->setEnabled( true ),
    buteAtt->setEnabled( true ), piece->setEnabled( true), piece_2->setEnabled( true), piece_3->setEnabled( true), piece_4->setEnabled( true),
    piece_5->setEnabled( true), piece_6->setEnabled( true), piece_7->setEnabled( true), piece_8->setEnabled( true), piece_9->setEnabled( true),
    piece_10->setEnabled( true), piece_11->setEnabled( true), piece_12->setEnabled( true), piece_13->setEnabled( true), piece_14->setEnabled( true),
    piece_15->setEnabled( true), piece_16->setEnabled( true), piece_17->setEnabled( true), piece_18->setEnabled( true), piece_19->setEnabled( true),
    piece_20->setEnabled( true), pbuReadAll->setEnabled( true ), pbuAuto->setEnabled( true ), pbuReset->setEnabled( true ),pbuQuitter->setEnabled(true);

    temps->setTime(QTime(0,0,0,0));
    Barre->setValue(0);

    m_modbusMap.at(i)->setValue(table, "BT1", "0" );
    m_modbusMap.at(i)->setValue(table, "BT2", "0" );
    m_modbusMap.at(i)->setValue(table, "T1", "0" );
    m_modbusMap.at(i)->setValue(table, "T2", "0" );
    m_modbusMap.at(i)->setValue(table, "C_Vision", "0" );
    m_modbusMap.at(i)->setValue(table, "E_Attente", "0" );

    return;
    }
    }

    sleep(3);
    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "0" );
    m_modbusMap.at(i)->setValue(table, "C_But", "0" );
    m_modbusMap.at(i)->setValue(table, "D_But", "0" );
    m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "0" );
    m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "0" );

    a=0;
    b=0;
    f=0;

    if (stopcycle==1)
    {
        // ************* REACTIVATION DES BOUTONS MANUELS
        pbuPom->setEnabled( true ), pbuMoteur1->setEnabled( true ), pbuMoteur2->setEnabled( true ), pbuMonter->setEnabled( true ), pbuDescendre->setEnabled( true ),
        pbuPinceFerme->setEnabled( true ) ,pbuPinceOuverte->setEnabled( true ), pbuVersPalette->setEnabled( true ), pbuVersTable->setEnabled( true ),
        pbuVersT1->setEnabled( true ), pbuVersT2->setEnabled( true ), buteA->setEnabled( true ), buteS->setEnabled( true ), buteV->setEnabled( true ),
        buteAtt->setEnabled( true ), piece->setEnabled( true), piece_2->setEnabled( true), piece_3->setEnabled( true), piece_4->setEnabled( true),
        piece_5->setEnabled( true), piece_6->setEnabled( true), piece_7->setEnabled( true), piece_8->setEnabled( true), piece_9->setEnabled( true),
        piece_10->setEnabled( true), piece_11->setEnabled( true), piece_12->setEnabled( true), piece_13->setEnabled( true), piece_14->setEnabled( true),
        piece_15->setEnabled( true), piece_16->setEnabled( true), piece_17->setEnabled( true), piece_18->setEnabled( true), piece_19->setEnabled( true),
        piece_20->setEnabled( true), pbuReadAll->setEnabled( true ), pbuAuto->setEnabled( true ), pbuReset->setEnabled( true ),pbuQuitter->setEnabled(true);

        temps->setTime(QTime(0,0,0,0));
        Barre->setValue(0);

        m_modbusMap.at(i)->setValue(table, "BT1", "0" );
        m_modbusMap.at(i)->setValue(table, "BT2", "0" );
        m_modbusMap.at(i)->setValue(table, "T1", "0" );
        m_modbusMap.at(i)->setValue(table, "T2", "0" );
        m_modbusMap.at(i)->setValue(table, "C_Vision", "0" );
        m_modbusMap.at(i)->setValue(table, "E_Attente", "0" );
        return;
    }

    sleep(1);

        m_modbusMap.at(i)->setValue(table, "BT2_Dem_Mot", "1" );
        m_modbusMap.at(i)->setValue(table, "BT1_Dem_Mot", "1" );
        m_modbusMap.at(i)->setValue(table, "A_Mon_but", "1" );
        m_modbusMap.at(i)->setValue(table, "C_But", "1" );
        m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "1" );
        scara=false;

        // *************BOUCLE MODE DEMONTAGE
            while(1)
            {
                m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "1" );

                if(b==15)
                {
                    m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                }

                if ((a==20) && (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Mon_Cap") == "0"))
                {
                   while(b != 20)
                    {
                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                        {

                        if (scara==false)
                        {
                        Barre->setValue(v++);
                        scara=true;
                        int randomNumber = qrand() %21;
                        int randomOrientation = qrand() %4;
                        QString numeroAleatoire = QString::number(randomNumber);
                        QString orientationAleatoire = QString::number(randomOrientation);

                        qDebug() << "pièce :"<< numeroAleatoire;
                        qDebug() << "orientation :" << orientationAleatoire;
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                        {
                            int randomNumber = qrand() %21;
                            int randomOrientation = qrand() %4;
                            QString numeroAleatoire = QString::number(randomNumber);
                            QString orientationAleatoire = QString::number(randomOrientation);

                            qDebug() << "pièce :"<< numeroAleatoire;
                            qDebug() << "orientation :" << orientationAleatoire;
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                            usleep(20000);
                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                        {
                         puzzleIhmDem();
                         m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                         scara=false;
                         m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                         if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                         {
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                         }
                        }
                        }

                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "A_Dem_but", "0" );
                        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "A_Mon_but", "0" );

                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Dem_Cap") == "1")
                                {
                                  b++;
                                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "1" );

                                  if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1")
                                  {
                                      usleep(100000);
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "0" );
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "A_Dem_but", "1" );
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "A_Mon_but", "1" );
                                      usleep(100000);
                                  }
                                }

                        Transfert1AutoDem();
                        Transfert2AutoDem();
                    }

                    if(b==20)
                    {
                        break;
                    }
                }

                  if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Dem_Cap") == "1")
                   {
                     b++;
                     m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "1" );

                           if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1")
                            {
                              usleep(100000);
                              m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "0" );
                            }
                   }

               //****************SCARA ALEATOIRE*****************// A PLACER DANS CHAQUE WHILE
                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                {

                if (scara==false)
                {
                Barre->setValue(v++);
                scara=true;
                int randomNumber = qrand() %21;
                int randomOrientation = qrand() %4;
                QString numeroAleatoire = QString::number(randomNumber);
                QString orientationAleatoire = QString::number(randomOrientation);

                qDebug() << "pièce :"<< numeroAleatoire;
                qDebug() << "orientation :" << orientationAleatoire;
                m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                }

                if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                {
                    int randomNumber = qrand() %21;
                    int randomOrientation = qrand() %4;
                    QString numeroAleatoire = QString::number(randomNumber);
                    QString orientationAleatoire = QString::number(randomOrientation);

                    qDebug() << "pièce :"<< numeroAleatoire;
                    qDebug() << "orientation :" << orientationAleatoire;
                    m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                    m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                    m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                    usleep(20000);
                }

                if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                {
                 puzzleIhmDem();
                 m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                 scara=false;
                 m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                 if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                 {
                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                 }
                }
                }

                Transfert1AutoDem();
                Transfert2AutoDem();

                //*********POSTE A***************

                if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Dem_Cap") == "1")
                {
                    Barre->setValue(v++);

                    m_modbusMap.at(0)->setValue(table, "A_Ver_XTab", "0" );
                    m_modbusMap.at(0)->setValue(table, "A_Ver_XPal", "1" );

                    while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XPal") == "0")
                    {
                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                        {

                        if (scara==false)
                        {
                        Barre->setValue(v++);
                        scara=true;
                        int randomNumber = qrand() %21;
                        int randomOrientation = qrand() %4;
                        QString numeroAleatoire = QString::number(randomNumber);
                        QString orientationAleatoire = QString::number(randomOrientation);

                        qDebug() << "pièce :"<< numeroAleatoire;
                        qDebug() << "orientation :" << orientationAleatoire;
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                        {
                            int randomNumber = qrand() %21;
                            int randomOrientation = qrand() %4;
                            QString numeroAleatoire = QString::number(randomNumber);
                            QString orientationAleatoire = QString::number(randomOrientation);

                            qDebug() << "pièce :"<< numeroAleatoire;
                            qDebug() << "orientation :" << orientationAleatoire;
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                            usleep(20000);
                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                        {
                         puzzleIhmDem();
                         m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                         scara=false;
                         m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                         if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                         {
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                         }
                        }
                        }
                        //******SCAN

                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Dem_Cap") == "1")
                                {

                                  b++;
                                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "1" );

                                  if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1")
                                  {
                                      usleep(100000);
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "0" );
                                  }

                                }

                        Transfert1AutoDem();
                        Transfert2AutoDem();
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XPal") == "1")
                    {
                        m_modbusMap.at(0)->setValue(table, "A_ver_ZHaut", "0" );
                        m_modbusMap.at(0)->setValue(table, "A_ver_ZBas", "1" );
                    }

                    while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "0")
                    {
                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                        {

                        if (scara==false)
                        {
                        Barre->setValue(v++);
                        scara=true;
                        int randomNumber = qrand() %21;
                        int randomOrientation = qrand() %4;
                        QString numeroAleatoire = QString::number(randomNumber);
                        QString orientationAleatoire = QString::number(randomOrientation);

                        qDebug() << "pièce :"<< numeroAleatoire;
                        qDebug() << "orientation :" << orientationAleatoire;
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                        {
                            int randomNumber = qrand() %21;
                            int randomOrientation = qrand() %4;
                            QString numeroAleatoire = QString::number(randomNumber);
                            QString orientationAleatoire = QString::number(randomOrientation);

                            qDebug() << "pièce :"<< numeroAleatoire;
                            qDebug() << "orientation :" << orientationAleatoire;
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                            usleep(20000);
                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                        {
                         puzzleIhmDem();
                         m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                         scara=false;
                         m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                         if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                         {
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                         }
                        }
                        }
                        //******SCAN

                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Dem_Cap") == "1")
                                {

                                  b++;
                                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "1" );

                                  if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1")
                                  {
                                      usleep(100000);
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "0" );
                                  }

                                }

                        Transfert1AutoDem();
                        Transfert2AutoDem();
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "1")
                    {
                        m_modbusMap.at(0)->setValue(table, "A_Ver_Pince", "1" );
                        m_modbusMap.at(0)->setValue(table, "A_ver_ZBas", "0" );
                        m_modbusMap.at(0)->setValue(table, "A_ver_ZHaut", "1" );

                    }

                    while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "0")
                    {
                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                        {

                        if (scara==false)
                        {
                        Barre->setValue(v++);
                        scara=true;
                        int randomNumber = qrand() %21;
                        int randomOrientation = qrand() %4;
                        QString numeroAleatoire = QString::number(randomNumber);
                        QString orientationAleatoire = QString::number(randomOrientation);

                        qDebug() << "pièce :"<< numeroAleatoire;
                        qDebug() << "orientation :" << orientationAleatoire;
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                        {
                            int randomNumber = qrand() %21;
                            int randomOrientation = qrand() %4;
                            QString numeroAleatoire = QString::number(randomNumber);
                            QString orientationAleatoire = QString::number(randomOrientation);

                            qDebug() << "pièce :"<< numeroAleatoire;
                            qDebug() << "orientation :" << orientationAleatoire;
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                            usleep(20000);
                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                        {
                         puzzleIhmDem();
                         m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                         scara=false;
                         m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                         if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                         {
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                         }
                        }
                        }

                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Dem_Cap") == "1")
                                {

                                  b++;
                                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "1" );

                                  if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1")
                                  {
                                      usleep(100000);
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "0" );
                                  }

                                }

                        Transfert1AutoDem();
                        Transfert2AutoDem();
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "1")
                    {

                        m_modbusMap.at(0)->setValue(table, "A_Ver_XPal", "0" );
                        m_modbusMap.at(0)->setValue(table, "A_Ver_XTab", "1" );

                    }

                    while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XTab") == "0")
                    {
                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                        {

                        if (scara==false)
                        {
                        Barre->setValue(v++);
                        scara=true;
                        int randomNumber = qrand() %21;
                        int randomOrientation = qrand() %4;
                        QString numeroAleatoire = QString::number(randomNumber);
                        QString orientationAleatoire = QString::number(randomOrientation);

                        qDebug() << "pièce :"<< numeroAleatoire;
                        qDebug() << "orientation :" << orientationAleatoire;
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                        m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                        {
                            int randomNumber = qrand() %21;
                            int randomOrientation = qrand() %4;
                            QString numeroAleatoire = QString::number(randomNumber);
                            QString orientationAleatoire = QString::number(randomOrientation);

                            qDebug() << "pièce :"<< numeroAleatoire;
                            qDebug() << "orientation :" << orientationAleatoire;
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                            usleep(20000);
                        }

                        if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                        {
                         puzzleIhmDem();
                         m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                         scara=false;
                         m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                         if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                         {
                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                         }
                        }
                        }

                        if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Dem_Cap") == "1")
                                {

                                  b++;
                                  m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "1" );

                                  if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1")
                                  {
                                      usleep(100000);
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "0" );
                                  }

                                }

                        Transfert1AutoDem();
                        Transfert2AutoDem();
                    }

                    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_XTab") == "1")
                    {

                       if((m_modbusMap.at(0)->value(QamModbusMap::Coil, tableau[a]) == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) )
                        {
                         m_modbusMap.at(i)->setValue(QamModbusMap::Coil, tableau[a], "0" );
                         a++;
                         m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "0" );
                         m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "1" );
                       }

                        while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "0")
                        {
                            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                            {

                            if (scara==false)
                            {
                            Barre->setValue(v++);
                            scara=true;
                            int randomNumber = qrand() %21;
                            int randomOrientation = qrand() %4;
                            QString numeroAleatoire = QString::number(randomNumber);
                            QString orientationAleatoire = QString::number(randomOrientation);

                            qDebug() << "pièce :"<< numeroAleatoire;
                            qDebug() << "orientation :" << orientationAleatoire;
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                            }

                            if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                            {
                                int randomNumber = qrand() %21;
                                int randomOrientation = qrand() %4;
                                QString numeroAleatoire = QString::number(randomNumber);
                                QString orientationAleatoire = QString::number(randomOrientation);

                                qDebug() << "pièce :"<< numeroAleatoire;
                                qDebug() << "orientation :" << orientationAleatoire;
                                m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                                m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                                m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                                usleep(20000);
                            }

                            if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                            {
                             puzzleIhmDem();
                             m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                             scara=false;
                             m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                             if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                             {
                              m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                             }
                            }
                            }

                            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_Dem_Cap") == "1")
                                    {

                                      b++;
                                      m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "1" );

                                      if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "E_But") == "1")
                                      {
                                          usleep(100000);
                                          m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "E_But", "0" );
                                      }

                                    }

                            Transfert1AutoDem();
                            Transfert2AutoDem();
                        }

                        if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZBas") == "1")
                        {
                            m_modbusMap.at(0)->setValue(table, "A_Ver_Pince", "0" );
                            m_modbusMap.at(0)->setValue(table, "A_ver_ZBas", "0" );
                            m_modbusMap.at(0)->setValue(table, "A_ver_ZHaut", "1" );
                        }

                        while (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "0")
                        {
                            if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_Dem_Cap") == "1")
                            {

                            if (scara==false)
                            {
                            Barre->setValue(v++);
                            scara=true;
                            int randomNumber = qrand() %21;
                            int randomOrientation = qrand() %4;
                            QString numeroAleatoire = QString::number(randomNumber);
                            QString orientationAleatoire = QString::number(randomOrientation);

                            qDebug() << "pièce :"<< numeroAleatoire;
                            qDebug() << "orientation :" << orientationAleatoire;
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                            m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );

                            }

                            if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Def_Num") == "1")
                            {
                                int randomNumber = qrand() %21;
                                int randomOrientation = qrand() %4;
                                QString numeroAleatoire = QString::number(randomNumber);
                                QString orientationAleatoire = QString::number(randomOrientation);

                                qDebug() << "pièce :"<< numeroAleatoire;
                                qDebug() << "orientation :" << orientationAleatoire;
                                m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Num", numeroAleatoire );
                                m_modbusMap.at(1)->setValue(QamModbusMap::HoldingRegister, "D_Tab_Ori", orientationAleatoire );
                                m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Dem", "1" );
                                usleep(20000);
                            }

                            if (m_modbusMap.at(1)->value(QamModbusMap::Coil, "D_Ok") == "1")
                            {
                             puzzleIhmDem();
                             m_modbusMap.at(1)->setValue(QamModbusMap::Coil, "D_Ok", "0" );
                             scara=false;
                             m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "1" );

                             if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "D_But") == "1")
                             {
                              m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "D_But", "0" );
                             }
                            }
                            }
                            Transfert1AutoDem();
                            Transfert2AutoDem();
                        }

                        if ((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Cap_ZHaut") == "1") && (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "A_Dem_Cap") == "1") )
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
                    // ************* REACTIVATION DES BOUTONS MANUELS
                    pbuPom->setEnabled( true ), pbuMoteur1->setEnabled( true ), pbuMoteur2->setEnabled( true ), pbuMonter->setEnabled( true ), pbuDescendre->setEnabled( true ),
                    pbuPinceFerme->setEnabled( true ) ,pbuPinceOuverte->setEnabled( true ), pbuVersPalette->setEnabled( true ), pbuVersTable->setEnabled( true ),
                    pbuVersT1->setEnabled( true ), pbuVersT2->setEnabled( true ), buteA->setEnabled( true ), buteS->setEnabled( true ), buteV->setEnabled( true ),
                    buteAtt->setEnabled( true ), piece->setEnabled( true), piece_2->setEnabled( true), piece_3->setEnabled( true), piece_4->setEnabled( true),
                    piece_5->setEnabled( true), piece_6->setEnabled( true), piece_7->setEnabled( true), piece_8->setEnabled( true), piece_9->setEnabled( true),
                    piece_10->setEnabled( true), piece_11->setEnabled( true), piece_12->setEnabled( true), piece_13->setEnabled( true), piece_14->setEnabled( true),
                    piece_15->setEnabled( true), piece_16->setEnabled( true), piece_17->setEnabled( true), piece_18->setEnabled( true), piece_19->setEnabled( true),
                    piece_20->setEnabled( true), pbuReadAll->setEnabled( true ), pbuAuto->setEnabled( true ), pbuReset->setEnabled( true ),pbuQuitter->setEnabled(true);

                    temps->setTime(QTime(0,0,0,0));
                    Barre->setValue(0);

                    m_modbusMap.at(i)->setValue(table, "BT1", "0" );
                    m_modbusMap.at(i)->setValue(table, "BT2", "0" );
                    m_modbusMap.at(i)->setValue(table, "T1", "0" );
                    m_modbusMap.at(i)->setValue(table, "T2", "0" );
                    m_modbusMap.at(i)->setValue(table, "C_Vision", "0" );
                    m_modbusMap.at(i)->setValue(table, "E_Attente", "0" );

                    return;
                }

            } //FIN MODE DEMONTAGE

            //MISE EN PLACE PALETTES POUR NOUVEAU CYCLE
            sleep(3);
            m_modbusMap.at(i)->setValue(table, "BT2_Dem_Mot", "0" );
            m_modbusMap.at(i)->setValue(table, "BT1_Dem_Mot", "0" );
            m_modbusMap.at(0)->setValue(table, "A_Dem_but", "0" );
            m_modbusMap.at(0)->setValue(table, "A_Mon_but", "0" );         
            m_modbusMap.at(0)->setValue(table, "C_But", "0" );
            m_modbusMap.at(0)->setValue(table, "E_But", "0" );
            m_modbusMap.at(0)->setValue(table, "D_But", "0" );
            m_modbusMap.at(0)->setValue(table, "CC1_A_Pom", "1" );

            if (stopcycle==1)
            {
                m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "1" );
                sleep(3);
                // ************* REACTIVATION DES BOUTONS MANUELS
                pbuPom->setEnabled( true ), pbuMoteur1->setEnabled( true ), pbuMoteur2->setEnabled( true ), pbuMonter->setEnabled( true ), pbuDescendre->setEnabled( true ),
                pbuPinceFerme->setEnabled( true ) ,pbuPinceOuverte->setEnabled( true ), pbuVersPalette->setEnabled( true ), pbuVersTable->setEnabled( true ),
                pbuVersT1->setEnabled( true ), pbuVersT2->setEnabled( true ), buteA->setEnabled( true ), buteS->setEnabled( true ), buteV->setEnabled( true ),
                buteAtt->setEnabled( true ), piece->setEnabled( true), piece_2->setEnabled( true), piece_3->setEnabled( true), piece_4->setEnabled( true),
                piece_5->setEnabled( true), piece_6->setEnabled( true), piece_7->setEnabled( true), piece_8->setEnabled( true), piece_9->setEnabled( true),
                piece_10->setEnabled( true), piece_11->setEnabled( true), piece_12->setEnabled( true), piece_13->setEnabled( true), piece_14->setEnabled( true),
                piece_15->setEnabled( true), piece_16->setEnabled( true), piece_17->setEnabled( true), piece_18->setEnabled( true), piece_19->setEnabled( true),
                piece_20->setEnabled( true), pbuReadAll->setEnabled( true ), pbuAuto->setEnabled( true ), pbuReset->setEnabled( true ),pbuQuitter->setEnabled(true);

                temps->setTime(QTime(0,0,0,0));
                Barre->setValue(0);

                m_modbusMap.at(i)->setValue(table, "BT1", "0" );
                m_modbusMap.at(i)->setValue(table, "BT2", "0" );
                m_modbusMap.at(i)->setValue(table, "T1", "0" );
                m_modbusMap.at(i)->setValue(table, "T2", "0" );
                m_modbusMap.at(i)->setValue(table, "C_Vision", "0" );
                m_modbusMap.at(i)->setValue(table, "E_Attente", "0" );
                return;
            }

            //NOUVEAU CYCLE COMPLET
            if((stop==0) && (stopcycle==0))
            {
            Auto();
            }
}

void manuel::puzzleIhmMon(){

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="0")
    this->piece0->setScene(scene);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="1")
    this->piece1->setScene(scene2);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="2")
    this->piece2->setScene(scene3);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="3")
    this->piece3->setScene(scene4);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="4")
    this->piece4->setScene(scene5);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="5")
    this->piece5->setScene(scene6);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="6")
    this->piece6->setScene(scene7);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="7")
    this->piece7->setScene(scene8);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="8")
    this->piece8->setScene(scene9);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="9")
    this->piece9->setScene(scene10);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="10")
    this->piece10->setScene(scene11);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="11")
    this->piece11->setScene(scene12);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="12")
    this->piece12->setScene(scene13);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="13")
    this->piece13->setScene(scene14);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="14")
    this->piece14->setScene(scene15);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="15")
    this->piece15->setScene(scene16);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="16")
    this->piece16->setScene(scene17);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="17")
    this->piece17->setScene(scene18);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="18")
    this->piece18->setScene(scene19);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="19")
    this->piece19->setScene(scene20);
}

void manuel::puzzleIhmDem(){

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="0")
    this->piece0->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="1")
    this->piece1->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="2")
    this->piece2->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="3")
    this->piece3->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="4")
    this->piece4->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="5")
    this->piece5->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="6")
    this->piece6->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="7")
    this->piece7->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="8")
    this->piece8->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="9")
    this->piece9->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="10")
    this->piece10->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="11")
    this->piece11->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="12")
    this->piece12->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="13")
    this->piece13->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="14")
    this->piece14->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="15")
    this->piece15->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="16")
    this->piece16->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="17")
    this->piece17->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="18")
    this->piece18->setScene(scene22);

    if(m_modbusMap.at(1)->value(QamModbusMap::HoldingRegister, "D_Tab_Num")=="19")
    this->piece19->setScene(scene22);
}

void manuel::puzzleIhmVision(){


    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="0")
    this->piecevision->setScene(scene);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="1")
    this->piecevision->setScene(scene2);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="2")
    this->piecevision->setScene(scene3);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="3")
    this->piecevision->setScene(scene4);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="4")
    this->piecevision->setScene(scene5);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="5")
    this->piecevision->setScene(scene6);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="6")
    this->piecevision->setScene(scene7);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="7")
    this->piecevision->setScene(scene8);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="8")
    this->piecevision->setScene(scene9);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="9")
    this->piecevision->setScene(scene10);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="10")
    this->piecevision->setScene(scene11);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="11")
    this->piecevision->setScene(scene12);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="12")
    this->piecevision->setScene(scene13);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="13")
    this->piecevision->setScene(scene14);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="14")
    this->piecevision->setScene(scene15);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="15")
    this->piecevision->setScene(scene16);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="16")
    this->piecevision->setScene(scene17);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="17")
    this->piecevision->setScene(scene18);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="18")
    this->piecevision->setScene(scene19);

    if(m_modbusMap.at(2)->value(QamModbusMap::HoldingRegister, "C_Tab_Num")=="19")
    this->piecevision->setScene(scene20);
}
