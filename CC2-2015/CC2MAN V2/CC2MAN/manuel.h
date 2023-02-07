#ifndef MANUEL_H
#define MANUEL_H

#define API 0
#define VISION 1
#define SCARA 2

#include "ui_manuel.h"
#include <QCloseEvent>
#include <QSettings>
#include "qammodbusmap.h"
#include "qamtcpclient.h"
#include "qammodbusmapviewer.h"
#include "qamabstractserver.h"
#include <QSemaphore>
#include "unistd.h"

#define ABOUTMESSAGE \
    "<p><h3>ModipManager - version %1</h3>" \
    "<p>Modbus over TCP/IP Supervisor Tool" \
    "<p><i>based on %2</i>" \
    "<p>Copyright (c)2014 by Alain Menu " \
    "<a href=\"mailto:alain.menu@ac-creteil.fr\">alain.menu@ac-creteil.fr</a>"

#define	VERSION "2.0"


namespace Ui {
class manuel;
}

class manuel : public QMainWindow, private Ui::manuel
{
    Q_OBJECT



public:
    explicit manuel(QWidget *parent = 0);
    ~manuel();



protected:
  void closeEvent(QCloseEvent* event ) ;

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


public slots:
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

private:
    Ui::manuel *ui;
    void readSettings() ;
    void writeSettings() ;
    void showPrompt(const QString& prompt ) ;
    void showMessage(const QString& msg, bool bold = false, QColor color = Qt::black ) ;

private:
  QString		m_configDir ;
  QList<QamModbusMap *>		m_modbusMap ;
  QList<QamTcpClient *>		m_tcpCLient ;
  QList<QamModbusMapViewer *>	m_modbusMapViewer ;




};

#endif // MANUEL_H
