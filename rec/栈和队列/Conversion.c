/*Conversion.c*/

#include "Conversion.h"

void conversion(int i)
{
	SqStack S;
	SElemType_Sq e;
	InitStack_Sq(&S);
	printf("十进制数%d转换为八进制后为：0",i);
	while(i)
	{
		Push_Sq(&S,i%8);  //进栈时从低位到高位； 
		i=i/8;
	}
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S,&e);
		printf("%d",e);
	}
} 