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
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shrinkmage
{
public:
    QFrame *frame;
    QTextBrowser *TitletextBrowser;
    QSpinBox *QSPShrinkxFactor;
    QSpinBox *QSPShrinkyFactor;
    QSlider *QSLShrinkxFactor;
    QSlider *QSLShrinkyFactor;
    QPushButton *ConfirmButton;
    QPushButton *closebtn;

    void setupUi(QWidget *Shrinkmage)
    {
        if (Shrinkmage->objectName().isEmpty())
            Shrinkmage->setObjectName("Shrinkmage");
        Shrinkmage->resize(400, 225);
        frame = new QFrame(Shrinkmage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 381, 201));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:20px"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        TitletextBrowser = new QTextBrowser(frame);
        TitletextBrowser->setObjectName("TitletextBrowser");
        TitletextBrowser->setGeometry(QRect(50, 20, 256, 31));
        QSPShrinkxFactor = new QSpinBox(frame);
        QSPShrinkxFactor->setObjectName("QSPShrinkxFactor");
        QSPShrinkxFactor->setGeometry(QRect(50, 90, 71, 31));
        QSPShrinkyFactor = new QSpinBox(frame);
        QSPShrinkyFactor->setObjectName("QSPShrinkyFactor");
        QSPShrinkyFactor->setGeometry(QRect(50, 120, 71, 31));
        QSLShrinkxFactor = new QSlider(frame);
        QSLShrinkxFactor->setObjectName("QSLShrinkxFactor");
        QSLShrinkxFactor->setGeometry(QRect(140, 90, 181, 31));
        QSLShrinkxFactor->setMaximum(100);
        QSLShrinkxFactor->setPageStep(10);
        QSLShrinkxFactor->setOrientation(Qt::Orientation::Horizontal);
        QSLShrinkxFactor->setTickPosition(QSlider::TickPosition::TicksBothSides);
        QSLShrinkxFactor->setTickInterval(10);
        QSLShrinkyFactor = new QSlider(frame);
        QSLShrinkyFactor->setObjectName("QSLShrinkyFactor");
        QSLShrinkyFactor->setGeometry(QRect(140, 120, 181, 31));
        QSLShrinkyFactor->setMaximum(100);
        QSLShrinkyFactor->setPageStep(10);
        QSLShrinkyFactor->setOrientation(Qt::Orientation::Horizontal);
        QSLShrinkyFactor->setTickPosition(QSlider::TickPosition::TicksBothSides);
        QSLShrinkyFactor->setTickInterval(10);
        ConfirmButton = new QPushButton(frame);
        ConfirmButton->setObjectName("ConfirmButton");
        ConfirmButton->setGeometry(QRect(130, 160, 101, 31));
        closebtn = new QPushButton(frame);
        closebtn->setObjectName("closebtn");
        closebtn->setGeometry(QRect(350, 10, 24, 24));

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
        closebtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Shrinkmage: public Ui_Shrinkmage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHRINKMAGE_H
