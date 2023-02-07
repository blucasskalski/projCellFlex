#ifndef BOUTON_H
#define BOUTON_H

#define API 0
#define VISION 1
#define SCARA 2


#include "manuel.h"
#include <QCloseEvent>
#include <QSettings>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include <QSemaphore>
#include "unistd.h"


class bouton : public QMainWindow
{

public:
     bouton();
    ~bouton();

};

#endif // BOUTON_H
