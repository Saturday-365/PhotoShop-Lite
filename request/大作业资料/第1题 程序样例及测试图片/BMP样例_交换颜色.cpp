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

typedef unsigned char uint8;      //һ���ֽ�
typedef unsigned short uint16;    //�����ֽ�
typedef unsigned long uint32;     //�ĸ��ֽ�

void bmp_swapRB(char *name, char *new_name)
{
	uint32 width;        //ԭͼ���ȣ�������
	uint32 height;       //ԭͼ��߶ȣ�������
	uint32 data_offset;  //ԭͼ��������ƫ����
	uint32 data_size;	 //ԭͼ����������С
	uint8 *data;         //ԭͼ��������ָ��
	
	//��ԭͼ���ļ�
	fstream bmpr;
	bmpr.open(name, ios::binary|ios::in);
	if(bmpr.fail())
	{
		cout<<"ԭͼƬ��ȡʧ��";
		exit(1);
	}	
		
	//----------------------------------------------------------
	// ��ȡԭͼ��������Ϣ
	//----------------------------------------------------------
	// ע�����
	// 1. BPMͼ������ļ�ͷ����Ϣͷ����ɫ���������
	// 2. �ؼ���ϢΪ��ȡ��߶ȡ�����ƫ��������������С
	// 3. 24λBMPͼ���ʽ��Լ򵥣�û�е�ɫ�� 
	//----------------------------------------------------------
	
	//��ȡԭͼ���ȣ�������
	bmpr.seekg(18, ios::beg);  //���ö�ȡλ�ã��ļ�ͷƫ��18���ֽ�
	bmpr.read((char *)(&width), sizeof(width));	
	
	//��ȡԭͼ��߶ȣ�������
	bmpr.seekg(22, ios::beg);  //���ö�ȡλ�ã��ļ�ͷƫ��22���ֽ�
	bmpr.read((char *)(&height), sizeof(height));
	
	//��ȡԭͼ��������ƫ����    
	bmpr.seekg(10, ios::beg);  //���ö�ȡλ�ã��ļ�ͷƫ��10���ֽ�
	bmpr.read((char *)(&data_offset), sizeof(data_offset));
	
	//��ȡԭͼ����������С
	bmpr.seekg(34, ios::beg);  //���ö�ȡλ�ã��ļ�ͷƫ��38���ֽ�
	bmpr.read((char *)(&data_size), sizeof(data_size));	
	
	//��ȡԭͼ������������
	data = new uint8[data_size];
	bmpr.seekg(data_offset, ios::beg);  //���ö�ȡλ�ã�ƫ����data_offset
	bmpr.read((char *)data, data_size);
		
	//----------------------------------------------------------
	// ����ͼ������
	//----------------------------------------------------------
	// ע�����
	// 1. ÿ�����ص����3����ɫ��ÿ����ɫһ���ֽڣ���BGR˳������
	// 2. ÿ����width�����ص㣬�����ң�һ��һ��������
	// 3. ÿ�е��ֽ�����������Ϊwidth*3���������4�ֽڶ���ԭ�򡱣�
	//    �����Ϊ4����������β����0ʹ֮Ϊ4�ı���
	// 4. ȫͼ����height�У������µ��ϵ�˳��洢������һ�п�ʼ��
	// 5. ���ͼ��ֱ����б仯���������ز���ֵ
	//----------------------------------------------------------
	
	//��ͼ��ֱ��� 
	uint32 widthN = width;	
	uint32 heightN = height;
	
	//���¼�����ͼ�����
	uint32 numN_width = 4*ceil(widthN*3.0/4);	//��ͼ��ÿ���ֽ���
	uint32 dataN_size = numN_width*heightN;		//��ͼ����������С
	
	//��ͼ�������� 
	uint8 *dataN = new uint8[dataN_size];		//�������������ռ�
	memset(dataN, 0, dataN_size);				//�¿ռ��ʼ��Ϊ0
	uint8 *pixelN;								//��ͼ������ָ��
	
	uint32 num_width = data_size/height;	//ԭͼ��ÿ���ֽ���
	uint8 *pixel;							//ԭͼ������ָ�� 
	
	//���δ���ͼ���ÿ������
	for(int i=0;i<heightN;i++)
	{
		for(int j=0;j<widthN;j++)
		{
			//��ͼ������i�е�j�����صĵ�ַ
			pixelN = dataN+i*numN_width+j*3;
			
			//ԭͼ������i�е�j�����صĵ�ַ
			pixel = data+i*num_width+j*3;
	
			//���ص�B��G������ֵ 
			*(pixelN) = *(pixel+2);
			*(pixelN+1) = *(pixel+1);
			*(pixelN+2) = *(pixel);
		}
	}	
	
	//----------------------------------------------------------
	// д�����ļ�
	//----------------------------------------------------------
	// ע�����
	// 1. ��ͼ���ͷ��Ϣ����ֱ��ԭ�ļ����ƹ��� 
	// 2. �ֱ��ʿ��ܱ仯����Ҫ�������еĿ�ȡ��߶Ⱥ���������Сֵ
	//----------------------------------------------------------
	
	//����ͼ���ļ�
	fstream bmpw;
	bmpw.open(new_name, ios::binary|ios::out);
	if(bmpw.fail())
	{
		cout<<"��ͼƬ����ʧ��";
		exit(1);
	}
	
	//��������ԭͼ���ļ���ͷ��Ϣ 
	uint8 *tmp = new uint8[data_offset];
	bmpr.seekg(0, ios::beg);               //���ö�ȡλ��Ϊ�ļ�ͷ
	bmpr.read((char *)tmp, data_offset);   //������ȡ
	bmpw.write((char *)tmp, data_offset);  //����д��
	delete []tmp;
	
	//����д����ͼ���ȣ�������
	bmpw.seekp(18, ios::beg);  //����д��λ�ã��ļ�ͷƫ��18���ֽ�
	bmpw.write((char *)(&widthN), sizeof(widthN));	
	
	//����д����ͼ��߶ȣ�������
	bmpw.seekp(22, ios::beg);  //����д��λ�ã��ļ�ͷƫ��22���ֽ�
	bmpw.write((char *)(&heightN), sizeof(heightN));
	
	//����д����ͼ����������С
	bmpw.seekg(34, ios::beg);  //���ö�ȡλ�ã��ļ�ͷƫ��38���ֽ�
	bmpw.write((char *)(&dataN_size), sizeof(dataN_size));	
		
	//д����ͼ������������ 
	bmpw.seekp(data_offset, ios::beg);  //����д��λ�ã�ƫ����data_offset
	bmpw.write((char *)dataN, dataN_size);
	
	//�ͷ��������ڴ�ռ� 
	delete []data;
	delete []dataN;
	
	//�ر��ļ�
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
