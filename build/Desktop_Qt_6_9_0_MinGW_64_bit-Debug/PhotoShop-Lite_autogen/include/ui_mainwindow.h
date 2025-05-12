/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *mode1Btn;
    QPushButton *mode2Btn;
    QPushButton *mode3Btn;
    QPushButton *mode4Btn;
    QMenuBar *menubar;
    QMenu *menuPhotoShop_Lite;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(899, 548);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 82, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mode1Btn = new QPushButton(widget);
        mode1Btn->setObjectName("mode1Btn");

        verticalLayout->addWidget(mode1Btn);

        mode2Btn = new QPushButton(widget);
        mode2Btn->setObjectName("mode2Btn");

        verticalLayout->addWidget(mode2Btn);

        mode3Btn = new QPushButton(widget);
        mode3Btn->setObjectName("mode3Btn");

        verticalLayout->addWidget(mode3Btn);

        mode4Btn = new QPushButton(widget);
        mode4Btn->setObjectName("mode4Btn");

        verticalLayout->addWidget(mode4Btn);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 899, 21));
        menuPhotoShop_Lite = new QMenu(menubar);
        menuPhotoShop_Lite->setObjectName("menuPhotoShop_Lite");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPhotoShop_Lite->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mode1Btn->setText(QString());
        mode2Btn->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        mode3Btn->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        mode4Btn->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        menuPhotoShop_Lite->setTitle(QCoreApplication::translate("MainWindow", "PhotoShop Lite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
