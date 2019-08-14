#include"Merge_sq.h"

/*���㷨��˼���ǣ������������е�Ԫ�غϲ�������һ�������У�
���Һϲ����������Ԫ�ذ���С�����˳�򣬲������ظ�ֵ*/ 
//1.����˳��������кϲ�
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
	while(i<=len_La && j<=len_Lb)  //ɨ��La Lb��ɨ����С���ȵ��Ǹ� 
	{
		GetElem_Sq(La,i,&ai);  //�õ���ǰ����λ�õ�Ԫ�� 
		GetElem_Sq(Lb,j,&bj);
		if(ai<=bj)//�ڵ�ǰλ�����La<Lb����Lc���д��La��Ԫ�ء� 
		{
			ListInsert_Sq(Lc,++k,ai);
			i++;//��Ӧ��La��λ����ǰһ��			
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
//2.�����û������� 
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc)
{
	LElemType_Sq *pa,*pb,*pc;
	LElemType_Sq *pa_last,*pb_last;
	
	pa=La.elem;//paָ��La���׵�ַ
	pb=Lb.elem;
	
	(*Lc).listsize=(*Lc).length=La.length+Lb.length;
	
	pc=(*Lc).elem=(LElemType_Sq*)malloc(sizeof(LElemType_Sq)*(*Lc).listsize);
	if(!pc)
	  printf("Lc�����ڴ����");
	
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