/*Single_Link_List.h*/
//������ͷ�ļ� 
#include<stdio.h>
#include<stdlib.h>
#include"Scanf.c"
#include"Status.h"

/*���������͵Ķ���*/
typedef int LElemType_L; //��������Ԫ������ 
typedef struct LNode
{
	LElemType_L data;  //������ 
	struct LNode* next;	//ָ���� 
}LNode;

typedef LNode* LinkList;  //ָ���������ָ��

/* ��������ͷ��㣩�����б� */ 
int InitList_L(LinkList *L);
/*����������������������
��(01)��ʼ��������L�� ��
����������������������*/

int ClearList_L(LinkList L);
/*��������������������������������
��(02)�ÿյ�����L��ͷ��㱣���� �� 
��������������������������������*/ 

void DestroyList_L(LinkList *L);
/*����������������������������������������
��(03)���ٵ�����L����ͬͨ���һ�����١� ��
����������������������������������������*/

int ListEmpty_L(LinkList L);
/*��������������������������������
��(04)�жϵ�����L�Ƿ�Ϊ�ա�     ��
��������������������������������*/

int ListLength_L(LinkList L);
/*��������������������������
��(05)���ص�����LԪ�ظ��� ��
��������������������������*/ 

int GetElem_L(LinkList L, int i, LElemType_L *e);
/*����������������������������������������
��(06)�㷨2.8����e���յ�����L�е�i��Ԫ�ة�
����������������������������������������*/ 

int LocateElem_L(LinkList L, LElemType_L e, int(Compare)(LElemType_L, LElemType_L));
/*��������������������������������������������������������
��(07)���ص�����L�е�һ����e����Compare��ϵ��Ԫ��λ�� ��
��������������������������������������������������������*/ 

int PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);
/*������������������������������
��(08)��pre_e����cur_e��ǰ������
������������������������������*/ 

int NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);
/*��������������������������������
��(09)��next_e����cur_e�ĺ�̡� ��
��������������������������������*/

int ListInsert_L(LinkList L, int i, LElemType_L e);
/*��������������������������������������������
��(10)�㷨2.9���ڵ�����L��i��λ��֮ǰ����e����
��������������������������������������������*/

int ListDelete_L(LinkList L, int i, LElemType_L *e);
/*������������������������������������������������������
��(11)�㷨2.10��ɾ��������L��i��λ�õ�ֵ������e���ա� ��
������������������������������������������������������*/ 

int ListTraverse_L(LinkList L, void(Visit)(LElemType_L));
/*������������������������������
��(12)��Visit�������ʵ�����L����
������������������������������*/  

int CreateList_HL(FILE *fp, LinkList *L, int n);
/*����������������������������������������������
��(13)�㷨2.11��ͷ�巨����������L(��������)�� ��
����������������������������������������������*/  

int CreateList_TL(FILE *fp, LinkList *L, int n);
/*������������������������������������
��(14)β�巨����������L(˳������)�� ��
������������������������������������*/   
//��Enter������ 
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }
