#include"Single_LinkList.h"
//1.��ʼ�������� 
int InitList_L(LinkList *L)
{
	(*L)=(LinkList)malloc(sizeof(LNode));  //��������ͷ�����ڴ�ռ� 
	if(!(*L))
		return 0;
	(*L)->next=NULL;//ͷ�ڵ����һ���ڵ�ָ��null 
	return 1;	
}
//2.������������ͷ��㣩 
int ClearList_L(LinkList L)
{
	if(!L)
		return 0;
	LinkList pre,p;
	pre=L->next;//�õ�����ĵ�һ����㣨����ͷ��㣩
	while(pre)
	{
		p=pre->next;//�õ���ǰ���ĺ�һ������ַ 
		free(pre);//���ٵ�ǰ��� 
		pre=p;// 
	}	
	L->next=NULL;
	return 1;
} 
//3.���ٵ����� 
void DestroyList_L(LinkList *L)
{
	LinkList p;
	p=(*L);
	while(p)//�������� 
	{
		p=(*L)->next;
		free((*L));
		(*L)=p;
	}
}
//4.�ж������Ƿ�Ϊ�� 
int ListEmpty_L(LinkList L)
{
	if(L!=NULL && L->next==NULL)
		return 1;
	else 
	 	return 0;
}
//5.������ĳ��� 
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
//6.�õ���������iλ�õ�Ԫ�� 
int GetElem_L(LinkList L, int i, LElemType_L *e)
{
	int j;
	LinkList p;
	j=0;
	p=L->next;
	
	while(p && j<i)//�õ�iλ�õĵ�ַ��jֵ 
	{
		j++;
		p=p->next;
	}
	
	if(!p ||j>i)
		return 0;
	
	(*e)=p->data;
	return 1;		
}
//7.���������е�һ����e����compare��ϵ��Ԫ�ص�λ�� 
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
			i++;//ÿѭ�����Σ�i+1 
			if(!Compare(e,p->data))//ѭ������������Compare��ƥ�� 
			{
				p=p->next;// һ����ƥ�������� 
				if(p==NULL)//��ε�����˾�+1 
					i++;
				
			}
			else //�� Compareƥ��֮�������ѭ���� 
				break;
		}
	}
	return i;
} 
//8.����cur_e��ֱ��ǰ��Ԫ�� 
int PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e)
{
	LinkList p,suc;
	if(L)//�����
	{
		p=L->next;
		if(p->data!=cur_e)//�ж�cur_e���ǵ�һ����㣬��Ϊ��һ�����û��ǰ��
		{
			while(p)
			{
				suc=p->next;//ָ����Ԫ��
				if(suc->data==cur_e)
				{
					*pre_e=p->data;
					return 1;
				} 
				p=suc;//����һλ 
			}
			
			 
		} 
	} 
	return 0;
}
//9.����cur_e��ֱ�Ӻ��Ԫ�� 
int NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
	LinkList p,suc;
	if(L)//�ǿձ�
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
//10.������Ĳ������ 
int ListInsert_L(LinkList L, int i, LElemType_L e)
{
	LinkList p,s;
	int j;
	p=L;
	j=0;
	
	while(p && j<i-1)
	{
		p=p->next;
		++j;//���һ����++���õ�i-1 
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
//11.�������ɾ������ 
int ListDelete_L(LinkList L, int i, LElemType_L *e)
{
	LinkList pre,p;
	int j;
	
	pre=L;
	j=1;
	while(pre->next  &&j<i)//�ҵ�i��λ�ã�����preָ��iԪ�ص�ǰ��
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
//12.��������� 
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
//13.ͷ�巨�����������������룩 
int CreateList_HL(FILE *fp, LinkList *L, int n)
{
	LinkList p;
	LElemType_L tmp;
	int i;
	
	*L=(LinkList)malloc(sizeof(LNode));
	if(!(*L))
		return 0;
	(*L)->next=NULL;  //����ͷ���
	
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
//14.β�巨����������L(˳������)
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
