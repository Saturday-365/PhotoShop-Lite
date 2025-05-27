#ifndef BMP_PROCESS_H
#define BMP_PROCESS_H

#include <conio.h>
#include <cstring>

// #include <iomanip>
#include <math.h>
#include <string>
#include <QString>

using namespace std;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

class BMP_Process
{
private:
    void readBMPInfo(string name, uint32 &width, uint32 &height,uint32 &data_offset, uint32 &data_size, uint8 *&data);
    void writeBMPInfo(string new_name, uint32 width, uint32 height,uint32 data_offset, uint32 data_size, uint8 *data,string old_name);
public:
    void medianFilter(string name, string new_name);
    void shrinkImage(string name, string new_name, double ratio);
    void rotateImage(string name, string new_name, double angle,int center_x, int center_y);
};

#endif
