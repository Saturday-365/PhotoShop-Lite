#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("PhotoShop Lite"); //设置窗口标题
    initButtons();

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
    setButtonStyle(ui->mode1Btn, "C:/QT_Program/PhotoShop-Lite/Icon/waiting.png");
    setButtonStyle(ui->mode2Btn, "C:/QT_Program/PhotoShop-Lite/Icon/waiting.png");
    setButtonStyle(ui->mode3Btn, "C:/QT_Program/PhotoShop-Lite/Icon/waiting.png");
    setButtonStyle(ui->mode4Btn, "C:/QT_Program/PhotoShop-Lite/Icon/waiting.png");

}
MainWindow::~MainWindow()
{
    delete ui;
}
