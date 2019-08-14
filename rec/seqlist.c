/*  seqlist.c   */
#include"seqlist.h"

/*  ���Ա���ز�����ʵ��    */
//1.��ʼ��������Ϊ˳������һ��Ԥ�����С������ռ䣬����������Ϊ0�� 
int InitList_Sq(SqList *L)   //����Ϊ��������Ա���׵�ַ 
{
	(*L).elem=(LElemType_Sq *)malloc(sizeof(LElemType_Sq)*LIST_INIT_SIZE);//Ϊ˳������ռ�
	if(!(*L).elem) 
		exit(-1);
	(*L).length=0;//��ʼ���ձ���
	(*L).listsize=100;
	return 0; 
} 
//2.���˳��� 
void ClearList_Sq(SqList *L)
{
	(*L).length=0;
} 
//3.����˳��� 
void DestroyList_Sq(SqList *L)
{
	free((*L).elem);
	(*L).elem=NULL;//�ͷ��ڴ���ÿ�ָ��
	(*L).length=0;
	(*L).listsize=0;//���ȶ���Ϊ0	
} 
//4.�жϿձ�Ϊ�շ���0���ǿշ���-1 
int ListEmpty_Sq(SqList L)
{
	return L.length==0?0:-1;
} 
//5.˳����� 
int ListLength_Sq(SqList L)
{
	return L.length;
}
//6.�õ�iλ�õ�����Ԫ�� 
int GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
	if(i<0 || i>L.length)
		return -1;
	else
		*e=L.elem[i-1];
	return 0;
}
//7.�õ�eԪ�ص�������compare��λ����λ 
int LocateElem_Sq(SqList L, LElemType_Sq e, int(Compare)(LElemType_Sq, LElemType_Sq))
{
	int i=1;
	while(i<=L.length && !Compare(e,L.elem[i-1]))
		i++;
	if(i<=L.length)
		return i;
	else
		return 0;
}
//8.�õ�e��ǰ��Ԫ�� 
int PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
	int i=1;
	if(L.elem[0]!=cur_e)
	{
		while(i<L.length && L.elem[i]!=cur_e)
			i++;
		if(i<L.length)
		{
			*pre_e=L.elem[i-1];
			return i;
		}
	}
	return -1;
}
//9.�õ�e�ĺ��Ԫ�� 
int NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
	int i=0;
	while(i<L.length && L.elem[i]!=cur_e)
		i++;
	if(i<L.length-1) 
	{
		*next_e=L.elem[i+1];
		return i+2;
	}
	return -1;		
}
//10.˳����в���һ��Ԫ�� 
int ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
	//������Ҫ�жϲ���֮�����ڴ��Ƿ��ã����������������㹻���ڴ�
	LElemType_Sq * newbase; 
	if(i<1 || i>(*L).length+1)
		return -1;
	if((*L).length>=(*L).listsize)
	{
		newbase=(LElemType_Sq *)realloc((*L).elem,sizeof(LElemType_Sq)*(LISTINCREMENT+(*L).listsize));
		if(!newbase)
			exit(-1);
		(*L).elem=newbase;
		(*L).listsize+= LISTINCREMENT;
	}
	//��ʼ��������Ԫ�أ���Ҫ�Ȱ�i�����Ԫ�ض�����ƶ�һλ��Ȼ���e��ֵ������ǰiλ��
	 LElemType_Sq *q;
	 q=&(*L).elem[i-1];//�õ�������λ��
     LElemType_Sq *p;  
	for(p=&(*L).elem[(*L).length-1];p>=q;p--)
		*(p+1)=*p;//������λ�ú��Ԫ�غ���
	*q=e;
	(*L).length++;
	return 0; 
}
//11.˳���ɾ��Ԫ�� 
int ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
	if(i<1 || i>(*L).length)
		return -1;
	LElemType_Sq *q;
 	q=&(*L).elem[i-1];//�õ�������λ��
 	*e=*q;
 	LElemType_Sq *p;
 	p=(*L).elem+(*L).length+1;
 	for(q++;q<=p;q++)
 	{
		*(q-1)=*q; 	
 	}
 	(*L).length--;
 	return 0;
}
//12.���������� 
int ListTraverse_Sq(SqList L, void (Visit)(LElemType_Sq))
{
		int i;
		for(i=0;i<L.length;i++)
		{
			Visit(L.elem[i]);
		}
		return 0;
}




