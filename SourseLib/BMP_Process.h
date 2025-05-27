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

// typedef unsigned char uint8;      // һ���ֽ�
// typedef unsigned short uint16;    // �����ֽ�
// typedef unsigned long uint32;     // �ĸ��ֽ�

// class BMP_PROCESS : public BMP_PROCESS
// {
//     Q_OBJECT
// public:

//     // ��ȡBMPͼ����Ϣ
//     void readBMPInfo(string filePath,  uint32 &width, uint32 &height, uint32 &data_offset, uint32 &data_size, uint8 *&data) ;

//     // д��BMPͼ����Ϣ
//     void writeBMPInfo(const char *new_name, uint32 width, uint32 height, uint32 data_offset, uint32 data_size, uint8 *data, const char *old_name);

//     // ��ֵ�˲�
//     void medianFilter(const char *name, const char *new_name);

//     // ͼ����С
//     void shrinkImage(const char *name, const char *new_name, double ratio);

//     // ͼ����ת
//     void rotateImage(const char *name, const char *new_name, double angle, int center_x, int center_y);
// };
// #endif
