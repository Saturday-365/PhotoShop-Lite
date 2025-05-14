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

#define MaxRow 100   //地图最大行数 
#define MaxCol 100   //地图最大列数
#define MaxNum 10    //游戏最大箱子数 

//判断坐标点(p, q)是否为箱子目的地
bool isdes(int des[][2], int num, int p, int q)
{
	for (int i=0;i<num;i++) //依次查找判断 
	{
		if (des[i][0]==p && des[i][1]==q)
		{
			return true;
		}
	}
	return false;
}

//游戏显示输出 
void game_show(int a[][MaxCol], int row, int col)
{
	system("cls");   //地图刷新 
	
	for(int i=0;i<row;i++)
    {
    	for(int j=0;j<col;j++)
    	{
    		switch(a[i][j])
    		{
    			case 0: cout<<"  ";break;   //空白（两个空格） 
    			case 1: cout<<"■";break;	//墙 
    			case 2: cout<<"♀";break;	//小人 
    			case 3: cout<<"·";break;	//箱子目的地（上面没有箱子）
    			case 4: cout<<"○";break;	//箱子不在目的地位置 
    			case 5: cout<<"☉";break;	//箱子处于目的地位置 
			}
		}
		cout<<endl;
    }
} 


int game(int a[][MaxCol], int row, int col, int num, int x, int y, int box[][2], int des[][2])
{	
	//地图上标识出小人 
	a[x][y] = 2;
	
	//在地图上标识出箱子目的地           
	for(int i=0;i<num;i++)
	{
		a[des[i][0]][des[i][1]] = 3;
	} 
	
	//在地图上标识出箱子          
	for(int i=0;i<num;i++)
	{
		if (isdes(des, num, box[i][0], box[i][1])==false)
		{
			a[box[i][0]][box[i][1]] = 4;    //箱子没有到达目的地 
		}
		else
		{
			a[box[i][0]][box[i][1]] = 5;   //箱子已经到达目的地 
		}
		
	} 	
	
	//初始显示 
	game_show(a, row, col);  
    
    char d;
    
    //重复游戏 
    while(1)  
    {
    	//捕获输入的字符 
    	d = getch();   
    	
        if(d=='w' || d=='W'|| d==72) //向上 
        {
        	//如果小人可以往上走
        	
        	
        	//如果小人可以往上推箱子
        	
			
        }
        else if(d=='s' || d=='S' || d==80)  //向下 
        {
        
        }
        else if(d=='a' || d=='A' || d==75)  //向左 
        {
        	
        }
		else if(d=='d' || d=='D' || d==77)  //向右 
        {
        
        }
        
        //刷新显示
        game_show(a, row, col);
        
        //游戏结束判断 

    }
    
    return 0;
}

int main()
{
	int row = 9;   //地图实际行数 
	int col = 8;   //地图实际列数	
	int num = 4;   //实际箱子个数
	
	//游戏静态地图 
    int a[MaxRow][MaxCol] = {{0, 0, 1, 1, 1, 1, 1, 0},
    		                 {1, 1, 1, 0, 0, 0, 1, 0},
    			             {1, 0, 0, 0, 0, 0, 1, 0},
    			             {1, 1, 1, 0, 0, 0, 1, 0},
    			             {1, 0, 1, 1, 0, 0, 1, 0},
    			             {1, 0, 1, 0, 0, 0, 1, 1},
    			             {1, 0, 0, 0, 0, 0, 0, 1},
    			             {1, 0, 0, 0, 0, 0, 0, 1},
    			             {1, 1, 1, 1, 1, 1, 1, 1}};			     
	
	//小人当前坐标
	int x = 2;		 
	int y = 2;

	//箱子当前坐标
	int box[MaxNum][2] = {{2, 1},
	                      {3, 4},
	                      {4, 4},
	                      {6, 1}};
	                      
	//箱子目的地坐标
	int des[MaxNum][2] = {{2, 1},
	                      {3, 5},
	                      {4, 1},
	                      {5, 4}};
	                   
	game(a, row, col, num, x, y, box, des); 
	
}




