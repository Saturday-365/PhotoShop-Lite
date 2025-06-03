/********************************************************************************
** Form generated from reading UI file 'shrinkmage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHRINKMAGE_H
#define UI_SHRINKMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shrinkmage
{
public:
    QSlider *QSLShrinkxFactor;
    QTextBrowser *TitletextBrowser;
    QPushButton *ConfirmButton;
    QSpinBox *QSPShrinkxFactor;
    QSpinBox *QSPShrinkyFactor;
    QSlider *QSLShrinkyFactor;

    void setupUi(QWidget *Shrinkmage)
    {
        if (Shrinkmage->objectName().isEmpty())
            Shrinkmage->setObjectName("Shrinkmage");
        Shrinkmage->resize(400, 225);
        QSLShrinkxFactor = new QSlider(Shrinkmage);
        QSLShrinkxFactor->setObjectName("QSLShrinkxFactor");
        QSLShrinkxFactor->setGeometry(QRect(150, 100, 181, 31));
        QSLShrinkxFactor->setMaximum(100);
        QSLShrinkxFactor->setPageStep(10);
        QSLShrinkxFactor->setOrientation(Qt::Orientation::Horizontal);
        QSLShrinkxFactor->setTickPosition(QSlider::TickPosition::TicksBothSides);
        QSLShrinkxFactor->setTickInterval(10);
        TitletextBrowser = new QTextBrowser(Shrinkmage);
        TitletextBrowser->setObjectName("TitletextBrowser");
        TitletextBrowser->setGeometry(QRect(70, 40, 256, 31));
        ConfirmButton = new QPushButton(Shrinkmage);
        ConfirmButton->setObjectName("ConfirmButton");
        ConfirmButton->setGeometry(QRect(280, 180, 51, 31));
        QSPShrinkxFactor = new QSpinBox(Shrinkmage);
        QSPShrinkxFactor->setObjectName("QSPShrinkxFactor");
        QSPShrinkxFactor->setGeometry(QRect(60, 100, 71, 31));
        QSPShrinkyFactor = new QSpinBox(Shrinkmage);
        QSPShrinkyFactor->setObjectName("QSPShrinkyFactor");
        QSPShrinkyFactor->setGeometry(QRect(60, 130, 71, 31));
        QSLShrinkyFactor = new QSlider(Shrinkmage);
        QSLShrinkyFactor->setObjectName("QSLShrinkyFactor");
        QSLShrinkyFactor->setGeometry(QRect(150, 130, 181, 31));
        QSLShrinkyFactor->setMaximum(100);
        QSLShrinkyFactor->setPageStep(10);
        QSLShrinkyFactor->setOrientation(Qt::Orientation::Horizontal);
        QSLShrinkyFactor->setTickPosition(QSlider::TickPosition::TicksBothSides);
        QSLShrinkyFactor->setTickInterval(10);

        retranslateUi(Shrinkmage);

        QMetaObject::connectSlotsByName(Shrinkmage);
    } // setupUi

    void retranslateUi(QWidget *Shrinkmage)
    {
        Shrinkmage->setWindowTitle(QCoreApplication::translate("Shrinkmage", "Form", nullptr));
        TitletextBrowser->setHtml(QCoreApplication::translate("Shrinkmage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">\350\257\267\351\200\232\350\277\207\346\273\221\345\235\227\351\200\211\346\213\251\344\275\240\346\203\263\350\246\201\347\274\251\345\260\217\347\232\204\347\263\273\346\225\260</span></p></body></html>", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("Shrinkmage", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shrinkmage: public Ui_Shrinkmage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHRINKMAGE_H
