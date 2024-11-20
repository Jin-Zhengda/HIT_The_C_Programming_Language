#include <stdio.h>
#include <stdlib.h>

//输入：数组及其储存数据个数
//功能：删除数组中重复的元素
//输出：处理后数组所剩的数据个数
int CutArray(int a[],int n)
{
    int i,j,k,cnt;
    cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<n+1;k++)//将被删除数后的所有数向前移动一位
                {
                    a[k]=a[k+1];
                }
                cnt++;//记录操作次数
            }
        }
    }
    return n-cnt;

}

//输入：数组及其储存数据个数
//功能：对数组元素降序排序
//输出：无
void Sorting(int a[],int m)
{
    int i,j,t;
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

int main()
{
    int n,m,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    m=CutArray(a,n);
    printf("%d\n",m);
    Sorting(a,m);
    for(i=0;i<m;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
