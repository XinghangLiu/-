/*Polynomial.h*/

#include<stdio.h>
#include<stdlib.h>
#include "Scanf.c"
#include "Status.h"

/*多项式类型定义*/
typedef struct
{
	float coef;    //系数
	int expn;   //指数	
}LElemType_E;   //重新定义扩展单链表中的数据元素类型

#include "ExtenLinkList.c" 
typedef LElemType_E ElemType_P;  //一元多项式每个项的数据元素类型 
typedef ELinkList Polynomial;  //一元多项式的结构类型 

/* 一元多项式函数列表 */
void CreatPolyn_P(FILE *fp, Polynomial *P, int m); 
/*━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.22：创建项数为m的一元多项式。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

void DestroyPolyn_P(Polynomial *P);
/*━━━━━━━━━━┓
┃(02)销毁一元多项式。┃
┗━━━━━━━━━━*/

int PolynLength_P(Polynomial P);
/*━━━━━━━━━━━━━┓
┃(03)返回一元多项式的项数。┃
┗━━━━━━━━━━━━━*/

void AddPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(04)算法2.23：一元多项式加法Pa=Pa+Pb，销毁Pb。┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

void SubtractPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*━━━━━━━━━━━━━━━━━━┓
┃(05)一元多项式减法Pa=Pa-Pb，销毁Pb。┃
┗━━━━━━━━━━━━━━━━━━*/

void MultiplyPolyn_P(Polynomial *Pa, Polynomial *Pb);
/*━━━━━━━━━━━━━━━━━━┓
┃(06)一元多项式乘法Pa=Pa*Pb，销毁Pb。┃
┗━━━━━━━━━━━━━━━━━━*/

int Cmp_exp(ElemType_P c1, ElemType_P c2);
/*━━━━━━━━━━━━━━┓
┃(07)比较c1项和c2项指数大小。┃
┗━━━━━━━━━━━━━━*/

void PrintPolyn_P(Polynomial P);
/*━━━━━━━━━━━━┓
┃(08)打印输出一元多项式。┃
┗━━━━━━━━━━━━*/
