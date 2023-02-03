#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QThread>
#include "qammodbusmap.h"

class Communication : public QThread
{
    Q_OBJECT
public:
    explicit Communication(QObject *parent = 0, QamModbusMap * m_map = NULL);
    bool en_cours;
    void set(bool);

    virtual ~Communication();

private :
    QamModbusMap * m_map;
    QamModbusMap::PrimaryTable m_table;
    bool stop;

protected :
    virtual void run();

signals:
    void faire_traitement();


public slots:
    void arret();


};

#endif // COMMUNICATION_H
