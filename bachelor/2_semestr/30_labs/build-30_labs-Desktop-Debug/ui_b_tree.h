/********************************************************************************
** Form generated from reading UI file 'b_tree.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_B_TREE_H
#define UI_B_TREE_H

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

class Ui_B_tree
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *B_tree)
    {
        if (B_tree->objectName().isEmpty())
            B_tree->setObjectName(QStringLiteral("B_tree"));
        B_tree->resize(400, 300);
        menuBar = new QMenuBar(B_tree);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        B_tree->setMenuBar(menuBar);
        mainToolBar = new QToolBar(B_tree);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        B_tree->addToolBar(mainToolBar);
        centralWidget = new QWidget(B_tree);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        B_tree->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(B_tree);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        B_tree->setStatusBar(statusBar);

        retranslateUi(B_tree);

        QMetaObject::connectSlotsByName(B_tree);
    } // setupUi

    void retranslateUi(QMainWindow *B_tree)
    {
        B_tree->setWindowTitle(QApplication::translate("B_tree", "B_tree", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class B_tree: public Ui_B_tree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_B_TREE_H
