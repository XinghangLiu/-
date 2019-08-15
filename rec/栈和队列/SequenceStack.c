/*SequenceStack.c*/

#include "SequenceStack.h"
//1.��ʼ��ջ�������ջ 
int InitStack_Sq(SqStack *S)
{
	(*S).base=(SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));//�����ʼ���ڴ�ռ��С���õ�ջ��ָ��
	if(!(*S).base)
		exit(-1);
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE; 
	return 1;
}
//2.����ջ 
int DestroyStack_Sq(SqStack *S)
{
	free((*S).base);
	(*S).base=(*S).top=NULL;
	(*S).stacksize=0;
	return 1;
}
//3.�ÿ� 
int ClearStack_Sq(SqStack *S)
{
	(*S).top=(*S).base;
	return 1;
} 
//4.�п� 
int StackEmpty_Sq(SqStack S)
{
	if(S.top==S.base)
		return 1;
	else
		return 0;
}
//5.��ջ�� 
int StackLength_Sq(SqStack S)
{
	return S.top-S.base;	
}
//6.��ȡջ��Ԫ�� 
int GetTop_Sq(SqStack S, SElemType_Sq *e)
{
	if(S.base==S.top)
		return 0;
	*e=*(S.top-1);
	return 1;	
}
//7.Ԫ��e��ջ 
int Push_Sq(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base >= (*S).stacksize)//ջ�ĳ������ˣ���Ҫ���� 
	{
		(*S).base=(SElemType_Sq *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(-1);
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACKINCREMENT;	
	}
	*(S->top)=e;  //��ջ�ȸ�ֵ��Ȼ�������� 
	(S->top)++;
	return 1;	
}
//8.Ԫ��e��ջ 
int Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;
	*e=*((*S).top);
	return 1;
} 
//9.����ȫջ 
int StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{
	SElemType_Sq *p=S.base;
	while(p<S.top)
	{
		Visit(*p++);	
	}
	return 1;
} 