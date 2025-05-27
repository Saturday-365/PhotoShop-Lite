// #ifndef BMP_PROCESS_H
// #define BMP_PROCESS_H
// #include <QString>
// #include <iostream>
// #include <fstream>
// #include <cstring>
// #include <math.h>
// #include <algorithm>
// #include <conio.h>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <QMainWindow>
// #include <QString>
// #include <QPushButton>
// #include <QFileDialog>
// #include <QComboBox>
// #include <QImage>
// #include <qlabel.h>

// typedef unsigned char uint8;      // 一个字节
// typedef unsigned short uint16;    // 两个字节
// typedef unsigned long uint32;     // 四个字节

// class BMP_PROCESS : public BMP_PROCESS
// {
//     Q_OBJECT
// public:

//     // 读取BMP图像信息
//     void readBMPInfo(string filePath,  uint32 &width, uint32 &height, uint32 &data_offset, uint32 &data_size, uint8 *&data) ;

//     // 写入BMP图像信息
//     void writeBMPInfo(const char *new_name, uint32 width, uint32 height, uint32 data_offset, uint32 data_size, uint8 *data, const char *old_name);

//     // 中值滤波
//     void medianFilter(const char *name, const char *new_name);

//     // 图像缩小
//     void shrinkImage(const char *name, const char *new_name, double ratio);

//     // 图像旋转
//     void rotateImage(const char *name, const char *new_name, double angle, int center_x, int center_y);
// };
// #endif
