#include"Single_LinkList.h"
//1.初始化单链表 
int InitList_L(LinkList *L)
{
	(*L)=(LinkList)malloc(sizeof(LNode));  //申请链表头结点的内存空间 
	if(!(*L))
		return 0;
	(*L)->next=NULL;//头节点的下一个节点指向null 
	return 1;	
}
//2.清理单链表（保留头结点） 
int ClearList_L(LinkList L)
{
	if(!L)
		return 0;
	LinkList pre,p;
	pre=L->next;//得到链表的第一个结点（保留头结点）
	while(pre)
	{
		p=pre->next;//得到当前结点的后一个结点地址 
		free(pre);//销毁当前结点 
		pre=p;// 
	}	
	L->next=NULL;
	return 1;
} 
//3.销毁单链表 
void DestroyList_L(LinkList *L)
{
	LinkList p;
	p=(*L);
	while(p)//遍历销毁 
	{
		p=(*L)->next;
		free((*L));
		(*L)=p;
	}
}
//4.判断链表是否为空 
int ListEmpty_L(LinkList L)
{
	if(L!=NULL && L->next==NULL)
		return 1;
	else 
	 	return 0;
}
//5.单链表的长度 
int ListLength_L(LinkList L)
{
	int i=0;
	LinkList p;
	if(L)
	{
		p=L->next;	
		while(p)
		{
			i++;
			p=p->next;
		}
	}
	return i;
}
//6.得到单链表中i位置的元素 
int GetElem_L(LinkList L, int i, LElemType_L *e)
{
	int j;
	LinkList p;
	j=0;
	p=L->next;
	
	while(p && j<i)//得到i位置的地址和j值 
	{
		j++;
		p=p->next;
	}
	
	if(!p ||j>i)
		return 0;
	
	(*e)=p->data;
	return 1;		
}
//7.返回链表中第一个和e满足compare关系的元素的位置 
int LocateElem_L(LinkList L, LElemType_L e, int(Compare)(LElemType_L, LElemType_L))
{
	int i;
	LinkList p;
	i=-1;
	
	if(L)
	{
		i=0;
		p=L->next;
		while(p)
		{
			i++;//每循环依次，i+1 
			if(!Compare(e,p->data))//循环条件就是与Compare不匹配 
			{
				p=p->next;// 一旦不匹配就向后移 
				if(p==NULL)//如何到最后了就+1 
					i++;
				
			}
			else //与 Compare匹配之后就跳出循环。 
				break;
		}
	}
	return i;
} 
//8.接受cur_e的直接前驱元素 
int PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e)
{
	LinkList p,suc;
	if(L)//表存在
	{
		p=L->next;
		if(p->data!=cur_e)//判断cur_e不是第一个结点，因为第一个结点没有前继
		{
			while(p)
			{
				suc=p->next;//指向后继元素
				if(suc->data==cur_e)
				{
					*pre_e=p->data;
					return 1;
				} 
				p=suc;//后移一位 
			}
			
			 
		} 
	} 
	return 0;
}
//9.接受cur_e的直接后继元素 
int NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
	LinkList p,suc;
	if(L)//非空表
	{
		p=L->next;
		while(p && p->next)
		{
			suc=p->next;
			if(suc  && p->data==cur_e)
			{
				*next_e=suc->data;
				return 1;
			}
			if(suc &&p->data!=cur_e)
			{
				p=suc;
			}
			else 
				break;
		}
	}
	return 0; 
}
//10.单链表的插入操作 
int ListInsert_L(LinkList L, int i, LElemType_L e)
{
	LinkList p,s;
	int j;
	p=L;
	j=0;
	
	while(p && j<i-1)
	{
		p=p->next;
		++j;//最后一个不++，得到i-1 
	}	
	if(!p  || j>i-1)
	{
		return 0;
	}
	
	s=(LinkList)malloc(sizeof(LNode));
	if(!s)
		return 0;
	s->data=e;
	s->next=p->next;
	p->next=s;
	
	return 1;
} 
//11.单链表的删除操作 
int ListDelete_L(LinkList L, int i, LElemType_L *e)
{
	LinkList pre,p;
	int j;
	
	pre=L;
	j=1;
	while(pre->next  &&j<i)//找到i的位置，并将pre指向i元素的前驱
	{
		pre=pre->next;
		++j;	
	} 
	if(!pre->next || j>i)
		return 0;
	p=pre->next;
	(*e)=p->data;
	pre->next=p->next;
	free(p);
	return 1;
}
//12.单链表遍历 
int ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
{
	LinkList p;
	if(!L)
		return 0;
	else 
		p=L->next;
	
	while(p)
	{
		Visit(p->data);
		p=p->next;
	}
	return 1;
}
//13.头插法建立单链表（逆序输入） 
int CreateList_HL(FILE *fp, LinkList *L, int n)
{
	LinkList p;
	LElemType_L tmp;
	int i;
	
	*L=(LinkList)malloc(sizeof(LNode));
	if(!(*L))
		return 0;
	(*L)->next=NULL;  //建立头结点
	
	for(i=1;i<=n;i++)
	{
		if(Scanf(fp,"%d",&tmp)==1)
		{
			p=(LinkList)malloc(sizeof(LNode));
		if(!p)
			return 0;
		p->data=tmp;
		p->next=(*L)->next;
		(*L)->next=p;
		}
		else
			return 0;
		
	} 
	return 1;		
} 
//14.尾插法建立单链表L(顺序输入)
int CreateList_TL(FILE *fp, LinkList *L, int n)
{
	int i;
	LinkList p,q;
	LElemType_L tmp;
	*L=(LinkList)malloc(sizeof(LNode));
	if(!(*L))
		return 0;
	(*L)->next=NULL;
	q=*L;
	for(i=1;i<=n;i++)
	{
		if(Scanf(fp,"%d",&tmp)==1)
		{
			p=(LinkList)malloc(sizeof(LNode));
			if(!p)
				return 0;
			p->data=tmp;
			q->next=p;
			q=q->next;	
		}
		else
			return 0;
	}
	q->next = NULL;
	return 1;
}
