#include <conio.h>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
#define M_PI 3.1415926; // ����Բ���ʳ���

void readBMPInfo(const char *name, uint32 &width, uint32 &height,
                 uint32 &data_offset, uint32 &data_size, uint8 *&data) {
  fstream bmpdata;

  bmpdata.open(name, ios::binary | ios::in); // �Զ�����ֻ��ģʽ���ļ�
  if (bmpdata.fail()) {                      // ����ļ��Ƿ��ʧ��
    cout << "ԭʼͼ���ȡʧ��";
    exit(1); // ��ʧ�����˳�����
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
  bmpdata.close(); // �ر��ļ�
}

// д��BMPͼ����Ϣ�ĺ���
void writeBMPInfo(const char *new_name, uint32 width, uint32 height,
                  uint32 data_offset, uint32 data_size, uint8 *data,
                  const char *old_name) {
  fstream bmpw;
  bmpw.open(new_name, ios::binary | ios::out); // �Զ�����дģʽ���ļ�
  if (bmpw.fail()) {                           // ����ļ��Ƿ��ʧ��
    cout << "��ͼ��д��ʧ��";
    exit(1); // ��ʧ�����˳�����
  }
  fstream bmpdata;
  bmpdata.open(old_name, ios::binary | ios::in);
  uint8 *tmp = new uint8[data_offset];
  bmpdata.seekg(0, ios::beg);
  bmpdata.read((char *)tmp, data_offset);
  bmpw.write((char *)tmp, data_offset);
  delete[] tmp;    // �ͷ���ʱ�ڴ�
  bmpdata.close(); // �ر�ԭʼ�ļ�
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

// ��ֵ�˲�
void medianFilter(const char *name, const char *new_name) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  uint32 num_width = data_size / height;
  uint8 *new_data = new uint8[data_size];
  memcpy(new_data, data, data_size);
  const int FILTER_SIZE = 25;
  uint8 values[FILTER_SIZE]; // 5x5����
  for (int i = 2; i < height - 2; i++) {
    for (int j = 2; j < width - 2; j++) {
      for (int c = 0; c < 3; c++) {
        // �ռ���������ֵ������
        int index = 0;
        for (int x = -2; x <= 2; x++) {
          for (int y = -2; y <= 2; y++) {
            values[index++] = *(data + (i + x) * num_width + (j + y) * 3 + c);
          }
        }
        // ʹ��ð������
        for (int pass = 0; pass < FILTER_SIZE - 1; pass++) {
          for (int k = 0; k < FILTER_SIZE - pass - 1; k++) {
            if (values[k] > values[k + 1]) {
              uint8 temp = values[k];
              values[k] = values[k + 1];
              values[k + 1] = temp;
            }
          }
        }
        // ��Ӧ����λȡ��ֵ
        *(new_data + i * num_width + j * 3 + c) = values[12];
      }
    }
  }
  writeBMPInfo(new_name, width, height, data_offset, data_size, new_data, name);
  delete[] data;
  delete[] new_data;
}

// ͼ����С����
void shrinkImage(const char *name, const char *new_name, double ratio) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  // ������С���ͼ���С
  uint32 new_width = static_cast<uint32>(width * ratio);
  uint32 new_height = static_cast<uint32>(height * ratio);

  uint32 num_width = data_size / height; // ����ԭʼͼ��ÿ�����ݵ��ֽ���

  uint32 new_num_width =
      4 * ceil(new_width * 3.0 /
               4); // ������С��ͼ��ÿ�����ݵ��ֽ�������4�ֽڶ��룩

  uint32 new_data_size = new_num_width * new_height; // ������С��ͼ������ݴ�С
  // ��̬�����ڴ����ڴ洢��С���ͼ������
  uint8 *new_data = new uint8[new_data_size];
  memset(new_data, 0, new_data_size);

  // ������С��ͼ���ÿ������
  for (int i = 0; i < new_height; i++) {
    for (int j = 0; j < new_width; j++) {
      // ����ԭͼ�����������
      int src_i = (int)(i / ratio);
      int src_j = (int)(j / ratio);
      // ����ÿ�����ص�����ͨ��
      for (int c = 0; c < 3; c++) {
        // ��ԭʼͼ���Ӧ���ص���ɫֵ������С��ͼ��Ķ�Ӧ����
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

// ͼ����ת
void rotateImage(const char *name, const char *new_name, double angle,
                 int center_x, int center_y) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  // ����ýǶ�ֵ
  double rad = angle / 180.0 * M_PI;
  double cos_angle = cos(rad);
  double sin_angle = sin(rad);

  // ����ԭʼͼ��ÿ�����ݵ��ֽ���
  uint32 num_width = data_size / height;
  // ��̬�����ڴ����ڴ洢��ת���ͼ������
  uint8 *new_data = new uint8[data_size];
  memset(new_data, 0, data_size);

  // ����ͼ���ÿ������
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // �����������������ת���ĵ�����
      int new_x = j - center_x;
      int new_y = i - center_y;

      // ��ת��ʽ����ԭͼ���е�����
      int old_x = (int)(new_x * cos_angle - new_y * sin_angle) + center_x;
      int old_y = (int)(new_x * sin_angle + new_y * cos_angle) + center_y;

      // �߽���
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

void rotateImage1(const char *name, const char *new_name, double angle,
                  int center_x, int center_y) {
  uint32 width, height, data_offset, data_size;
  uint8 *data;
  readBMPInfo(name, width, height, data_offset, data_size, data);

  double rad = angle / 180.0 * M_PI;
  double cos_angle = cos(rad);
  double sin_angle = sin(rad);

  uint32 new_width =
      (uint32)(width * fabs(cos_angle) + height * fabs(sin_angle));
  uint32 new_height =
      (uint32)(width * fabs(sin_angle) + height * fabs(cos_angle));

  uint32 num_width = data_size / height;
  uint32 new_num_width = 4 * ceil(new_width * 3.0 / 4);
  uint32 new_data_size = new_num_width * new_height;
  uint8 *new_data = new uint8[new_data_size];
  memset(new_data, 0, new_data_size);
  for (int i = 0; i < new_height; i++) {
    for (int j = 0; j < new_width; j++) {
      int new_x = j - center_x;
      int new_y = i - center_y;
      int old_x = (int)(new_x * cos_angle - new_y * sin_angle) + center_x;
      int old_y = (int)(new_x * sin_angle + new_y * cos_angle) + center_y;

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

// ��ʾ���˵��ĺ���
void mainMenu() {
  const int menuWidth = 30; // �˵��Ŀ��
  const string menuItems[] = {"��ֵ�˲�", "ͼ����С", "ͼ����ת", "�˳�����"};
  // ����˵���Ŀ������
  const int numItems = sizeof(menuItems) / sizeof(menuItems[0]);
  int selected = 0; // ��ǰѡ�еĲ˵���Ŀ����

  char bmp_name1[50] = "hqu.bmp"; // ����BMPͼ���ļ�������
  char bmp_name2[50] = "new.bmp"; // ���BMPͼ���ļ�������

  while (true) {
    system("cls"); // ����

    // ���Ʋ˵������߿�
    cout << "+";
    for (int i = 0; i < menuWidth; i++)
      cout << "-";
    cout << "+" << endl;

    // ��ʾ�˵�����
    string title = "���˵�";
    // �������ľ���λ��
    int titlePadding = (menuWidth - title.length()) / 2;
    cout << "|";
    cout << setw(titlePadding) << "" << title // ������⣬�������ո��Ծ���
         << setw(menuWidth - title.length() - titlePadding) << "";
    cout << "|" << endl;

    // ���Ʒָ���
    cout << "|";
    for (int i = 0; i < menuWidth; i++)
      cout << "-";
    cout << "|" << endl;

    // ��ʾ���в˵���Ŀ����ǵ�ǰѡ�е���Ŀ
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

    // ���Ʋ˵��ײ��߿�
    cout << "+";
    for (int i = 0; i < menuWidth; i++)
      cout << "-";
    cout << "+" << endl;

    char d = getch(); // ��ȡ�û���������
    switch (d) {
    case 'w':
      // ����
      selected = (selected - 1 + numItems) % numItems;
      break;
    case 's':
      // ����
      selected = (selected + 1) % numItems;
      break;
    case '\r': // ȷ��
      switch (selected) {
      case 0:
        // ������ֵ�˲�
        cout << "����ͼ������(��ʽ xxx.bmp) ";
        cin >> bmp_name1;
        medianFilter(bmp_name1, bmp_name2);
        cout << "��ֵ�˲���ɣ���ͼ���ѱ���Ϊ " << bmp_name2 << endl;
        getch();
        break;
      case 1: {
        double ratio;
        cout << "����ͼ������(��ʽ xxx.bmp) ";
        cin >> bmp_name1;
        cout << "��������С���������� 0.5: ";
        cin >> ratio;
        // ����ͼ����С
        shrinkImage(bmp_name1, bmp_name2, ratio);
        cout << "ͼ����С��ɣ���ͼ���ѱ���Ϊ " << bmp_name2 << endl;
        getch();
        break;
      }
      case 2: {
        double angle;
        int center_x, center_y;

        uint32 width1, height1, data_offset1, data_size1;
        uint8 *data1;
        // ��ȡԭʼͼ����Ϣ�����ڻ�ȡͼ��Ŀ�Ⱥ͸߶�
        cout << "����ͼ������(��ʽ xxx.bmp) ";
        cin >> bmp_name1;
        readBMPInfo(bmp_name1, width1, height1, data_offset1, data_size1,
                    data1);
        cout << "��������ת�Ƕȣ����Ƕ�˳ʱ����ת�����Ƕ���ʱ����ת��: ";
        cin >> angle;
        cout << "��������ת���ĵ��x���꣨��Χ0-" << width1 << "��: ";
        cin >> center_x;
        cout << "��������ת���ĵ��y���꣨��Χ0-" << height1 << "��: ";
        cin >> center_y;
        // ����ͼ����ת
        rotateImage(bmp_name1, bmp_name2, angle, center_x, center_y);
        cout << "ͼ����ת��ɣ���ͼ���ѱ���Ϊ " << bmp_name2 << endl;
        getch();
        break;
      }
      case 3:
        return; // �˳��˵�ѭ��
      }
      break;
    }
  }
}

int main() {
  mainMenu(); // �������˵�����
  return 0;
}