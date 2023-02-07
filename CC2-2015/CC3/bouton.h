#ifndef BOUTON_H
#define BOUTON_H

#define API 0
#define VISION 1
#define SCARA 2


#include "cc3.h"
#include "auto.h"
#include <QSemaphore>
#include <QCloseEvent>
#include <QSettings>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include "unistd.h"


class bouton : public QMainWindow
{

public:
     bouton();
    ~bouton();
};

#endif // BOUTON_H
