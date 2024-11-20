#include <stdio.h>
#include <stdlib.h>
#define N 50

//输入：数组
//功能：读入大数
//输出：大数位数
int ReadNumber(int* p)
{
    int t[N]= {0};
    char ch;
    int i=0,len=0;
    do
    {
        ch=getchar();
        t[i]=atoi(&ch);
        i++;
    }while(ch!='\n');//逆序读入每一位数据
    len=i-2;//记录读入位数
    for(i=i-2; i>=0; i--)//将逆序结果排正
    {
        p[len-i]=t[i];
    }
    return len;
}

//输入：两个存储大数的数组及其位数，存储计算结果的数组
//功能：进行大数加法
//输出：结果的位数
int Calculating(int* a,int* b,int* c,int x,int y)
{
    int m=(x>=y?x:y);//取两加数位数的最大值
    int i,flag=0;
    for(i=0; i<=m+1; i++)
    {
        c[i]=c[i]+a[i]+b[i];
        if(c[i]>=10)//进位
        {
            c[i]=c[i]-10;
            c[i+1]=c[i+1]+1;
        }
    }
    for(i=N; i>=0; i--)//计算结果位数
    {
        if(c[i]!=0)
        {
            flag=1;
            return i+1;
        }
    }
    if(flag==0)
    {
        return 1;
    }
}

int main(void)
{
    int n,x,y;
    int a[N]= {0};
    int b[N]= {0};
    int c[N+1]= {0};
    x=ReadNumber(a);
    y=ReadNumber(b);
    n=Calculating(a,b,c,x,y);
    for(int i=n-1; i>=0; i--)
    {
        printf("%d",c[i]);
    }
    printf("\n");
    return 0;
}
