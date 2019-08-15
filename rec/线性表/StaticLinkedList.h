/*��̬����---StaticLinkedList.h*/
#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

#define MAXSIZE 1000

/*��̬����Ķ���*/
typedef int SLinkList;  //��̬��������� 
typedef int LElemType_S;//����Ԫ�ص����� 


typedef struct
{
	LElemType_S data;  //������ 
	int cur;	//ָ���� 
}Component[MAXSIZE];     //����ռ������ 

Component SPACE;//��̬����ռ�     ȫ�ֱ���

/*	��̬�������б� */
void InitSpace_SL();
/*��������������������������������������������������������������
��(01)�㷨2.14����һά����SPACE�и���������һ����ı��ÿռ䡣 ��
��������������������������������������������������������������*/

int Malloc_SL();
/*������������������������������������
��(02)�㷨2.15��Ϊ������������ռ䡣��
������������������������������������*/

void Free_SL(int k);
/*������������������������������������������
��(03)�㷨2.16�����±�Ϊk�Ŀ��н����ա� ��
������������������������������������������*/

int InitList_SL(SLinkList *H);
/*����������������������������������
��(04)��ʼ����̬��������ͷ��㡣��
����������������������������������*/

int ClearList_SL(SLinkList H);
/*������������
��(05)�ÿա���
������������*/ 

void DestroyList_SL(SLinkList *H);
/*������������
��(06)���١���
������������*/

Status ListEmpty_SL(SLinkList H);
/*������������
��(07)�пա���
������������*/

int ListLength_SL(SLinkList H);
/*������������
��(08)�󳤡���
������������*/ 

Status GetElem_SL(SLinkList H, int i, LElemType_S *e);
/*������������
��(09)ȡֵ����
������������*/

int LocateElem_SL(SLinkList H, LElemType_S e);
/*����������������������������������
��(10)�㷨2.13������Ԫ��e��λ�� ��
����������������������������������*/

int PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e);
/*������������
��(11)ǰ������
������������*/

int NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e);
/*������������
��(12)��̡���
������������*/ 

int ListInsert_SL(SLinkList H, int i, LElemType_S e);
/*������������
��(13)���롣��
������������*/

int ListDelete_SL(SLinkList H, int i, LElemType_S *e);
/*������������
��(14)ɾ������
������������*/

int ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S));
/*������������
��(15)���ʡ���
������������*/  
