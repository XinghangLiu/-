/*求两线性表的并集的相关操作*/

#include"seqlist.c"
/* 并集函数列表 */ 
void Union(SqList *La, SqList Lb);
/*━━━━━━━━━━━┓
┃(01)算法2.1：A=A∪B。 ┃
┗━━━━━━━━━━━*/

int equal(LElemType_Sq e1, LElemType_Sq e2);
/*━━━━━━━━━━━━┓
┃(02)判断两元素是否相等。┃
┗━━━━━━━━━━━━*/