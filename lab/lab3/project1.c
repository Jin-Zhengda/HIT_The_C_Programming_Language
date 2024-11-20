#include <stdio.h>
#include <stdlib.h>

/*输入：一个正数*/
/*功能：判断该数是否为素数*/
/*输出：是素数返回该数，否则返回0*/
int IsPrime(int n)
{
    int i,find;
    find=1;
    if(n<=0)//判断输入是否合法
    {
        printf("Error!\n");
        exit(0);
    }
    if(n==1)
    {
        find=0;
    }
    else
    {
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                find=0;
            }
        }
    }

    if(find)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int M,N,n,ret,sum,i,j;
    int num[1000]={0};
    sum=0;
    scanf("%d",&M);

    for(i=1;i<=M;i++)
    {
         scanf("%d",&N);
         for(j=1;j<=N;j++)
         {
             scanf("%d",&n);
             ret=IsPrime(n);
             sum=sum+ret;
         }
         num[i-1]=sum;//使用数组储存计算结果，置sum为0后进行下一轮累加
         sum=0;
    }
    for(i=0;i<M;i++)
    {
        printf("%d\n",num[i]);
    }
    return 0;
}
