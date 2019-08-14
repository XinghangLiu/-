#include"Merge_sq.h"

/*该算法的思想是，将两个链表中的元素合并到另外一个链表中，
而且合并后的链表中元素按从小到大的顺序，不清理重复值*/ 
//1.调用顺序表函数进行合并
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc)
{
	int i,j;
	i=j=1;
	int k=0;
	int len_La,len_Lb;
	LElemType_Sq ai,bj;
	
	InitList_Sq(Lc);
	len_La=ListLength_Sq(La);
	len_Lb=ListLength_Sq(Lb);
	while(i<=len_La && j<=len_Lb)  //扫描La Lb表，扫描完小长度的那个 
	{
		GetElem_Sq(La,i,&ai);  //得到当前表中位置的元素 
		GetElem_Sq(Lb,j,&bj);
		if(ai<=bj)//在当前位置里，若La<Lb，在Lc表中存放La的元素。 
		{
			ListInsert_Sq(Lc,++k,ai);
			i++;//对应的La的位置向前一步			
		}

		else
		{
			ListInsert_Sq(Lc,++k,bj);
			j++;			
		}
	}
	while(i<=len_La)
	{
		GetElem_Sq(La,i++,&ai);
		ListInsert_Sq(Lc,++k,ai);
	}
	
	while(j<=len_Lb)
	{
		GetElem_Sq(Lb,j++,&bj);
		ListInsert_Sq(Lc,++k,bj);
	}	
} 
//2.不利用基本操作 
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc)
{
	LElemType_Sq *pa,*pb,*pc;
	LElemType_Sq *pa_last,*pb_last;
	
	pa=La.elem;//pa指向La的首地址
	pb=Lb.elem;
	
	(*Lc).listsize=(*Lc).length=La.length+Lb.length;
	
	pc=(*Lc).elem=(LElemType_Sq*)malloc(sizeof(LElemType_Sq)*(*Lc).listsize);
	if(!pc)
	  printf("Lc申请内存出错！");
	
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	
	while(pa<=pa_last  && pb<=pb_last)
	{
		if((*pa)<=(*pb))
		{
			*pc++=*pa++;
		}
		else
		{
			*pc++=*pb++;	
		}	
		
	} 
	while(pa<=pa_last)
	{
		*pc++=*pa++;
	}
	while(pb<=pb_last)
	{
		*pc++=*pb++;
	}
	
		
}