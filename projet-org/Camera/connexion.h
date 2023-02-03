#ifndef CONNEXION_H
#define CONNEXION_H

#include <QThread>
#include "ui_camera.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QGraphicsView>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QMessageBox>
#include <iostream>
#include <QSize>
#include <QDir>
#include <QTextStream>
#include <QTextStreamFunction>
#include <QTextStreamManipulator>
#include "qamtcpserver.h"
#include "qammodbusmap.h"
#include "communication.h"
#include "qamgraphicsscene.h"
#include "qamimgprocessor.h"
#include "qamimghistogram.h"
#include <QFileDialog>
#include <QTimer>

class Connexion : public QThread
{
    Q_OBJECT
public:
    explicit Connexion(QObject *parent = 0);

signals:

public slots:
    void connexion();

};

#endif // CONNEXION_H
