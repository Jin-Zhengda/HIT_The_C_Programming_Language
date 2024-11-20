#include <stdio.h>
//输入：数组及其储存数据个数
//功能：计算平均数
//输出：该组数据的平均数
int Mean(int a[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    return sum/n;
}

//输入：数组及其储存数据个数
//功能：计算中位数
//输出：该组数据的中位数
int Median(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)//按升序排序
    {
        for(j=i+1;j<n-1;j++)
        {
            if(a[j]>a[i])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    if(n%2==0)//偶数个取中间两项取平均值
    {
        return ((a[n/2-1]+a[n/2])/2);
    }
    else//奇数个数取中间的数
    {
        return a[(n)/2];
    }
}

//输入：数组及其储存数据个数
//功能：计算众数
//输出：该组数据的众数
int Mode(int a[],int n)
{
    int b[11];//存储每个数出现的次数
    int i,j,max,f;
    for(i=0;i<11;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=10;j++)
        {
            if(a[i]==j)
            {
                b[j]++;
            }
        }
    }
    max=b[0];//判断数组中的最大值
    for(i=0;i<=10;i++)
    {
        if(b[i]>max)
        {
            max=b[i];
            f=i;
        }
    }
    return f;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Mean=%d\n",Mean(a,n));
    printf("Median=%d\n",Median(a,n));
    printf("Mode=%d\n",Mode(a,n));
    return 0;
}
