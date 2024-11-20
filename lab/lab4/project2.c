#include <stdio.h>
#include <stdlib.h>

int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};//用数组分别存储平年和闰年每月的天数

//输入：年份
//功能：判断该年份是否为闰年
//输出：是闰年返回1，否则返回0
int IsLeap(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//输入：年份和月份
//功能：打印该月的日历表
//输出：无
void PrintMonth(int year,int month)
{
    int i,sum,oneday;
    sum=0;
    for(i=1900;i<year;i++)//计算到基日期的距离，用sum存储结果
    {
        if(IsLeap(i))
        {
            sum=sum+366;
        }
        else
        {
            sum=sum+365;
        }
    }

    if(IsLeap(year))
    {
        for(i=0;i<month-1;i++)
        {
            sum=sum+a[i];//加上该年到这个月前的总天数
        }
        oneday=sum%7;//判断第一天是星期几
        if(oneday!=6)
        {
            for(i=0;i<=oneday;i++)
            {
                printf("\t");//打印第一天前的空格
            }
        }
        for(i=1;i<=a[month-1];i++)
        {
            if(i==6-oneday)
            {
                printf("%d\t\n",i);//打印第一行末尾的数
            }
            else if((i-6+oneday)%7==0)
            {
                printf("%d\t\n",i);//打印每行末尾的数
            }
            else
            {
                printf("%d\t",i);
            }
        }
    }
    else
    {
        for(i=0;i<month-1;i++)
        {
            sum=sum+b[i];
        }
        oneday=sum%7;
        if(oneday!=6)
        {
            for(i=0;i<=oneday;i++)
            {
                printf("\t");
            }
        }
        for(i=1;i<=b[month-1];i++)
        {
            if(i==6-oneday)
            {
                printf("%d\t\n",i);
            }
            else if((i-6+oneday)%7==0)
            {
                printf("%d\t\n",i);
            }
            else
            {
                printf("%d\t",i);
            }
        }
    }

}

int main()
{
    int year,month;
    scanf("%d%d",&year,&month);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    PrintMonth(year,month);
    return 0;
}
