/*SequenceStack.h*/

#include<stdio.h>
#include<stdlib.h>

/*�궨��*/
#define STACK_INIT_SIZE 100   //ջ�ĳ�ʼ�ռ��С 
#define STACKINCREMENT 10    //�ռ�����

/*˳��ջ���Ͷ���*/ 
typedef int SElemType_Sq;  //ջԪ�ص����Ͷ���
typedef struct
{
	SElemType_Sq *base;  //ջ��ָ�룬 
	SElemType_Sq *top;   //ջ��ָ��
	int stacksize;
}SqStack;

/* ˳��ջ�����б� */
int InitStack_Sq(SqStack *S);
/*������������������
��(01)�����ջS�� ��
������������������*/

int DestroyStack_Sq(SqStack *S);
/*��������������
��(02)����S�� ��
��������������*/ 
 
int ClearStack_Sq(SqStack *S);
/*��������������
��(03)�ÿ�S�� ��
��������������*/

int StackEmpty_Sq(SqStack S);
/*����������������������
��(04)�ж�S�Ƿ�Ϊ�ա� ��
����������������������*/

int StackLength_Sq(SqStack S);
/*����������������������
��(05)����SԪ�ظ����� ��
����������������������*/
 
int GetTop_Sq(SqStack S, SElemType_Sq *e);
/*������������������������
��(06)��e��ȡջ��Ԫ�ء� ��
������������������������*/

int Push_Sq(SqStack *S, SElemType_Sq e);
/*������������������
��(07)Ԫ��e��ջ�� ��
������������������*/

int Pop_Sq(SqStack *S, SElemType_Sq *e);
/*������������������
��(08)Ԫ��e��ջ�� ��
������������������*/

int StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));
/*��������������
��(09)����ջ����
��������������*/ 


