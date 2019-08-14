/*DualCycleLinkList.c    */

#include"DualCycleLinkList.h"

//1.��ʼ�� 
int InitList_DuL(DuLinkList *L)
{
	(*L)=(DuLinkList)malloc(sizeof(DuLNode));
	if(!(*L))
		exit(-1);
	(*L)->next=(*L)->prior=(*L);   //��ǰ��ָ��ͺ��ָ�붼ָ���Լ����γ�ѭ����
	return 1; 
}
//2.�ÿ� 
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
//3.���������� 
void DestroyList_DuL(DuLinkList *L)
{
	ClearList_DuL(*L);
	free(*L);
	*L=NULL;
}
//4.�п� 
int ListEmpty_DuL(DuLinkList L)
{
	if(L && L->prior==L  && L->next==L)
		return 1;
	else 
		return 0;	
}
//5.����Ԫ�صĸ��� 
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
//6.�õ�iλ�õ�����Ԫ�� 
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
//7.Ѱ����e����һ����ϵԪ�ص�λ�� 
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
//8.����cur_e��ǰ�� 
int PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e)
{
	DuLinkList p;
	if(L)
	{
		p=L->next;
		while(p!=L  && p->data!=cur_e)
			p=p->next;
		if(p!=L && p->prior!=L)    //p��Ϊ�׽�� 
		{
			*pre_e=p->prior->data;
			return 1;
		}
	}
	return 0;
} 
//9. ����cur_e�ĺ�� 
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
//10.����ָ���i������ָ��
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
//11.˫ѭ������Ĳ��� 
int ListInsert_DuL(DuLinkList L, int i, LElemType_DC e)
{
	if(i<1 || i>ListLength_DuL(L)+1)
		return 0;
	
	DuLinkList p,s;
	p=GetElemPtr_DuL(L,i);//�õ���i������ָ��
	if(!p)//!pָp=NULL,��p�ص���ԭ����λ�� 
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
//12.˫ѭ�������ɾ�� 
int ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e)
{
	DuLinkList p;
	if(!(p=GetElemPtr_DuL(L,i)))  //i���Ϸ�
		return 0;
	*e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	p=NULL;
	return 1; 
}
//13.��������
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