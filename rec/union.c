#include"union.h"

void Union(SqList *La, SqList Lb)
{
	int len_La;
	int len_Lb;
	LElemType_Sq e;
	len_La=(*La).length;
	len_Lb=Lb.length;
	int i;
	for(i=1;i<=len_Lb;i++)
	{
		GetElem_Sq(Lb,i,&e);//得到Lb中的每一个元素 
		printf("查找函数返回值：%d  \n",LocateElem_Sq(*La,e,equal));
		if(!LocateElem_Sq(*La,e,equal))//判断该元素在La中是否存在 
			ListInsert_Sq(La,len_La++,e);//若不存在就在La后面插入该元素 
	}
}

int equal(LElemType_Sq e1, LElemType_Sq e2)
{
	return e1==e2 ? 1 : 0;
}