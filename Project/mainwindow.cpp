#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>
#include <QTimer>
#include <QPixmap>
#include <QPalette>
#include <QWidget>
#include <QMouseEvent>
#include <QPointerEvent>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>
#include "./SourseLib/BMP_Process.h"
#include <QThread>

#define MARGIN 2

QString FilePath,FilePath_Out;
string sFilePath,sFilePath_Out;
BMP_Process Process;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // setWindowFlags(Qt::FramelessWindowHint|Qt::WindowCloseButtonHint|Qt::WindowMinMaxButtonsHint);
    // setWindowFlag(Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::FramelessWindowHint);         //无边框
    setAttribute(Qt::WA_TranslucentBackground);     //窗口透明

    //直接初始化不起作用，需要定时器延时初始化
    QTimer *t = new QTimer(this);
    connect(t, &QTimer::timeout, this, [=](){Init();});
    t->setSingleShot(true);
    t->start(10);

    QPixmap pixmapAPPpix(":/Icon/image 1760.png");  //设置左上角图标
    //QPixmap pixmapclosepix(":/Icon/close.png");  //设置左上角图标
    if(!pixmapAPPpix.isNull()){
        ui->APPpixLable->clear();
        //QSize lableSize = pixmapAPPpix.size(); //设置大小为图片大小
         QSize lableSize = ui->APPpixLable->size();//设置大小为图标大小
        ui->APPpixLable->setPixmap(pixmapAPPpix.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
        ui->APPpixLable->setAlignment(Qt::AlignCenter);//图片居中这个lable
    }

    QPixmap pixmapdatalableground(":/Icon/blue120x100.png");  //设置图片显示位置背景浅蓝色
    if(!pixmapdatalableground.isNull()){
        ui->textlabel->clear();
        QSize lableSize = pixmapdatalableground.size(); //设置大小为图片大小
        //QSize lableSize = ui->textlabel->size();//设置大小为图标大小
        ui->textlabel->setPixmap(pixmapdatalableground.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
        ui->textlabel->setAlignment(Qt::AlignCenter);//图片居中这个lable
    }

    QPixmap pixmaptextlableground(":/Icon/blue690x100.png");  //设置图片显示位置背景浅蓝色
    if(!pixmaptextlableground.isNull()){
        ui->datalable->clear();
        QSize lableSize = pixmaptextlableground.size(); //设置大小为图片大小
        //QSize lableSize = ui->datalable->size();//设置大小为图标大小
        ui->datalable->setPixmap(pixmaptextlableground.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
        // ui->datalable->setAlignment(Qt::AlignCenter);//图片居中这个lable
    }

    QPixmap pixmapbackground(":/Icon/things.png");  //设置图片显示位置背景浅蓝色
    if(!pixmapbackground.isNull()){
        ui->backgroundlabel->clear();
        //QSize lableSize = pixmapbackground.size(); //设置大小为图片大小
        QSize lableSize = ui->backgroundlabel->size();//设置大小为图标大小
        ui->backgroundlabel->setPixmap(pixmapbackground.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
        ui->backgroundlabel->setAlignment(Qt::AlignCenter);//图片居中这个lable
    }
    // QPixmap pixmapbarbackground(":/Icon/barbackground.png");  //顶部bar透明黑色背景
    // if(!pixmapbackground.isNull()){
    //     ui->label->clear();
    //     //QSize lableSize = pixmapbarbackground.size(); //设置大小为图片大小
    //     QSize lableSize = ui->label->size();//设置大小为图标大小
    //     ui->label->setPixmap(pixmapbarbackground.scaled(lableSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
    //     ui->label->setAlignment(Qt::AlignCenter);//图片居中这个lable
    // }
    // setWindowTitle("PhotoShop Lite"); //设置窗口标题
    // setFixedSize(960,540);
    //setBackGround(":/Picture/mclaren senna wallpaper.jpg"); //设置背景
    initButtons();
    connect(ui->mode1Btn,&QPushButton::clicked,this,&MainWindow::Button_OpenFile);//按钮链接槽函数 打开图片文件
    connect(ui->mode2Btn,&QPushButton::clicked,this,&MainWindow::Button_medianFilter);//按钮链接槽函数 实现中值滤波并重新显示新的图片

}

void MainWindow::Init()
{
    const int cornerRadius = 20;                    //窗口倒角弧度
    QColor mainBackGround = QColor(247, 248, 251);  //背景色，默认白色
    //绘制遮罩
    QPainterPath path;
    path.addRoundedRect(ui->mainWidget->rect(),cornerRadius-1,cornerRadius-1);
    QRegion mask(path.toFillPolygon().toPolygon());
    ui->mainWidget->setMask(mask);
    //设置主界面样式
    QString mainStyle("QWidget#mainWidget{background-color:"
                      + mainBackGround.name()
                      + QString::asprintf(";border-radius:%dpx", cornerRadius)
                      + "}");
    ui->mainWidget->setStyleSheet(mainStyle);
    // //设置投影效果
    QGraphicsDropShadowEffect *windowShadow;        //阴影效果
    windowShadow = new QGraphicsDropShadowEffect(this);
    windowShadow->setBlurRadius(5);
    windowShadow->setColor(QColor(100, 100, 100));
    windowShadow->setOffset(5, 5);

    ui->centralwidget->setGraphicsEffect(windowShadow);
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

void MainWindow::setbarButtonStyle(QPushButton * button , const QString & filename)
{
    button->setFixedSize(30,30);//设置按钮大小
    button->setIcon(QIcon(filename));//设置按钮图标
    button->setIconSize(QSize(button->width(),button->height()));//设置按钮图标大小
    button->setStyleSheet("background-color:transparent");
}
void MainWindow::initButtons()
{
    setButtonStyle(ui->mode1Btn, ":/Icon/choosebtn.png");
    setButtonStyle(ui->mode2Btn, ":/Icon/flitbtn.png");
    setButtonStyle(ui->mode3Btn, ":/Icon/shrinkbtn.png");
    setButtonStyle(ui->mode4Btn, ":/Icon/rottbtn.png");
    setbarButtonStyle(ui->maxBtn, ":/Icon/maxbtn.png");
    setbarButtonStyle(ui->minBtn, ":/Icon/minbtn.png");
    setbarButtonStyle(ui->closeBtn, ":/Icon/close.png");

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

    QPixmap pixmapbackground(":/Icon/background.png");  //设置图片显示位置背景浅蓝色
    if(!pixmapbackground.isNull()){
        ui->backgroundlabel->clear();
        //QSize lableSize = pixmapbackground.size(); //设置大小为图片大小
        QSize lableSize = ui->backgroundlabel->size();//设置大小为图标大小
        ui->backgroundlabel->setPixmap(pixmapbackground.scaled(lableSize,Qt::KeepAspectRatio,Qt::SmoothTransformation));  //将图片按照原来的宽高比进行缩放到指定lable的大小
        ui->backgroundlabel->setAlignment(Qt::AlignCenter);//图片居中这个lable
    }

    FilePath=QFileDialog::getOpenFileName(this,"OpenPicture-File 打开你想要转换的BMP格式文件(不能包含中文路径)",":/Picture","BMP-img(*.bmp)");
    sFilePath = FilePath.toStdString();
    sFilePath=Process.convertPath(sFilePath);   //转化路径格式为io流可以读取的格式 /*  "/"->"\\" */
    //ui->Pic_filepath_textEdit->insertPlainText(FilePath);// 显示打开的图片的路径
    ui->filepath_label->setText(FilePath);
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
    ui->stagelabel->clear();
    ui->stagelabel->setText("Waitting");
    ui->stagelabel->setAlignment(Qt::AlignCenter);//居中这个lable
    // QThread::msleep(2000);//阻塞延时50ms
    Process.medianFilter(sFilePath,sFilePath_Out);//执行bmp处理函数
    ui->stagelabel->setText("Finish");
    reflash_PicShow();

}

void MainWindow::on_mode3Btn_clicked()
{
    shrinkWindow = new Shrinkmage(this);
    shrinkWindow->setWindowFlags(shrinkWindow->windowFlags() | Qt::Window);//在子窗口的构造函数或者显示之前，明确设置Qt::Window标志：
    shrinkWindow->show();


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



void MainWindow::on_mode4Btn_clicked()
{
    rotateWindow = new rotateimage(this);
    rotateWindow->setWindowFlags(rotateWindow->windowFlags() | Qt::Window);//在子窗口的构造函数或者显示之前，明确设置Qt::Window标志：
    rotateWindow->show();

}


//最小化界面
void MainWindow::on_minBtn_clicked()
{
    this->showMinimized();
}

//关闭界面
void MainWindow::on_closeBtn_clicked()
{
    this->close();
}

//放大，缩小界面
void MainWindow::on_maxBtn_clicked()
{
    // static bool max = false;
    // static QRect location = this->geometry();
    // if (max) {
    //     this->setGeometry(location);//回复窗口原大小和位置
    //     ui->maxBtn->setIcon(QIcon(":/MAX_.png"));
    // }else {
    //     ui->maxBtn->setIcon(QIcon(":/minMAX.png"));
    //     location = this->geometry();	//最大化前记录窗口大小和位置
    //     //this->setGeometry(qApp->desktop()->availableGeometry());
    //     this->showFullScreen();	//设置窗口铺满全屏
    // }
    // max = !max;
}


//鼠标按下事件
/*
 *作用：
 *1.判断是否时左键点击 _isleftpressed
 *2.获取光标在屏幕中的位置 _plast
 *3.左键按下时光标所在区域 _curpos
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
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
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (_isleftpressed)
        _isleftpressed = false;
    setCursor(Qt::ArrowCursor);
}

//鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event)
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
int MainWindow::countFlag(QPoint p,int row)//计算鼠标在哪一列和哪一行
{
    if(p.y()<MARGIN)
        return 10+row;
    else if(p.y()>this->height()-MARGIN)
        return 30+row;
    else
        return 20+row;
}

//获取光标在窗口所在区域的 行   返回行数
int MainWindow::countRow(QPoint p)
{
    return (p.x()<MARGIN) ? 1 : (p.x()>(this->width() - MARGIN) ? 3 : 2);
}

//根据鼠标所在位置改变鼠标指针形状
void MainWindow::setCursorType(int flag)
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
