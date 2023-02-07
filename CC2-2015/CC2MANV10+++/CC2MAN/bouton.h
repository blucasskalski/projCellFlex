#ifndef BOUTON_H
#define BOUTON_H

#include "manuel.h"
#include <QCloseEvent>
#include <QSettings>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include <QSemaphore>
#include "unistd.h"
#include <QThread>
#include <threadauto.h>

class bouton : public QMainWindow
{

public:

     bouton();
    ~bouton();

private:

};

#endif // BOUTON_H
