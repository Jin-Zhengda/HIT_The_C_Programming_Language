#include <stdio.h>
#include <string.h>
#define N 10

typedef struct//定义存储条目的结构体
{
    int ID;
    char Username[N];
    int income;
    int expense;
}Acount;

int EmptyRecord(Acount acount[]);
int InputRecord(Acount acount[]);
void SortRecord(Acount acount[],int n);
void SearchRecord(Acount acount[],int n);
void AverageRecord(Acount acount[],int n,float* averincome,float* averexpense);
void LargerRecord(Acount acount[],int n,float averexpense);
void OutputRecord(Acount acount[],int n);

int main(void)
{
    Acount acount[N]={0};
    float averincome;
    float averexpense;
    int flag,n;
    do
    {
        printf("1.Input record\n");
        printf("2.Sort and list records in reverse order by user name\n");
        printf("3.Search records by user name\n");
        printf("4.Calculate and list per capita income and expenses\n");
        printf("5.List records which have more expenses than per capita expenses\n");
        printf("6.List all records\n");
        printf("0.Exit\n");
        printf("Please enter your choice:");
        scanf("%d",&flag);
        switch(flag)
        {
            case 0:
                break;
            case 1:
                n=InputRecord(acount);
                break;
            case 2:
                if(!EmptyRecord(acount))
                {
                    break;
                }
                SortRecord(acount,n);
                break;
            case 3:
                if(!EmptyRecord(acount))
                {
                    break;
                }
                SearchRecord(acount,n);
                break;
            case 4:
                if(!EmptyRecord(acount))
                {
                    break;
                }
                AverageRecord(acount,n,&averincome,&averexpense);
                printf("Per capita income:%.2f\n",averincome);
                printf("Per capita expenses:%.2f\n",averexpense);
                break;
            case 5:
                if(!EmptyRecord(acount))
                {
                    break;
                }
                LargerRecord(acount,n,averexpense);
                break;
            case 6:
                if(!EmptyRecord(acount))
                {
                    break;
                }
                OutputRecord(acount,n);
                break;
            default:
                printf("Input Error!\n");
                break;
        }
        printf("\n");
    } while (flag!=0);
    return 0;
}

//输入：结构体数组
//功能：判断结构体数组是否为空
//输出：数组为空返回0，否则返回1
int EmptyRecord(Acount acount[])
{
    int flag=1;
    if(acount[0].ID==0)
    {
        printf("There is no data yet. Please choose 1 to input the data first.\n");
        flag=0;
    }
    return flag;
}

//输入：结构体数组
//功能：读取数据存储到结构体数组中
//输出：人数
int InputRecord(Acount acount[])
{
    int i,n;
    printf("Input the total of people:");
    scanf("%d",&n);
    while(n<=0||n>=10)//判断输入是否合法
    {
        if(n>=10)
        {
            printf("The system can only store the information of 10 people at most. Please re-enter.\n");
        }
        else
        {
            printf("The system can only store the information of 1 people at least. Please re-enter.\n");
        }
        printf("\nInput the total of people:");
        scanf("%d",&n);
    }
    printf("Please input user's ID, name, income and expenses: (format as:10001 Cindy 6000 1500)\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&acount[i].ID);
        scanf(" %s",acount[i].Username);//%s前有一个空格
        scanf("%d",&acount[i].income);
        scanf("%d",&acount[i].expense);
    }
    return n;
}

//输入：结构体数组，人数
//功能：按用户名降序排列数据
//输出：无
void SortRecord(Acount acount[],int n)
{
    Acount* pstr[N]={NULL};
    Acount t;
    int i,j;
    for(i=0;i<n;i++)
    {
        pstr[i]=&acount[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(pstr[i]->Username,pstr[j]->Username)<=0)
            {
                t=*pstr[i];
                *pstr[i]=*pstr[j];
                *pstr[j]=t;
            }
        }
    }
    printf("ID\tUserName\tIncome\tExpenses\t\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t\t%d\t%d\t\n",pstr[i]->ID,pstr[i]->Username,pstr[i]->income,pstr[i]->expense);
    }
}

//输入：结构体数组，人数
//功能：按用户名查找条目
//输出：查找到条目
void SearchRecord(Acount acount[],int n)
{
    char name[N]={0};
    int i,find=0;
    printf("Please input the user name:");
    scanf(" %s",name);
    for(i=0;i<n;i++)
    {
        if(strcmp(acount[i].Username,name)==0)
        {
            printf("ID\tUserName\tIncome\tExpenses\t\n");
            printf("%d\t%s\t\t%d\t%d\t\n",acount[i].ID,acount[i].Username,acount[i].income,acount[i].expense);
            find=1;
        }
    }
    if(!find)
    {
        printf("Not Found!\n");
    }
}

//输入：结构体数组，指向收入平均数的指针，指向支出平均数的指针
//功能：计算收入平均数和支出平均数
//输出：无
void AverageRecord(Acount acount[],int n,float* averincome,float* averexpense)
{
    float sum1=0,sum2=0;
    int i;
    for(i=0;i<n;i++)
    {
        sum1=sum1+(float)acount[i].income;
        sum2=sum2+(float)acount[i].expense;
    }
    *averincome=sum1/n;
    *averexpense=sum2/n;
}

//输入：结构体数组，人数，支出平均数
//功能：查找支出高于支出平均数的条目
//输出：无
void LargerRecord(Acount acount[],int n,float averexpense)
{
    int i;
    printf("ID\tUserName\tIncome\tExpenses\t\n");
    for(i=0;i<n;i++)
    {
        if(acount[i].expense>averexpense)
        {
            printf("%d\t%s\t\t%d\t%d\t\n",acount[i].ID,acount[i].Username,acount[i].income,acount[i].expense);
        }
    }
}

//输入：结构体数组人数
//功能：按ID升序排列打印条目
//输出：无
void OutputRecord(Acount acount[],int n)
{
    Acount* pstr[N]={NULL};
    Acount t;
    int i,j;
    for(i=0;i<n;i++)
    {
        pstr[i]=&acount[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pstr[i]->ID>=pstr[j]->ID)
            {
                t=*pstr[i];
                *pstr[i]=*pstr[j];
                *pstr[j]=t;
            }
        }
    }
    printf("ID\tUserName\tIncome\tExpenses\t\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t\t%d\t%d\t\n",pstr[i]->ID,pstr[i]->Username,pstr[i]->income,pstr[i]->expense);
    }
}
