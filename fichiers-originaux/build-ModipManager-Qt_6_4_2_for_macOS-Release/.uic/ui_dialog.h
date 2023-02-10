/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbuLogo;
    QTextEdit *edtDialog;
    QVBoxLayout *verticalLayout;
    QPushButton *pbuNew;
    QPushButton *pbuConnect;
    QSpacerItem *verticalSpacer;
    QPushButton *pbuReset;
    QPushButton *pbuReadAll;
    QPushButton *pbuRead;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pbuQuit;
    QTabWidget *tabWidget;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(769, 433);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/qam47.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        pbuLogo = new QPushButton(Dialog);
        pbuLogo->setObjectName("pbuLogo");
        pbuLogo->setMinimumSize(QSize(60, 60));
        pbuLogo->setMaximumSize(QSize(60, 60));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/qam47.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbuLogo->setIcon(icon1);
        pbuLogo->setIconSize(QSize(60, 60));
        pbuLogo->setFlat(true);

        gridLayout->addWidget(pbuLogo, 0, 0, 1, 1);

        edtDialog = new QTextEdit(Dialog);
        edtDialog->setObjectName("edtDialog");
        edtDialog->setMinimumSize(QSize(0, 100));
        edtDialog->setMaximumSize(QSize(16777215, 100));
        edtDialog->setReadOnly(true);

        gridLayout->addWidget(edtDialog, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        pbuNew = new QPushButton(Dialog);
        pbuNew->setObjectName("pbuNew");

        verticalLayout->addWidget(pbuNew);

        pbuConnect = new QPushButton(Dialog);
        pbuConnect->setObjectName("pbuConnect");

        verticalLayout->addWidget(pbuConnect);

        verticalSpacer = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbuReset = new QPushButton(Dialog);
        pbuReset->setObjectName("pbuReset");

        verticalLayout->addWidget(pbuReset);

        pbuReadAll = new QPushButton(Dialog);
        pbuReadAll->setObjectName("pbuReadAll");

        verticalLayout->addWidget(pbuReadAll);

        pbuRead = new QPushButton(Dialog);
        pbuRead->setObjectName("pbuRead");

        verticalLayout->addWidget(pbuRead);

        verticalSpacer_2 = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pbuQuit = new QPushButton(Dialog);
        pbuQuit->setObjectName("pbuQuit");

        verticalLayout->addWidget(pbuQuit);


        gridLayout->addLayout(verticalLayout, 0, 2, 2, 1);

        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabsClosable(true);

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(Dialog);
        QObject::connect(pbuQuit, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::close));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "ModipManager", nullptr));
#if QT_CONFIG(tooltip)
        pbuLogo->setToolTip(QCoreApplication::translate("Dialog", "About...", nullptr));
#endif // QT_CONFIG(tooltip)
        pbuLogo->setText(QString());
        pbuNew->setText(QCoreApplication::translate("Dialog", "New...", nullptr));
        pbuConnect->setText(QCoreApplication::translate("Dialog", "Connect", nullptr));
        pbuReset->setText(QCoreApplication::translate("Dialog", "Reset all", nullptr));
        pbuReadAll->setText(QCoreApplication::translate("Dialog", "Update all", nullptr));
        pbuRead->setText(QCoreApplication::translate("Dialog", "Update\n"
"selection", nullptr));
        pbuQuit->setText(QCoreApplication::translate("Dialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
