#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    m_scara = new QamScara ;



    setupUi(this);
}

void Widget::on_pushButton_clicked()
{
    m_scara->halt();
}

void Widget::on_pushButton_2_clicked()
{
     m_scara ->home(QamScara::ZAxis);
     m_scara ->home(QamScara::Shoulder);
     m_scara ->home(QamScara::Elbow);
     m_scara ->home(QamScara::Wrist);
     m_scara ->home(QamScara::Gripper);
     m_scara ->home(QamScara::Tcp);
    // if ( !m_scara->home() ) return ;
}

void Widget::on_pushButton_3_clicked()
{
    m_scara ->reset(QamScara::ZAxis);
    m_scara ->reset(QamScara::Shoulder);
    m_scara ->reset(QamScara::Elbow);
    m_scara ->reset(QamScara::Wrist);
    m_scara ->reset(QamScara::Gripper);
    m_scara ->reset(QamScara::Tcp);
    //if ( !m_scara->reset ) return ;

}

void Widget::on_pushButton_4_clicked()
{
    m_scara ->open() ;
    if ( !m_scara->open() ) return ;

}

void Widget::on_droite_clicked()
{
    m_scara->setAcceleration(QamScara::Wrist,0.5);
    m_scara->setVelocity(QamScara::Wrist,0.25);
    m_scara->acceleration(QamScara::Wrist);
}
