#include "bouton.h"
#include "manuel.h"
#include <QMessageBox>
#include <QFileDialog>

bouton::bouton()
{

}

bouton::~bouton()
{

}

//Codage des boutons pour controler l'automate//
void manuel::PinceOuverte(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "1" );
}

void manuel::PinceFerme(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_Pince", "0" );
}

void manuel::Monter(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "0" );
    m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "1" );
}

void manuel::Descendre(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_ver_ZHaut", "0" );
    m_modbusMap.at(i)->setValue(table, "A_ver_ZBas", "1" );
}

void manuel::VersPalette(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "1" );
}

void manuel::VersTable(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Ver_XPal", "0" );
    m_modbusMap.at(i)->setValue(table, "A_Ver_XTab", "1" );
}

void manuel::Moteur1(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "1" );
    pbuMoteur1->setText("Arret");
}

void manuel::Moteur2(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "BT2_Mon_Mot", "1" );
    pbuMoteur2->setText("Arret");
}

void manuel::TransfertVersT2(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "T1_Ver", "1" );
}

void manuel::TransfertVersT1(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "T2_Ver", "1" );
}

void manuel::Piece1(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "0" );
}

void manuel::Piece2(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "1" );
}

void manuel::Piece3(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "2" );
}

void manuel::Piece4(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "3" );
}

void manuel::Piece5(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "4" );
}

void manuel::Piece6(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "5" );
}

void manuel::Piece7(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "6" );
}

void manuel::Piece8(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "7" );
}

void manuel::Piece9(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "8" );
}

void manuel::Piece10(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "9" );
}

void manuel::Piece11(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "10" );
}

void manuel::Piece12(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "11" );
}

void manuel::Piece13(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "12" );
}

void manuel::Piece14(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "13" );
}

void manuel::Piece15(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "14" );
}

void manuel::Piece16(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "15" );
}

void manuel::Piece17(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "16" );
}

void manuel::Piece18(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "17" );
}

void manuel::Piece19(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "18" );
}

void manuel::Piece20(){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "A_Tab_Num", "19" );
}
//Buté//
void manuel::ButeA(int state){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Checked)
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "A_Mon_but", "0" );

}

void manuel::ButeV(int state){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Checked)
    m_modbusMap.at(i)->setValue(table, "C_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "C_But", "0" );
}

void manuel::ButeS(int state){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Checked)
    m_modbusMap.at(i)->setValue(table, "D_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "D_But", "0" );
}

void manuel::ButeAtt(int state){
    int i = tabWidget->currentIndex() ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    if(state == Qt::Checked)
    m_modbusMap.at(i)->setValue(table, "E_But", "1" );
    else
    m_modbusMap.at(i)->setValue(table, "E_But", "0" );
}
