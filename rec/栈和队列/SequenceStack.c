/*SequenceStack.c*/

#include "SequenceStack.h"
//1.初始化栈，构造空栈 
int InitStack_Sq(SqStack *S)
{
	(*S).base=(SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));//申请初始化内存空间大小，得到栈底指针
	if(!(*S).base)
		exit(-1);
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE; 
	return 1;
}
//2.销毁栈 
int DestroyStack_Sq(SqStack *S)
{
	free((*S).base);
	(*S).base=(*S).top=NULL;
	(*S).stacksize=0;
	return 1;
}
//3.置空 
int ClearStack_Sq(SqStack *S)
{
	(*S).top=(*S).base;
	return 1;
} 
//4.判空 
int StackEmpty_Sq(SqStack S)
{
	if(S.top==S.base)
		return 1;
	else
		return 0;
}
//5.求栈长 
int StackLength_Sq(SqStack S)
{
	return S.top-S.base;	
}
//6.获取栈顶元素 
int GetTop_Sq(SqStack S, SElemType_Sq *e)
{
	if(S.base==S.top)
		return 0;
	*e=*(S.top-1);
	return 1;	
}
//7.元素e进栈 
int Push_Sq(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base >= (*S).stacksize)//栈的长度满了，需要扩充 
	{
		(*S).base=(SElemType_Sq *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(-1);
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACKINCREMENT;	
	}
	*(S->top)=e;  //进栈先赋值，然后自增。 
	(S->top)++;
	return 1;	
}
//8.元素e出栈 
int Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return 0;
	(*S).top--;
	*e=*((*S).top);
	return 1;
} 
//9.遍历全栈 
int StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{
	SElemType_Sq *p=S.base;
	while(p<S.top)
	{
		Visit(*p++);	
	}
	return 1;
} 