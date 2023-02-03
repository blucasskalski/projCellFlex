/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include "qammodbusmapviewer.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbuLogo;
    QVBoxLayout *verticalLayout;
    QPushButton *pbuLoad;
    QHBoxLayout *horizontalLayout;
    QLabel *labPort;
    QLineEdit *edtPort;
    QPushButton *pbuStart;
    QTextEdit *edtDialog;
    QamModbusMapViewer *mapView;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(827, 385);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/qam47.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pbuLogo = new QPushButton(Dialog);
        pbuLogo->setObjectName(QStringLiteral("pbuLogo"));
        pbuLogo->setMinimumSize(QSize(60, 60));
        pbuLogo->setMaximumSize(QSize(60, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/qam47.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbuLogo->setIcon(icon1);
        pbuLogo->setIconSize(QSize(60, 60));
        pbuLogo->setFlat(true);

        gridLayout->addWidget(pbuLogo, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbuLoad = new QPushButton(Dialog);
        pbuLoad->setObjectName(QStringLiteral("pbuLoad"));

        verticalLayout->addWidget(pbuLoad);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labPort = new QLabel(Dialog);
        labPort->setObjectName(QStringLiteral("labPort"));
        labPort->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(labPort);

        edtPort = new QLineEdit(Dialog);
        edtPort->setObjectName(QStringLiteral("edtPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edtPort->sizePolicy().hasHeightForWidth());
        edtPort->setSizePolicy(sizePolicy);
        edtPort->setMinimumSize(QSize(60, 0));
        edtPort->setMaximumSize(QSize(60, 16777215));
        edtPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(edtPort);


        verticalLayout->addLayout(horizontalLayout);

        pbuStart = new QPushButton(Dialog);
        pbuStart->setObjectName(QStringLiteral("pbuStart"));

        verticalLayout->addWidget(pbuStart);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        edtDialog = new QTextEdit(Dialog);
        edtDialog->setObjectName(QStringLiteral("edtDialog"));
        edtDialog->setMinimumSize(QSize(100, 100));
        edtDialog->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(edtDialog, 0, 2, 1, 1);

        mapView = new QamModbusMapViewer(Dialog);
        mapView->setObjectName(QStringLiteral("mapView"));

        gridLayout->addWidget(mapView, 1, 0, 1, 3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "ModipButler", 0));
#ifndef QT_NO_TOOLTIP
        pbuLogo->setToolTip(QApplication::translate("Dialog", "About...", 0));
#endif // QT_NO_TOOLTIP
        pbuLogo->setText(QString());
        pbuLoad->setText(QApplication::translate("Dialog", "Load conf.", 0));
        labPort->setText(QApplication::translate("Dialog", "Port :", 0));
        edtPort->setText(QApplication::translate("Dialog", "502", 0));
        pbuStart->setText(QApplication::translate("Dialog", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
