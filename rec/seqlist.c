/*  seqlist.c   */
#include"seqlist.h"

/*  线性表相关操作的实现    */
//1.初始化操作：为顺序表分配一个预定义大小的数组空间，并将长度设为0； 
int InitList_Sq(SqList *L)   //参数为传入的线性表的首地址 
{
	(*L).elem=(LElemType_Sq *)malloc(sizeof(LElemType_Sq)*LIST_INIT_SIZE);//为顺序表分配空间
	if(!(*L).elem) 
		exit(-1);
	(*L).length=0;//初始化空表长度
	(*L).listsize=100;
	return 0; 
} 
//2.清空顺序表 
void ClearList_Sq(SqList *L)
{
	(*L).length=0;
} 
//3.销毁顺序表 
void DestroyList_Sq(SqList *L)
{
	free((*L).elem);
	(*L).elem=NULL;//释放内存后置空指针
	(*L).length=0;
	(*L).listsize=0;//长度都置为0	
} 
//4.判断空表，为空返回0，非空返回-1 
int ListEmpty_Sq(SqList L)
{
	return L.length==0?0:-1;
} 
//5.顺序表长度 
int ListLength_Sq(SqList L)
{
	return L.length;
}
//6.得到i位置的数据元素 
int GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
	if(i<0 || i>L.length)
		return -1;
	else
		*e=L.elem[i-1];
	return 0;
}
//7.得到e元素的与满足compare的位置序位 
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
//8.得到e的前驱元素 
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
//9.得到e的后继元素 
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
//10.顺序表中插入一个元素 
int ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
	//首先需要判断插入之后表的内存是否够用，若不够用需申请足够的内存
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
	//开始插入数据元素，需要先把i后面的元素都向后移动一位，然后把e的值赋给当前i位置
	 LElemType_Sq *q;
	 q=&(*L).elem[i-1];//得到待插入位置
     LElemType_Sq *p;  
	for(p=&(*L).elem[(*L).length-1];p>=q;p--)
		*(p+1)=*p;//待插入位置后的元素后移
	*q=e;
	(*L).length++;
	return 0; 
}
//11.顺序表删除元素 
int ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
	if(i<1 || i>(*L).length)
		return -1;
	LElemType_Sq *q;
 	q=&(*L).elem[i-1];//得到待插入位置
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
//12.遍历整个表 
int ListTraverse_Sq(SqList L, void (Visit)(LElemType_Sq))
{
		int i;
		for(i=0;i<L.length;i++)
		{
			Visit(L.elem[i]);
		}
		return 0;
}




