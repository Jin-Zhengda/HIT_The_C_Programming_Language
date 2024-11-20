// 冒泡排序
#include <stdio.h>
#define N 50

void BubbleSort(int num[],int n)
{
    int i,t,flag;
    do{
        flag=0;
        for(i=0;i<n-1;i++)
        {
            if(num[i+1]<num[i])
            {
                t=num[i];
                num[i]=num[i+1];
                num[i+1]=t;
            }
        }
        for(i=0;i<n-1;i++)
        {
            if(num[i+1]>=num[i])
            {
                flag++;
            }
        }
    }while(flag!=n-1);
}

int main()
{
    int num[N]={0};
    int n,i;
    n=0;
    printf("Input numbers:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]>0)
        {
            n++;
        }
        else
        {
            break;
        }
    }
    BubbleSort(num,n);
    printf("Result:\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",num[i]);
    }
    return 0;
}