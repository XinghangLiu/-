/*StaticLinkedList.c*/
#include"StaticLinkedList.h"

/*��̬���������������*/
//1.��ʼ�����ÿռ� 
void InitSpace_SL()
{
	int i;           //��ʼ�����ÿռ� 
	for(i=0;i<MAXSIZE-1;i++)
	{
		SPACE[i].cur=i+1;    //0�ŵ�ԪΪ��ʼ��㡣 
		SPACE[MAXSIZE-1].cur=0;  //���ռ�ڵ���β��ӡ� 
	}
} 
//2.Ϊ������������ռ� 
int Malloc_SL()     //�ӱ��ÿռ���������ռ� 
{
	int i;
	i=SPACE[0].cur;   //�õ����ÿռ��еĵ�һ���α� 
	if(SPACE[0].cur)   //�������α�û���� 
	{
		SPACE[0].cur=SPACE[i].cur;//�ڱ��ÿռ���ɾ������α� 
		return i;
	} 
	else
	{
		return 0;	
	}
	
} 
//3.���տ��еĽ�㣬����~
void Free_SL(int k)
{
	SPACE[k].cur=SPACE[0].cur;
	SPACE[0].cur=k;//���α�k���ӵ���������ĵ�һ��cur�ϡ� 
} 
//4.��ʼ����̬���� 
int InitList_SL(SLinkList *H)
{
	*H=Malloc_SL();    //����ͷ��� 
	if(!(*H))
		return 0;
	SPACE[*H].cur=0;	//ͷ�����α�ָ��0���൱��null 
} 
//5.������� 
int ClearList_SL(SLinkList H)
{
	if(!H)
		return 0;
	int p,q;
	p=SPACE[H].cur;    //pָ���һ�����
	
	while(p)
	{
		SPACE[H].cur=SPACE[p].cur;  //��ͷ���ָ��ڶ������
		Free_SL(p);     //ɾ����һ�����
		p=SPACE[H].cur;//��pָ����һ����� 
	} 
	
	return 1; 	
} 
//6.��������
void DestroyList_SL(SLinkList *H)
{
	ClearList_SL(*H); //��վ�̬���� 
	Free_SL(*H);  //�ͷ�ͷ��� 
	*H=0;
} 
//7.�ж��Ƿ�Ϊ�� 
Status ListEmpty_SL(SLinkList H)
{
	if(H &&!SPACE[H].cur)
		return 1;
	else
		return 0;
} 
//8.������
int ListLength_SL(SLinkList H)
{
	int count;
	int p;
	if(!H)
		return 0;
	count=0;
	p=SPACE[H].cur;//p�ǵ�һ�����
	while(p)
	{
		count++;
		p=SPACE[p].cur;
	} 
	return count;
} 
//9.iλ�õ�����Ԫ�� 
Status GetElem_SL(SLinkList H, int i, LElemType_S *e)
{
	int count,p;
	if(!H || i<1 ||i>MAXSIZE-2)
		return 0;
	count=0;
	p=SPACE[H].cur;
	while(p)
	{
		count++;
		if(count==i)
		{
			*e=SPACE[p].data;
			return 1;
		}
		p=SPACE[p].cur;
	}
}
//10.����Ԫ��e��λ�� 
int LocateElem_SL(SLinkList H, LElemType_S e)
{
	int k,count;
	count=1;
	if(H &&SPACE[H].cur)
	{
		k=SPACE[H].cur;
		while(k && SPACE[k].data!=e)
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k)
			return count;
	}
	return 0;
}
//11.����ǰ��
int PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e)
{
	int p,q;
	if(H)
	{
		p=SPACE[H].cur;
		if(p && SPACE[p].data!=cur_e)//cur_e���ǵ�һ������Ԫ�� 
		{
			q=SPACE[p].cur;
			while(q && SPACE[q].data!=cur_e)//��������ǰ�治���������Ľ�� 
			{
				p=q;    //���浱ǰ����ǰ�� 
				q=SPACE[q].cur;
			}
			if(q)
			{
				*pre_e=SPACE[p].data; //�ҵ��˸ý�� 
				return 1;
			}

		}
		
	}
	return 0;
} 
// 12.���غ��
int NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e)
{
	int p;
	if(H)
	{
		p=SPACE[H].cur;
		while(p && SPACE[p].data!=cur_e)
		{
			p=SPACE[p].cur;
		}
		if(p && SPACE[p].cur)
		{
			p=SPACE[p].cur;
			*next_e=SPACE[p].data;
			return 1;
		}
	}
	return 0;
} 
//13.��̬����������� 
int ListInsert_SL(SLinkList H, int i, LElemType_S e)
{
	int count,k,p;
	if(!H)
		return 0;
	if(i>0)
	{
		count=0;
		k=H;       //kָ��ͷ��� 
		while(k && count<i-1)  //�������ҵ�i-1λ�õĽ�� 
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k)    //k���� 
		{
			p=Malloc_SL();   //�����½�� 
			if(!p)
				return 0;
			SPACE[p].data=e;   // 
			SPACE[p].cur=SPACE[k].cur;//��i-1λ�õ��α괫���½����α� 
			SPACE[k].cur=p;    //���½��ĵ�ַ����i-1���α꣬��i-1ָ���½�㡣 
			return 1;
		}
	}
	return 0;
}
//14.��̬����ɾ������ 
int ListDelete_SL(SLinkList H, int i, LElemType_S *e)
{
	int count ,k,p;
	if(!H)
		return 0;
	if(i>0)
	{
		count=0;
		k=H;
		while(k && count<i-1)  //�ҵ�i-1��λ�õĽ�� 
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k && SPACE[k].cur) //���i���� 
		{
			p=SPACE[k].cur;  //�õ���ɾ���Ľ�� 
			*e=SPACE[p].data;
			SPACE[k].cur=SPACE[p].cur;//����ɾ���Ľ����α괫��i-1λ�õ��α� 
			Free_SL(p);    //�ͷŴ�ɾ���Ľ�� 
			return 1;
		}
	} 
	return 0;
}
//15.������̬����
int ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S))
{
	int p;
	if(!H)
		return 0;
	p=SPACE[H].cur;
	
	while(p)
	{
		Visit(SPACE[p].data);
		p=SPACE[p].cur;
	}
	return 1;
} 