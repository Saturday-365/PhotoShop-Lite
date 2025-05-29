#include <conio.h>
#include <cstring>
#include <fstream>
// #include <iomanip>
#include "BMP_Process.h"
#include <QString>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>


// #define M_PI 3.1415926; // 定义圆周率常量

string BMP_Process::convertPath(const string &path) {
  stringstream result;
  for (char c : path) {
    if (c == '/') {
      result << "\\\\";
    } else {
      result << c;
    }
  }
  return result.str();
}

void BMP_Process::readBMPInfo(string name, uint32 &width, uint32 &height,
                              uint32 &data_offset, uint32 &data_size,
                              uint8 *&data) {
  fstream bmpdata;
  bmpdata.open(name, ios::binary | ios::in); // 以二进制只读模式打开文件
  if (bmpdata.fail()) {                      // 检查文件是否打开失败
    // cout << "原始图像读取失败";
    exit(5); // 若失败则退出程序
  }
  bmpdata.seekg(18, ios::beg);
  bmpdata.read((char *)(&width), sizeof(width));
  bmpdata.seekg(22, ios::beg);
  bmpdata.read((char *)(&height), sizeof(height));
  bmpdata.seekg(10, ios::beg);
  bmpdata.read((char *)(&data_offset), sizeof(data_offset));
  bmpdata.seekg(34, ios::beg);
  bmpdata.read((char *)(&data_size), sizeof(data_size));
  data = new uint8[data_size];
  bmpdata.seekg(data_offset, ios::beg);
  bmpdata.read((char *)data, data_size);
  bmpdata.close(); // 关闭文件
}

// 写入BMP图像信息的函数
void BMP_Process::writeBMPInfo(string new_name, uint32 width, uint32 height,
                               uint32 data_offset, uint32 data_size,
                               uint8 *data, string old_name) {
  fstream bmpw;
  bmpw.open(new_name, ios::binary | ios::out); // 以二进制写模式打开文件
  if (bmpw.fail()) {                           // 检查文件是否打开失败
    // cout << "新图像写入失败";
    exit(4); // 若失败则退出程序
  }
  fstream bmpdata;
  bmpdata.open(old_name, ios::binary | ios::in);
  uint8 *tmp = new uint8[data_offset];
  bmpdata.seekg(0, ios::beg);
  bmpdata.read((char *)tmp, data_offset);
  bmpw.write((char *)tmp, data_offset);
  delete[] tmp;    // 释放临时内存
  bmpdata.close(); // 关闭原始文件
  bmpw.seekp(18, ios::beg);
  bmpw.write((char *)(&width), sizeof(width));
  bmpw.seekp(22, ios::beg);
  bmpw.write((char *)(&height), sizeof(height));
  bmpw.seekp(34, ios::beg);
  bmpw.write((char *)(&data_size), sizeof(data_size));
  bmpw.seekp(data_offset, ios::beg);
  bmpw.write((char *)data, data_size);
  bmpw.close();
}

// 中值滤波
void BMP_Process::medianFilter(string name, string new_name) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;

  readBMPInfo(name, width, height, data_offset, data_size, data);

  uint32 num_width = data_size / height;
  uint8 *new_data = new uint8[data_size];
  memcpy(new_data, data, data_size);
  const int FILTER_SIZE = 25;
  uint8 values[FILTER_SIZE]; // 5x5邻域
  for (int i = 2; i < height - 2; i++) {
    for (int j = 2; j < width - 2; j++) {
      for (int c = 0; c < 3; c++) {
        // 收集邻域像素值到数组
        int index = 0;
        for (int x = -2; x <= 2; x++) {
          for (int y = -2; y <= 2; y++) {
            values[index++] = *(data + (i + x) * num_width + (j + y) * 3 + c);
          }
        }
        // 使用冒泡排序
        for (int pass = 0; pass < FILTER_SIZE - 1; pass++) {
          for (int k = 0; k < FILTER_SIZE - pass - 1; k++) {
            if (values[k] > values[k + 1]) {
              uint8 temp = values[k];
              values[k] = values[k + 1];
              values[k + 1] = temp;
            }
          }
        }
        // 对应像素位取中值
        *(new_data + i * num_width + j * 3 + c) = values[12];
      }
    }
  }
  writeBMPInfo(new_name, width, height, data_offset, data_size, new_data, name);
  delete[] data;
  delete[] new_data;
}

// 图像缩小函数
void BMP_Process::shrinkImage(string name, string new_name, double ratio) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  // 计算缩小后的图像大小
  uint32 new_width = static_cast<uint32>(width * ratio);
  uint32 new_height = static_cast<uint32>(height * ratio);

  uint32 num_width = data_size / height; // 计算原始图像每行数据的字节数

  uint32 new_num_width =
      4 * ceil(new_width * 3.0 /
               4); // 计算缩小后图像每行数据的字节数（按4字节对齐）

  uint32 new_data_size = new_num_width * new_height; // 计算缩小后图像的数据大小
  // 动态分配内存用于存储缩小后的图像数据
  uint8 *new_data = new uint8[new_data_size];
  memset(new_data, 0, new_data_size);

  // 遍历缩小后图像的每个像素
  for (int i = 0; i < new_height; i++) {
    for (int j = 0; j < new_width; j++) {
      // 计算原图像的像素坐标
      int src_i = (int)(i / ratio);
      int src_j = (int)(j / ratio);
      // 遍历每个像素的三个通道
      for (int c = 0; c < 3; c++) {
        // 将原始图像对应像素的颜色值赋给缩小后图像的对应像素
        *(new_data + i * new_num_width + j * 3 + c) =
            *(data + src_i * num_width + src_j * 3 + c);
      }
    }
  }
  writeBMPInfo(new_name, new_width, new_height, data_offset, new_data_size,
               new_data, name);
  delete[] data;
  delete[] new_data;
}

// 图像旋转
void BMP_Process::rotateImage(string name, string new_name, double angle,
                              int center_x, int center_y) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  // 计算好角度值
  double rad = angle / 180.0 * M_PI;
  double cos_angle = cos(rad);
  double sin_angle = sin(rad);

  // 计算原始图像每行数据的字节数
  uint32 num_width = data_size / height;
  // 动态分配内存用于存储旋转后的图像数据
  uint8 *new_data = new uint8[data_size];
  memset(new_data, 0, data_size);

  // 遍历图像的每个像素
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // 计算新像素相对于旋转中心的坐标
      int new_x = j - center_x;
      int new_y = i - center_y;

      // 旋转公式计算原图像中的坐标
      int old_x = (int)(new_x * cos_angle - new_y * sin_angle) + center_x;
      int old_y = (int)(new_x * sin_angle + new_y * cos_angle) + center_y;

      // 边界检查
      if (old_x >= 0 && old_x < width && old_y >= 0 && old_y < height) {
        for (int c = 0; c < 3; c++) {
          *(new_data + i * num_width + j * 3 + c) =
              *(data + old_y * num_width + old_x * 3 + c);
        }
      }
    }
  }

  writeBMPInfo(new_name, width, height, data_offset, data_size, new_data, name);
  delete[] data;
  delete[] new_data;
}

// medianFilter(bmp_name1, bmp_name2);
// shrinkImage(bmp_name1, bmp_name2, ratio);
// rotateImage(bmp_name1, bmp_name2, angle, center_x, center_y);
