#ifndef WIDGET_H
#define WIDGET_H

#include "iostream"
#include "QCloseEvent"
#include "ui_widget.h"
#include "qamscara.h"
#include "qammodbusmap.h"
#include "qamtcpserver.h"
#include "qammodbusmapviewer.h"

#include <QtNetwork>


class Widget : public QWidget, private Ui::Scara
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

public slots:
    //bouton systeme
    void on_arret_clicked();    //arret d'urgence   
    void on_pbuStart_clicked();
    void on_PbuOpen_clicked();
    void on_Reset_clicked();
    void on_PbuHome_clicked();
    void on_pbuInit_clicked();

    void on_para_clicked(); //changer d'onglet , 0=page principale,1=page apres etc...
    void on_valide_para_accepted();  //valide parametre
    void on_valide_para_rejected();

    //bouton deplacement

    void on_pbuMonter_clicked();    //mvt vertical(axe Y)
    void on_pbuDescendre_clicked();

    void on_EpauleGauche_clicked(); //epaule
    void on_EpauleDroite_clicked();

    void on_bras_gauche_clicked();   //coude
    void on_bras_droite_clicked();

    void on_rota_ga_clicked();   //rota des pinces (poignet)
    void on_rota_dr_clicked();

    void on_serrer_clicked();   //ecartement des pinces
    void on_desserrer_clicked();


    //Bouton de reglage
           //Amplitude des mouvement des Axes
    void on_Zaxis_huge_scale_clicked();
    void on_Zaxis_avr_clicked();
    void on_Zaxis_low_scale_clicked();

    void on_shoulder_huge_scale_clicked();
    void on_shoulder_avr_scale_clicked();
    void on_shoulder_low_scale_clicked();

    void on_elbow_huge_scale_clicked();
    void on_elbow_avr_scale_clicked();
    void on_elbow_low_scale_clicked();

    void on_rota_90_clicked();
    void on_rota_35_clicked();
    void on_rota_10_clicked();
            //Vitesse des Axe





private slots:
    void on_shoulder_slow_clicked();

    void on_shoulder_avr_speed_clicked();

    void on_shoulder_fast_clicked();

    void on_elbow_fast_clicked();

    void on_elbow_avr_speed_clicked();

    void on_elbow_slow_clicked();

    void on_wrist_fast_clicked();

    void on_wrist_avr_speed_clicked();

    void on_wrist_slow_clicked();

    void on_waitpoint_clicked();

    void on_Piece1_clicked();

    void on_Piece2_clicked();

    void on_Piece3_clicked();

    void on_Piece4_clicked();

    void on_Piece5_clicked();

    void on_Piece6_clicked();

    void on_Piece11_clicked();

    void on_Piece16_clicked();

    void on_Piece7_clicked();

    void on_Piece8_clicked();

    void on_Piece9_clicked();

    void on_Piece10_clicked();

    void on_Piece12_clicked();

    void on_Piece13_clicked();

    void on_Piece14_clicked();

    void on_Piece15_clicked();

    void on_Piece17_clicked();

    void on_Piece18_clicked();

    void on_Piece19_clicked();

    void on_Piece20_clicked();

private:
    QamScara*      m_scara;
    QTabWidget*    onglet;
    QString        csv;
    QamModbusMap*  m_map;
    QamModbusMap::PrimaryTable m_table, m_table_holding;
    QamTcpServer* m_server;

    float   scaling_Zaxis = 0.05 ;
    float   scaling_epaule = 0.05;
    float   scaling_coude = 0.05;
    float   scaling_poignet = 0.05;


};

#endif // WIDGET_H
