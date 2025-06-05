/********************************************************************************
** Form generated from reading UI file 'shrinkmage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHRINKMAGE_H
#define UI_SHRINKMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shrinkmage
{
public:
    QPushButton *ConfirmButton;
    QSlider *QSLShrinkyFactor;
    QPushButton *closebtn;
    QSlider *QSLShrinkxFactor;
    QSpinBox *QSPShrinkxFactor;
    QSpinBox *QSPShrinkyFactor;
    QLabel *label;
    QFrame *frame;

    void setupUi(QWidget *Shrinkmage)
    {
        if (Shrinkmage->objectName().isEmpty())
            Shrinkmage->setObjectName("Shrinkmage");
        Shrinkmage->resize(400, 225);
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
        Shrinkmage->setPalette(palette);
        ConfirmButton = new QPushButton(Shrinkmage);
        ConfirmButton->setObjectName("ConfirmButton");
        ConfirmButton->setGeometry(QRect(130, 160, 77, 30));
        QSLShrinkyFactor = new QSlider(Shrinkmage);
        QSLShrinkyFactor->setObjectName("QSLShrinkyFactor");
        QSLShrinkyFactor->setGeometry(QRect(130, 110, 181, 31));
        QSLShrinkyFactor->setMaximum(100);
        QSLShrinkyFactor->setPageStep(10);
        QSLShrinkyFactor->setOrientation(Qt::Orientation::Horizontal);
        QSLShrinkyFactor->setTickPosition(QSlider::TickPosition::TicksBothSides);
        QSLShrinkyFactor->setTickInterval(10);
        closebtn = new QPushButton(Shrinkmage);
        closebtn->setObjectName("closebtn");
        closebtn->setGeometry(QRect(220, 160, 30, 30));
        QSLShrinkxFactor = new QSlider(Shrinkmage);
        QSLShrinkxFactor->setObjectName("QSLShrinkxFactor");
        QSLShrinkxFactor->setGeometry(QRect(130, 80, 181, 31));
        QSLShrinkxFactor->setMaximum(100);
        QSLShrinkxFactor->setPageStep(10);
        QSLShrinkxFactor->setOrientation(Qt::Orientation::Horizontal);
        QSLShrinkxFactor->setTickPosition(QSlider::TickPosition::TicksBothSides);
        QSLShrinkxFactor->setTickInterval(10);
        QSPShrinkxFactor = new QSpinBox(Shrinkmage);
        QSPShrinkxFactor->setObjectName("QSPShrinkxFactor");
        QSPShrinkxFactor->setGeometry(QRect(40, 80, 71, 31));
        QSPShrinkyFactor = new QSpinBox(Shrinkmage);
        QSPShrinkyFactor->setObjectName("QSPShrinkyFactor");
        QSPShrinkyFactor->setGeometry(QRect(40, 110, 71, 31));
        label = new QLabel(Shrinkmage);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 331, 61));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        frame = new QFrame(Shrinkmage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 399, 224));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 119, 246);\n"
"border-radius:20px"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->raise();
        ConfirmButton->raise();
        QSLShrinkyFactor->raise();
        closebtn->raise();
        QSLShrinkxFactor->raise();
        QSPShrinkxFactor->raise();
        QSPShrinkyFactor->raise();
        label->raise();

        retranslateUi(Shrinkmage);

        QMetaObject::connectSlotsByName(Shrinkmage);
    } // setupUi

    void retranslateUi(QWidget *Shrinkmage)
    {
        Shrinkmage->setWindowTitle(QCoreApplication::translate("Shrinkmage", "Form", nullptr));
        ConfirmButton->setText(QString());
        closebtn->setText(QString());
        label->setText(QCoreApplication::translate("Shrinkmage", "\350\257\267\351\200\232\350\277\207\346\273\221\345\235\227\351\200\211\346\213\251\346\250\252\347\272\265\346\226\271\345\220\221\344\270\212\347\232\204\347\274\251\345\260\217\346\257\224\344\276\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shrinkmage: public Ui_Shrinkmage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHRINKMAGE_H
