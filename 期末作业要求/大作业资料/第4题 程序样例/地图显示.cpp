//------------------------------------------------------
// An example of pushbox game using c++ 
// for the students of Communications Engneering
// in Huaqiao University
//------------------------------------------------------
// written by Shengliang Peng
// on May 24, 2022
//------------------------------------------------------

#include<iostream>
#include<windows.h>
#include <conio.h>
using namespace std;

#define MaxRow 100   //��ͼ������� 
#define MaxCol 100   //��ͼ�������
#define MaxNum 10    //��Ϸ��������� 

//�ж������(p, q)�Ƿ�Ϊ����Ŀ�ĵ�
bool isdes(int des[][2], int num, int p, int q)
{
	for (int i=0;i<num;i++) //���β����ж� 
	{
		if (des[i][0]==p && des[i][1]==q)
		{
			return true;
		}
	}
	return false;
}

//��Ϸ��ʾ��� 
void game_show(int a[][MaxCol], int row, int col)
{
	system("cls");   //��ͼˢ�� 
	
	for(int i=0;i<row;i++)
    {
    	for(int j=0;j<col;j++)
    	{
    		switch(a[i][j])
    		{
    			case 0: cout<<"  ";break;   //�հף������ո� 
    			case 1: cout<<"��";break;	//ǽ 
    			case 2: cout<<"��";break;	//С�� 
    			case 3: cout<<"��";break;	//����Ŀ�ĵأ�����û�����ӣ�
    			case 4: cout<<"��";break;	//���Ӳ���Ŀ�ĵ�λ�� 
    			case 5: cout<<"��";break;	//���Ӵ���Ŀ�ĵ�λ�� 
			}
		}
		cout<<endl;
    }
} 


int game(int a[][MaxCol], int row, int col, int num, int x, int y, int box[][2], int des[][2])
{	
	//��ͼ�ϱ�ʶ��С�� 
	a[x][y] = 2;
	
	//�ڵ�ͼ�ϱ�ʶ������Ŀ�ĵ�           
	for(int i=0;i<num;i++)
	{
		a[des[i][0]][des[i][1]] = 3;
	} 
	
	//�ڵ�ͼ�ϱ�ʶ������          
	for(int i=0;i<num;i++)
	{
		if (isdes(des, num, box[i][0], box[i][1])==false)
		{
			a[box[i][0]][box[i][1]] = 4;    //����û�е���Ŀ�ĵ� 
		}
		else
		{
			a[box[i][0]][box[i][1]] = 5;   //�����Ѿ�����Ŀ�ĵ� 
		}
		
	} 	
	
	//��ʼ��ʾ 
	game_show(a, row, col);  
    
    char d;
    
    //�ظ���Ϸ 
    while(1)  
    {
    	//����������ַ� 
    	d = getch();   
    	
        if(d=='w' || d=='W'|| d==72) //���� 
        {
        	//���С�˿���������
        	
        	
        	//���С�˿�������������
        	
			
        }
        else if(d=='s' || d=='S' || d==80)  //���� 
        {
        
        }
        else if(d=='a' || d=='A' || d==75)  //���� 
        {
        	
        }
		else if(d=='d' || d=='D' || d==77)  //���� 
        {
        
        }
        
        //ˢ����ʾ
        game_show(a, row, col);
        
        //��Ϸ�����ж� 

    }
    
    return 0;
}

int main()
{
	int row = 9;   //��ͼʵ������ 
	int col = 8;   //��ͼʵ������	
	int num = 4;   //ʵ�����Ӹ���
	
	//��Ϸ��̬��ͼ 
    int a[MaxRow][MaxCol] = {{0, 0, 1, 1, 1, 1, 1, 0},
    		                 {1, 1, 1, 0, 0, 0, 1, 0},
    			             {1, 0, 0, 0, 0, 0, 1, 0},
    			             {1, 1, 1, 0, 0, 0, 1, 0},
    			             {1, 0, 1, 1, 0, 0, 1, 0},
    			             {1, 0, 1, 0, 0, 0, 1, 1},
    			             {1, 0, 0, 0, 0, 0, 0, 1},
    			             {1, 0, 0, 0, 0, 0, 0, 1},
    			             {1, 1, 1, 1, 1, 1, 1, 1}};			     
	
	//С�˵�ǰ����
	int x = 2;		 
	int y = 2;

	//���ӵ�ǰ����
	int box[MaxNum][2] = {{2, 1},
	                      {3, 4},
	                      {4, 4},
	                      {6, 1}};
	                      
	//����Ŀ�ĵ�����
	int des[MaxNum][2] = {{2, 1},
	                      {3, 5},
	                      {4, 1},
	                      {5, 4}};
	                   
	game(a, row, col, num, x, y, box, des); 
	
}




