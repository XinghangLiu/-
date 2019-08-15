/*Polynomial.c*/

#include "Polynomial.h"
#include "Scanf.c"
//1.创建一元多项式 
void CreatPolyn_P(FILE *fp, Polynomial *P, int m)
{
	PositionPtr h;  //头结点的指针 
	ElemType_P e;
	int i;
	Link p;
	
	InitList_E(P); //初始化一个扩展的单链表来存放一元多项式的项
	h=GetHead_E(*P);//获得多项式的头指针
	e.coef=0.0;
	e.expn=-1;
	SetCurElem_E(h,e);//设置头结点的数据元素
	h->next=NULL;
	
	for(i=1;i<=m;i++)
	{
		Scanf(fp,"%f%d",&(e.coef),&(e.expn));
		MakeNode_E(&p,e);  //创建新节点 
		p->next=NULL;  //最后的节点指向NULL； 
		InsFirst_E(P,h,p);//将创建的新节点插入P中 
		h=h->next;//继续下一个 
	}
}
//2.销毁一元多项式 
void DestroyPolyn_P(Polynomial *P)
{
	DestroyList_E(P);	
}
//3.返回一元多项式的项数 
int PolynLength_P(Polynomial P)
{
	return ListLength_E(P);
}
//4.一元多项式的加法 
void AddPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha,hb,qa,qb;
	ElemType_P a,b;
	float sum;
	
	ha=GetHead_E(*Pa);   //得到Pa,Pb的头结点指针 
	hb=GetHead_E(*Pb);
	qa=NextPos_E(ha);    //得到Pa,Pb的第一个结点的指针 
	qb=NextPos_E(hb);
	
	while(qa &&  qb)  //qa,qb都非空 
	{
		a=GetCurElem_E(qa);  //得到当前结点的数据元素 
		b=GetCurElem_E(qb);
		switch(Cmp_exp(a,b))   //对此结点的数据元素的指数项进行比较 
		{
			case -1:   //若a<b， 
				ha=qa;
				qa=NextPos_E(ha);//跳过该结点，指向Pa的下一个结点 
				break;
			case 0://若指数相等 
				sum=a.coef+b.coef;//将a和b系数相加 
				if(sum!=0.0)  //若系数和不为0 
				{
					qa->data.coef=sum;  //
					SetCurElem_E(qa,qa->data);//将相加后的数据更新至Pa内 
					ha=qa;
				} 
				else  //若系数为0 
				{
					DelFirst_E(Pa,ha,&qa);//删掉Pa的当前结点 
					FreeNode_E(&qa);	//释放当前节点的空间 
				}
				DelFirst_E(Pb,hb,&qb);//无论是否系数为0，都删掉pb的当前结点，并释放空间 
				FreeNode_E(&qb);
				qb=NextPos_E(hb);//将Pa，Pb都向后移动一位 
				qa=NextPos_E(ha);
				break;
			case 1://a>b 
				DelFirst_E(Pb,hb,&qb); //删掉Pb的当前结点 
				InsFirst_E(Pa,ha,qb);//将该结点插入到Pa内 
				qb=NextPos_E(hb);//Pb向后移一位 
				ha=NextPos_E(ha);//Pa的头结点向后移一位 
				break;
		}	
	}
	if(qb)//若循环完，Pb还有剩余 
	{
		Append_E(Pa,qb);//将剩余的结点都链接到Pa后面 
	}
	FreeNode_E(&hb);//释放Pb 
	(*Pb).head=(*Pb).tail=NULL;
	(*Pb).len=0;
} 
// 5.一元多项式的减法 
void SubtractPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha,hb,qa,qb;// 
	PositionPtr r;
	ElemType_P a,b;
	float sum;
	
	ha=GetHead_E(*Pa);
	hb=GetHead_E(*Pb);
	qa=NextPos_E(ha);
	qb=NextPos_E(hb);//得到Pa，Pb的头结点和第一个结点 
	
	while(qa  && qb)//若当前结点不为空 
	{
		a=GetCurElem_E(qa);//得到当前结点中Pa，Pb的数据元素 
		b=GetCurElem_E(qb);
		switch(Cmp_exp(a,b))//比较他们的指数项大小 
		{
			case -1://若a>b  跳过Pa的当前结点 
				ha=qa;
				qa=NextPos_E(ha);
				break;
			case 0://若a=b  当前结点的系数项相减 
				sum=a.coef-b.coef;
				if(sum!=0.0)//若系数项相减后不为0 
				{
					qa->data.coef=sum;
					SetCurElem_E(qa,qa->data);//改变Pa在当前结点的值。然后移到下一位 
					ha=qa;
				}
				else//若为0 
				{
					DelFirst_E(Pa,ha,&qa);//删掉当前结点 
					FreeNode_E(&qa);
				}
				DelFirst_E(Pb,hb,&qb);//不管为不为0，都要删掉Pb的当前结点 
				FreeNode_E(&qb);
				qb=NextPos_E(hb);  //跳到下一位 
				qa=NextPos_E(ha);
				break;
			case 1://若a>b 
				DelFirst_E(Pb,hb,&qb);//删掉Pb的当前节点 
				qb->data.coef=-qb->data.coef; //将Pb的当前结点系数项取负 
				InsFirst_E(Pa,ha,qb);//插入Pa中 
				qb=NextPos_E(hb);//移到下一位 
				ha=NextPos_E(ha);
				break;
		}	
	}
	if(qb)//若Pb还有剩余 
	{
		r=qb;
		while(r)//通通取负 
		{
			r->data.coef=-r->data.coef;
			r=r->next;
		}
		Append_E(Pa,qb);//链接到Pa上 
	}
	FreeNode_E(&hb);//释放Pb的头结点 
	(*Pb).head=(*Pb).tail=NULL;
	(*Pb).len=0;
} 
//6.相乘
void MultiplyPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	Polynomial Pc,Ptmp;//定义两个一元多项式的链表 
	int i,j,la,lb;
	PositionPtr ha,qa,qb;
	Link s;
	
	la=PolynLength_P(*Pa);
	lb=PolynLength_P(*Pb);//得到两个多项式  项的个数 
	ha=(*Pa).head;  //得到Pa的头结点的指针 
	
	
	InitList_E(&Pc);//初始化多项式Pc 有了头指针，尾指针，和长度 
	for(i=1;i<=la;i++)//在Pa的长度里循环 
	{
		InitList_E(&Ptmp);//每循环一次就初始化一次Ptmp 
		qa=NextPos_E(ha);//得到其第一个结点 
		DelFirst_E(Pa,ha,&qa);//每次循环都删掉其当前结点 
		qb=(*Pb).head->next;//得到Pb的第一个结点 
		for(j=1;j<=lb;j++)//在Pb的长度里循环 
		{
			s=(Link)malloc(sizeof(ELNode));//每循环一次就申请一个结点空间 
			if(!s)
				exit(-1);
			s->data.coef=qa->data.coef*qb->data.coef;//系数相乘 
			s->data.expn=qa->data.expn+qb->data.expn;//指数相加 
			s->next=NULL;
			
			Append_E(&Ptmp,s);//然后将s链接到Ptmp上，当这一轮循环结束后，得到Pa的当前结点与Pb所有结点相乘的结果 
			qb=qb->next;
		}
		AddPolyn_P(&Pc,&Ptmp);//每次Pa长度循环都将Ptmp的相乘结果链接到Pc中 
	}
	AddPolyn_P(Pa,&Pc);//将所有的Pc链接到Pa上。 
	DestroyPolyn_P(Pb);//删掉Pb。 
} 
//7.比较指数大小 
int Cmp_exp(ElemType_P c1, ElemType_P c2)
{
	int i=c1.expn-c2.expn;
	if(i<0)
		return -1;
	else if(i==0)
		return 0;
	else
		return 1;		
} 
//8.打印输出多项式 
void PrintPolyn_P(Polynomial P)
{
	int i;
	Link p;
	p=P.head->next;
	for(i=1;i<=P.len;i++)
	{
		if(i==1)
			printf("%g",p->data.coef);
		else
		{
			if(p->data.coef>0)
			{
				printf(" + ");
				printf("%g",p->data.coef);
			}
			else
			{
				printf(" - ");
				printf("%g",-p->data.coef);
			}
		}
		if(p->data.expn)
		{
			printf("x");
			if(p->data.expn!=1)
				printf("^%d",p->data.expn);
		}
		p=p->next;
	}
} 
