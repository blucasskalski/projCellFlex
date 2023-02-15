/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qamimghistogram.h"

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *automatique;
    QRadioButton *manuel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *fenetre_photo;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QGraphicsView *fenetre;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *blanc1;
    QSpinBox *blanc2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *bin1;
    QSpinBox *bin2;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *config;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *connexion;
    QPushButton *photo;
    QPushButton *exit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *save_config;
    QTextEdit *log;
    QamImgHistogram *histo;
    QGraphicsView *photo_bin;
    QGraphicsView *photo_size;

    void setupUi(QWidget *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QString::fromUtf8("camera"));
        camera->resize(1280, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(camera->sizePolicy().hasHeightForWidth());
        camera->setSizePolicy(sizePolicy);
        camera->setMinimumSize(QSize(1280, 1000));
        verticalLayoutWidget = new QWidget(camera);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1110, 520, 157, 54));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        automatique = new QRadioButton(verticalLayoutWidget);
        automatique->setObjectName(QString::fromUtf8("automatique"));

        verticalLayout->addWidget(automatique);

        manuel = new QRadioButton(verticalLayoutWidget);
        manuel->setObjectName(QString::fromUtf8("manuel"));
        manuel->setChecked(true);

        verticalLayout->addWidget(manuel);

        layoutWidget = new QWidget(camera);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 622, 492));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        fenetre_photo = new QGraphicsView(layoutWidget);
        fenetre_photo->setObjectName(QString::fromUtf8("fenetre_photo"));
        sizePolicy.setHeightForWidth(fenetre_photo->sizePolicy().hasHeightForWidth());
        fenetre_photo->setSizePolicy(sizePolicy);
        fenetre_photo->setMinimumSize(QSize(620, 490));
        fenetre_photo->setMaximumSize(QSize(640, 490));

        horizontalLayout->addWidget(fenetre_photo);

        layoutWidget1 = new QWidget(camera);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(637, 9, 634, 492));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        fenetre = new QGraphicsView(layoutWidget1);
        fenetre->setObjectName(QString::fromUtf8("fenetre"));
        sizePolicy.setHeightForWidth(fenetre->sizePolicy().hasHeightForWidth());
        fenetre->setSizePolicy(sizePolicy);
        fenetre->setMinimumSize(QSize(620, 490));
        fenetre->setMaximumSize(QSize(640, 490));

        horizontalLayout_6->addWidget(fenetre);

        layoutWidget2 = new QWidget(camera);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(650, 520, 122, 55));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        blanc1 = new QSpinBox(layoutWidget2);
        blanc1->setObjectName(QString::fromUtf8("blanc1"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(blanc1->sizePolicy().hasHeightForWidth());
        blanc1->setSizePolicy(sizePolicy1);
        blanc1->setReadOnly(false);
        blanc1->setMaximum(255);
        blanc1->setValue(125);

        horizontalLayout_5->addWidget(blanc1);

        blanc2 = new QSpinBox(layoutWidget2);
        blanc2->setObjectName(QString::fromUtf8("blanc2"));
        sizePolicy1.setHeightForWidth(blanc2->sizePolicy().hasHeightForWidth());
        blanc2->setSizePolicy(sizePolicy1);
        blanc2->setCursor(QCursor(Qt::ArrowCursor));
        blanc2->setWrapping(false);
        blanc2->setReadOnly(false);
        blanc2->setMaximum(255);
        blanc2->setValue(15);

        horizontalLayout_5->addWidget(blanc2);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout_4);

        layoutWidget3 = new QWidget(camera);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(800, 520, 122, 51));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(30, 10));

        verticalLayout_3->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bin1 = new QSpinBox(layoutWidget3);
        bin1->setObjectName(QString::fromUtf8("bin1"));
        sizePolicy1.setHeightForWidth(bin1->sizePolicy().hasHeightForWidth());
        bin1->setSizePolicy(sizePolicy1);
        bin1->setMinimumSize(QSize(0, 0));
        bin1->setMaximum(255);

        horizontalLayout_4->addWidget(bin1);

        bin2 = new QSpinBox(layoutWidget3);
        bin2->setObjectName(QString::fromUtf8("bin2"));
        sizePolicy1.setHeightForWidth(bin2->sizePolicy().hasHeightForWidth());
        bin2->setSizePolicy(sizePolicy1);
        bin2->setMaximum(255);
        bin2->setValue(190);

        horizontalLayout_4->addWidget(bin2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_9->addLayout(verticalLayout_3);

        layoutWidget4 = new QWidget(camera);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(940, 520, 161, 27));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        config = new QPushButton(layoutWidget4);
        config->setObjectName(QString::fromUtf8("config"));
        sizePolicy1.setHeightForWidth(config->sizePolicy().hasHeightForWidth());
        config->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(config);

        layoutWidget5 = new QWidget(camera);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(640, 970, 621, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        connexion = new QPushButton(layoutWidget5);
        connexion->setObjectName(QString::fromUtf8("connexion"));

        horizontalLayout_3->addWidget(connexion);

        photo = new QPushButton(layoutWidget5);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setEnabled(true);
        sizePolicy1.setHeightForWidth(photo->sizePolicy().hasHeightForWidth());
        photo->setSizePolicy(sizePolicy1);
        photo->setChecked(false);

        horizontalLayout_3->addWidget(photo);

        exit = new QPushButton(layoutWidget5);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setCheckable(true);

        horizontalLayout_3->addWidget(exit);

        horizontalLayoutWidget = new QWidget(camera);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(940, 550, 160, 27));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        save_config = new QPushButton(horizontalLayoutWidget);
        save_config->setObjectName(QString::fromUtf8("save_config"));
        sizePolicy1.setHeightForWidth(save_config->sizePolicy().hasHeightForWidth());
        save_config->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(save_config);

        log = new QTextEdit(camera);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(640, 590, 630, 371));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(log->sizePolicy().hasHeightForWidth());
        log->setSizePolicy(sizePolicy2);
        log->setMinimumSize(QSize(630, 300));
        log->setMaximumSize(QSize(620, 500));
        log->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        log->setReadOnly(true);
        histo = new QamImgHistogram(camera);
        histo->setObjectName(QString::fromUtf8("histo"));
        histo->setGeometry(QRect(20, 860, 599, 141));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(histo->sizePolicy().hasHeightForWidth());
        histo->setSizePolicy(sizePolicy3);
        histo->setMinimumSize(QSize(550, 100));
        histo->setBaseSize(QSize(0, 0));
        photo_bin = new QGraphicsView(camera);
        photo_bin->setObjectName(QString::fromUtf8("photo_bin"));
        photo_bin->setGeometry(QRect(330, 530, 300, 300));
        sizePolicy3.setHeightForWidth(photo_bin->sizePolicy().hasHeightForWidth());
        photo_bin->setSizePolicy(sizePolicy3);
        photo_bin->setMinimumSize(QSize(300, 300));
        photo_bin->setMaximumSize(QSize(300, 300));
        photo_size = new QGraphicsView(camera);
        photo_size->setObjectName(QString::fromUtf8("photo_size"));
        photo_size->setGeometry(QRect(10, 530, 300, 300));
        sizePolicy3.setHeightForWidth(photo_size->sizePolicy().hasHeightForWidth());
        photo_size->setSizePolicy(sizePolicy3);
        photo_size->setMinimumSize(QSize(300, 300));
        photo_size->setMaximumSize(QSize(300, 300));

        retranslateUi(camera);
        QObject::connect(exit, &QPushButton::clicked, camera, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QWidget *camera)
    {
        camera->setWindowTitle(QCoreApplication::translate("camera", "camera", nullptr));
        automatique->setText(QCoreApplication::translate("camera", "Mode automatique", nullptr));
        manuel->setText(QCoreApplication::translate("camera", "Mode manuel", nullptr));
        label_2->setText(QCoreApplication::translate("camera", "blanc( int, int ) : ", nullptr));
        label->setText(QCoreApplication::translate("camera", "bin( int , int ) :", nullptr));
        config->setText(QCoreApplication::translate("camera", "Config", nullptr));
        connexion->setText(QCoreApplication::translate("camera", "connexion", nullptr));
        photo->setText(QCoreApplication::translate("camera", "Photo", nullptr));
        exit->setText(QCoreApplication::translate("camera", "Quitter", nullptr));
        save_config->setText(QCoreApplication::translate("camera", "Save config", nullptr));
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
