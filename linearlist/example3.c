//大整数求和运算
#include<stdio.h>
#define MAXLENGTH 100
int input(int arr[MAXLENGTH]);
int reverseData(int arr[MAXLENGTH],int start,int end);
int add(int arrA[MAXLENGTH],int na,int arrB[MAXLENGTH],int nb);
void printData(int arr[MAXLENGTH],int start,int end);
int main()
{
    int arr[MAXLENGTH];
    int arrB[MAXLENGTH];
    int na = input(arr);
    int nb = input(arrB);
    reverseData(arr,0,na);
    reverseData(arrB,0,nb);

   int nd= add(arr,na,arrB,nb);

    printData(arr,1,nd);
    return 1;
}
void printData(int arr[MAXLENGTH],int start,int end)
{
    for (int i=end; i>=start; i--) {
        printf("%d",arr[i]);
    }
}



int input(int arr[MAXLENGTH])
{
    int  i;
    for ( i=0; i<MAXLENGTH; i++) {
        arr[i]=0;
    }
    printf("请输入一个正整数的各位(输入-1结束)\n");
    i =0;
    while (1) {
        scanf("%d",&arr[i]);
        if(arr[i]==-1)
            break;
        i++;
        if(i==MAXLENGTH){
            printf("输入超过数组长度\n");
            break;
        }
    }
    return i;
}

int reverseData(int arr[MAXLENGTH],int start,int end)
{
    int temp;
    while (start<end) {
        temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    return 1;
}

int add(int arrA[MAXLENGTH],int na,int arrB[MAXLENGTH],int nb)
{
    int nc = na>=nb?na:nb;
    int nd =0;
    for (int i =1; i<=nc; i++) {
        nd++;
        int c = arrA[i]+arrB[i];
        if(c>9){
            arrA[i]=c-10;
            arrA[i+1]+=1;
            if(nd==nc){
                nd++;
            }
        }else{
            arrA[i]=c;
        }
    }
    return nd;
}

