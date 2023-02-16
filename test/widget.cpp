#include "widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    csv ="./cellflex_scara";

    m_scara = new QamScara ;
    onglet = new QTabWidget;
    m_map= new QamModbusMap(QamModbusMap::ServerMode,this);
    m_map->setVerbose(true);
    m_map->loadMap(csv);

   // m_table -> QamModbusMap::Coil ;
    //setModbusMap(m_map);

    setupUi(this) ;
}

// le tronc (ZAXIS)**********************************************


void Widget::on_pbuMonter_clicked()
{
    qDebug() << "on_pbuMonter_clicked";
    m_scara->setAcceleration(QamScara::ZAxis,0.5);
    m_scara->moveRel(QamScara::ZAxis,scaling_Zaxis*0.999);

}

void Widget::on_pbuDescendre_clicked()
{
    qDebug() << "on_Descendre_clicked";
    m_scara->setAcceleration(QamScara::ZAxis,0.5);
    m_scara->moveRel(QamScara::ZAxis,-scaling_Zaxis);
}


//l'epaule (SHOULDER)/////////////////////////////////////////


void Widget::on_EpauleGauche_clicked()
    {
        m_scara->setAcceleration(QamScara::Shoulder,2);
        m_scara->moveRel(QamScara::Shoulder,scaling_epaule);

    }

void Widget::on_EpauleDroite_clicked()
    {
        m_scara->setAcceleration(QamScara::Shoulder,1);
        m_scara->moveRel(QamScara::Shoulder,-scaling_epaule);
    }


// le Coude (ElBOW)*************************************


void Widget::on_bras_gauche_clicked()
{
     qDebug() << "on_bras_gauche_clicked";

     m_scara->moveRel(QamScara::Elbow,scaling_coude);
}

void Widget::on_bras_droite_clicked()
{
    qDebug() <<"on_bras_droite_clicked Shoulder";

    m_scara->moveRel(QamScara::Elbow,-scaling_coude);
}


//le poignet (WRIST)/////////////////////////////////////////


void Widget::on_rota_ga_clicked()
{
    qDebug() << "on_rota_ga_clicked Wrist";

    m_scara->moveRel(QamScara::Wrist,scaling_poignet);

}

void Widget::on_rota_dr_clicked()
{
   qDebug() << "on_rota_dr_clicked ";

   m_scara->moveRel(QamScara::Wrist,-scaling_poignet);
}


//PInce (GRIPPER)******************************************


void Widget::on_serrer_clicked()
{
    qDebug() << "on_serrer_clicked";

    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);

}

void Widget::on_desserrer_clicked()
{
    qDebug() << "on_desserer_clicked";

    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);


}


//LES BOUTONS DE PARAMETRES///////////////////////////////////


void Widget::on_para_clicked()
{
    qDebug() << "on_para_clicked";
    onglet->setTabEnabled(0,false);
    onglet->setTabEnabled(1,true);
    tabWidget->setCurrentIndex(1);
}
  // BOUTON DE LA PAGE PARAMETRE POUR LES 2 PROCHAINS
void Widget::on_valide_para_accepted()
{
    //sauvegarder les para
    qDebug() << "on_valide_para_accepted";
    onglet->hide();
    onglet->setTabEnabled(1,false);
    onglet->setTabEnabled(0,true);
    tabWidget->setCurrentIndex(0);
}

void Widget::on_valide_para_rejected()
{
    //remmetre les para comme avant
    qDebug() << "on_valide_para_rejected";
    onglet->setTabEnabled(1,false);
    onglet->setTabEnabled(0,true);
    tabWidget->setCurrentIndex(0);
}


//BOUTON DE DEMMARAGE*****************************************



void Widget::on_pbuInit_clicked()
{
    m_scara ->open() ;

    m_scara ->reset(QamScara::ZAxis);
    m_scara ->reset(QamScara::Shoulder);
    m_scara ->reset(QamScara::Elbow);
    m_scara ->reset(QamScara::Wrist);
    m_scara ->reset(QamScara::Gripper);
    m_scara ->reset(QamScara::Tcp);

    m_scara ->home(QamScara::ZAxis);
    m_scara ->home(QamScara::Shoulder);
    m_scara ->home(QamScara::Elbow);
    m_scara ->home(QamScara::Wrist);
    m_scara ->home(QamScara::Gripper);
    m_scara ->home(QamScara::Tcp);

    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
}


void Widget::on_PbuOpen_clicked()
{ 
    m_scara ->open() ;
    //if ( !m_scara->open() ) return ;
    qDebug() << "pbu_Open_clicked";
}

void Widget::on_Reset_clicked()
{
    m_scara ->reset(QamScara::ZAxis);
    m_scara ->reset(QamScara::Shoulder);
    m_scara ->reset(QamScara::Elbow);
    m_scara ->reset(QamScara::Wrist);
    m_scara ->reset(QamScara::Gripper);
    m_scara ->reset(QamScara::Tcp);
}

void Widget::on_PbuHome_clicked()
{
    m_scara ->home(QamScara::ZAxis);
    m_scara ->home(QamScara::Shoulder);
    m_scara ->home(QamScara::Elbow);
    m_scara ->home(QamScara::Wrist);
    m_scara ->home(QamScara::Gripper);
    m_scara ->home(QamScara::Tcp);
      qDebug() << "on_PbuHome_clicked";

      m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
}


void Widget::on_arret_clicked()
{
   qDebug() << "on_arret_clicked";
   m_scara->halt();
}


// LES AUTRES BOUTONS/////////////////////////////////////////
void Widget::on_pbuStart_clicked()
{
  if(pbuStart->isChecked())
  {
       qDebug() << "on_pbu_Start_checked";

      //demarrer le mode esclaves
  }
  else{
      qDebug() << "pbu_Start_Unchecked";
  }

}


//Scaling

void Widget::on_Zaxis_huge_scale_clicked()
{
    scaling_Zaxis = 0.1   ;
}

void Widget::on_Zaxis_avr_clicked()
{
    scaling_Zaxis = 0.05   ;
}

void Widget::on_Zaxis_low_scale_clicked()
{
    scaling_Zaxis = 0.01   ;
}


//Shoulder
void Widget::on_shoulder_huge_scale_clicked()
{
    scaling_epaule = 0.25   ;
}

void Widget::on_shoulder_avr_scale_clicked()
{
    scaling_epaule = 0.1   ;
}

void Widget::on_shoulder_low_scale_clicked()
{
    scaling_epaule = 0.05   ;
}


//Elbow
void Widget::on_elbow_huge_scale_clicked()
{
    scaling_coude = 0.5   ;
}

void Widget::on_elbow_avr_scale_clicked()
{
    scaling_coude = 0.1   ;
}

void Widget::on_elbow_low_scale_clicked()
{
    scaling_coude = 0.005   ;
}

//Wrist
void Widget::on_rota_90_clicked()
{
    scaling_poignet = degToRad(90);
}

void Widget::on_rota_35_clicked()
{
    scaling_poignet = degToRad(35);
}

void Widget::on_rota_10_clicked()
{
     scaling_poignet = degToRad(10);
}

//Vitesse___________________________________

//Shoulder

void Widget::on_shoulder_fast_clicked()
{
    m_scara->setVelocity(QamScara::Shoulder,0.5);
    m_scara->setAcceleration(QamScara::Shoulder,1);
}

void Widget::on_shoulder_avr_speed_clicked()
{
    m_scara->setVelocity(QamScara::Shoulder,0.5);
    m_scara->setAcceleration(QamScara::Shoulder,0.5);
}

void Widget::on_shoulder_slow_clicked()
{
    m_scara->reset(QamScara::Shoulder);


}
//Elbow

void Widget::on_elbow_fast_clicked()
{
    m_scara->setVelocity(QamScara::Wrist,0.5);
    m_scara->setAcceleration(QamScara::Elbow,2);
}

void Widget::on_elbow_avr_speed_clicked()
{
    m_scara->setVelocity(QamScara::Wrist,0.5);
    m_scara->setAcceleration(QamScara::Elbow,1);
}

void Widget::on_elbow_slow_clicked()
{
  m_scara->reset(QamScara::Elbow);

}


//Wrist
void Widget::on_wrist_fast_clicked()
{
    m_scara->setVelocity(QamScara::Wrist,0.5);
    m_scara->setAcceleration(QamScara::Wrist,2);
}

void Widget::on_wrist_avr_speed_clicked()
{
    m_scara->setVelocity(QamScara::Wrist,0.5);
    m_scara->setAcceleration(QamScara::Wrist,1);
}

void Widget::on_wrist_slow_clicked()
{
    m_scara->reset(QamScara::Wrist);
}


/*coordonnees____________________________________*/
void Widget::on_waitpoint_clicked()         //place pour jeter piece
{
    m_scara->moveAbs(500.00, 200.00, -50.00, 0.00);
}

/*les pieces________________________________*/

//1ere ranger

void Widget::on_Piece1_clicked()
{
    m_scara->moveAbs(385.53, -230.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, -230.31, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, -230.31, -50 , 0);
}

void Widget::on_Piece2_clicked()
{
    m_scara->moveAbs(385.53, -166.31, -50 , 00);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, -166.31, -160 , 00);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, -166.31, -50 , 00);
}

void Widget::on_Piece3_clicked()
{
    m_scara->moveAbs(387.53, -100.41, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(387.53, -100.41, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(387.53, -100.41, -50 , 0);
}

void Widget::on_Piece4_clicked()
{
    m_scara->moveAbs(385.53, -36.80, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, -36.80, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, -36.80, -50 , 0);
}

void Widget::on_Piece5_clicked()
{
    m_scara->moveAbs(385.53, 30.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, 30.31, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(385.53, 30.31, -50 , 0);
}

//2eme ligne

void Widget::on_Piece6_clicked()
{
    m_scara->moveAbs(449.53, -230.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(449.53, -230.31, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(449.53, -230.31, -50 , 0);
}

void Widget::on_Piece7_clicked()
{
    m_scara->moveAbs(449.53, -165.8, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(449.53, -165.8, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(449.53, -165.8, -50 , 0);
}

void Widget::on_Piece8_clicked()
{
    m_scara->moveAbs(451.53, -100.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(451.53, -100.31, -165 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(451.53, -100.31, -50 , 0);

}

void Widget::on_Piece9_clicked()
{
     m_scara->moveAbs(449.53, -36.31, -50 , 0);
     m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
     m_scara->moveAbs(449.53, -36.31, -160 , 0);
     m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
     m_scara->moveAbs(449.53, -36.31, -50 , 0);
}

void Widget::on_Piece10_clicked()
{
    m_scara->moveAbs(449.53, 30.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(449.53, 30.31, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(449.53, 30.31, -50 , 0);
}

//3eme ligne
void Widget::on_Piece11_clicked()
{
    m_scara->moveAbs(513.53, -229.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(513.53, -229.31, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(513.53, -229.31, -50 , 0);
}

void Widget::on_Piece12_clicked()
{
    m_scara->moveAbs(513.53, -164.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(513.53, -164.31, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(513.53, -164.31, -50 , 0);
}

void Widget::on_Piece13_clicked()
{
    m_scara->moveAbs(515.53, -99.81, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(515.53, -99.81, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(515.53, -99.81, -50 , 0);
}

void Widget::on_Piece14_clicked()
{
     m_scara->moveAbs(513.53, -34, -50 , 0);
     m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
     m_scara->moveAbs(513.53, -34, -160 , 0);
     m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
     m_scara->moveAbs(513.53, -34, -50 , 0);
}

void Widget::on_Piece15_clicked()
{
    m_scara->moveAbs(513.53, 28.31, -50 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(513.53, 28.31, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(513.53, 28.31, -50 , 0);

}
 //4eme ligne
void Widget::on_Piece16_clicked()
{
    m_scara->moveAbs(586.53, -230, -50 , 0);
    m_scara->moveAbs(586.53, -230, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(586.53, -230, -50 , 0);
}
void Widget::on_Piece17_clicked()
{
    m_scara->moveAbs(586.53, -164, -50 , 0);
    m_scara->moveAbs(586.53, -164, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(586.53, -164, -50 , 0);
}

void Widget::on_Piece18_clicked()
{
    m_scara->moveAbs(586.53, -97, -50 , 0);
    m_scara->moveAbs(586.53, -97, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(586.53, -97, -50 , 0);
}

void Widget::on_Piece19_clicked()
{
     m_scara->moveAbs(586, -32.5, -50 , 0);
     m_scara->moveAbs(586, -32.5, -160 , 0);
     m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
     m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
     m_scara->moveAbs(586, -32.5, -50 , 0);
}

void Widget::on_Piece20_clicked()
{
    m_scara->moveAbs(586, 33, -50 , 0);
    m_scara->moveAbs(586, 33, -160 , 0);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_OPEN - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(QamScara::Gripper,(SCARA_GRIPPER_CLOSE - SCARA_GRIPPER_OFFS)/1000);
    m_scara->moveAbs(586, 33, -50 , 0);

}
