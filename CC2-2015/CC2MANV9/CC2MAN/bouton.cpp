#include "bouton.h"
#include "manuel.h"


bouton::bouton()
{

}

bouton::~bouton()
{

}

//*********Codage des boutons pour controler l'automate**********//
// ************************************************************* //


void manuel::PinceOuverte()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "0" );
}

void manuel::PinceFerme()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "1" );
}

void manuel::Monter()
{

    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "0" );
    m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "1" );

    while(m_modbusMap.at(i)->value(table, "A_Cap_ZHaut") != "1" )

        {
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
        pbuVersTable->setEnabled(false);
        pbuVersPalette->setEnabled(false);
        }

    if(m_modbusMap.at(i)->value(table, "A_Cap_ZHaut") == "1" )

        {
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
        pbuVersTable->setEnabled(true);
        pbuVersPalette->setEnabled(true);
        }
}

void manuel::Descendre()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "0" );
    m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "1" );


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
    pbuVersTable->setEnabled(false);
    pbuVersPalette->setEnabled(false);//		QString host = m_modbusMap.at( index )->host() ;	// new 1.1
    //		quint16 port = m_modbusMap.at( index )->port() ;

}

void manuel::VersPalette()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "1" );
}

void manuel::VersTable()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "1" );
}

void manuel::Moteur1()
{

    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "BT1_Mon_Mot") == "0" )
    {
        int i = 0 ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "1" );
        pbuMoteur1->setText("Arret");
    }

    else
    {
        pbuMoteur1->setText("Moteur1");
        int i = 0 ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "0" );
    }
}

void manuel::Moteur2()
{

    if(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "BT2_Mon_Mot") == "0" )
    {
        int i = 0 ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "1" );
        pbuMoteur2->setText("Arret");
    }

    else
    {
        pbuMoteur2->setText("Moteur2");
        int i = 0 ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "0" );
    }
}

void manuel::TransfertVersT2()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    pbuVersT2->setEnabled(false);

    while((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") != "1"))
    {
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "0" );
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T2_Mon_Cap_Dep") == "1"))
    {
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
        m_modbusMap.at(i)->setValue(table, "T2_Mon_Mot", "1" );
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
    pbuVersT2->setEnabled(true);

}

void manuel::TransfertVersT1()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    pbuVersT1->setEnabled(false);
    while((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") != "1"))
    {
        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );

    }

    if((m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Dep") == "1"))
    {
        m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "1" );
    }


    while(m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "1")
    {
        m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "T1_Dem_Cap_Dep" ) ;
         m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "T1_Dem_Cap_Arr" ) ;
    }

    if (m_modbusMap.at(0)->value(QamModbusMap::HoldingRegister, "T1_Mon_Cap_Arr") == "0")
    {
        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
        m_modbusMap.at(i)->setValue(table, "T1_Mon_Mot", "0" );


    }
    pbuVersT1->setEnabled(true);
}

void manuel::Piece1()
{


    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_01", "1" );
    m_modbusMap.at(i)->setValue(table, "A_01", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    } 

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece2()
{


    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_02", "1" );
    m_modbusMap.at(i)->setValue(table, "A_02", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece3()
{

    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_03", "1" );
    m_modbusMap.at(i)->setValue(table, "A_03", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece4()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_04", "1" );
    m_modbusMap.at(i)->setValue(table, "A_04", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece5()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_05", "1" );
    m_modbusMap.at(i)->setValue(table, "A_05", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece6()
{


    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_06", "1" );
    m_modbusMap.at(i)->setValue(table, "A_06", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece7()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_07", "1" );
    m_modbusMap.at(i)->setValue(table, "A_07", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece8()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_08", "1" );
    m_modbusMap.at(i)->setValue(table, "A_08", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece9()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_09", "1" );
    m_modbusMap.at(i)->setValue(table, "A_09", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece10()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_10", "1" );
    m_modbusMap.at(i)->setValue(table, "A_10", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece11()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_11", "1" );
    m_modbusMap.at(i)->setValue(table, "A_11", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece12()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_12", "1" );
    m_modbusMap.at(i)->setValue(table, "A_12", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece13()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_13", "1" );
    m_modbusMap.at(i)->setValue(table, "A_13", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece14()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_14", "1" );
    m_modbusMap.at(i)->setValue(table, "A_14", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece15()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_15", "1" );
    m_modbusMap.at(i)->setValue(table, "A_15", "0" );

    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece16()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_16", "1" );
    m_modbusMap.at(i)->setValue(table, "A_16", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece17()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_17", "1" );
    m_modbusMap.at(i)->setValue(table, "A_17", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece18()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_18", "1" );
    m_modbusMap.at(i)->setValue(table, "A_18", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece19()
{

    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_19", "1" );
    m_modbusMap.at(i)->setValue(table, "A_19", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

void manuel::Piece20()
{
    int i = 0 ;

    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;

    m_modbusMap.at(i)->setValue(table, "Axis_X_At_Pnt", "0" );
    m_modbusMap.at(i)->setValue(table, "Axis_Y_At_Pnt", "0" );

    m_modbusMap.at(i)->setValue(table, "A_20", "1" );
    m_modbusMap.at(i)->setValue(table, "A_20", "0" );


    while(((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" )) ||
          ((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0")))

    {
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(false);
    pbuMonter->setEnabled(false);
    }

    if((m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1" ) && (m_modbusMap.at(0)->value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
{

    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_X_At_Pnt" ) ;
    m_modbusMap.at(i)->remoteValue( (QamModbusMap::PrimaryTable)table, "Axis_Y_At_Pnt" ) ;
    pbuDescendre->setEnabled(true);
    pbuMonter->setEnabled(true);
    }
}

//Butés//

void manuel::ButeA(int state)
{
    int i =0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Unchecked){
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "1" );
    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "1" );
    }
    else{
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Dem_but", "0" );
    }
}

void manuel::ButeV(int state)
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Unchecked)
    m_modbusMap.at(i)->setValue(table, "C_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "C_But", "0" );
}

void manuel::ButeS(int state)
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Unchecked)
    m_modbusMap.at(i)->setValue(table, "D_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "D_But", "0" );
}

void manuel::ButeAtt(int state)
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Unchecked)
    m_modbusMap.at(i)->setValue(table, "E_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "E_But", "0" );
}

//Arrêt rapide//

void manuel::Reset()
{
    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;

    /*m_modbusMap.at(i)->setValue(table, "BT1", "0" );
    m_modbusMap.at(i)->setValue(table, "BT2", "0" );
    m_modbusMap.at(i)->setValue(table, "T1", "0" );
    m_modbusMap.at(i)->setValue(table, "T2", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Cycle_U", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Tab", "0" );
    m_modbusMap.at(i)->setValue(table, "C_Vision", "0" );
    m_modbusMap.at(i)->setValue(table, "D_Scara", "0" );
    m_modbusMap.at(i)->setValue(table, "E_Attente", "0" );
    m_modbusMap.at(i)->setValue(table, "CC1_Mode", "0" );
    buteA->setChecked(true);
    buteS->setChecked(true);
    buteV->setChecked(true);
    buteAtt->setChecked(true);
    pbuMoteur1->setText("Moteur1");
    pbuMoteur2->setText("Moteur2");*/

    stop=1;
}



void manuel::Pom()
{
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
    pbuMonter->setEnabled( false ) ;
    pbuDescendre->setEnabled( false ) ;
    pbuPinceFerme->setEnabled( false ) ;
    pbuPinceOuverte->setEnabled( false ) ;
    pbuVersPalette->setEnabled( false ) ;
    pbuVersTable->setEnabled( false ) ;

    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "CC1_A_Pom", "0" );
    m_modbusMap.at(i)->setValue(table, "CC1_A_Pom", "1" );



    sleep(5);

    while((m_modbusMap.at(0)->value(table, "CC1_A_Pom_Ok") != "1" ))
    {
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
        pbuMonter->setEnabled( false ) ;
        pbuDescendre->setEnabled( false ) ;
        pbuPinceFerme->setEnabled( false ) ;
        pbuPinceOuverte->setEnabled( false ) ;
        pbuVersPalette->setEnabled( false ) ;
        pbuVersTable->setEnabled( false ) ;
    }

    if((m_modbusMap.at(0)->value(table, "CC1_A_Pom_Ok") == "1" ))
    {
        pbuPom->setEnabled( true) ;
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
        pbuMonter->setEnabled( true ) ;
        pbuDescendre->setEnabled( true ) ;
        pbuPinceFerme->setEnabled( true ) ;
        pbuPinceOuverte->setEnabled( true ) ;
        pbuVersPalette->setEnabled( true ) ;
        pbuVersTable->setEnabled( true ) ;
    }
}

