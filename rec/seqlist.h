//˳��洢�ṹ���Ա�
//seqlist.h

#include <stdio.h>
#include <stdlib.h>

/* �궨�� */

#define LIST_INIT_SIZE 100  //���Ա�洢�ṹ�ĳ�ʼ������ 
#define LISTINCREMENT 10  //��������
typedef int LElemType_Sq;

/* ˳������Ͷ��� */

typedef  struct
{
	LElemType_Sq *elem;//�洢�ռ�Ļ�ַ��ָ���һ������ָ��
	int length;//��ǰ���Ա�ĳ���
	int listsize;//��ǰ����Ĵ洢����	
} SqList;

/* ˳������б� */
int InitList_Sq(SqList *L);
/*��������������������������������
��(01)�㷨2.3����ʼ����˳���L����
��������������������������������*/

void ClearList_Sq(SqList *L);
/*��������������������
��(02)���˳���L�� ��
��������������������*/

void DestroyList_Sq(SqList *L);
/*��������������������
��(03)����˳���L�� ��
��������������������*/
	  
int ListEmpty_Sq(SqList L);
/*����������������������������
��(04)�ж�˳���L�Ƿ�Ϊ�ա� ��
����������������������������*/

int ListLength_Sq(SqList L);
/*������������������������������
��(05)����˳���L��Ԫ�ظ����� ��
������������������������������*/
	
int GetElem_Sq(SqList L, int i, LElemType_Sq *e);
/*����������������������������������
��(06)��e����˳���L�е�i��Ԫ�ء� ��
����������������������������������*/

int LocateElem_Sq(SqList L, LElemType_Sq e, int(Compare)(LElemType_Sq, LElemType_Sq));
/*��������������������������������������������������������������
��(07)�㷨2.6������˳���L���׸���e����Compare��ϵ��Ԫ��λ�򡣩�
��������������������������������������������������������������*/

int PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);
/*������������������������������������
��(08)��pre_e����cur_e��ǰ����      ��
������������������������������������*/

int NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);
/*������������������������������������
��(09)��next_e����cur_e�ĺ�̡�     ��
������������������������������������*/

int ListInsert_Sq(SqList *L, int i, LElemType_Sq e);
/*��������������������������������������������
��(10)�㷨2.4����˳���L�ĵ�i��λ���ϲ���e����
��������������������������������������������*/

int ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);
/*��������������������������������������������������������
��(11)�㷨2.5��ɾ��˳���L�ϵ�i��λ�õ�Ԫ�أ�����e���ء���
��������������������������������������������������������*/

int ListTraverse_Sq(SqList L, void (Visit)(LElemType_Sq)); 
/*������������������������������
��(12)��visit��������˳���L����
������������������������������*/
 //��Enter������ 
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }


