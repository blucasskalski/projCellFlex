#include "threadauto.h"

threadauto::threadauto(QObject *parent, QamModbusMap* m_map[3]) :
    QThread(parent)
{


}

void threadauto::run(){


        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "A_Ver_Pince", "1" );
        sleep(1);
        m_modbusMap.at(0)->setValue(QamModbusMap::HoldingRegister, "A_Ver_Pince", "0" );


}




