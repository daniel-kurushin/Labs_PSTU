/********************************************************************************
** Form generated from reading UI file 'stp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STP_H
#define UI_STP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_STP
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *STP)
    {
        if (STP->objectName().isEmpty())
            STP->setObjectName(QStringLiteral("STP"));
        STP->resize(400, 300);
        menuBar = new QMenuBar(STP);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        STP->setMenuBar(menuBar);
        mainToolBar = new QToolBar(STP);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        STP->addToolBar(mainToolBar);
        centralWidget = new QWidget(STP);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        STP->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(STP);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        STP->setStatusBar(statusBar);

        retranslateUi(STP);

        QMetaObject::connectSlotsByName(STP);
    } // setupUi

    void retranslateUi(QMainWindow *STP)
    {
        STP->setWindowTitle(QApplication::translate("STP", "STP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class STP: public Ui_STP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STP_H
