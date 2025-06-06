#include "shrinkmage.h"
#include "ui_shrinkmage.h"
#include "./SourseLib/BMP_Process.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
double shrink_xfactor=0;
int shrink_xfactor_int=10;
double shrink_yfactor=0;
int shrink_yfactor_int=10;
extern BMP_Process Process;
extern QString FilePath,FilePath_Out;
extern string sFilePath,sFilePath_Out;
#define MARGIN 2

Shrinkmage::Shrinkmage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Shrinkmage)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    setWindowTitle("设置缩小系数"); //设置窗口标题
    setFixedSize(400,225);
    setWindowFlag(Qt::FramelessWindowHint);         //无边框

    // QString filename = ":/Picture/mclaren senna wallpaper.jpg"; //设置背景
    // QPixmap pixmap(filename);//创建照片
    // QSize windowsSize = this->size(); // 获取当前窗口大小
    // QPixmap scalePixmap = pixmap.scaled(windowsSize,Qt::KeepAspectRatio,Qt::SmoothTransformation); //讲图片所放到当前窗口的大小
    // QPalette palette = this->palette();   //创建pattle对象并设置背景照片 调色板
    // palette.setBrush(QPalette::Window,QBrush(scalePixmap));

    // this->setPalette(palette);   //将调色板应用到windows
    setWindowFlag(Qt::FramelessWindowHint);         //无边框
    setAttribute(Qt::WA_TranslucentBackground);     //窗口透明

    //设置投影效果
    // QGraphicsDropShadowEffect *windowShadow;        //阴影效果
    // windowShadow = new QGraphicsDropShadowEffect(this);
    // windowShadow->setBlurRadius(5);
    // windowShadow->setColor(QColor(100, 100, 100));
    // windowShadow->setOffset(5, 5);
    // ui->frame->setGraphicsEffect(windowShadow);

    ui->closebtn->setFixedSize(30,30);//设置按钮大小
    ui->closebtn->setIcon(QIcon(":/Icon/close111.png"));//设置按钮图标
    ui->closebtn->setIconSize(QSize(ui->closebtn->width(),ui->closebtn->height()));//设置按钮图标大小
    ui->closebtn->setStyleSheet("background-color:transparent");

    ui->ConfirmButton->setFixedSize(77,30);//设置按钮大小
    ui->ConfirmButton->setIcon(QIcon(":/Icon/confirmbtnicon.png"));//设置按钮图标
    ui->ConfirmButton->setIconSize(QSize(ui->ConfirmButton->width(),ui->ConfirmButton->height()));//设置按钮图标大小
    ui->ConfirmButton->setStyleSheet("background-color:transparent");

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


void Shrinkmage::on_closebtn_clicked()
{
    this->close();
}


//鼠标按下事件
/*
 *作用：
 *1.判断是否时左键点击 _isleftpressed
 *2.获取光标在屏幕中的位置 _plast
 *3.左键按下时光标所在区域 _curpos
 */
void Shrinkmage::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (event->button() == Qt::LeftButton)
    {
        this->_isleftpressed = true;
        QPoint temp = event->globalPos();
        _plast = temp;
        _curpos = countFlag(event->pos(), countRow(event->pos()));
    }
}

//鼠标释放事件
/*
 *作用：
 *1.将_isleftpressed 设为false
 *2.将光标样式恢复原样式  setCursor(Qt::ArrowCursor);
 */
void Shrinkmage::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (_isleftpressed)
        _isleftpressed = false;
    setCursor(Qt::ArrowCursor);
}

//鼠标移动事件
void Shrinkmage::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(this->isFullScreen()) return;	//窗口铺满全屏，直接返回，不做任何操作
    int poss = countFlag(event->pos(), countRow(event->pos()));
    setCursorType(poss);
    if (_isleftpressed)//是否左击
    {
        QPoint ptemp = event->globalPos();
        ptemp = ptemp - _plast;
        if (_curpos == 22)//移动窗口
        {
            ptemp = ptemp + pos();
            move(ptemp);
        }
        else
        {
            QRect wid = geometry();
            switch (_curpos)//改变窗口的大小
            {
            case 11:wid.setTopLeft(wid.topLeft() + ptemp); break;//左上角
            case 13:wid.setTopRight(wid.topRight() + ptemp); break;//右上角
            case 31:wid.setBottomLeft(wid.bottomLeft() + ptemp); break;//左下角
            case 33:wid.setBottomRight(wid.bottomRight() + ptemp); break;//右下角
            case 12:wid.setTop(wid.top() + ptemp.y()); break;//中上角
            case 21:wid.setLeft(wid.left() + ptemp.x()); break;//中左角
            case 23:wid.setRight(wid.right() + ptemp.x()); break;//中右角
            case 32:wid.setBottom(wid.bottom() + ptemp.y()); break;//中下角
            }
            setGeometry(wid);
        }
        _plast = event->globalPos();//更新位置
    }
}

//获取光标在窗口所在区域的 列  返回行列坐标
int Shrinkmage::countFlag(QPoint p,int row)//计算鼠标在哪一列和哪一行
{
    if(p.y()<MARGIN)
        return 10+row;
    else if(p.y()>this->height()-MARGIN)
        return 30+row;
    else
        return 20+row;
}

//获取光标在窗口所在区域的 行   返回行数
int Shrinkmage::countRow(QPoint p)
{
    return (p.x()<MARGIN) ? 1 : (p.x()>(this->width() - MARGIN) ? 3 : 2);
}

//根据鼠标所在位置改变鼠标指针形状
void Shrinkmage::setCursorType(int flag)
{
    switch(flag)
    {
    case 11:
    case 33:
        setCursor(Qt::SizeFDiagCursor);
        break;
    case 13:
    case 31:
        setCursor(Qt::SizeBDiagCursor);break;
    case 21:
    case 23:
        setCursor(Qt::SizeHorCursor);break;
    case 12:
    case 32:
        setCursor(Qt::SizeVerCursor);break;
    case 22:
        setCursor(Qt::ArrowCursor);
        QApplication::restoreOverrideCursor();//恢复鼠标指针性状
        break;
    }
}


