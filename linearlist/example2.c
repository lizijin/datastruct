/**
*编写一个算法，把一个顺序表分拆成两个部分，使顺序表中小于0的元素位于左端
*大于0的元素位于右端。要求不占用额外的存储空间。
*例如顺序表(-12,3,-6,-10,20,-7,9,-20)经过分拆调整后变为
*（-12,-20,-6,-10,-7,20,9,3）
**/
#include<stdio.h>
typedef int DataType;
#include"SeqList.h"
void PrintData(SeqList List);
void SortData(SeqList *List);
int main()
{
    DataType a[]={-12,3,-6,-10,20,-7,9,-20};
    SeqList List;
    InitList(&List);
    for (int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
        DataType e = a[i];
        InsertList(&List,i+1,e);
    }
    SortData(&List);
    
    PrintData(List);
}

void PrintData(SeqList List)
{
    for (int i=1; i<=List.length; i++)
    {
        DataType e ;
        GetElem(List,i,&e);
        printf("%4d", e);
    }
    printf("\n");
//    for (int i=0; i<sizeof(List.list)/sizeof(List.list[0]); i++) {
//        printf("%4d", List.list[i]);
//    }
//    printf("\n");
}

void SortData(SeqList *List){
    int i=0,j=List->length-1;
    DataType temp;
    while (i<j) {
        while (List->list[i]<0)
        {
            i++;
        }
        while (List->list[j]>0)
        {
            j--;
        }
        if(i<j)
        {
            temp = List->list[i];
            List->list[i]=List->list[j];
            List->list[j]=temp;
        }
    }
}