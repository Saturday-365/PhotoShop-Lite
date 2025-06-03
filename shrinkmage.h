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

private slots: //定义槽函数
    void Button_shrinkImage();



private:
    Ui::Shrinkmage *ui;
    MainWindow *m_parent;              // 主窗口类的对象
};

#endif // SHRINKMAGE_H
