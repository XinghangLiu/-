#include"MergeList.h"

void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList pa,pb,pc;
	pa=La->next;
	pb=(*Lb)->next;
	pc=*Lc=La;  //��La��ͷ�����ΪLc��ͷ���
	
	while(pa && pb)
	{
		if(pa->data <=pb->data)
		{
			pc->next=pa;//pa��ֵ�浽pc�� 
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
	
	pc->next=pa ? pa : pb;//����ʣ���
	free(*Lb);
	*Lb=NULL;
	
	
}