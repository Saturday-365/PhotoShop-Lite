#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>

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

    void setButtonStyle(QPushButton * button , const QString & filename);//设置按钮样式
    void initButtons();//初始化所有按钮


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
