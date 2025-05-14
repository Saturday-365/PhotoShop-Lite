#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>
#include <QImage>
#include <qlabel.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


 private:
    void setBackGround(const QString & filename);
    void setButtonStyle(QPushButton * button , const QString & filename);//设置按钮样式
    void initButtons();//初始化所有按钮
    void setPicWindow(QLabel *imageLabel,QPixmap *pixmap);

private slots: //定义槽函数
    void Button_OpenFile();
//     void Button_medianFilter();
//     void Button_shrinkImage();
//     void Button_rotateImage();
//     void paintEvent(QPaintEvent *event);
// public:
//     enum Type{
//         None=0,medianFilter,shrink,rotate
//     }
//     void wheelEvent(QWheelEvent *e);//处理鼠标滑轮事件
//     bool event(QEvent *event);//判断处理鼠标事件

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
