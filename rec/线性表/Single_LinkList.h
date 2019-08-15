/*Single_Link_List.h*/
//单链表头文件 
#include<stdio.h>
#include<stdlib.h>
#include"Scanf.c"
#include"Status.h"

/*单链表类型的定义*/
typedef int LElemType_L; //定义数据元素类型 
typedef struct LNode
{
	LElemType_L data;  //数据域 
	struct LNode* next;	//指针域 
}LNode;

typedef LNode* LinkList;  //指向单链表结点的指针

/* 单链表（带头结点）函数列表 */ 
int InitList_L(LinkList *L);
/*━━━━━━━━━━┓
┃(01)初始化单链表L。 ┃
┗━━━━━━━━━━*/

int ClearList_L(LinkList L);
/*━━━━━━━━━━━━━━━┓
┃(02)置空单链表L，头结点保留。 ┃ 
┗━━━━━━━━━━━━━━━*/ 

void DestroyList_L(LinkList *L);
/*━━━━━━━━━━━━━━━━━━━┓
┃(03)销毁单链表L，连同通结点一起销毁。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

int ListEmpty_L(LinkList L);
/*━━━━━━━━━━━━━━━┓
┃(04)判断单链表L是否为空。     ┃
┗━━━━━━━━━━━━━━━*/

int ListLength_L(LinkList L);
/*━━━━━━━━━━━━┓
┃(05)返回单链表L元素个数 ┃
┗━━━━━━━━━━━━*/ 

int GetElem_L(LinkList L, int i, LElemType_L *e);
/*━━━━━━━━━━━━━━━━━━━┓
┃(06)算法2.8：用e接收单链表L中第i个元素┃
┗━━━━━━━━━━━━━━━━━━━*/ 

int LocateElem_L(LinkList L, LElemType_L e, int(Compare)(LElemType_L, LElemType_L));
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)返回单链表L中第一个与e满足Compare关系的元素位序。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/ 

int PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);
/*━━━━━━━━━━━━━━┓
┃(08)用pre_e接收cur_e的前驱。┃
┗━━━━━━━━━━━━━━*/ 

int NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);
/*━━━━━━━━━━━━━━━┓
┃(09)用next_e接收cur_e的后继。 ┃
┗━━━━━━━━━━━━━━━*/

int ListInsert_L(LinkList L, int i, LElemType_L e);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(10)算法2.9：在单链表L第i个位置之前插入e。┃
┗━━━━━━━━━━━━━━━━━━━━━*/

int ListDelete_L(LinkList L, int i, LElemType_L *e);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(11)算法2.10：删除单链表L第i个位置的值，并用e接收。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/ 

int ListTraverse_L(LinkList L, void(Visit)(LElemType_L));
/*━━━━━━━━━━━━━━┓
┃(12)用Visit函数访问单链表L。┃
┗━━━━━━━━━━━━━━*/  

int CreateList_HL(FILE *fp, LinkList *L, int n);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(13)算法2.11：头插法建立单链表L(逆序输入)。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/  

int CreateList_TL(FILE *fp, LinkList *L, int n);
/*━━━━━━━━━━━━━━━━━┓
┃(14)尾插法建立单链表L(顺序输入)。 ┃
┗━━━━━━━━━━━━━━━━━*/   
//摁Enter键继续 
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }
