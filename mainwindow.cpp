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
    connect(ui->mode1Btn,&QPushButton::clicked,this,&MainWindow::Button_OpenFile);
}

void MainWindow::setBackGround(const QString & filename)
{
    QPixmap pixmap(filename);//创建照片
    QSize windowsSize = this->size(); // 获取当前窗口大小
    QPixmap scalePixmap = pixmap.scaled(windowsSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation); //讲图片所放到当前窗口的大小
    QPalette palette = this->palette();   //创建pattle对象并设置背景照片 调色板
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    this->setPalette(palette);   //将调色板应用到windows
}

void MainWindow::setButtonStyle(QPushButton * button , const QString & filename)
{
    button->setFixedSize(136,48);//设置按钮大小
    button->setIcon(QIcon(filename));//设置按钮图标
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
QString MainWindow::Button_OpenFile(){
    QString FilePath=QFileDialog::getOpenFileName(this,"OpenPicture-File",":/Picture","BMP-img(*.bmp)");

    if(!FilePath.isNull()){
        QPixmap pixmapin(FilePath);
        if(!pixmapin.isNull())
           // setPicWindow(ui->label,&pixmapin);
        //QSize lableSize = ui->label->size();   // 获取当前窗口大小
        //QPixmap scalePixmap = pixmapin.scaled(ui->label->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation); //讲图片所放到当前窗口的大小
        ui->label->setPixmap(pixmapin.scaled(ui->label->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }

    return FilePath;
}

void MainWindow::setPicWindow(QLabel *imageLabel,QPixmap *pixmap)
{
    imageLabel->setStyleSheet("border:1px solid #ccc;border-radius:6px");
    //QPalette palette = this->palette(); //创建pattle对象并设置背景照片 调色板
    //palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    //this->setPalette(palette);          //将调色板应用到windows
}
// void MainWindow::wheelEvent(QWheelEvent *e)//处理鼠标滑轮事件
// {

// }
// bool MainWindow::event(QEvent *event)//判断处理鼠标事件
// {

//     return QWidget::event(event)
// }

// void MainWindow::paintEvent(QPaintEvent *event)//绘制窗口
// {


// }

// void MainWindow::Button_medianFilter()
// {

// }
// void MainWindow::Button_shrinkImage()
// {

// }
// void MainWindow::Button_rotateImage()
// {

// }
MainWindow::~MainWindow()
{
    delete ui;
}
