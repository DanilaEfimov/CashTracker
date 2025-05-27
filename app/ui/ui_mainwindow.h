/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actconverter;
    QAction *actprogress;
    QAction *actnoteint;
    QAction *actdbint;
    QAction *actionlight_theme;
    QAction *actiondark_theme;
    QAction *actnews;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menumenu;
    QMenu *menuview;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(369, 315);
        actconverter = new QAction(MainWindow);
        actconverter->setObjectName("actconverter");
        actprogress = new QAction(MainWindow);
        actprogress->setObjectName("actprogress");
        actnoteint = new QAction(MainWindow);
        actnoteint->setObjectName("actnoteint");
        actdbint = new QAction(MainWindow);
        actdbint->setObjectName("actdbint");
        actionlight_theme = new QAction(MainWindow);
        actionlight_theme->setObjectName("actionlight_theme");
        actiondark_theme = new QAction(MainWindow);
        actiondark_theme->setObjectName("actiondark_theme");
        actnews = new QAction(MainWindow);
        actnews->setObjectName("actnews");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 369, 17));
        menumenu = new QMenu(menubar);
        menumenu->setObjectName("menumenu");
        menuview = new QMenu(menubar);
        menuview->setObjectName("menuview");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menumenu->menuAction());
        menubar->addAction(menuview->menuAction());
        menumenu->addAction(actconverter);
        menumenu->addAction(actprogress);
        menumenu->addAction(actnoteint);
        menumenu->addAction(actdbint);
        menumenu->addAction(actnews);
        menuview->addAction(actionlight_theme);
        menuview->addAction(actiondark_theme);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actconverter->setText(QCoreApplication::translate("MainWindow", "converter", nullptr));
        actprogress->setText(QCoreApplication::translate("MainWindow", "progress", nullptr));
        actnoteint->setText(QCoreApplication::translate("MainWindow", "make note", nullptr));
        actdbint->setText(QCoreApplication::translate("MainWindow", "db interface", nullptr));
        actionlight_theme->setText(QCoreApplication::translate("MainWindow", "light theme", nullptr));
        actiondark_theme->setText(QCoreApplication::translate("MainWindow", "dark theme", nullptr));
        actnews->setText(QCoreApplication::translate("MainWindow", "news", nullptr));
        menumenu->setTitle(QCoreApplication::translate("MainWindow", "menu", nullptr));
        menuview->setTitle(QCoreApplication::translate("MainWindow", "view", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
