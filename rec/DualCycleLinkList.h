/*DualCycleLinkList.h     双向循环链表结构*/

#include<stdio.h>
#include<stdlib.h> 

/*双循环链表类型的定义*/
typedef int LElemType_DC;
typedef struct DuLNode
{
	LElemType_DC data;   //数据域 
	struct 	DuLNode* prior;   //前驱指针 
	struct  DuLNode* next;    //后继指针 
}DuLNode;

typedef DuLNode* DuLinkList;    //指向双循环结构的指针

/*	双循环链表函数列表	*/ 
int InitList_DuL(DuLinkList *L);
/*━━━━━━━━━━┓
┃(01)初始化双链表L。 ┃
┗━━━━━━━━━━*/

int ClearList_DuL(DuLinkList L);
/*━━━━━━┓
┃(02)置空L。 ┃
┗━━━━━━*/ 

void DestroyList_DuL(DuLinkList *L);
/*━━━━━━┓
┃(03)销毁L。 ┃
┗━━━━━━*/

int ListEmpty_DuL(DuLinkList L);
/*━━━━━━━━━━┓
┃(04)判断L是否为空。 ┃
┗━━━━━━━━━━*/ 

int ListLength_DuL(DuLinkList L);
/*━━━━━━━━━━┓
┃(05)返回L元素个数。 ┃
┗━━━━━━━━━━*/ 

int GetElem_DuL(DuLinkList L, int i, LElemType_DC *e);
/*━━━━━━━━━━━━━━━━━┓
┃(06)用e接收L中第i个结点的元素值。 ┃
┗━━━━━━━━━━━━━━━━━*/ 

int LocateElem_DuL(DuLinkList L, LElemType_DC e, int (Compare)(LElemType_DC, LElemType_DC));
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)返回L中第一个与e满足Compare关系的元素位序。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/ 

int PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e);
/*━━━━━━━━━━━━━━┓
┃(08)用pre_e接收cur_e的前驱。┃
┗━━━━━━━━━━━━━━*/ 

int NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);
/*━━━━━━━━━━━━━━━┓
┃(09)用next_e接收cur_e的后继。 ┃
┗━━━━━━━━━━━━━━━*/

DuLinkList GetElemPtr_DuL(DuLinkList L, int i);
/*━━━━━━━━━━━━━━━━┓
┃(10)返回L中指向第i个结点的指针。┃
┗━━━━━━━━━━━━━━━━*/

int ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);
/*━━━━━━━━━━━━━━━━━━━┓
┃(11)算法2.18：在L第i个位置之前插入e。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

int ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(12)算法2.19：删除L第i个位置的值，并用e接收。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/ 

void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));
/*━━━━━━━━━━━┓
┃(13)用Visit函数访问L。┃
┗━━━━━━━━━━━*/  

