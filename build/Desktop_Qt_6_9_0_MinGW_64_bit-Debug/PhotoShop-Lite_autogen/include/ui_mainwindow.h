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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *mainWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *mainLayout;
    QWidget *titleBar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *APPpixLable;
    QLabel *appnamelabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *minBtn;
    QPushButton *maxBtn;
    QPushButton *closeBtn;
    QWidget *Displaywidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *mode1Btn;
    QPushButton *mode2Btn;
    QPushButton *mode3Btn;
    QPushButton *mode4Btn;
    QTextEdit *Pic_filepath_textEdit;
    QLabel *filepath_label;
    QLabel *Pic_label;
    QLabel *backgroundlabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 575);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 971, 551));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainWidget = new QWidget(verticalLayoutWidget);
        mainWidget->setObjectName("mainWidget");
        verticalLayoutWidget_2 = new QWidget(mainWidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 941, 531));
        mainLayout = new QVBoxLayout(verticalLayoutWidget_2);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new QWidget(verticalLayoutWidget_2);
        titleBar->setObjectName("titleBar");
        titleBar->setEnabled(true);
        titleBar->setMaximumSize(QSize(1111, 1111));
        titleBar->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        horizontalLayoutWidget = new QWidget(titleBar);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 941, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        APPpixLable = new QLabel(horizontalLayoutWidget);
        APPpixLable->setObjectName("APPpixLable");

        horizontalLayout->addWidget(APPpixLable);

        appnamelabel = new QLabel(horizontalLayoutWidget);
        appnamelabel->setObjectName("appnamelabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font.setBold(true);
        appnamelabel->setFont(font);
        appnamelabel->setTextFormat(Qt::TextFormat::RichText);
        appnamelabel->setMargin(2);

        horizontalLayout->addWidget(appnamelabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minBtn = new QPushButton(horizontalLayoutWidget);
        minBtn->setObjectName("minBtn");
        minBtn->setCheckable(false);

        horizontalLayout->addWidget(minBtn);

        maxBtn = new QPushButton(horizontalLayoutWidget);
        maxBtn->setObjectName("maxBtn");

        horizontalLayout->addWidget(maxBtn);

        closeBtn = new QPushButton(horizontalLayoutWidget);
        closeBtn->setObjectName("closeBtn");

        horizontalLayout->addWidget(closeBtn);

        horizontalLayout->setStretch(2, 19);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        mainLayout->addWidget(titleBar);

        Displaywidget = new QWidget(verticalLayoutWidget_2);
        Displaywidget->setObjectName("Displaywidget");
        layoutWidget = new QWidget(Displaywidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 70, 161, 351));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        mode1Btn = new QPushButton(layoutWidget);
        mode1Btn->setObjectName("mode1Btn");
        mode1Btn->setEnabled(true);
        mode1Btn->setIconSize(QSize(136, 48));

        verticalLayout_2->addWidget(mode1Btn);

        mode2Btn = new QPushButton(layoutWidget);
        mode2Btn->setObjectName("mode2Btn");
        mode2Btn->setIconSize(QSize(136, 48));

        verticalLayout_2->addWidget(mode2Btn);

        mode3Btn = new QPushButton(layoutWidget);
        mode3Btn->setObjectName("mode3Btn");
        mode3Btn->setIconSize(QSize(136, 48));

        verticalLayout_2->addWidget(mode3Btn);

        mode4Btn = new QPushButton(layoutWidget);
        mode4Btn->setObjectName("mode4Btn");
        mode4Btn->setIconSize(QSize(136, 48));

        verticalLayout_2->addWidget(mode4Btn);

        Pic_filepath_textEdit = new QTextEdit(Displaywidget);
        Pic_filepath_textEdit->setObjectName("Pic_filepath_textEdit");
        Pic_filepath_textEdit->setGeometry(QRect(230, 410, 701, 41));
        filepath_label = new QLabel(Displaywidget);
        filepath_label->setObjectName("filepath_label");
        filepath_label->setGeometry(QRect(240, 420, 701, 21));
        Pic_label = new QLabel(Displaywidget);
        Pic_label->setObjectName("Pic_label");
        Pic_label->setGeometry(QRect(230, 40, 670, 340));
        backgroundlabel = new QLabel(Displaywidget);
        backgroundlabel->setObjectName("backgroundlabel");
        backgroundlabel->setGeometry(QRect(220, 30, 690, 360));
        backgroundlabel->raise();
        layoutWidget->raise();
        Pic_filepath_textEdit->raise();
        filepath_label->raise();
        Pic_label->raise();

        mainLayout->addWidget(Displaywidget);

        mainLayout->setStretch(0, 1);
        mainLayout->setStretch(1, 16);

        verticalLayout->addWidget(mainWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        APPpixLable->setText(QString());
        appnamelabel->setText(QCoreApplication::translate("MainWindow", "PhotoShop-Lite", nullptr));
        minBtn->setText(QString());
        maxBtn->setText(QString());
        closeBtn->setText(QString());
        mode1Btn->setText(QString());
        mode2Btn->setText(QString());
        mode3Btn->setText(QString());
        mode4Btn->setText(QString());
        filepath_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Pic_label->setText(QString());
        backgroundlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
