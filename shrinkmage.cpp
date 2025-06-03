#include "shrinkmage.h"
#include "ui_shrinkmage.h"
#include "./SourseLib/BMP_Process.h"
#include "mainwindow.h"
double shrink_xfactor=0;
int shrink_xfactor_int=10;
double shrink_yfactor=0;
int shrink_yfactor_int=10;
extern BMP_Process Process;
extern QString FilePath,FilePath_Out;
extern string sFilePath,sFilePath_Out;

Shrinkmage::Shrinkmage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Shrinkmage)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    setWindowTitle("设置缩小系数"); //设置窗口标题
    setFixedSize(400,225);

    QString filename = ":/Picture/mclaren senna wallpaper.jpg"; //设置背景
    QPixmap pixmap(filename);//创建照片
    QSize windowsSize = this->size(); // 获取当前窗口大小
    QPixmap scalePixmap = pixmap.scaled(windowsSize,Qt::KeepAspectRatio,Qt::SmoothTransformation); //讲图片所放到当前窗口的大小
    QPalette palette = this->palette();   //创建pattle对象并设置背景照片 调色板
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));

    this->setPalette(palette);   //将调色板应用到windows

    connect(ui->QSLShrinkxFactor,SIGNAL(valueChanged(int)),ui->QSPShrinkxFactor,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算
    connect(ui->QSPShrinkxFactor,SIGNAL(valueChanged(int)),ui->QSLShrinkxFactor,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算

    connect(ui->QSLShrinkyFactor,SIGNAL(valueChanged(int)),ui->QSPShrinkyFactor,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算
    connect(ui->QSPShrinkyFactor,SIGNAL(valueChanged(int)),ui->QSLShrinkyFactor,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算

    connect(ui->ConfirmButton,&QPushButton::clicked,this,&Shrinkmage::Button_shrinkImage);//按钮链接槽函数 进行缩小图片的计算

    m_parent = static_cast<MainWindow*>(parent);

}

void Shrinkmage::Button_shrinkImage(){
    shrink_xfactor_int = ui->QSPShrinkxFactor->value();
    shrink_xfactor=shrink_xfactor_int/100.0;
    // shrink_xfactor=0.5;
    shrink_yfactor_int = ui->QSPShrinkyFactor->value();
    shrink_yfactor=shrink_yfactor_int/100.0;
    // shrink_yfactor=0.5;
    //ui->FactorShow->setNum(shrink_factor_int);  //测试用
    Process.shrinkImage(sFilePath,sFilePath_Out,shrink_xfactor,shrink_yfactor);
    m_parent->reflash_PicShow();
}


Shrinkmage::~Shrinkmage()
{
    delete ui;
}
