#include <conio.h>
#include <cstring>
#include <fstream>
// #include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <QString>
#include "BMP_Process.h"
#include <sstream>

// #define M_PI 3.1415926; // ����Բ���ʳ���

string BMP_Process::convertPath(const string& path) {
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
                 uint32 &data_offset, uint32 &data_size, uint8 *&data) {
    fstream bmpdata;
    bmpdata.open(name, ios::binary | ios::in); // �Զ�����ֻ��ģʽ���ļ�
    if (bmpdata.fail()) {                      // ����ļ��Ƿ��ʧ��
        // cout << "ԭʼͼ���ȡʧ��";
        exit(5); // ��ʧ�����˳�����
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
void BMP_Process::writeBMPInfo(string new_name, uint32 width, uint32 height,
                  uint32 data_offset, uint32 data_size, uint8 *data,
                  string old_name) {
    fstream bmpw;
    bmpw.open(new_name, ios::binary | ios::out); // �Զ�����дģʽ���ļ�
    if (bmpw.fail()) {                           // ����ļ��Ƿ��ʧ��
        // cout << "��ͼ��д��ʧ��";
        exit(4); // ��ʧ�����˳�����
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
void BMP_Process::medianFilter(string name, string new_name) {
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
void BMP_Process::shrinkImage(string name, string new_name, double ratio) {
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
void BMP_Process::rotateImage(string name, string new_name, double angle,
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



// medianFilter(bmp_name1, bmp_name2);
// shrinkImage(bmp_name1, bmp_name2, ratio);
// rotateImage(bmp_name1, bmp_name2, angle, center_x, center_y);

