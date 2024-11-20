// 计算日期
 #include <stdio.h>
 #include <stdlib.h>
 int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
 int b[]={31,29,31,30,31,30,31,31,30,31,30,31};

int IsLeap(int year)
{
    if(year%4==0&&year%100!=0||year%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DayofYear(int year,int month,int day)
{
    int i,d;
    d=0;
    if(IsLeap(year))
    {
        for(i=0;i<month-1;i++)
        {
            d=d+b[i];
        }
        d=d+day;
    }
    else
    {
        for(i=0;i<month-1;i++)
        {
            d=d+a[i];
        }
        d=d+day;
    }
    return d;
}

void MonthDay(int year,int yearDay,int *pMonth,int *pDay)
{
    int i;
    *pMonth=0;
    if(IsLeap(year))
    {
        for(i=0;;i++)
        {
            if(yearDay>b[i])
            {
                yearDay=yearDay-b[i];
                *pMonth=*pMonth+1;
            }
            else
            {
                break;
            }
        }
        *pDay=yearDay;
    }
    else
    {
        for(i=0;;i++)
        {
            if(yearDay>a[i])
            {
                yearDay=yearDay-a[i];
                *pMonth=*pMonth+1;
            }
            else
            {
                break;
            }
        }
        *pDay=yearDay;
    }
}

int main(void)
{
    int n,year,month,day,d,yearDay;
    int *pMonth=&month;
    int *pDay=&d;

    printf("1.year/month/day->yearday\n");
    printf("2.yearDay->year/month/day\n");
    printf("3.Exit\n");
    printf("Please enter your choice:");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("Please enter year,month&day:");
            scanf("%d%d%d",&year,&month,&day);
            d=DayofYear(year,month,day);
            printf("%d.%d.%d is %d of %d",year,month,day,d,year);
            break;
        case 2:
            printf("Please enter year&yearDay:");
            scanf("%d%d",&year,&yearDay);
            MonthDay(year,yearDay,pMonth,pDay);
            printf("%d of %d is %d.%d.%d",yearDay,year,year,month,day);
            break;
        default:
            exit(0);
    }
    return 0;
}