#ifndef BMP_PROCESS_H
#define BMP_PROCESS_H

#include <conio.h>
#include <cstring>
// #include <iomanip>
#include <QString>
#include <math.h>
#include <string>


using namespace std;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

class BMP_Process{
private:
  void readBMPInfo(string name, uint32 &width, uint32 &height,
                   uint32 &data_offset, uint32 &data_size, uint8 *&data);
  void writeBMPInfo(string new_name, uint32 width, uint32 height,
                    uint32 data_offset, uint32 data_size, uint8 *data,
                    string old_name);
  uint32 calculateRowSize(uint32 width);

public:
  string convertPath(const string &path);
  void medianFilter(string name, string new_name);
  void shrinkImage(string name, string new_name, double ratio_x,double ratio_y);
  void rotateImage(string name, string new_name, double angle, int center_x,
                   int center_y);
};

#endif
