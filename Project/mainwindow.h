#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>
#include <QImage>
#include <qlabel.h>
#include "shrinkmage.h"
#include "rotateimage.h"

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

    void reflash_PicShow();

 private:
    void setBackGround(const QString & filename);
    void setButtonStyle(QPushButton * button , const QString & filename);//设置按钮样式
    void setbarButtonStyle(QPushButton * button , const QString & filename);
    void initButtons();//初始化所有按钮
    void setPicWindow(QLabel *imageLabel,QPixmap *pixmap);
    void Init();

private slots: //定义槽函数
    void Button_OpenFile();//打开照片文件 并返回照片文件的地址
    void Button_medianFilter();

    void on_minBtn_clicked();//配置无边框窗口后自行写关闭窗口等按钮
    void on_closeBtn_clicked();
    void on_maxBtn_clicked();
    void on_mode3Btn_clicked();
    void on_mode4Btn_clicked();

private:
    Ui::MainWindow *ui;
    Shrinkmage *shrinkWindow;
    rotateimage *rotateWindow;

    bool _isleftpressed = false; //判断是否是左键点击
    int _curpos = 0;    //鼠标左键按下时光标所在区域
    QPoint _plast;      //获取鼠标左键按下时光标在全局(屏幕而非窗口)的位置
    void mousePressEvent(QMouseEvent* event);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent* event);//鼠标释放事件
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件
    int countRow(QPoint p);            //获取光标在窗口所在区域的 行   返回行数
    int countFlag(QPoint p,int row);    //获取光标在窗口所在区域的 列  返回行列坐标
    void setCursorType(int flag);          //根据传入的坐标，设置光标样式
};
#endif // MAINWINDOW_H
