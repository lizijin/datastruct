//
//  LinkList.c
//  
//
//  Created by jiangbin on 16/4/19.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void MergeList(LinkList A,LinkList B,LinkList *C);

int main()
{
    int i;
    DataType a[]={8,10,15,21,67,91};
    DataType b[]={5,9,10,13,21,78,91};
    LinkList A,B,C;
    ListNode *p;

    InitList(&A);
    InitList(&B);

    for (i=1; i<=sizeof(a)/sizeof(a[0]); i++) {
        if (InsertList(A,i,a[i-1])==0) {
            return -1;
        }
    }
    
    for (i=1; i<=sizeof(b)/sizeof(b[0]); i++) {
        InsertList(B,i,b[i-1]);
    }


    MergeList(A,B,&C);
    
    for (i=1; i<=ListLength(C); i++) {
        p=Get(C,i);

        if (p) {
            printf("%4d",p->data);
        }
    }
    printf("\n");
    return 1;
}

void MergeList(LinkList A,LinkList B,LinkList *C)
{
    
    //头插法 最先插入的会排到链表的尾端,要求合并成一个递减有序的单链表,所以优先拿最小的

    ListNode *pa,*pb,*qa,*qb;//pa pb 相当于next指针
    pa=A->next;//指向链表A的第一个节点(除头结点)
    pb=B->next;//指向链表B的第一个节点(除头结点)
    
    
    free(B);//释放链表B的头指针
    
    *C=A;//指针C指向A
    
    (*C)->next=NULL;//将链表A的头节点的next指向空
    
    while (pa&&pb)
    {
        if(pa->data<pb->data)//如果链表A的数据小 先拿A的数据
        {
            qa=pa;
            pa=pa->next;
            if((*C)->next==NULL)
            {
                qa->next=(*C)->next;//如果单链表C为空直接插入
            }
            else if((*C)->next->data<qa->data)
            {
                qa->next=(*C)->next;
                (*C)->next=qa;
            }
            else
                free(qa);
        }
        else
        {
            qb=pb;
            pb=pb->next;
            if((*C)->next==NULL)
            {
                qb->next=(*C)->next;
                (*C)->next=qb;
            }
            else if((*C)->next->data<qb->data)
            {
                qb->next=(*C)->next;
                (*C)->next=qb;
            }
            else
                free(qb);
        }
    }
    
    while (pa) {
        qa=pa;
        pa=pa->next;
        if((*C)->next&&(*C)->next->data<qa->data)
        {
            qa->next=(*C)->next;
            (*C)->next=qa;
        }
        else
            free(qa);
    }
    
    while (pb) {
        qb=pb;
        pb=pb->next;
        if((*C)->next&&(*C)->next->data<qb->data)
        {
            qb->next=(*C)->next;
            (*C)->next=qb;
        }
        else
            free(qb);
    }
}
