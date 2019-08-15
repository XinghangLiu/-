#include"Difference.h"
//(A-B)∪(B-A)
void difference(SLinkList *S, LElemType_S A[], int len_A, LElemType_S B[], int len_B)
{
	int r,p,k; 
	int j,i;
	LElemType_S b;
	
	InitSpace_SL();   //初始化备用空间
	*S=Malloc_SL();  //S表建立头结点
	r=*S;  
	SPACE[r].cur=0; //r指向S表的当前最后结点
	
	//建立集合A的链表
	for(j=0;j<len_A;j++)
	{
		i=Malloc_SL();  //为S表申请新结点
		SPACE[i].data=A[j];
		SPACE[r].cur=i;   //在表尾插入 
		r=i;	
	} 
	SPACE[r].cur=0;//尾结点的指针为空。
	
	//录入B的元素值 
	for(j=0;j<len_B;j++)
	{
		b=B[j];
		p=*S;  //p指向A的头结点
	 	k=SPACE[p].cur;//k指向集合A的第一个结点
	 	//在集合A中查找B 
		while(k && SPACE[k].data!=b)
		{
			p=k;
			k=SPACE[k].cur;	
		} 
		if(!k)  //若A中找不到b 
		{
			i=Malloc_SL();
			SPACE[i].data=b;  //在B中插入b 
			SPACE[i].cur=SPACE[r].cur;
			SPACE[r].cur=i;
		}
		else//找到了 
		{
			SPACE[p].cur=SPACE[k].cur;//将b在A中删除 
			Free_SL(k);
			if(k==r)
			{
				r=p;
			}
		}
	} 
	
}