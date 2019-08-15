/*Polynomial.c*/

#include "Polynomial.h"
#include "Scanf.c"
//1.����һԪ����ʽ 
void CreatPolyn_P(FILE *fp, Polynomial *P, int m)
{
	PositionPtr h;  //ͷ����ָ�� 
	ElemType_P e;
	int i;
	Link p;
	
	InitList_E(P); //��ʼ��һ����չ�ĵ����������һԪ����ʽ����
	h=GetHead_E(*P);//��ö���ʽ��ͷָ��
	e.coef=0.0;
	e.expn=-1;
	SetCurElem_E(h,e);//����ͷ��������Ԫ��
	h->next=NULL;
	
	for(i=1;i<=m;i++)
	{
		Scanf(fp,"%f%d",&(e.coef),&(e.expn));
		MakeNode_E(&p,e);  //�����½ڵ� 
		p->next=NULL;  //���Ľڵ�ָ��NULL�� 
		InsFirst_E(P,h,p);//���������½ڵ����P�� 
		h=h->next;//������һ�� 
	}
}
//2.����һԪ����ʽ 
void DestroyPolyn_P(Polynomial *P)
{
	DestroyList_E(P);	
}
//3.����һԪ����ʽ������ 
int PolynLength_P(Polynomial P)
{
	return ListLength_E(P);
}
//4.һԪ����ʽ�ļӷ� 
void AddPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha,hb,qa,qb;
	ElemType_P a,b;
	float sum;
	
	ha=GetHead_E(*Pa);   //�õ�Pa,Pb��ͷ���ָ�� 
	hb=GetHead_E(*Pb);
	qa=NextPos_E(ha);    //�õ�Pa,Pb�ĵ�һ������ָ�� 
	qb=NextPos_E(hb);
	
	while(qa &&  qb)  //qa,qb���ǿ� 
	{
		a=GetCurElem_E(qa);  //�õ���ǰ��������Ԫ�� 
		b=GetCurElem_E(qb);
		switch(Cmp_exp(a,b))   //�Դ˽�������Ԫ�ص�ָ������бȽ� 
		{
			case -1:   //��a<b�� 
				ha=qa;
				qa=NextPos_E(ha);//�����ý�㣬ָ��Pa����һ����� 
				break;
			case 0://��ָ����� 
				sum=a.coef+b.coef;//��a��bϵ����� 
				if(sum!=0.0)  //��ϵ���Ͳ�Ϊ0 
				{
					qa->data.coef=sum;  //
					SetCurElem_E(qa,qa->data);//����Ӻ�����ݸ�����Pa�� 
					ha=qa;
				} 
				else  //��ϵ��Ϊ0 
				{
					DelFirst_E(Pa,ha,&qa);//ɾ��Pa�ĵ�ǰ��� 
					FreeNode_E(&qa);	//�ͷŵ�ǰ�ڵ�Ŀռ� 
				}
				DelFirst_E(Pb,hb,&qb);//�����Ƿ�ϵ��Ϊ0����ɾ��pb�ĵ�ǰ��㣬���ͷſռ� 
				FreeNode_E(&qb);
				qb=NextPos_E(hb);//��Pa��Pb������ƶ�һλ 
				qa=NextPos_E(ha);
				break;
			case 1://a>b 
				DelFirst_E(Pb,hb,&qb); //ɾ��Pb�ĵ�ǰ��� 
				InsFirst_E(Pa,ha,qb);//���ý����뵽Pa�� 
				qb=NextPos_E(hb);//Pb�����һλ 
				ha=NextPos_E(ha);//Pa��ͷ��������һλ 
				break;
		}	
	}
	if(qb)//��ѭ���꣬Pb����ʣ�� 
	{
		Append_E(Pa,qb);//��ʣ��Ľ�㶼���ӵ�Pa���� 
	}
	FreeNode_E(&hb);//�ͷ�Pb 
	(*Pb).head=(*Pb).tail=NULL;
	(*Pb).len=0;
} 
// 5.һԪ����ʽ�ļ��� 
void SubtractPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha,hb,qa,qb;// 
	PositionPtr r;
	ElemType_P a,b;
	float sum;
	
	ha=GetHead_E(*Pa);
	hb=GetHead_E(*Pb);
	qa=NextPos_E(ha);
	qb=NextPos_E(hb);//�õ�Pa��Pb��ͷ���͵�һ����� 
	
	while(qa  && qb)//����ǰ��㲻Ϊ�� 
	{
		a=GetCurElem_E(qa);//�õ���ǰ�����Pa��Pb������Ԫ�� 
		b=GetCurElem_E(qb);
		switch(Cmp_exp(a,b))//�Ƚ����ǵ�ָ�����С 
		{
			case -1://��a>b  ����Pa�ĵ�ǰ��� 
				ha=qa;
				qa=NextPos_E(ha);
				break;
			case 0://��a=b  ��ǰ����ϵ������� 
				sum=a.coef-b.coef;
				if(sum!=0.0)//��ϵ���������Ϊ0 
				{
					qa->data.coef=sum;
					SetCurElem_E(qa,qa->data);//�ı�Pa�ڵ�ǰ����ֵ��Ȼ���Ƶ���һλ 
					ha=qa;
				}
				else//��Ϊ0 
				{
					DelFirst_E(Pa,ha,&qa);//ɾ����ǰ��� 
					FreeNode_E(&qa);
				}
				DelFirst_E(Pb,hb,&qb);//����Ϊ��Ϊ0����Ҫɾ��Pb�ĵ�ǰ��� 
				FreeNode_E(&qb);
				qb=NextPos_E(hb);  //������һλ 
				qa=NextPos_E(ha);
				break;
			case 1://��a>b 
				DelFirst_E(Pb,hb,&qb);//ɾ��Pb�ĵ�ǰ�ڵ� 
				qb->data.coef=-qb->data.coef; //��Pb�ĵ�ǰ���ϵ����ȡ�� 
				InsFirst_E(Pa,ha,qb);//����Pa�� 
				qb=NextPos_E(hb);//�Ƶ���һλ 
				ha=NextPos_E(ha);
				break;
		}	
	}
	if(qb)//��Pb����ʣ�� 
	{
		r=qb;
		while(r)//ͨͨȡ�� 
		{
			r->data.coef=-r->data.coef;
			r=r->next;
		}
		Append_E(Pa,qb);//���ӵ�Pa�� 
	}
	FreeNode_E(&hb);//�ͷ�Pb��ͷ��� 
	(*Pb).head=(*Pb).tail=NULL;
	(*Pb).len=0;
} 
//6.���
void MultiplyPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	Polynomial Pc,Ptmp;//��������һԪ����ʽ������ 
	int i,j,la,lb;
	PositionPtr ha,qa,qb;
	Link s;
	
	la=PolynLength_P(*Pa);
	lb=PolynLength_P(*Pb);//�õ���������ʽ  ��ĸ��� 
	ha=(*Pa).head;  //�õ�Pa��ͷ����ָ�� 
	
	
	InitList_E(&Pc);//��ʼ������ʽPc ����ͷָ�룬βָ�룬�ͳ��� 
	for(i=1;i<=la;i++)//��Pa�ĳ�����ѭ�� 
	{
		InitList_E(&Ptmp);//ÿѭ��һ�ξͳ�ʼ��һ��Ptmp 
		qa=NextPos_E(ha);//�õ����һ����� 
		DelFirst_E(Pa,ha,&qa);//ÿ��ѭ����ɾ���䵱ǰ��� 
		qb=(*Pb).head->next;//�õ�Pb�ĵ�һ����� 
		for(j=1;j<=lb;j++)//��Pb�ĳ�����ѭ�� 
		{
			s=(Link)malloc(sizeof(ELNode));//ÿѭ��һ�ξ�����һ�����ռ� 
			if(!s)
				exit(-1);
			s->data.coef=qa->data.coef*qb->data.coef;//ϵ����� 
			s->data.expn=qa->data.expn+qb->data.expn;//ָ����� 
			s->next=NULL;
			
			Append_E(&Ptmp,s);//Ȼ��s���ӵ�Ptmp�ϣ�����һ��ѭ�������󣬵õ�Pa�ĵ�ǰ�����Pb���н����˵Ľ�� 
			qb=qb->next;
		}
		AddPolyn_P(&Pc,&Ptmp);//ÿ��Pa����ѭ������Ptmp����˽�����ӵ�Pc�� 
	}
	AddPolyn_P(Pa,&Pc);//�����е�Pc���ӵ�Pa�ϡ� 
	DestroyPolyn_P(Pb);//ɾ��Pb�� 
} 
//7.�Ƚ�ָ����С 
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
//8.��ӡ�������ʽ 
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
