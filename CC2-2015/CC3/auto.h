#ifndef AUTO_H
#define AUTO_H



#include <QCloseEvent>
#include <QSettings>
#include <QSemaphore>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include "unistd.h"

class Auto
{
public:
    Auto();
    ~Auto();

};

#endif // AUTO_H
