#include "bouton.h"
#include "cc3.h"
#include <QMessageBox>
#include <QFileDialog>

bouton::bouton()
{

}

bouton::~bouton()
{

}

//Codage des boutons pour controler l'automate//
void CC3::Pince(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if( m_modbusMap.at(i)-> value (table, "A_Ver_Pince") == "1" )
    {
    m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "0" );
    pbuPince->setText("Pince ouverte");
    }
    else{
    m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "1" );
    pbuPince->setText("Pince fermé");
    }
}

void CC3::Verver(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if( m_modbusMap.at(i)-> value (table, "A_Cap_ZHaut") == "0" )
    {
    m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "0" );
    m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "1" );
    pbuVerver->setText("vérin haut");
    usleep(1500000);
    if( m_modbusMap.at(i)-> value (table, "A_Cap_ZHaut") == "0" )
    {
        pbuVerhori -> setEnabled(true);
        piece -> setEnabled(true);
        piece_2 -> setEnabled(true);
        piece_3 -> setEnabled(true);
        piece_4 -> setEnabled(true);
        piece_5 -> setEnabled(true);
        piece_6 -> setEnabled(true);
        piece_7 -> setEnabled(true);
        piece_8 -> setEnabled(true);
        piece_9 -> setEnabled(true);
        piece_10 -> setEnabled(true);
        piece_11 -> setEnabled(true);
        piece_12 -> setEnabled(true);
        piece_13 -> setEnabled(true);
        piece_14 -> setEnabled(true);
        piece_15 -> setEnabled(true);
        piece_16 -> setEnabled(true);
        piece_17 -> setEnabled(true);
        piece_18 -> setEnabled(true);
        piece_19 -> setEnabled(true);
        piece_20 -> setEnabled(true);
        }
    }
    else
    {
        m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "1" );
        m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "0" );
        pbuVerver->setText("vérin bas");
        pbuVerhori -> setEnabled(false);
        piece -> setEnabled(false);
        piece_2 -> setEnabled(false);
        piece_3 -> setEnabled(false);
        piece_4 -> setEnabled(false);
        piece_5 -> setEnabled(false);
        piece_6 -> setEnabled(false);
        piece_7 -> setEnabled(false);
        piece_8 -> setEnabled(false);
        piece_9 -> setEnabled(false);
        piece_10 -> setEnabled(false);
        piece_11 -> setEnabled(false);
        piece_12 -> setEnabled(false);
        piece_13 -> setEnabled(false);
        piece_14 -> setEnabled(false);
        piece_15 -> setEnabled(false);
        piece_16 -> setEnabled(false);
        piece_17 -> setEnabled(false);
        piece_18 -> setEnabled(false);
        piece_19 -> setEnabled(false);
        piece_20 -> setEnabled(false);

    }
}

void CC3::Verhori(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(m_modbusMap.at(i)-> value (table, "A_Cap_XTab") == "1" )
    {
        m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "0" );
        m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "1" );
        pbuVerhori->setText("position palette");
    }
    else
    {
        m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "1" );
        m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "0" );
        pbuVerhori->setText("position table");
    }
}

void CC3::Moteur1(){

    if(moteur == 0){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "1" );
    moteur = 1;
    pbuMoteur1->setText("Arret");
    }
    else{
        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "0" );
        moteur = 0 ;
    }
}

void CC3::Moteur2(){

    if(moteur2 == 0){
        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "1" );
    moteur2 = 1;
    pbuMoteur2->setText("Arret");
    }
    else{
        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "0" );
        moteur2 = 0 ;
    }
}

void CC3::Reset(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "BT1", "0" );
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
    pbuMoteur2->setText("Moteur2");
    moteur = 0 ;
    moteur2 = 0 ;
    transfert = 0 ;
    transfert2 = 0 ;
}


void CC3::TransfertVersT2(){
    if(transfert == 0){
        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
    transfert = 1;
    }
    else{
        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "T1_Ver", "0" );
        transfert = 0 ;
    }
}

void CC3::TransfertVersT1(){
    if(transfert == 0){
        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
    transfert2 = 1;
    }
    else{
        int i = tabWidget->currentIndex() ;
        QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
        m_modbusMap.at(i)->setValue(table, "T2_Ver", "0" );
        transfert2 = 0 ;
    }
}

void CC3::Piece1(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_01", "1" );
    m_modbusMap.at(i)->setValue(table, "A_01", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece2(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_02", "1" );
    m_modbusMap.at(i)->setValue(table, "A_02", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece3(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_03", "1" );
    m_modbusMap.at(i)->setValue(table, "A_03", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece4(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_04", "1" );
    m_modbusMap.at(i)->setValue(table, "A_04", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece5(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_05", "1" );
    m_modbusMap.at(i)->setValue(table, "A_05", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece6(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_06", "1" );
    m_modbusMap.at(i)->setValue(table, "A_06", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece7(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_07", "1" );
    m_modbusMap.at(i)->setValue(table, "A_07", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece8(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_08", "1" );
    m_modbusMap.at(i)->setValue(table, "A_08", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece9(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_09", "1" );
    m_modbusMap.at(i)->setValue(table, "A_09", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece10(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_10", "1" );
    m_modbusMap.at(i)->setValue(table, "A_10", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece11(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_11", "1" );
    m_modbusMap.at(i)->setValue(table, "A_11", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece12(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_12", "1" );
    m_modbusMap.at(i)->setValue(table, "A_12", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece13(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_13", "1" );
    m_modbusMap.at(i)->setValue(table, "A_13", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece14(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_14", "1" );
    m_modbusMap.at(i)->setValue(table, "A_14", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece15(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_15", "1" );
    m_modbusMap.at(i)->setValue(table, "A_15", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece16(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_16", "1" );
    m_modbusMap.at(i)->setValue(table, "A_16", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece17(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_17", "1" );
    m_modbusMap.at(i)->setValue(table, "A_17", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece18(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_18", "1" );
    m_modbusMap.at(i)->setValue(table, "A_18", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece19(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_19", "1" );
    m_modbusMap.at(i)->setValue(table, "A_19", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}

void CC3::Piece20(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::Coil;
    m_modbusMap.at(i)->setValue(table, "A_20", "1" );
    m_modbusMap.at(i)->setValue(table, "A_20", "0" );
    while(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "0") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ) ||
          ( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "0" ) )
    {
        pbuVerver -> setEnabled(false);
    }

    if(( m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_X_At_Pnt") == "1") && (m_modbusMap.at(i)-> value(QamModbusMap::Coil, "Axis_Y_At_Pnt") == "1" ))
    {
        pbuVerver -> setEnabled(true);
    }
}
//Buté//
void CC3::ButeA(int state){
    int i =tabWidget->currentIndex() ;
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

void CC3::ButeV(int state){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Unchecked)
    m_modbusMap.at(i)->setValue(table, "C_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "C_But", "0" );
}

void CC3::ButeS(int state){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Unchecked)
    m_modbusMap.at(i)->setValue(table, "D_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "D_But", "0" );
}

void CC3::ButeAtt(int state){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Unchecked)
    m_modbusMap.at(i)->setValue(table, "E_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "E_But", "0" );
}
