#include "shrinkmage.h"
#include "ui_shrinkmage.h"
#include "./SourseLib/BMP_Process.h"
#include "mainwindow.h"
double shrink_factor=0;
int shrink_factor_int=10;
extern BMP_Process Process;
extern QString FilePath,FilePath_Out;
extern string sFilePath,sFilePath_Out;

Shrinkmage::Shrinkmage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Shrinkmage)
{
    ui->setupUi(this);
    m_parent = static_cast<MainWindow*>(parent);
    setWindowTitle("设置缩小系数"); //设置窗口标题
   // setFixedSize(200,150);
    QString filename = ":/Picture/mclaren senna wallpaper.jpg"; //设置背景
    QPixmap pixmap(filename);//创建照片
    QSize windowsSize = this->size(); // 获取当前窗口大小
    QPixmap scalePixmap = pixmap.scaled(windowsSize,Qt::KeepAspectRatio,Qt::SmoothTransformation); //讲图片所放到当前窗口的大小
    QPalette palette = this->palette();   //创建pattle对象并设置背景照片 调色板
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    this->setPalette(palette);   //将调色板应用到windows
    connect(ui->QSLShrinkFactor,SIGNAL(valueChanged(int)),ui->QSPShrinkFactor,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算
    connect(ui->QSPShrinkFactor,SIGNAL(valueChanged(int)),ui->QSLShrinkFactor,SLOT(setValue(int)));//按钮链接槽函数 进行缩小图片的计算
    connect(ui->ConfirmButton,&QPushButton::clicked,this,&Shrinkmage::Button_shrinkImage);//按钮链接槽函数 进行缩小图片的计算


}
void Shrinkmage::Button_shrinkImage(){
    shrink_factor_int = ui->QSPShrinkFactor->value();
    shrink_factor=shrink_factor_int/100.0;
    ui->FactorShow->setNum(shrink_factor_int);
    Process.shrinkImage(sFilePath,sFilePath_Out,shrink_factor);
    m_parent->reflash_PicShow();
}
void Shrinkmage::Button_rotateImage(){

}

Shrinkmage::~Shrinkmage()
{
    delete ui;
}
