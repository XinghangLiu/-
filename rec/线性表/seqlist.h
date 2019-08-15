//顺序存储结构线性表
//seqlist.h

#include <stdio.h>
#include <stdlib.h>

/* 宏定义 */

#define LIST_INIT_SIZE 100  //线性表存储结构的初始分配量 
#define LISTINCREMENT 10  //分配增量
typedef int LElemType_Sq;

/* 顺序表类型定义 */

typedef  struct
{
	LElemType_Sq *elem;//存储空间的基址，指向第一个结点的指针
	int length;//当前线性表的长度
	int listsize;//当前分配的存储容量	
} SqList;

/* 顺序表函数列表 */
int InitList_Sq(SqList *L);
/*━━━━━━━━━━━━━━━┓
┃(01)算法2.3：初始化空顺序表L。┃
┗━━━━━━━━━━━━━━━*/

void ClearList_Sq(SqList *L);
/*━━━━━━━━━┓
┃(02)清空顺序表L。 ┃
┗━━━━━━━━━*/

void DestroyList_Sq(SqList *L);
/*━━━━━━━━━┓
┃(03)销毁顺序表L。 ┃
┗━━━━━━━━━*/
	  
int ListEmpty_Sq(SqList L);
/*━━━━━━━━━━━━━┓
┃(04)判断顺序表L是否为空。 ┃
┗━━━━━━━━━━━━━*/

int ListLength_Sq(SqList L);
/*━━━━━━━━━━━━━━┓
┃(05)返回顺序表L中元素个数。 ┃
┗━━━━━━━━━━━━━━*/
	
int GetElem_Sq(SqList L, int i, LElemType_Sq *e);
/*━━━━━━━━━━━━━━━━┓
┃(06)用e接收顺序表L中第i个元素。 ┃
┗━━━━━━━━━━━━━━━━*/

int LocateElem_Sq(SqList L, LElemType_Sq e, int(Compare)(LElemType_Sq, LElemType_Sq));
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)算法2.6：返回顺序表L中首个与e满足Compare关系的元素位序。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);
/*━━━━━━━━━━━━━━━━━┓
┃(08)用pre_e接收cur_e的前驱。      ┃
┗━━━━━━━━━━━━━━━━━*/

int NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);
/*━━━━━━━━━━━━━━━━━┓
┃(09)用next_e接收cur_e的后继。     ┃
┗━━━━━━━━━━━━━━━━━*/

int ListInsert_Sq(SqList *L, int i, LElemType_Sq e);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(10)算法2.4：在顺序表L的第i个位置上插入e。┃
┗━━━━━━━━━━━━━━━━━━━━━*/

int ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(11)算法2.5：删除顺序表L上第i个位置的元素，并用e返回。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int ListTraverse_Sq(SqList L, void (Visit)(LElemType_Sq)); 
/*━━━━━━━━━━━━━━┓
┃(12)用visit函数访问顺序表L。┃
┗━━━━━━━━━━━━━━*/
 //摁Enter键继续 
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }


