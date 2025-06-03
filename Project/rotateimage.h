#ifndef ROTATEIMAGE_H
#define ROTATEIMAGE_H

#include <QWidget>

class MainWindow;

namespace Ui {
class rotateimage;
}

class rotateimage : public QWidget
{
    Q_OBJECT

public:
    explicit rotateimage(QWidget *parent = nullptr);
    ~rotateimage();

private slots: //定义槽函数
    void Button_rotateImage();

private:
    Ui::rotateimage *ui;
    MainWindow *m_parent;              // 主窗口类的对象

};

#endif // ROTATEIMAGE_H
