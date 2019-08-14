#include<stdlib.h>
#include"Single_LinkList.c"

/* 单链表归并函数列表 */
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc);
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.12：C=A+B，且保持元素相对位置不变。   ┃
┃    Lc利用La的头结点，Lb中结点均插入新链表Lc中。┃    
┗━━━━━━━━━━━━━━━━━━━━━━━━*/