/********************************************************************************
** Form generated from reading UI file 'manuel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUEL_H
#define UI_MANUEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manuel
{
public:
    QWidget *centralWidget;
    QLabel *label_4;
    QPushButton *pbuPinceFerme;
    QPushButton *pbuQuitter;
    QPushButton *pbuVersPalette;
    QCheckBox *buteV;
    QPushButton *pbuVersT1;
    QCheckBox *buteA;
    QPushButton *pbuMoteur1;
    QPushButton *pbuPinceOuverte;
    QCheckBox *buteS;
    QLabel *label_3;
    QPushButton *pbuMonter;
    QPushButton *pbuVersTable;
    QPushButton *pbuVersT2;
    QPushButton *pbuDescendre;
    QPushButton *pbuMoteur2;
    QPushButton *pbuAuto;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *piece;
    QPushButton *piece_2;
    QPushButton *piece_3;
    QPushButton *piece_4;
    QPushButton *piece_5;
    QPushButton *piece_6;
    QPushButton *piece_7;
    QPushButton *piece_8;
    QPushButton *piece_9;
    QPushButton *piece_10;
    QPushButton *piece_11;
    QPushButton *piece_12;
    QPushButton *piece_13;
    QPushButton *piece_14;
    QPushButton *piece_15;
    QPushButton *piece_16;
    QPushButton *piece_17;
    QPushButton *piece_18;
    QPushButton *piece_19;
    QPushButton *piece_20;
    QTextBrowser *textBrowser;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutPuzzle;
    QGraphicsView *piece19;
    QGraphicsView *piece17;
    QGraphicsView *piece9;
    QGraphicsView *piece18;
    QGraphicsView *piece7;
    QGraphicsView *piece0;
    QGraphicsView *piece3;
    QGraphicsView *piece8;
    QGraphicsView *piece6;
    QGraphicsView *piece5;
    QGraphicsView *piece16;
    QGraphicsView *piece10;
    QGraphicsView *piece14;
    QGraphicsView *piece12;
    QGraphicsView *piece13;
    QGraphicsView *piece15;
    QGraphicsView *piece4;
    QGraphicsView *piece11;
    QGraphicsView *piece1;
    QGraphicsView *piece2;
    QTextEdit *edtDialog;
    QPushButton *pbuConnect;
    QPushButton *pbuReset;
    QPushButton *pbuReadAll;
    QCheckBox *buteAtt;
    QTabWidget *tabWidget;
    QPushButton *pbuPom;
    QGraphicsView *piecevision;
    QLabel *label;
    QProgressBar *Barre;
    QTimeEdit *temps;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *manuel)
    {
        if (manuel->objectName().isEmpty())
            manuel->setObjectName(QStringLiteral("manuel"));
        manuel->setEnabled(true);
        manuel->resize(1220, 1200);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(manuel->sizePolicy().hasHeightForWidth());
        manuel->setSizePolicy(sizePolicy);
        manuel->setMinimumSize(QSize(1220, 1200));
        manuel->setMaximumSize(QSize(1220, 1200));
        centralWidget = new QWidget(manuel);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 460, 47, 31));
        label_4->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        pbuPinceFerme = new QPushButton(centralWidget);
        pbuPinceFerme->setObjectName(QStringLiteral("pbuPinceFerme"));
        pbuPinceFerme->setEnabled(false);
        pbuPinceFerme->setGeometry(QRect(1090, 210, 101, 31));
        pbuQuitter = new QPushButton(centralWidget);
        pbuQuitter->setObjectName(QStringLiteral("pbuQuitter"));
        pbuQuitter->setGeometry(QRect(1110, 910, 75, 31));
        pbuQuitter->setStyleSheet(QStringLiteral("color: rgb(190, 0, 0);"));
        pbuVersPalette = new QPushButton(centralWidget);
        pbuVersPalette->setObjectName(QStringLiteral("pbuVersPalette"));
        pbuVersPalette->setEnabled(false);
        pbuVersPalette->setGeometry(QRect(1090, 60, 101, 31));
        buteV = new QCheckBox(centralWidget);
        buteV->setObjectName(QStringLiteral("buteV"));
        buteV->setEnabled(false);
        buteV->setGeometry(QRect(450, 310, 101, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buteV->sizePolicy().hasHeightForWidth());
        buteV->setSizePolicy(sizePolicy1);
        buteV->setMinimumSize(QSize(0, 0));
        buteV->setStyleSheet(QLatin1String("color: rgb(254, 254, 254);\n"
"border-color: rgb(255, 255, 255);"));
        buteV->setChecked(true);
        pbuVersT1 = new QPushButton(centralWidget);
        pbuVersT1->setObjectName(QStringLiteral("pbuVersT1"));
        pbuVersT1->setEnabled(false);
        pbuVersT1->setGeometry(QRect(940, 380, 121, 31));
        buteA = new QCheckBox(centralWidget);
        buteA->setObjectName(QStringLiteral("buteA"));
        buteA->setEnabled(false);
        buteA->setGeometry(QRect(860, 310, 171, 21));
        buteA->setStyleSheet(QLatin1String("border-color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);"));
        buteA->setChecked(true);
        pbuMoteur1 = new QPushButton(centralWidget);
        pbuMoteur1->setObjectName(QStringLiteral("pbuMoteur1"));
        pbuMoteur1->setEnabled(false);
        pbuMoteur1->setGeometry(QRect(660, 360, 75, 31));
        pbuPinceOuverte = new QPushButton(centralWidget);
        pbuPinceOuverte->setObjectName(QStringLiteral("pbuPinceOuverte"));
        pbuPinceOuverte->setEnabled(false);
        pbuPinceOuverte->setGeometry(QRect(1090, 180, 101, 31));
        buteS = new QCheckBox(centralWidget);
        buteS->setObjectName(QStringLiteral("buteS"));
        buteS->setEnabled(false);
        buteS->setGeometry(QRect(450, 470, 101, 21));
        buteS->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
""));
        buteS->setChecked(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 300, 51, 31));
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        pbuMonter = new QPushButton(centralWidget);
        pbuMonter->setObjectName(QStringLiteral("pbuMonter"));
        pbuMonter->setEnabled(false);
        pbuMonter->setGeometry(QRect(1090, 100, 101, 31));
        pbuVersTable = new QPushButton(centralWidget);
        pbuVersTable->setObjectName(QStringLiteral("pbuVersTable"));
        pbuVersTable->setEnabled(false);
        pbuVersTable->setGeometry(QRect(1090, 30, 101, 31));
        pbuVersT2 = new QPushButton(centralWidget);
        pbuVersT2->setObjectName(QStringLiteral("pbuVersT2"));
        pbuVersT2->setEnabled(false);
        pbuVersT2->setGeometry(QRect(340, 380, 121, 31));
        pbuDescendre = new QPushButton(centralWidget);
        pbuDescendre->setObjectName(QStringLiteral("pbuDescendre"));
        pbuDescendre->setEnabled(false);
        pbuDescendre->setGeometry(QRect(1090, 140, 101, 31));
        pbuMoteur2 = new QPushButton(centralWidget);
        pbuMoteur2->setObjectName(QStringLiteral("pbuMoteur2"));
        pbuMoteur2->setEnabled(false);
        pbuMoteur2->setGeometry(QRect(660, 400, 75, 31));
        pbuAuto = new QPushButton(centralWidget);
        pbuAuto->setObjectName(QStringLiteral("pbuAuto"));
        pbuAuto->setEnabled(false);
        pbuAuto->setGeometry(QRect(820, 910, 75, 31));
        pbuAuto->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setEnabled(true);
        layoutWidget->setGeometry(QRect(800, 40, 181, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        piece = new QPushButton(layoutWidget);
        piece->setObjectName(QStringLiteral("piece"));
        piece->setEnabled(false);
        piece->setMaximumSize(QSize(30, 30));
        piece->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";\n"
""));

        gridLayout->addWidget(piece, 0, 0, 1, 1);

        piece_2 = new QPushButton(layoutWidget);
        piece_2->setObjectName(QStringLiteral("piece_2"));
        piece_2->setEnabled(false);
        piece_2->setMaximumSize(QSize(30, 30));
        piece_2->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_2, 0, 1, 1, 1);

        piece_3 = new QPushButton(layoutWidget);
        piece_3->setObjectName(QStringLiteral("piece_3"));
        piece_3->setEnabled(false);
        piece_3->setMaximumSize(QSize(30, 30));
        piece_3->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";\n"
""));

        gridLayout->addWidget(piece_3, 0, 2, 1, 1);

        piece_4 = new QPushButton(layoutWidget);
        piece_4->setObjectName(QStringLiteral("piece_4"));
        piece_4->setEnabled(false);
        piece_4->setMaximumSize(QSize(30, 30));
        piece_4->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_4, 0, 3, 1, 1);

        piece_5 = new QPushButton(layoutWidget);
        piece_5->setObjectName(QStringLiteral("piece_5"));
        piece_5->setEnabled(false);
        piece_5->setMaximumSize(QSize(30, 30));
        piece_5->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_5, 0, 4, 1, 1);

        piece_6 = new QPushButton(layoutWidget);
        piece_6->setObjectName(QStringLiteral("piece_6"));
        piece_6->setEnabled(false);
        piece_6->setMaximumSize(QSize(30, 30));
        piece_6->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_6, 1, 0, 1, 1);

        piece_7 = new QPushButton(layoutWidget);
        piece_7->setObjectName(QStringLiteral("piece_7"));
        piece_7->setEnabled(false);
        piece_7->setMaximumSize(QSize(30, 30));
        piece_7->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_7, 1, 1, 1, 1);

        piece_8 = new QPushButton(layoutWidget);
        piece_8->setObjectName(QStringLiteral("piece_8"));
        piece_8->setEnabled(false);
        piece_8->setMaximumSize(QSize(30, 30));
        piece_8->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_8, 1, 2, 1, 1);

        piece_9 = new QPushButton(layoutWidget);
        piece_9->setObjectName(QStringLiteral("piece_9"));
        piece_9->setEnabled(false);
        piece_9->setMaximumSize(QSize(30, 30));
        piece_9->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_9, 1, 3, 1, 1);

        piece_10 = new QPushButton(layoutWidget);
        piece_10->setObjectName(QStringLiteral("piece_10"));
        piece_10->setEnabled(false);
        piece_10->setMaximumSize(QSize(30, 30));
        piece_10->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_10, 1, 4, 1, 1);

        piece_11 = new QPushButton(layoutWidget);
        piece_11->setObjectName(QStringLiteral("piece_11"));
        piece_11->setEnabled(false);
        piece_11->setMaximumSize(QSize(30, 30));
        piece_11->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_11, 2, 0, 1, 1);

        piece_12 = new QPushButton(layoutWidget);
        piece_12->setObjectName(QStringLiteral("piece_12"));
        piece_12->setEnabled(false);
        piece_12->setMaximumSize(QSize(30, 30));
        piece_12->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_12, 2, 1, 1, 1);

        piece_13 = new QPushButton(layoutWidget);
        piece_13->setObjectName(QStringLiteral("piece_13"));
        piece_13->setEnabled(false);
        piece_13->setMaximumSize(QSize(30, 30));
        piece_13->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_13, 2, 2, 1, 1);

        piece_14 = new QPushButton(layoutWidget);
        piece_14->setObjectName(QStringLiteral("piece_14"));
        piece_14->setEnabled(false);
        piece_14->setMaximumSize(QSize(30, 30));
        piece_14->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_14, 2, 3, 1, 1);

        piece_15 = new QPushButton(layoutWidget);
        piece_15->setObjectName(QStringLiteral("piece_15"));
        piece_15->setEnabled(false);
        piece_15->setMaximumSize(QSize(30, 30));
        piece_15->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_15, 2, 4, 1, 1);

        piece_16 = new QPushButton(layoutWidget);
        piece_16->setObjectName(QStringLiteral("piece_16"));
        piece_16->setEnabled(false);
        piece_16->setMaximumSize(QSize(30, 30));
        piece_16->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_16, 3, 0, 1, 1);

        piece_17 = new QPushButton(layoutWidget);
        piece_17->setObjectName(QStringLiteral("piece_17"));
        piece_17->setEnabled(false);
        piece_17->setMaximumSize(QSize(30, 30));
        piece_17->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_17, 3, 1, 1, 1);

        piece_18 = new QPushButton(layoutWidget);
        piece_18->setObjectName(QStringLiteral("piece_18"));
        piece_18->setEnabled(false);
        piece_18->setMaximumSize(QSize(30, 30));
        piece_18->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_18, 3, 2, 1, 1);

        piece_19 = new QPushButton(layoutWidget);
        piece_19->setObjectName(QStringLiteral("piece_19"));
        piece_19->setEnabled(false);
        piece_19->setMaximumSize(QSize(30, 30));
        piece_19->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_19, 3, 3, 1, 1);

        piece_20 = new QPushButton(layoutWidget);
        piece_20->setObjectName(QStringLiteral("piece_20"));
        piece_20->setEnabled(false);
        piece_20->setMaximumSize(QSize(30, 30));
        piece_20->setStyleSheet(QLatin1String("color: rgb(34, 181, 55);\n"
"font: 11pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(piece_20, 3, 4, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(250, 10, 951, 521));
        textBrowser->setMinimumSize(QSize(0, 45));
        textBrowser->setStyleSheet(QStringLiteral("color: rgb(39, 186, 90);"));
        textBrowser->setInputMethodHints(Qt::ImhNone);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 340, 221, 191));
        gridLayoutPuzzle = new QGridLayout(gridLayoutWidget);
        gridLayoutPuzzle->setSpacing(0);
        gridLayoutPuzzle->setContentsMargins(11, 11, 11, 11);
        gridLayoutPuzzle->setObjectName(QStringLiteral("gridLayoutPuzzle"));
        gridLayoutPuzzle->setContentsMargins(0, 0, 0, 0);
        piece19 = new QGraphicsView(gridLayoutWidget);
        piece19->setObjectName(QStringLiteral("piece19"));
        piece19->setMinimumSize(QSize(40, 45));
        piece19->setMaximumSize(QSize(39, 39));
        piece19->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece19->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece19, 4, 4, 1, 1);

        piece17 = new QGraphicsView(gridLayoutWidget);
        piece17->setObjectName(QStringLiteral("piece17"));
        piece17->setMinimumSize(QSize(40, 45));
        piece17->setMaximumSize(QSize(39, 39));
        piece17->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece17->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece17, 4, 2, 1, 1);

        piece9 = new QGraphicsView(gridLayoutWidget);
        piece9->setObjectName(QStringLiteral("piece9"));
        piece9->setMinimumSize(QSize(40, 45));
        piece9->setMaximumSize(QSize(39, 39));
        piece9->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece9->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece9, 2, 4, 1, 1);

        piece18 = new QGraphicsView(gridLayoutWidget);
        piece18->setObjectName(QStringLiteral("piece18"));
        piece18->setMinimumSize(QSize(40, 45));
        piece18->setMaximumSize(QSize(39, 39));
        piece18->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece18->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece18, 4, 3, 1, 1);

        piece7 = new QGraphicsView(gridLayoutWidget);
        piece7->setObjectName(QStringLiteral("piece7"));
        piece7->setMinimumSize(QSize(40, 45));
        piece7->setMaximumSize(QSize(39, 39));
        piece7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece7, 2, 2, 1, 1);

        piece0 = new QGraphicsView(gridLayoutWidget);
        piece0->setObjectName(QStringLiteral("piece0"));
        piece0->setMinimumSize(QSize(40, 45));
        piece0->setMaximumSize(QSize(39, 39));
        piece0->setStyleSheet(QStringLiteral(""));
        piece0->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece0, 0, 0, 1, 1);

        piece3 = new QGraphicsView(gridLayoutWidget);
        piece3->setObjectName(QStringLiteral("piece3"));
        piece3->setMinimumSize(QSize(40, 45));
        piece3->setMaximumSize(QSize(39, 39));
        piece3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece3, 0, 3, 1, 1);

        piece8 = new QGraphicsView(gridLayoutWidget);
        piece8->setObjectName(QStringLiteral("piece8"));
        piece8->setMinimumSize(QSize(40, 45));
        piece8->setMaximumSize(QSize(39, 39));
        piece8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece8, 2, 3, 1, 1);

        piece6 = new QGraphicsView(gridLayoutWidget);
        piece6->setObjectName(QStringLiteral("piece6"));
        piece6->setMinimumSize(QSize(40, 45));
        piece6->setMaximumSize(QSize(39, 39));
        piece6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece6, 2, 1, 1, 1);

        piece5 = new QGraphicsView(gridLayoutWidget);
        piece5->setObjectName(QStringLiteral("piece5"));
        piece5->setMinimumSize(QSize(40, 45));
        piece5->setMaximumSize(QSize(39, 39));
        piece5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece5, 2, 0, 1, 1);

        piece16 = new QGraphicsView(gridLayoutWidget);
        piece16->setObjectName(QStringLiteral("piece16"));
        piece16->setMinimumSize(QSize(40, 45));
        piece16->setMaximumSize(QSize(39, 39));
        piece16->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece16->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece16, 4, 1, 1, 1);

        piece10 = new QGraphicsView(gridLayoutWidget);
        piece10->setObjectName(QStringLiteral("piece10"));
        piece10->setMinimumSize(QSize(40, 45));
        piece10->setMaximumSize(QSize(39, 39));
        piece10->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece10->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece10, 3, 0, 1, 1);

        piece14 = new QGraphicsView(gridLayoutWidget);
        piece14->setObjectName(QStringLiteral("piece14"));
        piece14->setMinimumSize(QSize(40, 45));
        piece14->setMaximumSize(QSize(39, 39));
        piece14->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece14->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece14, 3, 4, 1, 1);

        piece12 = new QGraphicsView(gridLayoutWidget);
        piece12->setObjectName(QStringLiteral("piece12"));
        piece12->setMinimumSize(QSize(40, 45));
        piece12->setMaximumSize(QSize(39, 39));
        piece12->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece12->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece12, 3, 2, 1, 1);

        piece13 = new QGraphicsView(gridLayoutWidget);
        piece13->setObjectName(QStringLiteral("piece13"));
        piece13->setMinimumSize(QSize(40, 45));
        piece13->setMaximumSize(QSize(39, 39));
        piece13->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece13->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece13, 3, 3, 1, 1);

        piece15 = new QGraphicsView(gridLayoutWidget);
        piece15->setObjectName(QStringLiteral("piece15"));
        piece15->setMinimumSize(QSize(40, 45));
        piece15->setMaximumSize(QSize(39, 39));
        piece15->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece15->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece15, 4, 0, 1, 1);

        piece4 = new QGraphicsView(gridLayoutWidget);
        piece4->setObjectName(QStringLiteral("piece4"));
        piece4->setMinimumSize(QSize(40, 45));
        piece4->setMaximumSize(QSize(39, 39));
        piece4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece4, 0, 4, 1, 1);

        piece11 = new QGraphicsView(gridLayoutWidget);
        piece11->setObjectName(QStringLiteral("piece11"));
        piece11->setMinimumSize(QSize(40, 45));
        piece11->setMaximumSize(QSize(39, 39));
        piece11->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece11->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece11, 3, 1, 1, 1);

        piece1 = new QGraphicsView(gridLayoutWidget);
        piece1->setObjectName(QStringLiteral("piece1"));
        piece1->setMinimumSize(QSize(40, 45));
        piece1->setMaximumSize(QSize(39, 39));
        piece1->setStyleSheet(QStringLiteral(""));
        piece1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece1, 0, 1, 1, 1);

        piece2 = new QGraphicsView(gridLayoutWidget);
        piece2->setObjectName(QStringLiteral("piece2"));
        piece2->setMinimumSize(QSize(40, 45));
        piece2->setMaximumSize(QSize(39, 39));
        piece2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piece2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayoutPuzzle->addWidget(piece2, 0, 2, 1, 1);

        edtDialog = new QTextEdit(centralWidget);
        edtDialog->setObjectName(QStringLiteral("edtDialog"));
        edtDialog->setGeometry(QRect(20, 10, 221, 321));
        pbuConnect = new QPushButton(centralWidget);
        pbuConnect->setObjectName(QStringLiteral("pbuConnect"));
        pbuConnect->setEnabled(false);
        pbuConnect->setGeometry(QRect(40, 910, 91, 31));
        pbuReset = new QPushButton(centralWidget);
        pbuReset->setObjectName(QStringLiteral("pbuReset"));
        pbuReset->setEnabled(false);
        pbuReset->setGeometry(QRect(900, 910, 111, 31));
        pbuReset->setStyleSheet(QStringLiteral("color: rgb(190, 0, 0);"));
        pbuReadAll = new QPushButton(centralWidget);
        pbuReadAll->setObjectName(QStringLiteral("pbuReadAll"));
        pbuReadAll->setEnabled(false);
        pbuReadAll->setGeometry(QRect(440, 20, 151, 51));
        buteAtt = new QCheckBox(centralWidget);
        buteAtt->setObjectName(QStringLiteral("buteAtt"));
        buteAtt->setEnabled(false);
        buteAtt->setGeometry(QRect(860, 470, 121, 22));
        buteAtt->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        buteAtt->setChecked(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(20, 540, 1181, 361));
        tabWidget->setStyleSheet(QLatin1String("border-color: rgb(255, 255, 255);\n"
"selection-color: rgb(255, 255, 255);\n"
"border-left-color: rgb(255, 255, 255);"));
        pbuPom = new QPushButton(centralWidget);
        pbuPom->setObjectName(QStringLiteral("pbuPom"));
        pbuPom->setEnabled(false);
        pbuPom->setGeometry(QRect(600, 20, 151, 51));
        piecevision = new QGraphicsView(centralWidget);
        piecevision->setObjectName(QStringLiteral("piecevision"));
        piecevision->setGeometry(QRect(420, 150, 140, 120));
        piecevision->setMinimumSize(QSize(140, 120));
        piecevision->setMaximumSize(QSize(140, 120));
        piecevision->setStyleSheet(QLatin1String("border-width:1px;\n"
"border-color: rgb(190, 190, 190);\n"
"border-style:solid;\n"
"border-radius:3px;\n"
""));
        piecevision->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        piecevision->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 120, 141, 20));
        label->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"text-decoration: underline;\n"
"color: rgb(130, 130, 130);"));
        Barre = new QProgressBar(centralWidget);
        Barre->setObjectName(QStringLiteral("Barre"));
        Barre->setEnabled(true);
        Barre->setGeometry(QRect(270, 80, 481, 21));
        Barre->setStyleSheet(QStringLiteral("font: 9pt \"MS Shell Dlg 2\";"));
        Barre->setValue(0);
        Barre->setAlignment(Qt::AlignCenter);
        Barre->setTextVisible(true);
        temps = new QTimeEdit(centralWidget);
        temps->setObjectName(QStringLiteral("temps"));
        temps->setGeometry(QRect(270, 20, 161, 51));
        temps->setStyleSheet(QLatin1String("background-color: rgb(243, 243, 243);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-color: rgb(184, 184, 184);\n"
"border-radius:3px;\n"
"color: rgb(34, 181, 55);\n"
"font: 14pt \"MS Shell Dlg 2\";\n"
"\n"
""));
        temps->setAlignment(Qt::AlignCenter);
        temps->setButtonSymbols(QAbstractSpinBox::NoButtons);
        temps->setProperty("showGroupSeparator", QVariant(false));
        temps->setCurrentSection(QDateTimeEdit::SecondSection);
        temps->setCurrentSectionIndex(2);
        temps->setTimeSpec(Qt::TimeZone);
        temps->setTime(QTime(0, 0, 0));
        manuel->setCentralWidget(centralWidget);
        textBrowser->raise();
        label_4->raise();
        pbuPinceFerme->raise();
        pbuQuitter->raise();
        pbuVersPalette->raise();
        buteV->raise();
        pbuVersT1->raise();
        buteA->raise();
        pbuMoteur1->raise();
        pbuPinceOuverte->raise();
        buteS->raise();
        label_3->raise();
        pbuMonter->raise();
        pbuVersTable->raise();
        pbuVersT2->raise();
        pbuDescendre->raise();
        pbuMoteur2->raise();
        pbuAuto->raise();
        layoutWidget->raise();
        gridLayoutWidget->raise();
        edtDialog->raise();
        pbuConnect->raise();
        pbuReset->raise();
        pbuReadAll->raise();
        buteAtt->raise();
        tabWidget->raise();
        pbuPom->raise();
        piecevision->raise();
        label->raise();
        Barre->raise();
        temps->raise();
        menuBar = new QMenuBar(manuel);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1220, 21));
        manuel->setMenuBar(menuBar);
        mainToolBar = new QToolBar(manuel);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        manuel->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(manuel);
        QObject::connect(pbuQuitter, SIGNAL(clicked()), manuel, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(manuel);
    } // setupUi

    void retranslateUi(QMainWindow *manuel)
    {
        manuel->setWindowTitle(QApplication::translate("manuel", "manuel", 0));
        label_4->setText(QApplication::translate("manuel", "Tapis 2", 0));
        pbuPinceFerme->setText(QApplication::translate("manuel", "PinceFerme", 0));
        pbuQuitter->setText(QApplication::translate("manuel", "Quitter", 0));
        pbuVersPalette->setText(QApplication::translate("manuel", "VersPalette", 0));
        buteV->setText(QApplication::translate("manuel", "but\303\251 vision", 0));
        pbuVersT1->setText(QApplication::translate("manuel", "TransfertVersT1", 0));
        buteA->setText(QApplication::translate("manuel", "but\303\251 poste A", 0));
        pbuMoteur1->setText(QApplication::translate("manuel", "Moteur1", 0));
        pbuPinceOuverte->setText(QApplication::translate("manuel", "PinceOuverte", 0));
        buteS->setText(QApplication::translate("manuel", "but\303\251 scara", 0));
        label_3->setText(QApplication::translate("manuel", "Tapis 1", 0));
        pbuMonter->setText(QApplication::translate("manuel", "Monter", 0));
        pbuVersTable->setText(QApplication::translate("manuel", "VersTable", 0));
        pbuVersT2->setText(QApplication::translate("manuel", "TansfertVersT2", 0));
        pbuDescendre->setText(QApplication::translate("manuel", "Descendre", 0));
        pbuMoteur2->setText(QApplication::translate("manuel", "Moteur2", 0));
        pbuAuto->setText(QApplication::translate("manuel", "Auto", 0));
        piece->setText(QApplication::translate("manuel", "1", 0));
        piece_2->setText(QApplication::translate("manuel", "2", 0));
        piece_3->setText(QApplication::translate("manuel", "3", 0));
        piece_4->setText(QApplication::translate("manuel", "4", 0));
        piece_5->setText(QApplication::translate("manuel", "5", 0));
        piece_6->setText(QApplication::translate("manuel", "6", 0));
        piece_7->setText(QApplication::translate("manuel", "7", 0));
        piece_8->setText(QApplication::translate("manuel", "8", 0));
        piece_9->setText(QApplication::translate("manuel", "9", 0));
        piece_10->setText(QApplication::translate("manuel", "10", 0));
        piece_11->setText(QApplication::translate("manuel", "11", 0));
        piece_12->setText(QApplication::translate("manuel", "12", 0));
        piece_13->setText(QApplication::translate("manuel", "13", 0));
        piece_14->setText(QApplication::translate("manuel", "14", 0));
        piece_15->setText(QApplication::translate("manuel", "15", 0));
        piece_16->setText(QApplication::translate("manuel", "16", 0));
        piece_17->setText(QApplication::translate("manuel", "17", 0));
        piece_18->setText(QApplication::translate("manuel", "18", 0));
        piece_19->setText(QApplication::translate("manuel", "19", 0));
        piece_20->setText(QApplication::translate("manuel", "20", 0));
        textBrowser->setHtml(QApplication::translate("manuel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/prefix/ressources/test.png\" /></p></body></html>", 0));
        edtDialog->setHtml(QApplication::translate("manuel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">Projet Cellflex 2015</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">R\303\251alis\303\251 par Alexandre Dubois</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">BTS IRIS</span></p>\n"
"<p style=\" margin-top:0px"
                        "; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">------------------------------------------------</span></p></body></html>", 0));
        pbuConnect->setText(QApplication::translate("manuel", "Demarrer", 0));
        pbuReset->setText(QApplication::translate("manuel", "Arr\303\252t rapide", 0));
        pbuReadAll->setText(QApplication::translate("manuel", "Mettre \303\240 jour \n"
" les tables", 0));
        buteAtt->setText(QApplication::translate("manuel", "but\303\251 attente", 0));
        pbuPom->setText(QApplication::translate("manuel", "POM \n"
"Table crois\303\251e", 0));
        label->setText(QApplication::translate("manuel", "Derni\303\250re pi\303\250ce trait\303\251e :", 0));
        temps->setDisplayFormat(QApplication::translate("manuel", "HH:mm:ss", 0));
    } // retranslateUi

};

namespace Ui {
    class manuel: public Ui_manuel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUEL_H
