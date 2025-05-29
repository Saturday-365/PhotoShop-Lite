#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "shrinkmage.h"
// #include "ui_shrinkmage.h"
#include <QIcon>
#include <QPixmap>
#include <QPalette>
#include "./SourseLib/BMP_Process.h"

QString FilePath,FilePath_Out;
string sFilePath,sFilePath_Out;
BMP_Process Process;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("PhotoShop Lite"); //设置窗口标题
    setFixedSize(960,540);
    setBackGround(":/Picture/mclaren senna wallpaper.jpg"); //设置背景
    initButtons();
    connect(ui->mode1Btn,&QPushButton::clicked,this,&MainWindow::Button_OpenFile);//按钮链接槽函数 打开图片文件
    connect(ui->mode2Btn,&QPushButton::clicked,this,&MainWindow::Button_medianFilter);//按钮链接槽函数 实现中值滤波并重新显示新的图片

}

void MainWindow::setBackGround(const QString & filename)  //设置背景
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
void MainWindow::reflash_PicShow(){
    QPixmap pixmapin(FilePath_Out);
    if(!pixmapin.isNull()){
        ui->Pic_label->clear();
        // QSize lableSize = pixmapin.size();
        QSize lableSize = ui->Pic_label->size();
        ui->Pic_label->setPixmap(pixmapin.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
        ui->Pic_label->setAlignment(Qt::AlignCenter);//图片居中这个lable
    }
}
void MainWindow::Button_OpenFile(){  //打开图片文件槽函数，返回这个文件的路径

    FilePath=QFileDialog::getOpenFileName(this,"OpenPicture-File 打开你想要转换的BMP格式文件(不能包含中文路径)",":/Picture","BMP-img(*.bmp)");
    sFilePath = FilePath.toStdString();
    sFilePath=Process.convertPath(sFilePath);   //转化路径格式为io流可以读取的格式 /*  "/"->"\\" */
    ui->Pic_filepath_textEdit->insertPlainText(FilePath);// 显示打开的图片的路径
    if(!FilePath.isNull()){
        QPixmap pixmapin(FilePath);
        if(!pixmapin.isNull()){
            QSize lableSize = ui->Pic_label->size();   // 获取当前窗口大小
            ui->Pic_label->setPixmap(pixmapin.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
            ui->Pic_label->setAlignment(Qt::AlignCenter);//图片居中这个lable
        }
    }
    FilePath_Out=QFileDialog::getSaveFileName(this,"SavePicture-File 请选择你想要把文件保存在哪里(不能包含中文路径)",":/Picture","BMP-img(*.bmp)");
    sFilePath_Out= FilePath_Out.toStdString();
    sFilePath_Out=Process.convertPath(sFilePath_Out);   //转化路径格式为io流可以读取的格式 /*  "/"->"\\" */

}
void MainWindow::Button_medianFilter(){
    char bmp_name1[50] = "hqu.bmp"; // 输入BMP图像文件的名称
    char bmp_name2[50] = "new.bmp"; // 输出BMP图像文件的名称
    Process.medianFilter(sFilePath,sFilePath_Out);//执行bmp处理函数

    QPixmap pixmapin(FilePath_Out);
    if(!pixmapin.isNull()){
        ui->Pic_label->clear();
        QSize lableSize = ui->Pic_label->size();   // 获取当前窗口大小
        ui->Pic_label->setPixmap(pixmapin.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
        ui->Pic_label->setAlignment(Qt::AlignCenter);//图片居中这个lable
    }

}

void MainWindow::on_mode3Btn_clicked()
{
    Shrinkmage *configWindow = new Shrinkmage(this);
    configWindow->show();


}


void MainWindow::setPicWindow(QLabel *imageLabel,QPixmap *pixmap)
{
    imageLabel->setStyleSheet("border:1px solid #ccc;border-radius:6px");
    //QPalette palette = this->palette(); //创建pattle对象并设置背景照片 调色板
    //palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    //this->setPalette(palette);          //将调色板应用到windows
}

MainWindow::~MainWindow()
{
    delete ui;
}


