#include <algorithm>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

typedef unsigned char uint8;   // 一个字节
typedef unsigned short uint16; // 两个字节
typedef unsigned long uint32;  // 四个字节
#define M_PI 3.1415926;
// 读取BMP图像信息
void readBMPInfo(const char *name, uint32 &width, uint32 &height,
                 uint32 &data_offset, uint32 &data_size, uint8 *&data) {
  fstream bmpr;
  bmpr.open(name, ios::binary | ios::in); // 读取文件模式为二进制 只读
  if (bmpr.fail()) {                      // 终止程序
    cout << "原始图像读取失败";
    exit(1);
  }

  // 读取原始图像的宽度（像素数）
  bmpr.seekg(18, ios::beg);
  bmpr.read((char *)(&width), sizeof(width));

  // 读取原始图像的高度（像素数）
  bmpr.seekg(22, ios::beg);
  bmpr.read((char *)(&height), sizeof(height));

  // 读取原始图像的数据偏移量
  bmpr.seekg(10, ios::beg);
  bmpr.read((char *)(&data_offset), sizeof(data_offset));

  // 读取原始图像的数据大小
  bmpr.seekg(34, ios::beg);
  bmpr.read((char *)(&data_size), sizeof(data_size));

  // 读取原始图像的数据内容
  data = new uint8[data_size];
  bmpr.seekg(data_offset, ios::beg);
  bmpr.read((char *)data, data_size);

  bmpr.close();
}

// 写入BMP图像信息
void writeBMPInfo(const char *new_name, uint32 width, uint32 height,
                  uint32 data_offset, uint32 data_size, uint8 *data,
                  const char *old_name) {
  fstream bmpw;
  bmpw.open(new_name, ios::binary | ios::out);
  if (bmpw.fail()) {
    cout << "新图像写入失败";
    exit(1); // 终止程序
  }

  // 复制原始图像的文件头和信息头
  fstream bmpr;
  bmpr.open(old_name, ios::binary | ios::in);
  uint8 *tmp = new uint8[data_offset];
  bmpr.seekg(0, ios::beg);
  bmpr.read((char *)tmp, data_offset);
  bmpw.write((char *)tmp, data_offset);
  delete[] tmp;
  bmpr.close();

  // 写入新图像的宽度（像素数）
  bmpw.seekp(18, ios::beg);
  bmpw.write((char *)(&width), sizeof(width));

  // 写入新图像的高度（像素数）
  bmpw.seekp(22, ios::beg);
  bmpw.write((char *)(&height), sizeof(height));

  // 写入新图像的数据大小
  bmpw.seekp(34, ios::beg);
  bmpw.write((char *)(&data_size), sizeof(data_size));

  // 写入新图像的数据内容
  bmpw.seekp(data_offset, ios::beg);
  bmpw.write((char *)data, data_size);

  bmpw.close();
}

// 中值滤波
void medianFilter(const char *name, const char *new_name) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  uint32 num_width = data_size / height;
  uint8 *new_data = new uint8[data_size];
  memcpy(new_data, data, data_size);

  for (int i = 2; i < height - 2; i++) {
    for (int j = 2; j < width - 2; j++) {
      for (int c = 0; c < 3; c++) {
        vector<uint8> values;
        for (int x = -2; x <= 2; x++) {
          for (int y = -2; y <= 2; y++) {
            values.push_back(*(data + (i + x) * num_width + (j + y) * 3 + c));
          }
        }
        sort(values.begin(), values.end());
        *(new_data + i * num_width + j * 3 + c) = values[12];
      }
    }
  }

  writeBMPInfo(new_name, width, height, data_offset, data_size, new_data, name);
  delete[] data;
  delete[] new_data;
}

// 图像缩小
void shrinkImage(const char *name, const char *new_name, double ratio) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  uint32 new_width = static_cast<uint32>(width * ratio);
  uint32 new_height = static_cast<uint32>(height * ratio);
  uint32 num_width = data_size / height;
  uint32 new_num_width = 4 * ceil(new_width * 3.0 / 4);
  uint32 new_data_size = new_num_width * new_height;
  uint8 *new_data = new uint8[new_data_size];
  memset(new_data, 0, new_data_size);

  for (int i = 0; i < new_height; i++) {
    for (int j = 0; j < new_width; j++) {
      int src_i = static_cast<int>(i / ratio);
      int src_j = static_cast<int>(j / ratio);
      for (int c = 0; c < 3; c++) {
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
void rotateImage(const char *name, const char *new_name, double angle,
                 int center_x, int center_y) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  double rad = angle / 180.0 * M_PI;
  double cos_angle = cos(rad);
  double sin_angle = sin(rad);

  uint32 new_width =
      static_cast<uint32>(width * fabs(cos_angle) + height * fabs(sin_angle));
  uint32 new_height =
      static_cast<uint32>(width * fabs(sin_angle) + height * fabs(cos_angle));
  uint32 num_width = data_size / height;
  uint32 new_num_width = 4 * ceil(new_width * 3.0 / 4);
  uint32 new_data_size = new_num_width * new_height;
  uint8 *new_data = new uint8[new_data_size];
  memset(new_data, 0, new_data_size);

  for (int i = 0; i < new_height; i++) {
    for (int j = 0; j < new_width; j++) {
      int new_x = j - center_x;
      int new_y = i - center_y;
      int old_x =
          static_cast<int>(new_x * cos_angle - new_y * sin_angle) + center_x;
      int old_y =
          static_cast<int>(new_x * sin_angle + new_y * cos_angle) + center_y;

      if (old_x >= 0 && old_x < width && old_y >= 0 && old_y < height) {
        for (int c = 0; c < 3; c++) {
          *(new_data + i * new_num_width + j * 3 + c) =
              *(data + old_y * num_width + old_x * 3 + c);
        }
      }
    }
  }

  writeBMPInfo(new_name, new_width, new_height, data_offset, new_data_size,
               new_data, name);
  delete[] data;
  delete[] new_data;
}

// 显示主菜单
void mainMenu() {
  const int menuWidth = 30; // 主菜单边框宽度
  const string menuItems[] = {"中值滤波", "图像缩小", "图像旋转", "退出程序"};
  const int numItems =
      sizeof(menuItems) / sizeof(menuItems[0]); // 得到菜单项数量
  int selected = 0;                             // 当前选中的菜单项

  char bmp_name1[50] = "hqu.bmp";
  char bmp_name2[50] = "new.bmp";

  while (true) {
    system("cls");

    // 绘制顶部边框
    cout << "+";
    for (int i = 0; i < menuWidth; i++)
      cout << "-";
    cout << "+" << endl;

    // 显示标题
    string title = "主菜单";
    int titlePadding = (menuWidth - title.length()) / 2; // 得到输出位置
    cout << "|";
    cout << setw(titlePadding) << ""
         << title // 输出字符串占一行 左右两边都有 * 例如|************主菜单 |
         << setw(menuWidth - title.length() - titlePadding)
         << ""; // 输出剩余空格补齐
    cout << "|" << endl;

    // 绘制分隔线
    cout << "|";
    for (int i = 0; i < menuWidth; i++)
      cout << "-";
    cout << "|" << endl;

    // 显示所有菜单项，并标记选中项
    for (int i = 0; i < numItems; i++) {
      int padding = (menuWidth - menuItems[i].length()) / 2;
      cout << "|";
      if (i == selected) {
        cout << setw(padding - 3) << "" << "-->" << menuItems[i] << "<--"
             << setw(menuWidth - menuItems[i].length() - 3 - padding) << "";
      } else {
        cout << " " << setw(padding - 1) << "" << menuItems[i]
             << setw(menuWidth - menuItems[i].length() - padding) << "";
      }
      cout << "|" << endl;
    }

    // 绘制底部边框
    cout << "+";
    for (int i = 0; i < menuWidth; i++)
      cout << "-";
    cout << "+" << endl;

    char d = getch();
    switch (d) {
    case 'w':
      selected = (selected - 1 + numItems) % numItems;
      break;
    case 's':
      selected = (selected + 1) % numItems;
      break;
    case '\r': // 回车键确认选择
      switch (selected) {
      case 0:
        medianFilter(bmp_name1, bmp_name2);
        cout << "中值滤波完成，新图像已保存为 " << bmp_name2 << endl;
        getch();
        break;
      case 1: {
        double ratio;
        cout << "请输入缩小比例（例如 0.5）: ";
        cin >> ratio;
        shrinkImage(bmp_name1, bmp_name2, ratio);
        cout << "图像缩小完成，新图像已保存为 " << bmp_name2 << endl;
        getch();
        break;
      }
      case 2: {
        double angle;
        int center_x, center_y;
        cout << "请输入旋转角度（例如 45）: ";
        cin >> angle;
        cout << "请输入旋转中心点的x坐标: ";
        cin >> center_x;
        cout << "请输入旋转中心点的y坐标: ";
        cin >> center_y;
        rotateImage(bmp_name1, bmp_name2, angle, center_x, center_y);
        cout << "图像旋转完成，新图像已保存为 " << bmp_name2 << endl;
        getch();
        break;
      }
      case 3:
        return;
      }
      break;
    }
  }
}

int main() {
  mainMenu();
  return 0;
}