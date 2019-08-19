/*maze.h*/

#include "maze.h"
#include "Status.h"
//1.迷宫寻路 
int MazePath(MazeType maze[][N], PosType start, PosType end) 
{
	SqStack S;    //定义了一个栈空间来存放所有有用通道的信息。 
	SElemType_Sq NodeInf;  //存储当前通道块的信息
	PosType curPos;     //当前位置   .x    .y 
	int curStep;  //当前通道块的序号    1.2.3.....
	
	InitStack_Sq(&S);  //初始化栈 
	curPos=start;      //设定当前位置为入口位置 
	curStep=1;
	
	do     //do-while结构先执行结构里的语句，在结尾处判断条件是否为真，若为真，继续循环，不真，推出循环 
	{
		if(Pass(curPos,maze))   //如果当前位置未被访问，即是未曾访问过的通道块  pass函数用来判断当前位置的通道能不能通过 
		{
			FootPrint(curPos,maze);  //留下足迹   能，就记录下该通道 
			ShowMaze(maze);             //并且展示出来。 
			
			SetSElemType(&NodeInf,curStep,curPos,East);  //设置通道块信息   然后将该通道的信息记录在nodeInf里面 
			Push_Sq(&S,NodeInf);   //加入路径    //并且将nodeInf加入到栈里 
		  	if(EqualPosType(curPos,end))//一直循环下去，一直找到出口 
		  	{
	  			printf("\n successful!!\n");
				return 1; 
	  		}
			curPos=NextPos(curPos,East);
			curStep++;
		} 
		else     //如果当前位置不能通过 
		{
			if(!StackEmpty_Sq(S))  //不能通过的同时，栈不为空，即前面有能通过的通道块 
			{
				Pop_Sq(&S,&NodeInf);//退回一步  将该通道块在S栈中删除 
				while(NodeInf.di==North  && !StackEmpty_Sq(S))//四个方向都遍历过   因为North是最后一个方向，所以当di=north时，表示都遍历过了。 
				{
					MarkPrint(NodeInf.seat,maze);  //留下不能通过的标记，退回一步   // 
					ShowMaze(maze);
					
					Pop_Sq(&S,&NodeInf);  //继续删除通道块	
				}
				if(NodeInf.di<North)//如果方向没有遍历完 
				{
					maze[NodeInf.seat.x][NodeInf.seat.y]=++NodeInf.di;  //改变探索的方向，并留下记号 
					ShowMaze(maze);//每次探索一个方向，都要加到栈里，去循环一便，看能不能通过 
					
					Push_Sq(&S,NodeInf);  //
					
					curPos=NextPos(NodeInf.seat,NodeInf.di); 
				}
			}
		}
	}while(!StackEmpty_Sq(S));        //只要栈不为空就循环 
	printf("\nfailed!!\n");
	return 0;			
}
//2.  迷宫的初始化，包括出入口的初始化 
void InitMaze(MazeType maze[][N], PosType *start, PosType *end)
{
	int i,j,tmp;
	srand((unsigned)time(NULL));
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i==0  || j==0 || i==N-1 || j==N-1)
				maze[i][j]=Wall;    //迷宫的外墙
			else
			{
				tmp=rand()%X;
				if(!tmp)
					maze[i][j]=Obstacle;    //1/X的概率生成障碍
				else
					maze[i][j]=Way;    //加入路径 
			} 
		}
	}
	(*start).x=1;
	(*start).y=0;  //迷宫的入口
	(*end).x=N-2;
	(*end).y=N-1; //迷宫的出口
	
	maze[1][0]=maze[N-2][N-1]=Way; //出入口一定要置为路 
	maze[1][1]=maze[N-2][N-2]=Way; //将出入口临近的口设置为出入口 
}
//3.在屏幕上画出迷宫 
void PaintMaze(MazeType maze[][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			if(maze[i][j]==Wall)				//外墙 
				printf("*");
			else if(maze[i][j]==Obstacle)		//内部障碍 
				printf("*");
			else if(maze[i][j]==East)			//朝东探索
				printf("->");
			else if(maze[i][j]==South)			//朝南探索
				printf("|");
			else if(maze[i][j]==West)			//朝西探索
				printf("<-");
			else if(maze[i][j]==North)			//朝北探索
				printf("|");
			else if(maze[i][j]==DeadLock)		//访问过且不能通过的结点 
				printf("$");
			else								//未访问过的路径结点 
				printf(" ");

			if(j!=0 && j%(N-1)==0)				//每隔N个结点换行 
				printf("\n");
		}
}
//4.迷宫的显示 
void ShowMaze(MazeType maze[][N])
{
	Wait(SleepTime);  //暂停
	system("cls");//先清除屏幕现有的内容
	PaintMaze(maze);  //在屏幕上画出迷宫 
} 
//5.比较两个通道是否为同一个通道 
int EqualPosType(PosType a, PosType b)
{
	if(a.x==b.x  && a.y==b.y)
		return 1;
	else
		return 0; 
}
//6.判断此通道是否未被访问 
int Pass(PosType seat, MazeType maze[][N])
{
	int x=seat.x;
	int y=seat.y;
	
	if(!IsCross(seat)  && maze[x][y]==Way)  //结点不能越界 
		return 1;
	else
		return 0; 
} 
//7.遇到未访问结点时，留下初始足迹 
void FootPrint(PosType seat, MazeType maze[][N])
{
	maze[seat.x][seat.y]=East; //初始设置为向东探索	
} 
//8.更新通道的信息 
void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di)
{
	(*e).ord=ord;
	(*e).seat=seat;
	(*e).di=di;	
} 
//9.当前通道的后继 
PosType NextPos(PosType seat, int di)
{
	PosType tmp=seat;
	switch(di)
	{
		case East: tmp.y++;   //向东
			break;
		case South: tmp.x++;   //向南
			break;
		case West: tmp.y--;   //向西 
			break;
		case North: tmp.x--;   //向北 
			break;	 
	}
	return tmp;	
}
//10.判断当前位置是否越界 
int IsCross(PosType seat)
{
	int x=seat.x;
	int y=seat.y;
	
	if(x<0 || y<0 ||x>N-1  ||y>N-1)
		return 1;
	else
		return 0; 
}
//11.标记当前通道不可访问 
void MarkPrint(PosType seat, MazeType maze[][N])
{
	int x=seat.x;
	int y=seat.y;
	
	maze[x][y] =DeadLock;    //留下不能通过的标记 
}