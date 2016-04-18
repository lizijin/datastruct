#include<stdio.h>
#define ListSize 100
typedef int DataType;
#include"SeqList.h"
void UnionAB(SeqList *A,SeqList B);
int main()
{
    int i,flag;
    DataType e;
    DataType a[]={2,3,17,20,9,31};
    DataType b[]={8,31,5,17,22,9,48,67};
    SeqList LA,LB;
    printf("%p",&LA);
    printf("\n");
    printf("%ld",sizeof(LA.list));
    printf("\n");
    InitList(&LA);
    InitList(&LB);
    for(i=0; i<sizeof(a)/sizeof(a[0]); i++) {
        if(InsertList(&LA,i+1,a[i])==0){
            printf("位置不合法");
//            return -1;
            break;
        }
    }
    for(i=0; i<sizeof(b)/sizeof(b[0]); i++) {
        if(InsertList(&LB,i+1,b[i])==0){
            printf("位置不合法");
//                   return -1;
            break;
        }
    }

    UnionAB(&LA,LB);

    for(i=1;i<=LA.length;i++)
    {
        flag = GetElem(LA,i,&e);
        if(flag==1)
            printf("%4d",e);
    }
    printf("\n");
           return 1;
}
void UnionAB(SeqList *LA,SeqList LB)
{
    DataType e;
    int flag;
    for (int i=1; i<=LB.length; i++) {
        flag = GetElem(LB,i,&e);

        if(flag){
            int pos = LocateElem(*LA,e);
            if(!pos)
            {
                InsertList(LA,LA->length+1,e);
            }
        }
    }
}