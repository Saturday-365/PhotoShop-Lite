/********************************************************************************
** Form generated from reading UI file 'rotateimage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATEIMAGE_H
#define UI_ROTATEIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rotateimage
{
public:
    QWidget *widget;
    QPushButton *confirmbutton;
    QSlider *horizontalSlider_xdata;
    QSlider *verticalSlider_ydata;
    QSpinBox *spinBox_ydata;
    QSpinBox *spinBox_xdata;
    QLabel *label_title;
    QLabel *label_ydata_2;
    QPushButton *closebut;
    QDial *dial_angledata;
    QSpinBox *spinBox_angledata;
    QLabel *label_pic;

    void setupUi(QWidget *rotateimage)
    {
        if (rotateimage->objectName().isEmpty())
            rotateimage->setObjectName("rotateimage");
        rotateimage->resize(400, 225);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush3);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush4);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 127));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush5);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush1);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush5);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush1);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush6(QColor(127, 127, 127, 127));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush1);
#endif
        rotateimage->setPalette(palette);
        widget = new QWidget(rotateimage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 381, 211));
        QPalette palette1;
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        widget->setPalette(palette1);
        widget->setStyleSheet(QString::fromUtf8(""));
        confirmbutton = new QPushButton(widget);
        confirmbutton->setObjectName("confirmbutton");
        confirmbutton->setGeometry(QRect(150, 180, 80, 24));
        horizontalSlider_xdata = new QSlider(widget);
        horizontalSlider_xdata->setObjectName("horizontalSlider_xdata");
        horizontalSlider_xdata->setGeometry(QRect(90, 150, 160, 16));
        horizontalSlider_xdata->setMaximum(1024);
        horizontalSlider_xdata->setOrientation(Qt::Orientation::Horizontal);
        verticalSlider_ydata = new QSlider(widget);
        verticalSlider_ydata->setObjectName("verticalSlider_ydata");
        verticalSlider_ydata->setGeometry(QRect(80, 60, 20, 81));
        verticalSlider_ydata->setMaximum(1024);
        verticalSlider_ydata->setOrientation(Qt::Orientation::Vertical);
        spinBox_ydata = new QSpinBox(widget);
        spinBox_ydata->setObjectName("spinBox_ydata");
        spinBox_ydata->setGeometry(QRect(10, 110, 71, 31));
        QPalette palette2;
        spinBox_ydata->setPalette(palette2);
        spinBox_ydata->setMaximum(1024);
        spinBox_xdata = new QSpinBox(widget);
        spinBox_xdata->setObjectName("spinBox_xdata");
        spinBox_xdata->setGeometry(QRect(10, 140, 71, 31));
        spinBox_xdata->setMaximum(1024);
        label_title = new QLabel(widget);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(110, 10, 151, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        label_title->setFont(font);
        label_ydata_2 = new QLabel(widget);
        label_ydata_2->setObjectName("label_ydata_2");
        label_ydata_2->setGeometry(QRect(280, 30, 61, 31));
        QFont font1;
        font1.setPointSize(14);
        label_ydata_2->setFont(font1);
        closebut = new QPushButton(widget);
        closebut->setObjectName("closebut");
        closebut->setGeometry(QRect(340, 10, 24, 24));
        closebut->setMinimumSize(QSize(0, 0));
        dial_angledata = new QDial(widget);
        dial_angledata->setObjectName("dial_angledata");
        dial_angledata->setGeometry(QRect(270, 60, 90, 90));
        dial_angledata->setMinimum(-150);
        dial_angledata->setMaximum(150);
        spinBox_angledata = new QSpinBox(widget);
        spinBox_angledata->setObjectName("spinBox_angledata");
        spinBox_angledata->setGeometry(QRect(280, 160, 71, 31));
        spinBox_angledata->setMinimum(-150);
        spinBox_angledata->setMaximum(150);
        label_pic = new QLabel(widget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(110, 70, 131, 71));
        confirmbutton->raise();
        horizontalSlider_xdata->raise();
        verticalSlider_ydata->raise();
        spinBox_xdata->raise();
        label_title->raise();
        label_ydata_2->raise();
        closebut->raise();
        dial_angledata->raise();
        spinBox_angledata->raise();
        label_pic->raise();
        spinBox_ydata->raise();

        retranslateUi(rotateimage);

        QMetaObject::connectSlotsByName(rotateimage);
    } // setupUi

    void retranslateUi(QWidget *rotateimage)
    {
        rotateimage->setWindowTitle(QCoreApplication::translate("rotateimage", "Form", nullptr));
        confirmbutton->setText(QCoreApplication::translate("rotateimage", "PushButton", nullptr));
        label_title->setText(QCoreApplication::translate("rotateimage", "\350\257\267\350\276\223\345\205\245\346\227\213\350\275\254\345\217\202\346\225\260", nullptr));
        label_ydata_2->setText(QCoreApplication::translate("rotateimage", "Angle", nullptr));
        closebut->setText(QString());
        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rotateimage: public Ui_rotateimage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEIMAGE_H
