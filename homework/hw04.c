// 计算40以内的数的阶乘
 #include <stdio.h>
 #define N 50

int Fact(int num[],int n)
{
    int i,j,k,figure,cnt;
    num[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=N-1;j>=0;j--)
        {
            if(num[j]!=0)
            {
                num[j]=num[j]*i;
            }
        }
        for(k=0;k<N;k++)
        {
            while(num[k]>=10)
            {
                figure=num[k]/10;
                num[k+1]=num[k+1]+figure;
                num[k]=num[k]-figure*10;
            }
        }
    }
    cnt=0;
    for(i=N-1;;i--)
    {
        if(num[i]==0)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    return N-cnt;
}

int main()
{

    int n,i,j,flag;

    printf("Input the n:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        int num[N]={0};
        flag = Fact(num, i);
        printf("%d!=", i);
        for (j = flag - 1; j >= 0; j--)
        {
            printf("%d", num[j]);
        }
        printf("\n");
    }
    return 0;
}