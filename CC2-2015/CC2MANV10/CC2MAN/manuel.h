#ifndef MANUEL_H
#define MANUEL_H

#include "ui_manuel.h"
#include <QCloseEvent>
#include <QSettings>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include <QSemaphore>
#include "unistd.h"
#include <QTimer>
#include <QThread>
#include <QProgressBar>

namespace Ui {
class manuel;
}

class manuel : public QMainWindow , private Ui::manuel
{
    Q_OBJECT

public:

    int a=0;
    int test;
    int test2;

    char tableau[20][10]= {

        "A_01","A_02","A_03","A_04","A_05","A_06","A_07",
        "A_08","A_09","A_10","A_11","A_12","A_13","A_14",
        "A_15","A_16","A_17","A_18","A_19","A_20"
    };

    //STOCKAGE DU TRAITEMENT POUR SCARA
    QString numero[20]{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
                       "0","0","0","0","0"};
    QString orientation[20]{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
                       "0","0","0","0","0"};

    explicit manuel(QWidget *parent = 0);
    ~manuel();  

    int stop = 0;
    int stopcycle=0;
    int b=0;
    int f=0;
    int g=0;
    int v=0;
    bool scara = false;
    bool vision = false;
    bool attente = false;

    QPixmap pixmap,pixmap2,pixmap3,pixmap4,pixmap5,pixmap6,pixmap7,pixmap8,pixmap9,pixmap10,pixmap11
    ,pixmap12,pixmap13,pixmap14,pixmap15,pixmap16,pixmap17,pixmap18,pixmap19,pixmap20,pixmap22;

    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsScene* scene2 = new QGraphicsScene;
    QGraphicsScene* scene3 = new QGraphicsScene;
    QGraphicsScene* scene4 = new QGraphicsScene;
    QGraphicsScene* scene5 = new QGraphicsScene;
    QGraphicsScene* scene6 = new QGraphicsScene;
    QGraphicsScene* scene7 = new QGraphicsScene;
    QGraphicsScene* scene8 = new QGraphicsScene;
    QGraphicsScene* scene9 = new QGraphicsScene;
    QGraphicsScene* scene10= new QGraphicsScene;
    QGraphicsScene* scene11= new QGraphicsScene;
    QGraphicsScene* scene12= new QGraphicsScene;
    QGraphicsScene* scene13= new QGraphicsScene;
    QGraphicsScene* scene14= new QGraphicsScene;
    QGraphicsScene* scene15= new QGraphicsScene;
    QGraphicsScene* scene16= new QGraphicsScene;
    QGraphicsScene* scene17= new QGraphicsScene;
    QGraphicsScene* scene18= new QGraphicsScene;
    QGraphicsScene* scene19= new QGraphicsScene;
    QGraphicsScene* scene20= new QGraphicsScene;
    QGraphicsScene* scene22= new QGraphicsScene;

    //DECLARATION TIMER
    QTimer *timer = new QTimer();

protected:
  void closeEvent(QCloseEvent* event ) ;

public slots:

  void on_pbuConnect_clicked() ;
  void on_pbuReadAll_clicked() ;
  void on_tabWidget_currentChanged(int index ) ;
  void on_tabWidget_tabCloseRequested(int index ) ;
  void info(const QString& source, const QString& message ) ;
  void valueChanged(int table,const QString& name ) ;
  void PinceOuverte();
  void PinceFerme();
  void Monter();
  void Descendre();
  void VersPalette();
  void VersTable();
  void Moteur1();
  void Moteur2();
  void TransfertVersT2();
  void TransfertVersT1();
  void Piece1();
  void Piece2();
  void Piece3();
  void Piece4();
  void Piece5();
  void Piece6();
  void Piece7();
  void Piece8();
  void Piece9();
  void Piece10();
  void Piece11();
  void Piece12();
  void Piece13();
  void Piece14();
  void Piece15();
  void Piece16();
  void Piece17();
  void Piece18();
  void Piece19();
  void Piece20();
  void ButeA(int state);
  void ButeV(int state);
  void ButeS(int state);
  void ButeAtt(int state);
  void Reset();
  void Auto();
  void Pom();
  void Transfert1AutoMon();
  void Transfert2AutoMon();
  void Transfert1AutoDem();
  void Transfert2AutoDem();
  void tempsSysteme();
  void ArretFinCycle();
  void puzzleIhmMon();
  void puzzleIhmVision();
  void puzzleIhmDem();

private:
    Ui::manuel *ui;
    void readSettings() ;
    void writeSettings() ;
    void showPrompt(const QString& prompt ) ;
    void showMessage(const QString& msg, bool bold = true, QColor color = Qt::black ) ;
    QString		m_configDir ;
    QList<QamModbusMap *>		m_modbusMap ;
    QList<QamTcpClient *>		m_tcpCLient ;
    QList<QamModbusMapViewer *>	m_modbusMapViewer ;
    bool tcpClientOk[3];
};

#endif // MANUEL_H
