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
		GetElem_Sq(Lb,i,&e);//�õ�Lb�е�ÿһ��Ԫ�� 
		printf("���Һ�������ֵ��%d  \n",LocateElem_Sq(*La,e,equal));
		if(!LocateElem_Sq(*La,e,equal))//�жϸ�Ԫ����La���Ƿ���� 
			ListInsert_Sq(La,len_La++,e);//�������ھ���La��������Ԫ�� 
	}
}

int equal(LElemType_Sq e1, LElemType_Sq e2)
{
	return e1==e2 ? 1 : 0;
}