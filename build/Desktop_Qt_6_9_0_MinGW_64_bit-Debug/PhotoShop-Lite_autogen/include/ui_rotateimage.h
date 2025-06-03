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
    QLabel *label_title;
    QSlider *horizontalSlider_xdata;
    QSlider *verticalSlider_ydata;
    QDial *dial_angledata;
    QSpinBox *spinBox_ydata;
    QSpinBox *spinBox_xdata;
    QLabel *label_xdata;
    QLabel *label_ydata;
    QSpinBox *spinBox_angledata;
    QLabel *label_pic;
    QPushButton *confirmbutton;

    void setupUi(QWidget *rotateimage)
    {
        if (rotateimage->objectName().isEmpty())
            rotateimage->setObjectName("rotateimage");
        rotateimage->resize(400, 225);
        label_title = new QLabel(rotateimage);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(150, 20, 111, 21));
        horizontalSlider_xdata = new QSlider(rotateimage);
        horizontalSlider_xdata->setObjectName("horizontalSlider_xdata");
        horizontalSlider_xdata->setGeometry(QRect(110, 160, 160, 16));
        horizontalSlider_xdata->setMaximum(1024);
        horizontalSlider_xdata->setOrientation(Qt::Orientation::Horizontal);
        verticalSlider_ydata = new QSlider(rotateimage);
        verticalSlider_ydata->setObjectName("verticalSlider_ydata");
        verticalSlider_ydata->setGeometry(QRect(90, 60, 20, 81));
        verticalSlider_ydata->setMaximum(1024);
        verticalSlider_ydata->setOrientation(Qt::Orientation::Vertical);
        dial_angledata = new QDial(rotateimage);
        dial_angledata->setObjectName("dial_angledata");
        dial_angledata->setGeometry(QRect(300, 90, 50, 64));
        dial_angledata->setMinimum(-180);
        dial_angledata->setMaximum(180);
        spinBox_ydata = new QSpinBox(rotateimage);
        spinBox_ydata->setObjectName("spinBox_ydata");
        spinBox_ydata->setGeometry(QRect(11, 113, 71, 31));
        spinBox_xdata = new QSpinBox(rotateimage);
        spinBox_xdata->setObjectName("spinBox_xdata");
        spinBox_xdata->setGeometry(QRect(11, 160, 71, 31));
        label_xdata = new QLabel(rotateimage);
        label_xdata->setObjectName("label_xdata");
        label_xdata->setGeometry(QRect(20, 70, 54, 16));
        label_ydata = new QLabel(rotateimage);
        label_ydata->setObjectName("label_ydata");
        label_ydata->setGeometry(QRect(20, 40, 61, 20));
        spinBox_angledata = new QSpinBox(rotateimage);
        spinBox_angledata->setObjectName("spinBox_angledata");
        spinBox_angledata->setGeometry(QRect(300, 170, 61, 31));
        label_pic = new QLabel(rotateimage);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(120, 60, 151, 81));
        confirmbutton = new QPushButton(rotateimage);
        confirmbutton->setObjectName("confirmbutton");
        confirmbutton->setGeometry(QRect(140, 190, 80, 24));

        retranslateUi(rotateimage);

        QMetaObject::connectSlotsByName(rotateimage);
    } // setupUi

    void retranslateUi(QWidget *rotateimage)
    {
        rotateimage->setWindowTitle(QCoreApplication::translate("rotateimage", "Form", nullptr));
        label_title->setText(QCoreApplication::translate("rotateimage", "\350\257\267\350\276\223\345\205\245\346\227\213\350\275\254\345\217\202\346\225\260", nullptr));
        label_xdata->setText(QCoreApplication::translate("rotateimage", "x", nullptr));
        label_ydata->setText(QCoreApplication::translate("rotateimage", "y", nullptr));
        label_pic->setText(QString());
        confirmbutton->setText(QCoreApplication::translate("rotateimage", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rotateimage: public Ui_rotateimage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEIMAGE_H
