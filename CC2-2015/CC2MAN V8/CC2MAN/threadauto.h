#ifndef THREADAUTO_H
#define THREADAUTO_H
#include "ui_manuel.h"
#include <QtGui>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include <QThread>



class Threadauto : public QThread, private Ui::manuel
{
public :


     Threadauto();

    ~Threadauto();

signals:

    void s_transfert();


protected:

    virtual void run();

private :
    QamModbusMap *m_map;
    QList<QamModbusMap *>		m_modbusMap ;
    QList<QamTcpClient *>		m_tcpCLient ;
    QList<QamModbusMapViewer *>	m_modbusMapViewer ;

    public slots:




private:


};

#endif // THREADAUTO_H
