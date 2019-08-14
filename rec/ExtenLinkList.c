/*ExtenLinkList.c*/

#include"ExtenLinkList.h"

//1.������pָ��e�Ľ�� 
int MakeNode_E(Link *p, LElemType_E e)
{
	*p=(Link)malloc(sizeof(ELNode));//���������ͷ���
	if(!(*p))
		exit(-1);
	(*p)->data=e; 
	(*p)->next=NULL;
	return 1;
} 
//2.�ͷ�pָ��Ľ��
void FreeNode_E(Link *p)
{
	free(*p);
	(*p)=NULL;
}
//3.��ʼ��һ���µ���������
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
//4.����������Ϊ��
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
//5.������������
void DestroyList_E(ELinkList *L)
{
	ClearList_E(L);
	free((*L).head);
	(*L).head=(*L).tail=NULL;
} 
//6.hָ��L�е�һ����㣬��h����ͷ��㣬��s���뵽����һ����㡱֮ǰ
void InsFirst_E(ELinkList *L, Link h, Link s)
{
	s->next=h->next;
	h->next=s;
	if(h==(*L).tail)   //h�����β��� 
	{
		(*L).tail=h->next;
	}
	(*L).len++;
}
//7.hָ��L�е�һ����㣬��h����ͷ��㣬ɾ������һ����㡱������q����
int DelFirst_E(ELinkList *L, Link h, Link *q)
{
	*q=h->next;
	if(*q)
	{
		h->next=(*q)->next;  //�Ѵ�ɾԪ�غ�һ����ַ��ͷ����ָ���� 
		if(!h->next)   //���h����ֻ��һ���ڵ�
			(*L).tail=h;
		(*L).len--;
		return 1; 
	}
	return 0;
} 
//8.��s��ָ��һ�����������L�����һ�����֮�󣬲��ı�L��βָ��
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
//9.ɾ��L��β��㣬��q���ܣ����ı�βָ�� 
int Remove_E(ELinkList *L, Link *q)
{
	if(!(*L).len)  //��ָ��ĳ���Ϊ0�� 
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
//10.����pָ��Ľ���ǰ�� 
PositionPtr PriorPos_E(ELinkList L, Link p)
{
	Link q;
	q=L.head->next;
	if(p==q)
		return NULL;   //�׽����ǰ��
	else
	{
		while(q->next!=p)  //Ѱըp��ǰ�� 
			q=q->next;
		return q;
	} 
}
//11.����pָ����ĺ�� 
PositionPtr NextPos_E(Link p)
{
	return p->next;
}
//12.��s��ָ������p��ָ���֮ǰ,����pָ���²���Ľ�㡣
void InsBefore_E(ELinkList *L, Link *p, Link s)
{
	Link q;
	q=PriorPos_E(*L,*p);  //Ѱ��p��ǰ��
	if(!q)
	{
		q=(*L).head;
	} 
	s->next=*p;
	q->next=s;
	*p=s;
	(*L).len++;
}
//13.��s��ָ������p��ָ���֮��,����pָ���²���Ľ��
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
//14. ��e������pָ�����е�ֵ 
void SetCurElem_E(Link p, LElemType_E e)
{
	p->data=e;
}
//15.����p����е�ֵ 
LElemType_E GetCurElem_E(Link p)
{
	return p->data;
}
//16.�п�
int ListEmpty_E(ELinkList L)
{
	if(L.len==0)
	{
		return 1;
	}
	else
		return 0;
} 
//17.������ĳ���
int ListLength_E(ELinkList L)
{
	return L.len;
} 
//18.����ͷ�ڵ��λ��
PositionPtr GetHead_E(ELinkList L)
{
	return L.head;
} 
//19.����β����λ��
PositionPtr GetLast_E(ELinkList L)
{
	return L.tail;
} 
//20.��pָ��L�е�i����㣬i=0ʱΪͷ�ڵ� 
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
//21.����L��ָ���һ����e����Compare��ϵ��Ԫ��ָ�롣
PositionPtr LocateElem_E(ELinkList L, LElemType_E e, int(Compare)(LElemType_E,LElemType_E))
{
	Link p=L.head->next;
	while(p && !Compare(e,p->data))
	{
		p=p->next;
	}
	return p;
}
//22.��������
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
//23.���� 
int ListInsert_L_E(ELinkList *L, int i, LElemType_E e)
{
	Link h,s;
	if(!LocatePos_E(*L,i-1,&h))  //��λ��i-1  ,hΪ�����ָ��ǰһ�� 
		return 0;
	if(!MakeNode_E(&s,e))    //sΪ����ָ�� 
		return 0;
	InsFirst_E(L,h,s);
	return 1;
}
//24.ɾ��
int ListDelete_L_E(ELinkList *L, int i, LElemType_E *e)
{
	Link p,q;
	if(i<1 || i>(*L).len)
		return 0;
	LocatePos_E(*L,i-1,&p); //��λ��i-1
	DelFirst_E(L,p,&q);//ɾ����q������pָ��iλ
	*e=q->data;
	free(q);
	q=NULL;
	return 1; 
} 