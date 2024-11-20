//打印【1900，2099】间任一年的一月的星期表
 #include <stdio.h>
 #include <stdlib.h>

int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};

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

void PrintMonth(int year,int month)
{
    int i,sum,oneday;
    sum=0;
    for(i=1900;i<year;i++)
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
            sum=sum+a[i];
        }
        oneday=sum%7;
        if(oneday!=6)
        {
            for(i=0;i<=oneday;i++)
            {
                printf("\t");
            }
        }
        for(i=1;i<=a[month-1];i++)
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