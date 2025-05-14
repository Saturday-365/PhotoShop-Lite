#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>
#include <QPixmap>
#include <QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("PhotoShop Lite"); //设置窗口标题
    setFixedSize(960,540);
    setBackGround(":/Picture/mclaren senna wallpaper.jpg"); //设置背景
    initButtons();

}
void MainWindow::setBackGround(const QString & filename)
{
    QPixmap pixmap(filename);//创建照片
    QSize windowsSize = this->size(); // 获取当前窗口大小
    QPixmap scalePixmap = pixmap.scaled(windowsSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation); //讲图片所放到当前窗口的大小
    QPalette palette = this->palette();   //创建pattle对象并设置背景照片 调色板
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    this->setPalette(palette);
}
void MainWindow::setButtonStyle(QPushButton * button , const QString & filename)
{
    button->setFixedSize(136,48);//设置按钮大小
    button->setIcon(QIcon(filename));//设置按钮图标  目前只有这个绝对地址有效 相对地址没有效果不知道为什么
    button->setIconSize(QSize(button->width(),button->height()));//设置按钮图标大小
    button->setStyleSheet("background-color:transparent");
}
void MainWindow::initButtons()
{
    setButtonStyle(ui->mode1Btn, ":/Icon/wating.png");
    setButtonStyle(ui->mode2Btn, ":/Icon/wating.png");
    setButtonStyle(ui->mode3Btn, ":/Icon/wating.png");
    setButtonStyle(ui->mode4Btn, ":/Icon/wating.png");

}
MainWindow::~MainWindow()
{
    delete ui;
}
