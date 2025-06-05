#ifndef SHRINKMAGE_H
#define SHRINKMAGE_H

#include <QWidget>

class MainWindow;

namespace Ui {
class Shrinkmage;
}

class Shrinkmage : public QWidget
{
    Q_OBJECT

public:
    explicit Shrinkmage(QWidget *parent = nullptr);
    ~Shrinkmage();
public:
    // void Init();

private slots: //定义槽函数
    void Button_shrinkImage();



    void on_closebtn_clicked();

private:
    Ui::Shrinkmage *ui;
    MainWindow *m_parent;              // 主窗口类的对象

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

#endif // SHRINKMAGE_H
