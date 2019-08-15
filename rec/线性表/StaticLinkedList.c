/*StaticLinkedList.c*/
#include"StaticLinkedList.h"

/*静态链表基本操作函数*/
//1.初始化备用空间 
void InitSpace_SL()
{
	int i;           //初始化备用空间 
	for(i=0;i<MAXSIZE-1;i++)
	{
		SPACE[i].cur=i+1;    //0号单元为起始结点。 
		SPACE[MAXSIZE-1].cur=0;  //各空间节点首尾相接。 
	}
} 
//2.为插入数据申请空间 
int Malloc_SL()     //从备用空间中申请结点空间 
{
	int i;
	i=SPACE[0].cur;   //得到备用空间中的第一个游标 
	if(SPACE[0].cur)   //如果这个游标没用完 
	{
		SPACE[0].cur=SPACE[i].cur;//在备用空间中删除这个游标 
		return i;
	} 
	else
	{
		return 0;	
	}
	
} 
//3.回收空闲的结点，销毁~
void Free_SL(int k)
{
	SPACE[k].cur=SPACE[0].cur;
	SPACE[0].cur=k;//把游标k链接到备用链表的第一个cur上。 
} 
//4.初始化静态链表 
int InitList_SL(SLinkList *H)
{
	*H=Malloc_SL();    //创建头结点 
	if(!(*H))
		return 0;
	SPACE[*H].cur=0;	//头结点的游标指向0，相当于null 
} 
//5.清空链表 
int ClearList_SL(SLinkList H)
{
	if(!H)
		return 0;
	int p,q;
	p=SPACE[H].cur;    //p指向第一个结点
	
	while(p)
	{
		SPACE[H].cur=SPACE[p].cur;  //将头结点指向第二个结点
		Free_SL(p);     //删掉第一个结点
		p=SPACE[H].cur;//将p指向下一个结点 
	} 
	
	return 1; 	
} 
//6.销毁链表
void DestroyList_SL(SLinkList *H)
{
	ClearList_SL(*H); //清空静态链表 
	Free_SL(*H);  //释放头结点 
	*H=0;
} 
//7.判断是否为空 
Status ListEmpty_SL(SLinkList H)
{
	if(H &&!SPACE[H].cur)
		return 1;
	else
		return 0;
} 
//8.链表长度
int ListLength_SL(SLinkList H)
{
	int count;
	int p;
	if(!H)
		return 0;
	count=0;
	p=SPACE[H].cur;//p是第一个结点
	while(p)
	{
		count++;
		p=SPACE[p].cur;
	} 
	return count;
} 
//9.i位置的数据元素 
Status GetElem_SL(SLinkList H, int i, LElemType_S *e)
{
	int count,p;
	if(!H || i<1 ||i>MAXSIZE-2)
		return 0;
	count=0;
	p=SPACE[H].cur;
	while(p)
	{
		count++;
		if(count==i)
		{
			*e=SPACE[p].data;
			return 1;
		}
		p=SPACE[p].cur;
	}
}
//10.返回元素e的位序 
int LocateElem_SL(SLinkList H, LElemType_S e)
{
	int k,count;
	count=1;
	if(H &&SPACE[H].cur)
	{
		k=SPACE[H].cur;
		while(k && SPACE[k].data!=e)
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k)
			return count;
	}
	return 0;
}
//11.返回前驱
int PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e)
{
	int p,q;
	if(H)
	{
		p=SPACE[H].cur;
		if(p && SPACE[p].data!=cur_e)//cur_e不是第一个结点的元素 
		{
			q=SPACE[p].cur;
			while(q && SPACE[q].data!=cur_e)//遍历所有前面不符合条件的结点 
			{
				p=q;    //保存当前结点的前驱 
				q=SPACE[q].cur;
			}
			if(q)
			{
				*pre_e=SPACE[p].data; //找到了该结点 
				return 1;
			}

		}
		
	}
	return 0;
} 
// 12.返回后继
int NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e)
{
	int p;
	if(H)
	{
		p=SPACE[H].cur;
		while(p && SPACE[p].data!=cur_e)
		{
			p=SPACE[p].cur;
		}
		if(p && SPACE[p].cur)
		{
			p=SPACE[p].cur;
			*next_e=SPACE[p].data;
			return 1;
		}
	}
	return 0;
} 
//13.静态链表插入数据 
int ListInsert_SL(SLinkList H, int i, LElemType_S e)
{
	int count,k,p;
	if(!H)
		return 0;
	if(i>0)
	{
		count=0;
		k=H;       //k指向头结点 
		while(k && count<i-1)  //遍历，找到i-1位置的结点 
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k)    //k存在 
		{
			p=Malloc_SL();   //申请新结点 
			if(!p)
				return 0;
			SPACE[p].data=e;   // 
			SPACE[p].cur=SPACE[k].cur;//将i-1位置的游标传给新结点的游标 
			SPACE[k].cur=p;    //将新结点的地址传给i-1的游标，，i-1指向新结点。 
			return 1;
		}
	}
	return 0;
}
//14.静态链表删除数据 
int ListDelete_SL(SLinkList H, int i, LElemType_S *e)
{
	int count ,k,p;
	if(!H)
		return 0;
	if(i>0)
	{
		count=0;
		k=H;
		while(k && count<i-1)  //找到i-1的位置的结点 
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k && SPACE[k].cur) //如果i存在 
		{
			p=SPACE[k].cur;  //得到待删除的结点 
			*e=SPACE[p].data;
			SPACE[k].cur=SPACE[p].cur;//将待删除的结点的游标传给i-1位置的游标 
			Free_SL(p);    //释放待删除的结点 
			return 1;
		}
	} 
	return 0;
}
//15.遍历静态链表
int ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S))
{
	int p;
	if(!H)
		return 0;
	p=SPACE[H].cur;
	
	while(p)
	{
		Visit(SPACE[p].data);
		p=SPACE[p].cur;
	}
	return 1;
} 