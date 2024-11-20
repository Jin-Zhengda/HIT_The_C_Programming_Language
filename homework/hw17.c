// 查找星期表
 #include <stdio.h>
 #include <string.h>
 #define R 7
 #define C 10

int DaySearch(char day[],int *pr)
{
    char week[R][C]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int i,find;
    find=0;
    for(i=0;i<R;i++)
    {
        if(strcmp(day,week[i])==0)
        {
            *pr=i;
            find=1;
        }
    }
    return find;
}

int main(void)
{
    int n,r,find;
    int *pr=&r;
    char day[C];
    printf("Please enter the day's name:");
    gets(day);
    find=DaySearch(day,pr);
    if(find)
    {
        printf("The day's number is %d.\n",r);
    }
    else
    {
        printf("Input erorr!\n");
    }
    return 0;
}
