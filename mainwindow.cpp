#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("PhotoShop Lite"); //设置窗口标题
    //ui->mode1Btn->setFixedSize(50,50);//设置按钮大小
    ui->mode1Btn->setIcon(QIcon(":/Icon/STAR.PNG"));//设置按钮图标
    ui->mode1Btn->setIconSize(QSize(ui->mode1Btn->width(),ui->mode1Btn->height()));//设置按钮图标大小
    ui->mode1Btn->setStyleSheet("background-color:transparent");

}

MainWindow::~MainWindow()
{
    delete ui;
}
