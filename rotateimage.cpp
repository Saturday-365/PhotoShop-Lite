#include "rotateimage.h"
#include "ui_rotateimage.h"
#include "./SourseLib/BMP_Process.h"
#include "mainwindow.h"

int rotate_angle_int=0;
int xdata_int=0;
int ydata_int=0;
extern BMP_Process Process;
extern QString FilePath,FilePath_Out;
extern string sFilePath,sFilePath_Out;

rotateimage::rotateimage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rotateimage)
{
    ui->setupUi(this);
    setWindowTitle("设置缩小系数"); //设置窗口标题
    setFixedSize(400,225);

    QString filename = ":/Picture/mclaren senna wallpaper.jpg"; //设置背景
    QPixmap pixmap(filename);//创建照片
    QSize windowsSize = this->size(); // 获取当前窗口大小
    QPixmap scalePixmap = pixmap.scaled(windowsSize,Qt::KeepAspectRatio,Qt::SmoothTransformation); //讲图片所放到当前窗口的大小
    QPalette palette = this->palette();   //创建pattle对象并设置背景照片 调色板
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));

    this->setPalette(palette);   //将调色板应用到windows

    connect(ui->horizontalSlider_xdata,SIGNAL(valueChanged(int)),ui->spinBox_xdata,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算
    connect(ui->spinBox_xdata,SIGNAL(valueChanged(int)),ui->horizontalSlider_xdata,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算

    connect(ui->verticalSlider_ydata,SIGNAL(valueChanged(int)),ui->spinBox_ydata,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算
    connect(ui->spinBox_ydata,SIGNAL(valueChanged(int)),ui->verticalSlider_ydata,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算

    connect(ui->dial_angledata,SIGNAL(valueChanged(int)),ui->spinBox_angledata,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算
    connect(ui->spinBox_angledata,SIGNAL(valueChanged(int)),ui->dial_angledata,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算

    connect(ui->confirmbutton,&QPushButton::clicked,this,&rotateimage::Button_rotateImage);//按钮链接槽函数 进行缩小图片的计算

    m_parent = static_cast<MainWindow*>(parent);
}


void rotateimage::Button_rotateImage(){
    rotate_angle_int = ui->dial_angledata->value();
    double rotate_angle=rotate_angle_int*1.0;
    xdata_int = ui->verticalSlider_ydata->value();
    ydata_int = ui->horizontalSlider_xdata->value();
    Process.rotateImage(sFilePath, sFilePath_Out, rotate_angle, xdata_int,ydata_int);
    m_parent->reflash_PicShow();
}

rotateimage::~rotateimage()
{
    delete ui;
}
