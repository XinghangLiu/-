#include"Difference.h"
//(A-B)��(B-A)
void difference(SLinkList *S, LElemType_S A[], int len_A, LElemType_S B[], int len_B)
{
	int r,p,k; 
	int j,i;
	LElemType_S b;
	
	InitSpace_SL();   //��ʼ�����ÿռ�
	*S=Malloc_SL();  //S����ͷ���
	r=*S;  
	SPACE[r].cur=0; //rָ��S��ĵ�ǰ�����
	
	//��������A������
	for(j=0;j<len_A;j++)
	{
		i=Malloc_SL();  //ΪS�������½��
		SPACE[i].data=A[j];
		SPACE[r].cur=i;   //�ڱ�β���� 
		r=i;	
	} 
	SPACE[r].cur=0;//β����ָ��Ϊ�ա�
	
	//¼��B��Ԫ��ֵ 
	for(j=0;j<len_B;j++)
	{
		b=B[j];
		p=*S;  //pָ��A��ͷ���
	 	k=SPACE[p].cur;//kָ�򼯺�A�ĵ�һ�����
	 	//�ڼ���A�в���B 
		while(k && SPACE[k].data!=b)
		{
			p=k;
			k=SPACE[k].cur;	
		} 
		if(!k)  //��A���Ҳ���b 
		{
			i=Malloc_SL();
			SPACE[i].data=b;  //��B�в���b 
			SPACE[i].cur=SPACE[r].cur;
			SPACE[r].cur=i;
		}
		else//�ҵ��� 
		{
			SPACE[p].cur=SPACE[k].cur;//��b��A��ɾ�� 
			Free_SL(k);
			if(k==r)
			{
				r=p;
			}
		}
	} 
	
}