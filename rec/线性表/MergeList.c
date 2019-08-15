#include"MergeList.h"

void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList pa,pb,pc;
	pa=La->next;
	pb=(*Lb)->next;
	pc=*Lc=La;  //用La的头结点作为Lc的头结点
	
	while(pa && pb)
	{
		if(pa->data <=pb->data)
		{
			pc->next=pa;//pa的值存到pc中 
			pc=pa;//pc+1 
			pa=pa->next;//pa+1
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	} 
	
	pc->next=pa ? pa : pb;//插入剩余段
	free(*Lb);
	*Lb=NULL;
	
	
}