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
#include <QtWidgets/QHeaderView>
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
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(769, 433);
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

        edtDialog = new QTextEdit(Dialog);
        edtDialog->setObjectName(QStringLiteral("edtDialog"));
        edtDialog->setMinimumSize(QSize(0, 100));
        edtDialog->setMaximumSize(QSize(16777215, 100));
        edtDialog->setReadOnly(true);

        gridLayout->addWidget(edtDialog, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbuNew = new QPushButton(Dialog);
        pbuNew->setObjectName(QStringLiteral("pbuNew"));

        verticalLayout->addWidget(pbuNew);

        pbuConnect = new QPushButton(Dialog);
        pbuConnect->setObjectName(QStringLiteral("pbuConnect"));

        verticalLayout->addWidget(pbuConnect);

        verticalSpacer = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbuReset = new QPushButton(Dialog);
        pbuReset->setObjectName(QStringLiteral("pbuReset"));

        verticalLayout->addWidget(pbuReset);

        pbuReadAll = new QPushButton(Dialog);
        pbuReadAll->setObjectName(QStringLiteral("pbuReadAll"));

        verticalLayout->addWidget(pbuReadAll);

        pbuRead = new QPushButton(Dialog);
        pbuRead->setObjectName(QStringLiteral("pbuRead"));

        verticalLayout->addWidget(pbuRead);

        verticalSpacer_2 = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pbuQuit = new QPushButton(Dialog);
        pbuQuit->setObjectName(QStringLiteral("pbuQuit"));

        verticalLayout->addWidget(pbuQuit);


        gridLayout->addLayout(verticalLayout, 0, 2, 2, 1);

        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabsClosable(true);

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(Dialog);
        QObject::connect(pbuQuit, SIGNAL(clicked()), Dialog, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "ModipManager", 0));
#ifndef QT_NO_TOOLTIP
        pbuLogo->setToolTip(QApplication::translate("Dialog", "About...", 0));
#endif // QT_NO_TOOLTIP
        pbuLogo->setText(QString());
        pbuNew->setText(QApplication::translate("Dialog", "New...", 0));
        pbuConnect->setText(QApplication::translate("Dialog", "Connect", 0));
        pbuReset->setText(QApplication::translate("Dialog", "Reset all", 0));
        pbuReadAll->setText(QApplication::translate("Dialog", "Update all", 0));
        pbuRead->setText(QApplication::translate("Dialog", "Update\n"
"selection", 0));
        pbuQuit->setText(QApplication::translate("Dialog", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
