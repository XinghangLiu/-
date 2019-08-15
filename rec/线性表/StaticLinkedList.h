/*静态链表---StaticLinkedList.h*/
#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

#define MAXSIZE 1000

/*静态链表的定义*/
typedef int SLinkList;  //静态链表的类型 
typedef int LElemType_S;//数据元素的类型 


typedef struct
{
	LElemType_S data;  //数据域 
	int cur;	//指针域 
}Component[MAXSIZE];     //链表空间的类型 

Component SPACE;//静态链表空间     全局变量

/*	静态链表函数列表 */
void InitSpace_SL();
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.14：将一维数组SPACE中各分量链成一个大的备用空间。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int Malloc_SL();
/*━━━━━━━━━━━━━━━━━┓
┃(02)算法2.15：为插入数据申请空间。┃
┗━━━━━━━━━━━━━━━━━*/

void Free_SL(int k);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法2.16：将下标为k的空闲结点回收。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

int InitList_SL(SLinkList *H);
/*━━━━━━━━━━━━━━━━┓
┃(04)初始化静态链表，建立头结点。┃
┗━━━━━━━━━━━━━━━━*/

int ClearList_SL(SLinkList H);
/*━━━━━┓
┃(05)置空。┃
┗━━━━━*/ 

void DestroyList_SL(SLinkList *H);
/*━━━━━┓
┃(06)销毁。┃
┗━━━━━*/

Status ListEmpty_SL(SLinkList H);
/*━━━━━┓
┃(07)判空。┃
┗━━━━━*/

int ListLength_SL(SLinkList H);
/*━━━━━┓
┃(08)求长。┃
┗━━━━━*/ 

Status GetElem_SL(SLinkList H, int i, LElemType_S *e);
/*━━━━━┓
┃(09)取值。┃
┗━━━━━*/

int LocateElem_SL(SLinkList H, LElemType_S e);
/*━━━━━━━━━━━━━━━━┓
┃(10)算法2.13：返回元素e的位序。 ┃
┗━━━━━━━━━━━━━━━━*/

int PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e);
/*━━━━━┓
┃(11)前驱。┃
┗━━━━━*/

int NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e);
/*━━━━━┓
┃(12)后继。┃
┗━━━━━*/ 

int ListInsert_SL(SLinkList H, int i, LElemType_S e);
/*━━━━━┓
┃(13)插入。┃
┗━━━━━*/

int ListDelete_SL(SLinkList H, int i, LElemType_S *e);
/*━━━━━┓
┃(14)删除。┃
┗━━━━━*/

int ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S));
/*━━━━━┓
┃(15)访问。┃
┗━━━━━*/  
