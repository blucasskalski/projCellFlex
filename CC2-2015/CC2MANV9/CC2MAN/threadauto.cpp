#include "threadauto.h"

Threadauto::Threadauto()
{

}

Threadauto::~Threadauto()
{

}

void Threadauto::run(){




    int i = 0 ;
    QamModbusMap::PrimaryTable table = QamModbusMap::HoldingRegister;
    m_modbusMap.at(i)->setValue(table, "BT1_Mon_Mot", "1" );
    pbuMoteur1->setText("Arret");
    sleep(1);
   // qDebug() <<"thread secondaire  :" << test.thread();


}






