/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *log;
    QVBoxLayout *verticalLayout;
    QGraphicsView *fenetre;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *blanc1;
    QSpinBox *blanc2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *connexion;
    QPushButton *config;
    QPushButton *save_config;
    QPushButton *photo;
    QPushButton *exit;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *bin1;
    QSpinBox *bin2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *fenetre_photo;

    void setupUi(QWidget *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QStringLiteral("camera"));
        camera->resize(1308, 651);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(camera->sizePolicy().hasHeightForWidth());
        camera->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(camera);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        log = new QTextEdit(camera);
        log->setObjectName(QStringLiteral("log"));
        sizePolicy.setHeightForWidth(log->sizePolicy().hasHeightForWidth());
        log->setSizePolicy(sizePolicy);
        log->setMinimumSize(QSize(0, 0));
        log->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_2->addWidget(log);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 4, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fenetre = new QGraphicsView(camera);
        fenetre->setObjectName(QStringLiteral("fenetre"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fenetre->sizePolicy().hasHeightForWidth());
        fenetre->setSizePolicy(sizePolicy1);
        fenetre->setMinimumSize(QSize(640, 490));

        verticalLayout->addWidget(fenetre);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(camera);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);


        gridLayout->addLayout(verticalLayout_3, 1, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        blanc1 = new QSpinBox(camera);
        blanc1->setObjectName(QStringLiteral("blanc1"));
        blanc1->setReadOnly(false);
        blanc1->setMaximum(255);
        blanc1->setValue(125);

        horizontalLayout_5->addWidget(blanc1);

        blanc2 = new QSpinBox(camera);
        blanc2->setObjectName(QStringLiteral("blanc2"));
        blanc2->setCursor(QCursor(Qt::ArrowCursor));
        blanc2->setWrapping(false);
        blanc2->setReadOnly(false);
        blanc2->setMaximum(255);
        blanc2->setValue(15);

        horizontalLayout_5->addWidget(blanc2);


        gridLayout->addLayout(horizontalLayout_5, 4, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        connexion = new QPushButton(camera);
        connexion->setObjectName(QStringLiteral("connexion"));

        horizontalLayout_3->addWidget(connexion);

        config = new QPushButton(camera);
        config->setObjectName(QStringLiteral("config"));

        horizontalLayout_3->addWidget(config);

        save_config = new QPushButton(camera);
        save_config->setObjectName(QStringLiteral("save_config"));

        horizontalLayout_3->addWidget(save_config);

        photo = new QPushButton(camera);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setEnabled(true);
        photo->setChecked(false);

        horizontalLayout_3->addWidget(photo);

        exit = new QPushButton(camera);
        exit->setObjectName(QStringLiteral("exit"));

        horizontalLayout_3->addWidget(exit);


        gridLayout->addLayout(horizontalLayout_3, 5, 1, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        bin1 = new QSpinBox(camera);
        bin1->setObjectName(QStringLiteral("bin1"));
        bin1->setMaximum(255);

        horizontalLayout_4->addWidget(bin1);

        bin2 = new QSpinBox(camera);
        bin2->setObjectName(QStringLiteral("bin2"));
        bin2->setMaximum(255);
        bin2->setValue(190);

        horizontalLayout_4->addWidget(bin2);


        gridLayout->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(camera);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_4, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fenetre_photo = new QGraphicsView(camera);
        fenetre_photo->setObjectName(QStringLiteral("fenetre_photo"));
        sizePolicy1.setHeightForWidth(fenetre_photo->sizePolicy().hasHeightForWidth());
        fenetre_photo->setSizePolicy(sizePolicy1);
        fenetre_photo->setMinimumSize(QSize(640, 490));

        horizontalLayout->addWidget(fenetre_photo);


        gridLayout->addLayout(horizontalLayout, 0, 0, 2, 1);


        retranslateUi(camera);
        QObject::connect(exit, SIGNAL(clicked()), camera, SLOT(close()));

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QWidget *camera)
    {
        camera->setWindowTitle(QApplication::translate("camera", "camera", 0));
        label->setText(QApplication::translate("camera", "Bin(int , int)", 0));
        connexion->setText(QApplication::translate("camera", "connexion", 0));
        config->setText(QApplication::translate("camera", "Config", 0));
        save_config->setText(QApplication::translate("camera", "Save config", 0));
        photo->setText(QApplication::translate("camera", "Photo", 0));
        exit->setText(QApplication::translate("camera", "Quitter", 0));
        label_2->setText(QApplication::translate("camera", "Blanc(int , int)", 0));
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
