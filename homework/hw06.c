// 排序并插值
 #include <stdio.h>
 #define N 50

void DateSort(int num[],int n)
{
    int i,j,t;
    for (i = 0; i < n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(num[j]>num[i])
            {
                t=num[j];
                num[j]=num[i];
                num[i]=t;
            }
        }
    }
}

void Inserting(int num[],int x,int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        if(x<num[i]&&x>=num[i+1])
        {
            for (j = n - 1; j >i; j--)
            {
                num[j + 1] = num[j];
            }
            num[i+1] = x;
        }
    }
}

int main()
{
    int num[N]={0};
    int n,x,i;
    n=0;
    printf("Input numbers:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]>=0)
        {
            n++;
        }
        else
        {
            break;
        }
    }
    printf("Input x:\n");
    scanf("%d",&x);
    DateSort(num,n);
    Inserting(num,x,n);
    printf("Result:\n");
    for(i=0;i<=n;i++)
    {
        printf("%d  ",num[i]);
    }
    return 0;
}