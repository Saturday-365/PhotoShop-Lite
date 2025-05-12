//------------------------------------------------------
// An example of 24bit BMP image processing using c++ 
// for the students of Communications Engneering
// in Huaqiao University
//------------------------------------------------------
// written by Shengliang Peng
// on May 18, 2022
//------------------------------------------------------

#include<iostream>
#include<fstream>
#include<cstring>
#include<math.h>

using namespace std;

typedef unsigned char uint8;      //一个字节
typedef unsigned short uint16;    //两个字节
typedef unsigned long uint32;     //四个字节

void bmp_swapRB(char *name, char *new_name)
{
	uint32 width;        //原图像宽度（列数）
	uint32 height;       //原图像高度（行数）
	uint32 data_offset;  //原图像数据区偏移量
	uint32 data_size;	 //原图像数据区大小
	uint8 *data;         //原图像数据区指针
	
	//打开原图像文件
	fstream bmpr;
	bmpr.open(name, ios::binary|ios::in);
	if(bmpr.fail())
	{
		cout<<"原图片读取失败";
		exit(1);
	}	
		
	//----------------------------------------------------------
	// 读取原图像的相关信息
	//----------------------------------------------------------
	// 注意事项：
	// 1. BPM图像包括文件头、信息头、调色板和数据区
	// 2. 关键信息为宽度、高度、数据偏移量、数据区大小
	// 3. 24位BMP图像格式相对简单，没有调色板 
	//----------------------------------------------------------
	
	//读取原图像宽度（列数）
	bmpr.seekg(18, ios::beg);  //设置读取位置：文件头偏移18个字节
	bmpr.read((char *)(&width), sizeof(width));	
	
	//读取原图像高度（行数）
	bmpr.seekg(22, ios::beg);  //设置读取位置：文件头偏移22个字节
	bmpr.read((char *)(&height), sizeof(height));
	
	//读取原图像数据区偏移量    
	bmpr.seekg(10, ios::beg);  //设置读取位置：文件头偏移10个字节
	bmpr.read((char *)(&data_offset), sizeof(data_offset));
	
	//读取原图像数据区大小
	bmpr.seekg(34, ios::beg);  //设置读取位置：文件头偏移38个字节
	bmpr.read((char *)(&data_size), sizeof(data_size));	
	
	//读取原图像数据区数据
	data = new uint8[data_size];
	bmpr.seekg(data_offset, ios::beg);  //设置读取位置：偏移量data_offset
	bmpr.read((char *)data, data_size);
		
	//----------------------------------------------------------
	// 处理图像数据
	//----------------------------------------------------------
	// 注意事项：
	// 1. 每个像素点包含3种颜色，每个颜色一个字节，按BGR顺序排列
	// 2. 每行有width个像素点，从左到右，一个一个地排列
	// 3. 每行的字节数，理论上为width*3，但需遵顼“4字节对齐原则”，
	//    如果不为4的整数倍，尾部补0使之为4的倍数
	// 4. 全图包含height行，按从下到上的顺序存储（最下一行开始）
	// 5. 如果图像分辨率有变化，需更新相关参数值
	//----------------------------------------------------------
	
	//新图像分辨率 
	uint32 widthN = width;	
	uint32 heightN = height;
	
	//重新计算新图像参数
	uint32 numN_width = 4*ceil(widthN*3.0/4);	//新图像每行字节数
	uint32 dataN_size = numN_width*heightN;		//新图像数据区大小
	
	//新图像数据区 
	uint8 *dataN = new uint8[dataN_size];		//开辟新数据区空间
	memset(dataN, 0, dataN_size);				//新空间初始化为0
	uint8 *pixelN;								//新图像像素指针
	
	uint32 num_width = data_size/height;	//原图像每行字节数
	uint8 *pixel;							//原图像像素指针 
	
	//依次处理图像的每个像素
	for(int i=0;i<heightN;i++)
	{
		for(int j=0;j<widthN;j++)
		{
			//新图像倒数第i行第j列像素的地址
			pixelN = dataN+i*numN_width+j*3;
			
			//原图像倒数第i行第j列像素的地址
			pixel = data+i*num_width+j*3;
	
			//像素点B和G交换赋值 
			*(pixelN) = *(pixel+2);
			*(pixelN+1) = *(pixel+1);
			*(pixelN+2) = *(pixel);
		}
	}	
	
	//----------------------------------------------------------
	// 写入新文件
	//----------------------------------------------------------
	// 注意事项：
	// 1. 新图像的头信息，可直接原文件复制过来 
	// 2. 分辨率可能变化，需要更新其中的宽度、高度和数据区大小值
	//----------------------------------------------------------
	
	//打开新图像文件
	fstream bmpw;
	bmpw.open(new_name, ios::binary|ios::out);
	if(bmpw.fail())
	{
		cout<<"新图片创建失败";
		exit(1);
	}
	
	//批量复制原图像文件的头信息 
	uint8 *tmp = new uint8[data_offset];
	bmpr.seekg(0, ios::beg);               //设置读取位置为文件头
	bmpr.read((char *)tmp, data_offset);   //批量读取
	bmpw.write((char *)tmp, data_offset);  //批量写入
	delete []tmp;
	
	//重新写入新图像宽度（列数）
	bmpw.seekp(18, ios::beg);  //设置写入位置：文件头偏移18个字节
	bmpw.write((char *)(&widthN), sizeof(widthN));	
	
	//重新写入新图像高度（行数）
	bmpw.seekp(22, ios::beg);  //设置写入位置：文件头偏移22个字节
	bmpw.write((char *)(&heightN), sizeof(heightN));
	
	//重新写入新图像数据区大小
	bmpw.seekg(34, ios::beg);  //设置读取位置：文件头偏移38个字节
	bmpw.write((char *)(&dataN_size), sizeof(dataN_size));	
		
	//写入新图像数据区数据 
	bmpw.seekp(data_offset, ios::beg);  //设置写入位置：偏移量data_offset
	bmpw.write((char *)dataN, dataN_size);
	
	//释放数据区内存空间 
	delete []data;
	delete []dataN;
	
	//关闭文件
	bmpr.close();
	bmpw.close();
}


int main()
{
	char bmp_name1[50] = "hqu.bmp";
	char bmp_name2[50] = "new.bmp";
	
	bmp_swapRB(bmp_name1, bmp_name2);
	
	return 0;
}
