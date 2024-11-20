#include <stdio.h>
#include <stdlib.h>

int main()
{
     int year,month,day,p,i,sum;
     int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
     int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};//用数组分别储存闰年和平年每月的天数

     printf("请输入日期（年，月，日）");
     scanf("%d,%d,%d",&year,&month,&day);

     p=(year%4==0&&year%100!=0)||(year%400==0);
     if(p)
     {
         for(i=0;i<month-1;i++)
         {
             sum=sum+a[i];//累加计算输入月份前的总天数
         }
         sum=sum+day;//加上当月天数
     }
     else
     {
         for(i=0;i<month-1;i++)
         {
             sum=sum+b[i];
         }
         sum=sum+day;
     }
     printf("%d月%d日是%d年的第%d天",month,day,year,sum);
     return 0;
}
