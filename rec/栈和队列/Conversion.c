/*Conversion.c*/

#include "Conversion.h"

void conversion(int i)
{
	SqStack S;
	SElemType_Sq e;
	InitStack_Sq(&S);
	printf("ʮ������%dת��Ϊ�˽��ƺ�Ϊ��0",i);
	while(i)
	{
		Push_Sq(&S,i%8);  //��ջʱ�ӵ�λ����λ�� 
		i=i/8;
	}
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S,&e);
		printf("%d",e);
	}
} 