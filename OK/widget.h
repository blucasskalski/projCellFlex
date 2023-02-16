#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include "iostream"
#include "QCloseEvent"
#include "qamscara.h"

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_droite_clicked();

private:
   QamScara*      m_scara;

};

#endif // WIDGET_H
