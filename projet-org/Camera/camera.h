#ifndef CAMERA_H
#define CAMERA_H

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


namespace Ui {
class camera;
}

class camera : public QWidget
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = 0);
    ~camera();
     void affichage_image();
     void test_traitement_photo();
     void lire_BDD();
     void communication();
     void ecrir_log(QString);
     void ecrir_log_pb(QString);
     void ecrir_log_bleu(QString);
     void fenetre_1(QImage*);
     void fenetre_2(QImage*);
     void photo (QImage*);
     void reglage();
     QImage traitement_image();
     void reconnaissance();
     int comparaison_line2(QString, QString,int min =0, int max =31);
     int comparaison_line1(QString, QString,int min =0, int max =31);
     int comparaison_grid(QString, QString);
     bool comparaison_densite(float, float);
     void nouvelle_tentative();
     void netoyage_bin();
     void netoyage_signature();
     void envoie_donees();

public slots :
    void erreurConnection(QNetworkReply::NetworkError);
    void connection();
    void reponse_connexion();
    void traitement_photo();
    void mousepoint(int, int, int, int);
    void config();
    void valeur_bin1(int);
    void valeur_bin2(int);
    void valeur_blanc1(int);
    void valeur_blanc2(int);
    void message_photo();
    void save_config();
    void traitement_spe();
    void creation_BdD();
    void reglage_button();

private:
    Ui::camera *ui;
    bool error,premier_passage;
    QImage image;
    bool piece;
    QamModbusMap *m_map;
    QamTcpServer* m_server;
    QamModbusMap::PrimaryTable table, m_table_holding;
    Communication* attente;
    Qamgraphicsscene *scene_cam, *scene_config;
    QGraphicsPixmapItem *pix ;
    QGraphicsScene *scene_signature, *scene_bin;
    QamImgProcessor *traitement;
    Qamgraphicsscene *photo_cut;
    int position_x, position_y, position_h, position_w, bin1, bin2, blanc1, blanc2, nb_piece, rotation_piece,tempo, temps;
    quint32 line_1, line_2,line_vert_1,line_vert_2;
    quint64 grid;
    float densite_photo, tempo_densite;
    QString line_AS1,line_AS2, grid_AS, line_AS1_spe,grid_AS_spe, line_AS2_spe, line_vert_AS_1, line_vert_AS_2;
    QString line_vert_AS_1_spe,line_vert_AS_2_spe;
    QamImgHistogram *histogramme;
    //QamImgProcessor *traitement;


};

#endif // CAMERA_H
