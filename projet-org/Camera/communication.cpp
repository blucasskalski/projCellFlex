#include "communication.h"
#include <qdebug.h>

Communication::Communication(QObject *parent, QamModbusMap * m_map) :
    QThread(parent)
{
    this->m_map = m_map;
    this->m_table = QamModbusMap::Coil;
    stop = false;
    en_cours = false;
}

Communication::~Communication()
{
    exit();
    wait();
}

void Communication::run()
{
     while(1)
    {
        sleep(1);
        if(stop)
        {
            exit();
            return;
        }
        if(en_cours == false && m_map->value(m_table, "C_Mon" ) == "1")
        {
            sleep(3);
            emit faire_traitement();
            en_cours = true;
        }
    }
}

void Communication::arret()
{
    stop = true;

}

void Communication::set(bool traitement)
{
    en_cours = traitement;
}
