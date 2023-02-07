#ifndef THREADAUTO_H
#define THREADAUTO_H
#include "ui_manuel.h"
#include <QtGui>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"


class threadauto : public QThread, private Ui::manuel
{
public :


    explicit threadauto (QObject *parent = 0, QamModbusMap*[3] = 0);



signals:



protected:

    virtual void run();

private :
    QamModbusMap *m_map[3];
    QList<QamModbusMap *>		m_modbusMap ;
    QList<QamTcpClient *>		m_tcpCLient ;
    QList<QamModbusMapViewer *>	m_modbusMapViewer ;

};

#endif // THREADAUTO_H
