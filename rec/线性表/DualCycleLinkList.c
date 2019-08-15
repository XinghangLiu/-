/*DualCycleLinkList.c    */

#include"DualCycleLinkList.h"

//1.初始化 
int InitList_DuL(DuLinkList *L)
{
	(*L)=(DuLinkList)malloc(sizeof(DuLNode));
	if(!(*L))
		exit(-1);
	(*L)->next=(*L)->prior=(*L);   //其前驱指针和后继指针都指向自己。形成循环。
	return 1; 
}
//2.置空 
int ClearList_DuL(DuLinkList L)
{
	DuLinkList p,q;
	
	p=L->next;
	while(p!=L)
	{
		q=p->next;   
		free(p);
		p=q;
	}
	L->prior=L->next=L;
	return 1;
}
//3.销毁整个表 
void DestroyList_DuL(DuLinkList *L)
{
	ClearList_DuL(*L);
	free(*L);
	*L=NULL;
}
//4.判空 
int ListEmpty_DuL(DuLinkList L)
{
	if(L && L->prior==L  && L->next==L)
		return 1;
	else 
		return 0;	
}
//5.返回元素的个数 
int ListLength_DuL(DuLinkList L)
{
	DuLinkList p;
	int count;
	if(L)
	{
		p=L;
		count=0;
		while(p->next!=L)
		{
			count++;
			p=p->next;
		}
	}	
	return count;
}
//6.得到i位置的数据元素 
int GetElem_DuL(DuLinkList L, int i, LElemType_DC *e)
{
	DuLinkList p;
	int count;	
	if(L)
	{
		p=L->next;
		count=1;
		while(p!=L && count<i)
		{
			count++;
			p=p->next;
		}
		if(p!=L)
		{
			*e=p->data;
			return 1;	
		}
	}
	return 0;
}
//7.寻找与e满足一定关系元素的位置 
int LocateElem_DuL(DuLinkList L, LElemType_DC e, int (Compare)(LElemType_DC, LElemType_DC))
{
	DuLinkList p;
	int count;
	if(L)
	{
		count=1;
		p=L->next;
		while(p!=L && !Compare(e,p->data))
		{
			count++;
			p=p->next;
		}
		if(p!=L)
		{
			return count;
		}
	}
	return 0;	
}
//8.接受cur_e的前驱 
int PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e)
{
	DuLinkList p;
	if(L)
	{
		p=L->next;
		while(p!=L  && p->data!=cur_e)
			p=p->next;
		if(p!=L && p->prior!=L)    //p不为首结点 
		{
			*pre_e=p->prior->data;
			return 1;
		}
	}
	return 0;
} 
//9. 接受cur_e的后继 
int NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e)
{
	DuLinkList p;
	if(L)
	{
		p=L->next;
		while(p!=L  &&p->data!=cur_e)
			p=p->next;
		if(p!=L  &&p->next!=L)
		{
		 	*next_e=p->next->data;
			 return 1;	
		}
	}
	return 0;
}
//10.返回指向第i个结点的指针
DuLinkList GetElemPtr_DuL(DuLinkList L, int i)
{
	DuLinkList p;
	int count;
	if(L)
	{
		p=L->next;
		count=1;
		while(p!=L  && i<count)
		{
			count++;
			p=p->next;
		}
		if(p!=L)
		{
			return p;
		}
	}
	return NULL;	
} 
//11.双循环链表的插入 
int ListInsert_DuL(DuLinkList L, int i, LElemType_DC e)
{
	if(i<1 || i>ListLength_DuL(L)+1)
		return 0;
	
	DuLinkList p,s;
	p=GetElemPtr_DuL(L,i);//得到第i个结点的指针
	if(!p)//!p指p=NULL,即p回到了原来的位置 
	{
		p=L;
	}
	s=(DuLinkList)malloc(sizeof(DuLNode));
	if(!s)
	{
		exit(-1);
	}
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return 1;	
}
//12.双循环链表的删除 
int ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e)
{
	DuLinkList p;
	if(!(p=GetElemPtr_DuL(L,i)))  //i不合法
		return 0;
	*e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	p=NULL;
	return 1; 
}
//13.遍历函数
void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC))
{
	DuLinkList p;
	p=L->next;
	while(p!=L)
	{
		Visit(p->data);
		p=p->next;
	}
} 