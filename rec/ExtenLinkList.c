/*ExtenLinkList.c*/

#include"ExtenLinkList.h"

//1.分配由p指向e的结点 
int MakeNode_E(Link *p, LElemType_E e)
{
	*p=(Link)malloc(sizeof(ELNode));//申请链表的头结点
	if(!(*p))
		exit(-1);
	(*p)->data=e; 
	(*p)->next=NULL;
	return 1;
} 
//2.释放p指向的结点
void FreeNode_E(Link *p)
{
	free(*p);
	(*p)=NULL;
}
//3.初始化一个新的线性链表
int InitList_E(ELinkList *L)
{
	Link p;
	p=(Link)malloc(sizeof(ELNode));
	if(!p)
		exit(-1);
	p->next=NULL;
	(*L).head=(*L).tail=p;
	(*L).len=0;
	return 1;
} 
//4.置线性链表为空
void ClearList_E(ELinkList *L)
{
	Link p,q;
	p=((*L).head)->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;	
	}
	(*L).head->next=NULL;
	(*L).tail=(*L).head;
	(*L).len=0;
} 
//5.销毁线性链表
void DestroyList_E(ELinkList *L)
{
	ClearList_E(L);
	free((*L).head);
	(*L).head=(*L).tail=NULL;
} 
//6.h指向L中的一个结点，将h当做头结点，将s插入到“第一个结点”之前
void InsFirst_E(ELinkList *L, Link h, Link s)
{
	s->next=h->next;
	h->next=s;
	if(h==(*L).tail)   //h如果是尾结点 
	{
		(*L).tail=h->next;
	}
	(*L).len++;
}
//7.h指向L中的一个结点，将h当做头结点，删除“第一个结点”，并用q接收
int DelFirst_E(ELinkList *L, Link h, Link *q)
{
	*q=h->next;
	if(*q)
	{
		h->next=(*q)->next;  //把待删元素后一个地址给头结点的指针域 
		if(!h->next)   //如果h后面只有一个节点
			(*L).tail=h;
		(*L).len--;
		return 1; 
	}
	return 0;
} 
//8.将s所指的一串结点链接在L的最后一个结点之后，并改变L的尾指针
void Append_E(ELinkList *L, Link s)
{
	int count=0;
	(*L).tail->next=s;
	while(s)
	{
		(*L).tail=s;
		s=s->next;
		count++;
	}
	(*L).len+=count;
} 
//9.删除L的尾结点，用q接受，并改变尾指针 
int Remove_E(ELinkList *L, Link *q)
{
	if(!(*L).len)  //若指针的长度为0； 
	{
		*q=NULL;
		return 0;	
	}
	*q=(*L).tail;
	
	Link p;
	p=(*L).head;
	while(p->next!=(*L).tail)
	{
		p=p->next;	
	}
	p->next=NULL;
	(*L).tail=p;
	(*L).len--;
	return 1;
} 
//10.返回p指向的结点的前驱 
PositionPtr PriorPos_E(ELinkList L, Link p)
{
	Link q;
	q=L.head->next;
	if(p==q)
		return NULL;   //首结点无前驱
	else
	{
		while(q->next!=p)  //寻炸p的前驱 
			q=q->next;
		return q;
	} 
}
//11.返回p指向结点的后继 
PositionPtr NextPos_E(Link p)
{
	return p->next;
}
//12.将s所指结点插入p所指结点之前,并将p指向新插入的结点。
void InsBefore_E(ELinkList *L, Link *p, Link s)
{
	Link q;
	q=PriorPos_E(*L,*p);  //寻找p的前驱
	if(!q)
	{
		q=(*L).head;
	} 
	s->next=*p;
	q->next=s;
	*p=s;
	(*L).len++;
}
//13.将s所指结点插入p所指结点之后,并将p指向新插入的结点
void InsAfter_E(ELinkList *L, Link *p, Link s)
{
	if(*p==(*L).tail)
	{
		(*L).tail=s;
	}
	s->next=(*p)->next;
	(*p)->next=s;
	*p=s;
	(*L).len++;
}
//14. 用e来更新p指向结点中的值 
void SetCurElem_E(Link p, LElemType_E e)
{
	p->data=e;
}
//15.返回p结点中的值 
LElemType_E GetCurElem_E(Link p)
{
	return p->data;
}
//16.判空
int ListEmpty_E(ELinkList L)
{
	if(L.len==0)
	{
		return 1;
	}
	else
		return 0;
} 
//17.求链表的长度
int ListLength_E(ELinkList L)
{
	return L.len;
} 
//18.返回头节点的位置
PositionPtr GetHead_E(ELinkList L)
{
	return L.head;
} 
//19.返回尾结点的位置
PositionPtr GetLast_E(ELinkList L)
{
	return L.tail;
} 
//20.将p指向L中第i个结点，i=0时为头节点 
int LocatePos_E(ELinkList L, int i, Link *p)
{
	int count=0;
	*p=L.head;
	if(i<0 || i> L.len)
		return 0;
	while(count<i)
	{
		count++;
		*p=(*p)->next;	
	}	
	return 1;
}
//21.返回L中指向第一个与e满足Compare关系的元素指针。
PositionPtr LocateElem_E(ELinkList L, LElemType_E e, int(Compare)(LElemType_E,LElemType_E))
{
	Link p=L.head->next;
	while(p && !Compare(e,p->data))
	{
		p=p->next;
	}
	return p;
}
//22.遍历访问
int ListTraverse_E(ELinkList L, void(Visit)(LElemType_E))
{
	Link p;
	p=L.head->next;
	int j;
	for(j=1;j<=L.len;j++)
	{
		Visit(p->data);
		p=p->next;
	}
	return 1;
} 
//23.插入 
int ListInsert_L_E(ELinkList *L, int i, LElemType_E e)
{
	Link h,s;
	if(!LocatePos_E(*L,i-1,&h))  //定位至i-1  ,h为待插的指针前一个 
		return 0;
	if(!MakeNode_E(&s,e))    //s为待插指针 
		return 0;
	InsFirst_E(L,h,s);
	return 1;
}
//24.删除
int ListDelete_L_E(ELinkList *L, int i, LElemType_E *e)
{
	Link p,q;
	if(i<1 || i>(*L).len)
		return 0;
	LocatePos_E(*L,i-1,&p); //定位至i-1
	DelFirst_E(L,p,&q);//删掉了q，并将p指向i位
	*e=q->data;
	free(q);
	q=NULL;
	return 1; 
} 