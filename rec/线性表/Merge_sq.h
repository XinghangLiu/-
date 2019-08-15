/*顺序表的归并操作*/
#include<stdlib.h>
#include"seqlist.c"

/* 顺序表归并函数列表 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.2：求C=A+B，A,B,C均为非递减序列 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/

void MergeSqList_2(SqList La, SqList Lb, SqList *Lc);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法2.7：求C=A+B，A,B,C均为非递减序列 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/
 