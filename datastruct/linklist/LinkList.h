//
//  LinkList.h
//  
//
//  Created by jiangbin on 16/4/19.
//
//

#ifndef ____LinkList__
#define ____LinkList__

#include <stdio.h>

#endif /* defined(____LinkList__) */
typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node *next;
}ListNode,*LinkList;

void InitList(LinkList *head)
{
    if((*head=(LinkList)malloc(sizeof(ListNode)))==NULL) {
        exit(-1);
    }
    (*head)->next=NULL;
}

int ListEmpty(LinkList head)
{
    if(head->next==NULL)
        return 1;
    return 0;
}

ListNode *Get(LinkList head,int i)
{
    if(ListEmpty(head))
        return NULL;
    if(i<1)
        return NULL;
    ListNode *p;
    int j=0;
    p=head;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(i==j)
        return p;
    return NULL;
}

ListNode *LocateElem(LinkList head,DataType e)
{
    ListNode *p;
    p=head->next;
    while (p) {
        if(p->data!=e)
            p=p->next;
        else
            break;
    }
    return p;
}
int LocatPos(LinkList head,DataType e)
{
    ListNode *p;
    int i;
    if(ListEmpty(head))
    {
        return 0;
    }
    p=head->next;
    i=1;
    while (p) {
        if(p->data==e)
        {
            return i;
        }
        else
        {
            p=p->next;
            i++;
        }
    }
    if (!p) {
        return 0;
    }
    return i;
}

int InsertList(LinkList head,int i,DataType e)
{
    ListNode *pre,*p;
    int j;
    pre =head;
    j=0;
    while (pre->next!=NULL&&j<i-1) {
        pre=pre->next;
        j++;
    }
    if(j!=i-1)
    {
        return 0;
    }
    if((p=(ListNode *) malloc(sizeof(ListNode)))==NULL)
        exit(-1);
    p->data=e;
    p->next=pre->next;
    pre->next=p;
    return 1;
}

int DeleteList(LinkList head,int i,DataType *e)
{
    ListNode *pre,*p;
    int j;
    pre=head;
    j=0;
    while (pre->next!=NULL&&pre->next!=NULL&&j<i-1) {
        pre =pre->next;
        j++;
    }
    if(j!=i-1)
        return 0;
    p=pre->next;
    *e=p->data;
    pre->next=p->next;
    free(p);
    return 1;
}

int ListLength(LinkList head)
{
    ListNode *p;
    int count=0;
    p=head;
    while (p->next!=NULL) {
        p=p->next;
        count++;
    }
    return count;
}

void DestroyList(LinkList head)
{
    ListNode *p,*q;
    p=head;
    while (p!=NULL) {
        q=p;
        p=p->next;
        free(q);
    }
}








