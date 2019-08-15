/*SequenceStack.h*/

#include<stdio.h>
#include<stdlib.h>

/*宏定义*/
#define STACK_INIT_SIZE 100   //栈的初始空间大小 
#define STACKINCREMENT 10    //空间增量

/*顺序栈类型定义*/ 
typedef int SElemType_Sq;  //栈元素的类型定义
typedef struct
{
	SElemType_Sq *base;  //栈底指针， 
	SElemType_Sq *top;   //栈顶指针
	int stacksize;
}SqStack;

/* 顺序栈函数列表 */
int InitStack_Sq(SqStack *S);
/*━━━━━━━━┓
┃(01)构造空栈S。 ┃
┗━━━━━━━━*/

int DestroyStack_Sq(SqStack *S);
/*━━━━━━┓
┃(02)销毁S。 ┃
┗━━━━━━*/ 
 
int ClearStack_Sq(SqStack *S);
/*━━━━━━┓
┃(03)置空S。 ┃
┗━━━━━━*/

int StackEmpty_Sq(SqStack S);
/*━━━━━━━━━━┓
┃(04)判断S是否为空。 ┃
┗━━━━━━━━━━*/

int StackLength_Sq(SqStack S);
/*━━━━━━━━━━┓
┃(05)返回S元素个数。 ┃
┗━━━━━━━━━━*/
 
int GetTop_Sq(SqStack S, SElemType_Sq *e);
/*━━━━━━━━━━━┓
┃(06)用e获取栈顶元素。 ┃
┗━━━━━━━━━━━*/

int Push_Sq(SqStack *S, SElemType_Sq e);
/*━━━━━━━━┓
┃(07)元素e进栈。 ┃
┗━━━━━━━━*/

int Pop_Sq(SqStack *S, SElemType_Sq *e);
/*━━━━━━━━┓
┃(08)元素e出栈。 ┃
┗━━━━━━━━*/

int StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));
/*━━━━━━┓
┃(09)访问栈。┃
┗━━━━━━*/ 


