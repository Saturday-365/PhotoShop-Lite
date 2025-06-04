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
    QLabel *filepath_label;
    QLabel *Pic_label;
    QLabel *backgroundlabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1006, 630);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 971, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainWidget = new QWidget(verticalLayoutWidget);
        mainWidget->setObjectName("mainWidget");
        verticalLayoutWidget_2 = new QWidget(mainWidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 951, 581));
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
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 951, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        APPpixLable = new QLabel(horizontalLayoutWidget);
        APPpixLable->setObjectName("APPpixLable");
        APPpixLable->setToolTipDuration(-1);
        APPpixLable->setMargin(2);

        horizontalLayout->addWidget(APPpixLable);

        appnamelabel = new QLabel(horizontalLayoutWidget);
        appnamelabel->setObjectName("appnamelabel");
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush1);
        QBrush brush2(QColor(255, 85, 0, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush4);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::HighlightedText, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush6(QColor(0, 0, 0, 127));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::HighlightedText, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::HighlightedText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush7(QColor(127, 127, 127, 127));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush2);
#endif
        appnamelabel->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font.setPointSize(11);
        font.setBold(true);
        appnamelabel->setFont(font);
        appnamelabel->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));
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

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 20);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        mainLayout->addWidget(titleBar);

        Displaywidget = new QWidget(verticalLayoutWidget_2);
        Displaywidget->setObjectName("Displaywidget");
        layoutWidget = new QWidget(Displaywidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 40, 161, 351));
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

        filepath_label = new QLabel(Displaywidget);
        filepath_label->setObjectName("filepath_label");
        filepath_label->setGeometry(QRect(230, 460, 701, 21));
        Pic_label = new QLabel(Displaywidget);
        Pic_label->setObjectName("Pic_label");
        Pic_label->setGeometry(QRect(230, 40, 670, 340));
        backgroundlabel = new QLabel(Displaywidget);
        backgroundlabel->setObjectName("backgroundlabel");
        backgroundlabel->setGeometry(QRect(220, 30, 690, 360));
        backgroundlabel->raise();
        layoutWidget->raise();
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
        filepath_label->setText(QString());
        Pic_label->setText(QString());
        backgroundlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
