#ifndef cc3_H
#define cc3_H

#define API 0
#define VISION 1
#define SCARA 2

#include "ui_cc3.h"
#include <QCloseEvent>
#include <QSettings>
#include <QSemaphore>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include "unistd.h"
#include "bouton.h"
#include "auto.h"

#define ABOUTMESSAGE \
    "<p><h3>ModipManager - version %1</h3>" \
    "<p>Modbus over TCP/IP Supervisor Tool" \
    "<p><i>based on %2</i>" \
    "<p>Copyright (c)2014 by Alain Menu " \
    "<a href=\"mailto:alain.menu@ac-creteil.fr\">alain.menu@ac-creteil.fr</a>"

#define	VERSION "2.0"


namespace Ui {
class CC3;
}

class CC3 : public QMainWindow, private Ui::CC3
{
    Q_OBJECT

public:
    explicit CC3(QWidget *parent = 0);
    ~CC3();
    bool modBusWrite(int, QString, QString);
    int moteur = 0 ;
    int moteur2 = 0 ;
    int transfert = 0 ;
    int transfert2 = 0 ;

protected:
  void closeEvent(QCloseEvent* event ) ;

public slots:
  void Reset();
  void Pince();
  void Verver();
  void Verhori();
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
  void ButeA(int state );
  void ButeV(int state);
  void ButeS(int state);
  void ButeAtt(int state);

public slots:
  void on_pbuNew_clicked() ;
  void on_pbuConnect_clicked() ;
  void on_pbuReset_clicked() ;
  void on_pbuReadAll_clicked() ;
  void on_pbuRead_clicked() ;
  void on_tabWidget_currentChanged(int index ) ;
  void on_tabWidget_tabCloseRequested(int index ) ;
  void info(const QString& source, const QString& message ) ;
  void valueChanged(int table,const QString& name ) ;
  //void on_pbuModeAuto_clicked() ;
  //void on_pbuModeManu_clicked() ;

private:
    Ui::CC3 *ui;
    void readSettings() ;
    void writeSettings() ;
    void showPrompt(const QString& prompt ) ;
    void showMessage(const QString& msg, bool bold = false, QColor color = Qt::black ) ;

private:
  QString		m_configDir ;
  QList<QamModbusMap *>		m_modbusMap ;
  QList<QamTcpClient *>		m_tcpCLient ;
  QList<QamModbusMapViewer *>	m_modbusMapViewer ;
  QamModbusMap::PrimaryTable m_table;
  QamModbusMap *m_map[3];
  QamModbusMap *map[3];
  QamTcpClient *tcpClient[3];
  bool tcpClientOk[3];

  //QamModbusMap *m_map;
  //QamModbusMap *map;

  QString csv1 = "./cellflex_api.csv" ;
  //QString csv2 = "./cellflex_vision.csv" ;
  //QString csv3 = "./cellflex_scara.csv" ;

/*
  QString csv1 = "/sdcard/cellflex_api.csv" ;
  //QString csv2 = "/sdcard/cellflex_vision.csv" ;
  //QString csv3 = "/sdcard/cellflex_scara.csv" ;
*/
};

#endif // cc3_H
